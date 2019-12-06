/* Generated by IDL compiler */
#ifndef FreeDCEOWinNTTypes_v0_0_included
#define FreeDCEOWinNTTypes_v0_0_included
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
#include <wtypes.h>
#endif
typedef LONG NTSTATUS;
typedef NTSTATUS *PNTSTATUS;
typedef DWORD ACCESS_MASK;
typedef ACCESS_MASK *PACCESS_MASK;
typedef struct  {
DWORD low;
LONG high;
} LUID;
typedef LUID *PLUID;
typedef struct  {
LUID luid;
DWORD attr;
} LUID_AND_ATTRIBUTES;
typedef LUID_AND_ATTRIBUTES *PLUID_AND_ATTRIBUTES;
typedef struct  {
DWORD count;
DWORD control;
PLUID_AND_ATTRIBUTES luids;
} PRIVILEGE_SET;
typedef PRIVILEGE_SET *PPRIVILEGE_SET;
typedef struct  {
ULONG count;
PLUID_AND_ATTRIBUTES luids;
} LUID_AND_ATTRIBUTES_ARRAY;
typedef LUID_AND_ATTRIBUTES_ARRAY *PLUID_AND_ATTRIBUTES_ARRAY;
typedef LUID_AND_ATTRIBUTES_ARRAY TOKEN_PRIVILEGES;
typedef PLUID_AND_ATTRIBUTES_ARRAY PTOKEN_PRIVILEGES;
typedef struct  {
USHORT length;
USHORT size;
WCHAR *string;
} UNICODE_STRING;
typedef UNICODE_STRING *PUNICODE_STRING;
typedef UNICODE_STRING LSA_UNICODE_STRING;
typedef PUNICODE_STRING PLSA_UNICODE_STRING;
typedef struct  {
idl_long_int count;
PUNICODE_STRING string;
} UNICODE_STRING_ARRAY;
typedef UNICODE_STRING_ARRAY *PUNICODE_STRING_ARRAY;
typedef UNICODE_STRING_ARRAY LSA_UNICODE_STRING_ARRAY;
typedef PUNICODE_STRING_ARRAY PLSA_UNICODE_STRING_ARRAY;
typedef struct  {
USHORT length;
USHORT size;
CHAR *string;
} STRING;
typedef STRING *PSTRING;
typedef STRING LSA_STRING;
typedef PSTRING PLSA_STRING;
typedef struct  {
ULONG count;
PSTRING string;
} STRING_ARRAY;
typedef STRING_ARRAY *PSTRING_ARRAY;
typedef STRING_ARRAY LSA_STRING_ARRAY;
typedef PSTRING_ARRAY PLSA_STRING_ARRAY;
#define SPECIFIC_RIGHTS_MASK (0xffff)
#define STANDARD_RIGHTS_MASK (0xff0000)
#define DELETE_ACCESS (0x10000)
#define READ_CONTROL_ACCESS (0x20000)
#define WRITE_DAC_ACCESS (0x40000)
#define WRITE_OWNER_ACCESS (0x80000)
#define SYNCHRONIZE_ACCESS (0x100000)
#define SYSTEM_SECURITY_ACCESS (0x1000000)
#define MAXIMUM_ALLOWED_ACCESS (0x2000000)
#define GENERIC_ALL_ACCESS (0x8000000)
#define GENERIC_EXECUTE_ACCESS (0x10000000)
#define GENERIC_WRITE_ACCESS (0x20000000)
#define GENERIC_READ_ACCESS (0x40000000)
#define STANDARD_RIGHTS_READ READ_CONTROL_ACCESS
#define STANDARD_RIGHTS_WRITE STANDARD_RIGHTS_READ
#define STANDARD_RIGHTS_EXECUTE STANDARD_RIGHTS_READ
#define STANDARD_RIGHTS_REQUIRED (0xf0000)
#define SEC_RIGHTS_QUERY_VALUE (0x1)
#define SEC_RIGHTS_SET_VALUE (0x2)
#define SEC_RIGHTS_CREATE_SUBKEY (0x4)
#define SEC_RIGHTS_ENUM_SUBKEYS (0x8)
#define SEC_RIGHTS_NOTIFY (0x10)
#define SEC_RIGHTS_CREATE_LINK (0x20)
#define SEC_RIGHTS_DELETE DELETE_ACCESS
#define SEC_RIGHTS_READ_CONTROL READ_CONTROL_ACCESS
#define SEC_RIGHTS_WRITE_DAC WRITE_DAC_ACCESS
#define SEC_RIGHTS_WRITE_OWNER WRITE_OWNER_ACCESS
#define SEC_RIGHTS_MAXIMUM_ALLOWED MAXIMUM_ALLOWED_ACCESS
#define SEC_RIGHTS_READ (0x20009)
#define SEC_RIGHTS_FULL_CONTROL (0xf003f)
#define SEC_ACE_TYPE_ACCESS_ALLOWED (0x0)
#define SEC_ACE_TYPE_ACCESS_DENIED (0x1)
#define SEC_ACE_TYPE_SYSTEM_AUDIT (0x2)
#define SEC_ACE_TYPE_SYSTEM_ALARM (0x3)
#define SEC_ACE_FLAG_OBJECT_INHERIT (0x1)
#define SEC_ACE_FLAG_CONTAINER_INHERIT (0x2)
#define SEC_ACE_FLAG_NO_PROPAGATE_INHERIT (0x4)
#define SEC_ACE_FLAG_INHERIT_ONLY (0x8)
#define SEC_ACE_FLAG_INHERITED_ACE (0x10)
#define SEC_ACE_FLAG_VALID_INHERIT (0xf)
#define SEC_ACE_FLAG_SUCCESSFUL_ACCESS (0x40)
#define SEC_ACE_FLAG_FAILED_ACCESS (0x80)
#define SEC_DESC_OWNER_DEFAULTED (0x1)
#define SEC_DESC_GROUP_DEFAULTED (0x2)
#define SEC_DESC_DACL_PRESENT (0x4)
#define SEC_DESC_DACL_DEFAULTED (0x8)
#define SEC_DESC_SACL_PRESENT (0x10)
#define SEC_DESC_SACL_DEFAULTED (0x20)
#define SE_DESC_DACL_AUTO_INHERIT_REQ (0x100)
#define SE_DESC_SACL_AUTO_INHERIT_REQ (0x200)
#define SE_DESC_DACL_AUTO_INHERITED (0x400)
#define SE_DESC_SACL_AUTO_INHERITED (0x800)
#define SE_DESC_DACL_PROTECTED (0x1000)
#define SE_DESC_SACL_PROTECTED (0x2000)
#define SEC_DESC_SELF_RELATIVE (0x8000)
#define OWNER_SECURITY_INFORMATION (0x1)
#define GROUP_SECURITY_INFORMATION (0x2)
#define DACL_SECURITY_INFORMATION (0x4)
#define SACL_SECURITY_INFORMATION (0x8)
#define ALL_SECURITY_INFORMATION (0xf)
#define NT4_ACL_REVISION (0x2)
#define ACL_REVISION (0x3)
#define SEC_DESC_REVISION (0x1)
typedef struct  {
ULONG size;
BYTE *buffer;
} LSA_SECURITY_DESCRIPTOR;
typedef LSA_SECURITY_DESCRIPTOR *PLSA_SECURITY_DESCRIPTOR;
typedef struct  {
LSA_SECURITY_DESCRIPTOR sd;
BOOL inherit;
} SECURITY_ATTRIBUTES;
typedef SECURITY_ATTRIBUTES *PSECURITY_ATTRIBUTES;
typedef struct  {
BYTE value[6];
} SID_IDENTIFIER_AUTHORITY;
typedef struct  {
BYTE revision;
BYTE subauth_count;
SID_IDENTIFIER_AUTHORITY authority;
DWORD subauth[1];
} SID;
typedef SID *PISID;
typedef struct  {
SID *sid;
} PSID;
typedef struct  {
ULONG count;
PSID *sids;
} PSID_ARRAY;
#define SidTypeUser (0x1)
#define SidTypeGroup (0x2)
#define SidTypeDomain (0x3)
#define SidTypeAlias (0x4)
#define SidTypeWellKnownGroup (0x5)
#define SidTypeDeletedAccount (0x6)
#define SidTypeInvalid (0x7)
#define SidTypeUnknown (0x8)
#define SidTypeComputer (0x9)
typedef USHORT SID_NAME_USE;
typedef struct  {
SID_NAME_USE use;
ULONG rid;
LONG index;
} LSA_TRANSLATED_SID;
typedef LSA_TRANSLATED_SID *PLSA_TRANSLATED_SID;
typedef struct  {
ULONG count;
PLSA_TRANSLATED_SID rids;
} LSA_TRANSLATED_SIDS;
typedef LSA_TRANSLATED_SIDS *PLSA_TRANSLATED_SIDS;
typedef struct  {
SID_NAME_USE usd;
ULONG rid;
LONG index;
ULONG unknown;
} LSA_TRANSLATED_SID_EX;
typedef LSA_TRANSLATED_SID_EX *PLSA_TRANSLATED_SID_EX;
typedef struct  {
ULONG count;
PLSA_TRANSLATED_SID_EX rids;
} LSA_TRANSLATED_SIDS_EX;
typedef LSA_TRANSLATED_SIDS_EX *PLSA_TRANSLATED_SIDS_EX;
typedef struct  {
SID_NAME_USE use;
LSA_UNICODE_STRING name;
LONG index;
} LSA_TRANSLATED_NAME;
typedef LSA_TRANSLATED_NAME *PLSA_TRANSLATED_NAME;
typedef struct  {
ULONG count;
PLSA_TRANSLATED_NAME domains;
} LSA_TRANSLATED_NAMES;
typedef LSA_TRANSLATED_NAMES *PLSA_TRANSLATED_NAMES;
typedef struct  {
SID_NAME_USE use;
LSA_UNICODE_STRING name;
LONG index;
ULONG unknown;
} LSA_TRANSLATED_NAME_EX;
typedef LSA_TRANSLATED_NAME_EX *PLSA_TRANSLATED_NAME_EX;
typedef struct  {
ULONG count;
PLSA_TRANSLATED_NAME_EX domains;
} LSA_TRANSLATED_NAMES_EX;
typedef LSA_TRANSLATED_NAMES_EX *PLSA_TRANSLATED_NAMES_EX;
typedef struct  {
LSA_UNICODE_STRING name;
LUID luid;
} LSA_PRIVILEGE;
typedef LSA_PRIVILEGE *PLSA_PRIVILEGE;
typedef struct  {
ULONG count;
PLSA_PRIVILEGE info;
} LSA_PRIVILEGES;
typedef LSA_PRIVILEGES *PLSA_PRIVILEGES;
typedef ULONG LSA_ENUMERATION_HANDLE;
typedef LSA_ENUMERATION_HANDLE *PLSA_ENUMERATION_HANDLE;
typedef struct  {
PISID sid;
} LSA_ENUMERATION_INFORMATION;
typedef LSA_ENUMERATION_INFORMATION *PLSA_ENUMERATION_INFORMATION;
typedef struct  {
ULONG percent_full;
ULONG log_size;
LARGE_INTEGER retention_period;
BOOLEAN shutdown_in_progress;
LARGE_INTEGER time_to_shutdown;
ULONG next_audit_record;
} POLICY_AUDIT_LOG_INFO;
typedef POLICY_AUDIT_LOG_INFO *PPOLICY_AUDIT_LOG_INFO;
typedef struct  {
LSA_UNICODE_STRING name;
} POLICY_PD_ACCOUNT_INFO;
typedef POLICY_PD_ACCOUNT_INFO *PPOLICY_PD_ACCOUNT_INFO;
typedef struct  {
BOOLEAN enabled;
ULONG *settings;
ULONG count;
} POLICY_AUDIT_EVENTS_INFO;
typedef POLICY_AUDIT_EVENTS_INFO *PPOLICY_AUDIT_EVENTS_INFO;
typedef struct  {
LSA_UNICODE_STRING domain;
PISID sid;
} POLICY_PRIMARY_DOMAIN_INFO;
typedef POLICY_PRIMARY_DOMAIN_INFO *PPOLICY_PRIMARY_DOMAIN_INFO;
typedef struct  {
LSA_UNICODE_STRING name;
PISID sid;
} POLICY_ACCOUNT_DOMAIN_INFO;
typedef POLICY_ACCOUNT_DOMAIN_INFO *PPOLICY_ACCOUNT_DOMAIN_INFO;
typedef struct  {
ULONG rid_offset;
} TRUSTED_POSIX_OFFSET_INFO;
typedef TRUSTED_POSIX_OFFSET_INFO *PTRUSTED_POSIX_OFFSET_INFO;
typedef LSA_STRING LSA_SECRET;
typedef struct  {
LSA_SECRET current;
LSA_SECRET old;
} TRUSTED_PASSWORD_INFO;
typedef TRUSTED_PASSWORD_INFO *PTRUSTED_PASSWORD_INFO;
typedef struct  {
PISID sid;
DWORD attrib;
} SID_AND_ATTRIBUTES;
typedef SID_AND_ATTRIBUTES *PSID_AND_ATTRIBUTES;
typedef struct  {
ULONG count;
PSID_AND_ATTRIBUTES sids;
} SID_AND_ATTRIBUTES_ARRAY;
typedef SID_AND_ATTRIBUTES_ARRAY *PSID_AND_ATTRIBUTES_ARRAY;
typedef SID_AND_ATTRIBUTES_ARRAY TOKEN_GROUPS;
typedef PSID_AND_ATTRIBUTES_ARRAY PTOKEN_GROUPS;
typedef struct  {
UCHAR revision;
UCHAR reserved;
USHORT size;
USHORT count;
USHORT reserved2;
} ACL;
typedef ACL *PACL;
typedef struct  {
UCHAR revision;
UCHAR reserved;
USHORT control;
PISID owner;
PISID group;
PACL sacl;
PACL dacl;
} SECURITY_DESCRIPTOR;
typedef SECURITY_DESCRIPTOR *PISECURITY_DESCRIPTOR;
typedef LPVOID PSECURITY_DESCRIPTOR;
#define SecurityAnonymous (0x0)
#define SecurityIdentification (0x1)
#define SecurityImpersonation (0x2)
#define SecurityDelegation (0x3)
typedef ULONG SECURITY_IMPERSONATION_LEVEL;
typedef SECURITY_IMPERSONATION_LEVEL *PSECURITY_IMPERSONATION_LEVEL;
typedef BOOLEAN SECURITY_CONTEXT_TRACKING_MODE;
typedef SECURITY_CONTEXT_TRACKING_MODE *PSECURITY_CONTEXT_TRACKING_MODE;
typedef struct  {
DWORD length;
SECURITY_IMPERSONATION_LEVEL imp_level;
SECURITY_CONTEXT_TRACKING_MODE track_context;
BOOLEAN effective_only;
} SECURITY_QUALITY_OF_SERVICE;
typedef SECURITY_QUALITY_OF_SERVICE *PSECURITY_QUALITY_OF_SERVICE;
typedef struct  {
WCHAR *user;
ULONG user_length;
WCHAR *domain;
ULONG domain_length;
WCHAR *password;
ULONG password_length;
ULONG flags;
} COAUTHIDENTITY;
typedef COAUTHIDENTITY SEC_WINNT_AUTH_IDENTITY;
typedef struct  {
ULONG rid;
ULONG attrib;
} GROUP_MEMBERSHIP;
typedef GROUP_MEMBERSHIP *PGROUP_MEMBERSHIP;
typedef struct  {
LSA_UNICODE_STRING name;
PISID sid;
} LSA_TRUST_INFORMATION;
typedef LSA_TRUST_INFORMATION *PLSA_TRUST_INFORMATION;
typedef LSA_TRUST_INFORMATION TRUSTED_DOMAIN_INFORMATION_BASIC;
typedef PLSA_TRUST_INFORMATION PTRUSTED_DOMAIN_INFORMATION_BASIC;
typedef struct  {
LSA_UNICODE_STRING name;
LUID luid;
} LSA_ACCOUNT;
typedef LSA_ACCOUNT *PLSA_ACCOUNT;
typedef struct  {
ULONG entries;
PLSA_TRUST_INFORMATION domains;
ULONG maxEntries;
} LSA_REFERENCED_DOMAIN_LIST;
typedef LSA_REFERENCED_DOMAIN_LIST *PLSA_REFERENCED_DOMAIN_LIST;
#define TRUST_DIRECTION_DISABLED (0x0)
#define TRUST_DIRECTION_INBOUND (0x1)
#define TRUST_DIRECTION_OUTBOUND (0x2)
#define TRUST_TYPE_DOWNLEVEL (0x1)
#define TRUST_TYPE_UPLEVEL (0x2)
#define TRUST_TYPE_MIT (0x3)
#define TRUST_TYPE_DCE (0x4)
#define TRUST_ATTRIBUTE_NON_TRANSITIVE (0x1)
#define TRUST_ATTRIBUTE_UPLEVEL_ONLY (0x2)
#define TRUST_ATTRIBUTE_TREE_PARENT (0x400000)
#define TRUST_ATTRIBUTE_TREE_ROOT (0x800000)
typedef struct  {
LSA_UNICODE_STRING name;
LSA_UNICODE_STRING flat_name;
PISID sid;
ULONG direction;
ULONG type;
ULONG attr;
} TRUSTED_DOMAIN_INFORMATION_EX;
typedef TRUSTED_DOMAIN_INFORMATION_EX *PTRUSTED_DOMAIN_INFORMATION_EX;
typedef struct  {
ULONG entries;
PTRUSTED_DOMAIN_INFORMATION_EX domains;
ULONG maxEntries;
} TRUSTED_DOMAIN_INFORMATION_LIST_EX;
typedef TRUSTED_DOMAIN_INFORMATION_LIST_EX *PTRUSTED_DOMAIN_INFORMATION_LIST_EX;
typedef struct  {
LARGE_INTEGER update;
ULONG type;
ULONG len;
BYTE *info;
} LSA_AUTH_INFORMATION;
typedef LSA_AUTH_INFORMATION *PLSA_AUTH_INFORMATION;
typedef struct  {
ULONG element_275;
LSA_AUTH_INFORMATION *element_276;
LSA_AUTH_INFORMATION *element_277;
ULONG element_278;
LSA_AUTH_INFORMATION *element_279;
LSA_AUTH_INFORMATION *element_280;
} TRUSTED_DOMAIN_AUTH_INFORMATION;
typedef TRUSTED_DOMAIN_AUTH_INFORMATION *PTRUSTED_DOMAIN_AUTH_INFORMATION;
typedef struct  {
TRUSTED_DOMAIN_INFORMATION_EX info;
TRUSTED_POSIX_OFFSET_INFO posix;
TRUSTED_DOMAIN_AUTH_INFORMATION auth;
} TRUSTED_DOMAIN_FULL_INFORMATION;
typedef TRUSTED_DOMAIN_FULL_INFORMATION *PTRUSTED_DOMAIN_FULL_INFORMATION;
typedef struct  {
TRUSTED_DOMAIN_INFORMATION_EX info;
TRUSTED_POSIX_OFFSET_INFO posix;
LSA_SECURITY_DESCRIPTOR p1;
} TRUSTED_DOMAIN_PRIVATE_INFORMATION;
typedef TRUSTED_DOMAIN_PRIVATE_INFORMATION *PTRUSTED_DOMAIN_PRIVATE_INFORMATION;
typedef struct  {
ULONG length;
LPSTR *root_directory;
LSA_UNICODE_STRING *name;
ULONG attr;
SECURITY_DESCRIPTOR *sec_desc;
SECURITY_QUALITY_OF_SERVICE *sec_qos;
} LSA_OBJECT_ATTRIBUTES;
typedef LSA_OBJECT_ATTRIBUTES *PLSA_OBJECT_ATTRIBUTES;
#define PolicyServerRoleBackup (0x2)
#define PolicyServerRolePrimary (0x3)
typedef struct  {
USHORT role;
} POLICY_LSA_SERVER_ROLE_INFO;
typedef POLICY_LSA_SERVER_ROLE_INFO *PPOLICY_LSA_SERVER_ROLE_INFO;
typedef struct  {
LSA_UNICODE_STRING source;
LSA_UNICODE_STRING account_name;
} POLICY_REPLICA_SOURCE_INFO;
typedef POLICY_REPLICA_SOURCE_INFO *PPOLICY_REPLICA_SOURCE_INFO;
typedef struct  {
ULONG paged_pool;
ULONG non_paged_pool;
ULONG min_wss;
ULONG max_wss;
ULONG pagefile;
LARGE_INTEGER unknown;
} POLICY_DEFAULT_QUOTA_INFO;
typedef POLICY_DEFAULT_QUOTA_INFO *PPOLICY_DEFAULT_QUOTA_INFO;
typedef struct  {
BOOLEAN unknown1;
} POLICY_AUDIT_FULL_SET_INFO;
typedef POLICY_AUDIT_FULL_SET_INFO *PPOLICY_AUDIT_FULL_SET_INFO;
typedef struct  {
LARGE_INTEGER seq_no;
LARGE_INTEGER mtime;
} POLICY_MODIFICATION_INFO;
typedef POLICY_MODIFICATION_INFO *PPOLICY_MODIFICATION_INFO;
typedef struct  {
BOOLEAN unknown1;
BOOLEAN unknown2;
} POLICY_AUDIT_FULL_QUERY_INFO;
typedef POLICY_AUDIT_FULL_QUERY_INFO *PPOLICY_AUDIT_FULL_QUERY_INFO;
typedef struct  {
LSA_UNICODE_STRING name;
LSA_UNICODE_STRING domain;
LSA_UNICODE_STRING forest;
GUID guid;
PISID sid;
} POLICY_DNS_DOMAIN_INFO;
typedef POLICY_DNS_DOMAIN_INFO *PPOLICY_DNS_DOMAIN_INFO;
typedef struct  {
ULONG qos;
} POLICY_DOMAIN_QUALITY_OF_SERVICE_INFO;
typedef POLICY_DOMAIN_QUALITY_OF_SERVICE_INFO *PPOLICY_DOMAIN_QUALITY_OF_SERVICE_INFO;
typedef struct  {
ULONG length;
BYTE *blob;
} POLICY_DOMAIN_EFS_INFO;
typedef POLICY_DOMAIN_EFS_INFO *PPOLICY_DOMAIN_EFS_INFO;
typedef struct  {
ULONG opts;
LARGE_INTEGER stkt_age;
LARGE_INTEGER tkt_age;
LARGE_INTEGER renew_age;
LARGE_INTEGER clock_skew;
LARGE_INTEGER skew;
} POLICY_DOMAIN_KERBEROS_TICKET_INFO;
typedef POLICY_DOMAIN_KERBEROS_TICKET_INFO *PPOLICY_DOMAIN_KERBEROS_TICKET_INFO;

#ifdef __cplusplus
    }
#endif

#endif