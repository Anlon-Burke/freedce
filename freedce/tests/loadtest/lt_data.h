/*
 * lt_data.h: deterministic test data for the load test.
 *
 * Client and server generate the same data from an lt_key_t, so each side
 * can check everything it receives.  A "stream" separates the request data
 * (sent by the client) from the reply data (sent by the server).
 */
#ifndef LT_DATA_H
#define LT_DATA_H

#include "lt_port.h"
#include "loadtest.h"

/* lt_key_t.flags */
#define LT_F_WIDE_SWITCH    0x1     /* long union discriminants > 16 bits */

/* streams */
#define LT_REQ              1
#define LT_REP              2

/* operation numbers (index into lt_stats_t.calls) */
enum
{
    LT_OP_NULL, LT_OP_NULL_IDEM, LT_OP_STRUCT, LT_OP_ARRAY, LT_OP_UNION,
    LT_OP_LIST, LT_OP_GRAPH, LT_OP_PIPE_IN, LT_OP_PIPE_OUT, LT_OP_OPEN,
    LT_OP_CTX_OP, LT_OP_CLOSE, LT_OP_SLOW, LT_OP_STATS, LT_OP_MAYBE,
    LT_OP_PTRARR, LT_OP_PTRBOX, LT_N_OPS
};

extern const char *lt_op_names[LT_N_OPS];

typedef struct
{
    uint64_t s;
} lt_rng_t;

void lt_rng_init(lt_rng_t *r, const lt_key_t *key, unsigned int stream);
uint64_t lt_rng_next(lt_rng_t *r);
uint32_t lt_rng_below(lt_rng_t *r, uint32_t n);    /* 0 .. n-1 */

/*
 * Allocator for pointed-to data: malloc on the client, rpc_ss_allocate in
 * a server manager.  Set by the program before generating data.
 */
extern idl_void_p_t (*lt_alloc)(idl_size_t size);

/*
 * Checks append a description of the first differences to err (size
 * errlen) and return the number of differences.
 */

/* lt_struct */
void lt_gen_rec(const lt_key_t *key, unsigned int stream, lt_rec_t *rec);
int lt_check_rec(const lt_key_t *key, unsigned int stream, const lt_rec_t *rec,
                 char *err, size_t errlen);

/* lt_array: number of reply elements for a request array of capacity max */
unsigned32 lt_reply_len(const lt_key_t *key, unsigned32 max);
void lt_gen_items(const lt_key_t *key, unsigned int stream, unsigned32 len,
                  lt_item_t *items);
int lt_check_items(const lt_key_t *key, unsigned int stream, unsigned32 len,
                   const lt_item_t *items, char *err, size_t errlen);

/* lt_union */
void lt_gen_vars(const lt_key_t *key, unsigned int stream, unsigned32 n,
                 lt_var_t *vars);
int lt_check_vars(const lt_key_t *key, unsigned int stream, unsigned32 n,
                  const lt_var_t *vars, char *err, size_t errlen);

/* lt_list: returns the head (NULL for an empty list) */
lt_node_t *lt_gen_list(const lt_key_t *key, unsigned int stream);
int lt_check_list(const lt_key_t *key, unsigned int stream,
                  const lt_node_t *list, char *err, size_t errlen);

/*
 * lt_graph: n slots pointing into lt_graph_nodes(n) nodes.  nodes must
 * have room for lt_graph_nodes(n) elements.  lt_check_graph checks the
 * structure (node ids, aliasing) and that every node's visits counter
 * equals its initial value plus visits_per_ref times its number of
 * references from slots.
 */
unsigned32 lt_graph_nodes(unsigned32 n);
void lt_gen_graph(const lt_key_t *key, unsigned32 n, lt_gnode_t *nodes,
                  lt_gnode_p_t *slots);
int lt_check_graph(const lt_key_t *key, unsigned32 n, lt_gnode_p_t *slots,
                   unsigned32 visits_per_ref, char *err, size_t errlen);

/* pipes: element i of a pipe */
idl_ulong_int lt_pipe_elt(const lt_key_t *key, unsigned int stream,
                          unsigned32 i);

/* error text helper */
void lt_errf(char *err, size_t errlen, const char *fmt, ...)
    LT_FORMAT(3, 4);

#endif
