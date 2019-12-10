/* Generated by IDL compiler version FreeDCE 1.0.1 64-bit with GNU Flex/Bison */
#ifndef perfb_v1_0_included
#define perfb_v1_0_included
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
typedef idl_ulong_int perfb_data_t[1];
#define perfb_large_size (0xbb8)
extern void perfb_init(
#ifdef IDL_PROTOTYPES
    /* [in] */ handle_t handle,
    /* [out] */ idl_char name[256]
#endif
);
extern void perfb_in(
#ifdef IDL_PROTOTYPES
    /* [in] */ handle_t handle,
    /* [in] */ perfb_data_t data,
    /* [in] */ idl_ulong_int l,
    /* [in] */ idl_boolean v,
    /* [out] */ idl_ulong_int *sum
#endif
);
extern void perfb_brd(
#ifdef IDL_PROTOTYPES
    /* [in] */ handle_t handle,
    /* [out] */ idl_char name[256]
#endif
);
extern void perfb_null(
#ifdef IDL_PROTOTYPES
    /* [in] */ handle_t handle
#endif
);
extern void perfb_null_idem(
#ifdef IDL_PROTOTYPES
    /* [in] */ handle_t handle
#endif
);
typedef struct perfb_v1_0_epv_t {
	void (*perfb_init)(
#ifdef IDL_PROTOTYPES
    /* [in] */ handle_t handle,
    /* [out] */ idl_char name[256]
#endif
);
	void (*perfb_in)(
#ifdef IDL_PROTOTYPES
    /* [in] */ handle_t handle,
    /* [in] */ perfb_data_t data,
    /* [in] */ idl_ulong_int l,
    /* [in] */ idl_boolean v,
    /* [out] */ idl_ulong_int *sum
#endif
);
	void (*perfb_brd)(
#ifdef IDL_PROTOTYPES
    /* [in] */ handle_t handle,
    /* [out] */ idl_char name[256]
#endif
);
	void (*perfb_null)(
#ifdef IDL_PROTOTYPES
    /* [in] */ handle_t handle
#endif
);
	void (*perfb_null_idem)(
#ifdef IDL_PROTOTYPES
    /* [in] */ handle_t handle
#endif
);
} perfb_v1_0_epv_t;
extern rpc_if_handle_t perfb_v1_0_c_ifspec;
extern rpc_if_handle_t perfb_v1_0_s_ifspec;

#ifdef __cplusplus
    }
#endif

#endif
