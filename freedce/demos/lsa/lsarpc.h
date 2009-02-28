/* Generated by IDL compiler version FreeDCE 1.1.0.7 with GNU Flex/Bison */
#ifndef lsarpc_v0_0_included
#define lsarpc_v0_0_included
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
#ifndef FreeDCEORPCTypes_v0_0_included
#include <wtypes.h>
#endif
#ifndef FreeDCEOWinNTTypes_v0_0_included
#include <winnt.h>
#endif
#define POLICY_VIEW_LOCAL_INFORMATION (0x1)
#define POLICY_VIEW_AUDIT_INFORMATION (0x2)
#define POLICY_GET_PRIVATE_INFORMATION (0x4)
#define POLICY_TRUST_ADMIN (0x8)
#define POLICY_CREATE_ACCOUNT (0x10)
#define POLICY_CREATE_SECRET (0x20)
#define POLICY_CREATE_PRIVILEGE (0x40)
#define POLICY_SET_DEFAULT_QUOTA_LIMITS (0x80)
#define POLICY_SET_AUDIT_REQUIREMENTS (0x100)
#define POLICY_AUDIT_LOG_ADMIN (0x200)
#define POLICY_SERVER_ADMIN (0x400)
#define POLICY_LOOKUP_NAMES (0x800)
#define POLICY_ALL_ACCESS (0xf0fff)
#define POLICY_READ (0x20006)
#define POLICY_WRITE (0x207f8)
#define POLICY_EXECUTE (0x20801)
typedef HANDLE LSA_HANDLE;
extern NTSTATUS LsarClose(
#ifdef IDL_PROTOTYPES
    /* [in, out] */ LSA_HANDLE *hnd
#endif
);
extern NTSTATUS LsarDelete(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd
#endif
);
extern NTSTATUS LsarEnumeratePrivileges(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in, out] */ ULONG *count,
    /* [out] */ LSA_PRIVILEGES *privs,
    /* [in] */ ULONG size
#endif
);
extern NTSTATUS LsarQuerySecurityObject(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ ULONG info_type,
    /* [out] */ LSA_SECURITY_DESCRIPTOR **sec_info
#endif
);
extern NTSTATUS LsarSetSecurityObject(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ ULONG info_type,
    /* [in] */ LSA_SECURITY_DESCRIPTOR *sec_info
#endif
);
extern NTSTATUS LsarChangePassword(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_UNICODE_STRING *server,
    /* [in] */ LSA_UNICODE_STRING *domain,
    /* [in] */ LSA_UNICODE_STRING *user,
    /* [in] */ LSA_UNICODE_STRING *old_passwd,
    /* [in] */ LSA_UNICODE_STRING *new_passwd
#endif
);
extern NTSTATUS LsarOpenPolicy(
#ifdef IDL_PROTOTYPES
    /* [in] */ WCHAR *server,
    /* [in] */ LSA_OBJECT_ATTRIBUTES *attribs,
    /* [in] */ ACCESS_MASK access,
    /* [out] */ LSA_HANDLE *hnd
#endif
);
typedef enum {PolicyAuditLogInformation = 1,
PolicyAuditEventsInformation = 2,
PolicyPrimaryDomainInformation = 3,
PolicyPdAccountInformation = 4,
PolicyAccountDomainInformation = 5,
PolicyLsaServerRoleInformation = 6,
PolicyReplicaSourceInformation = 7,
PolicyDefaultQuotaInformation = 8,
PolicyModificationInformation = 9,
PolicyAuditFullSetInformation = 10,
PolicyAuditFullQueryInformation = 11,
PolicyDnsDomainInformation = 12} POLICY_INFORMATION_CLASS;
typedef struct  {
POLICY_INFORMATION_CLASS level;
union  {
/* case(s):  */
POLICY_AUDIT_LOG_INFO audit_log;
/* case(s):  */
POLICY_AUDIT_EVENTS_INFO audit_settings;
/* case(s):  */
POLICY_PRIMARY_DOMAIN_INFO primary_domain;
/* case(s):  */
POLICY_ACCOUNT_DOMAIN_INFO account_domain;
/* case(s):  */
LSA_UNICODE_STRING account;
/* case(s):  */
POLICY_LSA_SERVER_ROLE_INFO server_role;
/* case(s):  */
POLICY_REPLICA_SOURCE_INFO replica_source;
/* case(s):  */
POLICY_DEFAULT_QUOTA_INFO default_quota;
/* case(s):  */
POLICY_MODIFICATION_INFO history;
/* case(s):  */
POLICY_AUDIT_FULL_SET_INFO audit_set;
/* case(s):  */
POLICY_AUDIT_FULL_QUERY_INFO audit_query;
/* case(s):  */
POLICY_DNS_DOMAIN_INFO dns_info;
} contents;
} POLICY_INFORMATION;
extern NTSTATUS LsarQueryInformationPolicy(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ POLICY_INFORMATION_CLASS level,
    /* [out] */ POLICY_INFORMATION *info
#endif
);
extern NTSTATUS LsarSetInformationPolicy(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ POLICY_INFORMATION_CLASS level,
    /* [in] */ POLICY_INFORMATION *info
#endif
);
extern NTSTATUS LsarClearAuditLog(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd
#endif
);
extern NTSTATUS LsarCreateAccount(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd_pol,
    /* [in] */ SID *account,
    /* [in] */ ACCESS_MASK access,
    /* [out] */ LSA_HANDLE *hnd
#endif
);
extern NTSTATUS LsarEnumerateAccounts(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in, out] */ LSA_ENUMERATION_HANDLE *resume_hnd,
    /* [out] */ PSID_ARRAY **accounts,
    /* [in] */ ULONG pref_maxlen
#endif
);
extern NTSTATUS LsarCreateTrustedDomain(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd_pol,
    /* [in] */ LSA_TRUST_INFORMATION *domain,
    /* [in] */ ACCESS_MASK access,
    /* [out] */ LSA_HANDLE *hnd
#endif
);
extern NTSTATUS LsarEnumerateTrustedDomains(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in, out] */ LSA_ENUMERATION_HANDLE *resume_hnd,
    /* [out] */ LSA_REFERENCED_DOMAIN_LIST *domains,
    /* [in] */ ULONG pref_maxlen
#endif
);
extern NTSTATUS LsarLookupNames(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ ULONG count,
    /* [in] */ LSA_UNICODE_STRING *names,
    /* [out] */ LSA_REFERENCED_DOMAIN_LIST *domains,
    /* [in, out] */ LSA_TRANSLATED_SIDS *rids,
    /* [in] */ USHORT level,
    /* [in, out] */ ULONG *num_mapped
#endif
);
extern NTSTATUS LsarLookupSids(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ PSID_ARRAY **sids,
    /* [out] */ LSA_REFERENCED_DOMAIN_LIST *domains,
    /* [in, out] */ LSA_TRANSLATED_NAMES *names,
    /* [in] */ USHORT level,
    /* [in, out] */ ULONG *num_mapped
#endif
);
extern NTSTATUS LsarCreateSecret(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd_pol,
    /* [in] */ LSA_UNICODE_STRING *name,
    /* [in] */ ACCESS_MASK access,
    /* [out] */ LSA_HANDLE *hnd
#endif
);
extern NTSTATUS LsarOpenAccount(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd_pol,
    /* [in] */ SID *account,
    /* [in] */ ACCESS_MASK access,
    /* [out] */ LSA_HANDLE *hnd
#endif
);
extern NTSTATUS LsarEnumeratePrivilegesAccount(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [out] */ LUID_AND_ATTRIBUTES_ARRAY **privs
#endif
);
extern NTSTATUS LsarAddPrivilegesToAccount(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ LUID_AND_ATTRIBUTES_ARRAY *privs
#endif
);
extern NTSTATUS LsarRemovePrivilegesFromAccount(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ idl_char unknown,
    /* [in] */ LUID_AND_ATTRIBUTES_ARRAY *privs
#endif
);
extern NTSTATUS LsarGetQuotasForAccount(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [out] */ POLICY_DEFAULT_QUOTA_INFO *quotas
#endif
);
extern NTSTATUS LsarSetQuotasForAccount(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ POLICY_DEFAULT_QUOTA_INFO *quotas
#endif
);
extern NTSTATUS LsarGetSystemAccessAccount(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [out] */ ULONG *rid
#endif
);
extern NTSTATUS LsarSetSystemAccessAccount(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ ULONG rid
#endif
);
extern NTSTATUS LsarOpenTrustedDomain(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd_pol,
    /* [in] */ SID *sid,
    /* [in] */ ACCESS_MASK access,
    /* [out] */ LSA_HANDLE *hnd
#endif
);
typedef enum {TrustedDomainNameInformation = 1,
TrustedControllersInformation = 2,
TrustedPosixOffsetInformation = 3,
TrustedPasswordInformation = 4,
TrustedDomainInformationBasic = 5,
TrustedDomainInformationEx = 6,
TrustedDomainAuthInformation = 7,
TrustedDomainFullInformation = 8,
TrustedDomainSecurityDescriptor = 9,
TrustedDomainPrivateInformation = 10} TRUSTED_INFORMATION_CLASS;
typedef TRUSTED_INFORMATION_CLASS *PTRUSTED_INFORMATION_CLASS;
typedef struct  {
TRUSTED_INFORMATION_CLASS level;
union  {
/* case(s):  */
LSA_UNICODE_STRING name;
/* case(s):  */
LSA_UNICODE_STRING_ARRAY names;
/* case(s):  */
TRUSTED_POSIX_OFFSET_INFO posix;
/* case(s):  */
TRUSTED_PASSWORD_INFO secret;
/* case(s):  */
TRUSTED_DOMAIN_INFORMATION_BASIC basic;
/* case(s):  */
TRUSTED_DOMAIN_INFORMATION_EX ex;
/* case(s):  */
TRUSTED_DOMAIN_AUTH_INFORMATION auth;
/* case(s):  */
TRUSTED_DOMAIN_FULL_INFORMATION full;
/* case(s):  */
LSA_SECURITY_DESCRIPTOR sd;
/* case(s):  */
TRUSTED_DOMAIN_PRIVATE_INFORMATION priv;
} contents;
} TRUSTED_DOMAIN_INFORMATION;
typedef TRUSTED_DOMAIN_INFORMATION *PTRUSTED_DOMAIN_INFOMATION;
extern NTSTATUS LsarQueryInfoTrustedDomain(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ TRUSTED_INFORMATION_CLASS level,
    /* [out] */ TRUSTED_DOMAIN_INFORMATION *info
#endif
);
extern NTSTATUS LsarSetInformationTrustedDomain(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ TRUSTED_INFORMATION_CLASS level,
    /* [in] */ TRUSTED_DOMAIN_INFORMATION *info
#endif
);
extern NTSTATUS LsarOpenSecret(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd_pol,
    /* [in] */ LSA_UNICODE_STRING *name,
    /* [in] */ ACCESS_MASK access,
    /* [out] */ LSA_HANDLE *hnd
#endif
);
extern NTSTATUS LsarSetSecret(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ LSA_SECRET *new_val,
    /* [in] */ LSA_SECRET *old_val
#endif
);
extern NTSTATUS LsarQuerySecret(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in, out] */ LSA_SECRET *curr_val,
    /* [in, out] */ LARGE_INTEGER *curr_mtime,
    /* [in, out] */ LSA_SECRET *old_val,
    /* [in, out] */ LARGE_INTEGER *old_mtime
#endif
);
extern NTSTATUS LsarLookupPrivilegeValue(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ LSA_UNICODE_STRING *name,
    /* [out] */ LUID *value
#endif
);
extern NTSTATUS LsarLookupPrivilegeName(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ LUID *value,
    /* [out] */ LSA_UNICODE_STRING **name
#endif
);
extern NTSTATUS LsarLookupPrivilegeDisplayName(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ LSA_UNICODE_STRING *name,
    /* [in] */ USHORT unknown,
    /* [in] */ USHORT size,
    /* [out] */ LSA_UNICODE_STRING **disp_name,
    /* [out] */ USHORT *size_needed
#endif
);
extern NTSTATUS LsarDeleteObject(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd
#endif
);
extern NTSTATUS LsarEnumerateAccountsWithUserRight(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ LSA_UNICODE_STRING *rights,
    /* [out] */ LSA_UNICODE_STRING_ARRAY *accounts
#endif
);
extern NTSTATUS LsarEnumerateAccountRights(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ SID *account,
    /* [out] */ LSA_UNICODE_STRING_ARRAY *rights
#endif
);
extern NTSTATUS LsarAddAccountRights(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ SID *account,
    /* [in] */ LSA_UNICODE_STRING_ARRAY *rights
#endif
);
extern NTSTATUS LsarRemoveAccountRights(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ SID *account,
    /* [in] */ BOOLEAN remove_all,
    /* [in] */ LSA_UNICODE_STRING_ARRAY *rights
#endif
);
extern NTSTATUS LsarQueryTrustedDomainInfo(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ SID *sid,
    /* [in] */ TRUSTED_INFORMATION_CLASS level,
    /* [out] */ TRUSTED_DOMAIN_INFORMATION *info
#endif
);
extern NTSTATUS LsarSetTrustedDomainInfo(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ SID *sid,
    /* [in] */ TRUSTED_INFORMATION_CLASS level,
    /* [in] */ TRUSTED_DOMAIN_INFORMATION *info
#endif
);
extern NTSTATUS LsarDeleteTrustedDomain(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ SID *sid
#endif
);
extern NTSTATUS LsarStorePrivateData(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ LSA_UNICODE_STRING *key,
    /* [in] */ LSA_SECRET **data
#endif
);
extern NTSTATUS LsarRetrievePrivateData(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ LSA_STRING *key,
    /* [in, out] */ LSA_SECRET **data
#endif
);
extern NTSTATUS LsarOpenPolicy2(
#ifdef IDL_PROTOTYPES
    /* [in] */ WCHAR *server,
    /* [in] */ LSA_OBJECT_ATTRIBUTES *attribs,
    /* [in] */ ACCESS_MASK access,
    /* [out] */ LSA_HANDLE *hnd
#endif
);
extern NTSTATUS LsarGetUserName(
#ifdef IDL_PROTOTYPES
    /* [in] */ WCHAR *server,
    /* [in, out] */ LSA_UNICODE_STRING **user,
    /* [in, out] */ LSA_UNICODE_STRING **domain
#endif
);
extern NTSTATUS Function_2e(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ POLICY_INFORMATION_CLASS level,
    /* [out] */ POLICY_INFORMATION *info
#endif
);
extern NTSTATUS Function_2f(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ POLICY_INFORMATION_CLASS level,
    /* [in] */ POLICY_INFORMATION *info
#endif
);
extern NTSTATUS LsarQueryTrustedDomainInfoByName(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE handle,
    /* [in] */ LSA_UNICODE_STRING *name,
    /* [in] */ TRUSTED_INFORMATION_CLASS level,
    /* [out] */ TRUSTED_DOMAIN_INFORMATION *info
#endif
);
extern NTSTATUS LsarSetTrustedDomainInfoByName(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE handle,
    /* [in] */ LSA_UNICODE_STRING *name,
    /* [in] */ TRUSTED_INFORMATION_CLASS level,
    /* [in] */ TRUSTED_DOMAIN_INFORMATION *info
#endif
);
extern NTSTATUS LsarEnumerateTrustedDomainsEx(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in, out] */ LSA_ENUMERATION_HANDLE *resume_hnd,
    /* [out] */ TRUSTED_DOMAIN_INFORMATION_LIST_EX *domains,
    /* [in] */ ULONG pref_maxlen
#endif
);
extern NTSTATUS LsarCreateTrustedDomainEx(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ TRUSTED_DOMAIN_INFORMATION_EX *info,
    /* [in] */ TRUSTED_DOMAIN_AUTH_INFORMATION *auth,
    /* [in] */ ACCESS_MASK mask,
    /* [out] */ LSA_HANDLE *tdHnd
#endif
);
extern NTSTATUS LsarCloseTrustedDomainEx(
#ifdef IDL_PROTOTYPES
    /* [in, out] */ LSA_HANDLE *tdHnd
#endif
);
typedef enum {PolicyDomainQualityOfServiceInformation = 1,
PolicyDomainEfsInformation = 2,
PolicyDomainKerberosTicketInformation = 3} POLICY_DOMAIN_INFORMATION_CLASS;
typedef POLICY_DOMAIN_INFORMATION_CLASS *PPOLICY_DOMAIN_INFORMATION_CLASS;
typedef struct  {
POLICY_DOMAIN_INFORMATION_CLASS level;
union  {
/* case(s):  */
POLICY_DOMAIN_QUALITY_OF_SERVICE_INFO qos;
/* case(s):  */
POLICY_DOMAIN_EFS_INFO efs;
/* case(s):  */
POLICY_DOMAIN_KERBEROS_TICKET_INFO krb;
} contents;
} POLICY_DOMAIN_INFORMATION;
typedef POLICY_DOMAIN_INFORMATION *PPOLICY_DOMAIN_INFORMATION;
extern NTSTATUS LsarQueryDomainInformationPolicy(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE handle,
    /* [in] */ POLICY_DOMAIN_INFORMATION_CLASS level,
    /* [out] */ POLICY_INFORMATION *info
#endif
);
extern NTSTATUS LsarSetDomainInformationPolicy(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE handle,
    /* [in] */ POLICY_INFORMATION_CLASS level,
    /* [in] */ POLICY_INFORMATION *info
#endif
);
extern NTSTATUS LsarOpenTrustedDomainByName(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE handle,
    /* [in] */ LSA_UNICODE_STRING *name,
    /* [in] */ ACCESS_MASK access,
    /* [out] */ LSA_HANDLE *phnd
#endif
);
extern NTSTATUS Function_38(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE handle,
    /* [in] */ USHORT flag,
    /* [in] */ LSA_SECURITY_DESCRIPTOR *sd,
    /* [out] */ LSA_SECURITY_DESCRIPTOR **psd
#endif
);
extern NTSTATUS LsarLookupSids2(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE handle,
    /* [in] */ PSID_ARRAY **sids,
    /* [out] */ LSA_REFERENCED_DOMAIN_LIST *domains,
    /* [in, out] */ LSA_TRANSLATED_NAMES_EX *names,
    /* [in] */ USHORT level,
    /* [in, out] */ ULONG *num_mapped,
    /* [in] */ ULONG unknown1,
    /* [in] */ ULONG unknown2
#endif
);
extern NTSTATUS LsarLookupNames2(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ ULONG count,
    /* [in] */ LSA_UNICODE_STRING *names,
    /* [out] */ LSA_REFERENCED_DOMAIN_LIST *domains,
    /* [in, out] */ LSA_TRANSLATED_SIDS_EX *rids,
    /* [in] */ USHORT level,
    /* [in, out] */ ULONG *num_mapped,
    /* [in] */ ULONG unknown1,
    /* [in] */ ULONG unknown2
#endif
);
extern NTSTATUS Function_3b(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ TRUSTED_DOMAIN_INFORMATION_EX *info,
    /* [in] */ LSA_SECURITY_DESCRIPTOR *sd,
    /* [in] */ ULONG unknown,
    /* [out] */ LSA_HANDLE *h2
#endif
);
void LSA_HANDLE_rundown(
#ifdef IDL_PROTOTYPES
    rpc_ss_context_t context_handle
#endif
);
typedef struct lsarpc_v0_0_epv_t {
	NTSTATUS (*LsarClose)(
#ifdef IDL_PROTOTYPES
    /* [in, out] */ LSA_HANDLE *hnd
#endif
);
	NTSTATUS (*LsarDelete)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd
#endif
);
	NTSTATUS (*LsarEnumeratePrivileges)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in, out] */ ULONG *count,
    /* [out] */ LSA_PRIVILEGES *privs,
    /* [in] */ ULONG size
#endif
);
	NTSTATUS (*LsarQuerySecurityObject)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ ULONG info_type,
    /* [out] */ LSA_SECURITY_DESCRIPTOR **sec_info
#endif
);
	NTSTATUS (*LsarSetSecurityObject)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ ULONG info_type,
    /* [in] */ LSA_SECURITY_DESCRIPTOR *sec_info
#endif
);
	NTSTATUS (*LsarChangePassword)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_UNICODE_STRING *server,
    /* [in] */ LSA_UNICODE_STRING *domain,
    /* [in] */ LSA_UNICODE_STRING *user,
    /* [in] */ LSA_UNICODE_STRING *old_passwd,
    /* [in] */ LSA_UNICODE_STRING *new_passwd
#endif
);
	NTSTATUS (*LsarOpenPolicy)(
#ifdef IDL_PROTOTYPES
    /* [in] */ WCHAR *server,
    /* [in] */ LSA_OBJECT_ATTRIBUTES *attribs,
    /* [in] */ ACCESS_MASK access,
    /* [out] */ LSA_HANDLE *hnd
#endif
);
	NTSTATUS (*LsarQueryInformationPolicy)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ POLICY_INFORMATION_CLASS level,
    /* [out] */ POLICY_INFORMATION *info
#endif
);
	NTSTATUS (*LsarSetInformationPolicy)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ POLICY_INFORMATION_CLASS level,
    /* [in] */ POLICY_INFORMATION *info
#endif
);
	NTSTATUS (*LsarClearAuditLog)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd
#endif
);
	NTSTATUS (*LsarCreateAccount)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd_pol,
    /* [in] */ SID *account,
    /* [in] */ ACCESS_MASK access,
    /* [out] */ LSA_HANDLE *hnd
#endif
);
	NTSTATUS (*LsarEnumerateAccounts)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in, out] */ LSA_ENUMERATION_HANDLE *resume_hnd,
    /* [out] */ PSID_ARRAY **accounts,
    /* [in] */ ULONG pref_maxlen
#endif
);
	NTSTATUS (*LsarCreateTrustedDomain)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd_pol,
    /* [in] */ LSA_TRUST_INFORMATION *domain,
    /* [in] */ ACCESS_MASK access,
    /* [out] */ LSA_HANDLE *hnd
#endif
);
	NTSTATUS (*LsarEnumerateTrustedDomains)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in, out] */ LSA_ENUMERATION_HANDLE *resume_hnd,
    /* [out] */ LSA_REFERENCED_DOMAIN_LIST *domains,
    /* [in] */ ULONG pref_maxlen
#endif
);
	NTSTATUS (*LsarLookupNames)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ ULONG count,
    /* [in] */ LSA_UNICODE_STRING *names,
    /* [out] */ LSA_REFERENCED_DOMAIN_LIST *domains,
    /* [in, out] */ LSA_TRANSLATED_SIDS *rids,
    /* [in] */ USHORT level,
    /* [in, out] */ ULONG *num_mapped
#endif
);
	NTSTATUS (*LsarLookupSids)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ PSID_ARRAY **sids,
    /* [out] */ LSA_REFERENCED_DOMAIN_LIST *domains,
    /* [in, out] */ LSA_TRANSLATED_NAMES *names,
    /* [in] */ USHORT level,
    /* [in, out] */ ULONG *num_mapped
#endif
);
	NTSTATUS (*LsarCreateSecret)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd_pol,
    /* [in] */ LSA_UNICODE_STRING *name,
    /* [in] */ ACCESS_MASK access,
    /* [out] */ LSA_HANDLE *hnd
#endif
);
	NTSTATUS (*LsarOpenAccount)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd_pol,
    /* [in] */ SID *account,
    /* [in] */ ACCESS_MASK access,
    /* [out] */ LSA_HANDLE *hnd
#endif
);
	NTSTATUS (*LsarEnumeratePrivilegesAccount)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [out] */ LUID_AND_ATTRIBUTES_ARRAY **privs
#endif
);
	NTSTATUS (*LsarAddPrivilegesToAccount)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ LUID_AND_ATTRIBUTES_ARRAY *privs
#endif
);
	NTSTATUS (*LsarRemovePrivilegesFromAccount)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ idl_char unknown,
    /* [in] */ LUID_AND_ATTRIBUTES_ARRAY *privs
#endif
);
	NTSTATUS (*LsarGetQuotasForAccount)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [out] */ POLICY_DEFAULT_QUOTA_INFO *quotas
#endif
);
	NTSTATUS (*LsarSetQuotasForAccount)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ POLICY_DEFAULT_QUOTA_INFO *quotas
#endif
);
	NTSTATUS (*LsarGetSystemAccessAccount)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [out] */ ULONG *rid
#endif
);
	NTSTATUS (*LsarSetSystemAccessAccount)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ ULONG rid
#endif
);
	NTSTATUS (*LsarOpenTrustedDomain)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd_pol,
    /* [in] */ SID *sid,
    /* [in] */ ACCESS_MASK access,
    /* [out] */ LSA_HANDLE *hnd
#endif
);
	NTSTATUS (*LsarQueryInfoTrustedDomain)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ TRUSTED_INFORMATION_CLASS level,
    /* [out] */ TRUSTED_DOMAIN_INFORMATION *info
#endif
);
	NTSTATUS (*LsarSetInformationTrustedDomain)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ TRUSTED_INFORMATION_CLASS level,
    /* [in] */ TRUSTED_DOMAIN_INFORMATION *info
#endif
);
	NTSTATUS (*LsarOpenSecret)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd_pol,
    /* [in] */ LSA_UNICODE_STRING *name,
    /* [in] */ ACCESS_MASK access,
    /* [out] */ LSA_HANDLE *hnd
#endif
);
	NTSTATUS (*LsarSetSecret)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ LSA_SECRET *new_val,
    /* [in] */ LSA_SECRET *old_val
#endif
);
	NTSTATUS (*LsarQuerySecret)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in, out] */ LSA_SECRET *curr_val,
    /* [in, out] */ LARGE_INTEGER *curr_mtime,
    /* [in, out] */ LSA_SECRET *old_val,
    /* [in, out] */ LARGE_INTEGER *old_mtime
#endif
);
	NTSTATUS (*LsarLookupPrivilegeValue)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ LSA_UNICODE_STRING *name,
    /* [out] */ LUID *value
#endif
);
	NTSTATUS (*LsarLookupPrivilegeName)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ LUID *value,
    /* [out] */ LSA_UNICODE_STRING **name
#endif
);
	NTSTATUS (*LsarLookupPrivilegeDisplayName)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ LSA_UNICODE_STRING *name,
    /* [in] */ USHORT unknown,
    /* [in] */ USHORT size,
    /* [out] */ LSA_UNICODE_STRING **disp_name,
    /* [out] */ USHORT *size_needed
#endif
);
	NTSTATUS (*LsarDeleteObject)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd
#endif
);
	NTSTATUS (*LsarEnumerateAccountsWithUserRight)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ LSA_UNICODE_STRING *rights,
    /* [out] */ LSA_UNICODE_STRING_ARRAY *accounts
#endif
);
	NTSTATUS (*LsarEnumerateAccountRights)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ SID *account,
    /* [out] */ LSA_UNICODE_STRING_ARRAY *rights
#endif
);
	NTSTATUS (*LsarAddAccountRights)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ SID *account,
    /* [in] */ LSA_UNICODE_STRING_ARRAY *rights
#endif
);
	NTSTATUS (*LsarRemoveAccountRights)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ SID *account,
    /* [in] */ BOOLEAN remove_all,
    /* [in] */ LSA_UNICODE_STRING_ARRAY *rights
#endif
);
	NTSTATUS (*LsarQueryTrustedDomainInfo)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ SID *sid,
    /* [in] */ TRUSTED_INFORMATION_CLASS level,
    /* [out] */ TRUSTED_DOMAIN_INFORMATION *info
#endif
);
	NTSTATUS (*LsarSetTrustedDomainInfo)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ SID *sid,
    /* [in] */ TRUSTED_INFORMATION_CLASS level,
    /* [in] */ TRUSTED_DOMAIN_INFORMATION *info
#endif
);
	NTSTATUS (*LsarDeleteTrustedDomain)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ SID *sid
#endif
);
	NTSTATUS (*LsarStorePrivateData)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ LSA_UNICODE_STRING *key,
    /* [in] */ LSA_SECRET **data
#endif
);
	NTSTATUS (*LsarRetrievePrivateData)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ LSA_STRING *key,
    /* [in, out] */ LSA_SECRET **data
#endif
);
	NTSTATUS (*LsarOpenPolicy2)(
#ifdef IDL_PROTOTYPES
    /* [in] */ WCHAR *server,
    /* [in] */ LSA_OBJECT_ATTRIBUTES *attribs,
    /* [in] */ ACCESS_MASK access,
    /* [out] */ LSA_HANDLE *hnd
#endif
);
	NTSTATUS (*LsarGetUserName)(
#ifdef IDL_PROTOTYPES
    /* [in] */ WCHAR *server,
    /* [in, out] */ LSA_UNICODE_STRING **user,
    /* [in, out] */ LSA_UNICODE_STRING **domain
#endif
);
	NTSTATUS (*Function_2e)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ POLICY_INFORMATION_CLASS level,
    /* [out] */ POLICY_INFORMATION *info
#endif
);
	NTSTATUS (*Function_2f)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ POLICY_INFORMATION_CLASS level,
    /* [in] */ POLICY_INFORMATION *info
#endif
);
	NTSTATUS (*LsarQueryTrustedDomainInfoByName)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE handle,
    /* [in] */ LSA_UNICODE_STRING *name,
    /* [in] */ TRUSTED_INFORMATION_CLASS level,
    /* [out] */ TRUSTED_DOMAIN_INFORMATION *info
#endif
);
	NTSTATUS (*LsarSetTrustedDomainInfoByName)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE handle,
    /* [in] */ LSA_UNICODE_STRING *name,
    /* [in] */ TRUSTED_INFORMATION_CLASS level,
    /* [in] */ TRUSTED_DOMAIN_INFORMATION *info
#endif
);
	NTSTATUS (*LsarEnumerateTrustedDomainsEx)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in, out] */ LSA_ENUMERATION_HANDLE *resume_hnd,
    /* [out] */ TRUSTED_DOMAIN_INFORMATION_LIST_EX *domains,
    /* [in] */ ULONG pref_maxlen
#endif
);
	NTSTATUS (*LsarCreateTrustedDomainEx)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ TRUSTED_DOMAIN_INFORMATION_EX *info,
    /* [in] */ TRUSTED_DOMAIN_AUTH_INFORMATION *auth,
    /* [in] */ ACCESS_MASK mask,
    /* [out] */ LSA_HANDLE *tdHnd
#endif
);
	NTSTATUS (*LsarCloseTrustedDomainEx)(
#ifdef IDL_PROTOTYPES
    /* [in, out] */ LSA_HANDLE *tdHnd
#endif
);
	NTSTATUS (*LsarQueryDomainInformationPolicy)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE handle,
    /* [in] */ POLICY_DOMAIN_INFORMATION_CLASS level,
    /* [out] */ POLICY_INFORMATION *info
#endif
);
	NTSTATUS (*LsarSetDomainInformationPolicy)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE handle,
    /* [in] */ POLICY_INFORMATION_CLASS level,
    /* [in] */ POLICY_INFORMATION *info
#endif
);
	NTSTATUS (*LsarOpenTrustedDomainByName)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE handle,
    /* [in] */ LSA_UNICODE_STRING *name,
    /* [in] */ ACCESS_MASK access,
    /* [out] */ LSA_HANDLE *phnd
#endif
);
	NTSTATUS (*Function_38)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE handle,
    /* [in] */ USHORT flag,
    /* [in] */ LSA_SECURITY_DESCRIPTOR *sd,
    /* [out] */ LSA_SECURITY_DESCRIPTOR **psd
#endif
);
	NTSTATUS (*LsarLookupSids2)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE handle,
    /* [in] */ PSID_ARRAY **sids,
    /* [out] */ LSA_REFERENCED_DOMAIN_LIST *domains,
    /* [in, out] */ LSA_TRANSLATED_NAMES_EX *names,
    /* [in] */ USHORT level,
    /* [in, out] */ ULONG *num_mapped,
    /* [in] */ ULONG unknown1,
    /* [in] */ ULONG unknown2
#endif
);
	NTSTATUS (*LsarLookupNames2)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ ULONG count,
    /* [in] */ LSA_UNICODE_STRING *names,
    /* [out] */ LSA_REFERENCED_DOMAIN_LIST *domains,
    /* [in, out] */ LSA_TRANSLATED_SIDS_EX *rids,
    /* [in] */ USHORT level,
    /* [in, out] */ ULONG *num_mapped,
    /* [in] */ ULONG unknown1,
    /* [in] */ ULONG unknown2
#endif
);
	NTSTATUS (*Function_3b)(
#ifdef IDL_PROTOTYPES
    /* [in] */ LSA_HANDLE hnd,
    /* [in] */ TRUSTED_DOMAIN_INFORMATION_EX *info,
    /* [in] */ LSA_SECURITY_DESCRIPTOR *sd,
    /* [in] */ ULONG unknown,
    /* [out] */ LSA_HANDLE *h2
#endif
);
} lsarpc_v0_0_epv_t;
extern rpc_if_handle_t lsarpc_v0_0_c_ifspec;
extern rpc_if_handle_t lsarpc_v0_0_s_ifspec;

#ifdef __cplusplus
    }
#endif

#endif
