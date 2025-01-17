/* Generated by IDL compiler version FreeDCE 1.0.1 64-bit with GNU Flex/Bison */
#ifndef samr_v1_0_included
#define samr_v1_0_included
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
#define MAX_SIZE (0x3e8)
typedef idl_void_p_t connect_hnd_t;
typedef idl_void_p_t domain_hnd_t;
typedef idl_void_p_t user_hnd_t;
typedef idl_void_p_t group_hnd_t;
typedef idl_void_p_t alias_hnd_t;
typedef idl_void_p_t obj_hnd_t;
typedef idl_void_p_t unknown_hnd_t;
extern idl_long_int SamrConnect(
#ifdef IDL_PROTOTYPES
    /* [in] */ handle_t h,
    /* [in] */ idl_ushort_int server,
    /* [out] */ connect_hnd_t *hnd,
    /* [in] */ idl_long_int access
#endif
);
extern idl_long_int SamrCloseHandle(
#ifdef IDL_PROTOTYPES
    /* [in, out] */ connect_hnd_t *hnd
#endif
);
typedef struct  {
idl_long_int size;
idl_char *buffer;
} BUFFER;
extern idl_long_int SamrSetSecurityObject(
#ifdef IDL_PROTOTYPES
    /* [in] */ obj_hnd_t hnd,
    /* [in] */ idl_long_int info_type,
    /* [in] */ BUFFER *sec_info
#endif
);
extern idl_long_int SamrQuerySecurityObject(
#ifdef IDL_PROTOTYPES
    /* [in] */ obj_hnd_t hnd,
    /* [in] */ idl_long_int info_type,
    /* [out] */ BUFFER **sec_info
#endif
);
extern idl_long_int SamrShutdownSamServer(
#ifdef IDL_PROTOTYPES
    /* [in] */ connect_hnd_t hnd
#endif
);
typedef struct samr_v1_0_2_tag {
idl_short_int length;
idl_short_int size;
idl_ushort_int *string;
} UNICODE_STRING;
typedef struct  {
idl_char value[6];
} SID_IDENTIFIER_AUTHORITY;
typedef struct  {
idl_char revision;
idl_small_int subauth_count;
SID_IDENTIFIER_AUTHORITY authority;
idl_long_int subauth[1];
} SID;
extern idl_long_int SamrLookupDomainInSamServer(
#ifdef IDL_PROTOTYPES
    /* [in] */ connect_hnd_t hnd,
    /* [in] */ UNICODE_STRING *domain,
    /* [out] */ SID **sid
#endif
);
typedef struct samr_v1_0_0_tag {
idl_long_int index;
UNICODE_STRING name;
} IDX_AND_NAME;
typedef struct  {
idl_long_int count;
IDX_AND_NAME *entry;
} IDX_AND_NAME_ARRAY;
extern idl_long_int SamrEnumerateDomainsInSamServer(
#ifdef IDL_PROTOTYPES
    /* [in] */ connect_hnd_t hnd,
    /* [in, out] */ idl_long_int *resume_hnd,
    /* [out] */ IDX_AND_NAME_ARRAY **domains,
    /* [in] */ idl_long_int pref_maxlen,
    /* [out] */ idl_long_int *entries
#endif
);
extern idl_long_int SamrOpenDomain(
#ifdef IDL_PROTOTYPES
    /* [in] */ connect_hnd_t sam_hnd,
    /* [in] */ idl_long_int access,
    /* [in] */ SID *domain,
    /* [out] */ domain_hnd_t *hnd
#endif
);
typedef struct  {
idl_long_int low;
idl_long_int high;
} NTTIME;
typedef struct  {
idl_short_int min_pwd_len;
idl_short_int pwd_history_len;
idl_long_int unknown;
NTTIME max_pwd_age;
NTTIME min_pwd_age;
} DOMAIN_INFO_1;
typedef struct  {
NTTIME unknown1;
UNICODE_STRING unknown2;
UNICODE_STRING domain;
UNICODE_STRING controller;
NTTIME seq_no;
idl_long_int unknown3;
idl_long_int unknown4;
idl_char unknown5;
idl_long_int num_users;
idl_long_int num_groups;
idl_long_int num_aliases;
} DOMAIN_INFO_2;
typedef struct  {
NTTIME max_pwd_age;
NTTIME min_pwd_age;
} DOMAIN_INFO_8;
typedef struct  {
idl_hyper_int value;
} LARGE_INTEGER;
typedef struct  {
LARGE_INTEGER unknown1;
LARGE_INTEGER unknown2;
idl_short_int unknown3;
} REPLICATION_STATUS;
typedef struct  {
DOMAIN_INFO_2 info;
REPLICATION_STATUS repl;
} DOMAIN_INFO_11;
typedef struct  {
NTTIME unknown1;
NTTIME unknown2;
NTTIME seq_no;
} DOMAIN_INFO_13;
typedef union  {
/* case(s):  */
DOMAIN_INFO_1 di1;
/* case(s):  */
DOMAIN_INFO_2 di2;
/* case(s):  */
NTTIME unknown1;
/* case(s):  */
UNICODE_STRING unknown2;
/* case(s):  */
UNICODE_STRING domain;
/* case(s):  */
UNICODE_STRING controller;
/* case(s):  */
idl_ushort_int unknown3;
/* case(s):  */
DOMAIN_INFO_8 di8;
/* case(s):  */
idl_ushort_int unknown4;
/* case(s):  */
DOMAIN_INFO_11 di11;
/* case(s):  */
REPLICATION_STATUS repl;
/* case(s):  */
DOMAIN_INFO_13 di13;
} DOMAIN_INFO;
extern idl_long_int SamrQueryInformationDomain(
#ifdef IDL_PROTOTYPES
    /* [in] */ domain_hnd_t hnd,
    /* [in, out] */ idl_ushort_int *level,
    /* [out] */ DOMAIN_INFO *info
#endif
);
extern idl_long_int SamrSetInformationDomain(
#ifdef IDL_PROTOTYPES
    /* [in] */ domain_hnd_t hnd,
    /* [in] */ idl_ushort_int level,
    /* [in] */ DOMAIN_INFO *info
#endif
);
extern idl_long_int SamrCreateGroupInDomain(
#ifdef IDL_PROTOTYPES
    /* [in] */ domain_hnd_t hnd_dom,
    /* [in] */ UNICODE_STRING *name,
    /* [in] */ idl_long_int access,
    /* [out] */ group_hnd_t *hnd,
    /* [out] */ idl_long_int *rid
#endif
);
extern idl_long_int SamrEnumerateGroupsInDomain(
#ifdef IDL_PROTOTYPES
    /* [in] */ domain_hnd_t hnd,
    /* [in, out] */ idl_long_int *resume_hnd,
    /* [in] */ idl_long_int mask,
    /* [out] */ IDX_AND_NAME_ARRAY **groups,
    /* [in] */ idl_long_int pref_maxlen,
    /* [out] */ idl_long_int *entries
#endif
);
extern idl_long_int SamrCreateUserInDomain(
#ifdef IDL_PROTOTYPES
    /* [in] */ domain_hnd_t hnd_dom,
    /* [in] */ UNICODE_STRING *name,
    /* [in] */ idl_long_int access,
    /* [out] */ user_hnd_t *hnd,
    /* [out] */ idl_long_int *rid
#endif
);
extern idl_long_int SamrEnumerateUsersInDomain(
#ifdef IDL_PROTOTYPES
    /* [in] */ domain_hnd_t hnd,
    /* [in, out] */ idl_long_int *resume_hnd,
    /* [in] */ idl_long_int mask,
    /* [out] */ IDX_AND_NAME_ARRAY **groups,
    /* [in] */ idl_long_int pref_maxlen,
    /* [out] */ idl_long_int *entries
#endif
);
extern idl_long_int SamrCreateAliasInDomain(
#ifdef IDL_PROTOTYPES
    /* [in] */ domain_hnd_t hnd_dom,
    /* [in] */ UNICODE_STRING *name,
    /* [in] */ idl_long_int access,
    /* [out] */ alias_hnd_t *hnd,
    /* [out] */ idl_long_int *rid
#endif
);
extern idl_long_int SamrEnumerateAliasesInDomain(
#ifdef IDL_PROTOTYPES
    /* [in] */ domain_hnd_t hnd,
    /* [in, out] */ idl_long_int *resume_hnd,
    /* [in] */ idl_long_int mask,
    /* [out] */ IDX_AND_NAME_ARRAY **groups,
    /* [in] */ idl_long_int pref_maxlen,
    /* [out] */ idl_long_int *entries
#endif
);
typedef struct samr_v1_0_1_tag {
SID *sid;
} PSID;
typedef struct  {
idl_long_int count;
PSID *sids;
} PSID_ARRAY;
typedef struct  {
idl_long_int count;
idl_long_int *value;
} INDEX_ARRAY;
extern idl_long_int SamrGetAliasMembersip(
#ifdef IDL_PROTOTYPES
    /* [in] */ alias_hnd_t hnd,
    /* [in] */ PSID_ARRAY *sids,
    /* [out] */ INDEX_ARRAY *aliases
#endif
);
extern idl_long_int SamrLookupNamesInDomain(
#ifdef IDL_PROTOTYPES
    /* [in] */ domain_hnd_t hnd,
    /* [in] */ idl_long_int count,
    /* [in] */ UNICODE_STRING *names,
    /* [out] */ INDEX_ARRAY *rids,
    /* [out] */ INDEX_ARRAY *types
#endif
);
typedef struct  {
idl_long_int count;
UNICODE_STRING *string;
} UNICODE_STRING_ARRAY;
extern idl_long_int SamrLookupIdsInDomain(
#ifdef IDL_PROTOTYPES
    /* [in] */ domain_hnd_t hnd,
    /* [in] */ idl_long_int count,
    /* [in] */ idl_long_int *rids,
    /* [out] */ UNICODE_STRING_ARRAY *names,
    /* [out] */ INDEX_ARRAY *types
#endif
);
extern idl_long_int SamrOpenGroup(
#ifdef IDL_PROTOTYPES
    /* [in] */ domain_hnd_t hnd_dom,
    /* [in] */ idl_long_int access,
    /* [in] */ idl_long_int rid,
    /* [out] */ group_hnd_t *hnd
#endif
);
typedef struct  {
UNICODE_STRING name;
idl_long_int rid;
idl_long_int attrib;
UNICODE_STRING desc;
} GROUP_INFO_1;
typedef union  {
/* case(s):  */
GROUP_INFO_1 gi1;
/* case(s):  */
UNICODE_STRING name;
/* case(s):  */
idl_long_int attrib;
/* case(s):  */
UNICODE_STRING desc;
} GROUP_INFO;
extern idl_long_int SamrQueryInformationGroup(
#ifdef IDL_PROTOTYPES
    /* [in] */ group_hnd_t hnd,
    /* [in, out] */ idl_ushort_int *level,
    /* [out] */ GROUP_INFO *info
#endif
);
extern idl_long_int SamrSetInformationGroup(
#ifdef IDL_PROTOTYPES
    /* [in] */ group_hnd_t hnd,
    /* [in] */ idl_ushort_int level,
    /* [in] */ GROUP_INFO *info
#endif
);
extern idl_long_int SamrAddMemberToGroup(
#ifdef IDL_PROTOTYPES
    /* [in] */ group_hnd_t hnd,
    /* [in] */ idl_long_int group,
    /* [in] */ idl_long_int rid
#endif
);
extern idl_long_int SamrDeleteGroup(
#ifdef IDL_PROTOTYPES
    /* [in] */ group_hnd_t hnd
#endif
);
extern idl_long_int SamrRemoveMemberFromGroup(
#ifdef IDL_PROTOTYPES
    /* [in] */ group_hnd_t hnd,
    /* [in] */ idl_long_int group,
    /* [in] */ idl_long_int rid
#endif
);
typedef struct  {
idl_long_int count;
idl_long_int *rid;
idl_long_int *types;
} MEMBER_ARRAY;
extern idl_long_int SamrGetMembersInGroup(
#ifdef IDL_PROTOTYPES
    /* [in] */ group_hnd_t hnd,
    /* [out] */ MEMBER_ARRAY **members
#endif
);
extern idl_long_int SamrSetMemberAttributesOfGroup(
#ifdef IDL_PROTOTYPES
    /* [in] */ group_hnd_t hnd,
    /* [in] */ idl_long_int attrib
#endif
);
extern idl_long_int SamrOpenAlias(
#ifdef IDL_PROTOTYPES
    /* [in] */ domain_hnd_t hnd_dom,
    /* [in] */ idl_long_int access,
    /* [in] */ idl_long_int rid,
    /* [out] */ alias_hnd_t *hnd
#endif
);
typedef struct  {
UNICODE_STRING name;
idl_long_int rid;
UNICODE_STRING desc;
} ALIAS_INFO_1;
typedef union  {
/* case(s):  */
ALIAS_INFO_1 ai1;
/* case(s):  */
UNICODE_STRING name;
/* case(s):  */
UNICODE_STRING desc;
} ALIAS_INFO;
extern idl_long_int SamrQueryInformationAlias(
#ifdef IDL_PROTOTYPES
    /* [in] */ alias_hnd_t hnd,
    /* [in, out] */ idl_ushort_int *level,
    /* [out] */ ALIAS_INFO *info
#endif
);
extern idl_long_int SamrSetInformationAlias(
#ifdef IDL_PROTOTYPES
    /* [in] */ alias_hnd_t hnd,
    /* [in, out] */ idl_ushort_int *level,
    /* [in] */ ALIAS_INFO *info
#endif
);
extern idl_long_int SamrDeleteAlias(
#ifdef IDL_PROTOTYPES
    /* [in] */ alias_hnd_t hnd
#endif
);
extern idl_long_int SamrAddMemberToAlias(
#ifdef IDL_PROTOTYPES
    /* [in] */ alias_hnd_t hnd,
    /* [in] */ SID *member
#endif
);
extern idl_long_int SamrRemoveMemberFromAlias(
#ifdef IDL_PROTOTYPES
    /* [in] */ alias_hnd_t hnd,
    /* [in] */ SID *member
#endif
);
extern idl_long_int SamrGetMembersInAlias(
#ifdef IDL_PROTOTYPES
    /* [in] */ alias_hnd_t hnd,
    /* [out] */ PSID_ARRAY *members
#endif
);
extern idl_long_int SamrOpenUser(
#ifdef IDL_PROTOTYPES
    /* [in] */ domain_hnd_t hnd_dom,
    /* [in] */ idl_long_int access,
    /* [in] */ idl_long_int rid,
    /* [out] */ user_hnd_t *hnd
#endif
);
extern idl_long_int SamrDeleteUser(
#ifdef IDL_PROTOTYPES
    /* [in] */ user_hnd_t hnd
#endif
);
typedef struct  {
UNICODE_STRING acct_name;
UNICODE_STRING full_name;
idl_long_int acct_ctrl;
UNICODE_STRING home;
UNICODE_STRING script;
} USER_INFO_1;
typedef struct  {
UNICODE_STRING acct_name;
UNICODE_STRING full_name;
idl_short_int bad_pwd_count;
idl_short_int logon_count;
} USER_INFO_2;
typedef struct  {
idl_short_int divisions;
idl_char *hours;
} LOGON_HOURS;
typedef struct  {
UNICODE_STRING acct_name;
UNICODE_STRING full_name;
idl_long_int user_rid;
idl_long_int group_rid;
UNICODE_STRING home;
UNICODE_STRING home_drive;
UNICODE_STRING script;
UNICODE_STRING acct_desc;
UNICODE_STRING workstations;
NTTIME logon_time;
NTTIME logoff_time;
NTTIME pwd_last_set_time;
NTTIME pwd_can_change_time;
NTTIME pwd_must_change_time;
LOGON_HOURS hours;
idl_short_int logon_count;
idl_short_int bad_pw_count;
idl_long_int acct_ctrl;
} USER_INFO_3;
typedef struct  {
UNICODE_STRING acct_name;
UNICODE_STRING full_name;
idl_long_int user_rid;
idl_long_int group_rid;
idl_short_int country;
idl_short_int codepage;
UNICODE_STRING home;
UNICODE_STRING home_drive;
UNICODE_STRING script;
UNICODE_STRING acct_desc;
UNICODE_STRING workstations;
NTTIME logon_time;
NTTIME logoff_time;
LOGON_HOURS hours;
idl_short_int bad_pwd_count;
idl_short_int logon_count;
NTTIME pwd_last_set_time;
NTTIME acct_expiry_time;
idl_long_int acct_ctrl;
} USER_INFO_5;
typedef struct  {
UNICODE_STRING acct_name;
UNICODE_STRING full_name;
} USER_INFO_6;
typedef struct  {
idl_char hash[16];
} CRYPT_HASH;
typedef struct  {
CRYPT_HASH nt_hash;
CRYPT_HASH lm_hash;
idl_char unknown1;
idl_char unknown2;
idl_char unknown3;
} USER_INFO_18;
typedef struct  {
idl_long_int acct_ctrl;
NTTIME logon_time;
NTTIME logoff_time;
idl_short_int bad_pwd_count;
idl_short_int logon_count;
} USER_INFO_19;
typedef struct  {
NTTIME logon_time;
NTTIME logoff_time;
NTTIME kickoff_time;
NTTIME pwd_last_set_time;
NTTIME pwd_can_change_time;
NTTIME pwd_must_change_time;
UNICODE_STRING acct_name;
UNICODE_STRING full_name;
UNICODE_STRING home;
UNICODE_STRING home_drive;
UNICODE_STRING script;
UNICODE_STRING profile;
UNICODE_STRING acct_desc;
UNICODE_STRING workstations;
UNICODE_STRING comment;
UNICODE_STRING parameters;
UNICODE_STRING reserved1;
UNICODE_STRING reserved2;
UNICODE_STRING reserved3;
BUFFER sec_desc;
idl_long_int user_rid;
idl_long_int group_rid;
idl_long_int acct_ctrl;
idl_long_int unknown1;
LOGON_HOURS hours;
idl_short_int bad_pwd_count;
idl_short_int logon_count;
idl_short_int country;
idl_short_int codepage;
idl_char nt_pwd_set;
idl_char lm_pwd_set;
idl_char pwd_expired;
idl_char unknown2;
} USER_INFO_21;
typedef struct  {
USER_INFO_21 info;
LARGE_INTEGER revision;
} USER_INFO_22;
typedef struct  {
idl_char password[516];
} CRYPT_PASSWORD;
typedef struct  {
USER_INFO_21 info;
CRYPT_PASSWORD pwd;
} USER_INFO_23;
typedef struct  {
CRYPT_PASSWORD pwd;
idl_char unknown;
} USER_INFO_24;
typedef union  {
/* case(s):  */
USER_INFO_1 ui1;
/* case(s):  */
USER_INFO_2 ui2;
/* case(s):  */
USER_INFO_3 ui3;
/* case(s):  */
LOGON_HOURS hours;
/* case(s):  */
USER_INFO_5 ui5;
/* case(s):  */
USER_INFO_6 ui6;
/* case(s):  */
UNICODE_STRING full_name;
/* case(s):  */
UNICODE_STRING acct_desc;
/* case(s):  */
idl_long_int unknown1;
/* case(s):  */
USER_INFO_6 ui10;
/* case(s):  */
UNICODE_STRING home;
/* case(s):  */
UNICODE_STRING home_drive;
/* case(s):  */
UNICODE_STRING script;
/* case(s):  */
UNICODE_STRING workstations;
/* case(s):  */
idl_long_int unknown2;
/* case(s):  */
NTTIME unknown3;
/* case(s):  */
USER_INFO_18 ui18;
/* case(s):  */
USER_INFO_19 ui19;
/* case(s):  */
UNICODE_STRING profile;
/* case(s):  */
USER_INFO_21 ui21;
/* case(s):  */
USER_INFO_22 ui22;
/* case(s):  */
USER_INFO_23 ui23;
/* case(s):  */
USER_INFO_24 ui24;
} USER_INFO;
extern idl_long_int SamrQueryInformationUser(
#ifdef IDL_PROTOTYPES
    /* [in] */ user_hnd_t hnd,
    /* [in, out] */ idl_ushort_int *level,
    /* [out] */ USER_INFO *info
#endif
);
extern idl_long_int SamrSetInformationUser(
#ifdef IDL_PROTOTYPES
    /* [in] */ user_hnd_t hnd,
    /* [in] */ idl_ushort_int level,
    /* [in] */ USER_INFO *info
#endif
);
extern idl_long_int SamrChangePasswordUser(
#ifdef IDL_PROTOTYPES
    /* [in] */ user_hnd_t hnd,
    /* [in] */ idl_char unknown1,
    /* [in] */ CRYPT_HASH *hash1,
    /* [in] */ CRYPT_HASH *hash2,
    /* [in] */ idl_char unknown2,
    /* [in] */ CRYPT_HASH *hash3,
    /* [in] */ CRYPT_HASH *hash4,
    /* [in] */ idl_char unknown3,
    /* [in] */ CRYPT_HASH *hash5,
    /* [in] */ idl_char unknown4,
    /* [in] */ CRYPT_HASH *hash6
#endif
);
typedef struct samr_v1_0_3_tag {
idl_long_int rid;
idl_long_int attrib;
} USER_GROUP;
typedef struct  {
idl_long_int count;
USER_GROUP *groups;
} USER_GROUP_ARRAY;
extern idl_long_int SamrGetGroupsForUser(
#ifdef IDL_PROTOTYPES
    /* [in] */ user_hnd_t hnd,
    /* [out] */ USER_GROUP_ARRAY **groups
#endif
);
typedef struct samr_v1_0_4_tag {
idl_long_int index;
idl_long_int user_rid;
idl_long_int acct_ctrl;
UNICODE_STRING acct_name;
UNICODE_STRING full_name;
UNICODE_STRING acct_desc;
} USER_DISPINFO_1;
typedef struct  {
idl_long_int count;
USER_DISPINFO_1 *users;
} USER_DISPINFO_1_ARRAY;
typedef struct samr_v1_0_5_tag {
idl_long_int index;
idl_long_int user_rid;
idl_long_int acct_ctrl;
UNICODE_STRING acct_name;
UNICODE_STRING acct_desc;
} USER_DISPINFO_2;
typedef struct  {
idl_long_int count;
USER_DISPINFO_2 *users;
} USER_DISPINFO_2_ARRAY;
typedef struct samr_v1_0_6_tag {
idl_long_int index;
idl_long_int rid;
idl_long_int attrib;
UNICODE_STRING name;
UNICODE_STRING desc;
} GROUP_DISPINFO;
typedef struct  {
idl_long_int count;
GROUP_DISPINFO *groups;
} GROUP_DISPINFO_ARRAY;
typedef struct  {
idl_short_int length;
idl_short_int size;
idl_char *string;
} STRING;
typedef struct samr_v1_0_7_tag {
idl_long_int index;
STRING name;
} ASCII_DISPINFO;
typedef struct  {
idl_long_int count;
ASCII_DISPINFO *info;
} ASCII_DISPINFO_ARRAY;
typedef union  {
/* case(s):  */
USER_DISPINFO_1_ARRAY users1;
/* case(s):  */
USER_DISPINFO_2_ARRAY users2;
/* case(s):  */
GROUP_DISPINFO_ARRAY groups;
/* case(s):  */
ASCII_DISPINFO_ARRAY ausers;
/* case(s):  */
ASCII_DISPINFO_ARRAY agroups;
} DISPLAY_INFO;
extern idl_long_int SamrQueryDisplayInformation(
#ifdef IDL_PROTOTYPES
    /* [in] */ domain_hnd_t hnd,
    /* [in, out] */ idl_ushort_int *level,
    /* [in] */ idl_long_int start_idx,
    /* [in] */ idl_long_int max_entries,
    /* [in] */ idl_long_int pref_maxsize,
    /* [out] */ idl_long_int *total_size,
    /* [out] */ idl_long_int *ret_size,
    /* [out] */ DISPLAY_INFO *info
#endif
);
extern idl_long_int SamrGetDisplayEnumerationIndex(
#ifdef IDL_PROTOTYPES
    /* [in] */ domain_hnd_t hnd,
    /* [in] */ idl_ushort_int level,
    /* [in] */ UNICODE_STRING *name,
    /* [out] */ idl_long_int *index
#endif
);
extern idl_long_int SamrTestPrivateFunctionsDomain(
#ifdef IDL_PROTOTYPES
    /* [in] */ connect_hnd_t hnd
#endif
);
extern idl_long_int SamrTestPrivateFunctionsUser(
#ifdef IDL_PROTOTYPES
    /* [in] */ user_hnd_t hnd
#endif
);
typedef struct  {
idl_short_int unknown1;
idl_long_int unknown2;
} PASSWORD_INFO;
extern idl_long_int SamrGetUserDomPasswordInfo(
#ifdef IDL_PROTOTYPES
    /* [in] */ user_hnd_t *hnd,
    /* [out] */ PASSWORD_INFO *info
#endif
);
extern idl_long_int SamrRemoveMemFromForeignDom(
#ifdef IDL_PROTOTYPES
    /* [in] */ unknown_hnd_t hnd,
    /* [in] */ SID *member
#endif
);
extern idl_long_int SamrQueryInformationDomain2(
#ifdef IDL_PROTOTYPES
    /* [in] */ domain_hnd_t hnd,
    /* [in, out] */ idl_ushort_int *level,
    /* [out] */ DOMAIN_INFO *info
#endif
);
extern idl_long_int SamrQueryInformationUser2(
#ifdef IDL_PROTOTYPES
    /* [in] */ user_hnd_t hnd,
    /* [in, out] */ idl_ushort_int *level,
    /* [out] */ USER_INFO *info
#endif
);
extern idl_long_int SamrQueryDisplayInformation2(
#ifdef IDL_PROTOTYPES
    /* [in] */ domain_hnd_t hnd,
    /* [in, out] */ idl_ushort_int *level,
    /* [in] */ idl_long_int start_idx,
    /* [in] */ idl_long_int max_entries,
    /* [in] */ idl_long_int pref_maxsize,
    /* [out] */ idl_long_int *total_size,
    /* [out] */ idl_long_int *ret_size,
    /* [out] */ DISPLAY_INFO *info
#endif
);
extern idl_long_int SamrGetDisplayEnumerationIndex2(
#ifdef IDL_PROTOTYPES
    /* [in] */ domain_hnd_t hnd,
    /* [in] */ idl_ushort_int level,
    /* [in] */ UNICODE_STRING *name,
    /* [out] */ idl_long_int *index
#endif
);
extern idl_long_int SamrCreateUser2InDomain(
#ifdef IDL_PROTOTYPES
    /* [in] */ domain_hnd_t hnd_dom,
    /* [in] */ UNICODE_STRING *name,
    /* [in] */ idl_long_int acct_ctrl,
    /* [in] */ idl_long_int access,
    /* [out] */ user_hnd_t *hnd,
    /* [out] */ idl_long_int *unknown,
    /* [out] */ idl_long_int *rid
#endif
);
extern idl_long_int SamrQueryDisplayInformation3(
#ifdef IDL_PROTOTYPES
    /* [in] */ domain_hnd_t hnd,
    /* [in, out] */ idl_ushort_int *level,
    /* [in] */ idl_long_int start_idx,
    /* [in] */ idl_long_int max_entries,
    /* [in] */ idl_long_int pref_maxsize,
    /* [out] */ idl_long_int *total_size,
    /* [out] */ idl_long_int *ret_size,
    /* [out] */ DISPLAY_INFO *info
#endif
);
extern idl_long_int SamrAddMultipleMembersToAlias(
#ifdef IDL_PROTOTYPES
    /* [in] */ alias_hnd_t hnd,
    /* [in] */ PSID_ARRAY *sids
#endif
);
extern idl_long_int SamrRemoveMultMemsFromAlias(
#ifdef IDL_PROTOTYPES
    /* [in] */ alias_hnd_t hnd,
    /* [in] */ PSID_ARRAY *sids
#endif
);
extern idl_long_int SamrOemChangePasswordUser2(
#ifdef IDL_PROTOTYPES
    /* [in] */ handle_t hnd,
    /* [in] */ STRING *server,
    /* [in] */ STRING *user,
    /* [in] */ CRYPT_PASSWORD *lm_newpass,
    /* [in] */ CRYPT_HASH *lm_oldhash
#endif
);
extern idl_long_int SamrUniChangePasswordUser2(
#ifdef IDL_PROTOTYPES
    /* [in] */ handle_t hnd,
    /* [in] */ UNICODE_STRING *server,
    /* [in] */ UNICODE_STRING *user,
    /* [in] */ CRYPT_PASSWORD *nt_newpass,
    /* [in] */ CRYPT_HASH *nt_oldhash,
    /* [in] */ idl_char lm_change,
    /* [in] */ CRYPT_PASSWORD *lm_newpass,
    /* [in] */ CRYPT_HASH *lm_oldhash
#endif
);
extern idl_long_int SamrGetDomainPasswordInfo(
#ifdef IDL_PROTOTYPES
    /* [in] */ handle_t hnd,
    /* [in] */ UNICODE_STRING *domain,
    /* [out] */ PASSWORD_INFO *info
#endif
);
extern idl_long_int SamrConnect2(
#ifdef IDL_PROTOTYPES
    /* [in] */ handle_t h,
    /* [in] */ idl_ushort_int *server,
    /* [out] */ connect_hnd_t *hnd,
    /* [in] */ idl_long_int access
#endif
);
extern idl_long_int SamrSetInformationUser2(
#ifdef IDL_PROTOTYPES
    /* [in] */ user_hnd_t hnd,
    /* [in] */ idl_ushort_int level,
    /* [in] */ USER_INFO *info
#endif
);
extern idl_long_int Function_3b(
#ifdef IDL_PROTOTYPES
    /* [in] */ unknown_hnd_t element_570,
    /* [in] */ idl_ushort_int element_571,
    /* [in] */ UNICODE_STRING *element_572,
    /* [in] */ UNICODE_STRING *element_573
#endif
);
extern idl_long_int Function_3c(
#ifdef IDL_PROTOTYPES
    /* [in] */ unknown_hnd_t element_574,
    /* [out] */ idl_ushort_int *element_575
#endif
);
void connect_hnd_t_rundown(
#ifdef IDL_PROTOTYPES
    rpc_ss_context_t context_handle
#endif
);
void domain_hnd_t_rundown(
#ifdef IDL_PROTOTYPES
    rpc_ss_context_t context_handle
#endif
);
void user_hnd_t_rundown(
#ifdef IDL_PROTOTYPES
    rpc_ss_context_t context_handle
#endif
);
void group_hnd_t_rundown(
#ifdef IDL_PROTOTYPES
    rpc_ss_context_t context_handle
#endif
);
void alias_hnd_t_rundown(
#ifdef IDL_PROTOTYPES
    rpc_ss_context_t context_handle
#endif
);
void obj_hnd_t_rundown(
#ifdef IDL_PROTOTYPES
    rpc_ss_context_t context_handle
#endif
);
void unknown_hnd_t_rundown(
#ifdef IDL_PROTOTYPES
    rpc_ss_context_t context_handle
#endif
);
typedef struct samr_v1_0_epv_t {
	idl_long_int (*SamrConnect)(
#ifdef IDL_PROTOTYPES
    /* [in] */ handle_t h,
    /* [in] */ idl_ushort_int server,
    /* [out] */ connect_hnd_t *hnd,
    /* [in] */ idl_long_int access
#endif
);
	idl_long_int (*SamrCloseHandle)(
#ifdef IDL_PROTOTYPES
    /* [in, out] */ connect_hnd_t *hnd
#endif
);
	idl_long_int (*SamrSetSecurityObject)(
#ifdef IDL_PROTOTYPES
    /* [in] */ obj_hnd_t hnd,
    /* [in] */ idl_long_int info_type,
    /* [in] */ BUFFER *sec_info
#endif
);
	idl_long_int (*SamrQuerySecurityObject)(
#ifdef IDL_PROTOTYPES
    /* [in] */ obj_hnd_t hnd,
    /* [in] */ idl_long_int info_type,
    /* [out] */ BUFFER **sec_info
#endif
);
	idl_long_int (*SamrShutdownSamServer)(
#ifdef IDL_PROTOTYPES
    /* [in] */ connect_hnd_t hnd
#endif
);
	idl_long_int (*SamrLookupDomainInSamServer)(
#ifdef IDL_PROTOTYPES
    /* [in] */ connect_hnd_t hnd,
    /* [in] */ UNICODE_STRING *domain,
    /* [out] */ SID **sid
#endif
);
	idl_long_int (*SamrEnumerateDomainsInSamServer)(
#ifdef IDL_PROTOTYPES
    /* [in] */ connect_hnd_t hnd,
    /* [in, out] */ idl_long_int *resume_hnd,
    /* [out] */ IDX_AND_NAME_ARRAY **domains,
    /* [in] */ idl_long_int pref_maxlen,
    /* [out] */ idl_long_int *entries
#endif
);
	idl_long_int (*SamrOpenDomain)(
#ifdef IDL_PROTOTYPES
    /* [in] */ connect_hnd_t sam_hnd,
    /* [in] */ idl_long_int access,
    /* [in] */ SID *domain,
    /* [out] */ domain_hnd_t *hnd
#endif
);
	idl_long_int (*SamrQueryInformationDomain)(
#ifdef IDL_PROTOTYPES
    /* [in] */ domain_hnd_t hnd,
    /* [in, out] */ idl_ushort_int *level,
    /* [out] */ DOMAIN_INFO *info
#endif
);
	idl_long_int (*SamrSetInformationDomain)(
#ifdef IDL_PROTOTYPES
    /* [in] */ domain_hnd_t hnd,
    /* [in] */ idl_ushort_int level,
    /* [in] */ DOMAIN_INFO *info
#endif
);
	idl_long_int (*SamrCreateGroupInDomain)(
#ifdef IDL_PROTOTYPES
    /* [in] */ domain_hnd_t hnd_dom,
    /* [in] */ UNICODE_STRING *name,
    /* [in] */ idl_long_int access,
    /* [out] */ group_hnd_t *hnd,
    /* [out] */ idl_long_int *rid
#endif
);
	idl_long_int (*SamrEnumerateGroupsInDomain)(
#ifdef IDL_PROTOTYPES
    /* [in] */ domain_hnd_t hnd,
    /* [in, out] */ idl_long_int *resume_hnd,
    /* [in] */ idl_long_int mask,
    /* [out] */ IDX_AND_NAME_ARRAY **groups,
    /* [in] */ idl_long_int pref_maxlen,
    /* [out] */ idl_long_int *entries
#endif
);
	idl_long_int (*SamrCreateUserInDomain)(
#ifdef IDL_PROTOTYPES
    /* [in] */ domain_hnd_t hnd_dom,
    /* [in] */ UNICODE_STRING *name,
    /* [in] */ idl_long_int access,
    /* [out] */ user_hnd_t *hnd,
    /* [out] */ idl_long_int *rid
#endif
);
	idl_long_int (*SamrEnumerateUsersInDomain)(
#ifdef IDL_PROTOTYPES
    /* [in] */ domain_hnd_t hnd,
    /* [in, out] */ idl_long_int *resume_hnd,
    /* [in] */ idl_long_int mask,
    /* [out] */ IDX_AND_NAME_ARRAY **groups,
    /* [in] */ idl_long_int pref_maxlen,
    /* [out] */ idl_long_int *entries
#endif
);
	idl_long_int (*SamrCreateAliasInDomain)(
#ifdef IDL_PROTOTYPES
    /* [in] */ domain_hnd_t hnd_dom,
    /* [in] */ UNICODE_STRING *name,
    /* [in] */ idl_long_int access,
    /* [out] */ alias_hnd_t *hnd,
    /* [out] */ idl_long_int *rid
#endif
);
	idl_long_int (*SamrEnumerateAliasesInDomain)(
#ifdef IDL_PROTOTYPES
    /* [in] */ domain_hnd_t hnd,
    /* [in, out] */ idl_long_int *resume_hnd,
    /* [in] */ idl_long_int mask,
    /* [out] */ IDX_AND_NAME_ARRAY **groups,
    /* [in] */ idl_long_int pref_maxlen,
    /* [out] */ idl_long_int *entries
#endif
);
	idl_long_int (*SamrGetAliasMembersip)(
#ifdef IDL_PROTOTYPES
    /* [in] */ alias_hnd_t hnd,
    /* [in] */ PSID_ARRAY *sids,
    /* [out] */ INDEX_ARRAY *aliases
#endif
);
	idl_long_int (*SamrLookupNamesInDomain)(
#ifdef IDL_PROTOTYPES
    /* [in] */ domain_hnd_t hnd,
    /* [in] */ idl_long_int count,
    /* [in] */ UNICODE_STRING *names,
    /* [out] */ INDEX_ARRAY *rids,
    /* [out] */ INDEX_ARRAY *types
#endif
);
	idl_long_int (*SamrLookupIdsInDomain)(
#ifdef IDL_PROTOTYPES
    /* [in] */ domain_hnd_t hnd,
    /* [in] */ idl_long_int count,
    /* [in] */ idl_long_int *rids,
    /* [out] */ UNICODE_STRING_ARRAY *names,
    /* [out] */ INDEX_ARRAY *types
#endif
);
	idl_long_int (*SamrOpenGroup)(
#ifdef IDL_PROTOTYPES
    /* [in] */ domain_hnd_t hnd_dom,
    /* [in] */ idl_long_int access,
    /* [in] */ idl_long_int rid,
    /* [out] */ group_hnd_t *hnd
#endif
);
	idl_long_int (*SamrQueryInformationGroup)(
#ifdef IDL_PROTOTYPES
    /* [in] */ group_hnd_t hnd,
    /* [in, out] */ idl_ushort_int *level,
    /* [out] */ GROUP_INFO *info
#endif
);
	idl_long_int (*SamrSetInformationGroup)(
#ifdef IDL_PROTOTYPES
    /* [in] */ group_hnd_t hnd,
    /* [in] */ idl_ushort_int level,
    /* [in] */ GROUP_INFO *info
#endif
);
	idl_long_int (*SamrAddMemberToGroup)(
#ifdef IDL_PROTOTYPES
    /* [in] */ group_hnd_t hnd,
    /* [in] */ idl_long_int group,
    /* [in] */ idl_long_int rid
#endif
);
	idl_long_int (*SamrDeleteGroup)(
#ifdef IDL_PROTOTYPES
    /* [in] */ group_hnd_t hnd
#endif
);
	idl_long_int (*SamrRemoveMemberFromGroup)(
#ifdef IDL_PROTOTYPES
    /* [in] */ group_hnd_t hnd,
    /* [in] */ idl_long_int group,
    /* [in] */ idl_long_int rid
#endif
);
	idl_long_int (*SamrGetMembersInGroup)(
#ifdef IDL_PROTOTYPES
    /* [in] */ group_hnd_t hnd,
    /* [out] */ MEMBER_ARRAY **members
#endif
);
	idl_long_int (*SamrSetMemberAttributesOfGroup)(
#ifdef IDL_PROTOTYPES
    /* [in] */ group_hnd_t hnd,
    /* [in] */ idl_long_int attrib
#endif
);
	idl_long_int (*SamrOpenAlias)(
#ifdef IDL_PROTOTYPES
    /* [in] */ domain_hnd_t hnd_dom,
    /* [in] */ idl_long_int access,
    /* [in] */ idl_long_int rid,
    /* [out] */ alias_hnd_t *hnd
#endif
);
	idl_long_int (*SamrQueryInformationAlias)(
#ifdef IDL_PROTOTYPES
    /* [in] */ alias_hnd_t hnd,
    /* [in, out] */ idl_ushort_int *level,
    /* [out] */ ALIAS_INFO *info
#endif
);
	idl_long_int (*SamrSetInformationAlias)(
#ifdef IDL_PROTOTYPES
    /* [in] */ alias_hnd_t hnd,
    /* [in, out] */ idl_ushort_int *level,
    /* [in] */ ALIAS_INFO *info
#endif
);
	idl_long_int (*SamrDeleteAlias)(
#ifdef IDL_PROTOTYPES
    /* [in] */ alias_hnd_t hnd
#endif
);
	idl_long_int (*SamrAddMemberToAlias)(
#ifdef IDL_PROTOTYPES
    /* [in] */ alias_hnd_t hnd,
    /* [in] */ SID *member
#endif
);
	idl_long_int (*SamrRemoveMemberFromAlias)(
#ifdef IDL_PROTOTYPES
    /* [in] */ alias_hnd_t hnd,
    /* [in] */ SID *member
#endif
);
	idl_long_int (*SamrGetMembersInAlias)(
#ifdef IDL_PROTOTYPES
    /* [in] */ alias_hnd_t hnd,
    /* [out] */ PSID_ARRAY *members
#endif
);
	idl_long_int (*SamrOpenUser)(
#ifdef IDL_PROTOTYPES
    /* [in] */ domain_hnd_t hnd_dom,
    /* [in] */ idl_long_int access,
    /* [in] */ idl_long_int rid,
    /* [out] */ user_hnd_t *hnd
#endif
);
	idl_long_int (*SamrDeleteUser)(
#ifdef IDL_PROTOTYPES
    /* [in] */ user_hnd_t hnd
#endif
);
	idl_long_int (*SamrQueryInformationUser)(
#ifdef IDL_PROTOTYPES
    /* [in] */ user_hnd_t hnd,
    /* [in, out] */ idl_ushort_int *level,
    /* [out] */ USER_INFO *info
#endif
);
	idl_long_int (*SamrSetInformationUser)(
#ifdef IDL_PROTOTYPES
    /* [in] */ user_hnd_t hnd,
    /* [in] */ idl_ushort_int level,
    /* [in] */ USER_INFO *info
#endif
);
	idl_long_int (*SamrChangePasswordUser)(
#ifdef IDL_PROTOTYPES
    /* [in] */ user_hnd_t hnd,
    /* [in] */ idl_char unknown1,
    /* [in] */ CRYPT_HASH *hash1,
    /* [in] */ CRYPT_HASH *hash2,
    /* [in] */ idl_char unknown2,
    /* [in] */ CRYPT_HASH *hash3,
    /* [in] */ CRYPT_HASH *hash4,
    /* [in] */ idl_char unknown3,
    /* [in] */ CRYPT_HASH *hash5,
    /* [in] */ idl_char unknown4,
    /* [in] */ CRYPT_HASH *hash6
#endif
);
	idl_long_int (*SamrGetGroupsForUser)(
#ifdef IDL_PROTOTYPES
    /* [in] */ user_hnd_t hnd,
    /* [out] */ USER_GROUP_ARRAY **groups
#endif
);
	idl_long_int (*SamrQueryDisplayInformation)(
#ifdef IDL_PROTOTYPES
    /* [in] */ domain_hnd_t hnd,
    /* [in, out] */ idl_ushort_int *level,
    /* [in] */ idl_long_int start_idx,
    /* [in] */ idl_long_int max_entries,
    /* [in] */ idl_long_int pref_maxsize,
    /* [out] */ idl_long_int *total_size,
    /* [out] */ idl_long_int *ret_size,
    /* [out] */ DISPLAY_INFO *info
#endif
);
	idl_long_int (*SamrGetDisplayEnumerationIndex)(
#ifdef IDL_PROTOTYPES
    /* [in] */ domain_hnd_t hnd,
    /* [in] */ idl_ushort_int level,
    /* [in] */ UNICODE_STRING *name,
    /* [out] */ idl_long_int *index
#endif
);
	idl_long_int (*SamrTestPrivateFunctionsDomain)(
#ifdef IDL_PROTOTYPES
    /* [in] */ connect_hnd_t hnd
#endif
);
	idl_long_int (*SamrTestPrivateFunctionsUser)(
#ifdef IDL_PROTOTYPES
    /* [in] */ user_hnd_t hnd
#endif
);
	idl_long_int (*SamrGetUserDomPasswordInfo)(
#ifdef IDL_PROTOTYPES
    /* [in] */ user_hnd_t *hnd,
    /* [out] */ PASSWORD_INFO *info
#endif
);
	idl_long_int (*SamrRemoveMemFromForeignDom)(
#ifdef IDL_PROTOTYPES
    /* [in] */ unknown_hnd_t hnd,
    /* [in] */ SID *member
#endif
);
	idl_long_int (*SamrQueryInformationDomain2)(
#ifdef IDL_PROTOTYPES
    /* [in] */ domain_hnd_t hnd,
    /* [in, out] */ idl_ushort_int *level,
    /* [out] */ DOMAIN_INFO *info
#endif
);
	idl_long_int (*SamrQueryInformationUser2)(
#ifdef IDL_PROTOTYPES
    /* [in] */ user_hnd_t hnd,
    /* [in, out] */ idl_ushort_int *level,
    /* [out] */ USER_INFO *info
#endif
);
	idl_long_int (*SamrQueryDisplayInformation2)(
#ifdef IDL_PROTOTYPES
    /* [in] */ domain_hnd_t hnd,
    /* [in, out] */ idl_ushort_int *level,
    /* [in] */ idl_long_int start_idx,
    /* [in] */ idl_long_int max_entries,
    /* [in] */ idl_long_int pref_maxsize,
    /* [out] */ idl_long_int *total_size,
    /* [out] */ idl_long_int *ret_size,
    /* [out] */ DISPLAY_INFO *info
#endif
);
	idl_long_int (*SamrGetDisplayEnumerationIndex2)(
#ifdef IDL_PROTOTYPES
    /* [in] */ domain_hnd_t hnd,
    /* [in] */ idl_ushort_int level,
    /* [in] */ UNICODE_STRING *name,
    /* [out] */ idl_long_int *index
#endif
);
	idl_long_int (*SamrCreateUser2InDomain)(
#ifdef IDL_PROTOTYPES
    /* [in] */ domain_hnd_t hnd_dom,
    /* [in] */ UNICODE_STRING *name,
    /* [in] */ idl_long_int acct_ctrl,
    /* [in] */ idl_long_int access,
    /* [out] */ user_hnd_t *hnd,
    /* [out] */ idl_long_int *unknown,
    /* [out] */ idl_long_int *rid
#endif
);
	idl_long_int (*SamrQueryDisplayInformation3)(
#ifdef IDL_PROTOTYPES
    /* [in] */ domain_hnd_t hnd,
    /* [in, out] */ idl_ushort_int *level,
    /* [in] */ idl_long_int start_idx,
    /* [in] */ idl_long_int max_entries,
    /* [in] */ idl_long_int pref_maxsize,
    /* [out] */ idl_long_int *total_size,
    /* [out] */ idl_long_int *ret_size,
    /* [out] */ DISPLAY_INFO *info
#endif
);
	idl_long_int (*SamrAddMultipleMembersToAlias)(
#ifdef IDL_PROTOTYPES
    /* [in] */ alias_hnd_t hnd,
    /* [in] */ PSID_ARRAY *sids
#endif
);
	idl_long_int (*SamrRemoveMultMemsFromAlias)(
#ifdef IDL_PROTOTYPES
    /* [in] */ alias_hnd_t hnd,
    /* [in] */ PSID_ARRAY *sids
#endif
);
	idl_long_int (*SamrOemChangePasswordUser2)(
#ifdef IDL_PROTOTYPES
    /* [in] */ handle_t hnd,
    /* [in] */ STRING *server,
    /* [in] */ STRING *user,
    /* [in] */ CRYPT_PASSWORD *lm_newpass,
    /* [in] */ CRYPT_HASH *lm_oldhash
#endif
);
	idl_long_int (*SamrUniChangePasswordUser2)(
#ifdef IDL_PROTOTYPES
    /* [in] */ handle_t hnd,
    /* [in] */ UNICODE_STRING *server,
    /* [in] */ UNICODE_STRING *user,
    /* [in] */ CRYPT_PASSWORD *nt_newpass,
    /* [in] */ CRYPT_HASH *nt_oldhash,
    /* [in] */ idl_char lm_change,
    /* [in] */ CRYPT_PASSWORD *lm_newpass,
    /* [in] */ CRYPT_HASH *lm_oldhash
#endif
);
	idl_long_int (*SamrGetDomainPasswordInfo)(
#ifdef IDL_PROTOTYPES
    /* [in] */ handle_t hnd,
    /* [in] */ UNICODE_STRING *domain,
    /* [out] */ PASSWORD_INFO *info
#endif
);
	idl_long_int (*SamrConnect2)(
#ifdef IDL_PROTOTYPES
    /* [in] */ handle_t h,
    /* [in] */ idl_ushort_int *server,
    /* [out] */ connect_hnd_t *hnd,
    /* [in] */ idl_long_int access
#endif
);
	idl_long_int (*SamrSetInformationUser2)(
#ifdef IDL_PROTOTYPES
    /* [in] */ user_hnd_t hnd,
    /* [in] */ idl_ushort_int level,
    /* [in] */ USER_INFO *info
#endif
);
	idl_long_int (*Function_3b)(
#ifdef IDL_PROTOTYPES
    /* [in] */ unknown_hnd_t element_570,
    /* [in] */ idl_ushort_int element_571,
    /* [in] */ UNICODE_STRING *element_572,
    /* [in] */ UNICODE_STRING *element_573
#endif
);
	idl_long_int (*Function_3c)(
#ifdef IDL_PROTOTYPES
    /* [in] */ unknown_hnd_t element_574,
    /* [out] */ idl_ushort_int *element_575
#endif
);
} samr_v1_0_epv_t;
extern rpc_if_handle_t samr_v1_0_c_ifspec;
extern rpc_if_handle_t samr_v1_0_s_ifspec;

#ifdef __cplusplus
    }
#endif

#endif
