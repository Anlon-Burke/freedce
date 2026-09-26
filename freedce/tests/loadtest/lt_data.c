/*
 * lt_data.c: deterministic test data for the load test (see lt_data.h).
 */
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lt_data.h"

const char *lt_op_names[LT_N_OPS] =
{
    "null", "null_idem", "struct", "array", "union", "list", "graph",
    "pipe_in", "pipe_out", "open", "ctx_op", "close", "slow", "stats"
};

idl_void_p_t (*lt_alloc)(idl_size_t size);

/* splitmix64 */
static uint64_t mix(uint64_t z)
{
    z += 0x9e3779b97f4a7c15ULL;
    z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9ULL;
    z = (z ^ (z >> 27)) * 0x94d049bb133111ebULL;
    return z ^ (z >> 31);
}

#ifdef _WIN32

int64_t lt_hyper_get(const idl_hyper_int *v) { return *v; }
void lt_hyper_set(idl_hyper_int *v, int64_t x) { *v = x; }
uint64_t lt_uhyper_get(const idl_uhyper_int *v) { return *v; }
void lt_uhyper_set(idl_uhyper_int *v, uint64_t x) { *v = x; }

#else

/* DCE: a struct of two 32-bit halves */
int64_t lt_hyper_get(const idl_hyper_int *v)
{
    return (int64_t) (((uint64_t) (uint32_t) v->high << 32) | v->low);
}

void lt_hyper_set(idl_hyper_int *v, int64_t x)
{
    v->low = (idl_ulong_int) x;
    v->high = (idl_long_int) ((uint64_t) x >> 32);
}

uint64_t lt_uhyper_get(const idl_uhyper_int *v)
{
    return ((uint64_t) v->high << 32) | v->low;
}

void lt_uhyper_set(idl_uhyper_int *v, uint64_t x)
{
    v->low = (idl_ulong_int) x;
    v->high = (idl_ulong_int) (x >> 32);
}

#endif

static uint64_t key_base(const lt_key_t *key, unsigned int stream)
{
    uint64_t s = lt_uhyper_get(&key->seed);

    s = mix(s ^ key->client);
    s = mix(s ^ key->thread);
    s = mix(s ^ key->call);
    s = mix(s ^ ((uint64_t) key->flags << 32) ^ stream);
    return s;
}

void lt_rng_init(lt_rng_t *r, const lt_key_t *key, unsigned int stream)
{
    r->s = key_base(key, stream);
}

uint64_t lt_rng_next(lt_rng_t *r)
{
    r->s += 0x9e3779b97f4a7c15ULL;
    return mix(r->s);
}

uint32_t lt_rng_below(lt_rng_t *r, uint32_t n)
{
    return n == 0 ? 0 : (uint32_t) (lt_rng_next(r) % n);
}

void lt_errf(char *err, size_t errlen, const char *fmt, ...)
{
    size_t  used = strlen(err);
    va_list ap;

    if (used + 1 >= errlen)
        return;
    va_start(ap, fmt);
    vsnprintf(err + used, errlen - used, fmt, ap);
    va_end(ap);
}

static double gen_double(lt_rng_t *r)
{
    return (double) (int64_t) lt_rng_next(r) / 1024.0;
}

static char *gen_string(lt_rng_t *r, char *buf, unsigned int max, int may_be_null)
{
    unsigned int i, len;

    if (may_be_null && lt_rng_below(r, 8) == 0)
        return NULL;
    len = lt_rng_below(r, max + 1);
    for (i = 0; i < len; i++)
        buf[i] = 'A' + lt_rng_below(r, 26);
    buf[len] = '\0';
    return buf;
}

static char *dup_string(const char *s)
{
    char *p;

    if (s == NULL)
        return NULL;
    p = (*lt_alloc)((idl_size_t) strlen(s) + 1);
    strcpy(p, s);
    return p;
}

static int str_differs(const idl_char *a, const char *b)
{
    if (a == NULL || b == NULL)
        return a != NULL || b != NULL;
    return strcmp((const char *) a, b) != 0;
}

/* lt_struct ---------------------------------------------------------------- */

static void gen_rec_into(const lt_key_t *key, unsigned int stream,
                         lt_rec_t *rec, char *namebuf)
{
    lt_rng_t r;
    uint64_t x;
    int      i;

    lt_rng_init(&r, key, stream);
    lt_hyper_set(&rec->h, (int64_t) lt_rng_next(&r));
    lt_uhyper_set(&rec->uh, lt_rng_next(&r));
    rec->d = gen_double(&r);
    rec->f = (float) (int32_t) lt_rng_next(&r) / 16.0f;
    x = lt_rng_next(&r);
    rec->s8 = (idl_small_int) x;
    rec->u8 = (idl_usmall_int) (x >> 8);
    rec->s16 = (idl_short_int) (x >> 16);
    rec->u16 = (idl_ushort_int) (x >> 32);
    rec->s32 = (idl_long_int) lt_rng_next(&r);
    rec->u32 = (idl_ulong_int) lt_rng_next(&r);
    rec->flag = (idl_boolean) lt_rng_below(&r, 2);
    rec->raw = (idl_byte) lt_rng_next(&r);
    rec->color = (lt_color_t) lt_rng_below(&r, 3);
    for (i = 0; i < lt_tag_len; i++)
        rec->tag[i] = 'a' + lt_rng_below(&r, 26);
    rec->name = (idl_char *) gen_string(&r, namebuf, lt_max_name, 1);
}

void lt_gen_rec(const lt_key_t *key, unsigned int stream, lt_rec_t *rec)
{
    char namebuf[lt_max_name + 1];

    gen_rec_into(key, stream, rec, namebuf);
    rec->name = (idl_char *) dup_string((char *) rec->name);
}

int lt_check_rec(const lt_key_t *key, unsigned int stream, const lt_rec_t *rec,
                 char *err, size_t errlen)
{
    char     namebuf[lt_max_name + 1];
    lt_rec_t e;
    int      bad = 0;

#define CHK(cond, what) \
    if (cond) { if (bad++ == 0) lt_errf(err, errlen, "rec.%s differs", what); }

    gen_rec_into(key, stream, &e, namebuf);
    CHK(lt_hyper_get(&rec->h) != lt_hyper_get(&e.h), "h");
    CHK(lt_uhyper_get(&rec->uh) != lt_uhyper_get(&e.uh), "uh");
    CHK(memcmp(&rec->d, &e.d, sizeof e.d) != 0, "d");
    CHK(memcmp(&rec->f, &e.f, sizeof e.f) != 0, "f");
    CHK(rec->s8 != e.s8, "s8");
    CHK(rec->u8 != e.u8, "u8");
    CHK(rec->s16 != e.s16, "s16");
    CHK(rec->u16 != e.u16, "u16");
    CHK(rec->s32 != e.s32, "s32");
    CHK(rec->u32 != e.u32, "u32");
    CHK(rec->flag != e.flag, "flag");
    CHK(rec->raw != e.raw, "raw");
    CHK(rec->color != e.color, "color");
    CHK(memcmp(rec->tag, e.tag, sizeof e.tag) != 0, "tag");
    CHK(str_differs(rec->name, (char *) e.name), "name");
#undef CHK
    return bad;
}

/* lt_array ----------------------------------------------------------------- */

unsigned32 lt_reply_len(const lt_key_t *key, unsigned32 max)
{
    lt_rng_t r;

    lt_rng_init(&r, key, LT_REP + 100);
    return lt_rng_below(&r, max + 1);
}

static void gen_item(lt_rng_t *r, unsigned32 i, lt_item_t *it)
{
    uint64_t x = lt_rng_next(r);
    int      j;

    it->id = i ^ (idl_ulong_int) (x >> 32);
    it->kind = (idl_ushort_int) x;
    for (j = 0; j < 6; j++)
        it->data[j] = (idl_byte) (x >> (16 + 8 * j));
    it->value = gen_double(r);
}

static int item_differs(const lt_item_t *a, const lt_item_t *b)
{
    return a->id != b->id || a->kind != b->kind
        || memcmp(a->data, b->data, sizeof a->data) != 0
        || memcmp(&a->value, &b->value, sizeof a->value) != 0;
}

void lt_gen_items(const lt_key_t *key, unsigned int stream, unsigned32 len,
                  lt_item_t *items)
{
    lt_rng_t   r;
    unsigned32 i;

    lt_rng_init(&r, key, stream);
    for (i = 0; i < len; i++)
        gen_item(&r, i, &items[i]);
}

int lt_check_items(const lt_key_t *key, unsigned int stream, unsigned32 len,
                   const lt_item_t *items, char *err, size_t errlen)
{
    lt_rng_t   r;
    lt_item_t  e;
    unsigned32 i;
    int        bad = 0;

    lt_rng_init(&r, key, stream);
    for (i = 0; i < len; i++)
    {
        gen_item(&r, i, &e);
        if (item_differs(&items[i], &e) && bad++ == 0)
            lt_errf(err, errlen, "items[%u] differs (of %u)", i, len);
    }
    return bad;
}

/* lt_union ----------------------------------------------------------------- */

static void gen_var(lt_rng_t *r, const lt_key_t *key, lt_var_t *v, char *sbuf)
{
    static const idl_long_int k32_normal[] = { 0, 1, 2, 3 };
    static const idl_long_int k32_wide[] = { 0, 1, 2, 3, 65536, -1 };

    memset(v, 0, sizeof *v);

    v->k8 = (idl_small_int) lt_rng_below(r, 4);
    switch (v->k8)
    {
        case 1: v->u8.l = (idl_long_int) lt_rng_next(r); break;
        case 2: v->u8.d = gen_double(r); break;
        case 3: gen_item(r, 3, &v->u8.item); break;
    }

    v->k16 = (idl_short_int) (1 + lt_rng_below(r, 4));
    switch (v->k16)
    {
        case 1: v->u16.b = (idl_small_int) lt_rng_next(r); break;
        case 2: lt_hyper_set(&v->u16.h, (int64_t) lt_rng_next(r)); break;
        case 3: v->u16.s = (idl_char *) gen_string(r, sbuf, lt_max_name, 0); break;
        default: v->u16.other = (idl_long_int) lt_rng_next(r); break;
    }

    if (key->flags & LT_F_WIDE_SWITCH)
        v->k32 = k32_wide[lt_rng_below(r, 6)];
    else
        v->k32 = k32_normal[lt_rng_below(r, 4)];
    switch (v->k32)
    {
        case 1: v->u32.w = (idl_short_int) lt_rng_next(r); break;
        case 2:
        case 3: gen_item(r, 32, &v->u32.item); break;
        case 65536: v->u32.big = gen_double(r); break;
        case -1: v->u32.neg = (idl_ulong_int) lt_rng_next(r); break;
    }

    v->eu.kind = (idl_short_int) (1 + lt_rng_below(r, 4));
    switch (v->eu.kind)
    {
        case 1: v->eu.v.l = (idl_long_int) lt_rng_next(r); break;
        case 2: v->eu.v.d = gen_double(r); break;
        case 3: gen_item(r, 33, &v->eu.v.item); break;
    }
}

void lt_gen_vars(const lt_key_t *key, unsigned int stream, unsigned32 n,
                 lt_var_t *vars)
{
    char       sbuf[lt_max_name + 1];
    lt_rng_t   r;
    unsigned32 i;

    lt_rng_init(&r, key, stream);
    for (i = 0; i < n; i++)
    {
        gen_var(&r, key, &vars[i], sbuf);
        if (vars[i].k16 == 3)
            vars[i].u16.s = (idl_char *) dup_string((char *) vars[i].u16.s);
    }
}

static int var_differs(const lt_var_t *a, const lt_var_t *e, const char **what)
{
    *what = "k8";
    if (a->k8 != e->k8)
        return 1;
    *what = "u8";
    switch (e->k8)
    {
        case 1: if (a->u8.l != e->u8.l) return 1; break;
        case 2: if (memcmp(&a->u8.d, &e->u8.d, sizeof e->u8.d)) return 1; break;
        case 3: if (item_differs(&a->u8.item, &e->u8.item)) return 1; break;
    }
    *what = "k16";
    if (a->k16 != e->k16)
        return 1;
    *what = "u16";
    switch (e->k16)
    {
        case 1: if (a->u16.b != e->u16.b) return 1; break;
        case 2: if (lt_hyper_get(&a->u16.h) != lt_hyper_get(&e->u16.h)) return 1; break;
        case 3: if (str_differs(a->u16.s, (char *) e->u16.s)) return 1; break;
        default: if (a->u16.other != e->u16.other) return 1; break;
    }
    *what = "k32";
    if (a->k32 != e->k32)
        return 1;
    *what = "u32";
    switch (e->k32)
    {
        case 1: if (a->u32.w != e->u32.w) return 1; break;
        case 2:
        case 3: if (item_differs(&a->u32.item, &e->u32.item)) return 1; break;
        case 65536: if (memcmp(&a->u32.big, &e->u32.big, sizeof e->u32.big)) return 1; break;
        case -1: if (a->u32.neg != e->u32.neg) return 1; break;
    }
    *what = "eu.kind";
    if (a->eu.kind != e->eu.kind)
        return 1;
    *what = "eu.v";
    switch (e->eu.kind)
    {
        case 1: if (a->eu.v.l != e->eu.v.l) return 1; break;
        case 2: if (memcmp(&a->eu.v.d, &e->eu.v.d, sizeof e->eu.v.d)) return 1; break;
        case 3: if (item_differs(&a->eu.v.item, &e->eu.v.item)) return 1; break;
    }
    return 0;
}

int lt_check_vars(const lt_key_t *key, unsigned int stream, unsigned32 n,
                  const lt_var_t *vars, char *err, size_t errlen)
{
    char       sbuf[lt_max_name + 1];
    const char *what;
    lt_rng_t   r;
    lt_var_t   e;
    unsigned32 i;
    int        bad = 0;

    lt_rng_init(&r, key, stream);
    for (i = 0; i < n; i++)
    {
        gen_var(&r, key, &e, sbuf);
        if (var_differs(&vars[i], &e, &what) && bad++ == 0)
            lt_errf(err, errlen, "vars[%u].%s differs (k8 %d/%d k16 %d/%d k32 %ld/%ld)",
                    i, what, vars[i].k8, e.k8, vars[i].k16, e.k16,
                    (long) vars[i].k32, (long) e.k32);
    }
    return bad;
}

/* lt_list ------------------------------------------------------------------ */

static unsigned32 list_len(lt_rng_t *r)
{
    return lt_rng_below(r, 9);
}

lt_node_t *lt_gen_list(const lt_key_t *key, unsigned int stream)
{
    char       lbuf[lt_max_name + 1];
    lt_rng_t   r;
    lt_node_t  *head = NULL, **tail = &head;
    unsigned32 i, len;

    lt_rng_init(&r, key, stream);
    len = list_len(&r);
    for (i = 0; i < len; i++)
    {
        lt_node_t *n = (*lt_alloc)(sizeof *n);

        n->value = (idl_ulong_int) lt_rng_next(&r);
        n->label = (idl_char *) dup_string(gen_string(&r, lbuf, 24, 1));
        n->next = NULL;
        *tail = n;
        tail = &n->next;
    }
    return head;
}

int lt_check_list(const lt_key_t *key, unsigned int stream,
                  const lt_node_t *list, char *err, size_t errlen)
{
    char       lbuf[lt_max_name + 1];
    lt_rng_t   r;
    unsigned32 i, len;
    int        bad = 0;

    lt_rng_init(&r, key, stream);
    len = list_len(&r);
    for (i = 0; i < len; i++, list = list->next)
    {
        idl_ulong_int value;
        char          *label;

        if (list == NULL)
        {
            lt_errf(err, errlen, "list has %u nodes, expected %u", i, len);
            return bad + 1;
        }
        value = (idl_ulong_int) lt_rng_next(&r);
        label = gen_string(&r, lbuf, 24, 1);
        if ((list->value != value || str_differs(list->label, label)) && bad++ == 0)
            lt_errf(err, errlen, "list node %u differs", i);
    }
    if (list != NULL)
    {
        lt_errf(err, errlen, "list longer than %u nodes", len);
        bad++;
    }
    return bad;
}

/* lt_graph ----------------------------------------------------------------- */

unsigned32 lt_graph_nodes(unsigned32 n)
{
    return n / 2 + 1;
}

/*
 * Generates the structure: target[i] = node index of slot i or -1,
 * next[k] = node index of nodes[k].next or -1, visits[k] = initial visits.
 */
static void gen_graph_shape(const lt_key_t *key, unsigned32 n, long *target,
                            long *next, idl_ulong_int *visits)
{
    lt_rng_t   r;
    unsigned32 m = lt_graph_nodes(n), i;

    lt_rng_init(&r, key, LT_REQ + 200);
    for (i = 0; i < m; i++)
    {
        uint32_t t = lt_rng_below(&r, m + 1);

        next[i] = t == m ? -1 : (long) t;
        visits[i] = lt_rng_below(&r, 1000);
    }
    for (i = 0; i < n; i++)
        target[i] = lt_rng_below(&r, 8) == 0 ? -1 : (long) lt_rng_below(&r, m);
}

void lt_gen_graph(const lt_key_t *key, unsigned32 n, lt_gnode_t *nodes,
                  lt_gnode_p_t *slots)
{
    unsigned32    m = lt_graph_nodes(n), i;
    long          *target = malloc(n * sizeof *target + 1);
    long          *next = malloc(m * sizeof *next);
    idl_ulong_int *visits = malloc(m * sizeof *visits);

    gen_graph_shape(key, n, target, next, visits);
    for (i = 0; i < m; i++)
    {
        nodes[i].id = i + 1;
        nodes[i].visits = visits[i];
        nodes[i].next = next[i] < 0 ? NULL : &nodes[next[i]];
    }
    for (i = 0; i < n; i++)
        slots[i] = target[i] < 0 ? NULL : &nodes[target[i]];
    free(target);
    free(next);
    free(visits);
}

int lt_check_graph(const lt_key_t *key, unsigned32 n, lt_gnode_p_t *slots,
                   unsigned32 visits_per_ref, char *err, size_t errlen)
{
    unsigned32    m = lt_graph_nodes(n), i;
    long          *target = malloc(n * sizeof *target + 1);
    long          *next = malloc(m * sizeof *next);
    idl_ulong_int *visits = malloc(m * sizeof *visits);
    unsigned32    *refs = calloc(m, sizeof *refs);
    lt_gnode_p_t  *seen = calloc(m, sizeof *seen);    /* node index -> address */
    int           bad = 0;

    gen_graph_shape(key, n, target, next, visits);

    /* slots: right node, and one address per node (aliasing kept) */
    for (i = 0; i < n; i++)
    {
        lt_gnode_p_t p = slots[i];

        if ((p == NULL) != (target[i] < 0))
        {
            if (bad++ == 0)
                lt_errf(err, errlen, "slot %u is %sNULL", i, p == NULL ? "" : "not ");
            continue;
        }
        if (p == NULL)
            continue;
        if (p->id != (idl_ulong_int) target[i] + 1)
        {
            if (bad++ == 0)
                lt_errf(err, errlen, "slot %u points to node %u, expected %ld",
                        i, p->id, target[i] + 1);
            continue;
        }
        if (seen[target[i]] == NULL)
            seen[target[i]] = p;
        else if (seen[target[i]] != p && bad++ == 0)
            lt_errf(err, errlen, "slot %u: node %ld has two addresses (aliasing lost)",
                    i, target[i] + 1);
        refs[target[i]]++;
    }

    /* next pointers and visit counters of the nodes reachable from slots */
    for (i = 0; i < m; i++)
    {
        lt_gnode_p_t p = seen[i], q;

        if (p == NULL)
            continue;
        if (p->visits != visits[i] + visits_per_ref * refs[i] && bad++ == 0)
            lt_errf(err, errlen, "node %u: visits %u, expected %u",
                    i + 1, p->visits, visits[i] + visits_per_ref * refs[i]);
        q = p->next;
        if ((q == NULL) != (next[i] < 0))
        {
            if (bad++ == 0)
                lt_errf(err, errlen, "node %u: next is %sNULL", i + 1, q == NULL ? "" : "not ");
            continue;
        }
        if (q == NULL)
            continue;
        if (q->id != (idl_ulong_int) next[i] + 1)
        {
            if (bad++ == 0)
                lt_errf(err, errlen, "node %u: next is node %u, expected %ld",
                        i + 1, q->id, next[i] + 1);
            continue;
        }
        if (seen[next[i]] != NULL && seen[next[i]] != q && bad++ == 0)
            lt_errf(err, errlen, "node %u: next node %ld has two addresses",
                    i + 1, next[i] + 1);
    }

    free(target);
    free(next);
    free(visits);
    free(refs);
    free(seen);
    return bad;
}

/* pipes -------------------------------------------------------------------- */

idl_ulong_int lt_pipe_elt(const lt_key_t *key, unsigned int stream, unsigned32 i)
{
    return (idl_ulong_int) mix(key_base(key, stream) ^ i);
}
