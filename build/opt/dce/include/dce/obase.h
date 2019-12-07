/* Generated by IDL compiler version FreeDCE 1.1.0.7 64-bit with GNU Flex/Bison */
#ifndef ObjectRpcBaseTypes_v0_0_included
#define ObjectRpcBaseTypes_v0_0_included
#ifndef IDLBASE_H
#include <dce/idlbase.h>
#endif

#ifdef __cplusplus
    extern "C" {
#endif

#ifndef nbase_v0_0_included
#include <dce/nbase.h>
#endif
#ifndef FreeDCEORPCTypes_v0_0_included
#include <dce/wtypes.h>
#endif
typedef idl_uhyper_int ID;
typedef ID MID;
typedef ID OXID;
typedef ID OID;
typedef ID SETID;
typedef GUID IPID;
typedef GUID CID;
typedef REFGUID REFIPID;
#define COM_MINOR_VERSION_1 (0x1)
#define COM_MINOR_VERSION_2 (0x2)
#define COM_MAJOR_VERSION (0x5)
#define COM_MINOR_VERSION (0x3)
typedef struct tagCOMVERSION {
idl_ushort_int MajorVersion;
idl_ushort_int MinorVersion;
} COMVERSION;
#define ORPCF_NULL (0x0)
#define ORPCF_LOCAL (0x1)
#define ORPCF_RESERVED1 (0x2)
#define ORPCF_RESERVED2 (0x4)
#define ORPCF_RESERVED3 (0x8)
#define ORPCF_RESERVED4 (0x10)
typedef struct tagORPC_EXTENT {
GUID id;
idl_ulong_int size;
idl_byte data[1];
} ORPC_EXTENT;
typedef struct tagORPC_EXTENT_ARRAY {
idl_ulong_int size;
idl_ulong_int reserved;
ORPC_EXTENT **extent;
} ORPC_EXTENT_ARRAY;
typedef struct tagORPCTHIS {
COMVERSION version;
idl_ulong_int flags;
idl_ulong_int reserved1;
CID cid;
ORPC_EXTENT_ARRAY *extensions;
} ORPCTHIS;
typedef struct tagORPCTHAT {
idl_ulong_int flags;
ORPC_EXTENT_ARRAY *extensions;
} ORPCTHAT;
#define NCADG_IP_UDP (0x8)
#define NCACN_IP_TCP (0x7)
#define NCADG_IPX (0xe)
#define NCACN_SPX (0xc)
#define NCACN_NB_NB (0x12)
#define NCACN_NB_IPX (0xd)
#define NCACN_DNET_NSP (0x4)
#define NCACN_HTTP (0x1f)
typedef struct tagSTRINGBINDING {
idl_ushort_int wTowerId;
idl_ushort_int aNetworkAddr;
} STRINGBINDING;
#define COM_C_AUTHZ_NONE (0xffff)
typedef struct tagSECURITYBINDING {
idl_ushort_int wAuthnSvc;
idl_ushort_int wAuthzSvc;
idl_ushort_int aPrincName;
} SECURITYBINDING;
typedef struct tagDUALSTRINGARRAY {
idl_ushort_int wNumEntries;
idl_ushort_int wSecurityOffset;
idl_ushort_int aStringArray[1];
} DUALSTRINGARRAY;
#define OBJREF_SIGNATURE (0x574f454d)
#define OBJREF_STANDARD (0x1)
#define OBJREF_HANDLER (0x2)
#define OBJREF_CUSTOM (0x4)
#define SORF_OXRES1 (0x1)
#define SORF_OXRES2 (0x20)
#define SORF_OXRES3 (0x40)
#define SORF_OXRES4 (0x80)
#define SORF_OXRES5 (0x100)
#define SORF_OXRES6 (0x200)
#define SORF_OXRES7 (0x400)
#define SORF_OXRES8 (0x800)
#define SORF_NULL (0x0)
#define SORF_NOPING (0x1000)
typedef struct tagSTDOBJREF {
idl_ulong_int flags;
idl_ulong_int cPublicRefs;
OXID oxid;
OID oid;
IPID ipid;
} STDOBJREF;
typedef struct tagOBJREF {
idl_ulong_int signature;
idl_ulong_int flags;
GUID iid;
} OBJREF;
typedef struct tagMInterfacePointer {
ULONG ulCntData;
BYTE abData[1];
} MInterfacePointer;
typedef MInterfacePointer *PMInterfacePointer;

#ifdef __cplusplus
    }
#endif

#endif
