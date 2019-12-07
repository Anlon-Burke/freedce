/* Generated by IDL compiler version FreeDCE 1.1.0.7 64-bit with GNU Flex/Bison */
#ifndef mgmt_v1_0_included
#define mgmt_v1_0_included
#ifndef IDLBASE_H
#include <dce/idlbase.h>
#endif
#include <dce/rpc.h>

#ifdef __cplusplus
    extern "C" {
#endif

#ifndef nbase_v0_0_included
#include <dce/nbase.h>
#endif
#ifndef rpctypes_v0_0_included
#include <dce/rpctypes.h>
#endif
extern void rpc__mgmt_inq_if_ids(
#ifdef IDL_PROTOTYPES
    /* [in] */ handle_t binding_handle,
    /* [out] */ rpc_if_id_vector_p_t *if_id_vector,
    /* [out] */ error_status_t *status
#endif
);
extern void rpc__mgmt_inq_stats(
#ifdef IDL_PROTOTYPES
    /* [in] */ handle_t binding_handle,
    /* [in, out] */ unsigned32 *count,
    /* [out] */ unsigned32 statistics[],
    /* [out] */ error_status_t *status
#endif
);
extern boolean32 rpc__mgmt_is_server_listening(
#ifdef IDL_PROTOTYPES
    /* [in] */ handle_t binding_handle,
    /* [out] */ error_status_t *status
#endif
);
extern void rpc__mgmt_stop_server_listening(
#ifdef IDL_PROTOTYPES
    /* [in] */ handle_t binding_handle,
    /* [out] */ error_status_t *status
#endif
);
extern void rpc__mgmt_inq_princ_name(
#ifdef IDL_PROTOTYPES
    /* [in] */ handle_t binding_handle,
    /* [in] */ unsigned32 authn_proto,
    /* [in] */ unsigned32 princ_name_size,
    /* [out] */ idl_char princ_name[],
    /* [out] */ error_status_t *status
#endif
);
typedef struct mgmt_v1_0_epv_t {
	void (*rpc__mgmt_inq_if_ids)(
#ifdef IDL_PROTOTYPES
    /* [in] */ handle_t binding_handle,
    /* [out] */ rpc_if_id_vector_p_t *if_id_vector,
    /* [out] */ error_status_t *status
#endif
);
	void (*rpc__mgmt_inq_stats)(
#ifdef IDL_PROTOTYPES
    /* [in] */ handle_t binding_handle,
    /* [in, out] */ unsigned32 *count,
    /* [out] */ unsigned32 statistics[],
    /* [out] */ error_status_t *status
#endif
);
	boolean32 (*rpc__mgmt_is_server_listening)(
#ifdef IDL_PROTOTYPES
    /* [in] */ handle_t binding_handle,
    /* [out] */ error_status_t *status
#endif
);
	void (*rpc__mgmt_stop_server_listening)(
#ifdef IDL_PROTOTYPES
    /* [in] */ handle_t binding_handle,
    /* [out] */ error_status_t *status
#endif
);
	void (*rpc__mgmt_inq_princ_name)(
#ifdef IDL_PROTOTYPES
    /* [in] */ handle_t binding_handle,
    /* [in] */ unsigned32 authn_proto,
    /* [in] */ unsigned32 princ_name_size,
    /* [out] */ idl_char princ_name[],
    /* [out] */ error_status_t *status
#endif
);
} mgmt_v1_0_epv_t;
extern mgmt_v1_0_epv_t mgmt_v1_0_c_epv;
extern rpc_if_handle_t mgmt_v1_0_c_ifspec;
extern rpc_if_handle_t mgmt_v1_0_s_ifspec;

#ifdef __cplusplus
    }
#endif

#endif
