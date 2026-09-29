/*
 * errtext.c - "make check" for dce_error_inq_text(): every kind of status code gets its
 * built-in text (dce_error_table.h, generated from rpcsts.idl and ncastat.idl), unknown
 * codes still give "status <hex>" with status -1.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dce/rpc.h>
#include <dce/dce_error.h>

static int fails;

static void expect(unsigned32 st, const char *part, int want_status)
{
    dce_error_string_t  text;
    int                 ist = 99;

    dce_error_inq_text(st, text, &ist);
    if (ist != want_status || strstr((char *) text, part) == NULL)
    {
        printf("FAIL 0x%08x: status %d, text \"%s\" (expected %d and \"%s\")\n",
               (unsigned) st, ist, (char *) text, want_status, part);
        fails++;
    }
    else
        printf("ok   0x%08x: %s\n", (unsigned) st, (char *) text);
}

int main(void)
{
    /* the built-in texts, not a catalog that happens to be on this machine */
    unsetenv("NLSPATH");

    expect(0, "successful completion", 0);
    expect(rpc_s_connection_closed, "connection closed (rpc_s_connection_closed)", 0);
    expect(rpc_s_comm_failure, "(rpc_s_comm_failure)", 0);
    expect(rpc_s_invalid_endpoint_format, "(rpc_s_invalid_endpoint_format)", 0);
    expect(rpc_s_ss_no_compat_codeset, "no compat codeset (rpc_s_ss_no_compat_codeset)", 0);
    expect(rpc_s_fault_codeset_conv_error, "(rpc_s_fault_codeset_conv_error)", 0);
    expect(ept_s_not_registered, "(ept_s_not_registered)", 0);
    expect(uuid_s_invalid_string_uuid, "(uuid_s_invalid_string_uuid)", 0);
    expect(twr_s_unknown_tower, "(twr_s_unknown_tower)", 0);
    expect(rpc_m_ctxrundown_nomem, "(rpc_m_ctxrundown_nomem)", 0);
    expect(0x1C010001, "unable to get response from server (nca_s_comm_failure)", 0);
    expect(0x1C000023, "(nca_s_fault_codeset_conv_error)", 0);
    /* codes without a text */
    expect(0x16c9afff, "status 16c9afff", -1);
    expect(0x70000001, "unknown facility", -1);

    printf("%s\n", fails ? "errtext: FAILED" : "errtext: all texts found");
    return fails != 0;
}
