/* Generated by IDL compiler version FreeDCE 1.0.1 64-bit with GNU Flex/Bison */
#ifndef uuid_v0_0_included
#define uuid_v0_0_included
#ifndef IDLBASE_H
#include <dce/idlbase.h>
#endif

#ifdef __cplusplus
    extern "C" {
#endif

#ifndef nbase_v0_0_included
#include <dce/nbase.h>
#endif
#ifndef lbase_v0_0_included
#include <dce/lbase.h>
#endif
#define uuid_c_version (0x1)
#define uuid_c_version_highest (0x2)
typedef struct  {
unsigned32 count;
uuid_p_t uuid[1];
} uuid_vector_t;
typedef uuid_vector_t *uuid_vector_p_t;
#define uuid_s_ok error_status_ok
extern void uuid_create(
#ifdef IDL_PROTOTYPES
    /* [out] */ uuid_t *uuid,
    /* [out] */ unsigned32 *status
#endif
);
extern void uuid_create_nil(
#ifdef IDL_PROTOTYPES
    /* [out] */ uuid_t *uuid,
    /* [out] */ unsigned32 *status
#endif
);
extern void uuid_to_string(
#ifdef IDL_PROTOTYPES
    /* [in] */ uuid_p_t uuid,
    /* [out] */ unsigned_char_p_t *uuid_string,
    /* [out] */ unsigned32 *status
#endif
);
extern void uuid_from_string(
#ifdef IDL_PROTOTYPES
    /* [in] */ unsigned_char_p_t uuid_string,
    /* [out] */ uuid_t *uuid,
    /* [out] */ unsigned32 *status
#endif
);
extern boolean32 uuid_equal(
#ifdef IDL_PROTOTYPES
    /* [in] */ uuid_p_t uuid1,
    /* [in] */ uuid_p_t uuid2,
    /* [out] */ unsigned32 *status
#endif
);
extern boolean32 uuid_is_nil(
#ifdef IDL_PROTOTYPES
    /* [in] */ uuid_p_t uuid,
    /* [out] */ unsigned32 *status
#endif
);
extern signed32 uuid_compare(
#ifdef IDL_PROTOTYPES
    /* [in] */ uuid_p_t uuid1,
    /* [in] */ uuid_p_t uuid2,
    /* [out] */ unsigned32 *status
#endif
);
extern unsigned16 uuid_hash(
#ifdef IDL_PROTOTYPES
    /* [in] */ uuid_p_t uuid,
    /* [out] */ unsigned32 *status
#endif
);

#ifdef __cplusplus
    }
#endif

#endif
