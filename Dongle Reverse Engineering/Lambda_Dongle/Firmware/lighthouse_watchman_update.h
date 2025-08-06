typedef unsigned char   undefined;

typedef unsigned char    bool;
typedef unsigned char    byte;
typedef unsigned char    dwfenc;
typedef unsigned int    dword;
typedef long double    longdouble;
typedef long long    longlong;
typedef unsigned long    qword;
typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned long long    ulonglong;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined3;
typedef unsigned int    undefined4;
typedef unsigned long    undefined5;
typedef unsigned long    undefined6;
typedef unsigned long    undefined8;
typedef unsigned short    ushort;
typedef unsigned short    wchar16;
typedef unsigned int    wchar32;
typedef int    wchar_t;
typedef unsigned short    word;
#define unkbyte9   unsigned long long
#define unkbyte10   unsigned long long
#define unkbyte11   unsigned long long
#define unkbyte12   unsigned long long
#define unkbyte13   unsigned long long
#define unkbyte14   unsigned long long
#define unkbyte15   unsigned long long
#define unkbyte16   unsigned long long

#define unkuint9   unsigned long long
#define unkuint10   unsigned long long
#define unkuint11   unsigned long long
#define unkuint12   unsigned long long
#define unkuint13   unsigned long long
#define unkuint14   unsigned long long
#define unkuint15   unsigned long long
#define unkuint16   unsigned long long

#define unkint9   long long
#define unkint10   long long
#define unkint11   long long
#define unkint12   long long
#define unkint13   long long
#define unkint14   long long
#define unkint15   long long
#define unkint16   long long

#define unkfloat1   float
#define unkfloat2   float
#define unkfloat3   float
#define unkfloat5   double
#define unkfloat6   double
#define unkfloat7   double
#define unkfloat9   long double
#define unkfloat11   long double
#define unkfloat12   long double
#define unkfloat13   long double
#define unkfloat14   long double
#define unkfloat15   long double
#define unkfloat16   long double

#define BADSPACEBASE   void
#define code   void

typedef struct CLog CLog, *PCLog;

struct CLog { // PlaceHolder Class Structure
};

typedef struct CAssert CAssert, *PCAssert;

struct CAssert { // PlaceHolder Class Structure
};

typedef struct vortex vortex, *Pvortex;

struct vortex { // PlaceHolder Class Structure
};

typedef struct CThreadRWLock CThreadRWLock, *PCThreadRWLock;

struct CThreadRWLock { // PlaceHolder Class Structure
};

typedef struct eh_frame_hdr eh_frame_hdr, *Peh_frame_hdr;

struct eh_frame_hdr {
    byte eh_frame_hdr_version; // Exception Handler Frame Header Version
    dwfenc eh_frame_pointer_encoding; // Exception Handler Frame Pointer Encoding
    dwfenc eh_frame_desc_entry_count_encoding; // Encoding of # of Exception Handler FDEs
    dwfenc eh_frame_table_encoding; // Exception Handler Table Encoding
};

typedef struct CThreadSpinRWLock CThreadSpinRWLock, *PCThreadSpinRWLock;

struct CThreadSpinRWLock { // PlaceHolder Class Structure
};

typedef struct CThreadSpinLock CThreadSpinLock, *PCThreadSpinLock;

struct CThreadSpinLock { // PlaceHolder Class Structure
};

typedef struct LSFRCRC LSFRCRC, *PLSFRCRC;

struct LSFRCRC { // PlaceHolder Class Structure
};

typedef struct fde_table_entry fde_table_entry, *Pfde_table_entry;

struct fde_table_entry {
    dword initial_loc; // Initial Location
    dword data_loc; // Data location
};

typedef void _IO_lock_t;

typedef struct _IO_marker _IO_marker, *P_IO_marker;

typedef struct _IO_FILE _IO_FILE, *P_IO_FILE;

typedef long __off_t;

typedef long __off64_t;

typedef ulong size_t;

struct _IO_FILE {
    int _flags;
    char *_IO_read_ptr;
    char *_IO_read_end;
    char *_IO_read_base;
    char *_IO_write_base;
    char *_IO_write_ptr;
    char *_IO_write_end;
    char *_IO_buf_base;
    char *_IO_buf_end;
    char *_IO_save_base;
    char *_IO_backup_base;
    char *_IO_save_end;
    struct _IO_marker *_markers;
    struct _IO_FILE *_chain;
    int _fileno;
    int _flags2;
    __off_t _old_offset;
    ushort _cur_column;
    char _vtable_offset;
    char _shortbuf[1];
    _IO_lock_t *_lock;
    __off64_t _offset;
    void *__pad1;
    void *__pad2;
    void *__pad3;
    void *__pad4;
    size_t __pad5;
    int _mode;
    char _unused2[20];
};

struct _IO_marker {
    struct _IO_marker *_next;
    struct _IO_FILE *_sbuf;
    int _pos;
};

typedef enum __priority_which {
    PRIO_PROCESS=0,
    PRIO_PGRP=1,
    PRIO_USER=2
} __priority_which;

typedef enum __priority_which __priority_which_t;

typedef struct rlimit rlimit, *Prlimit;

typedef ulong __rlim_t;

typedef __rlim_t rlim_t;

struct rlimit {
    rlim_t rlim_cur;
    rlim_t rlim_max;
};

typedef enum __rlimit_resource {
    RLIMIT_CPU=0,
    RLIMIT_FSIZE=1,
    RLIMIT_DATA=2,
    RLIMIT_STACK=3,
    RLIMIT_CORE=4,
    __RLIMIT_RSS=5,
    __RLIMIT_NPROC=6,
    RLIMIT_NOFILE=7,
    __RLIMIT_MEMLOCK=8,
    __RLIMIT_OFILE=8,
    RLIMIT_AS=9,
    __RLIMIT_LOCKS=10,
    __RLIMIT_SIGPENDING=11,
    __RLIMIT_MSGQUEUE=12,
    __RLIMIT_NICE=13,
    __RLIMIT_RTPRIO=14,
    __RLIMIT_NLIMITS=15,
    __RLIM_NLIMITS=16
} __rlimit_resource;

typedef enum __rlimit_resource __rlimit_resource_t;

typedef struct stat64 stat64, *Pstat64;

typedef ulong __dev_t;

typedef ulong __ino64_t;

typedef ulong __nlink_t;

typedef uint __mode_t;

typedef uint __uid_t;

typedef uint __gid_t;

typedef long __blksize_t;

typedef long __blkcnt64_t;

typedef struct timespec timespec, *Ptimespec;

typedef long __time_t;

struct timespec {
    __time_t tv_sec;
    long tv_nsec;
};

struct stat64 {
    __dev_t st_dev;
    __ino64_t st_ino;
    __nlink_t st_nlink;
    __mode_t st_mode;
    __uid_t st_uid;
    __gid_t st_gid;
    int __pad0;
    __dev_t st_rdev;
    __off_t st_size;
    __blksize_t st_blksize;
    __blkcnt64_t st_blocks;
    struct timespec st_atim;
    struct timespec st_mtim;
    struct timespec st_ctim;
    long __unused[3];
};

typedef struct stat stat, *Pstat;

typedef ulong __ino_t;

typedef long __blkcnt_t;

struct stat {
    __dev_t st_dev;
    __ino_t st_ino;
    __nlink_t st_nlink;
    __mode_t st_mode;
    __uid_t st_uid;
    __gid_t st_gid;
    int __pad0;
    __dev_t st_rdev;
    __off_t st_size;
    __blksize_t st_blksize;
    __blkcnt_t st_blocks;
    struct timespec st_atim;
    struct timespec st_mtim;
    struct timespec st_ctim;
    long __unused[3];
};

typedef struct utsname utsname, *Putsname;

struct utsname {
    char sysname[65];
    char nodename[65];
    char release[65];
    char version[65];
    char machine[65];
    char domainname[65];
};

typedef struct sembuf sembuf, *Psembuf;

struct sembuf {
    ushort sem_num;
    short sem_op;
    short sem_flg;
};

typedef struct _IO_FILE __FILE;

typedef struct _IO_FILE FILE;

typedef struct __locale_data __locale_data, *P__locale_data;

struct __locale_data {
};

typedef struct __locale_struct __locale_struct, *P__locale_struct;

struct __locale_struct {
    struct __locale_data *__locales[13];
    ushort *__ctype_b;
    int *__ctype_tolower;
    int *__ctype_toupper;
    char *__names[13];
};

typedef struct __locale_struct *__locale_t;

typedef long __ssize_t;

typedef __ssize_t ssize_t;

typedef int __pid_t;

typedef int __key_t;

typedef __key_t key_t;

typedef int __clockid_t;

typedef uint __useconds_t;

typedef uint __id_t;

typedef __id_t id_t;

typedef long __suseconds_t;

typedef long __clock_t;

typedef struct pollfd pollfd, *Ppollfd;

struct pollfd {
    int fd;
    short events;
    short revents;
};

typedef ulong nfds_t;

typedef struct evp_pkey_ctx_st evp_pkey_ctx_st, *Pevp_pkey_ctx_st;

struct evp_pkey_ctx_st {
};

typedef struct evp_pkey_ctx_st EVP_PKEY_CTX;

typedef struct dirent dirent, *Pdirent;

struct dirent {
    __ino_t d_ino;
    __off_t d_off;
    ushort d_reclen;
    uchar d_type;
    char d_name[256];
};

typedef struct dirent64 dirent64, *Pdirent64;

struct dirent64 {
    __ino64_t d_ino;
    __off64_t d_off;
    ushort d_reclen;
    uchar d_type;
    char d_name[256];
};

typedef struct __dirstream __dirstream, *P__dirstream;

typedef struct __dirstream DIR;

struct __dirstream {
};

typedef union pthread_mutex_t pthread_mutex_t, *Ppthread_mutex_t;

typedef struct __pthread_mutex_s __pthread_mutex_s, *P__pthread_mutex_s;

typedef struct __pthread_internal_list __pthread_internal_list, *P__pthread_internal_list;

typedef struct __pthread_internal_list __pthread_list_t;

struct __pthread_internal_list {
    struct __pthread_internal_list *__prev;
    struct __pthread_internal_list *__next;
};

struct __pthread_mutex_s {
    int __lock;
    uint __count;
    int __owner;
    uint __nusers;
    int __kind;
    int __spins;
    __pthread_list_t __list;
};

union pthread_mutex_t {
    struct __pthread_mutex_s __data;
    char __size[40];
    long __align;
};

typedef union pthread_condattr_t pthread_condattr_t, *Ppthread_condattr_t;

union pthread_condattr_t {
    char __size[4];
    int __align;
};

typedef union pthread_mutexattr_t pthread_mutexattr_t, *Ppthread_mutexattr_t;

union pthread_mutexattr_t {
    char __size[4];
    int __align;
};

typedef int pthread_once_t;

typedef union pthread_cond_t pthread_cond_t, *Ppthread_cond_t;

typedef struct _struct_16 _struct_16, *P_struct_16;

struct _struct_16 {
    int __lock;
    uint __futex;
    ulonglong __total_seq;
    ulonglong __wakeup_seq;
    ulonglong __woken_seq;
    void *__mutex;
    uint __nwaiters;
    uint __broadcast_seq;
};

union pthread_cond_t {
    struct _struct_16 __data;
    char __size[48];
    longlong __align;
};

typedef ulong pthread_t;

typedef uint pthread_key_t;

typedef union pthread_attr_t pthread_attr_t, *Ppthread_attr_t;

union pthread_attr_t {
    char __size[56];
    long __align;
};

typedef struct __mbstate_t __mbstate_t, *P__mbstate_t;

typedef union _union_27 _union_27, *P_union_27;

union _union_27 {
    uint __wch;
    char __wchb[4];
};

struct __mbstate_t {
    int __count;
    union _union_27 __value;
};

typedef struct __mbstate_t mbstate_t;

typedef union sigval sigval, *Psigval;

typedef union sigval sigval_t;

union sigval {
    int sival_int;
    void *sival_ptr;
};

typedef union _union_1441 _union_1441, *P_union_1441;

typedef struct _struct_1442 _struct_1442, *P_struct_1442;

typedef struct _struct_1443 _struct_1443, *P_struct_1443;

typedef struct _struct_1444 _struct_1444, *P_struct_1444;

typedef struct _struct_1445 _struct_1445, *P_struct_1445;

typedef struct _struct_1446 _struct_1446, *P_struct_1446;

typedef struct _struct_1447 _struct_1447, *P_struct_1447;

struct _struct_1445 {
    __pid_t si_pid;
    __uid_t si_uid;
    int si_status;
    __clock_t si_utime;
    __clock_t si_stime;
};

struct _struct_1444 {
    __pid_t si_pid;
    __uid_t si_uid;
    sigval_t si_sigval;
};

struct _struct_1443 {
    int si_tid;
    int si_overrun;
    sigval_t si_sigval;
};

struct _struct_1446 {
    void *si_addr;
};

struct _struct_1442 {
    __pid_t si_pid;
    __uid_t si_uid;
};

struct _struct_1447 {
    long si_band;
    int si_fd;
};

union _union_1441 {
    int _pad[28];
    struct _struct_1442 _kill;
    struct _struct_1443 _timer;
    struct _struct_1444 _rt;
    struct _struct_1445 _sigchld;
    struct _struct_1446 _sigfault;
    struct _struct_1447 _sigpoll;
};

typedef struct siginfo siginfo, *Psiginfo;

struct siginfo {
    int si_signo;
    int si_errno;
    int si_code;
    union _union_1441 _sifields;
};

typedef struct siginfo siginfo_t;

typedef struct _Rb_tree<std::string,std::pair<std::string_const,unsigned_int>,std::_Select1st<std::pair<std::string_const,unsigned_int>>,std::less<std::string>,std::allocator<std::pair<std::string_const,unsigned_int>>> _Rb_tree<std::string,std::pair<std::string_const,unsigned_int>,std::_Select1st<std::pair<std::string_const,unsigned_int>>,std::less<std::string>,std::allocator<std::pair<std::string_const,unsigned_int>>>, *P_Rb_tree<std::string,std::pair<std::string_const,unsigned_int>,std::_Select1st<std::pair<std::string_const,unsigned_int>>,std::less<std::string>,std::allocator<std::pair<std::string_const,unsigned_int>>>;

struct _Rb_tree<std::string,std::pair<std::string_const,unsigned_int>,std::_Select1st<std::pair<std::string_const,unsigned_int>>,std::less<std::string>,std::allocator<std::pair<std::string_const,unsigned_int>>> { // PlaceHolder Class Structure
};

typedef struct _Rb_tree<std::string,std::pair<std::string_const,vortex::CLighthouseInput*>,std::_Select1st<std::pair<std::string_const,vortex::CLighthouseInput*>>,std::less<std::string>,std::allocator<std::pair<std::string_const,vortex::CLighthouseInput*>>> _Rb_tree<std::string,std::pair<std::string_const,vortex::CLighthouseInput*>,std::_Select1st<std::pair<std::string_const,vortex::CLighthouseInput*>>,std::less<std::string>,std::allocator<std::pair<std::string_const,vortex::CLighthouseInput*>>>, *P_Rb_tree<std::string,std::pair<std::string_const,vortex::CLighthouseInput*>,std::_Select1st<std::pair<std::string_const,vortex::CLighthouseInput*>>,std::less<std::string>,std::allocator<std::pair<std::string_const,vortex::CLighthouseInput*>>>;

struct _Rb_tree<std::string,std::pair<std::string_const,vortex::CLighthouseInput*>,std::_Select1st<std::pair<std::string_const,vortex::CLighthouseInput*>>,std::less<std::string>,std::allocator<std::pair<std::string_const,vortex::CLighthouseInput*>>> { // PlaceHolder Class Structure
};

typedef struct _Rb_tree<std::string,std::string,std::_Identity<std::string>,std::less<std::string>,std::allocator<std::string>> _Rb_tree<std::string,std::string,std::_Identity<std::string>,std::less<std::string>,std::allocator<std::string>>, *P_Rb_tree<std::string,std::string,std::_Identity<std::string>,std::less<std::string>,std::allocator<std::string>>;

struct _Rb_tree<std::string,std::string,std::_Identity<std::string>,std::less<std::string>,std::allocator<std::string>> { // PlaceHolder Class Structure
};

typedef struct function<bool()> function<bool()>, *Pfunction<bool()>;

struct function<bool()> { // PlaceHolder Class Structure
};

typedef struct _Rb_tree<std::string,std::pair<std::string_const,std::shared_ptr<std::vector<unsigned_char,std::allocator<unsigned_char>>>>,std::_Select1st<std::pair<std::string_const,std::shared_ptr<std::vector<unsigned_char,std::allocator<unsigned_char>>>>>,std::less<std::string>,std::allocator<std::pair<std::string_const,std::shared_ptr<std::vector<unsigned_char,std::allocator<unsigned_char>>>>>> _Rb_tree<std::string,std::pair<std::string_const,std::shared_ptr<std::vector<unsigned_char,std::allocator<unsigned_char>>>>,std::_Select1st<std::pair<std::string_const,std::shared_ptr<std::vector<unsigned_char,std::allocator<unsigned_char>>>>>,std::less<std::string>,std::allocator<std::pair<std::string_const,std::shared_ptr<std::vector<unsigned_char,std::allocator<unsigned_char>>>>>>, *P_Rb_tree<std::string,std::pair<std::string_const,std::shared_ptr<std::vector<unsigned_char,std::allocator<unsigned_char>>>>,std::_Select1st<std::pair<std::string_const,std::shared_ptr<std::vector<unsigned_char,std::allocator<unsigned_char>>>>>,std::less<std::string>,std::allocator<std::pair<std::string_const,std::shared_ptr<std::vector<unsigned_char,std::allocator<unsigned_char>>>>>>;

struct _Rb_tree<std::string,std::pair<std::string_const,std::shared_ptr<std::vector<unsigned_char,std::allocator<unsigned_char>>>>,std::_Select1st<std::pair<std::string_const,std::shared_ptr<std::vector<unsigned_char,std::allocator<unsigned_char>>>>>,std::less<std::string>,std::allocator<std::pair<std::string_const,std::shared_ptr<std::vector<unsigned_char,std::allocator<unsigned_char>>>>>> { // PlaceHolder Class Structure
};

typedef struct vector<vortex::CLighthouseUsbThread::lighthouse_t,std::allocator<vortex::CLighthouseUsbThread::lighthouse_t>> vector<vortex::CLighthouseUsbThread::lighthouse_t,std::allocator<vortex::CLighthouseUsbThread::lighthouse_t>>, *Pvector<vortex::CLighthouseUsbThread::lighthouse_t,std::allocator<vortex::CLighthouseUsbThread::lighthouse_t>>;

struct vector<vortex::CLighthouseUsbThread::lighthouse_t,std::allocator<vortex::CLighthouseUsbThread::lighthouse_t>> { // PlaceHolder Class Structure
};

typedef struct vector<CLogCallback*,std::allocator<CLogCallback*>> vector<CLogCallback*,std::allocator<CLogCallback*>>, *Pvector<CLogCallback*,std::allocator<CLogCallback*>>;

struct vector<CLogCallback*,std::allocator<CLogCallback*>> { // PlaceHolder Class Structure
};

typedef struct vector<std::pair<unsigned_int,bool>,std::allocator<std::pair<unsigned_int,bool>>> vector<std::pair<unsigned_int,bool>,std::allocator<std::pair<unsigned_int,bool>>>, *Pvector<std::pair<unsigned_int,bool>,std::allocator<std::pair<unsigned_int,bool>>>;

struct vector<std::pair<unsigned_int,bool>,std::allocator<std::pair<unsigned_int,bool>>> { // PlaceHolder Class Structure
};

typedef struct vector<char,std::allocator<char>> vector<char,std::allocator<char>>, *Pvector<char,std::allocator<char>>;

struct vector<char,std::allocator<char>> { // PlaceHolder Class Structure
};

typedef struct vector<hid_device_*,std::allocator<hid_device_*>> vector<hid_device_*,std::allocator<hid_device_*>>, *Pvector<hid_device_*,std::allocator<hid_device_*>>;

struct vector<hid_device_*,std::allocator<hid_device_*>> { // PlaceHolder Class Structure
};

typedef struct istreambuf_iterator<wchar_t,std::char_traits<wchar_t>> istreambuf_iterator<wchar_t,std::char_traits<wchar_t>>, *Pistreambuf_iterator<wchar_t,std::char_traits<wchar_t>>;

struct istreambuf_iterator<wchar_t,std::char_traits<wchar_t>> { // PlaceHolder Class Structure
};

typedef struct vector<CWirelessDecoder::SobData_s,std::allocator<CWirelessDecoder::SobData_s>> vector<CWirelessDecoder::SobData_s,std::allocator<CWirelessDecoder::SobData_s>>, *Pvector<CWirelessDecoder::SobData_s,std::allocator<CWirelessDecoder::SobData_s>>;

struct vector<CWirelessDecoder::SobData_s,std::allocator<CWirelessDecoder::SobData_s>> { // PlaceHolder Class Structure
};

typedef struct _Sp_counted_base<(_Lock_policy)2> _Sp_counted_base<(_Lock_policy)2>, *P_Sp_counted_base<(_Lock_policy)2>;

struct _Sp_counted_base<(_Lock_policy)2> { // PlaceHolder Class Structure
};

typedef struct _Rb_tree<std::tuple<unsigned_short,unsigned_short,std::wstring>,std::pair<std::tuple<unsigned_short,unsigned_short,std::wstring>const,int>,std::_Select1st<std::pair<std::tuple<unsigned_short,unsigned_short,std::wstring>const,int>>,std::less<std::tuple<unsigned_short,unsigned_short,std::wstring>>,std::allocator<std::pair<std::tuple<unsigned_short,unsigned_short,std::wstring>const,int>>> _Rb_tree<std::tuple<unsigned_short,unsigned_short,std::wstring>,std::pair<std::tuple<unsigned_short,unsigned_short,std::wstring>const,int>,std::_Select1st<std::pair<std::tuple<unsigned_short,unsigned_short,std::wstring>const,int>>,std::less<std::tuple<unsigned_short,unsigned_short,std::wstring>>,std::allocator<std::pair<std::tuple<unsigned_short,unsigned_short,std::wstring>const,int>>>, *P_Rb_tree<std::tuple<unsigned_short,unsigned_short,std::wstring>,std::pair<std::tuple<unsigned_short,unsigned_short,std::wstring>const,int>,std::_Select1st<std::pair<std::tuple<unsigned_short,unsigned_short,std::wstring>const,int>>,std::less<std::tuple<unsigned_short,unsigned_short,std::wstring>>,std::allocator<std::pair<std::tuple<unsigned_short,unsigned_short,std::wstring>const,int>>>;

struct _Rb_tree<std::tuple<unsigned_short,unsigned_short,std::wstring>,std::pair<std::tuple<unsigned_short,unsigned_short,std::wstring>const,int>,std::_Select1st<std::pair<std::tuple<unsigned_short,unsigned_short,std::wstring>const,int>>,std::less<std::tuple<unsigned_short,unsigned_short,std::wstring>>,std::allocator<std::pair<std::tuple<unsigned_short,unsigned_short,std::wstring>const,int>>> { // PlaceHolder Class Structure
};

typedef struct __facet_shims __facet_shims, *P__facet_shims;

struct __facet_shims { // PlaceHolder Class Structure
};

typedef struct vector<CAssertCallback*,std::allocator<CAssertCallback*>> vector<CAssertCallback*,std::allocator<CAssertCallback*>>, *Pvector<CAssertCallback*,std::allocator<CAssertCallback*>>;

struct vector<CAssertCallback*,std::allocator<CAssertCallback*>> { // PlaceHolder Class Structure
};

typedef struct random_device random_device, *Prandom_device;

struct random_device { // PlaceHolder Class Structure
};

typedef struct istreambuf_iterator<char,std::char_traits<char>> istreambuf_iterator<char,std::char_traits<char>>, *Pistreambuf_iterator<char,std::char_traits<char>>;

struct istreambuf_iterator<char,std::char_traits<char>> { // PlaceHolder Class Structure
};

typedef struct deque<CWirelessDecoder::SensorHit_s,std::allocator<CWirelessDecoder::SensorHit_s>> deque<CWirelessDecoder::SensorHit_s,std::allocator<CWirelessDecoder::SensorHit_s>>, *Pdeque<CWirelessDecoder::SensorHit_s,std::allocator<CWirelessDecoder::SensorHit_s>>;

struct deque<CWirelessDecoder::SensorHit_s,std::allocator<CWirelessDecoder::SensorHit_s>> { // PlaceHolder Class Structure
};

typedef struct vector<std::Catalog_info*,std::allocator<std::Catalog_info*>> vector<std::Catalog_info*,std::allocator<std::Catalog_info*>>, *Pvector<std::Catalog_info*,std::allocator<std::Catalog_info*>>;

struct vector<std::Catalog_info*,std::allocator<std::Catalog_info*>> { // PlaceHolder Class Structure
};

typedef struct vector<WirelessDongleFirmwareUpdater::Block,std::allocator<WirelessDongleFirmwareUpdater::Block>> vector<WirelessDongleFirmwareUpdater::Block,std::allocator<WirelessDongleFirmwareUpdater::Block>>, *Pvector<WirelessDongleFirmwareUpdater::Block,std::allocator<WirelessDongleFirmwareUpdater::Block>>;

struct vector<WirelessDongleFirmwareUpdater::Block,std::allocator<WirelessDongleFirmwareUpdater::Block>> { // PlaceHolder Class Structure
};

typedef struct vector<FirmwareImage_t*,std::allocator<FirmwareImage_t*>> vector<FirmwareImage_t*,std::allocator<FirmwareImage_t*>>, *Pvector<FirmwareImage_t*,std::allocator<FirmwareImage_t*>>;

struct vector<FirmwareImage_t*,std::allocator<FirmwareImage_t*>> { // PlaceHolder Class Structure
};

typedef struct _Rep _Rep, *P_Rep;

struct _Rep { // PlaceHolder Class Structure
};

typedef void *__gnuc_va_list;

typedef struct timezone timezone, *Ptimezone;

struct timezone {
    int tz_minuteswest;
    int tz_dsttime;
};

typedef __time_t time_t;

typedef __clockid_t clockid_t;

typedef struct timeval timeval, *Ptimeval;

struct timeval {
    __time_t tv_sec;
    __suseconds_t tv_usec;
};

typedef struct timezone *__timezone_ptr_t;

typedef struct tm tm, *Ptm;

struct tm {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
    long tm_gmtoff;
    char *tm_zone;
};

typedef union _union_1457 _union_1457, *P_union_1457;

typedef void (*__sighandler_t)(int);

union _union_1457 {
    __sighandler_t sa_handler;
    void (*sa_sigaction)(int, siginfo_t *, void *);
};

typedef struct sigaction sigaction, *Psigaction;

typedef struct __sigset_t __sigset_t, *P__sigset_t;

struct __sigset_t {
    ulong __val[16];
};

struct sigaction {
    union _union_1457 __sigaction_handler;
    struct __sigset_t sa_mask;
    int sa_flags;
    void (*sa_restorer)(void);
};

typedef uint wint_t;

typedef struct cpu_set_t cpu_set_t, *Pcpu_set_t;

typedef ulong __cpu_mask;

struct cpu_set_t {
    __cpu_mask __bits[16];
};

typedef struct sched_param sched_param, *Psched_param;

struct sched_param {
    int __sched_priority;
};

typedef struct iovec iovec, *Piovec;

struct iovec {
    void *iov_base;
    size_t iov_len;
};

typedef void *iconv_t;

typedef struct DeviceInterfaceV3 DeviceInterfaceV3, *PDeviceInterfaceV3;

struct DeviceInterfaceV3 { // PlaceHolder Structure
};

typedef struct hid_device_info hid_device_info, *Phid_device_info;

struct hid_device_info { // PlaceHolder Structure
};

typedef struct stdio_sync_filebuf stdio_sync_filebuf, *Pstdio_sync_filebuf;

struct stdio_sync_filebuf { // PlaceHolder Structure
};

typedef struct ControllerAttribute ControllerAttribute, *PControllerAttribute;

struct ControllerAttribute { // PlaceHolder Structure
};

typedef struct recursive_init_error recursive_init_error, *Precursive_init_error;

struct recursive_init_error { // PlaceHolder Structure
};

typedef struct FpgaFirmwareUpdater FpgaFirmwareUpdater, *PFpgaFirmwareUpdater;

struct FpgaFirmwareUpdater { // PlaceHolder Structure
};

typedef struct WatchmanV3FirmwareUpdater WatchmanV3FirmwareUpdater, *PWatchmanV3FirmwareUpdater;

struct WatchmanV3FirmwareUpdater { // PlaceHolder Structure
};

typedef struct VRCDeviceInterface VRCDeviceInterface, *PVRCDeviceInterface;

struct VRCDeviceInterface { // PlaceHolder Structure
};

typedef dword device_string_id;

typedef dword watchmanv3UpdateMode_t;

typedef struct CThreadFullMutex CThreadFullMutex, *PCThreadFullMutex;

struct CThreadFullMutex { // PlaceHolder Structure
};

typedef struct _Unwind_Context _Unwind_Context, *P_Unwind_Context;

struct _Unwind_Context { // PlaceHolder Structure
};

typedef struct WirelessDongleFirmwareUpdater WirelessDongleFirmwareUpdater, *PWirelessDongleFirmwareUpdater;

struct WirelessDongleFirmwareUpdater { // PlaceHolder Structure
};

typedef struct VRCDevice VRCDevice, *PVRCDevice;

struct VRCDevice { // PlaceHolder Structure
};

typedef struct CStopwatch CStopwatch, *PCStopwatch;

struct CStopwatch { // PlaceHolder Structure
};

typedef struct MsgGetDongleDeviceInfo MsgGetDongleDeviceInfo, *PMsgGetDongleDeviceInfo;

struct MsgGetDongleDeviceInfo { // PlaceHolder Structure
};

typedef struct FirmwareUpdateStatus FirmwareUpdateStatus, *PFirmwareUpdateStatus;

struct FirmwareUpdateStatus { // PlaceHolder Structure
};

typedef struct FirmwareAttributes FirmwareAttributes, *PFirmwareAttributes;

struct FirmwareAttributes { // PlaceHolder Structure
};

typedef struct WirelessDongleDevice WirelessDongleDevice, *PWirelessDongleDevice;

struct WirelessDongleDevice { // PlaceHolder Structure
};

typedef struct CAssertCallback CAssertCallback, *PCAssertCallback;

struct CAssertCallback { // PlaceHolder Structure
};

typedef struct CThreadSyncObject CThreadSyncObject, *PCThreadSyncObject;

struct CThreadSyncObject { // PlaceHolder Structure
};

typedef struct CThreadEvent CThreadEvent, *PCThreadEvent;

struct CThreadEvent { // PlaceHolder Structure
};

typedef struct UserDataImageBuilder UserDataImageBuilder, *PUserDataImageBuilder;

struct UserDataImageBuilder { // PlaceHolder Structure
};

typedef struct ValveControllerStatePacketK2_t ValveControllerStatePacketK2_t, *PValveControllerStatePacketK2_t;

struct ValveControllerStatePacketK2_t { // PlaceHolder Structure
};

typedef struct _finddata_t _finddata_t, *P_finddata_t;

struct _finddata_t { // PlaceHolder Structure
};

typedef struct WatchmanV1DeviceInterface WatchmanV1DeviceInterface, *PWatchmanV1DeviceInterface;

struct WatchmanV1DeviceInterface { // PlaceHolder Structure
};

typedef struct WirelessDeviceInterface WirelessDeviceInterface, *PWirelessDeviceInterface;

struct WirelessDeviceInterface { // PlaceHolder Structure
};

typedef struct signed signed, *Psigned;

struct signed { // PlaceHolder Structure
};

typedef struct WatchmanV1FirmwareUpdaterViaDongle WatchmanV1FirmwareUpdaterViaDongle, *PWatchmanV1FirmwareUpdaterViaDongle;

struct WatchmanV1FirmwareUpdaterViaDongle { // PlaceHolder Structure
};

typedef struct PrimaryDevice PrimaryDevice, *PPrimaryDevice;

struct PrimaryDevice { // PlaceHolder Structure
};

typedef struct ValveControllerStatePacketV2_t ValveControllerStatePacketV2_t, *PValveControllerStatePacketV2_t;

struct ValveControllerStatePacketV2_t { // PlaceHolder Structure
};

typedef struct z_stream_s z_stream_s, *Pz_stream_s;

struct z_stream_s { // PlaceHolder Structure
};

typedef struct FeatureReportMsg FeatureReportMsg, *PFeatureReportMsg;

struct FeatureReportMsg { // PlaceHolder Structure
};

typedef struct IFirmwareUpdater IFirmwareUpdater, *PIFirmwareUpdater;

struct IFirmwareUpdater { // PlaceHolder Structure
};

typedef struct hid_device_ hid_device_, *Phid_device_;

struct hid_device_ { // PlaceHolder Structure
};

typedef struct CLogCallback CLogCallback, *PCLogCallback;

struct CLogCallback { // PlaceHolder Structure
};

typedef struct FuelGaugeFirmwareUpdater FuelGaugeFirmwareUpdater, *PFuelGaugeFirmwareUpdater;

struct FuelGaugeFirmwareUpdater { // PlaceHolder Structure
};

typedef struct WatchmanV1DeviceInterfaceViaDongle WatchmanV1DeviceInterfaceViaDongle, *PWatchmanV1DeviceInterfaceViaDongle;

struct WatchmanV1DeviceInterfaceViaDongle { // PlaceHolder Structure
};

typedef struct WatchmanV3DeviceInterface WatchmanV3DeviceInterface, *PWatchmanV3DeviceInterface;

struct WatchmanV3DeviceInterface { // PlaceHolder Structure
};

typedef struct FirmwareImage_t FirmwareImage_t, *PFirmwareImage_t;

struct FirmwareImage_t { // PlaceHolder Structure
};

typedef dword ELogLevel;

typedef struct _Unwind_Exception _Unwind_Exception, *P_Unwind_Exception;

struct _Unwind_Exception { // PlaceHolder Structure
};

typedef struct SteamControllerStatusEvent_t SteamControllerStatusEvent_t, *PSteamControllerStatusEvent_t;

struct SteamControllerStatusEvent_t { // PlaceHolder Structure
};

typedef struct CThreadMutex CThreadMutex, *PCThreadMutex;

struct CThreadMutex { // PlaceHolder Structure
};

typedef struct NEOVRCDevice NEOVRCDevice, *PNEOVRCDevice;

struct NEOVRCDevice { // PlaceHolder Structure
};

typedef struct __scoped_lock __scoped_lock, *P__scoped_lock;

struct __scoped_lock { // PlaceHolder Structure
};

typedef struct unsigned_char unsigned_char, *Punsigned_char;

struct unsigned_char { // PlaceHolder Structure
};

typedef struct lsda_header_info lsda_header_info, *Plsda_header_info;

struct lsda_header_info { // PlaceHolder Structure
};

typedef struct stdio_filebuf<char,std::char_traits<char>> stdio_filebuf<char,std::char_traits<char>>, *Pstdio_filebuf<char,std::char_traits<char>>;

struct stdio_filebuf<char,std::char_traits<char>> { // PlaceHolder Structure
};

typedef struct WirelessDevice WirelessDevice, *PWirelessDevice;

struct WirelessDevice { // PlaceHolder Structure
};

typedef struct CThreadSemaphore CThreadSemaphore, *PCThreadSemaphore;

struct CThreadSemaphore { // PlaceHolder Structure
};

typedef struct WirelessDongleDeviceInterface WirelessDongleDeviceInterface, *PWirelessDongleDeviceInterface;

struct WirelessDongleDeviceInterface { // PlaceHolder Structure
};

typedef dword firmware_update_target_t;

typedef struct ValveControllerStatePacket_t ValveControllerStatePacket_t, *PValveControllerStatePacket_t;

struct ValveControllerStatePacket_t { // PlaceHolder Structure
};

typedef struct CWirelessDecoder CWirelessDecoder, *PCWirelessDecoder;

struct CWirelessDecoder { // PlaceHolder Structure
};

typedef struct WatchmanDevice WatchmanDevice, *PWatchmanDevice;

struct WatchmanDevice { // PlaceHolder Structure
};

typedef struct DeviceInterfaceV1 DeviceInterfaceV1, *PDeviceInterfaceV1;

struct DeviceInterfaceV1 { // PlaceHolder Structure
};

typedef struct SteamControllerDongleDevice SteamControllerDongleDevice, *PSteamControllerDongleDevice;

struct SteamControllerDongleDevice { // PlaceHolder Structure
};

typedef struct CVrcDecodeTagged CVrcDecodeTagged, *PCVrcDecodeTagged;

struct CVrcDecodeTagged { // PlaceHolder Structure
};

typedef struct WatchmanV3FirmwareUpdaterViaDongle WatchmanV3FirmwareUpdaterViaDongle, *PWatchmanV3FirmwareUpdaterViaDongle;

struct WatchmanV3FirmwareUpdaterViaDongle { // PlaceHolder Structure
};

typedef struct WatchmanV3MatchedDevice_t WatchmanV3MatchedDevice_t, *PWatchmanV3MatchedDevice_t;

struct WatchmanV3MatchedDevice_t { // PlaceHolder Structure
};

typedef struct CThreadLocalBase CThreadLocalBase, *PCThreadLocalBase;

struct CThreadLocalBase { // PlaceHolder Structure
};

typedef struct WatchmanV1FirmwareUpdater WatchmanV1FirmwareUpdater, *PWatchmanV1FirmwareUpdater;

struct WatchmanV1FirmwareUpdater { // PlaceHolder Structure
};

typedef dword int128;

typedef struct FirmwareFooter FirmwareFooter, *PFirmwareFooter;

struct FirmwareFooter { // PlaceHolder Structure
};

typedef struct __concurrence_lock_error __concurrence_lock_error, *P__concurrence_lock_error;

struct __concurrence_lock_error { // PlaceHolder Structure
};

typedef struct CFirmwareImageList CFirmwareImageList, *PCFirmwareImageList;

struct CFirmwareImageList { // PlaceHolder Structure
};

typedef dword _Unwind_Reason_Code;

typedef struct stdio_sync_filebuf<wchar_t,std::char_traits<wchar_t>> stdio_sync_filebuf<wchar_t,std::char_traits<wchar_t>>, *Pstdio_sync_filebuf<wchar_t,std::char_traits<wchar_t>>;

struct stdio_sync_filebuf<wchar_t,std::char_traits<wchar_t>> { // PlaceHolder Structure
};

typedef struct CSDLDynamic CSDLDynamic, *PCSDLDynamic;

struct CSDLDynamic { // PlaceHolder Structure
};

typedef struct stdio_sync_filebuf<char,std::char_traits<char>> stdio_sync_filebuf<char,std::char_traits<char>>, *Pstdio_sync_filebuf<char,std::char_traits<char>>;

struct stdio_sync_filebuf<char,std::char_traits<char>> { // PlaceHolder Structure
};

typedef struct CThread CThread, *PCThread;

struct CThread { // PlaceHolder Structure
};

typedef struct stdio_filebuf stdio_filebuf, *Pstdio_filebuf;

struct stdio_filebuf { // PlaceHolder Structure
};

typedef struct NEOVRCDeviceInterface NEOVRCDeviceInterface, *PNEOVRCDeviceInterface;

struct NEOVRCDeviceInterface { // PlaceHolder Structure
};

typedef struct VRCFirmwareUpdater VRCFirmwareUpdater, *PVRCFirmwareUpdater;

struct VRCFirmwareUpdater { // PlaceHolder Structure
};

typedef struct CThreadLocalPtr<CThread> CThreadLocalPtr<CThread>, *PCThreadLocalPtr<CThread>;

struct CThreadLocalPtr<CThread> { // PlaceHolder Structure
};

typedef struct DeviceInterface DeviceInterface, *PDeviceInterface;

struct DeviceInterface { // PlaceHolder Structure
};

typedef dword __normal_iterator;

typedef struct RadioFirmwareUpdater RadioFirmwareUpdater, *PRadioFirmwareUpdater;

struct RadioFirmwareUpdater { // PlaceHolder Structure
};

typedef struct __va_list_tag __va_list_tag, *P__va_list_tag;

struct __va_list_tag { // PlaceHolder Structure
};

typedef struct FirmwareUpdater FirmwareUpdater, *PFirmwareUpdater;

struct FirmwareUpdater { // PlaceHolder Structure
};

typedef struct CWirelessDecoderWv2 CWirelessDecoderWv2, *PCWirelessDecoderWv2;

struct CWirelessDecoderWv2 { // PlaceHolder Structure
};

typedef struct ValveHmdState_t ValveHmdState_t, *PValveHmdState_t;

struct ValveHmdState_t { // PlaceHolder Structure
};

typedef dword device_t;

typedef struct stdio_filebuf<wchar_t,std::char_traits<wchar_t>> stdio_filebuf<wchar_t,std::char_traits<wchar_t>>, *Pstdio_filebuf<wchar_t,std::char_traits<wchar_t>>;

struct stdio_filebuf<wchar_t,std::char_traits<wchar_t>> { // PlaceHolder Structure
};

typedef struct WatchmanDongleDevice WatchmanDongleDevice, *PWatchmanDongleDevice;

struct WatchmanDongleDevice { // PlaceHolder Structure
};

typedef struct NEOVRCFirmwareUpdater NEOVRCFirmwareUpdater, *PNEOVRCFirmwareUpdater;

struct NEOVRCFirmwareUpdater { // PlaceHolder Structure
};

typedef struct CDirIterator CDirIterator, *PCDirIterator;

struct CDirIterator { // PlaceHolder Structure
};

typedef struct UserDataFirmwareUpdater UserDataFirmwareUpdater, *PUserDataFirmwareUpdater;

struct UserDataFirmwareUpdater { // PlaceHolder Structure
};

typedef struct CThreadLocalInt<long> CThreadLocalInt<long>, *PCThreadLocalInt<long>;

struct CThreadLocalInt<long> { // PlaceHolder Structure
};

typedef dword FeatureReportMessageIDs;

typedef struct WatchmanV3DeviceInterfaceViaDongle WatchmanV3DeviceInterfaceViaDongle, *PWatchmanV3DeviceInterfaceViaDongle;

struct WatchmanV3DeviceInterfaceViaDongle { // PlaceHolder Structure
};

typedef struct __concurrence_unlock_error __concurrence_unlock_error, *P__concurrence_unlock_error;

struct __concurrence_unlock_error { // PlaceHolder Structure
};

typedef struct Block Block, *PBlock;

struct Block { // PlaceHolder Structure
};

typedef struct __function_type_info __function_type_info, *P__function_type_info;

struct __function_type_info { // PlaceHolder Structure
};

typedef struct __forced_unwind __forced_unwind, *P__forced_unwind;

struct __forced_unwind { // PlaceHolder Structure
};

typedef struct __pointer_type_info __pointer_type_info, *P__pointer_type_info;

struct __pointer_type_info { // PlaceHolder Structure
};

typedef struct __class_type_info __class_type_info, *P__class_type_info;

struct __class_type_info { // PlaceHolder Structure
};

typedef struct __foreign_exception __foreign_exception, *P__foreign_exception;

struct __foreign_exception { // PlaceHolder Structure
};

typedef struct __si_class_type_info __si_class_type_info, *P__si_class_type_info;

struct __si_class_type_info { // PlaceHolder Structure
};

typedef struct __fundamental_type_info __fundamental_type_info, *P__fundamental_type_info;

struct __fundamental_type_info { // PlaceHolder Structure
};

typedef struct __vmi_class_type_info __vmi_class_type_info, *P__vmi_class_type_info;

struct __vmi_class_type_info { // PlaceHolder Structure
};

typedef struct __pbase_type_info __pbase_type_info, *P__pbase_type_info;

struct __pbase_type_info { // PlaceHolder Structure
};

typedef struct __pointer_to_member_type_info __pointer_to_member_type_info, *P__pointer_to_member_type_info;

struct __pointer_to_member_type_info { // PlaceHolder Structure
};

typedef struct __dyncast_result __dyncast_result, *P__dyncast_result;

struct __dyncast_result { // PlaceHolder Structure
};

typedef dword __sub_kind;

typedef struct __upcast_result __upcast_result, *P__upcast_result;

struct __upcast_result { // PlaceHolder Structure
};

typedef struct wistringstream wistringstream, *Pwistringstream;

struct wistringstream { // PlaceHolder Structure
};

typedef struct exception exception, *Pexception;

struct exception { // PlaceHolder Structure
};

typedef dword _Rb_tree_iterator;

typedef struct wios wios, *Pwios;

struct wios { // PlaceHolder Structure
};

typedef dword istreambuf_iterator;

typedef struct __codecvt_utf16_base<char32_t> __codecvt_utf16_base<char32_t>, *P__codecvt_utf16_base<char32_t>;

struct __codecvt_utf16_base<char32_t> { // PlaceHolder Structure
};

typedef struct ostream ostream, *Postream;

struct ostream { // PlaceHolder Structure
};

typedef struct ios ios, *Pios;

struct ios { // PlaceHolder Structure
};

typedef struct wostream wostream, *Pwostream;

struct wostream { // PlaceHolder Structure
};

typedef dword random_access_iterator_tag;

typedef struct num_put num_put, *Pnum_put;

struct num_put { // PlaceHolder Structure
};

typedef struct _Ios_Iostate _Ios_Iostate, *P_Ios_Iostate;

struct _Ios_Iostate { // PlaceHolder Structure
};

typedef dword fpos;

typedef struct time_get_byname<char,std::istreambuf_iterator<char,std::char_traits<char>>> time_get_byname<char,std::istreambuf_iterator<char,std::char_traits<char>>>, *Ptime_get_byname<char,std::istreambuf_iterator<char,std::char_traits<char>>>;

struct time_get_byname<char,std::istreambuf_iterator<char,std::char_traits<char>>> { // PlaceHolder Structure
};

typedef struct moneypunct<char,true> moneypunct<char,true>, *Pmoneypunct<char,true>;

struct moneypunct<char,true> { // PlaceHolder Structure
};

typedef struct iostream iostream, *Piostream;

struct iostream { // PlaceHolder Structure
};

typedef struct istream istream, *Pistream;

struct istream { // PlaceHolder Structure
};

typedef struct numpunct<char> numpunct<char>, *Pnumpunct<char>;

struct numpunct<char> { // PlaceHolder Structure
};

typedef struct ostringstream ostringstream, *Postringstream;

struct ostringstream { // PlaceHolder Structure
};

typedef struct numpunct numpunct, *Pnumpunct;

struct numpunct { // PlaceHolder Structure
};

typedef struct collate_byname<wchar_t> collate_byname<wchar_t>, *Pcollate_byname<wchar_t>;

struct collate_byname<wchar_t> { // PlaceHolder Structure
};

typedef struct wofstream wofstream, *Pwofstream;

struct wofstream { // PlaceHolder Structure
};

typedef struct nothrow_t nothrow_t, *Pnothrow_t;

struct nothrow_t { // PlaceHolder Structure
};

typedef dword _Setw;

typedef struct ctype<char> ctype<char>, *Pctype<char>;

struct ctype<char> { // PlaceHolder Structure
};

typedef struct __timepunct<char> __timepunct<char>, *P__timepunct<char>;

struct __timepunct<char> { // PlaceHolder Structure
};

typedef struct wistream wistream, *Pwistream;

struct wistream { // PlaceHolder Structure
};

typedef struct num_get<char,std::istreambuf_iterator<char,std::char_traits<char>>> num_get<char,std::istreambuf_iterator<char,std::char_traits<char>>>, *Pnum_get<char,std::istreambuf_iterator<char,std::char_traits<char>>>;

struct num_get<char,std::istreambuf_iterator<char,std::char_traits<char>>> { // PlaceHolder Structure
};

typedef struct bad_cast bad_cast, *Pbad_cast;

struct bad_cast { // PlaceHolder Structure
};

typedef struct wiostream wiostream, *Pwiostream;

struct wiostream { // PlaceHolder Structure
};

typedef struct time_get_byname<wchar_t,std::istreambuf_iterator<wchar_t,std::char_traits<wchar_t>>> time_get_byname<wchar_t,std::istreambuf_iterator<wchar_t,std::char_traits<wchar_t>>>, *Ptime_get_byname<wchar_t,std::istreambuf_iterator<wchar_t,std::char_traits<wchar_t>>>;

struct time_get_byname<wchar_t,std::istreambuf_iterator<wchar_t,std::char_traits<wchar_t>>> { // PlaceHolder Structure
};

typedef struct __sso_string __sso_string, *P__sso_string;

struct __sso_string { // PlaceHolder Structure
};

typedef struct codecvt<char,char,__mbstate_t> codecvt<char,char,__mbstate_t>, *Pcodecvt<char,char,__mbstate_t>;

struct codecvt<char,char,__mbstate_t> { // PlaceHolder Structure
};

typedef struct __codecvt_utf16_base<wchar_t> __codecvt_utf16_base<wchar_t>, *P__codecvt_utf16_base<wchar_t>;

struct __codecvt_utf16_base<wchar_t> { // PlaceHolder Structure
};

typedef struct vector vector, *Pvector;

struct vector { // PlaceHolder Structure
};

typedef struct stringstream stringstream, *Pstringstream;

struct stringstream { // PlaceHolder Structure
};

typedef struct __numpunct_cache __numpunct_cache, *P__numpunct_cache;

struct __numpunct_cache { // PlaceHolder Structure
};

typedef struct bad_alloc bad_alloc, *Pbad_alloc;

struct bad_alloc { // PlaceHolder Structure
};

typedef struct type_info type_info, *Ptype_info;

struct type_info { // PlaceHolder Structure
};

typedef struct moneypunct moneypunct, *Pmoneypunct;

struct moneypunct { // PlaceHolder Structure
};

typedef dword _Manager_operation;

typedef struct stringbuf stringbuf, *Pstringbuf;

struct stringbuf { // PlaceHolder Structure
};

typedef struct messages<char> messages<char>, *Pmessages<char>;

struct messages<char> { // PlaceHolder Structure
};

typedef struct vector<WatchmanV3MatchedDevice_t,std::allocator<WatchmanV3MatchedDevice_t>> vector<WatchmanV3MatchedDevice_t,std::allocator<WatchmanV3MatchedDevice_t>>, *Pvector<WatchmanV3MatchedDevice_t,std::allocator<WatchmanV3MatchedDevice_t>>;

struct vector<WatchmanV3MatchedDevice_t,std::allocator<WatchmanV3MatchedDevice_t>> { // PlaceHolder Structure
};

typedef struct collate<char> collate<char>, *Pcollate<char>;

struct collate<char> { // PlaceHolder Structure
};

typedef struct Catalog_info Catalog_info, *PCatalog_info;

struct Catalog_info { // PlaceHolder Structure
};

typedef struct __timepunct_cache<char> __timepunct_cache<char>, *P__timepunct_cache<char>;

struct __timepunct_cache<char> { // PlaceHolder Structure
};

typedef struct __codecvt_utf8_base<char32_t> __codecvt_utf8_base<char32_t>, *P__codecvt_utf8_base<char32_t>;

struct __codecvt_utf8_base<char32_t> { // PlaceHolder Structure
};

typedef struct __timepunct_cache __timepunct_cache, *P__timepunct_cache;

struct __timepunct_cache { // PlaceHolder Structure
};

typedef struct filebuf filebuf, *Pfilebuf;

struct filebuf { // PlaceHolder Structure
};

typedef struct __timepunct_cache<wchar_t> __timepunct_cache<wchar_t>, *P__timepunct_cache<wchar_t>;

struct __timepunct_cache<wchar_t> { // PlaceHolder Structure
};

typedef struct ctype_byname<char> ctype_byname<char>, *Pctype_byname<char>;

struct ctype_byname<char> { // PlaceHolder Structure
};

typedef struct __iosfail_type_info __iosfail_type_info, *P__iosfail_type_info;

struct __iosfail_type_info { // PlaceHolder Structure
};

typedef dword forward_iterator_tag;

typedef struct logic_error logic_error, *Plogic_error;

struct logic_error { // PlaceHolder Structure
};

typedef struct bad_array_new_length bad_array_new_length, *Pbad_array_new_length;

struct bad_array_new_length { // PlaceHolder Structure
};

typedef struct out_of_range out_of_range, *Pout_of_range;

struct out_of_range { // PlaceHolder Structure
};

typedef struct time_put<char,std::ostreambuf_iterator<char,std::char_traits<char>>> time_put<char,std::ostreambuf_iterator<char,std::char_traits<char>>>, *Ptime_put<char,std::ostreambuf_iterator<char,std::char_traits<char>>>;

struct time_put<char,std::ostreambuf_iterator<char,std::char_traits<char>>> { // PlaceHolder Structure
};

typedef struct _Rb_tree_node _Rb_tree_node, *P_Rb_tree_node;

struct _Rb_tree_node { // PlaceHolder Structure
};

typedef dword ostreambuf_iterator;

typedef struct error_condition error_condition, *Perror_condition;

struct error_condition { // PlaceHolder Structure
};

typedef struct istringstream istringstream, *Pistringstream;

struct istringstream { // PlaceHolder Structure
};

typedef struct wstring wstring, *Pwstring;

struct wstring { // PlaceHolder Structure
};

typedef dword _Resetiosflags;

typedef struct wstringstream wstringstream, *Pwstringstream;

struct wstringstream { // PlaceHolder Structure
};

typedef struct __numpunct_cache<wchar_t> __numpunct_cache<wchar_t>, *P__numpunct_cache<wchar_t>;

struct __numpunct_cache<wchar_t> { // PlaceHolder Structure
};

typedef struct collate collate, *Pcollate;

struct collate { // PlaceHolder Structure
};

typedef struct num_get num_get, *Pnum_get;

struct num_get { // PlaceHolder Structure
};

typedef struct time_get<char,std::istreambuf_iterator<char,std::char_traits<char>>> time_get<char,std::istreambuf_iterator<char,std::char_traits<char>>>, *Ptime_get<char,std::istreambuf_iterator<char,std::char_traits<char>>>;

struct time_get<char,std::istreambuf_iterator<char,std::char_traits<char>>> { // PlaceHolder Structure
};

typedef struct time_put time_put, *Ptime_put;

struct time_put { // PlaceHolder Structure
};

typedef struct locale locale, *Plocale;

struct locale { // PlaceHolder Structure
};

typedef struct money_get money_get, *Pmoney_get;

struct money_get { // PlaceHolder Structure
};

typedef struct _Rb_tree_node_base _Rb_tree_node_base, *P_Rb_tree_node_base;

struct _Rb_tree_node_base { // PlaceHolder Structure
};

typedef struct error_code error_code, *Perror_code;

struct error_code { // PlaceHolder Structure
};

typedef struct __basic_file<char> __basic_file<char>, *P__basic_file<char>;

struct __basic_file<char> { // PlaceHolder Structure
};

typedef struct __cow_string __cow_string, *P__cow_string;

struct __cow_string { // PlaceHolder Structure
};

typedef struct wostringstream wostringstream, *Pwostringstream;

struct wostringstream { // PlaceHolder Structure
};

typedef struct __ios_failure __ios_failure, *P__ios_failure;

struct __ios_failure { // PlaceHolder Structure
};

typedef dword pair;


// WARNING! conflicting data type names: /Demangler/std/string - /string

typedef struct vector<unsigned_char,std::allocator<unsigned_char>> vector<unsigned_char,std::allocator<unsigned_char>>, *Pvector<unsigned_char,std::allocator<unsigned_char>>;

struct vector<unsigned_char,std::allocator<unsigned_char>> { // PlaceHolder Structure
};

typedef struct __codecvt_utf8_utf16_base<char32_t> __codecvt_utf8_utf16_base<char32_t>, *P__codecvt_utf8_utf16_base<char32_t>;

struct __codecvt_utf8_utf16_base<char32_t> { // PlaceHolder Structure
};

typedef dword _Setbase;

typedef struct wstringbuf wstringbuf, *Pwstringbuf;

struct wstringbuf { // PlaceHolder Structure
};

typedef dword codecvt_mode;

typedef struct underflow_error underflow_error, *Punderflow_error;

struct underflow_error { // PlaceHolder Structure
};

typedef struct __moneypunct_cache __moneypunct_cache, *P__moneypunct_cache;

struct __moneypunct_cache { // PlaceHolder Structure
};

typedef struct time_get time_get, *Ptime_get;

struct time_get { // PlaceHolder Structure
};

typedef struct __use_cache<std::__numpunct_cache<char>> __use_cache<std::__numpunct_cache<char>>, *P__use_cache<std::__numpunct_cache<char>>;

struct __use_cache<std::__numpunct_cache<char>> { // PlaceHolder Structure
};

typedef struct length_error length_error, *Plength_error;

struct length_error { // PlaceHolder Structure
};

typedef struct money_put money_put, *Pmoney_put;

struct money_put { // PlaceHolder Structure
};

typedef struct codecvt<wchar_t,char,__mbstate_t> codecvt<wchar_t,char,__mbstate_t>, *Pcodecvt<wchar_t,char,__mbstate_t>;

struct codecvt<wchar_t,char,__mbstate_t> { // PlaceHolder Structure
};

typedef dword _Setprecision;

typedef dword _Ios_Seekdir;

typedef struct __moneypunct_cache<char,true> __moneypunct_cache<char,true>, *P__moneypunct_cache<char,true>;

struct __moneypunct_cache<char,true> { // PlaceHolder Structure
};

typedef struct wfilebuf wfilebuf, *Pwfilebuf;

struct wfilebuf { // PlaceHolder Structure
};

typedef struct money_get<char,std::istreambuf_iterator<char,std::char_traits<char>>> money_get<char,std::istreambuf_iterator<char,std::char_traits<char>>>, *Pmoney_get<char,std::istreambuf_iterator<char,std::char_traits<char>>>;

struct money_get<char,std::istreambuf_iterator<char,std::char_traits<char>>> { // PlaceHolder Structure
};

typedef struct moneypunct<wchar_t,false> moneypunct<wchar_t,false>, *Pmoneypunct<wchar_t,false>;

struct moneypunct<wchar_t,false> { // PlaceHolder Structure
};

typedef struct time_put<wchar_t,std::ostreambuf_iterator<wchar_t,std::char_traits<wchar_t>>> time_put<wchar_t,std::ostreambuf_iterator<wchar_t,std::char_traits<wchar_t>>>, *Ptime_put<wchar_t,std::ostreambuf_iterator<wchar_t,std::char_traits<wchar_t>>>;

struct time_put<wchar_t,std::ostreambuf_iterator<wchar_t,std::char_traits<wchar_t>>> { // PlaceHolder Structure
};

typedef struct pair<std::string,std::string> pair<std::string,std::string>, *Ppair<std::string,std::string>;

struct pair<std::string,std::string> { // PlaceHolder Structure
};

typedef struct codecvt_byname<wchar_t,char,__mbstate_t> codecvt_byname<wchar_t,char,__mbstate_t>, *Pcodecvt_byname<wchar_t,char,__mbstate_t>;

struct codecvt_byname<wchar_t,char,__mbstate_t> { // PlaceHolder Structure
};

typedef struct ctype_byname<wchar_t> ctype_byname<wchar_t>, *Pctype_byname<wchar_t>;

struct ctype_byname<wchar_t> { // PlaceHolder Structure
};

typedef struct wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111ul,(std::codecvt_mode)0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>> wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111ul,(std::codecvt_mode)0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>, *Pwstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111ul,(std::codecvt_mode)0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>;

struct wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111ul,(std::codecvt_mode)0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>> { // PlaceHolder Structure
};

typedef struct money_get<wchar_t,std::istreambuf_iterator<wchar_t,std::char_traits<wchar_t>>> money_get<wchar_t,std::istreambuf_iterator<wchar_t,std::char_traits<wchar_t>>>, *Pmoney_get<wchar_t,std::istreambuf_iterator<wchar_t,std::char_traits<wchar_t>>>;

struct money_get<wchar_t,std::istreambuf_iterator<wchar_t,std::char_traits<wchar_t>>> { // PlaceHolder Structure
};

typedef struct codecvt<char16_t,char8_t,__mbstate_t> codecvt<char16_t,char8_t,__mbstate_t>, *Pcodecvt<char16_t,char8_t,__mbstate_t>;

struct codecvt<char16_t,char8_t,__mbstate_t> { // PlaceHolder Structure
};

typedef struct bad_function_call bad_function_call, *Pbad_function_call;

struct bad_function_call { // PlaceHolder Structure
};

typedef dword _Ios_Fmtflags;

typedef struct invalid_argument invalid_argument, *Pinvalid_argument;

struct invalid_argument { // PlaceHolder Structure
};

typedef struct numpunct<wchar_t> numpunct<wchar_t>, *Pnumpunct<wchar_t>;

struct numpunct<wchar_t> { // PlaceHolder Structure
};

typedef struct moneypunct_byname<wchar_t,false> moneypunct_byname<wchar_t,false>, *Pmoneypunct_byname<wchar_t,false>;

struct moneypunct_byname<wchar_t,false> { // PlaceHolder Structure
};

typedef struct wstreambuf wstreambuf, *Pwstreambuf;

struct wstreambuf { // PlaceHolder Structure
};

typedef struct bad_typeid bad_typeid, *Pbad_typeid;

struct bad_typeid { // PlaceHolder Structure
};

typedef struct streambuf streambuf, *Pstreambuf;

struct streambuf { // PlaceHolder Structure
};

typedef struct allocator allocator, *Pallocator;

struct allocator { // PlaceHolder Structure
};

typedef struct numpunct_byname<char> numpunct_byname<char>, *Pnumpunct_byname<char>;

struct numpunct_byname<char> { // PlaceHolder Structure
};

typedef struct time_put_byname<wchar_t,std::ostreambuf_iterator<wchar_t,std::char_traits<wchar_t>>> time_put_byname<wchar_t,std::ostreambuf_iterator<wchar_t,std::char_traits<wchar_t>>>, *Ptime_put_byname<wchar_t,std::ostreambuf_iterator<wchar_t,std::char_traits<wchar_t>>>;

struct time_put_byname<wchar_t,std::ostreambuf_iterator<wchar_t,std::char_traits<wchar_t>>> { // PlaceHolder Structure
};

typedef struct ios_base ios_base, *Pios_base;

struct ios_base { // PlaceHolder Structure
};

typedef struct map<std::string,unsigned_int,std::less<std::string>,std::allocator<std::pair<std::string_const,unsigned_int>>> map<std::string,unsigned_int,std::less<std::string>,std::allocator<std::pair<std::string_const,unsigned_int>>>, *Pmap<std::string,unsigned_int,std::less<std::string>,std::allocator<std::pair<std::string_const,unsigned_int>>>;

struct map<std::string,unsigned_int,std::less<std::string>,std::allocator<std::pair<std::string_const,unsigned_int>>> { // PlaceHolder Structure
};

typedef struct moneypunct_byname<wchar_t,true> moneypunct_byname<wchar_t,true>, *Pmoneypunct_byname<wchar_t,true>;

struct moneypunct_byname<wchar_t,true> { // PlaceHolder Structure
};

typedef struct __moneypunct_cache<wchar_t,true> __moneypunct_cache<wchar_t,true>, *P__moneypunct_cache<wchar_t,true>;

struct __moneypunct_cache<wchar_t,true> { // PlaceHolder Structure
};

typedef struct time_get<wchar_t,std::istreambuf_iterator<wchar_t,std::char_traits<wchar_t>>> time_get<wchar_t,std::istreambuf_iterator<wchar_t,std::char_traits<wchar_t>>>, *Ptime_get<wchar_t,std::istreambuf_iterator<wchar_t,std::char_traits<wchar_t>>>;

struct time_get<wchar_t,std::istreambuf_iterator<wchar_t,std::char_traits<wchar_t>>> { // PlaceHolder Structure
};

typedef struct ofstream ofstream, *Pofstream;

struct ofstream { // PlaceHolder Structure
};

typedef struct domain_error domain_error, *Pdomain_error;

struct domain_error { // PlaceHolder Structure
};

typedef struct wifstream wifstream, *Pwifstream;

struct wifstream { // PlaceHolder Structure
};

typedef struct ifstream ifstream, *Pifstream;

struct ifstream { // PlaceHolder Structure
};

typedef struct num_put<char,std::ostreambuf_iterator<char,std::char_traits<char>>> num_put<char,std::ostreambuf_iterator<char,std::char_traits<char>>>, *Pnum_put<char,std::ostreambuf_iterator<char,std::char_traits<char>>>;

struct num_put<char,std::ostreambuf_iterator<char,std::char_traits<char>>> { // PlaceHolder Structure
};

typedef struct codecvt<char32_t,char8_t,__mbstate_t> codecvt<char32_t,char8_t,__mbstate_t>, *Pcodecvt<char32_t,char8_t,__mbstate_t>;

struct codecvt<char32_t,char8_t,__mbstate_t> { // PlaceHolder Structure
};

typedef struct wfstream wfstream, *Pwfstream;

struct wfstream { // PlaceHolder Structure
};

typedef struct messages messages, *Pmessages;

struct messages { // PlaceHolder Structure
};

typedef struct Catalogs Catalogs, *PCatalogs;

struct Catalogs { // PlaceHolder Structure
};

typedef struct vector<float,std::allocator<float>> vector<float,std::allocator<float>>, *Pvector<float,std::allocator<float>>;

struct vector<float,std::allocator<float>> { // PlaceHolder Structure
};

typedef struct codecvt<char16_t,char,__mbstate_t> codecvt<char16_t,char,__mbstate_t>, *Pcodecvt<char16_t,char,__mbstate_t>;

struct codecvt<char16_t,char,__mbstate_t> { // PlaceHolder Structure
};

typedef struct ctype ctype, *Pctype;

struct ctype { // PlaceHolder Structure
};

typedef struct collate<wchar_t> collate<wchar_t>, *Pcollate<wchar_t>;

struct collate<wchar_t> { // PlaceHolder Structure
};

typedef struct tuple tuple, *Ptuple;

struct tuple { // PlaceHolder Structure
};

typedef struct _Sp_counted_ptr<std::vector<unsigned_char,std::allocator<unsigned_char>>*,(_Lock_policy)2> _Sp_counted_ptr<std::vector<unsigned_char,std::allocator<unsigned_char>>*,(_Lock_policy)2>, *P_Sp_counted_ptr<std::vector<unsigned_char,std::allocator<unsigned_char>>*,(_Lock_policy)2>;

struct _Sp_counted_ptr<std::vector<unsigned_char,std::allocator<unsigned_char>>*,(_Lock_policy)2> { // PlaceHolder Structure
};

typedef struct codecvt codecvt, *Pcodecvt;

struct codecvt { // PlaceHolder Structure
};

typedef dword _Setiosflags;

typedef struct codecvt_utf8_utf16<wchar_t,1114111ul,(std::codecvt_mode)0> codecvt_utf8_utf16<wchar_t,1114111ul,(std::codecvt_mode)0>, *Pcodecvt_utf8_utf16<wchar_t,1114111ul,(std::codecvt_mode)0>;

struct codecvt_utf8_utf16<wchar_t,1114111ul,(std::codecvt_mode)0> { // PlaceHolder Structure
};

typedef struct moneypunct<wchar_t,true> moneypunct<wchar_t,true>, *Pmoneypunct<wchar_t,true>;

struct moneypunct<wchar_t,true> { // PlaceHolder Structure
};

typedef dword _Ios_Openmode;

typedef struct runtime_error runtime_error, *Pruntime_error;

struct runtime_error { // PlaceHolder Structure
};

typedef struct _Any_data _Any_data, *P_Any_data;

struct _Any_data { // PlaceHolder Structure
};

typedef struct system_error system_error, *Psystem_error;

struct system_error { // PlaceHolder Structure
};

typedef struct money_put<char,std::ostreambuf_iterator<char,std::char_traits<char>>> money_put<char,std::ostreambuf_iterator<char,std::char_traits<char>>>, *Pmoney_put<char,std::ostreambuf_iterator<char,std::char_traits<char>>>;

struct money_put<char,std::ostreambuf_iterator<char,std::char_traits<char>>> { // PlaceHolder Structure
};

typedef struct __codecvt_utf8_utf16_base<char16_t> __codecvt_utf8_utf16_base<char16_t>, *P__codecvt_utf8_utf16_base<char16_t>;

struct __codecvt_utf8_utf16_base<char16_t> { // PlaceHolder Structure
};

typedef struct vector<vortex::CLighthouseIMUThread::ImuCallbackEntry_t,std::allocator<vortex::CLighthouseIMUThread::ImuCallbackEntry_t>> vector<vortex::CLighthouseIMUThread::ImuCallbackEntry_t,std::allocator<vortex::CLighthouseIMUThread::ImuCallbackEntry_t>>, *Pvector<vortex::CLighthouseIMUThread::ImuCallbackEntry_t,std::allocator<vortex::CLighthouseIMUThread::ImuCallbackEntry_t>>;

struct vector<vortex::CLighthouseIMUThread::ImuCallbackEntry_t,std::allocator<vortex::CLighthouseIMUThread::ImuCallbackEntry_t>> { // PlaceHolder Structure
};

typedef struct vector<std::string,std::allocator<std::string>> vector<std::string,std::allocator<std::string>>, *Pvector<std::string,std::allocator<std::string>>;

struct vector<std::string,std::allocator<std::string>> { // PlaceHolder Structure
};

typedef struct num_get<wchar_t,std::istreambuf_iterator<wchar_t,std::char_traits<wchar_t>>> num_get<wchar_t,std::istreambuf_iterator<wchar_t,std::char_traits<wchar_t>>>, *Pnum_get<wchar_t,std::istreambuf_iterator<wchar_t,std::char_traits<wchar_t>>>;

struct num_get<wchar_t,std::istreambuf_iterator<wchar_t,std::char_traits<wchar_t>>> { // PlaceHolder Structure
};

typedef struct __moneypunct_cache<wchar_t,false> __moneypunct_cache<wchar_t,false>, *P__moneypunct_cache<wchar_t,false>;

struct __moneypunct_cache<wchar_t,false> { // PlaceHolder Structure
};

typedef struct codecvt_utf8<char32_t,1114111ul,(std::codecvt_mode)0> codecvt_utf8<char32_t,1114111ul,(std::codecvt_mode)0>, *Pcodecvt_utf8<char32_t,1114111ul,(std::codecvt_mode)0>;

struct codecvt_utf8<char32_t,1114111ul,(std::codecvt_mode)0> { // PlaceHolder Structure
};

typedef struct collate_byname<char> collate_byname<char>, *Pcollate_byname<char>;

struct collate_byname<char> { // PlaceHolder Structure
};

typedef struct piecewise_construct_t piecewise_construct_t, *Ppiecewise_construct_t;

struct piecewise_construct_t { // PlaceHolder Structure
};

typedef struct map<std::string,vortex::CLighthouseInput*,std::less<std::string>,std::allocator<std::pair<std::string_const,vortex::CLighthouseInput*>>> map<std::string,vortex::CLighthouseInput*,std::less<std::string>,std::allocator<std::pair<std::string_const,vortex::CLighthouseInput*>>>, *Pmap<std::string,vortex::CLighthouseInput*,std::less<std::string>,std::allocator<std::pair<std::string_const,vortex::CLighthouseInput*>>>;

struct map<std::string,vortex::CLighthouseInput*,std::less<std::string>,std::allocator<std::pair<std::string_const,vortex::CLighthouseInput*>>> { // PlaceHolder Structure
};

typedef struct __timepunct __timepunct, *P__timepunct;

struct __timepunct { // PlaceHolder Structure
};

typedef dword function;

typedef struct vector<std::pair<std::string,std::string>,std::allocator<std::pair<std::string,std::string>>> vector<std::pair<std::string,std::string>,std::allocator<std::pair<std::string,std::string>>>, *Pvector<std::pair<std::string,std::string>,std::allocator<std::pair<std::string,std::string>>>;

struct vector<std::pair<std::string,std::string>,std::allocator<std::pair<std::string,std::string>>> { // PlaceHolder Structure
};

typedef dword integral_constant;

typedef struct overflow_error overflow_error, *Poverflow_error;

struct overflow_error { // PlaceHolder Structure
};

typedef struct numpunct_byname<wchar_t> numpunct_byname<wchar_t>, *Pnumpunct_byname<wchar_t>;

struct numpunct_byname<wchar_t> { // PlaceHolder Structure
};

typedef dword _Setfill;

typedef struct __codecvt_utf16_base<char16_t> __codecvt_utf16_base<char16_t>, *P__codecvt_utf16_base<char16_t>;

struct __codecvt_utf16_base<char16_t> { // PlaceHolder Structure
};

typedef struct __codecvt_utf8_utf16_base<wchar_t> __codecvt_utf8_utf16_base<wchar_t>, *P__codecvt_utf8_utf16_base<wchar_t>;

struct __codecvt_utf8_utf16_base<wchar_t> { // PlaceHolder Structure
};

typedef struct codecvt_byname<char,char,__mbstate_t> codecvt_byname<char,char,__mbstate_t>, *Pcodecvt_byname<char,char,__mbstate_t>;

struct codecvt_byname<char,char,__mbstate_t> { // PlaceHolder Structure
};

typedef struct vector<vortex::Edid_t,std::allocator<vortex::Edid_t>> vector<vortex::Edid_t,std::allocator<vortex::Edid_t>>, *Pvector<vortex::Edid_t,std::allocator<vortex::Edid_t>>;

struct vector<vortex::Edid_t,std::allocator<vortex::Edid_t>> { // PlaceHolder Structure
};

typedef struct money_put<wchar_t,std::ostreambuf_iterator<wchar_t,std::char_traits<wchar_t>>> money_put<wchar_t,std::ostreambuf_iterator<wchar_t,std::char_traits<wchar_t>>>, *Pmoney_put<wchar_t,std::ostreambuf_iterator<wchar_t,std::char_traits<wchar_t>>>;

struct money_put<wchar_t,std::ostreambuf_iterator<wchar_t,std::char_traits<wchar_t>>> { // PlaceHolder Structure
};

typedef struct messages<wchar_t> messages<wchar_t>, *Pmessages<wchar_t>;

struct messages<wchar_t> { // PlaceHolder Structure
};

typedef struct num_put<wchar_t,std::ostreambuf_iterator<wchar_t,std::char_traits<wchar_t>>> num_put<wchar_t,std::ostreambuf_iterator<wchar_t,std::char_traits<wchar_t>>>, *Pnum_put<wchar_t,std::ostreambuf_iterator<wchar_t,std::char_traits<wchar_t>>>;

struct num_put<wchar_t,std::ostreambuf_iterator<wchar_t,std::char_traits<wchar_t>>> { // PlaceHolder Structure
};

typedef dword initializer_list;

typedef struct bad_exception bad_exception, *Pbad_exception;

struct bad_exception { // PlaceHolder Structure
};

typedef struct __numpunct_cache<char> __numpunct_cache<char>, *P__numpunct_cache<char>;

struct __numpunct_cache<char> { // PlaceHolder Structure
};

typedef struct messages_byname<wchar_t> messages_byname<wchar_t>, *Pmessages_byname<wchar_t>;

struct messages_byname<wchar_t> { // PlaceHolder Structure
};

typedef struct codecvt<char32_t,char,__mbstate_t> codecvt<char32_t,char,__mbstate_t>, *Pcodecvt<char32_t,char,__mbstate_t>;

struct codecvt<char32_t,char,__mbstate_t> { // PlaceHolder Structure
};

typedef struct __moneypunct_cache<char,false> __moneypunct_cache<char,false>, *P__moneypunct_cache<char,false>;

struct __moneypunct_cache<char,false> { // PlaceHolder Structure
};

typedef struct __timepunct<wchar_t> __timepunct<wchar_t>, *P__timepunct<wchar_t>;

struct __timepunct<wchar_t> { // PlaceHolder Structure
};

typedef struct ctype<wchar_t> ctype<wchar_t>, *Pctype<wchar_t>;

struct ctype<wchar_t> { // PlaceHolder Structure
};

typedef struct messages_byname<char> messages_byname<char>, *Pmessages_byname<char>;

struct messages_byname<char> { // PlaceHolder Structure
};

typedef struct __use_cache<std::__numpunct_cache<wchar_t>> __use_cache<std::__numpunct_cache<wchar_t>>, *P__use_cache<std::__numpunct_cache<wchar_t>>;

struct __use_cache<std::__numpunct_cache<wchar_t>> { // PlaceHolder Structure
};

typedef struct range_error range_error, *Prange_error;

struct range_error { // PlaceHolder Structure
};

typedef struct moneypunct<char,false> moneypunct<char,false>, *Pmoneypunct<char,false>;

struct moneypunct<char,false> { // PlaceHolder Structure
};

typedef struct __codecvt_utf8_base<char16_t> __codecvt_utf8_base<char16_t>, *P__codecvt_utf8_base<char16_t>;

struct __codecvt_utf8_base<char16_t> { // PlaceHolder Structure
};

typedef struct moneypunct_byname<char,true> moneypunct_byname<char,true>, *Pmoneypunct_byname<char,true>;

struct moneypunct_byname<char,true> { // PlaceHolder Structure
};

typedef dword _Rb_tree_const_iterator;

typedef struct vector<vortex::CHidDevice::HidDeviceIdentifier,std::allocator<vortex::CHidDevice::HidDeviceIdentifier>> vector<vortex::CHidDevice::HidDeviceIdentifier,std::allocator<vortex::CHidDevice::HidDeviceIdentifier>>, *Pvector<vortex::CHidDevice::HidDeviceIdentifier,std::allocator<vortex::CHidDevice::HidDeviceIdentifier>>;

struct vector<vortex::CHidDevice::HidDeviceIdentifier,std::allocator<vortex::CHidDevice::HidDeviceIdentifier>> { // PlaceHolder Structure
};

typedef struct fstream fstream, *Pfstream;

struct fstream { // PlaceHolder Structure
};

typedef struct moneypunct_byname<char,false> moneypunct_byname<char,false>, *Pmoneypunct_byname<char,false>;

struct moneypunct_byname<char,false> { // PlaceHolder Structure
};

typedef struct time_put_byname<char,std::ostreambuf_iterator<char,std::char_traits<char>>> time_put_byname<char,std::ostreambuf_iterator<char,std::char_traits<char>>>, *Ptime_put_byname<char,std::ostreambuf_iterator<char,std::char_traits<char>>>;

struct time_put_byname<char,std::ostreambuf_iterator<char,std::char_traits<char>>> { // PlaceHolder Structure
};

typedef struct __codecvt_utf8_base<wchar_t> __codecvt_utf8_base<wchar_t>, *P__codecvt_utf8_base<wchar_t>;

struct __codecvt_utf8_base<wchar_t> { // PlaceHolder Structure
};

typedef struct range range, *Prange;

struct range { // PlaceHolder Structure
};

typedef dword surrogates;

typedef dword dateorder;

typedef struct _Alloc_hider _Alloc_hider, *P_Alloc_hider;

struct _Alloc_hider { // PlaceHolder Structure
};

typedef struct sentry sentry, *Psentry;

struct sentry { // PlaceHolder Structure
};

typedef dword result;

typedef struct facet facet, *Pfacet;

struct facet { // PlaceHolder Structure
};

typedef struct _Impl _Impl, *P_Impl;

struct _Impl { // PlaceHolder Structure
};

typedef struct id id, *Pid;

struct id { // PlaceHolder Structure
};

typedef struct __xfer_bufptrs __xfer_bufptrs, *P__xfer_bufptrs;

struct __xfer_bufptrs { // PlaceHolder Structure
};

typedef struct __any_string __any_string, *P__any_string;

struct __any_string { // PlaceHolder Structure
};

typedef struct messages_shim<wchar_t> messages_shim<wchar_t>, *Pmessages_shim<wchar_t>;

struct messages_shim<wchar_t> { // PlaceHolder Structure
};

typedef struct money_put_shim<char> money_put_shim<char>, *Pmoney_put_shim<char>;

struct money_put_shim<char> { // PlaceHolder Structure
};

typedef struct collate_shim<char> collate_shim<char>, *Pcollate_shim<char>;

struct collate_shim<char> { // PlaceHolder Structure
};

typedef struct money_get_shim<wchar_t> money_get_shim<wchar_t>, *Pmoney_get_shim<wchar_t>;

struct money_get_shim<wchar_t> { // PlaceHolder Structure
};

typedef struct messages_shim<char> messages_shim<char>, *Pmessages_shim<char>;

struct messages_shim<char> { // PlaceHolder Structure
};

typedef struct numpunct_shim<char> numpunct_shim<char>, *Pnumpunct_shim<char>;

struct numpunct_shim<char> { // PlaceHolder Structure
};

typedef struct moneypunct_shim<char,false> moneypunct_shim<char,false>, *Pmoneypunct_shim<char,false>;

struct moneypunct_shim<char,false> { // PlaceHolder Structure
};

typedef struct numpunct_shim<wchar_t> numpunct_shim<wchar_t>, *Pnumpunct_shim<wchar_t>;

struct numpunct_shim<wchar_t> { // PlaceHolder Structure
};

typedef struct time_get_shim<wchar_t> time_get_shim<wchar_t>, *Ptime_get_shim<wchar_t>;

struct time_get_shim<wchar_t> { // PlaceHolder Structure
};

typedef struct moneypunct_shim<wchar_t,true> moneypunct_shim<wchar_t,true>, *Pmoneypunct_shim<wchar_t,true>;

struct moneypunct_shim<wchar_t,true> { // PlaceHolder Structure
};

typedef struct moneypunct_shim<wchar_t,false> moneypunct_shim<wchar_t,false>, *Pmoneypunct_shim<wchar_t,false>;

struct moneypunct_shim<wchar_t,false> { // PlaceHolder Structure
};

typedef struct money_get_shim<char> money_get_shim<char>, *Pmoney_get_shim<char>;

struct money_get_shim<char> { // PlaceHolder Structure
};

typedef struct time_get_shim<char> time_get_shim<char>, *Ptime_get_shim<char>;

struct time_get_shim<char> { // PlaceHolder Structure
};

typedef struct collate_shim<wchar_t> collate_shim<wchar_t>, *Pcollate_shim<wchar_t>;

struct collate_shim<wchar_t> { // PlaceHolder Structure
};

typedef struct money_put_shim<wchar_t> money_put_shim<wchar_t>, *Pmoney_put_shim<wchar_t>;

struct money_put_shim<wchar_t> { // PlaceHolder Structure
};

typedef struct moneypunct_shim<char,true> moneypunct_shim<char,true>, *Pmoneypunct_shim<char,true>;

struct moneypunct_shim<char,true> { // PlaceHolder Structure
};

typedef struct __close_sentry __close_sentry, *P__close_sentry;

struct __close_sentry { // PlaceHolder Structure
};

typedef struct Init Init, *PInit;

struct Init { // PlaceHolder Structure
};

typedef struct failure[abi:cxx11] failure[abi:cxx11], *Pfailure[abi:cxx11];

struct failure[abi:cxx11] { // PlaceHolder Structure
};

typedef dword event;

typedef struct failure failure, *Pfailure;

struct failure { // PlaceHolder Structure
};

typedef struct error_category error_category, *Perror_category;

struct error_category { // PlaceHolder Structure
};

typedef struct generic_error_category generic_error_category, *Pgeneric_error_category;

struct generic_error_category { // PlaceHolder Structure
};

typedef struct io_error_category io_error_category, *Pio_error_category;

struct io_error_category { // PlaceHolder Structure
};

typedef struct system_error_category system_error_category, *Psystem_error_category;

struct system_error_category { // PlaceHolder Structure
};

typedef struct _Watchman_WirelessReport_t _Watchman_WirelessReport_t, *P_Watchman_WirelessReport_t;

struct _Watchman_WirelessReport_t { // PlaceHolder Structure
};

typedef struct CVortexMutex CVortexMutex, *PCVortexMutex;

struct CVortexMutex { // PlaceHolder Structure
};

typedef struct CVortexConditionVariable CVortexConditionVariable, *PCVortexConditionVariable;

struct CVortexConditionVariable { // PlaceHolder Structure
};

typedef struct _Watchman_IMUReport_t _Watchman_IMUReport_t, *P_Watchman_IMUReport_t;

struct _Watchman_IMUReport_t { // PlaceHolder Structure
};

typedef struct CVortexMutexLock CVortexMutexLock, *PCVortexMutexLock;

struct CVortexMutexLock { // PlaceHolder Structure
};

typedef dword EPowerLevel;

typedef struct CVortexSemaphore CVortexSemaphore, *PCVortexSemaphore;

struct CVortexSemaphore { // PlaceHolder Structure
};

typedef struct _Watchman_OpticalReport_v4_t _Watchman_OpticalReport_v4_t, *P_Watchman_OpticalReport_v4_t;

struct _Watchman_OpticalReport_v4_t { // PlaceHolder Structure
};

typedef struct EdidInfoVec_t EdidInfoVec_t, *PEdidInfoVec_t;

struct EdidInfoVec_t { // PlaceHolder Structure
};

typedef struct Watchman_Feature_HMDStatus_t Watchman_Feature_HMDStatus_t, *PWatchman_Feature_HMDStatus_t;

struct Watchman_Feature_HMDStatus_t { // PlaceHolder Structure
};

typedef struct _Watchman_OpticalReport_v3b_t _Watchman_OpticalReport_v3b_t, *P_Watchman_OpticalReport_v3b_t;

struct _Watchman_OpticalReport_v3b_t { // PlaceHolder Structure
};

typedef struct CLighthouseOpticalThread CLighthouseOpticalThread, *PCLighthouseOpticalThread;

struct CLighthouseOpticalThread { // PlaceHolder Structure
};

typedef struct display_metrics_page0_v1_t display_metrics_page0_v1_t, *Pdisplay_metrics_page0_v1_t;

struct display_metrics_page0_v1_t { // PlaceHolder Structure
};

typedef struct CSysTimer CSysTimer, *PCSysTimer;

struct CSysTimer { // PlaceHolder Structure
};

typedef struct _Watchman_Wireless_Packet_t _Watchman_Wireless_Packet_t, *P_Watchman_Wireless_Packet_t;

struct _Watchman_Wireless_Packet_t { // PlaceHolder Structure
};

typedef struct display_metrics_page1_v1_t display_metrics_page1_v1_t, *Pdisplay_metrics_page1_v1_t;

struct display_metrics_page1_v1_t { // PlaceHolder Structure
};

typedef struct CVortexReadLock CVortexReadLock, *PCVortexReadLock;

struct CVortexReadLock { // PlaceHolder Structure
};

typedef dword ERadioMode;

typedef struct _Watchman_OpticalReport_v2_t _Watchman_OpticalReport_v2_t, *P_Watchman_OpticalReport_v2_t;

struct _Watchman_OpticalReport_v2_t { // PlaceHolder Structure
};

typedef struct _lighthouse_errors _lighthouse_errors, *P_lighthouse_errors;

struct _lighthouse_errors { // PlaceHolder Structure
};

typedef struct CVrControllerUsbThread CVrControllerUsbThread, *PCVrControllerUsbThread;

struct CVrControllerUsbThread { // PlaceHolder Structure
};

typedef struct panel_stats_t panel_stats_t, *Ppanel_stats_t;

struct panel_stats_t { // PlaceHolder Structure
};

typedef struct Edid_t Edid_t, *PEdid_t;

struct Edid_t { // PlaceHolder Structure
};

typedef struct CVortexWriteLock CVortexWriteLock, *PCVortexWriteLock;

struct CVortexWriteLock { // PlaceHolder Structure
};

typedef struct CHidDevice CHidDevice, *PCHidDevice;

struct CHidDevice { // PlaceHolder Structure
};

typedef struct CLighthouseUsbThread CLighthouseUsbThread, *PCLighthouseUsbThread;

struct CLighthouseUsbThread { // PlaceHolder Structure
};

typedef struct CLighthouseIMUThread CLighthouseIMUThread, *PCLighthouseIMUThread;

struct CLighthouseIMUThread { // PlaceHolder Structure
};

typedef struct qpd_cmd_schedule_t qpd_cmd_schedule_t, *Pqpd_cmd_schedule_t;

struct qpd_cmd_schedule_t { // PlaceHolder Structure
};

typedef struct _Watchman_IMUSample_t _Watchman_IMUSample_t, *P_Watchman_IMUSample_t;

struct _Watchman_IMUSample_t { // PlaceHolder Structure
};

typedef struct panel_column_correction_t panel_column_correction_t, *Ppanel_column_correction_t;

struct panel_column_correction_t { // PlaceHolder Structure
};

typedef struct _Watchman_OpticalReport_v3_t _Watchman_OpticalReport_v3_t, *P_Watchman_OpticalReport_v3_t;

struct _Watchman_OpticalReport_v3_t { // PlaceHolder Structure
};

typedef struct CVortexReadWriteLock CVortexReadWriteLock, *PCVortexReadWriteLock;

struct CVortexReadWriteLock { // PlaceHolder Structure
};

typedef struct _Watchman_OpticalReport_t _Watchman_OpticalReport_t, *P_Watchman_OpticalReport_t;

struct _Watchman_OpticalReport_t { // PlaceHolder Structure
};

typedef struct CLighthouseInput CLighthouseInput, *PCLighthouseInput;

struct CLighthouseInput { // PlaceHolder Structure
};

typedef struct _Watchman_Feature_IMUMode_t _Watchman_Feature_IMUMode_t, *P_Watchman_Feature_IMUMode_t;

struct _Watchman_Feature_IMUMode_t { // PlaceHolder Structure
};

typedef struct WatchmanOtgtResults_t WatchmanOtgtResults_t, *PWatchmanOtgtResults_t;

struct WatchmanOtgtResults_t { // PlaceHolder Structure
};

typedef struct Watchman_Feature_WatchmanStatus_t Watchman_Feature_WatchmanStatus_t, *PWatchman_Feature_WatchmanStatus_t;

struct Watchman_Feature_WatchmanStatus_t { // PlaceHolder Structure
};

typedef struct CLighthouseThreadBase CLighthouseThreadBase, *PCLighthouseThreadBase;

struct CLighthouseThreadBase { // PlaceHolder Structure
};

typedef struct CVortexThread CVortexThread, *PCVortexThread;

struct CVortexThread { // PlaceHolder Structure
};

typedef dword audio_stream_status_t;

typedef dword WatchmanRebootRequestType_t;

typedef dword EWatchmanWirelessProtocolVersion;

typedef dword FeatureID;

typedef struct CUsbRetryTimer CUsbRetryTimer, *PCUsbRetryTimer;

struct CUsbRetryTimer { // PlaceHolder Structure
};

typedef struct HidDeviceIdentifier HidDeviceIdentifier, *PHidDeviceIdentifier;

struct HidDeviceIdentifier { // PlaceHolder Structure
};

typedef dword LighthouseDeviceTypes;

typedef dword RequestType;

typedef struct lighthouse_t lighthouse_t, *Plighthouse_t;

struct lighthouse_t { // PlaceHolder Structure
};

typedef struct CTime CTime, *PCTime;

struct CTime { // PlaceHolder Structure
};

typedef struct CConnection CConnection, *PCConnection;

struct CConnection { // PlaceHolder Structure
};

typedef struct IAuxEventCallback IAuxEventCallback, *PIAuxEventCallback;

struct IAuxEventCallback { // PlaceHolder Structure
};

typedef struct ImuCallbackEntry_t ImuCallbackEntry_t, *PImuCallbackEntry_t;

struct ImuCallbackEntry_t { // PlaceHolder Structure
};

typedef struct IMonitorCallback IMonitorCallback, *PIMonitorCallback;

struct IMonitorCallback { // PlaceHolder Structure
};

typedef struct ICallback ICallback, *PICallback;

struct ICallback { // PlaceHolder Structure
};

typedef struct HmdMuteState_s HmdMuteState_s, *PHmdMuteState_s;

struct HmdMuteState_s { // PlaceHolder Structure
};

typedef struct IImuCallback IImuCallback, *PIImuCallback;

struct IImuCallback { // PlaceHolder Structure
};

typedef dword ESyncDetectMode;

typedef struct VideoConfig_t VideoConfig_t, *PVideoConfig_t;

struct VideoConfig_t { // PlaceHolder Structure
};

typedef dword ESensorSchedule;

typedef struct IVrcCallback IVrcCallback, *PIVrcCallback;

struct IVrcCallback { // PlaceHolder Structure
};

typedef dword Unhandled;

typedef struct SensorHit_s SensorHit_s, *PSensorHit_s;

struct SensorHit_s { // PlaceHolder Structure
};

typedef struct SobData_s SobData_s, *PSobData_s;

struct SobData_s { // PlaceHolder Structure
};

typedef dword _Iter_equal_to_iter;

typedef dword _Iter_less_iter;

typedef dword _Iter_pred;

typedef dword _Iter_equals_iter;

typedef dword _Iter_equals_val;

typedef enum Elf_ProgramHeaderType {
    PT_NULL=0,
    PT_LOAD=1,
    PT_DYNAMIC=2,
    PT_INTERP=3,
    PT_NOTE=4,
    PT_SHLIB=5,
    PT_PHDR=6,
    PT_TLS=7,
    PT_GNU_EH_FRAME=1685382480,
    PT_GNU_STACK=1685382481,
    PT_GNU_RELRO=1685382482
} Elf_ProgramHeaderType;

typedef struct Elf64_Dyn Elf64_Dyn, *PElf64_Dyn;

typedef enum Elf64_DynTag {
    DT_NULL=0,
    DT_NEEDED=1,
    DT_PLTRELSZ=2,
    DT_PLTGOT=3,
    DT_HASH=4,
    DT_STRTAB=5,
    DT_SYMTAB=6,
    DT_RELA=7,
    DT_RELASZ=8,
    DT_RELAENT=9,
    DT_STRSZ=10,
    DT_SYMENT=11,
    DT_INIT=12,
    DT_FINI=13,
    DT_SONAME=14,
    DT_RPATH=15,
    DT_SYMBOLIC=16,
    DT_REL=17,
    DT_RELSZ=18,
    DT_RELENT=19,
    DT_PLTREL=20,
    DT_DEBUG=21,
    DT_TEXTREL=22,
    DT_JMPREL=23,
    DT_BIND_NOW=24,
    DT_INIT_ARRAY=25,
    DT_FINI_ARRAY=26,
    DT_INIT_ARRAYSZ=27,
    DT_FINI_ARRAYSZ=28,
    DT_RUNPATH=29,
    DT_FLAGS=30,
    DT_PREINIT_ARRAY=32,
    DT_PREINIT_ARRAYSZ=33,
    DT_RELRSZ=35,
    DT_RELR=36,
    DT_RELRENT=37,
    DT_ANDROID_REL=1610612751,
    DT_ANDROID_RELSZ=1610612752,
    DT_ANDROID_RELA=1610612753,
    DT_ANDROID_RELASZ=1610612754,
    DT_ANDROID_RELR=1879040000,
    DT_ANDROID_RELRSZ=1879040001,
    DT_ANDROID_RELRENT=1879040003,
    DT_GNU_PRELINKED=1879047669,
    DT_GNU_CONFLICTSZ=1879047670,
    DT_GNU_LIBLISTSZ=1879047671,
    DT_CHECKSUM=1879047672,
    DT_PLTPADSZ=1879047673,
    DT_MOVEENT=1879047674,
    DT_MOVESZ=1879047675,
    DT_FEATURE_1=1879047676,
    DT_POSFLAG_1=1879047677,
    DT_SYMINSZ=1879047678,
    DT_SYMINENT=1879047679,
    DT_GNU_XHASH=1879047924,
    DT_GNU_HASH=1879047925,
    DT_TLSDESC_PLT=1879047926,
    DT_TLSDESC_GOT=1879047927,
    DT_GNU_CONFLICT=1879047928,
    DT_GNU_LIBLIST=1879047929,
    DT_CONFIG=1879047930,
    DT_DEPAUDIT=1879047931,
    DT_AUDIT=1879047932,
    DT_PLTPAD=1879047933,
    DT_MOVETAB=1879047934,
    DT_SYMINFO=1879047935,
    DT_VERSYM=1879048176,
    DT_RELACOUNT=1879048185,
    DT_RELCOUNT=1879048186,
    DT_FLAGS_1=1879048187,
    DT_VERDEF=1879048188,
    DT_VERDEFNUM=1879048189,
    DT_VERNEED=1879048190,
    DT_VERNEEDNUM=1879048191,
    DT_AUXILIARY=2147483645,
    DT_FILTER=2147483647
} Elf64_DynTag;

struct Elf64_Dyn {
    enum Elf64_DynTag d_tag;
    qword d_val;
};

typedef struct Elf64_Phdr Elf64_Phdr, *PElf64_Phdr;

struct Elf64_Phdr {
    enum Elf_ProgramHeaderType p_type;
    dword p_flags;
    qword p_offset;
    qword p_vaddr;
    qword p_paddr;
    qword p_filesz;
    qword p_memsz;
    qword p_align;
};

typedef struct Elf64_Shdr Elf64_Shdr, *PElf64_Shdr;

typedef enum Elf_SectionHeaderType {
    SHT_NULL=0,
    SHT_PROGBITS=1,
    SHT_SYMTAB=2,
    SHT_STRTAB=3,
    SHT_RELA=4,
    SHT_HASH=5,
    SHT_DYNAMIC=6,
    SHT_NOTE=7,
    SHT_NOBITS=8,
    SHT_REL=9,
    SHT_SHLIB=10,
    SHT_DYNSYM=11,
    SHT_INIT_ARRAY=14,
    SHT_FINI_ARRAY=15,
    SHT_PREINIT_ARRAY=16,
    SHT_GROUP=17,
    SHT_SYMTAB_SHNDX=18,
    SHT_ANDROID_REL=1610612737,
    SHT_ANDROID_RELA=1610612738,
    SHT_GNU_ATTRIBUTES=1879048181,
    SHT_GNU_HASH=1879048182,
    SHT_GNU_LIBLIST=1879048183,
    SHT_CHECKSUM=1879048184,
    SHT_SUNW_move=1879048186,
    SHT_SUNW_COMDAT=1879048187,
    SHT_SUNW_syminfo=1879048188,
    SHT_GNU_verdef=1879048189,
    SHT_GNU_verneed=1879048190,
    SHT_GNU_versym=1879048191
} Elf_SectionHeaderType;

struct Elf64_Shdr {
    dword sh_name;
    enum Elf_SectionHeaderType sh_type;
    qword sh_flags;
    qword sh_addr;
    qword sh_offset;
    qword sh_size;
    dword sh_link;
    dword sh_info;
    qword sh_addralign;
    qword sh_entsize;
};

typedef struct GnuBuildId GnuBuildId, *PGnuBuildId;

struct GnuBuildId {
    dword namesz; // Length of name field
    dword descsz; // Length of description field
    dword type; // Vendor specific type
    char name[4]; // Vendor name
    byte hash[20];
};

typedef struct Elf64_Ehdr Elf64_Ehdr, *PElf64_Ehdr;

struct Elf64_Ehdr {
    byte e_ident_magic_num;
    char e_ident_magic_str[3];
    byte e_ident_class;
    byte e_ident_data;
    byte e_ident_version;
    byte e_ident_osabi;
    byte e_ident_abiversion;
    byte e_ident_pad[7];
    word e_type;
    word e_machine;
    dword e_version;
    qword e_entry;
    qword e_phoff;
    qword e_shoff;
    dword e_flags;
    word e_ehsize;
    word e_phentsize;
    word e_phnum;
    word e_shentsize;
    word e_shnum;
    word e_shstrndx;
};

typedef struct Elf64_Rela Elf64_Rela, *PElf64_Rela;

struct Elf64_Rela {
    qword r_offset; // location to apply the relocation action
    qword r_info; // the symbol table index and the type of relocation
    qword r_addend; // a constant addend used to compute the relocatable field value
};

typedef struct GnuDebugLink_32 GnuDebugLink_32, *PGnuDebugLink_32;

struct GnuDebugLink_32 {
    char filename[32];
    dword crc;
};

typedef struct Elf64_Sym Elf64_Sym, *PElf64_Sym;

struct Elf64_Sym {
    dword st_name;
    byte st_info;
    byte st_other;
    word st_shndx;
    qword st_value;
    qword st_size;
};

typedef struct NoteAbiTag NoteAbiTag, *PNoteAbiTag;

struct NoteAbiTag {
    dword namesz; // Length of name field
    dword descsz; // Length of description field
    dword type; // Vendor specific type
    char name[4]; // Vendor name
    dword abiType; // 0 == Linux
    dword requiredKernelVersion[3]; // Major.minor.patch
};




int _init(EVP_PKEY_CTX *ctx);
void FUN_0011bd40(void);
void __cxa_finalize(void);
void __cxa_atexit(void);
void * memcpy(void *__dest,void *__src,size_t __n);
int printf(char *__format,...);
FILE * fopen(char *__filename,char *__modes);
int fseek(FILE *__stream,long __off,int __whence);
long ftell(FILE *__stream);
size_t fread(void *__ptr,size_t __size,size_t __n,FILE *__stream);
int fclose(FILE *__stream);
size_t fwrite(void *__ptr,size_t __size,size_t __n,FILE *__s);
char * strstr(char *__haystack,char *__needle);
int strcmp(char *__s1,char *__s2);
size_t strlen(char *__s);
int remove(char *__filename);
int tolower(int __c);
void * memset(void *__s,int __c,size_t __n);
int sprintf(char *__s,char *__format,...);
int puts(char *__s);
int memcmp(void *__s1,void *__s2,size_t __n);
ulong strtoul(char *__nptr,char **__endptr,int __base);
int * __errno_location(void);
long strtol(char *__nptr,char **__endptr,int __base);
void * memmove(void *__dest,void *__src,size_t __n);
int setvbuf(FILE *__stream,char *__buf,int __modes,size_t __n);
void exit(int __status);
int getc(FILE *__stream);
int toupper(int __c);
int mkdir(char *__path,__mode_t __mode);
void * malloc(size_t __size);
void free(void *__ptr);
char * strncpy(char *__dest,char *__src,size_t __n);
int snprintf(char *__s,size_t __maxlen,char *__format,...);
int __xstat(int __ver,char *__filename,stat *__stat_buf);
char * strrchr(char *__s,int __c);
int scandir(char *__dir,dirent ***__namelist,__selector *__selector,__cmp *__cmp);
int pthread_mutex_lock(pthread_mutex_t *__mutex);
int vsnprintf(char *__s,size_t __maxlen,char *__format,__gnuc_va_list __arg);
int pthread_mutex_unlock(pthread_mutex_t *__mutex);
void dladdr(void);
ssize_t readlink(char *__path,char *__buf,size_t __len);
char * getcwd(char *__buf,size_t __size);
int chdir(char *__path);
char * getenv(char *__name);
int chmod(char *__file,__mode_t __mode);
int fputs(char *__s,FILE *__stream);
int rename(char *__old,char *__new);
int unlink(char *__name);
int strncasecmp(char *__s1,char *__s2,size_t __n);
int strncmp(char *__s1,char *__s2,size_t __n);
int strcasecmp(char *__s1,char *__s2);
ulonglong strtoull(char *__nptr,char **__endptr,int __base);
int clock_gettime(clockid_t __clock_id,timespec *__tp);
int nanosleep(timespec *__requested_time,timespec *__remaining);
tm * localtime(time_t *__timer);
time_t mktime(tm *__tp);
size_t strftime(char *__s,size_t __maxsize,char *__format,tm *__tp);
int gettimeofday(timeval *__tv,__timezone_ptr_t __tz);
time_t time(time_t *__timer);
int uname(utsname *__name);
int sscanf(char *__s,char *__format,...);
char * strdup(char *__s);
char * strtok_r(char *__s,char *__delim,char **__save_ptr);
char * strchr(char *__s,int __c);
size_t mbstowcs(wchar_t *__pwcs,char *__s,size_t __n);
void * calloc(size_t __nmemb,size_t __size);
void udev_new(void);
int __fxstat(int __ver,int __fildes,stat *__stat_buf);
void udev_device_new_from_devnum(void);
void udev_device_get_parent_with_subsystem_devtype(void);
void udev_device_get_sysattr_value(void);
void udev_device_unref(void);
void udev_unref(void);
wchar_t * wcsncpy(wchar_t *__dest,wchar_t *__src,size_t __n);
char * setlocale(int __category,char *__locale);
void udev_enumerate_new(void);
void udev_enumerate_add_match_subsystem(void);
void udev_enumerate_scan_devices(void);
void udev_enumerate_get_list_entry(void);
void udev_list_entry_get_next(void);
void udev_list_entry_get_name(void);
void udev_device_new_from_syspath(void);
void udev_device_get_devnode(void);
wchar_t * wcsdup(wchar_t *__s);
void udev_enumerate_unref(void);
int open(char *__file,int __oflag,...);
int ioctl(int __fd,ulong __request,...);
void perror(char *__s);
int wcscmp(wchar_t *__s1,wchar_t *__s2);
ssize_t write(int __fd,void *__buf,size_t __n);
int poll(pollfd *__fds,nfds_t __nfds,int __timeout);
ssize_t read(int __fd,void *__buf,size_t __nbytes);
int close(int __fd);
size_t wcslen(wchar_t *__s);
int wcsncmp(wchar_t *__s1,wchar_t *__s2,size_t __n);
int wmemcmp(wchar_t *__s1,wchar_t *__s2,size_t __n);
int putchar(int __c);
void inflate(void);
void deflateInit_(void);
void deflate(void);
void deflateEnd(void);
void inflateInit_(void);
void inflateEnd(void);
void crc32(void);
int pthread_cond_timedwait(pthread_cond_t *__cond,pthread_mutex_t *__mutex,timespec *__abstime);
int pthread_cond_wait(pthread_cond_t *__cond,pthread_mutex_t *__mutex);
pthread_t pthread_self(void);
int pthread_setschedparam(pthread_t __target_thread,int __policy,sched_param *__param);
int pthread_join(pthread_t __th,void **__thread_return);
int pthread_create(pthread_t *__newthread,pthread_attr_t *__attr,__start_routine *__start_routine,void *__arg);
int usleep(__useconds_t __useconds);
int pthread_kill(pthread_t __threadid,int __signo);
int pthread_getschedparam(pthread_t __target_thread,int *__policy,sched_param *__param);
int pthread_cond_init(pthread_cond_t *__cond,pthread_condattr_t *__cond_attr);
int pthread_cond_destroy(pthread_cond_t *__cond);
int pthread_cond_signal(pthread_cond_t *__cond);
int pthread_cond_broadcast(pthread_cond_t *__cond);
int sched_get_priority_max(int __algorithm);
int sched_get_priority_min(int __algorithm);
void openlog(char *__ident,int __option,int __facility);
int vsprintf(char *__s,char *__format,__gnuc_va_list __arg);
void syslog(int __pri,char *__fmt,...);
__pid_t waitpid(__pid_t __pid,int *__stat_loc,int __options);
long syscall(long __sysno,...);
int pthread_setname_np(pthread_t __target_thread,char *__name);
__pid_t getpid(void);
int pthread_cancel(pthread_t __th);
int sched_setaffinity(__pid_t __pid,size_t __cpusetsize,cpu_set_t *__cpuset);
__pid_t fork(void);
int system(char *__command);
void _exit(int __status);
int kill(__pid_t __pid,int __sig);
int getpriority(__priority_which_t __which,id_t __who);
int setpriority(__priority_which_t __which,id_t __who,int __prio);
int __xstat64(int __ver,char *__filename,stat64 *__stat_buf);
int sigaction(int __sig,sigaction *__act,sigaction *__oact);
DIR * opendir(char *__name);
dirent * readdir(DIR *__dirp);
char * fgets(char *__s,int __n,FILE *__stream);
int closedir(DIR *__dirp);
int pthread_mutexattr_init(pthread_mutexattr_t *__attr);
int pthread_mutex_init(pthread_mutex_t *__mutex,pthread_mutexattr_t *__mutexattr);
int pthread_mutexattr_destroy(pthread_mutexattr_t *__attr);
int pthread_mutex_destroy(pthread_mutex_t *__mutex);
int semctl(int __semid,int __semnum,int __cmd,...);
int semget(key_t __key,int __nsems,int __semflg);
char * strerror(int __errnum);
int semop(int __semid,sembuf *__sops,size_t __nsops);
int pthread_setspecific(pthread_key_t __key,void *__pointer);
void * pthread_getspecific(pthread_key_t __key);
int isalpha(int param_1);
int pthread_key_create(pthread_key_t *__key,__destr_function *__destr_function);
int pthread_mutexattr_settype(pthread_mutexattr_t *__attr,int __kind);
int getrlimit(__rlimit_resource_t __resource,rlimit *__rlimits);
int setrlimit(__rlimit_resource_t __resource,rlimit *__rlimits);
int sched_getscheduler(__pid_t __pid);
int sched_getparam(__pid_t __pid,sched_param *__param);
int sched_setscheduler(__pid_t __pid,int __policy,sched_param *__param);
int sched_yield(void);
int pthread_attr_init(pthread_attr_t *__attr);
int pthread_attr_setstacksize(pthread_attr_t *__attr,size_t __stacksize);
__pid_t getppid(void);
int pthread_key_delete(pthread_key_t __key);
void rewind(FILE *__stream);
int fflush(FILE *__stream);
void dlopen(void);
void dlerror(void);
void dlsym(void);
void dlclose(void);
void abort(void);
int fputc(int __c,FILE *__stream);
FILE * fdopen(int __fd,char *__modes);
FILE * fopen64(char *__filename,char *__modes);
int fileno(FILE *__stream);
ssize_t writev(int __fd,iovec *__iovec,int __count);
__off64_t lseek64(int __fd,__off64_t __offset,int __whence);
int __fxstat64(int __ver,int __fildes,stat64 *__stat_buf);
void __uselocale(void);
wchar_t * wmemchr(wchar_t *__s,wchar_t __c,size_t __n);
size_t wcsnrtombs(char *__dst,wchar_t **__src,size_t __nwc,size_t __len,mbstate_t *__ps);
size_t wcrtomb(char *__s,wchar_t __wc,mbstate_t *__ps);
void * memchr(void *__s,int __c,size_t __n);
size_t mbsnrtowcs(wchar_t *__dst,char **__src,size_t __nmc,size_t __len,mbstate_t *__ps);
size_t mbrtowc(wchar_t *__pwc,char *__s,size_t __n,mbstate_t *__p);
size_t __ctype_get_mb_cur_max(void);
int pthread_once(pthread_once_t *__once_control,__init_routine *__init_routine);
void __nl_langinfo_l(void);
size_t mbsrtowcs(wchar_t *__dst,char **__src,size_t __len,mbstate_t *__ps);
iconv_t iconv_open(char *__tocode,char *__fromcode);
size_t iconv(iconv_t __cd,char **__inbuf,size_t *__inbytesleft,char **__outbuf,size_t *__outbytesleft);
int iconv_close(iconv_t __cd);
wchar_t * wmemcpy(wchar_t *__s1,wchar_t *__s2,size_t __n);
wchar_t * wmemmove(wchar_t *__s1,wchar_t *__s2,size_t __n);
wchar_t * wmemset(wchar_t *__s,wchar_t __c,size_t __n);
void __wctype_l(void);
void __towupper_l(void);
void __towlower_l(void);
void __iswctype_l(void);
int wctob(wint_t __c);
wint_t btowc(int __c);
void bindtextdomain(void);
int ungetc(int __c,FILE *__stream);
int putc(int __c,FILE *__stream);
int fseeko64(FILE *__stream,__off64_t __off,int __whence);
__off64_t ftello64(FILE *__stream);
wint_t getwc(__FILE *__stream);
wint_t ungetwc(wint_t __wc,__FILE *__stream);
wint_t putwc(wchar_t __wc,__FILE *__stream);
void gettext(void);
void * realloc(void *__ptr,size_t __size);
void __strtof_l(void);
void __strtod_l(void);
double strtold_l(char *__nptr,char **__endptr,__locale_t __loc);
void __newlocale(void);
void __freelocale(void);
void __duplocale(void);
void __strcoll_l(void);
void __strxfrm_l(void);
void __wcscoll_l(void);
void __wcsxfrm_l(void);
void bind_textdomain_codeset(void);
void dgettext(void);
void __strftime_l(void);
void __wcsftime_l(void);
void _ITM_RU1(void);
void _ZGTtnam(void);
void _ITM_memcpyRtWn(void);
void _ITM_RU8(void);
void _ITM_addUserCommitAction(void);
void _ITM_memcpyRnWt(void);
void _ZGTtdlPv(void);
void dl_iterate_phdr(void);
void __thiscall DeviceInterface::DeviceInterface(DeviceInterface *this,ushort param_1);
void FirmwareFooter::Import(char *param_1);
void FirmwareFooter::SignFile(char *param_1,char *param_2,firmware_update_target_t param_3);
void FirmwareUpdater::ComputeCRC(char *param_1,uchar *param_2);
void FirmwareUpdater::UpdateDevice(char *param_1,bool param_2);
undefined8 get_device_interface(void);
void FUN_0011cc32(void);
void FUN_0011cc4f(void);
void FUN_0011cc64(void);
void FUN_0011cc79(void);
void FUN_0011cc8e(void);
void FUN_0011cca3(void);
void FUN_0011ccb8(void);
void get_primary_device(void);
void FUN_0011cd18(void);
void FUN_0011cd4a(void);
void FUN_0011cd9a(void);
void FUN_0011cdc9(void);
void FUN_0011cdf8(void);
void PrintChecksum(char *param_1);
void SetBoardRevision(uint param_1);
void SetLotCode(uint param_1);
void GetPathToValveDevice(void);
void DoesWatchmanV3DeviceHaveDoppleganger(void);
void FUN_0011cf5d(void);
void UpdateV3FirmwareForSingleDevice(char *param_1,firmware_update_target_t param_2,watchmanv3UpdateMode_t param_3,bool param_4);
void FUN_0011d00d(void);
void FUN_0011d04b(void);
void FUN_0011d0c1(void);
void FUN_0011d0d4(void);
void FUN_0011d0ee(void);
void FUN_0011d125(void);
void FUN_0011d153(void);
void FUN_0011d170(void);
void FUN_0011d1a7(void);
void FUN_0011d1dd(void);
void FUN_0011d213(void);
void FUN_0011d229(void);
void FUN_0011d243(void);
void FUN_0011d279(void);
void FUN_0011d29f(void);
void FUN_0011d2d5(void);
void FUN_0011d30b(void);
void FUN_0011d342(void);
void UpdateApplicationFirmware(char *param_1,bool param_2,bool param_3);
void FUN_0011d378(void);
void UpdateFpgaFirmware(char *param_1,bool param_2);
void FUN_0011d3c4(void);
void UpdateRadioFirmware(char *param_1,bool param_2);
void FUN_0011d415(void);
void PrintGetAttributesResult(void);
void FUN_0011d456(void);
void FUN_0011d47b(void);
void UpdateFuelGaugeFirmware(char *param_1);
void FUN_0011d4e9(void);
void PrintWatchmanVersion(char *param_1);
void FUN_0011d529(void);
void TestWatchmanV3HwidWildcardMatch(void);
void FUN_0011d57f(void);
void FUN_0011d5d1(void);
void FUN_0011d64c(void);
void GetWatchmanV3DeviceNameFromHwid(uint param_1);
void FUN_0011d696(void);
void FUN_0011d6c4(void);
void FUN_0011d733(void);
void FUN_0011d754(void);
void FUN_0011d778(void);
void FUN_0011d7ad(void);
void FUN_0011d7d1(void);
void FUN_0011d7f2(void);
void FUN_0011d816(void);
void FUN_0011d83a(void);
void FUN_0011d85e(void);
void FUN_0011d882(void);
void FUN_0011d8a6(void);
void FUN_0011d8ca(void);
void FUN_0011d8ee(void);
void FUN_0011d912(void);
void FUN_0011d936(void);
void FUN_0011d95a(void);
void FUN_0011d97f(void);
void FUN_0011d9a0(void);
void __thiscall CFirmwareImageList::CFirmwareImageList(CFirmwareImageList *this,char *param_1);
void FUN_0011da19(void);
void FUN_0011da4d(void);
void FUN_0011da69(void);
void decode_long_arg(int param_1,char **param_2);
void FUN_0011db87(void);
void FUN_0011dbc6(void);
void FUN_0011dbe1(void);
void FilterValveDevices(void);
void FilterWatchmanV3Devices(string *param_1,vector *param_2,vector *param_3,vector *param_4,vector *param_5,watchmanv3UpdateMode_t param_6,bool param_7);
void FUN_0011dd26(void);
void FUN_0011dd9c(void);
void FUN_0011de09(void);
void FUN_0011de52(undefined8 param_1,undefined8 param_2,undefined8 param_3);
void FUN_0011de7f(void);
void FUN_0011dece(void);
void FUN_0011df1d(void);
void UpdateV3Firmware(char *param_1,firmware_update_target_t param_2,watchmanv3UpdateMode_t param_3,bool param_4);
void FUN_0011df82(void);
void UpdateUserDataImage(vector *param_1);
void FUN_0011dfdd(void);
void FUN_0011e00e(void);
void UpdateEverything(char *param_1,bool param_2,bool param_3);
void FUN_0011e0bf(void);
void FUN_0011e0e8(void);
void FUN_0011e150(void);
void SanityCheckDongleFirmware(char *param_1,uint *param_2);
undefined4 FUN_0011e1a6(void);
void FUN_0011e1de(void);
void UpdateDongle(char *param_1,bool param_2,bool param_3,bool param_4);
void FUN_0011e28c(void);
void FUN_0011e2a8(void);
void FUN_0011e2b2(void);
void HandleCommand(int param_1,int param_2,char **param_3);
void FUN_0011e305(void);
void FUN_0011e341(void);
void FUN_0011e363(void);
void FUN_0011e385(void);
void WirelessDongleDeviceInterface::Version(void);
void FUN_0011e428(void);
void WirelessDongleFirmwareUpdater::Blocks(vector *param_1);
void WirelessDongleFirmwareUpdater::UpdateDevice(char *param_1,bool param_2);
void FUN_0011e549(void);
void FUN_0011e56d(void);
void FUN_0011e5c8(void);
undefined4 FUN_0011e5e9(void);
void BCreateDirectoryRecursive(char *param_1);
void FUN_0011e628(void);
void __thiscall CDirIterator::CDirIterator(CDirIterator *this,char *param_1,char *param_2);
void FUN_0011e67c(void);
void CLog::Log(ELogLevel param_1,char *param_2,__va_list_tag *param_3);
void CLog::GetInstance(void);
void CLog::AddCallback(CLogCallback *param_1);
void CLogCallback::Initialize(function param_1,void *param_2);
void Path_GetWorkingDirectory(void);
void Path_FixSlashes(string *param_1,char param_2);
void Path_Join(string *param_1,string *param_2,char param_3);
void Path_Join(string *param_1,string *param_2,string *param_3,char param_4);
void Path_Join(string *param_1,string *param_2,string *param_3,string *param_4,char param_5);
void Path_Join(string *param_1,string *param_2,string *param_3,string *param_4,string *param_5,char param_6);
void Path_RemoveTrailingSlash(string *param_1,char param_2);
void Path_Compact(string *param_1,char param_2);
void Path_MakeAbsolute(string *param_1,string *param_2);
void FUN_0011e8d4(void);
void Path_IsSamePath(string *param_1,string *param_2);
void Path_IsDirectory(string *param_1);
void Path_WriteStringToTextFileAtomic(string *param_1,char *param_2);
void FUN_0011e95d(void);
void Path_FilePathToUrl(string *param_1,string *param_2);
void FUN_0011e9b3(void);
void FUN_0011ea2c(void);
void FUN_0011ea33(void);
void FUN_0011ea3a(void);
void Path_UrlToFilePath(string *param_1);
void Path_SanitizeFilename(string *param_1);
void Path_ReadBinaryFile(string *param_1);
void Path_FindParentSubDirectoryRecursively(string *param_1,string *param_2);
void Path_FindParentDirectoryRecursively(string *param_1,string *param_2);
void std::string::_Rep::_M_dispose(allocator *param_1);
void std::wstring::_Rep::_M_dispose(allocator *param_1);
void StringReplace(string *param_1,string *param_2,string *param_3);
void UTF16to8(wstring *param_1);
undefined8 FUN_0011ebc1(void);
void UTF16to8(wchar_t *param_1);
void UTF8to16(string *param_1);
undefined8 FUN_0011ec41(void);
void UTF8to16(char *param_1);
void StringToUpper(string *param_1);
void StringToLower(string *param_1);
void V_URLEncode(char *param_1,int param_2,char *param_3,int param_4);
void V_URLEncodeNoPlusForSpace(char *param_1,int param_2,char *param_3,int param_4);
void V_URLEncodeFullPath(char *param_1,int param_2,char *param_3,int param_4);
void RepairUTF8(char *param_1,char *param_2,string *param_3);
void Format(char *param_1,...);
void TokenizeString(string *param_1,char param_2);
void FUN_0011edf1(void);
void FUN_0011ee42(void);
void CAssert::AssertMsgImpl(char *param_1,uint param_2,bool param_3,uint param_4,...);
void CAssert::GetInstance(void);
void CAssert::AddCallback(CAssertCallback *param_1);
void CAssertCallback::Initialize(function param_1,void *param_2);
void BuildImage(UserDataImageBuilder *param_1,char *param_2,ulong param_3);
void FUN_0011ef73(void);
void SetUserData(UserDataImageBuilder *param_1,char *param_2,char *param_3,ulong param_4);
void FUN_0011efc8(void);
void FUN_0011efde(void);
void vortex::CHidDevice::WriteFeatureReport(FeatureID param_1,void *param_2,ulong param_3,int param_4);
void vortex::CHidDevice::GetAttachedDeviceInfo(int param_1,uint *param_2,uint *param_3,char *param_4,int param_5,char *param_6,int param_7);
void vortex::CHidDevice::GetAttachedDevicePath(int param_1,string *param_2);
void vortex::CHidDevice::FindAttachedDeviceNth(ushort param_1,ushort param_2,string *param_3,int param_4);
void vortex::CHidDevice::FindAttachedDevice(uint param_1,uint param_2,char *param_3);
void vortex::CHidDevice::FindAttachedDevicePid(uint param_1,char *param_2,int param_3);
void vortex::CHidDevice::SetDeviceID(uint param_1,uint param_2,char *param_3,int param_4);
void vortex::CHidDevice::FindAttachedDeviceBySerial(uint *param_1,uint *param_2,char *param_3);
void fix_hid_device_interface_numbers(hid_device_info *param_1);
void FUN_0011f10a(void);
void vortex::CHidDevice::Open(bool param_1);
void vortex::CHidDevice::DetectDevices(bool param_1);
void vortex::CHidDevice::GetAttachedLighthouseDevices(LighthouseDeviceTypes param_1,bool param_2,bool param_3);
void vortex::CHidDevice::GetAttachedLighthouseDevicesWithRetries(LighthouseDeviceTypes param_1,bool param_2,int param_3);
void vortex::CLighthouseUsbThread::Run(void);
void __thiscall vortex::CLighthouseThreadBase::CLighthouseThreadBase(CLighthouseThreadBase *this,CTime *param_1,char *param_2,int param_3,ushort param_4,ushort param_5);
void __thiscall vortex::CLighthouseIMUThread::CLighthouseIMUThread(CLighthouseIMUThread *this,CTime *param_1,ICallback *param_2,char *param_3);
void FUN_0011f26f(void);
void FUN_0011f29f(void);
void FUN_0011f2e0(void);
void vortex::CLighthouseIMUThread::GetWatchmanDeviceConsoleLogString(string *param_1);
void vortex::CLighthouseIMUThread::UpdateWatchmanVersion(void);
void vortex::CLighthouseIMUThread::VrcSetPowerLevel(EPowerLevel param_1);
void vortex::CLighthouseIMUThread::GetWirelessDongleAttributes(void);
void vortex::CLighthouseThreadBase::CTime::UpdateTrackingTime(double param_1,double param_2,bool param_3);
void vortex::CLighthouseThreadBase::CTime::GetTrackingTimeOffset(CTime *param_1);
void vortex::WriteUSBConfig(uint param_1,uint param_2,char *param_3,string *param_4);
void vortex::CLighthouseInput::NotifyWirelessDisconnection(CLighthouseIMUThread *param_1);
void __thiscall vortex::CLighthouseInput::CLighthouseInput(CLighthouseInput *this,string *param_1);
void __thiscall vortex::CLighthouseInput::CConnection::CConnection(CConnection *this,string *param_1);
void vortex::CLighthouseInput::CConnection::GetWirelessDongleSerialNumber(string *param_1);
void vortex::CLighthouseIMUThread::GetWirelessDongleFirmwareVersionString(void);
void FUN_0011f488(void);
void vortex::CLighthouseIMUThread::DeliverImuSample(_Watchman_IMUSample_t *param_1,long param_2);
void vortex::CLighthouseIMUThread::ProcessWirelessPacketWithDecoder(CWirelessDecoder *param_1,_Watchman_Wireless_Packet_t *param_2,long *param_3);
void FUN_0011f53d(void);
void vortex::DecodeAnalogixAudioStreamStatus(audio_stream_status_t param_1);
void FUN_0011f57d(void);
void FUN_0011f5b7(void);
void vortex::CLighthouseIMUThread::GetWatchmanHMDStatusString(void);
void vortex::CLighthouseIMUThread::GetWatchmanDeviceFlashLogString(string *param_1);
void FUN_0011f65e(void);
void FUN_0011f68e(void);
void FUN_0011f6b0(void);
void FUN_0011f702(void);
void vortex::FlashLogInterpretFuelGaugeReset(uchar *param_1);
void FUN_0011f7ac(void);
void FUN_0011f845(void);
void vortex::FlashLogInterpretVideoFailure(uchar *param_1);
void FUN_0011f89c(void);
void FUN_0011f8e7(void);
void vortex::FlashLogInterpretFwUpdateInfo(uchar *param_1);
void FUN_0011f98b(void);
void FUN_0011fa20(void);
void vortex::FlashLogInterpretRunningState(uchar *param_1);
void FUN_0011fa76(void);
void FUN_0011fb0b(void);
void vortex::FlashLogInterpretInitState(uchar *param_1);
void FUN_0011fb62(void);
void FUN_0011fbb4(void);
void vortex::FlashLogInterpretUint32(uchar *param_1);
void FUN_0011fc5f(void);
void FUN_0011fced(void);
void vortex::FlashLogInterpretAssert(uchar *param_1);
void FUN_0011fd5f(void);
void FUN_0011fdd3(void);
void FUN_0011fdff(void);
void vortex::EdidInfoVec_t::FindEdidWithNearestRefresh(float param_1);
void vortex::CLighthouseIMUThread::GetUserDataHeader(vector *param_1);
void vortex::CLighthouseThreadBase::Start(void);
void vortex::CLighthouseInput::Start(void);
void FUN_0011fe75(void);
void vortex::CLighthouseThreadBase::Stop(void);
void vortex::CLighthouseInput::Stop(void);
void vortex::CLighthouseInput::CConnection::Disconnect(void);
void vortex::CLighthouseIMUThread::EnumerateEdids(EdidInfoVec_t *param_1);
void vortex::CLighthouseIMUThread::AddImuCallback(void *param_1,IImuCallback *param_2);
void vortex::CLighthouseInput::CConnection::ConfigureInput(void);
void FUN_0011ff46(void);
void vortex::ReadUSBUserDataMaxAllocatedSizeCore(CHidDevice *param_1,int *param_2);
void vortex::ReadUSBConfig(CHidDevice *param_1,string *param_2,bool param_3);
void vortex::ReadUSBConfig(uint param_1,uint param_2,char *param_3,string *param_4,bool param_5,int param_6);
void vortex::CLighthouseInput::NotifyWiredDevicePresent(string *param_1);
void vortex::CLighthouseInput::GetAllWirelessDongleDescriptions(void);
void FUN_0011fff6(void);
void FUN_0012004d(void);
void vortex::ReadUSBUserDataCore(CHidDevice *param_1,uint param_2,uint param_3,int param_4,vector *param_5,function param_6);
void vortex::CLighthouseIMUThread::ReadUserData(uint param_1,uint param_2,vector *param_3);
void vortex::ReadUserDataHeaderCore(CHidDevice *param_1,vector *param_2);
void FUN_001200c8(void);
void vortex::CLighthouseIMUThread::LoadUserDataHeader(void);
void vortex::VerifyUSBUserDataInDirectoryCore(bool *param_1,CHidDevice *param_2,vector *param_3,char *param_4,int param_5,function param_6);
void FUN_0012013e(void);
void FUN_00120156(void);
void vortex::CLighthouseIMUThread::VerifyUSBUserDataInDirectory(bool *param_1,string *param_2,int param_3,function param_4);
void FUN_001201b0(void);
void vortex::CLighthouseInput::GetBySerialNumber(string *param_1,bool param_2);
void FUN_001201fc(void);
void vortex::CLighthouseInput::GetByWiredSerialNumber(string *param_1);
void FUN_0012022a(void);
void vortex::CLighthouseInput::NotifyWirelessConnection(string *param_1,bool param_2,CLighthouseInput *param_3);
void vortex::CLighthouseInput::SetAttachedDeviceId(string *param_1,uint param_2);
void vortex::EdidInfoVec_t::GetAvailableRefreshRates(void);
void _GLOBAL__sub_I_lighthouseusb.cpp.cold(void);
void vortex::CVortexReadWriteLock::EnterRead(void);
void vortex::CVortexReadWriteLock::EnterWrite(void);
void __thiscall vortex::CVortexMutex::CVortexMutex(CVortexMutex *this);
void __thiscall vortex::CVortexSemaphore::CVortexSemaphore(CVortexSemaphore *this,bool param_1);
void vortex::CVrControllerUsbThread::OnHidClose(void);
void vortex::CVrControllerUsbThread::VrcSetPowerLevel(EPowerLevel param_1);
void vortex::CVrControllerUsbThread::OnHidPacket(uchar *param_1,int param_2,double param_3,bool param_4);
void vortex::CVrControllerUsbThread::FindSerialNumberByAttachedDeviceId(uint param_1);
void FUN_001203cf(void);
void vortex::CVrControllerUsbThread::Create(CTime *param_1,string *param_2,uint param_3);
void vortex::CVrControllerUsbThread::GetAttachedControllerId(uint *param_1,uint *param_2);
void FUN_00120441(void);
void CVrcDecodeTagged::DecodeSensorHits(uchar *param_1,int param_2);
void CWirelessDecoderWv2::Decode(uchar param_1,uchar *param_2,int param_3);
void FUN_0012048c(void);
void FUN_001204b2(void);
void FUN_001204bc(void);
void vortex::VortexOutputDebugString(char *param_1);
void FUN_00120569(void);
void vortex::RemoveDebugOutputHandler(_func_void_char_ptr *param_1);
void vortex::AddDebugOutputHandler(_func_void_char_ptr *param_1);
void FUN_001205a3(void);
void __thiscall CThreadEvent::CThreadEvent(CThreadEvent *this,char *param_1,bool param_2,bool param_3);
void CThread::ThreadProc(void *param_1);
void __thiscall CThreadSemaphore::CThreadSemaphore(CThreadSemaphore *this,long param_1,long param_2);
void __thiscall CThreadFullMutex::CThreadFullMutex(CThreadFullMutex *this,bool param_1,char *param_2,bool param_3,bool param_4);
void ThreadSetPriority.cold(void);
void CThread::Start(uint param_1);
void std::string::_Rep::_M_dispose(allocator *param_1);
void SteamVRVersionAsString(void);
void IsRunningInAppContainer(void);
void FUN_00120786(void);
undefined4 FUN_001207b2(void);
void SDLDynamic(void);
void __throw_concurrence_lock_error(void);
void (anonymous_namespace)::pool::free(void *param_1);
void (anonymous_namespace)::pool::allocate(ulong param_1);
void read_encoded_value_with_base(uchar param_1,ulong param_2,uchar *param_3,ulong *param_4);
void get_ttype_entry(lsda_header_info *param_1,ulong param_2);
void base_of_encoded_value(uchar param_1,_Unwind_Context *param_2);
void __gxx_personality_v0.cold(void);
void __cxa_call_unexpected.cold(void);
void __cxxabiv1::__terminate(_func_void *param_1);
void __cxa_guard_acquire.cold(void);
void * operator.new(ulong param_1);
void __verbose_terminate_handler(void);
void FUN_00120a18(void);
void __thiscall std::codecvt<>::~codecvt(codecvt<> *this);
void __thiscall std::codecvt<>::~codecvt(codecvt<> *this);
void __thiscall std::codecvt<>::~codecvt(codecvt<> *this);
void __thiscall std::codecvt<>::~codecvt(codecvt<> *this);
void std::codecvt<>::codecvt(ulong param_1);
void std::codecvt<>::codecvt(ulong param_1);
istream * std::operator>>(istream *param_1,string *param_2);
istream * std::getline<>(istream *param_1,string *param_2,char param_3);
void FUN_00120b98(void);
wistream * std::getline<>(wistream *param_1,wstring *param_2,wchar_t param_3);
void FUN_00120c19(void);
void __thiscall std::ios_base::Init::Init(Init *this);
void FUN_00120c94(void);
void FUN_00120cb4(void);
void FUN_00120cd4(void);
void FUN_00120cf6(void);
void FUN_00120d16(void);
void FUN_00120d38(void);
void FUN_00120d58(void);
void __thiscall std::ios_base::Init::~Init(Init *this);
void std::ios_base::sync_with_stdio(bool param_1);
void __thiscall std::locale::facet::~facet(facet *this);
void std::locale::name[abi:cxx11](void);
void __thiscall std::locale::operator==(locale *this,locale *param_2,undefined param_3,undefined param_4,undefined param_5,undefined param_6,undefined param_7,undefined param_8,undefined param_9,undefined param_10,undefined1 *param_11,undefined param_12);
void __thiscall std::locale::_Impl::~_Impl(_Impl *this);
void FUN_00120df7(void);
void __thiscall std::locale::_Impl::_Impl(_Impl *this,_Impl *param_1,ulong param_2);
void std::locale::_Impl::_M_install_facet(id *param_1,facet *param_2);
void FUN_00120e53(void);
void FUN_00120e62(void);
void FUN_00120e71(void);
void FUN_00120e83(void);
void std::locale::_Impl::_M_install_cache(facet *param_1,ulong param_2);
void FUN_00120f28(void);
void FUN_00120f56(void);
void __thiscall std::locale::_Impl::_Impl(_Impl *this,ulong param_1);
void FUN_00120f9b(void);
void FUN_00120fac(void);
void FUN_00120fbd(void);
void FUN_00120fce(void);
void FUN_00120fdf(void);
void FUN_00120ff0(void);
void FUN_00121001(void);
void __thiscall std::locale::locale(locale *this);
void FUN_0012104d(undefined8 param_1,undefined8 param_2,long param_3);
void std::locale::global(locale *param_1);
void FUN_001210be(void);
void std::moneypunct<char,true>::_M_initialize_moneypunct(__locale_struct *param_1,char *param_2,undefined param_3,undefined param_4,undefined param_5,undefined param_6,undefined8 param_7,undefined8 param_8);
void FUN_00121145(void);
void FUN_00121176(void);
void std::moneypunct<char,false>::_M_initialize_moneypunct(__locale_struct *param_1,char *param_2,undefined param_3,undefined param_4,undefined param_5,undefined param_6,undefined8 param_7,undefined8 param_8);
void FUN_001211ef(void);
void FUN_00121220(void);
void __thiscall std::moneypunct<char,true>::~moneypunct(moneypunct<char,true> *this);
void __thiscall std::moneypunct<char,true>::~moneypunct(moneypunct<char,true> *this);
void __thiscall std::moneypunct<char,false>::~moneypunct(moneypunct<char,false> *this);
void __thiscall std::moneypunct<char,false>::~moneypunct(moneypunct<char,false> *this);
void std::moneypunct<>::_M_initialize_moneypunct(__locale_struct *param_1,char *param_2,undefined param_3,undefined param_4,undefined param_5,undefined param_6,undefined8 param_7);
void FUN_001212d6(void);
void FUN_00121301(void);
void std::moneypunct<>::_M_initialize_moneypunct(__locale_struct *param_1,char *param_2,undefined param_3,undefined param_4,undefined param_5,undefined param_6,undefined8 param_7);
void FUN_00121378(void);
void FUN_001213a3(void);
void __thiscall std::moneypunct<>::~moneypunct(moneypunct<> *this);
void __thiscall std::moneypunct<>::~moneypunct(moneypunct<> *this);
void __thiscall std::moneypunct<>::~moneypunct(moneypunct<> *this);
void __thiscall std::moneypunct<>::~moneypunct(moneypunct<> *this);
void std::moneypunct<char,true>::_M_initialize_moneypunct(__locale_struct *param_1,char *param_2,undefined param_3,undefined param_4,undefined param_5,undefined param_6,undefined8 param_7,undefined8 param_8);
void FUN_0012145d(void);
void FUN_0012148e(void);
void std::moneypunct<char,false>::_M_initialize_moneypunct(__locale_struct *param_1,char *param_2,undefined param_3,undefined param_4,undefined param_5,undefined param_6,undefined8 param_7,undefined8 param_8);
void FUN_00121507(void);
void FUN_00121538(void);
void __thiscall std::moneypunct<char,true>::~moneypunct(moneypunct<char,true> *this);
void __thiscall std::moneypunct<char,true>::~moneypunct(moneypunct<char,true> *this);
void __thiscall std::moneypunct<char,false>::~moneypunct(moneypunct<char,false> *this);
void __thiscall std::moneypunct<char,false>::~moneypunct(moneypunct<char,false> *this);
void std::moneypunct<>::_M_initialize_moneypunct(__locale_struct *param_1,char *param_2,undefined param_3,undefined param_4,undefined param_5,undefined param_6,undefined8 param_7);
void FUN_001215ee(void);
void FUN_00121619(void);
void std::moneypunct<>::_M_initialize_moneypunct(__locale_struct *param_1,char *param_2,undefined param_3,undefined param_4,undefined param_5,undefined param_6,undefined8 param_7);
void FUN_00121690(void);
void FUN_001216bb(void);
void __thiscall std::moneypunct<>::~moneypunct(moneypunct<> *this);
void __thiscall std::moneypunct<>::~moneypunct(moneypunct<> *this);
void __thiscall std::moneypunct<>::~moneypunct(moneypunct<> *this);
void __thiscall std::moneypunct<>::~moneypunct(moneypunct<> *this);
void std::numpunct<char>::_M_initialize_numpunct(__locale_struct *param_1);
void __thiscall std::numpunct<char>::~numpunct(numpunct<char> *this);
void __thiscall std::numpunct<char>::~numpunct(numpunct<char> *this);
void std::numpunct<wchar_t>::_M_initialize_numpunct(__locale_struct *param_1);
void __thiscall std::numpunct<wchar_t>::~numpunct(numpunct<wchar_t> *this);
void __thiscall std::numpunct<wchar_t>::~numpunct(numpunct<wchar_t> *this);
void std::numpunct<char>::_M_initialize_numpunct(__locale_struct *param_1);
void __thiscall std::numpunct<char>::~numpunct(numpunct<char> *this);
void __thiscall std::numpunct<char>::~numpunct(numpunct<char> *this);
void std::numpunct<wchar_t>::_M_initialize_numpunct(__locale_struct *param_1);
void __thiscall std::numpunct<wchar_t>::~numpunct(numpunct<wchar_t> *this);
void __thiscall std::numpunct<wchar_t>::~numpunct(numpunct<wchar_t> *this);
void std::locale::_Impl::_M_init_extra(facet **param_1);
void FUN_00121862(void);
void FUN_00121876(void);
void FUN_0012188a(void);
void FUN_0012189e(void);
void FUN_001218b2(void);
void FUN_001218c6(void);
void FUN_001218da(void);
void std::locale::_Impl::_M_init_extra(void *param_1,void *param_2,char *param_3,char *param_4);
void FUN_00121906(void);
void FUN_0012191e(void);
void FUN_00121936(void);
void FUN_00121946(void);
void FUN_0012195e(void);
void FUN_00121976(void);
void FUN_0012198e(void);
void std::locale::name(undefined param_1,undefined param_2,undefined param_3,undefined param_4,undefined param_5,undefined param_6,undefined param_7,undefined param_8,undefined param_9,undefined param_10,undefined1 param_11);
void std::wstring::_Rep::_M_dispose(allocator *param_1);
void std::string::_Rep::_M_dispose(allocator *param_1);
void std::__facet_shims::(anonymous_namespace)::money_put_shim<wchar_t>::do_put(ostreambuf_iterator param_1,bool param_2,ios_base *param_3,wchar_t param_4,wstring *param_5);
void std::__facet_shims::(anonymous_namespace)::money_put_shim<char>::do_put(ostreambuf_iterator param_1,bool param_2,ios_base *param_3,char param_4,string *param_5);
void std::__facet_shims::(anonymous_namespace)::collate_shim<char>::do_transform(char *param_1,char *param_2,undefined param_3,undefined param_4,undefined param_5,undefined param_6,undefined param_7,undefined param_8,undefined param_9,undefined param_10,code *param_11);
void std::__facet_shims::(anonymous_namespace)::collate_shim<wchar_t>::do_transform(wchar_t *param_1,wchar_t *param_2,undefined param_3,undefined param_4,undefined param_5,undefined param_6,undefined param_7,undefined param_8,undefined param_9,undefined param_10,code *param_11);
void std::__facet_shims::(anonymous_namespace)::messages_shim<char>::do_get(int param_1,int param_2,int param_3,string *param_4);
void std::__facet_shims::(anonymous_namespace)::messages_shim<wchar_t>::do_get(int param_1,int param_2,int param_3,wstring *param_4);
void std::__facet_shims::(anonymous_namespace)::money_get_shim<wchar_t>::do_get(istreambuf_iterator param_1,istreambuf_iterator param_2,bool param_3,ios_base *param_4,_Ios_Iostate *param_5,wstring *param_6);
void std::__facet_shims::(anonymous_namespace)::money_get_shim<char>::do_get(istreambuf_iterator param_1,istreambuf_iterator param_2,bool param_3,ios_base *param_4,_Ios_Iostate *param_5,string *param_6);
void std::locale::facet::_M_cow_shim(id *param_1);
void FUN_00121afe(void);
void FUN_00121b16(void);
void FUN_00121b2e(void);
void FUN_00121b3e(void);
void FUN_00121b56(void);
void FUN_00121b6e(void);
void FUN_00121b86(void);
void FUN_00121b9a(void);
void FUN_00121bb2(void);
void FUN_00121bc6(void);
void FUN_00121bd6(void);
void FUN_00121bed(void);
void FUN_00121c04(void);
void FUN_00121c1c(void);
void FUN_00121c33(void);
void std::string::_Rep::_M_dispose(allocator *param_1);
void std::wstring::_Rep::_M_dispose(allocator *param_1);
void std::ctype<wchar_t>::ctype(ulong param_1);
void std::ctype_byname<wchar_t>::ctype_byname(char *param_1,ulong param_2);
void std::ctype<char>::classic_table(void);
void std::ctype<char>::ctype(ushort *param_1,bool param_2,ulong param_3);
void std::ctype_byname<char>::ctype_byname(char *param_1,ulong param_2);
void std::ctype<wchar_t>::do_narrow(wchar_t param_1,char param_2);
void std::ctype<wchar_t>::do_narrow(wchar_t *param_1,wchar_t *param_2,char param_3,char *param_4);
void FUN_00121d15(void);
void std::ctype<wchar_t>::_M_initialize_ctype(void);
void FUN_00121d35(void);
void std::__facet_shims::(anonymous_namespace)::collate_shim<char>::do_transform(char *param_1,char *param_2,undefined param_3,undefined param_4,undefined param_5,undefined param_6,undefined param_7,undefined param_8,undefined param_9,code *param_10);
void std::__facet_shims::(anonymous_namespace)::messages_shim<char>::do_get(int param_1,int param_2,int param_3,string *param_4);
void std::__facet_shims::(anonymous_namespace)::money_put_shim<char>::do_put(ostreambuf_iterator param_1,bool param_2,ios_base *param_3,char param_4,string *param_5);
void std::__facet_shims::(anonymous_namespace)::collate_shim<wchar_t>::do_transform(wchar_t *param_1,wchar_t *param_2,undefined param_3,undefined param_4,undefined param_5,undefined param_6,undefined param_7,undefined param_8,undefined param_9,code *param_10);
void std::__facet_shims::(anonymous_namespace)::messages_shim<wchar_t>::do_get(int param_1,int param_2,int param_3,wstring *param_4);
void std::__facet_shims::(anonymous_namespace)::money_put_shim<wchar_t>::do_put(ostreambuf_iterator param_1,bool param_2,ios_base *param_3,wchar_t param_4,wstring *param_5);
void std::__facet_shims::(anonymous_namespace)::money_get_shim<char>::do_get(istreambuf_iterator param_1,istreambuf_iterator param_2,bool param_3,ios_base *param_4,_Ios_Iostate *param_5,string *param_6);
void std::__facet_shims::(anonymous_namespace)::money_get_shim<wchar_t>::do_get(istreambuf_iterator param_1,istreambuf_iterator param_2,bool param_3,ios_base *param_4,_Ios_Iostate *param_5,wstring *param_6);
void std::locale::facet::_M_sso_shim(id *param_1);
void FUN_00121e16(void);
void FUN_00121e2e(void);
void FUN_00121e46(void);
void FUN_00121e56(void);
void FUN_00121e6e(void);
void FUN_00121e86(void);
void FUN_00121e9e(void);
void FUN_00121eb2(void);
void FUN_00121eca(void);
void FUN_00121ede(void);
void FUN_00121eee(void);
void FUN_00121f05(void);
void FUN_00121f1c(void);
void FUN_00121f34(void);
void FUN_00121f4b(void);
void std::__throw_bad_exception(void);
void std::__throw_bad_alloc(void);
void std::__throw_bad_cast(void);
void std::__throw_bad_typeid(void);
void std::__throw_logic_error(char *param_1);
void std::__throw_domain_error(char *param_1);
void std::__throw_invalid_argument(char *param_1);
void std::__throw_length_error(char *param_1);
void std::__throw_out_of_range(char *param_1);
void std::__throw_out_of_range_fmt(char *param_1,...);
void FUN_001221c4(void);
void std::__throw_runtime_error(char *param_1);
void std::__throw_range_error(char *param_1);
void std::__throw_overflow_error(char *param_1);
void std::__throw_underflow_error(char *param_1);
void std::__throw_bad_function_call(void);
void std::ios_base::_M_call_callbacks(event param_1);
void std::_V2::error_category::_M_message[abi:cxx11](int param_1,undefined param_2,undefined param_3,undefined param_4,undefined param_5,undefined param_6,undefined param_7,undefined param_8);
void std::__throw_system_error(int param_1);
void d_type.cold(void);
void __cxa_bad_cast(void);
void __cxa_bad_typeid(void);
void __cxa_throw_bad_array_new_length(void);
void * operator.new[](ulong param_1,nothrow_t *param_2);
void std::Catalogs::_M_erase(int param_1);
void std::Catalogs::_M_get(int param_1);
void std::Catalogs::_M_add(void);
void FUN_001226ca(void);
void std::istream::getline(char *param_1,long param_2,char param_3);
void FUN_0012275b(void);
void FUN_00122763(void);
void std::istream::ignore(long param_1,int param_2);
istream * std::operator>>(istream *param_1,char *param_2);
void FUN_00122819(void);
void std::wistream::getline(wchar_t *param_1,long param_2,wchar_t param_3);
void FUN_001228b5(void);
void FUN_001228ba(void);
void std::wistream::ignore(long param_1,uint param_2);
void std::__verify_grouping(char *param_1,ulong param_2,string *param_3);
void std::messages<char>::do_open(string *param_1,locale *param_2);
void std::messages<wchar_t>::do_open(string *param_1,locale *param_2);
void std::messages<char>::do_open(string *param_1,locale *param_2);
void std::messages<wchar_t>::do_open(string *param_1,locale *param_2);
void std::__verify_grouping(char *param_1,ulong param_2,string *param_3);
void __thiscall std::logic_error::logic_error(logic_error *this,string *param_1);
void __thiscall std::runtime_error::runtime_error(runtime_error *this,string *param_1);
void __thiscall std::logic_error::logic_error(logic_error *this,char *param_1);
void __thiscall std::runtime_error::runtime_error(runtime_error *this,char *param_1);
void std::_V2::error_category::_M_message(int param_1,undefined param_2,undefined param_3,undefined param_4,undefined param_5,undefined param_6,long param_7);
void _txnal_cow_string_C1_for_exceptions(void *param_1,char *param_2,void *param_3);
void __thiscall std::logic_error::logic_error(logic_error *this,char *param_1);
void std::logic_error::logic_error(std::string_const&)_[clone_.cold](void);
void __thiscall std::domain_error::domain_error(domain_error *this,char *param_1);
void std::domain_error::domain_error(std::string_const&)_[clone_.cold](void);
void __thiscall std::invalid_argument::invalid_argument(invalid_argument *this,char *param_1);
void std::invalid_argument::invalid_argument(std::string_const&)_[clone_.cold](void);
void __thiscall std::length_error::length_error(length_error *this,char *param_1);
void std::length_error::length_error(std::string_const&)_[clone_.cold](void);
void __thiscall std::out_of_range::out_of_range(out_of_range *this,char *param_1);
void std::out_of_range::out_of_range(std::string_const&)_[clone_.cold](void);
void __thiscall std::runtime_error::runtime_error(runtime_error *this,char *param_1);
void std::runtime_error::runtime_error(std::string_const&)_[clone_.cold](void);
void __thiscall std::range_error::range_error(range_error *this,char *param_1);
void std::range_error::range_error(std::string_const&)_[clone_.cold](void);
void __thiscall std::overflow_error::overflow_error(overflow_error *this,char *param_1);
void std::overflow_error::overflow_error(std::string_const&)_[clone_.cold](void);
void __thiscall std::underflow_error::underflow_error(underflow_error *this,char *param_1);
void std::underflow_error::underflow_error(std::string_const&)_[clone_.cold](void);
void (anonymous_namespace)::io_error_category::message[abi:cxx11](int param_1);
void std::ios_base::failure[abi:cxx11]::failure(string *param_1,undefined param_2,undefined param_3,undefined param_4,undefined param_5,undefined param_6,undefined param_7,void *param_8,undefined param_9,undefined param_10,void *param_11);
void FUN_00122c04(void);
void FUN_00122c24(void);
void std::ios_base::failure[abi:cxx11]::failure(string *param_1,error_code *param_2,undefined param_3,undefined param_4,undefined param_5,undefined param_6,undefined param_7,void *param_8,undefined param_9,undefined param_10,void *param_11);
void FUN_00122c62(void);
void FUN_00122c79(void);
void std::ios_base::failure[abi:cxx11]::failure(char *param_1,error_code *param_2);
void FUN_00122cb0(void);
void std::__throw_ios_failure(char *param_1);
void std::__throw_ios_failure(char *param_1,int param_2);
void __thiscall std::logic_error::logic_error(logic_error *this,string *param_1);
void __thiscall std::runtime_error::runtime_error(runtime_error *this,string *param_1);
void std::istream::ignore(long param_1);
void std::wistream::ignore(long param_1);
void __thiscall std::ios_base::failure::failure(failure *this,string *param_1);
void read_encoded_value_with_base.cold(void);
void base_of_encoded_value.cold(void);
void execute_cfa_program.cold(void);
void uw_frame_state_for.cold(void);
void uw_install_context_1.cold(void);
void execute_stack_op.cold(void);
void switchD_002051bf::caseD_4(void);
void uw_update_context_1.cold(void);
void abort(void);
void uw_init_context_1.cold(void);
void uw_update_context.cold(void);
void _Unwind_RaiseException_Phase2.cold(void);
void _Unwind_GetGR.cold(void);
void _Unwind_SetGR.cold(void);
void _Unwind_Resume.cold(void);
void _Unwind_Resume_or_Rethrow.cold(void);
void size_of_encoded_value.cold(void);
void base_from_object.cold(void);
void base_from_cb_data.cold(void);
void read_encoded_value_with_base.cold(void);
void _Unwind_IteratePhdrCallback.cold(void);
void search_object.cold(void);
void _GLOBAL__sub_I_DeviceInterface.cpp(void);
void _GLOBAL__sub_I_FirmwareUpdater.cpp(void);
undefined4 main(int param_1,char **param_2);
void _GLOBAL__sub_I_main.cpp(void);
void _GLOBAL__sub_I_SteamControllerDongleDevice.cpp(void);
void _GLOBAL__sub_I_WatchmanDongleDevice.cpp(void);
void _GLOBAL__sub_I_WirelessDongleDeviceInterface.cpp(void);
void _GLOBAL__sub_I_WirelessDongleFirmwareUpdater.cpp(void);
void _GLOBAL__sub_I_strtools_public.cpp(void);
void _GLOBAL__sub_I_hiddevice.cpp(void);
void _GLOBAL__sub_I_lighthouseusb.cpp(void);
void _GLOBAL__sub_I_systimer.cpp(void);
void _GLOBAL__sub_I_thread.cpp(void);
void _GLOBAL__sub_I_vrcontrollerusb.cpp(void);
void _GLOBAL__sub_I_threadtools.cpp(void);
void _GLOBAL__sub_I_eh_alloc.cc(void);
void _GLOBAL__sub_I_cxx11_locale_inst.cc(void);
void _GLOBAL__sub_I_cxx11_wlocale_inst.cc(void);
void _GLOBAL__sub_I_locale_inst.cc(void);
void _GLOBAL__sub_I_system_error.cc(void);
void _GLOBAL__sub_I_wlocale_inst.cc(void);
void processEntry _start(undefined8 param_1,undefined8 param_2);
void deregister_tm_clones(void);
void register_tm_clones(void);
void __do_global_dtors_aux(void);
void frame_dummy(void);
undefined8 __thiscall DeviceInterface::ParseFirmwareAttributes(DeviceInterface *this,ControllerAttribute *param_1,uint param_2,FirmwareAttributes *param_3);
void __thiscall DeviceInterface::DeviceInterface(DeviceInterface *this,ushort param_1);
void __thiscall DeviceInterface::~DeviceInterface(DeviceInterface *this);
void __thiscall DeviceInterface::~DeviceInterface(DeviceInterface *this);
undefined8 __thiscall DeviceInterface::WriteFeatureReportMessage(DeviceInterface *this,FeatureReportMsg *param_1,uint param_2);
undefined8 __thiscall DeviceInterface::SendFirmwareUpdateReboot(DeviceInterface *this,bool param_1);
undefined8 __thiscall DeviceInterface::SendResetIntoISP(DeviceInterface *this);
undefined8 __thiscall DeviceInterface::SendSetBoardRevision(DeviceInterface *this,uint param_1);
undefined8 __thiscall DeviceInterface::SendSetDateLotCode(DeviceInterface *this,uint param_1);
undefined8 __thiscall DeviceInterface::GetFirmwareAttributes(DeviceInterface *this,FirmwareAttributes *param_1);
undefined8 __thiscall DeviceInterface::GetFirmwareUpdateAck(DeviceInterface *this,FirmwareUpdateStatus *param_1);
void DeviceInterface::Open(bool param_1);
void __thiscall vortex::CHidDevice::~CHidDevice(CHidDevice *this);
void __thiscall vortex::CHidDevice::~CHidDevice(CHidDevice *this);
void __thiscall DeviceInterfaceV1::~DeviceInterfaceV1(DeviceInterfaceV1 *this);
void __thiscall DeviceInterfaceV1::~DeviceInterfaceV1(DeviceInterfaceV1 *this);
void __thiscall DeviceInterfaceV1::SendUpdateStart(DeviceInterfaceV1 *this,FeatureReportMessageIDs param_1);
undefined8 __thiscall DeviceInterfaceV1::SendFirmwareUpdateStart(DeviceInterfaceV1 *this);
undefined8 __thiscall DeviceInterfaceV1::SendFpgaUpdateStart(DeviceInterfaceV1 *this);
undefined8 __thiscall DeviceInterfaceV1::SendRadioUpdateStart(DeviceInterfaceV1 *this);
undefined8 __thiscall DeviceInterfaceV1::SendFuelGaugeUpdateStart(DeviceInterfaceV1 *this);
undefined8 __thiscall DeviceInterfaceV1::SendUserDataUpdateStart(DeviceInterfaceV1 *this);
void __thiscall DeviceInterfaceV1::SendUpdateData(DeviceInterfaceV1 *this,FeatureReportMessageIDs param_1,uchar *param_2,int param_3);
undefined8 __thiscall DeviceInterfaceV1::SendFirmwareUpdateData(DeviceInterfaceV1 *this,uchar *param_1,int param_2);
undefined8 __thiscall DeviceInterfaceV1::SendFpgaUpdateData(DeviceInterfaceV1 *this,uchar *param_1,int param_2);
undefined8 __thiscall DeviceInterfaceV1::SendRadioUpdateData(DeviceInterfaceV1 *this,uchar *param_1,int param_2);
undefined8 __thiscall DeviceInterfaceV1::SendFuelGaugeUpdateData(DeviceInterfaceV1 *this,uchar *param_1,int param_2);
undefined8 __thiscall DeviceInterfaceV1::SendUserDataUpdateData(DeviceInterfaceV1 *this,uchar *param_1,int param_2);
void __thiscall DeviceInterfaceV1::SendUpdateComplete(DeviceInterfaceV1 *this,FeatureReportMessageIDs param_1,uchar *param_2);
undefined8 __thiscall DeviceInterfaceV1::SendFirmwareUpdateComplete(DeviceInterfaceV1 *this,uchar *param_1);
undefined8 __thiscall DeviceInterfaceV1::SendFpgaUpdateComplete(DeviceInterfaceV1 *this,uchar *param_1);
undefined8 __thiscall DeviceInterfaceV1::SendRadioUpdateComplete(DeviceInterfaceV1 *this,uchar *param_1);
undefined8 __thiscall DeviceInterfaceV1::SendRadioDTMUpdateComplete(DeviceInterfaceV1 *this,uchar *param_1);
undefined8 __thiscall DeviceInterfaceV1::SendFuelGaugeUpdateComplete(DeviceInterfaceV1 *this,uchar *param_1);
undefined8 __thiscall DeviceInterfaceV1::SendUserDataUpdateComplete(DeviceInterfaceV1 *this,uchar *param_1);
void __thiscall DeviceInterfaceV1::DeviceInterfaceV1(DeviceInterfaceV1 *this,ushort param_1,bool param_2,bool param_3);
undefined8 __thiscall DeviceInterfaceV1::SendUpdateStart(DeviceInterfaceV1 *this,FeatureReportMessageIDs param_1);
undefined8 __thiscall DeviceInterfaceV1::SendUpdateData(DeviceInterfaceV1 *this,FeatureReportMessageIDs param_1,uchar *param_2,int param_3);
undefined8 __thiscall DeviceInterfaceV1::SendUpdateComplete(DeviceInterfaceV1 *this,FeatureReportMessageIDs param_1,uchar *param_2);
void __thiscall DeviceInterfaceV3::~DeviceInterfaceV3(DeviceInterfaceV3 *this);
void __thiscall DeviceInterfaceV3::~DeviceInterfaceV3(DeviceInterfaceV3 *this);
ulong __thiscall DeviceInterfaceV3::SendUpdateStart(DeviceInterfaceV3 *this);
undefined8 __thiscall DeviceInterfaceV3::SendFirmwareUpdateStart(DeviceInterfaceV3 *this);
undefined8 __thiscall DeviceInterfaceV3::SendRadioUpdateStart(DeviceInterfaceV3 *this);
undefined8 __thiscall DeviceInterfaceV3::SendFuelGaugeUpdateStart(DeviceInterfaceV3 *this);
undefined8 __thiscall DeviceInterfaceV3::SendUserDataUpdateStart(DeviceInterfaceV3 *this);
undefined8 __thiscall DeviceInterfaceV3::SendFpgaUpdateStart(DeviceInterfaceV3 *this);
ulong __thiscall DeviceInterfaceV3::SendUpdateData(DeviceInterfaceV3 *this,uchar *param_1,int param_2);
undefined8 __thiscall DeviceInterfaceV3::SendRadioUpdateData(DeviceInterfaceV3 *this,uchar *param_1,int param_2);
undefined8 __thiscall DeviceInterfaceV3::SendFpgaUpdateData(DeviceInterfaceV3 *this,uchar *param_1,int param_2);
void __thiscall DeviceInterfaceV3::SendUpdateComplete(DeviceInterfaceV3 *this);
undefined8 DeviceInterfaceV3::SendRadioUpdateComplete(uchar *param_1);
undefined8 DeviceInterfaceV3::SendFpgaUpdateComplete(uchar *param_1);
void __thiscall DeviceInterfaceV3::DeviceInterfaceV3(DeviceInterfaceV3 *this,bool param_1,bool param_2);
undefined8 __thiscall DeviceInterfaceV3::SendUpdateStart(DeviceInterfaceV3 *this);
undefined8 __thiscall DeviceInterfaceV3::SendUpdateData(DeviceInterfaceV3 *this,uchar *param_1,int param_2);
undefined8 __thiscall DeviceInterfaceV3::SendUpdateComplete(DeviceInterfaceV3 *this);
undefined8 __thiscall DeviceInterfaceV3::ParseFirmwareAttributesV3(DeviceInterfaceV3 *this,ControllerAttribute *param_1,uint param_2,FirmwareAttributes *param_3,bool param_4);
void __thiscall FirmwareFooter::FirmwareFooter(FirmwareFooter *this);
undefined8 __thiscall FirmwareFooter::Import(FirmwareFooter *this,char *param_1);
ulong FirmwareFooter::SignFile(char *param_1,char *param_2,firmware_update_target_t param_3);
undefined8 __thiscall FirmwareUpdater::ComputeCRC(FirmwareUpdater *this,char *param_1,uchar *param_2);
undefined4 __thiscall FirmwareUpdater::UpdateDevice(FirmwareUpdater *this,char *param_1,bool param_2);
void __thiscall FirmwareUpdater::FirmwareUpdater(FirmwareUpdater *this,DeviceInterface *param_1);
void __thiscall FirmwareUpdater::~FirmwareUpdater(FirmwareUpdater *this);
void __thiscall FirmwareUpdater::~FirmwareUpdater(FirmwareUpdater *this);
undefined4 __thiscall std::ctype<char>::do_widen(ctype<char> *this,char param_1);
void __thiscall LSFRCRC::Init(LSFRCRC *this);
void LSFRCRC::Add(int128 param_1);
void __thiscall LSFRCRC::GetResult(LSFRCRC *this,int128 *param_1);
DeviceInterfaceV1 * get_device_interface(undefined4 param_1,long *param_2);
char * get_device_string(device_t param_1);
void decode_device(char *param_1);
void std::string::_Rep::_M_dispose(allocator *param_1);
bool __thiscall VRCDevice::SendRebootIntoBootloader(VRCDevice *this);
undefined8 __thiscall VRCDevice::SendResetIntoISP(VRCDevice *this);
undefined8 __thiscall NEOVRCDevice::SendRebootIntoBootloader(NEOVRCDevice *this);
undefined8 __thiscall NEOVRCDevice::SendResetIntoISP(NEOVRCDevice *this);
bool __thiscall WirelessDevice::SendRebootIntoBootloader(WirelessDevice *this);
undefined8 __thiscall WirelessDevice::SendResetIntoISP(WirelessDevice *this);
bool __thiscall WirelessDongleDevice::SendRebootIntoBootloader(WirelessDongleDevice *this);
undefined8 __thiscall WirelessDongleDevice::SendResetIntoISP(WirelessDongleDevice *this);
void PrintUsage(void);
undefined8 SendResetWatchamnFromBootloader(DeviceInterface *param_1,bool param_2);
undefined8 SendResetIntoBootloader(PrimaryDevice *param_1,bool param_2);
CHidDevice * get_primary_device(undefined4 param_1,long *param_2);
undefined8 SteamAPI_IsSteamRunning(void);
undefined8 PrintChecksum(char *param_1);
undefined8 SetBoardRevision(uint param_1);
undefined8 SetLotCode(uint param_1);
undefined8 UpdateFirmware(CHidDevice *param_1,IFirmwareUpdater *param_2,char *param_3);
string * GetPathToValveDevice(string *param_1,uint param_2,undefined8 *param_3,undefined8 *param_4,string *param_5);
undefined8 DoesWatchmanV3DeviceHaveDoppleganger(string *param_1,string *param_2,string *param_3,undefined8 param_4,undefined8 param_5,undefined param_6);
int UpdateV3FirmwareForSingleDevice(char *param_1,firmware_update_target_t param_2,watchmanv3UpdateMode_t param_3,bool param_4);
int UpdateApplicationFirmware(char *param_1,bool param_2,bool param_3);
undefined4 UpdateFpgaFirmware(char *param_1,bool param_2);
undefined8 UpdateIspFirmware(char *param_1);
undefined4 UpdateRadioFirmware(char *param_1,bool param_2);
undefined8 IsValidWirelessDongleFirmware(vector *param_1,uint *param_2);
undefined8 PrintGetAttributesResult(void);
undefined8 ReadWatchmanFirmwareVersions(string *param_1,uint *param_2,uint *param_3);
void __thiscall CFirmwareImageList::~CFirmwareImageList(CFirmwareImageList *this);
long __thiscall CFirmwareImageList::FindLatestImageForHardwareRevision(CFirmwareImageList *this,uint param_1);
undefined4 UpdateFuelGaugeFirmware(char *param_1);
undefined8 PrintWatchmanVersion(char *param_1);
void PrintNotEnoughArguments(void);
undefined8 TestWatchmanV3HwidWildcardMatch(uint param_1,string *param_2,undefined8 param_3,undefined8 param_4,ulong param_5,undefined param_6);
string * GetWatchmanV3DeviceNameFromHwid(uint param_1);
void __thiscall CFirmwareImageList::CheckAddFirmwareImage(CFirmwareImageList *this,string *param_1,string *param_2);
void __thiscall CFirmwareImageList::CFirmwareImageList(CFirmwareImageList *this,char *param_1);
undefined8 decode_long_arg(int param_1,char **param_2);
int FilterValveDevices(uint param_1,string *param_2,string *param_3,long param_4,long param_5,long param_6,char param_11);
int FilterWatchmanV3Devices(string *param_1,vector *param_2,vector *param_3,vector *param_4,vector *param_5,watchmanv3UpdateMode_t param_6,bool param_7);
int UpdateV3Firmware(char *param_1,firmware_update_target_t param_2,watchmanv3UpdateMode_t param_3,bool param_4);
undefined4 UpdateUserDataImage(vector *param_1);
undefined4 UpdateEverything(char *param_1,bool param_2,bool param_3);
undefined8 IsValidProductionTestDongleFirmware(vector *param_1,uint *param_2);
undefined4 SanityCheckDongleFirmware(char *param_1,uint *param_2);
undefined8 UpdateDongle(char *param_1,bool param_2,bool param_3,bool param_4);
ulong HandleCommand(int param_1,int param_2,char **param_3);
undefined8 VRCFirmwareUpdater::GetFileOffset(void);
undefined8 VRCFirmwareUpdater::GetTransferLength(void);
void VRCFirmwareUpdater::SendUpdateData(uchar *param_1,ulong param_2);
void VRCFirmwareUpdater::SendUpdateComplete(uchar *param_1);
undefined8 VRCFirmwareUpdater::GetChecksumLength(void);
undefined8 VRCFirmwareUpdater::GetChecksumOffset(void);
undefined8 NEOVRCFirmwareUpdater::GetFileOffset(void);
undefined8 NEOVRCFirmwareUpdater::GetTransferLength(void);
void NEOVRCFirmwareUpdater::SendUpdateData(uchar *param_1,ulong param_2);
void NEOVRCFirmwareUpdater::SendUpdateComplete(uchar *param_1);
undefined8 NEOVRCFirmwareUpdater::GetChecksumLength(void);
undefined8 NEOVRCFirmwareUpdater::GetChecksumOffset(void);
uint __thiscall WatchmanV1FirmwareUpdater::GetFileOffset(WatchmanV1FirmwareUpdater *this);
undefined8 WatchmanV1FirmwareUpdater::GetTransferLength(void);
void WatchmanV1FirmwareUpdater::SendUpdateData(uchar *param_1,ulong param_2);
void WatchmanV1FirmwareUpdater::SendUpdateComplete(uchar *param_1);
undefined8 WatchmanV1FirmwareUpdater::GetChecksumLength(void);
undefined8 WatchmanV1FirmwareUpdater::GetChecksumOffset(void);
undefined8 WatchmanV3FirmwareUpdater::GetFileOffset(void);
undefined8 WatchmanV3FirmwareUpdater::GetTransferLength(void);
void WatchmanV3FirmwareUpdater::SendUpdateData(uchar *param_1,ulong param_2);
void WatchmanV3FirmwareUpdater::SendUpdateComplete(uchar *param_1);
undefined8 WatchmanV3FirmwareUpdater::GetChecksumLength(void);
undefined8 WatchmanV3FirmwareUpdater::GetChecksumOffset(void);
void __thiscall WatchmanV3FirmwareUpdater::InitChecksum(WatchmanV3FirmwareUpdater *this);
void __thiscall WatchmanV3FirmwareUpdater::GetChecksum(WatchmanV3FirmwareUpdater *this,uchar *param_1);
undefined8 FpgaFirmwareUpdater::GetFileOffset(void);
undefined8 FpgaFirmwareUpdater::GetTransferLength(void);
void __thiscall FpgaFirmwareUpdater::SendUpdateStart(FpgaFirmwareUpdater *this);
void FpgaFirmwareUpdater::SendUpdateData(uchar *param_1,ulong param_2);
void FpgaFirmwareUpdater::SendUpdateComplete(uchar *param_1);
undefined8 FpgaFirmwareUpdater::GetChecksumLength(void);
undefined8 FpgaFirmwareUpdater::GetChecksumOffset(void);
void __thiscall FpgaFirmwareUpdater::InitChecksum(FpgaFirmwareUpdater *this);
long __thiscall RadioFirmwareUpdater::GetFileOffset(RadioFirmwareUpdater *this);
undefined8 RadioFirmwareUpdater::GetTransferLength(void);
undefined8 RadioFirmwareUpdater::GetChecksumLength(void);
undefined8 RadioFirmwareUpdater::GetChecksumOffset(void);
undefined8 UserDataFirmwareUpdater::GetFileOffset(void);
undefined8 UserDataFirmwareUpdater::GetTransferLength(void);
void __thiscall UserDataFirmwareUpdater::SendUpdateStart(UserDataFirmwareUpdater *this);
void UserDataFirmwareUpdater::SendUpdateData(uchar *param_1,ulong param_2);
void UserDataFirmwareUpdater::SendUpdateComplete(uchar *param_1);
undefined8 UserDataFirmwareUpdater::GetChecksumLength(void);
undefined8 UserDataFirmwareUpdater::GetChecksumOffset(void);
void __thiscall UserDataFirmwareUpdater::InitChecksum(UserDataFirmwareUpdater *this);
undefined8 FuelGaugeFirmwareUpdater::GetFileOffset(void);
undefined8 FuelGaugeFirmwareUpdater::GetTransferLength(void);
void __thiscall FuelGaugeFirmwareUpdater::SendUpdateStart(FuelGaugeFirmwareUpdater *this);
void FuelGaugeFirmwareUpdater::SendUpdateData(uchar *param_1,ulong param_2);
void FuelGaugeFirmwareUpdater::SendUpdateComplete(uchar *param_1);
undefined8 FuelGaugeFirmwareUpdater::GetChecksumLength(void);
undefined8 FuelGaugeFirmwareUpdater::GetChecksumOffset(void);
void __thiscall FuelGaugeFirmwareUpdater::InitChecksum(FuelGaugeFirmwareUpdater *this);
undefined4 RadioFirmwareUpdater::SendUpdateData(uchar *param_1,ulong param_2);
undefined4 __thiscall RadioFirmwareUpdater::SendUpdateStart(RadioFirmwareUpdater *this);
undefined4 __thiscall WatchmanV3FirmwareUpdaterViaDongle::SendUpdateStart(WatchmanV3FirmwareUpdaterViaDongle *this);
undefined4 __thiscall WatchmanV1FirmwareUpdaterViaDongle::SendUpdateStart(WatchmanV1FirmwareUpdaterViaDongle *this);
undefined4 __thiscall WatchmanV3FirmwareUpdater::SendUpdateStart(WatchmanV3FirmwareUpdater *this);
undefined4 __thiscall WatchmanV1FirmwareUpdater::SendUpdateStart(WatchmanV1FirmwareUpdater *this);
undefined4 __thiscall NEOVRCFirmwareUpdater::SendUpdateStart(NEOVRCFirmwareUpdater *this);
undefined4 __thiscall VRCFirmwareUpdater::SendUpdateStart(VRCFirmwareUpdater *this);
void WirelessDongleDeviceInterface::Open(bool param_1);
void PrimaryDevice::Open(bool param_1);
void __thiscall WatchmanV1DeviceInterface::~WatchmanV1DeviceInterface(WatchmanV1DeviceInterface *this);
void __thiscall WatchmanV1DeviceInterface::~WatchmanV1DeviceInterface(WatchmanV1DeviceInterface *this);
void __thiscall VRCDeviceInterface::~VRCDeviceInterface(VRCDeviceInterface *this);
void __thiscall VRCDeviceInterface::~VRCDeviceInterface(VRCDeviceInterface *this);
void __thiscall WirelessDeviceInterface::~WirelessDeviceInterface(WirelessDeviceInterface *this);
void __thiscall WirelessDeviceInterface::~WirelessDeviceInterface(WirelessDeviceInterface *this);
void __thiscall NEOVRCDeviceInterface::~NEOVRCDeviceInterface(NEOVRCDeviceInterface *this);
void __thiscall NEOVRCDeviceInterface::~NEOVRCDeviceInterface(NEOVRCDeviceInterface *this);
void __thiscall WatchmanV1DeviceInterfaceViaDongle::~WatchmanV1DeviceInterfaceViaDongle(WatchmanV1DeviceInterfaceViaDongle *this);
void __thiscall WatchmanV1DeviceInterfaceViaDongle::~WatchmanV1DeviceInterfaceViaDongle(WatchmanV1DeviceInterfaceViaDongle *this);
void __thiscall RadioFirmwareUpdater::GetChecksum(RadioFirmwareUpdater *this,uchar *param_1);
void __thiscall WatchmanV1FirmwareUpdater::GetChecksum(WatchmanV1FirmwareUpdater *this,uchar *param_1);
void __thiscall NEOVRCFirmwareUpdater::GetChecksum(NEOVRCFirmwareUpdater *this,uchar *param_1);
void __thiscall VRCFirmwareUpdater::GetChecksum(VRCFirmwareUpdater *this,uchar *param_1);
void RadioFirmwareUpdater::UpdateChecksum(uchar *param_1);
void WatchmanV1FirmwareUpdater::UpdateChecksum(uchar *param_1);
void NEOVRCFirmwareUpdater::UpdateChecksum(uchar *param_1);
void VRCFirmwareUpdater::UpdateChecksum(uchar *param_1);
void __thiscall RadioFirmwareUpdater::InitChecksum(RadioFirmwareUpdater *this);
void __thiscall WatchmanV1FirmwareUpdater::InitChecksum(WatchmanV1FirmwareUpdater *this);
void __thiscall NEOVRCFirmwareUpdater::InitChecksum(NEOVRCFirmwareUpdater *this);
void __thiscall VRCFirmwareUpdater::InitChecksum(VRCFirmwareUpdater *this);
void __thiscall RadioFirmwareUpdater::~RadioFirmwareUpdater(RadioFirmwareUpdater *this);
void __thiscall RadioFirmwareUpdater::~RadioFirmwareUpdater(RadioFirmwareUpdater *this);
void __thiscall FpgaFirmwareUpdater::~FpgaFirmwareUpdater(FpgaFirmwareUpdater *this);
void __thiscall FpgaFirmwareUpdater::~FpgaFirmwareUpdater(FpgaFirmwareUpdater *this);
void __thiscall FuelGaugeFirmwareUpdater::~FuelGaugeFirmwareUpdater(FuelGaugeFirmwareUpdater *this);
void __thiscall FuelGaugeFirmwareUpdater::~FuelGaugeFirmwareUpdater(FuelGaugeFirmwareUpdater *this);
void __thiscall UserDataFirmwareUpdater::~UserDataFirmwareUpdater(UserDataFirmwareUpdater *this);
void __thiscall UserDataFirmwareUpdater::~UserDataFirmwareUpdater(UserDataFirmwareUpdater *this);
void __thiscall WatchmanV3FirmwareUpdater::~WatchmanV3FirmwareUpdater(WatchmanV3FirmwareUpdater *this);
void __thiscall WatchmanV3FirmwareUpdater::~WatchmanV3FirmwareUpdater(WatchmanV3FirmwareUpdater *this);
void __thiscall WatchmanV3FirmwareUpdaterViaDongle::~WatchmanV3FirmwareUpdaterViaDongle(WatchmanV3FirmwareUpdaterViaDongle *this);
void __thiscall WatchmanV3FirmwareUpdaterViaDongle::~WatchmanV3FirmwareUpdaterViaDongle(WatchmanV3FirmwareUpdaterViaDongle *this);
void __thiscall WatchmanV1FirmwareUpdater::~WatchmanV1FirmwareUpdater(WatchmanV1FirmwareUpdater *this);
void __thiscall WatchmanV1FirmwareUpdater::~WatchmanV1FirmwareUpdater(WatchmanV1FirmwareUpdater *this);
void __thiscall WatchmanV1FirmwareUpdaterViaDongle::~WatchmanV1FirmwareUpdaterViaDongle(WatchmanV1FirmwareUpdaterViaDongle *this);
void __thiscall WatchmanV1FirmwareUpdaterViaDongle::~WatchmanV1FirmwareUpdaterViaDongle(WatchmanV1FirmwareUpdaterViaDongle *this);
void __thiscall NEOVRCFirmwareUpdater::~NEOVRCFirmwareUpdater(NEOVRCFirmwareUpdater *this);
void __thiscall NEOVRCFirmwareUpdater::~NEOVRCFirmwareUpdater(NEOVRCFirmwareUpdater *this);
void __thiscall VRCFirmwareUpdater::~VRCFirmwareUpdater(VRCFirmwareUpdater *this);
void __thiscall VRCFirmwareUpdater::~VRCFirmwareUpdater(VRCFirmwareUpdater *this);
void __thiscall WatchmanV3FirmwareUpdater::UpdateChecksum(WatchmanV3FirmwareUpdater *this,uchar *param_1);
void __thiscall WatchmanV3DeviceInterface::~WatchmanV3DeviceInterface(WatchmanV3DeviceInterface *this);
void __thiscall WatchmanV3DeviceInterface::~WatchmanV3DeviceInterface(WatchmanV3DeviceInterface *this);
void __thiscall WatchmanV3DeviceInterfaceViaDongle::~WatchmanV3DeviceInterfaceViaDongle(WatchmanV3DeviceInterfaceViaDongle *this);
void __thiscall WatchmanV3DeviceInterfaceViaDongle::~WatchmanV3DeviceInterfaceViaDongle(WatchmanV3DeviceInterfaceViaDongle *this);
void __thiscall WatchmanV3DeviceInterface::ParseFirmwareAttributes(WatchmanV3DeviceInterface *this,ControllerAttribute *param_1,uint param_2,FirmwareAttributes *param_3);
void __thiscall WatchmanV3DeviceInterfaceViaDongle::ParseFirmwareAttributes(WatchmanV3DeviceInterfaceViaDongle *this,ControllerAttribute *param_1,uint param_2,FirmwareAttributes *param_3);
void RadioFirmwareUpdater::SendUpdateComplete(uchar *param_1);
void __thiscall FpgaFirmwareUpdater::UpdateChecksum(FpgaFirmwareUpdater *this,uchar *param_1);
void __thiscall FpgaFirmwareUpdater::GetChecksum(FpgaFirmwareUpdater *this,uchar *param_1);
void __thiscall UserDataFirmwareUpdater::UpdateChecksum(UserDataFirmwareUpdater *this,uchar *param_1);
void __thiscall UserDataFirmwareUpdater::GetChecksum(UserDataFirmwareUpdater *this,uchar *param_1);
void __thiscall FuelGaugeFirmwareUpdater::UpdateChecksum(FuelGaugeFirmwareUpdater *this,uchar *param_1);
void __thiscall FuelGaugeFirmwareUpdater::GetChecksum(FuelGaugeFirmwareUpdater *this,uchar *param_1);
void __thiscall std::vector<>::~vector(vector<> *this);
void __thiscall WirelessDongleDevice::~WirelessDongleDevice(WirelessDongleDevice *this);
void __thiscall WirelessDongleDeviceInterface::~WirelessDongleDeviceInterface(WirelessDongleDeviceInterface *this);
void __thiscall NEOVRCDevice::~NEOVRCDevice(NEOVRCDevice *this);
void __thiscall VRCDevice::~VRCDevice(VRCDevice *this);
void __thiscall WirelessDevice::~WirelessDevice(WirelessDevice *this);
void __thiscall WatchmanDevice::~WatchmanDevice(WatchmanDevice *this);
void __thiscall WirelessDevice::~WirelessDevice(WirelessDevice *this);
void __thiscall WirelessDongleDeviceInterface::~WirelessDongleDeviceInterface(WirelessDongleDeviceInterface *this);
void __thiscall WirelessDongleDevice::~WirelessDongleDevice(WirelessDongleDevice *this);
void __thiscall NEOVRCDevice::~NEOVRCDevice(NEOVRCDevice *this);
void __thiscall VRCDevice::~VRCDevice(VRCDevice *this);
undefined4 __thiscall WatchmanV1FirmwareUpdaterViaDongle::UpdateDevice(WatchmanV1FirmwareUpdaterViaDongle *this,char *param_1,bool param_2);
undefined4 __thiscall WatchmanV3FirmwareUpdaterViaDongle::UpdateDevice(WatchmanV3FirmwareUpdaterViaDongle *this,char *param_1,bool param_2);
void __thiscall PrimaryDevice::PrimaryDevice(PrimaryDevice *this,ushort param_1,ushort param_2,string *param_3,ulong param_4,bool param_5);
void __thiscall WatchmanDevice::WatchmanDevice(WatchmanDevice *this,ushort param_1);
void __thiscall WatchmanDevice::~WatchmanDevice(WatchmanDevice *this);
void __thiscall std::pair<>::~pair(pair<> *this);
void __thiscall WatchmanV3MatchedDevice_t::~WatchmanV3MatchedDevice_t(WatchmanV3MatchedDevice_t *this);
void __thiscall std::stringbuf::~stringbuf(stringbuf *this);
void __thiscall std::stringbuf::~stringbuf(stringbuf *this);
void __thiscall std::vector<>::~vector(vector<> *this);
void __thiscall std::vector<>::~vector(vector<> *this);
string * __thiscall std::vector<>::emplace_back<>(vector<> *this,string *param_1);
void __thiscall std::vector<>::_M_realloc_insert<>(vector<> *this,__normal_iterator param_1,string *param_2);
void __thiscall std::vector<>::_M_realloc_insert<>(vector<> *this,__normal_iterator param_1,WatchmanV3MatchedDevice_t *param_2);
void __thiscall std::_Rb_tree<>::_M_erase(_Rb_tree<> *this,_Rb_tree_node *param_1);
pair __thiscall std::_Rb_tree<>::_M_insert_unique<>(_Rb_tree<> *this,string *param_1);
void __thiscall std::vector<>::_M_realloc_insert<>(vector<> *this,__normal_iterator param_1,FirmwareImage_t **param_2);
__normal_iterator std::__find_if<>(__normal_iterator param_1,__normal_iterator param_2,_Iter_equals_val param_3,random_access_iterator_tag param_4);
void std::vector<>::_M_range_insert<>(__normal_iterator param_1,__normal_iterator param_2,__normal_iterator param_3,forward_iterator_tag param_4);
__normal_iterator std::__find_if<>(__normal_iterator param_1,__normal_iterator param_2,_Iter_equals_val param_3,random_access_iterator_tag param_4);
void std::vector<>::_M_range_insert<>(__normal_iterator param_1,__normal_iterator param_2,__normal_iterator param_3,forward_iterator_tag param_4);
__normal_iterator std::__find_if<>(__normal_iterator param_1,__normal_iterator param_2,_Iter_equals_val param_3,random_access_iterator_tag param_4);
void __thiscall std::vector<>::_M_realloc_insert<>(vector<> *this,__normal_iterator param_1,pair *param_2);
__normal_iterator std::__find_if<>(__normal_iterator param_1,__normal_iterator param_2,_Iter_equals_iter param_3,random_access_iterator_tag param_4);
__normal_iterator std::__search<>(__normal_iterator param_1,__normal_iterator param_2,uchar *param_3,uchar *param_4,_Iter_equal_to_iter param_5);
void __thiscall std::vector<>::_M_realloc_insert<char>(vector<> *this,__normal_iterator param_1,char *param_2);
undefined8 SteamControllerDongleDevice::SendResetIntoISP(void);
bool SteamControllerDongleDevice::Open(bool param_1);
bool __thiscall SteamControllerDongleDevice::SendRebootIntoBootloader(SteamControllerDongleDevice *this);
void __thiscall SteamControllerDongleDevice::~SteamControllerDongleDevice(SteamControllerDongleDevice *this);
void __thiscall SteamControllerDongleDevice::~SteamControllerDongleDevice(SteamControllerDongleDevice *this);
undefined8 __thiscall WatchmanDevice::SendRebootIntoBootloader(WatchmanDevice *this);
undefined8 __thiscall WatchmanDevice::SendResetIntoISP(WatchmanDevice *this);
undefined8 WatchmanDongleDevice::SendResetIntoISP(void);
bool __thiscall WatchmanDongleDevice::SendRebootIntoBootloader(WatchmanDongleDevice *this);
undefined8 __thiscall WatchmanDongleDevice::GetDongleDeviceInfo(WatchmanDongleDevice *this,MsgGetDongleDeviceInfo *param_1);
void __thiscall WatchmanDongleDevice::~WatchmanDongleDevice(WatchmanDongleDevice *this);
void __thiscall WatchmanDongleDevice::~WatchmanDongleDevice(WatchmanDongleDevice *this);
ulong __thiscall WirelessDongleDeviceInterface::GetAck(WirelessDongleDeviceInterface *this);
undefined8 __thiscall WirelessDongleDeviceInterface::WaitReady(WirelessDongleDeviceInterface *this);
undefined8 __thiscall WirelessDongleDeviceInterface::FlushAcks(WirelessDongleDeviceInterface *this);
bool __thiscall WirelessDongleDeviceInterface::RawCommand(WirelessDongleDeviceInterface *this,uchar *param_1,int param_2);
undefined4 __thiscall WirelessDongleDeviceInterface::RawReply(WirelessDongleDeviceInterface *this,uchar *param_1,int param_2);
undefined8 __thiscall WirelessDongleDeviceInterface::Command(WirelessDongleDeviceInterface *this,uchar *param_1,int param_2,uchar *param_3,int param_4);
void __thiscall WirelessDongleDeviceInterface::FlashWriteInit(WirelessDongleDeviceInterface *this,int param_1);
void __thiscall WirelessDongleDeviceInterface::FlashPageErase(WirelessDongleDeviceInterface *this,int param_1);
void __thiscall WirelessDongleDeviceInterface::SelectFlashHalf(WirelessDongleDeviceInterface *this,int param_1);
void __thiscall WirelessDongleDeviceInterface::FlashReadBlock(WirelessDongleDeviceInterface *this,int param_1,uchar *param_2);
void __thiscall WirelessDongleDeviceInterface::ResetToApplication(WirelessDongleDeviceInterface *this);
void WirelessDongleDeviceInterface::Version(void);
undefined4 __thiscall WirelessDongleDeviceInterface::Flush(WirelessDongleDeviceInterface *this);
undefined4 __thiscall WirelessDongleFirmwareUpdater::WritePage(WirelessDongleFirmwareUpdater *this,int param_1,__normal_iterator param_2);
undefined4 __thiscall WirelessDongleFirmwareUpdater::VerifyPage(WirelessDongleFirmwareUpdater *this,int param_1,__normal_iterator param_2,bool *param_3);
undefined8 __thiscall WirelessDongleFirmwareUpdater::UpdatePage(WirelessDongleFirmwareUpdater *this,int param_1,vector *param_2,bool param_3,int param_4);
ulong __thiscall WirelessDongleFirmwareUpdater::CheckForJumpInstruction(WirelessDongleFirmwareUpdater *this);
undefined8 __thiscall WirelessDongleFirmwareUpdater::WriteJumpInstruction(WirelessDongleFirmwareUpdater *this);
vector * WirelessDongleFirmwareUpdater::Blocks(vector *param_1);
undefined4 __thiscall WirelessDongleFirmwareUpdater::UpdateDevice(WirelessDongleFirmwareUpdater *this,char *param_1,bool param_2);
void __thiscall WirelessDongleFirmwareUpdater::~WirelessDongleFirmwareUpdater(WirelessDongleFirmwareUpdater *this);
void __thiscall WirelessDongleFirmwareUpdater::~WirelessDongleFirmwareUpdater(WirelessDongleFirmwareUpdater *this);
void __thiscall std::vector<>::_M_fill_insert(vector<> *this,__normal_iterator param_1,ulong param_2,char *param_3);
void __thiscall std::vector<>::_M_realloc_insert<>(vector<> *this,__normal_iterator param_1,Block *param_2);
uint vrcore::crc32(uint param_1,void *param_2,ulong param_3);
void std::string::_Rep::_M_dispose(allocator *param_1);
bool FileSelect(dirent *param_1);
bool BCreateDirectory(char *param_1);
undefined4 BCreateDirectoryRecursive(char *param_1);
void __thiscall CDirIterator::~CDirIterator(CDirIterator *this);
bool __thiscall CDirIterator::IsValid(CDirIterator *this);
bool __thiscall CDirIterator::BValidFilename(CDirIterator *this);
void CDirIterator::CurrentFileName(void);
undefined8 __thiscall CDirIterator::CurrentFileLength(CDirIterator *this);
undefined8 __thiscall CDirIterator::CurrentFileWriteTime(CDirIterator *this);
undefined8 __thiscall CDirIterator::CurrentFileCreateTime(CDirIterator *this);
uint __thiscall CDirIterator::BCurrentIsDir(CDirIterator *this);
undefined8 CDirIterator::BCurrentIsHidden(void);
undefined8 CDirIterator::BCurrentIsReadOnly(void);
undefined8 CDirIterator::BCurrentIsSystem(void);
undefined8 CDirIterator::BCurrentIsMarkedForArchive(void);
undefined8 FillDataStruct(_finddata_t *param_1);
CDirIterator __thiscall CDirIterator::BNextFile(CDirIterator *this);
ulong _findfirst(char *param_1,_finddata_t *param_2);
void __thiscall CDirIterator::Init(CDirIterator *this,string *param_1);
void __thiscall CDirIterator::CDirIterator(CDirIterator *this,char *param_1,char *param_2);
undefined8 _findnext(long param_1,_finddata_t *param_2);
undefined8 _findclose(long param_1);
void __thiscall CLog::RemoveCallback(CLog *this,CLogCallback *param_1);
void __thiscall CLog::Log(CLog *this,ELogLevel param_1,char *param_2,__va_list_tag *param_3);
void CLog::Log(ELogLevel param_1,char *param_2,undefined param_3,undefined param_4,undefined param_5,undefined param_6,undefined param_7,...);
undefined8 * CLog::GetInstance(void);
void LogHelper(ELogLevel param_1,char *param_2,__va_list_tag *param_3);
void __thiscall CLogCallback::~CLogCallback(CLogCallback *this);
void Log(ELogLevel param_1,char *param_2,undefined param_3,undefined param_4,undefined param_5,undefined param_6,undefined param_7,...);
void Log(char *param_1,undefined param_2,undefined param_3,undefined param_4,undefined param_5,undefined param_6,undefined param_7,...);
void LogDirect(ELogLevel param_1,char *param_2,__va_list_tag *param_3);
undefined8 __thiscall CLog::AddCallback(CLog *this,CLogCallback *param_1);
undefined8 __thiscall CLogCallback::Initialize(CLogCallback *this,function param_1,void *param_2);
void __thiscall std::vector<>::_M_realloc_insert<>(vector<> *this,__normal_iterator param_1,CLogCallback **param_2);
void Path_GetThisModulePath(void);
void std::string::_Rep::_M_dispose(allocator *param_1);
void Path_GetExecutablePath(void);
void Path_GetWorkingDirectory(void);
bool Path_SetWorkingDirectory(string *param_1);
void Path_GetTemporaryDirectory(void);
bool Path_IsAbsolute(string *param_1);
string * Path_FixSlashes(string *param_1,char param_2);
undefined8 Path_GetSlash(void);
string * Path_Join(string *param_1,string *param_2,char param_3);
string * Path_Join(string *param_1,string *param_2,string *param_3,char param_4);
string * Path_Join(string *param_1,string *param_2,string *param_3,string *param_4,char param_5);
string * Path_Join(string *param_1,string *param_2,string *param_3,string *param_4,string *param_5,char param_6,undefined1 param_7);
string * Path_RemoveTrailingSlash(string *param_1,char param_2);
string * Path_Compact(string *param_1,char param_2);
string * Path_MakeAbsolute(string *param_1,string *param_2);
ulong Path_IsSamePath(string *param_1,string *param_2);
ulong Path_IsDirectory(string *param_1);
undefined8 Path_IsAppBundle(string *param_1);
ulong Path_Exists(string *param_1);
void * Path_ReadBinaryFile(string *param_1,int *param_2);
ulong Path_ReadBinaryFile(string *param_1,uchar *param_2,uint param_3);
bool Path_WriteBinaryFile(string *param_1,uchar *param_2,uint param_3);
string * Path_ReadTextFile(string *param_1);
undefined8 Path_MakeWritable(string *param_1);
uint Path_WriteStringToTextFile(string *param_1,char *param_2);
ulong Path_WriteStringToTextFileAtomic(string *param_1,char *param_2);
string * Path_FilePathToUrl(string *param_1,string *param_2);
string * Path_UrlToFilePath(string *param_1);
void GetUserDocumentsPath(void);
bool Path_UnlinkFile(string *param_1);
string * Path_SanitizeFilename(string *param_1);
undefined8 Path_DeleteDirectory(string *param_1,bool param_2);
string * Path_ReadBinaryFile(string *param_1);
string * Path_StripFilename(string *param_1,char param_2);
string * Path_FindParentSubDirectoryRecursively(string *param_1,string *param_2);
string * Path_StripDirectory(string *param_1,char param_2);
string * Path_FindParentDirectoryRecursively(string *param_1,string *param_2);
string * Path_StripExtension(string *param_1);
string * Path_GetExtension(string *param_1);
void __thiscall std::vector<>::_M_default_append(vector<> *this,ulong param_1);
char * std::string::_S_construct<>(__normal_iterator param_1,__normal_iterator param_2,allocator *param_3,forward_iterator_tag param_4);
uint CharNeedsEscape_Component(char param_1);
uint CharNeedsEscape_FullPath(char param_1);
long V_URLDecodeInternal(char *param_1,int param_2,char *param_3,int param_4,bool param_5);
void stricmp(char *param_1,char *param_2);
void strnicmp(char *param_1,char *param_2,ulong param_3);
bool StringHasPrefix(string *param_1,string *param_2);
bool StringHasPrefixCaseSensitive(string *param_1,string *param_2);
ulong StringHasSuffix(string *param_1,string *param_2);
ulong StringHasSuffixCaseSensitive(string *param_1,string *param_2);
string * StringReplace(string *param_1,string *param_2,string *param_3);
wstring * UTF16to8(wstring *param_1);
wchar_t * UTF16to8(wchar_t *param_1);
string * UTF8to16(string *param_1);
char * UTF8to16(char *param_1);
void strcpy_safe(char *param_1,ulong param_2,char *param_3);
string * StringToUpper(string *param_1);
string * StringToLower(string *param_1);
uint ReturnStdString(string *param_1,char *param_2,uint param_3);
ulong Uint64ToString(ulong param_1);
void StringToUint64(string *param_1);
char cIntToHexDigit(int param_1);
uint iHexCharToInt(char param_1);
void V_URLEncodeInternal(char *param_1,int param_2,char *param_3,int param_4,bool param_5,function param_6);
undefined8 V_URLDecodeInternal(char *param_1,int param_2,char *param_3,int param_4,bool param_5);
void V_URLEncode(char *param_1,int param_2,char *param_3,int param_4);
void V_URLEncodeNoPlusForSpace(char *param_1,int param_2,char *param_3,int param_4);
void V_URLEncodeFullPath(char *param_1,int param_2,char *param_3,int param_4);
undefined8 V_URLDecode(char *param_1,int param_2,char *param_3,int param_4);
undefined8 V_URLDecodeNoPlusForSpace(char *param_1,int param_2,char *param_3,int param_4);
void V_StripExtension(string *param_1);
undefined RepairUTF8(char *param_1,char *param_2,string *param_3);
void RepairUTF8(string *param_1,string *param_2);
string * TrimTrailingWhitespace(string *param_1);
char * Format(char *param_1,undefined param_2,undefined param_3,undefined param_4,undefined param_5,undefined param_6,undefined param_7,...);
undefined8 IpToString(uint param_1);
undefined8 IpAndPortToString(uint param_1,ushort param_2);
string * TokenizeString(string *param_1,char param_2);
void std::_Function_handler<>::_M_invoke(_Any_data *param_1,char *param_2);
undefined8 std::_Function_base::_Base_manager<>::_M_manager(_Any_data *param_1,_Any_data *param_2,_Manager_operation param_3);
void std::__codecvt_abstract_base<>::out(__mbstate_t *param_1,wchar_t *param_2,wchar_t *param_3,wchar_t **param_4,char *param_5,char *param_6,char **param_7);
void std::__codecvt_abstract_base<>::in(__mbstate_t *param_1,char *param_2,char *param_3,char **param_4,wchar_t *param_5,wchar_t *param_6,wchar_t **param_7);
void __thiscall std::codecvt_utf8_utf16<>::~codecvt_utf8_utf16(codecvt_utf8_utf16<> *this);
void __thiscall std::codecvt_utf8_utf16<>::~codecvt_utf8_utf16(codecvt_utf8_utf16<> *this);
void __thiscall std::codecvt_utf8<>::~codecvt_utf8(codecvt_utf8<> *this);
void __thiscall std::codecvt_utf8<>::~codecvt_utf8(codecvt_utf8<> *this);
void __thiscall std::wstring_convert<>::~wstring_convert(wstring_convert<> *this);
void __thiscall std::vector<>::_M_default_append(vector<> *this,ulong param_1);
void __thiscall std::vector<>::_M_realloc_insert<>(vector<> *this,__normal_iterator param_1,string *param_2);
void InitSystemTime(ulong param_1);
void InitSystemBaseTimeTicks(ulong param_1);
undefined8 GetSystemBaseTicks(void);
long GetSystemTimeInTicks(void);
double GetSystemTime(void);
double GetSystemTimeFromTicks(ulong param_1);
double SystemTicksToSeconds(ulong param_1);
long GetSystemTicksFromTime(double param_1);
long SecondsToSystemTicks(double param_1);
undefined8 GetSystemTimeFrequency(void);
ulong NanosecondsFromSystemTicks(ulong param_1);
ulong SystemTicksFromNanoseconds(ulong param_1);
ulong MillisecondsFromNanoseconds(ulong param_1);
void SystemTimeSleep(uint param_1);
void SystemTimeSleepUntil(double param_1);
double GetClockRealtime(void);
void GetGMUnixTime(void);
time_t GetGMUnixTimeAtNextLocalTime(ulong param_1,int param_2,int param_3,int param_4);
ulong UnixTimeToDateString(ulong param_1);
ulong UnixTimeToDateAndTimeString(ulong param_1);
string * GetVRLogTimeString(bool param_1);
void GetFilenameTimeString(void);
void __thiscall CStopwatch::CStopwatch(CStopwatch *this);
void __thiscall CStopwatch::Start(CStopwatch *this);
void __thiscall CStopwatch::Stop(CStopwatch *this);
void __thiscall CStopwatch::Reset(CStopwatch *this);
float __thiscall CStopwatch::GetElapsedSeconds(CStopwatch *this);
long __thiscall CStopwatch::GetElapsedMs(CStopwatch *this);
void __thiscall CAssert::RemoveCallback(CAssert *this,CAssertCallback *param_1);
int CAssert::AssertMsgImpl(char *param_1,uint param_2,bool param_3,uint param_4,undefined param_5,undefined param_6,undefined param_7,...);
undefined * CAssert::GetInstance(void);
void __thiscall CAssertCallback::~CAssertCallback(CAssertCallback *this);
undefined8 __thiscall CAssert::AddCallback(CAssert *this,CAssertCallback *param_1);
undefined8 __thiscall CAssertCallback::Initialize(CAssertCallback *this,function param_1,void *param_2);
void __thiscall std::vector<>::_M_realloc_insert<>(vector<> *this,__normal_iterator param_1,CAssertCallback **param_2);
__off_t GetFileLength(char *param_1);
bool BFileExists(char *param_1);
undefined8 MakeFileWriteable(char *param_1);
bool UnlinkFile(char *param_1);
undefined8 BDeleteFileIfExists(char *param_1);
bool BRenameFile(char *param_1,char *param_2);
int GetFileCreateTime(char *param_1,long *param_2);
int GetFileWriteTime(char *param_1,long *param_2);
void CreateUserDataImageBuilder(void);
ulong BuildImage(UserDataImageBuilder *param_1,char *param_2,ulong param_3);
void GetUserDataHeaderPrefix(uint *param_1,uint *param_2);
bool GetUserDataHeader(uchar *param_1,ulong param_2,int *param_3,uint *param_4,uint *param_5);
bool SanityCheckUserDataHeader(int *param_1,uchar *param_2,ulong param_3);
ulong FindUserDataByName(uchar *param_1,ulong param_2,char *param_3,int *param_4);
bool ParseUserDataEntry(uchar *param_1,ulong param_2,int param_3,char **param_4,uint *param_5,uint *param_6,uint *param_7);
void DeleteUserDataImageBuilder(UserDataImageBuilder *param_1);
void SetUserData(UserDataImageBuilder *param_1,char *param_2,char *param_3,ulong param_4);
void __thiscall std::_Sp_counted_ptr<>::~_Sp_counted_ptr(_Sp_counted_ptr<> *this);
undefined8 std::_Sp_counted_ptr<>::_M_get_deleter(type_info *param_1);
void __thiscall std::_Sp_counted_ptr<>::~_Sp_counted_ptr(_Sp_counted_ptr<> *this);
void __thiscall std::_Sp_counted_ptr<>::_M_destroy(_Sp_counted_ptr<> *this);
void __thiscall std::_Sp_counted_ptr<>::_M_dispose(_Sp_counted_ptr<> *this);
void __thiscall std::_Rb_tree<>::_M_erase(_Rb_tree<> *this,_Rb_tree_node *param_1);
void __thiscall std::_Sp_counted_base<>::_M_release(_Sp_counted_base<> *this);
undefined  [16] __thiscall std::_Rb_tree<>::equal_range(_Rb_tree<> *this,string *param_1);
long __thiscall std::_Rb_tree<>::erase(_Rb_tree<> *this,string *param_1);
undefined  [16] __thiscall std::_Rb_tree<>::_M_get_insert_unique_pos(_Rb_tree<> *this,string *param_1);
undefined  [16] __thiscall std::_Rb_tree<>::_M_get_insert_hint_unique_pos(_Rb_tree<> *this,_Rb_tree_const_iterator param_1,string *param_2);
int detect_kernel_version(void);
uint parse_uevent_info(char *param_1,int *param_2,ushort *param_3,ushort *param_4,char **param_5,char **param_6);
wchar_t * utf8_to_wchar_t(char *param_1);
int get_device_string(hid_device_ *param_1,device_string_id param_2,wchar_t *param_3,ulong param_4);
undefined8 hid_init(void);
undefined8 hid_exit(void);
undefined8 * hid_enumerate(ushort param_1,ushort param_2);
void hid_free_enumeration(undefined8 *param_1);
int * hid_open_path(char *param_1);
long * hid_open(short param_1,short param_2,wchar_t *param_3);
void hid_write(int *param_1,void *param_2,size_t param_3);
int hid_read_timeout(int *param_1,void *param_2,size_t param_3,int param_4);
void hid_read(void);
undefined8 hid_set_nonblocking(long param_1,int param_2);
int hid_send_feature_report(int *param_1,undefined8 param_2,long param_3);
void hid_get_feature_report(int *param_1,undefined8 param_2,long param_3);
void hid_close(int *param_1);
void hid_get_manufacturer_string(hid_device_ *param_1,wchar_t *param_2,ulong param_3);
void hid_get_product_string(hid_device_ *param_1,wchar_t *param_2,ulong param_3);
void hid_get_serial_number_string(hid_device_ *param_1,wchar_t *param_2,ulong param_3);
undefined8 hid_get_indexed_string(void);
undefined8 hid_error(void);
bool __thiscall vortex::CHidDevice::CUsbRetryTimer::operator()(CUsbRetryTimer *this);
undefined8 __thiscall vortex::CHidDevice::HidDeviceIdentifier::operator==(HidDeviceIdentifier *this,HidDeviceIdentifier *param_1);
void std::string::_Rep::_M_dispose(allocator *param_1);
void std::wstring::_Rep::_M_dispose(allocator *param_1);
void __tcf_1(void);
void __tcf_2(void);
void __tcf_0(void);
void __thiscall vortex::CHidDevice::CHidDevice(CHidDevice *this);
void __thiscall vortex::CHidDevice::SetDevicePath(CHidDevice *this,uint param_1,uint param_2,string *param_3);
undefined4 __thiscall vortex::CHidDevice::ReadPacket(CHidDevice *this,uchar *param_1,int param_2,uint param_3,ulong *param_4);
bool __thiscall vortex::CHidDevice::SendSimpleMessage(CHidDevice *this,RequestType param_1,void *param_2,ulong param_3);
void __thiscall vortex::CHidDevice::CUsbRetryTimer::CUsbRetryTimer(CUsbRetryTimer *this,int param_1,int param_2,int param_3);
undefined8 __thiscall vortex::CHidDevice::CUsbRetryTimer::operator()(CUsbRetryTimer *this);
int __thiscall vortex::CHidDevice::GetFeatureReport(CHidDevice *this,FeatureID param_1,void *param_2,ulong param_3,int param_4);
undefined8 __thiscall vortex::CHidDevice::WriteFeatureReport(CHidDevice *this,FeatureID param_1,void *param_2,ulong param_3,int param_4);
undefined8 CompareSerialNumbers(wchar_t *param_1,wchar_t *param_2);
hid_device_info * concat_hid_device_info(hid_device_info *param_1,hid_device_info *param_2);
void __thiscall vortex::CHidDevice::Close(CHidDevice *this);
undefined8 __thiscall vortex::CHidDevice::ReleaseHidDevice(CHidDevice *this);
void vortex::CHidDevice::CloseReleasedHidDevice(hid_device_ *param_1);
undefined4 vortex::CHidDevice::GetAttachedDeviceCount(void);
undefined8 vortex::CHidDevice::GetAttachedDeviceInfo(int param_1,uint *param_2,uint *param_3,char *param_4,int param_5,char *param_6,int param_7);
undefined8 vortex::CHidDevice::GetAttachedDevicePath(int param_1,string *param_2);
string * vortex::CHidDevice::FindAttachedDeviceNth(ushort param_1,ushort param_2,string *param_3,int param_4);
ulong vortex::CHidDevice::FindAttachedDevice(uint param_1,uint param_2,char *param_3);
int vortex::CHidDevice::FindAttachedDevicePid(uint param_1,char *param_2,int param_3);
void __thiscall vortex::CHidDevice::SetDeviceID(CHidDevice *this,uint param_1,uint param_2,char *param_3,int param_4);
undefined8 vortex::CHidDevice::FindAttachedDeviceBySerial(uint *param_1,uint *param_2,char *param_3);
ulong __thiscall vortex::CHidDevice::HidDeviceIdentifier::operator<(HidDeviceIdentifier *this,HidDeviceIdentifier *param_1);
undefined8 __thiscall vortex::CHidDevice::HidDeviceIdentifier::operator==(HidDeviceIdentifier *this,HidDeviceIdentifier *param_1);
void fix_hid_device_interface_numbers(hid_device_info *param_1);
undefined8 __thiscall vortex::CHidDevice::Open(CHidDevice *this,bool param_1);
int vortex::CHidDevice::DetectDevices(bool param_1);
CHidDevice * __thiscall vortex::CHidDevice::GetAttachedLighthouseDevices(CHidDevice *this,LighthouseDeviceTypes param_1,bool param_2,bool param_3);
CHidDevice * __thiscall vortex::CHidDevice::GetAttachedLighthouseDevicesWithRetries(CHidDevice *this,LighthouseDeviceTypes param_1,bool param_2,int param_3);
void __thiscall std::vector<>::~vector(vector<> *this);
void __thiscall std::_Rb_tree<>::_M_erase(_Rb_tree<> *this,_Rb_tree_node *param_1);
void __thiscall std::vector<>::_M_realloc_insert<>(vector<> *this,__normal_iterator param_1,HidDeviceIdentifier *param_2);
__normal_iterator std::__find_if<>(__normal_iterator param_1,__normal_iterator param_2,_Iter_equals_val param_3,random_access_iterator_tag param_4);
undefined  [16] __thiscall std::_Rb_tree<>::_M_get_insert_unique_pos(_Rb_tree<> *this,tuple *param_1);
_Rb_tree_node_base * __thiscall std::_Rb_tree<>::_M_get_insert_hint_unique_pos(_Rb_tree<> *this,_Rb_tree_const_iterator param_1,tuple *param_2);
void vortex::UnpackControllerButtons(ulong param_1,ulong *param_2,ulong *param_3);
undefined8 __thiscall vortex::CLighthouseIMUThread::GetVRCVersion(CLighthouseIMUThread *this,uint *param_1);
void __thiscall vortex::CLighthouseIMUThread::GetVRCVersion(CLighthouseIMUThread *this,uint *param_1);
undefined8 __thiscall vortex::CLighthouseIMUThread::GetRadioVersion(CLighthouseIMUThread *this,uint *param_1);
void __thiscall vortex::CLighthouseIMUThread::GetRadioVersion(CLighthouseIMUThread *this,uint *param_1);
undefined8 __thiscall vortex::CLighthouseIMUThread::GetPeripheralApplicationVersion(CLighthouseIMUThread *this,uint *param_1);
void __thiscall vortex::CLighthouseIMUThread::GetPeripheralApplicationVersion(CLighthouseIMUThread *this,uint *param_1);
void vortex::CLighthouseIMUThread::OnHidPacketRate(uint param_1,double param_2);
undefined8 std::_Function_handler<>::_M_invoke(_Any_data *param_1);
undefined8 std::_Function_base::_Base_manager<>::_M_manager(_Any_data *param_1,_Any_data *param_2,_Manager_operation param_3);
undefined8 std::_Function_base::_Base_manager<>::_M_manager(_Any_data *param_1,_Any_data *param_2,_Manager_operation param_3);
undefined8 std::_Function_base::_Base_manager<>::_M_manager(_Any_data *param_1,_Any_data *param_2,_Manager_operation param_3);
void std::string::_Rep::_M_dispose(allocator *param_1);
bool __thiscall vortex::CLighthouseIMUThread::VrcTriggerHapticPulse(CLighthouseIMUThread *this,uint param_1,ushort param_2,ushort param_3,ushort param_4,uchar param_5);
void __thiscall vortex::CLighthouseIMUThread::VrcTriggerHapticPulse(CLighthouseIMUThread *this,uint param_1,ushort param_2,ushort param_3,ushort param_4,uchar param_5);
ulong __thiscall vortex::CLighthouseIMUThread::VrcCalibrateTrackpad(CLighthouseIMUThread *this);
void __thiscall vortex::CLighthouseIMUThread::VrcCalibrateTrackpad(CLighthouseIMUThread *this);
ulong __thiscall vortex::CLighthouseIMUThread::VrcCalibrateCapsense(CLighthouseIMUThread *this);
void __thiscall vortex::CLighthouseIMUThread::VrcCalibrateCapsense(CLighthouseIMUThread *this);
ulong __thiscall vortex::CLighthouseIMUThread::VrcSetTrackpadDebugEnable(CLighthouseIMUThread *this,bool param_1);
void __thiscall vortex::CLighthouseIMUThread::VrcSetTrackpadDebugEnable(CLighthouseIMUThread *this,bool param_1);
undefined8 __thiscall vortex::CLighthouseIMUThread::GetDongleVersion(CLighthouseIMUThread *this,uint *param_1);
bool __thiscall vortex::CLighthouseIMUThread::SetRadioMode(CLighthouseIMUThread *this,ERadioMode param_1);
undefined8 __thiscall vortex::CLighthouseIMUThread::DongleUnpair(CLighthouseIMUThread *this);
uint __thiscall vortex::CLighthouseIMUThread::VrcSetPrngEntropy(CLighthouseIMUThread *this);
undefined8 std::_Function_handler<>::_M_invoke(_Any_data *param_1);
undefined8 std::_Function_handler<>::_M_invoke(_Any_data *param_1);
undefined8 __thiscall vortex::CLighthouseIMUThread::GetWatchmanFirmwareVersionString(CLighthouseIMUThread *this,string *param_1);
void __thiscall vortex::CLighthouseThreadBase::CLighthouseThreadBase(CLighthouseThreadBase *this,CTime *param_1,char *param_2,int param_3,ushort param_4,ushort param_5);
CLighthouseThreadBase __thiscall vortex::CLighthouseThreadBase::WaitForFirstOpenAttempt(CLighthouseThreadBase *this,double param_1);
void vortex::CLighthouseThreadBase::DeviceAttached(void);
void vortex::CLighthouseThreadBase::SetRateMeasurementInterval(int param_1);
undefined  [16] __thiscall vortex::CLighthouseThreadBase::HandleUnknownReportId(CLighthouseThreadBase *this,uchar *param_1);
void __thiscall vortex::CLighthouseIMUThread::CLighthouseIMUThread(CLighthouseIMUThread *this,CTime *param_1,ICallback *param_2,char *param_3);
undefined8 __thiscall vortex::CLighthouseIMUThread::RequestWirelessProtocolVersion(CLighthouseIMUThread *this,EWatchmanWirelessProtocolVersion param_1);
void vortex::CLighthouseIMUThread::ProcessUsbSofMeasurement(ushort param_1,double param_2,bool param_3);
void __thiscall vortex::CLighthouseIMUThread::RetryWirelessProtocolVersionRequest(CLighthouseIMUThread *this,double param_1);
undefined8 vortex::CLighthouseIMUThread::ProcessWirelessProtocolVersionRequest(_Watchman_Wireless_Packet_t *param_1,long *param_2);
void __thiscall vortex::CLighthouseIMUThread::ResetDeviceSpecificState(CLighthouseIMUThread *this);
undefined4 __thiscall vortex::CLighthouseIMUThread::GetIMUConfig(CLighthouseIMUThread *this,_Watchman_Feature_IMUMode_t *param_1);
CLighthouseIMUThread __thiscall vortex::CLighthouseIMUThread::IsWirelessConnected(CLighthouseIMUThread *this);
undefined4 __thiscall vortex::CLighthouseIMUThread::SendCurrentSampleModeAndVersion(CLighthouseIMUThread *this);
void __thiscall vortex::CLighthouseIMUThread::SetSyncDetectMode(CLighthouseIMUThread *this,ESyncDetectMode param_1);
undefined8 __thiscall vortex::CLighthouseIMUThread::SetSensorScheduleMode(CLighthouseIMUThread *this,ESensorSchedule param_1);
bool __thiscall vortex::CLighthouseIMUThread::GetSensorScheduleMode(CLighthouseIMUThread *this,uchar *param_1);
undefined4 __thiscall vortex::CLighthouseIMUThread::GetLighthouseErrorReport(CLighthouseIMUThread *this,_lighthouse_errors *param_1);
void __thiscall vortex::CLighthouseIMUThread::StartInSystemProgramming(CLighthouseIMUThread *this);
void __thiscall vortex::CLighthouseIMUThread::RequestFpgaReset(CLighthouseIMUThread *this);
undefined8 __thiscall vortex::CLighthouseIMUThread::GetWatchmanHMDStatus(CLighthouseIMUThread *this,Watchman_Feature_HMDStatus_t *param_1);
undefined8 __thiscall vortex::CLighthouseIMUThread::GetWatchmanStatus(CLighthouseIMUThread *this,Watchman_Feature_WatchmanStatus_t *param_1);
uint __thiscall vortex::CLighthouseIMUThread::GetWatchmanDeviceConsoleLogString(CLighthouseIMUThread *this,string *param_1);
undefined8 __thiscall vortex::CLighthouseIMUThread::ReadWatchmanVersion(CLighthouseIMUThread *this);
void __thiscall vortex::CLighthouseIMUThread::UpdateWatchmanVersion(CLighthouseIMUThread *this);
undefined8 __thiscall vortex::CLighthouseIMUThread::GetWatchmanVersion(CLighthouseIMUThread *this,uint *param_1,uint *param_2,char *param_3,ulong param_4,char *param_5,ulong param_6);
undefined8 __thiscall vortex::CLighthouseIMUThread::GetWatchmanFirmwareVersionString(CLighthouseIMUThread *this,string *param_1);
undefined8 __thiscall vortex::CLighthouseIMUThread::GetWatchmanHardwareRevisionString(CLighthouseIMUThread *this,string *param_1);
undefined8 __thiscall vortex::CLighthouseIMUThread::GetWatchmanHardwareRevision(CLighthouseIMUThread *this,uint *param_1);
uint __thiscall vortex::CLighthouseIMUThread::GetSensorType(CLighthouseIMUThread *this);
undefined8 __thiscall vortex::CLighthouseIMUThread::GetWatchmanFirmwareVersion(CLighthouseIMUThread *this,uint *param_1);
undefined8 __thiscall vortex::CLighthouseIMUThread::GetWatchmanFPGAVersion(CLighthouseIMUThread *this,uint *param_1);
undefined8 __thiscall vortex::CLighthouseIMUThread::GetDongleVersion(CLighthouseIMUThread *this,uint *param_1);
undefined8 __thiscall vortex::CLighthouseIMUThread::SetRadioMode(CLighthouseIMUThread *this,ERadioMode param_1);
undefined8 __thiscall vortex::CLighthouseIMUThread::GetRadioMode(CLighthouseIMUThread *this,ERadioMode *param_1);
undefined8 __thiscall vortex::CLighthouseIMUThread::GetEdidId(CLighthouseIMUThread *this,uchar *param_1);
uint __thiscall vortex::CLighthouseIMUThread::SetEdidId(CLighthouseIMUThread *this,uchar param_1);
undefined8 __thiscall vortex::CLighthouseIMUThread::VideoConfig_t::SetDisplayPortTrainingMode(VideoConfig_t *this,int param_1);
undefined8 __thiscall vortex::CLighthouseIMUThread::GetVideoConfig(CLighthouseIMUThread *this,VideoConfig_t *param_1);
uint __thiscall vortex::CLighthouseIMUThread::SetVideoConfig(CLighthouseIMUThread *this,VideoConfig_t *param_1);
undefined8 __thiscall vortex::CLighthouseIMUThread::GetBacklightGain(CLighthouseIMUThread *this,float *param_1);
uint __thiscall vortex::CLighthouseIMUThread::SetBacklightGain(CLighthouseIMUThread *this,float param_1);
undefined8 __thiscall vortex::CLighthouseIMUThread::GetPanelColumnCorrection(CLighthouseIMUThread *this,panel_column_correction_t *param_1,panel_column_correction_t *param_2);
uint __thiscall vortex::CLighthouseIMUThread::SetPanelColumnCorrection(CLighthouseIMUThread *this,panel_column_correction_t *param_1,panel_column_correction_t *param_2);
undefined8 __thiscall vortex::CLighthouseIMUThread::GetPanelStats(CLighthouseIMUThread *this,panel_stats_t *param_1);
undefined8 __thiscall vortex::CLighthouseIMUThread::GetDisplayMetrics(CLighthouseIMUThread *this,display_metrics_page0_v1_t *param_1);
undefined8 __thiscall vortex::CLighthouseIMUThread::GetDisplayMetrics(CLighthouseIMUThread *this,display_metrics_page1_v1_t *param_1);
uint __thiscall vortex::CLighthouseIMUThread::SetHMDMuteState(CLighthouseIMUThread *this,HmdMuteState_s *param_1);
undefined8 __thiscall vortex::CLighthouseIMUThread::GetHMDMuteState(CLighthouseIMUThread *this,HmdMuteState_s *param_1);
void __thiscall vortex::EdidInfoVec_t::DropNonSoloEdids(EdidInfoVec_t *this);
undefined8 __thiscall vortex::EdidInfoVec_t::BContainsEdidId(EdidInfoVec_t *this,uchar param_1);
uint __thiscall vortex::CLighthouseIMUThread::WriteFPGARegister(CLighthouseIMUThread *this,uchar param_1,ushort param_2);
undefined8 __thiscall vortex::CLighthouseIMUThread::ReadFPGARegister(CLighthouseIMUThread *this,uchar param_1,ushort *param_2);
undefined8 __thiscall vortex::CLighthouseIMUThread::SetISPSyncDivisor(CLighthouseIMUThread *this,uchar param_1);
undefined8 __thiscall vortex::CLighthouseIMUThread::GetISPSyncDivisor(CLighthouseIMUThread *this,uchar *param_1);
undefined8 __thiscall vortex::CLighthouseIMUThread::TriggerWirelessPairing(CLighthouseIMUThread *this,bool param_1);
undefined8 __thiscall vortex::CLighthouseIMUThread::DongleUnpair(CLighthouseIMUThread *this);
bool __thiscall vortex::CLighthouseIMUThread::Reboot(CLighthouseIMUThread *this,WatchmanRebootRequestType_t param_1);
undefined4 __thiscall vortex::CLighthouseIMUThread::GetWirelessPacketsPerSecond(CLighthouseIMUThread *this);
undefined8 __thiscall vortex::CLighthouseIMUThread::UpdateIMURangeMode(CLighthouseIMUThread *this);
void __thiscall vortex::CLighthouseIMUThread::ClearTrackingCallback(CLighthouseIMUThread *this,void *param_1);
void __thiscall vortex::CLighthouseIMUThread::ClearVrcCallback(CLighthouseIMUThread *this,void *param_1);
void __thiscall vortex::CLighthouseIMUThread::ClearMonitorCallback(CLighthouseIMUThread *this,void *param_1);
void __thiscall vortex::CLighthouseIMUThread::ClearAuxEventCallback(CLighthouseIMUThread *this,void *param_1);
void __thiscall vortex::CLighthouseIMUThread::RemoveImuCallbacks(CLighthouseIMUThread *this,void *param_1);
void __thiscall vortex::CLighthouseIMUThread::SetTrackingCallback(CLighthouseIMUThread *this,void *param_1,ICallback *param_2);
void __thiscall vortex::CLighthouseIMUThread::SetVrcCallback(CLighthouseIMUThread *this,void *param_1,IVrcCallback *param_2);
void __thiscall vortex::CLighthouseIMUThread::SetMonitorCallback(CLighthouseIMUThread *this,void *param_1,IMonitorCallback *param_2);
void __thiscall vortex::CLighthouseIMUThread::SetAuxEventCallback(CLighthouseIMUThread *this,void *param_1,IAuxEventCallback *param_2);
vortex * __thiscall vortex::GetWatchmanPowerLevelMagicStr(vortex *this,EPowerLevel param_1);
bool __thiscall vortex::CLighthouseIMUThread::VrcSetPowerLevel(CLighthouseIMUThread *this,EPowerLevel param_1);
void __thiscall vortex::CLighthouseIMUThread::VrcSetPowerLevel(CLighthouseIMUThread *this,EPowerLevel param_1);
undefined8 __thiscall vortex::CLighthouseIMUThread::VrcSetPrngEntropy(CLighthouseIMUThread *this);
char __thiscall vortex::CLighthouseIMUThread::GetWirelessDongleType(CLighthouseIMUThread *this);
ulong __thiscall vortex::CLighthouseIMUThread::GetWirelessDongleAttributes(CLighthouseIMUThread *this);
void vortex::CLighthouseIMUThread::TriggerUnhandledCallback(Unhandled param_1);
uint __thiscall vortex::CLighthouseIMUThread::RefreshForKeepAlive(CLighthouseIMUThread *this);
void __thiscall vortex::CLighthouseIMUThread::OnHidKeepalive(CLighthouseIMUThread *this);
undefined8 __thiscall vortex::CLighthouseIMUThread::SendDonglePairingMessage(CLighthouseIMUThread *this,int param_1,bool param_2);
undefined8 __thiscall vortex::CLighthouseIMUThread::TriggerDonglePairing(CLighthouseIMUThread *this,int param_1,bool param_2);
undefined8 __thiscall vortex::CLighthouseIMUThread::StopDonglePairing(CLighthouseIMUThread *this);
uint __thiscall vortex::CLighthouseIMUThread::SetLedSchedule(CLighthouseIMUThread *this,qpd_cmd_schedule_t *param_1);
uint __thiscall vortex::CLighthouseIMUThread::SetLedEmitterConfig(CLighthouseIMUThread *this,uchar param_1,uint param_2);
uint __thiscall vortex::CLighthouseIMUThread::SetLedSequence(CLighthouseIMUThread *this,signed *param_1,uchar param_2);
ulong __thiscall vortex::CLighthouseIMUThread::StartOtgt(CLighthouseIMUThread *this);
undefined8 __thiscall vortex::CLighthouseIMUThread::GetOtgtResults(CLighthouseIMUThread *this,WatchmanOtgtResults_t *param_1);
void __thiscall vortex::CLighthouseOpticalThread::CLighthouseOpticalThread(CLighthouseOpticalThread *this,CTime *param_1,ICallback *param_2,char *param_3);
void __thiscall vortex::CLighthouseOpticalThread::DispatchSampleEvent(CLighthouseOpticalThread *this,int param_1,double param_2,double param_3);
ulong __thiscall vortex::CLighthouseThreadBase::CTime::ExtendTimestamp(CTime *this,uint param_1,int param_2);
double vortex::CLighthouseOpticalThread::ProcessReportV1(_Watchman_OpticalReport_t *param_1,double param_2);
double vortex::CLighthouseOpticalThread::ProcessReportV2(_Watchman_OpticalReport_v2_t *param_1,double param_2);
double vortex::CLighthouseOpticalThread::ProcessReportV3(_Watchman_OpticalReport_v3_t *param_1,double param_2,bool param_3);
void __thiscall vortex::CLighthouseOpticalThread::ProcessReportV3b(CLighthouseOpticalThread *this,_Watchman_OpticalReport_v3b_t *param_1,double param_2);
void vortex::CLighthouseOpticalThread::ProcessReportV4(_Watchman_OpticalReport_v4_t *param_1,double param_2);
void vortex::CLighthouseOpticalThread::OnHidPacket(uchar *param_1,int param_2,double param_3,bool param_4);
ulong __thiscall vortex::CLighthouseThreadBase::CTime::ExtendTrackingTimestamp(CTime *this,uint param_1,int param_2);
double __thiscall vortex::CLighthouseThreadBase::CTime::TimeFromTimestamp(CTime *this,long param_1);
double __thiscall vortex::CLighthouseThreadBase::CTime::TrackingTimeFromTimestamp(CTime *this,long param_1);
void __thiscall vortex::CLighthouseThreadBase::CTime::UpdateUsbTime(CTime *this,double param_1,double param_2);
void __thiscall vortex::CLighthouseThreadBase::CTime::UpdateTrackingTime(CTime *this,double param_1,double param_2,bool param_3);
double __thiscall vortex::CLighthouseThreadBase::CTime::GetTrackingTimeOffset(CTime *this,CTime *param_1);
undefined8 vortex::UnzipChunkAndAppend(z_stream_s *param_1,uchar *param_2,ulong param_3,string *param_4);
undefined8 vortex::WriteUSBConfig(CHidDevice *param_1,string *param_2);
void __thiscall vortex::CLighthouseIMUThread::WriteConfig(CLighthouseIMUThread *this,string *param_1);
undefined4 vortex::WriteUSBConfig(uint param_1,uint param_2,char *param_3,string *param_4);
void vortex::CLighthouseInput::NotifyWirelessDisconnection(CLighthouseIMUThread *param_1);
void vortex::CLighthouseInput::NotifyWiredConnectionChange(CLighthouseThreadBase *param_1);
void __thiscall vortex::CLighthouseOpticalThread::OnHidOpen(CLighthouseOpticalThread *this);
void __thiscall vortex::CLighthouseOpticalThread::OnHidClose(CLighthouseOpticalThread *this);
void __thiscall vortex::CLighthouseIMUThread::OnHidClose(CLighthouseIMUThread *this);
undefined4 vortex::CLighthouseInput::GetAttachedDeviceId(string *param_1);
void __thiscall vortex::CLighthouseInput::CLighthouseInput(CLighthouseInput *this,string *param_1);
char __thiscall vortex::CLighthouseInput::IsRunning(CLighthouseInput *this);
ulong __thiscall vortex::CLighthouseInput::IsHidOpen(CLighthouseInput *this);
void vortex::CLighthouseInput::OnWirelessDisconnect(void);
undefined8 __thiscall vortex::CLighthouseInput::IsDeviceConnected(CLighthouseInput *this);
void __thiscall vortex::CLighthouseInput::CConnection::CConnection(CConnection *this,string *param_1);
long __thiscall vortex::CLighthouseInput::CConnection::GetVrcInterface(CConnection *this);
ulong __thiscall vortex::CLighthouseInput::CConnection::GetWirelessDongleSerialNumber(CConnection *this,string *param_1);
undefined8 vortex::CLighthouseInput::CConnection::SetPowerLevel(EPowerLevel param_1);
CLighthouseThreadBase * __thiscall vortex::CLighthouseThreadBase::GetRateStatusReport(CLighthouseThreadBase *this);
void vortex::CLighthouseIMUThread::GetWirelessDongleFirmwareVersionString(void);
void __thiscall vortex::CLighthouseIMUThread::DeliverImuSample(CLighthouseIMUThread *this,_Watchman_IMUSample_t *param_1,long param_2);
void __thiscall vortex::CLighthouseIMUThread::ProcessReport(CLighthouseIMUThread *this,_Watchman_IMUReport_t *param_1,double param_2,bool param_3);
uint __thiscall vortex::CLighthouseIMUThread::ProcessWirelessPacketWithDecoder(CLighthouseIMUThread *this,CWirelessDecoder *param_1,_Watchman_Wireless_Packet_t *param_2,long *param_3);
undefined8 __thiscall vortex::CLighthouseIMUThread::ProcessWirelessPacket(CLighthouseIMUThread *this,_Watchman_Wireless_Packet_t *param_1,long *param_2);
void __thiscall vortex::CLighthouseIMUThread::ProcessReport(CLighthouseIMUThread *this,_Watchman_WirelessReport_t *param_1,double param_2,bool param_3);
void __thiscall vortex::CLighthouseIMUThread::OnHidPacket(CLighthouseIMUThread *this,uchar *param_1,int param_2,double param_3,bool param_4);
vortex * __thiscall vortex::DecodeAnalogixAudioStreamStatus(vortex *this,audio_stream_status_t param_1);
undefined8 vortex::CLighthouseIMUThread::GetWatchmanHMDStatusString(void);
undefined8 __thiscall vortex::CLighthouseIMUThread::GetWatchmanDeviceFlashLogString(CLighthouseIMUThread *this,string *param_1);
vortex * __thiscall vortex::FlashLogInterpretFuelGaugeReset(vortex *this,uchar *param_1);
vortex * __thiscall vortex::FlashLogInterpretVideoFailure(vortex *this,uchar *param_1);
vortex * __thiscall vortex::FlashLogInterpretFwUpdateInfo(vortex *this,uchar *param_1);
vortex * __thiscall vortex::FlashLogInterpretRunningState(vortex *this,uchar *param_1);
vortex * __thiscall vortex::FlashLogInterpretInitState(vortex *this,uchar *param_1);
vortex * __thiscall vortex::FlashLogInterpretUint32(vortex *this,uchar *param_1);
vortex * __thiscall vortex::FlashLogInterpretAssert(vortex *this,uchar *param_1);
void vortex::EdidInfoVec_t::FindEdidWithNearestRefresh(float param_1);
ulong __thiscall vortex::CLighthouseIMUThread::GetUserDataHeader(CLighthouseIMUThread *this,vector *param_1);
void __thiscall vortex::CLighthouseThreadBase::Start(CLighthouseThreadBase *this);
undefined8 __thiscall vortex::CLighthouseInput::Start(CLighthouseInput *this);
void __thiscall vortex::CLighthouseThreadBase::Stop(CLighthouseThreadBase *this);
void __thiscall vortex::CLighthouseInput::~CLighthouseInput(CLighthouseInput *this);
undefined8 __thiscall vortex::CLighthouseInput::Stop(CLighthouseInput *this);
void __thiscall vortex::CLighthouseInput::CConnection::Disconnect(CConnection *this);
void __thiscall vortex::CLighthouseInput::CConnection::~CConnection(CConnection *this);
undefined8 __thiscall vortex::CLighthouseIMUThread::EnumerateEdids(CLighthouseIMUThread *this,EdidInfoVec_t *param_1);
void __thiscall vortex::CLighthouseIMUThread::AddImuCallback(CLighthouseIMUThread *this,void *param_1,IImuCallback *param_2);
void __thiscall vortex::CLighthouseInput::CConnection::ConfigureInput(CConnection *this);
void __thiscall vortex::CLighthouseInput::CConnection::SetImuCallback(CConnection *this,ICallback *param_1);
void __thiscall vortex::CLighthouseInput::CConnection::SetVrcCallback(CConnection *this,IVrcCallback *param_1);
void __thiscall vortex::CLighthouseInput::CConnection::SetMonitorCallback(CConnection *this,IMonitorCallback *param_1);
void __thiscall vortex::CLighthouseInput::CConnection::SetOpticalCallback(CConnection *this,ICallback *param_1,ESyncDetectMode param_2);
void __thiscall vortex::CLighthouseInput::CConnection::SetAuxEventCallback(CConnection *this,IAuxEventCallback *param_1);
void __thiscall vortex::CLighthouseInput::CConnection::SetRawImuCallback(CConnection *this,IImuCallback *param_1);
undefined8 vortex::ReadUSBUserDataMaxAllocatedSizeCore(CHidDevice *param_1,int *param_2);
bool __thiscall vortex::CLighthouseIMUThread::ReadUSBUserDataMaxAllocatedSize(CLighthouseIMUThread *this,int *param_1);
undefined8 vortex::ReadUSBConfig(CHidDevice *param_1,string *param_2,bool param_3);
bool __thiscall vortex::CLighthouseIMUThread::ReadConfig(CLighthouseIMUThread *this,string *param_1);
int vortex::ReadUSBConfig(uint param_1,uint param_2,char *param_3,string *param_4,bool param_5,int param_6);
void vortex::ReadUSBConfig(CLighthouseThreadBase *param_1,string *param_2,bool param_3);
void vortex::CLighthouseInput::NotifyWiredDevicePresent(string *param_1);
CLighthouseInput * __thiscall vortex::CLighthouseInput::GetAllWirelessDongleDescriptions(CLighthouseInput *this);
int vortex::ReadUSBUserDataCore(CHidDevice *param_1,uint param_2,uint param_3,int param_4,vector *param_5,function param_6);
ulong __thiscall vortex::CLighthouseIMUThread::ReadUserData(CLighthouseIMUThread *this,uint param_1,uint param_2,vector *param_3);
int vortex::ReadUserDataHeaderCore(CHidDevice *param_1,vector *param_2);
void __thiscall vortex::CLighthouseIMUThread::LoadUserDataHeader(CLighthouseIMUThread *this);
char vortex::VerifyUSBUserDataInDirectoryCore(bool *param_1,CHidDevice *param_2,vector *param_3,char *param_4,int param_5,function param_6);
undefined4 __thiscall vortex::CLighthouseIMUThread::VerifyUSBUserDataInDirectory(CLighthouseIMUThread *this,bool *param_1,string *param_2,int param_3,function param_4);
long vortex::CLighthouseInput::GetBySerialNumber(string *param_1,bool param_2);
undefined8 __thiscall vortex::CLighthouseInput::CConnection::BNeedReconnection(CConnection *this);
undefined8 __thiscall vortex::CLighthouseInput::CConnection::ConnectOrReconnect(CConnection *this);
undefined8 vortex::CLighthouseInput::GetByWiredSerialNumber(string *param_1);
void vortex::CLighthouseInput::NotifyWirelessConnection(string *param_1,bool param_2,CLighthouseInput *param_3);
char __thiscall vortex::CLighthouseIMUThread::VrcGetAttributesValues(CLighthouseIMUThread *this);
undefined8 __thiscall vortex::CLighthouseIMUThread::VrcGetAttributesValues(CLighthouseIMUThread *this);
void __thiscall vortex::CLighthouseIMUThread::OnHidOpen(CLighthouseIMUThread *this);
void vortex::CLighthouseInput::SetAttachedDeviceId(string *param_1,uint param_2);
void vortex::EdidInfoVec_t::GetAvailableRefreshRates(void);
undefined8 CWirelessDecoder::GetOpticalSubprotocolVersion(void);
undefined8 CWirelessDecoder::GetControllerSubprotocolVersion(void);
void vortex::CLighthouseThreadBase::OnHidOpen(void);
void vortex::CLighthouseThreadBase::OnHidClose(void);
void vortex::CLighthouseThreadBase::OnHidKeepalive(void);
void vortex::CLighthouseThreadBase::OnHidPacketRate(uint param_1,double param_2);
undefined8 vortex::CLighthouseThreadBase::GetKeepaliveTime(void);
undefined * vortex::CLighthouseIMUThread::GetThreadName(void);
undefined8 vortex::CLighthouseIMUThread::GetPollingTime(void);
undefined8 __thiscall vortex::CLighthouseIMUThread::GetKeepaliveTime(CLighthouseIMUThread *this);
char * vortex::CLighthouseOpticalThread::GetThreadName(void);
undefined8 vortex::CLighthouseOpticalThread::GetPollingTime(void);
void __thiscall vortex::CLighthouseUsbThread::~CLighthouseUsbThread(CLighthouseUsbThread *this);
void __thiscall vortex::CLighthouseUsbThread::~CLighthouseUsbThread(CLighthouseUsbThread *this);
void __thiscall CWirelessDecoder::Reset(CWirelessDecoder *this);
void __thiscall CWirelessDecoder::~CWirelessDecoder(CWirelessDecoder *this);
void __thiscall CWirelessDecoder::~CWirelessDecoder(CWirelessDecoder *this);
string * vortex::CLighthouseUsbThread::GetRateStatusReport(void);
vector<> * __thiscall std::vector<>::operator=(vector<> *this,vector *param_1);
vector<> * __thiscall std::vector<>::operator=(vector<> *this,vector *param_1);
vector<> * __thiscall std::vector<>::operator=(vector<> *this,vector *param_1);
vector<> * __thiscall std::vector<>::operator=(vector<> *this,vector *param_1);
void __thiscall std::function<bool()>::function(function<bool()> *this,function *param_1);
void __thiscall std::vector<>::_M_realloc_insert<>(vector<> *this,__normal_iterator param_1,lighthouse_t *param_2);
void __thiscall std::vector<>::_M_realloc_insert<>(vector<> *this,__normal_iterator param_1,hid_device_ **param_2);
void __thiscall vortex::CLighthouseOpticalThread::~CLighthouseOpticalThread(CLighthouseOpticalThread *this);
void __thiscall vortex::CLighthouseOpticalThread::~CLighthouseOpticalThread(CLighthouseOpticalThread *this);
void __thiscall vortex::CLighthouseIMUThread::~CLighthouseIMUThread(CLighthouseIMUThread *this);
void __thiscall vortex::CLighthouseIMUThread::~CLighthouseIMUThread(CLighthouseIMUThread *this);
void __thiscall std::vector<>::_M_realloc_insert<>(vector<> *this,__normal_iterator param_1,float *param_2);
void __thiscall std::vector<>::_M_realloc_insert<>(vector<> *this,__normal_iterator param_1,Edid_t *param_2);
void __thiscall std::vector<>::_M_realloc_insert<>(vector<> *this,__normal_iterator param_1,ImuCallbackEntry_t *param_2);
void __thiscall std::vector<>::_M_fill_insert(vector<> *this,__normal_iterator param_1,ulong param_2,uchar *param_3);
void __thiscall std::_Rb_tree<>::_M_erase(_Rb_tree<> *this,_Rb_tree_node *param_1);
void __thiscall std::map<>::~map(map<> *this);
void __thiscall std::_Rb_tree<>::_M_erase(_Rb_tree<> *this,_Rb_tree_node *param_1);
void __thiscall std::map<>::~map(map<> *this);
_Rb_tree<> * __thiscall std::_Rb_tree<>::find(_Rb_tree<> *this,string *param_1);
pair __thiscall std::_Rb_tree<>::_M_insert_unique<>(_Rb_tree<> *this,string *param_1);
void std::vector<>::_M_range_insert<>(__normal_iterator param_1,__normal_iterator param_2,__normal_iterator param_3,forward_iterator_tag param_4);
undefined  [16] __thiscall std::_Rb_tree<>::_M_get_insert_unique_pos(_Rb_tree<> *this,string *param_1);
_Rb_tree_node * __thiscall std::_Rb_tree<>::_M_insert_node(_Rb_tree<> *this,_Rb_tree_node_base *param_1,_Rb_tree_node_base *param_2,_Rb_tree_node *param_3);
pair __thiscall std::_Rb_tree<>::_M_emplace_unique<>(_Rb_tree<> *this,pair *param_1);
undefined  [16] __thiscall std::_Rb_tree<>::_M_get_insert_hint_unique_pos(_Rb_tree<> *this,_Rb_tree_const_iterator param_1,string *param_2);
_Rb_tree_iterator std::_Rb_tree<>::_M_emplace_hint_unique<>(_Rb_tree_const_iterator param_1,piecewise_construct_t *param_2,tuple *param_3,tuple *param_4);
void std::__insertion_sort<>(__normal_iterator param_1,__normal_iterator param_2,_Iter_less_iter param_3);
undefined  [16] __thiscall std::_Rb_tree<>::_M_get_insert_unique_pos(_Rb_tree<> *this,string *param_1);
undefined  [16] __thiscall std::_Rb_tree<>::_M_get_insert_hint_unique_pos(_Rb_tree<> *this,_Rb_tree_const_iterator param_1,string *param_2);
_Rb_tree_iterator std::_Rb_tree<>::_M_emplace_hint_unique<>(_Rb_tree_const_iterator param_1,piecewise_construct_t *param_2,tuple *param_3,tuple *param_4);
void std::__adjust_heap<>(__normal_iterator param_1,long param_2,long param_3,float param_4,_Iter_less_iter param_5);
void std::__introsort_loop<>(__normal_iterator param_1,__normal_iterator param_2,long param_3,_Iter_less_iter param_4);
void vortex::CSysTimer::Init(void);
void vortex::CSysTimer::TickCount(void);
void vortex::CSysTimer::Init(void);
void __thiscall vortex::CSysTimer::~CSysTimer(CSysTimer *this);
void __thiscall vortex::CVortexReadWriteLock::~CVortexReadWriteLock(CVortexReadWriteLock *this);
void __thiscall vortex::CVortexReadWriteLock::EnterRead(CVortexReadWriteLock *this);
void __thiscall vortex::CVortexReadWriteLock::LeaveRead(CVortexReadWriteLock *this);
void __thiscall vortex::CVortexReadWriteLock::EnterWrite(CVortexReadWriteLock *this);
void __thiscall vortex::CVortexReadWriteLock::LeaveWrite(CVortexReadWriteLock *this);
void __thiscall vortex::CVortexMutex::CVortexMutex(CVortexMutex *this);
void __thiscall vortex::CVortexMutex::CVortexMutex(CVortexMutex *this,int param_1);
void __thiscall vortex::CVortexMutex::~CVortexMutex(CVortexMutex *this);
void __thiscall vortex::CVortexMutex::Enter(CVortexMutex *this);
void __thiscall vortex::CVortexMutex::Leave(CVortexMutex *this);
void __thiscall vortex::CVortexConditionVariable::CVortexConditionVariable(CVortexConditionVariable *this);
void __thiscall vortex::CVortexConditionVariable::~CVortexConditionVariable(CVortexConditionVariable *this);
void __thiscall vortex::CVortexConditionVariable::Wake(CVortexConditionVariable *this);
void __thiscall vortex::CVortexConditionVariable::WakeAll(CVortexConditionVariable *this);
undefined8 __thiscall vortex::CVortexConditionVariable::Wait(CVortexConditionVariable *this,CVortexMutex *param_1,uint param_2);
undefined8 __thiscall vortex::CVortexConditionVariable::Wait(CVortexConditionVariable *this,CVortexMutexLock *param_1,uint param_2);
undefined8 vortex::CVortexConditionVariable::Wait(CVortexReadWriteLock *param_1,bool param_2,uint param_3);
undefined8 vortex::CVortexConditionVariable::Wait(CVortexReadLock *param_1,uint param_2);
undefined8 vortex::CVortexConditionVariable::Wait(CVortexWriteLock *param_1,uint param_2);
void __thiscall vortex::CVortexSemaphore::CVortexSemaphore(CVortexSemaphore *this,bool param_1);
void __thiscall vortex::CVortexSemaphore::~CVortexSemaphore(CVortexSemaphore *this);
void __thiscall vortex::CVortexSemaphore::Set(CVortexSemaphore *this);
void vortex::CVortexSemaphore::Reset(void);
void vortex::CVortexSemaphore::Wait(uint param_1);
undefined8 vortex::CVortexThread::SetCurrentThreadPriority(int param_1);
void vortex::CVortexThread::SetCurrentThreadDebugName(char *param_1);
void vortex::CVortexThread::Sleep(uint param_1);
void __thiscall vortex::CVortexThread::CVortexThread(CVortexThread *this);
void __thiscall vortex::CVortexThread::~CVortexThread(CVortexThread *this);
void __thiscall vortex::CVortexThread::~CVortexThread(CVortexThread *this);
void __thiscall vortex::CVortexThread::Start(CVortexThread *this);
undefined8 __thiscall vortex::CVortexThread::WaitStopped(CVortexThread *this,uint param_1);
int __thiscall vortex::CVortexThread::GetPriority(CVortexThread *this);
bool __thiscall vortex::CVortexThread::SetPriority(CVortexThread *this,int param_1);
undefined8 __thiscall vortex::CVortexThread::IsCurrent(CVortexThread *this);
undefined8 vortex::CThreadHelper::ThreadCallback(void *param_1);
undefined8 __thiscall vortex::CVrControllerUsbThread::GetVRCVersion(CVrControllerUsbThread *this,uint *param_1);
void __thiscall vortex::CVrControllerUsbThread::GetVRCVersion(CVrControllerUsbThread *this,uint *param_1);
undefined8 __thiscall vortex::CVrControllerUsbThread::GetRadioVersion(CVrControllerUsbThread *this,uint *param_1);
void __thiscall vortex::CVrControllerUsbThread::GetRadioVersion(CVrControllerUsbThread *this,uint *param_1);
undefined8 __thiscall vortex::CVrControllerUsbThread::GetPeripheralApplicationVersion(CVrControllerUsbThread *this,uint *param_1);
void __thiscall vortex::CVrControllerUsbThread::GetPeripheralApplicationVersion(CVrControllerUsbThread *this,uint *param_1);
bool __thiscall vortex::CVrControllerUsbThread::VrcTriggerHapticPulse(CVrControllerUsbThread *this,uint param_1,ushort param_2,ushort param_3,ushort param_4,uchar param_5);
void __thiscall vortex::CVrControllerUsbThread::VrcTriggerHapticPulse(CVrControllerUsbThread *this,uint param_1,ushort param_2,ushort param_3,ushort param_4,uchar param_5);
bool __thiscall vortex::CVrControllerUsbThread::VrcCalibrateTrackpad(CVrControllerUsbThread *this);
void __thiscall vortex::CVrControllerUsbThread::VrcCalibrateTrackpad(CVrControllerUsbThread *this);
bool __thiscall vortex::CVrControllerUsbThread::VrcCalibrateCapsense(CVrControllerUsbThread *this);
void __thiscall vortex::CVrControllerUsbThread::VrcCalibrateCapsense(CVrControllerUsbThread *this);
bool __thiscall vortex::CVrControllerUsbThread::VrcSetTrackpadDebugEnable(CVrControllerUsbThread *this,bool param_1);
void __thiscall vortex::CVrControllerUsbThread::VrcSetTrackpadDebugEnable(CVrControllerUsbThread *this,bool param_1);
void std::string::_Rep::_M_dispose(allocator *param_1);
void __thiscall vortex::CVrControllerUsbThread::OnHidClose(CVrControllerUsbThread *this);
void __thiscall vortex::CVrControllerUsbThread::~CVrControllerUsbThread(CVrControllerUsbThread *this);
void __thiscall vortex::CVrControllerUsbThread::~CVrControllerUsbThread(CVrControllerUsbThread *this);
ulong __thiscall vortex::CVrControllerUsbThread::VrcSetPowerLevel(CVrControllerUsbThread *this,EPowerLevel param_1);
void __thiscall vortex::CVrControllerUsbThread::VrcSetPowerLevel(CVrControllerUsbThread *this,EPowerLevel param_1);
void __thiscall vortex::CVrControllerUsbThread::CVrControllerUsbThread(CVrControllerUsbThread *this,CTime *param_1,string *param_2,int param_3);
void __thiscall vortex::CVrControllerUsbThread::UpdateControllerState(CVrControllerUsbThread *this,ValveControllerStatePacketK2_t *param_1);
void __thiscall vortex::CVrControllerUsbThread::UpdateBatteryState(CVrControllerUsbThread *this,SteamControllerStatusEvent_t *param_1);
void __thiscall vortex::CVrControllerUsbThread::UpdateHmdState(CVrControllerUsbThread *this,ValveHmdState_t *param_1);
void __thiscall vortex::CVrControllerUsbThread::UpdateMappedInputState(CVrControllerUsbThread *this,uchar *param_1,ulong param_2);
void vortex::CVrControllerUsbThread::UnpackControllerButtons(ulong param_1,ulong *param_2,ulong *param_3);
void __thiscall vortex::CVrControllerUsbThread::UpdateControllerState(CVrControllerUsbThread *this,ValveControllerStatePacket_t *param_1);
void __thiscall vortex::CVrControllerUsbThread::UpdateControllerState(CVrControllerUsbThread *this,ValveControllerStatePacketV2_t *param_1);
void vortex::CVrControllerUsbThread::OnHidPacket(uchar *param_1,int param_2,double param_3,bool param_4);
void __thiscall vortex::CVrControllerUsbThread::SetCallback(CVrControllerUsbThread *this,void *param_1,IVrcCallback *param_2);
void __thiscall vortex::CVrControllerUsbThread::ClearCallback(CVrControllerUsbThread *this,void *param_1);
undefined8 __thiscall vortex::CVrControllerUsbThread::GetAttributesValues(CVrControllerUsbThread *this);
undefined8 __thiscall vortex::CVrControllerUsbThread::OnHidOpen(CVrControllerUsbThread *this);
bool vortex::CVrControllerUsbThread::GetAttributes(CHidDevice *param_1);
CVrControllerUsbThread * __thiscall vortex::CVrControllerUsbThread::FindSerialNumberByAttachedDeviceId(CVrControllerUsbThread *this,uint param_1);
CVrControllerUsbThread * __thiscall vortex::CVrControllerUsbThread::GetControllerDeviceInfo(CVrControllerUsbThread *this,string *param_1,uint param_2,int *param_3);
CVrControllerUsbThread *vortex::CVrControllerUsbThread::Create(CTime *param_1,string *param_2,uint param_3);
void vortex::CVrControllerUsbThread::GetAttachedControllerId(uint *param_1,uint *param_2);
char * vortex::CVrControllerUsbThread::GetThreadName(void);
undefined8 vortex::CVrControllerUsbThread::GetPollingTime(void);
_Rb_tree<> * __thiscall std::_Rb_tree<>::find(_Rb_tree<> *this,string *param_1);
uint BUnused(pair param_1);
uint __thiscall CVrcDecodeTagged::ExtendOpticalHitTo32Bits(CVrcDecodeTagged *this,uchar param_1,uint param_2,uint param_3);
bool __thiscall CVrcDecodeTagged::DecodeSensorHits(CVrcDecodeTagged *this,uchar *param_1,int param_2);
undefined4 __thiscall CVrcDecodeTagged::Decode(CVrcDecodeTagged *this,uchar param_1,uchar *param_2,int param_3);
void __thiscall CVrcDecodeTagged::~CVrcDecodeTagged(CVrcDecodeTagged *this);
void __thiscall CVrcDecodeTagged::~CVrcDecodeTagged(CVrcDecodeTagged *this);
void __thiscall std::deque<>::_M_push_front_aux<>(deque<> *this,SensorHit_s *param_1);
void __thiscall std::vector<>::_M_realloc_insert<>(vector<> *this,__normal_iterator param_1,pair *param_2);
pair * __thiscall std::vector<>::emplace_back<>(vector<> *this,pair *param_1);
__normal_iterator std::__find_if<>(__normal_iterator param_1,__normal_iterator param_2,_Iter_pred param_3,random_access_iterator_tag param_4);
void __thiscall CWirelessDecoderWv2::Reset(CWirelessDecoderWv2 *this);
void __thiscall CWirelessDecoderWv2::ResetImpl(CWirelessDecoderWv2 *this);
void __thiscall CWirelessDecoderWv2::DecodeControllerStateK2(CWirelessDecoderWv2 *this,uchar *param_1,int param_2);
bool __thiscall CWirelessDecoderWv2::Decode(CWirelessDecoderWv2 *this,uchar param_1,uchar *param_2,int param_3);
undefined4 __thiscall CWirelessDecoderWv2::GetOpticalSubprotocolVersion(CWirelessDecoderWv2 *this);
undefined4 __thiscall CWirelessDecoderWv2::GetControllerSubprotocolVersion(CWirelessDecoderWv2 *this);
void __thiscall CWirelessDecoderWv2::~CWirelessDecoderWv2(CWirelessDecoderWv2 *this);
void __thiscall CWirelessDecoderWv2::~CWirelessDecoderWv2(CWirelessDecoderWv2 *this);
void __thiscall std::vector<>::_M_realloc_insert<>(vector<> *this,__normal_iterator param_1,SobData_s *param_2);
void OutputDebugStringA(char *param_1);
void vortex::VortexOutputDebugString(char *param_1);
undefined8 vortex::RemoveDebugOutputHandler(_func_void_char_ptr *param_1);
undefined8 vortex::AddDebugOutputHandler(_func_void_char_ptr *param_1);
void vortex::ErrorPrintf(char *param_1,undefined param_2,undefined param_3,undefined param_4,undefined param_5,undefined param_6,undefined param_7,...);
void vortex::Printf(char *param_1,undefined param_2,undefined param_3,undefined param_4,undefined param_5,undefined param_6,undefined param_7,...);
void CThread::OnExit(void);
undefined8 CThread::Init(void);
code * CThread::GetThreadProc(void);
void ReapChildProcesses(int param_1);
undefined4 ThreadProcConvert(void *param_1);
void __thiscall CThreadMutex::~CThreadMutex(CThreadMutex *this);
void ThreadSetDebugName.part.0(char *param_1);
void __thiscall CThread::IsAlive(CThread *this);
undefined8 __thiscall CThread::IsThreadRunning(CThread *this);
pthread_t CreateSimpleThread(_func_uint_void_ptr *param_1,void *param_2,uint *param_3,uint param_4);
undefined8 ReleaseThreadHandle(void);
void ThreadYield(void);
void ThreadSleep(long param_1);
void ThreadGetCurrentId(void);
long VerifyTidIntegrity(void);
pthread_t ThreadGetCurrentHandle(void);
void ThreadGetCurrentRunningRef(void);
bool ThreadIsThreadRunning(uint param_1);
int ThreadGetPriority(pthread_t param_1);
bool ThreadTerminate(pthread_t param_1);
undefined8 ThreadSetAffinity(__pid_t param_1,ulong param_2,uint *param_3);
void InitMainThread(void);
bool ThreadInMainThread(void);
void DeclareCurrentThreadIsMainThread(void);
void ThreadSetDebugName(long param_1);
int CreateSimpleProcess(char *param_1,undefined8 param_2,__pid_t *param_3);
__pid_t ThreadGetCurrentProcessHandle(void);
undefined4 ThreadOpenProcess(undefined4 param_1);
bool ThreadCloseProcess(__pid_t param_1);
__pid_t ThreadGetCurrentProcessId(void);
undefined8 ThreadOverrideCurrentProcessId(int param_1);
bool ThreadIsProcessActive(__pid_t param_1);
bool ThreadTerminateProcessCode(__pid_t param_1);
bool ThreadGetProcessExitCode(__pid_t param_1,int *param_2);
undefined8 ThreadWaitForProcessExit(__pid_t param_1,uint param_2);
__pid_t ThreadGetProcessParentID(void);
char ThreadGetProcessPriority(id_t param_1);
undefined8 ThreadSetProcessPriority(id_t param_1,uint param_2);
__pid_t ThreadShellExecute(undefined8 param_1,undefined8 param_2,char *param_3);
int ThreadGetProcessListInfo(int param_1,int *param_2);
void __thiscall CThreadSyncObject::CThreadSyncObject(CThreadSyncObject *this);
byte __thiscall CThreadSyncObject::operator!(CThreadSyncObject *this);
void CThreadSyncObject::AssertUseable(void);
undefined8 CThreadSyncObject::SaveNameToFile(char *param_1);
undefined8 __thiscall CThreadSyncObject::CreateAnonymousSyncObjectInternal(CThreadSyncObject *this,bool param_1,bool param_2);
void __thiscall CThreadEvent::CThreadEvent(CThreadEvent *this,bool param_1);
undefined8 __thiscall CThreadSyncObject::SignalThreadSyncObjectInternal(CThreadSyncObject *this);
bool __thiscall CThreadSyncObject::IsSemaphoreOrphanedInternal(CThreadSyncObject *this,int param_1,int param_2);
int __thiscall CThreadSyncObject::CreateSemaphoreInternal(CThreadSyncObject *this,char *param_1,long param_2,bool param_3,bool *param_4);
int __thiscall CThreadSyncObject::OpenSemaphoreInternal(CThreadSyncObject *this,char *param_1,bool param_2);
CThreadSyncObject __thiscall CThreadSyncObject::AcquireSemaphoreInternal(CThreadSyncObject *this,uint param_1);
undefined4 __thiscall CThreadSyncObject::Wait(CThreadSyncObject *this,uint param_1);
void __thiscall CThreadEvent::Check(CThreadEvent *this);
undefined8 __thiscall CThreadSyncObject::ReleaseSemaphoreInternal(CThreadSyncObject *this,int param_1,long param_2);
void CThreadSyncObject::CloseSemaphoreInternal(int param_1,bool param_2,char *param_3);
void __thiscall CThreadSyncObject::~CThreadSyncObject(CThreadSyncObject *this);
void __thiscall CThreadSyncObject::~CThreadSyncObject(CThreadSyncObject *this);
void __thiscall CThreadEvent::CThreadEvent(CThreadEvent *this,char *param_1,bool param_2,bool param_3);
undefined8 __thiscall CThreadSyncObject::EnsureSemaphoreClearedInternal(CThreadSyncObject *this,int param_1);
undefined8 __thiscall CThreadEvent::Reset(CThreadEvent *this);
undefined8 __thiscall CThreadSyncObject::EnsureSemaphorePostedInternal(CThreadSyncObject *this,int param_1);
undefined8 __thiscall CThreadEvent::Set(CThreadEvent *this);
undefined4 CThread::ThreadProc(void *param_1);
void __thiscall CThreadSemaphore::CThreadSemaphore(CThreadSemaphore *this,long param_1,long param_2);
undefined8 __thiscall CThreadSemaphore::Release(CThreadSemaphore *this,long param_1);
void __thiscall CThreadFullMutex::CThreadFullMutex(CThreadFullMutex *this,bool param_1,char *param_2,bool param_3,bool param_4);
undefined8 __thiscall CThreadFullMutex::Release(CThreadFullMutex *this);
CThreadFullMutex __thiscall CThreadFullMutex::IsCreator(CThreadFullMutex *this);
void __thiscall CThreadLocalBase::CThreadLocalBase(CThreadLocalBase *this);
void __thiscall CThreadLocalBase::~CThreadLocalBase(CThreadLocalBase *this);
void __thiscall CThreadLocalBase::Get(CThreadLocalBase *this);
void __thiscall CThreadLocalBase::Set(CThreadLocalBase *this,void *param_1);
long ThreadInterlockedIncrement(int *param_1);
long ThreadInterlockedDecrement(int *param_1);
long ThreadInterlockedExchange(int *param_1,int param_2);
long ThreadInterlockedExchangeAdd(int *param_1,int param_2);
long ThreadInterlockedCompareExchange(int *param_1,int param_2,int param_3);
undefined8 ThreadInterlockedAssignIf(uint *param_1,uint param_2,uint param_3);
undefined8 ThreadInterlockedExchangePointer(undefined8 *param_1,undefined8 param_2);
long ThreadInterlockedCompareExchangePointer(long *param_1,long param_2,long param_3);
bool ThreadInterlockedAssignPointerIf(long *param_1,long param_2,long param_3);
long ThreadInterlockedIncrement64(long *param_1);
long ThreadInterlockedDecrement64(long *param_1);
long ThreadInterlockedExchangeAdd64(long *param_1,long param_2);
undefined8 ThreadInterlockedExchange64(undefined8 *param_1,undefined8 param_2);
long ThreadInterlockedCompareExchange64(long *param_1,long param_2,long param_3);
bool ThreadInterlockedAssignIf64(long *param_1,long param_2,long param_3);
void __thiscall CThreadMutex::CThreadMutex(CThreadMutex *this);
undefined8 ThreadSetPriority(pthread_t param_1,int param_2,undefined8 param_3,undefined param_4,undefined param_5,undefined param_6);
void __thiscall CThreadSpinLock::Lock(CThreadSpinLock *this,uint param_1);
void __thiscall CThreadRWLock::WaitForRead(CThreadRWLock *this);
ulong __thiscall CThreadRWLock::LockForWrite(CThreadRWLock *this);
int __thiscall CThreadRWLock::UnlockWrite(CThreadRWLock *this);
long __thiscall CThreadSpinRWLock::SpinLockForWrite(CThreadSpinRWLock *this,uint param_1);
long __thiscall CThreadSpinRWLock::LockForRead(CThreadSpinRWLock *this);
long __thiscall CThreadSpinRWLock::UnlockRead(CThreadSpinRWLock *this);
undefined8 __thiscall CThreadSpinRWLock::UnlockWrite(CThreadSpinRWLock *this);
void ThreadSuspendSignal(int param_1);
void ThreadResumeSignal(int param_1);
void __thiscall CThread::CThread(CThread *this);
CThread * __thiscall CThread::GetName(CThread *this);
void __thiscall CThread::SetName(CThread *this,char *param_1);
bool __thiscall CThread::Start(CThread *this,uint param_1);
undefined8 __thiscall CThread::IsAlive(CThread *this);
undefined4 __thiscall CThread::BHasValidThreadID(CThread *this);
undefined8 __thiscall CThread::Join(CThread *this,uint param_1);
void __thiscall CThread::~CThread(CThread *this);
void __thiscall CThread::~CThread(CThread *this);
void __thiscall CThread::~CThread(CThread *this);
undefined4 __thiscall CThread::GetResult(CThread *this);
void __thiscall CThread::Stop(CThread *this,int param_1);
void __thiscall CThread::GetPriority(CThread *this);
void CThread::SetPriority(int param_1);
undefined8 CThread::Suspend(void);
undefined8 CThread::Resume(void);
undefined8 CThread::Terminate(int param_1);
void CThread::GetCurrentCThread(void);
void CThread::Yield(void);
void CThread::Sleep(uint param_1);
void __thiscall CThread::WaitForCreateComplete(CThread *this,CThreadEvent *param_1);
void CThread::ThreadExceptionWrapper(void *param_1);
void __thiscall CThreadLocalPtr<CThread>::~CThreadLocalPtr(CThreadLocalPtr<CThread> *this);
void __thiscall CThreadLocalInt<long>::~CThreadLocalInt(CThreadLocalInt<long> *this);
bool Plat_IsInDebugSession(void);
undefined8 IsPosix(void);
undefined8 IsWorkstationLocked(void);
undefined4 IsOnLaptop(void);
undefined8 IsRunningAsService(void);
undefined8 SetCurrentProcessExplicitAppUserModelID(void);
void SteamVRVersionAsString(void);
undefined IsRunningInAppContainer(void);
undefined8 *__to_xstring<>(undefined8 param_1_00,undefined8 param_2_00,undefined8 param_3_00,undefined8 param_4,undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,undefined8 *param_1,code *param_2,long param_3,undefined8 param_12,undefined8 param_13,undefined8 param_14,...);
void __thiscall CSDLDynamic::Init(CSDLDynamic *this);
void __thiscall CSDLDynamic::Unload(CSDLDynamic *this);
undefined1 * SDLDynamic(void);
void __thiscall CSDLDynamic::~CSDLDynamic(CSDLDynamic *this);
long SharedLib_Load(char *param_1,string *param_2);
void SharedLib_GetFunction(void *param_1,char *param_2);
void SharedLib_Unload(void *param_1);
bool __thiscall __cxxabiv1::__class_type_info::__do_upcast(__class_type_info *this,__class_type_info *param_1,void **param_2);
char __thiscall __cxxabiv1::__class_type_info::__do_find_public_src(__class_type_info *this,long param_1,void *param_2,__class_type_info *param_3,void *param_4);
void __thiscall __cxxabiv1::__class_type_info::~__class_type_info(__class_type_info *this);
void __thiscall __cxxabiv1::__class_type_info::~__class_type_info(__class_type_info *this);
undefined8 __thiscall __cxxabiv1::__class_type_info::__do_dyncast(__class_type_info *this,long param_1,__sub_kind param_2,__class_type_info *param_3,void *param_4,__class_type_info *param_5,void *param_6,__dyncast_result *param_7);
undefined8 __thiscall __cxxabiv1::__class_type_info::__do_upcast(__class_type_info *this,__class_type_info *param_1,void *param_2,__upcast_result *param_3);
undefined8 __thiscall __cxxabiv1::__class_type_info::__do_catch(__class_type_info *this,type_info *param_1,void **param_2,uint param_3);
void operator.delete(void *param_1);
void operator.delete(void *param_1,ulong param_2);
void operator.delete[](void *param_1);
long __dynamic_cast(long *param_1,undefined8 param_2,long *param_3,long param_4);
char * __concurrence_lock_error::what(void);
char * __concurrence_unlock_error::what(void);
void __thiscall __concurrence_lock_error::~__concurrence_lock_error(__concurrence_lock_error *this);
void __thiscall __concurrence_unlock_error::~__concurrence_unlock_error(__concurrence_unlock_error *this);
void __thiscall __concurrence_lock_error::~__concurrence_lock_error(__concurrence_lock_error *this);
void __thiscall __concurrence_unlock_error::~__concurrence_unlock_error(__concurrence_unlock_error *this);
void (anonymous_namespace)::pool::free(void *param_1);
ulong * (anonymous_namespace)::pool::allocate(ulong param_1);
void __freeres(void);
undefined8 * __cxa_allocate_exception(long param_1);
void __cxa_free_exception(long param_1);
undefined8 * __cxa_allocate_dependent_exception(void);
void __cxa_free_dependent_exception(void *param_1);
undefined8 __cxa_get_exception_ptr(long param_1);
long __cxa_begin_catch(long *param_1);
void __cxa_end_catch(void);
undefined4 std::uncaught_exception(void);
undefined4 std::uncaught_exceptions(void);
void __thiscall std::exception::~exception(exception *this);
void __thiscall std::bad_exception::~bad_exception(bad_exception *this);
char * std::exception::what(void);
char * std::bad_exception::what(void);
void __thiscall std::exception::~exception(exception *this);
void __thiscall std::bad_exception::~bad_exception(bad_exception *this);
void __thiscall __cxxabiv1::__forced_unwind::~__forced_unwind(__forced_unwind *this);
void __thiscall __cxxabiv1::__forced_unwind::~__forced_unwind(__forced_unwind *this);
void __thiscall __cxxabiv1::__foreign_exception::~__foreign_exception(__foreign_exception *this);
void __thiscall __cxxabiv1::__foreign_exception::~__foreign_exception(__foreign_exception *this);
void __thiscall std::exception::~exception(exception *this);
char * std::exception::what(void);
void __thiscall std::bad_exception::~bad_exception(bad_exception *this);
char * std::bad_exception::what(void);
long __cxa_get_globals_fast(void);
long __cxa_get_globals(void);
void get_adjusted_ptr(type_info *param_1,type_info *param_2,void **param_3);
ulong * read_encoded_value_with_base(uchar param_1,ulong param_2,uchar *param_3,ulong *param_4);
ulong get_ttype_entry(lsda_header_info *param_1,ulong param_2);
undefined8 check_exception_spec(lsda_header_info *param_1,type_info *param_2,void *param_3,long param_4);
undefined8 base_of_encoded_value(uchar param_1,_Unwind_Context *param_2);
lsda_header_info *parse_lsda_header(_Unwind_Context *param_1,uchar *param_2,lsda_header_info *param_3);
undefined8 __gxx_personality_v0(int param_1,uint param_2,long param_3,byte *param_4,_Unwind_Context *param_5);
void __cxa_call_unexpected(long param_1);
void __cxxabiv1::__terminate(_func_void *param_1);
undefined * std::set_terminate(_func_void *param_1);
undefined * std::get_terminate(void);
void std::terminate(void);
void __cxxabiv1::__unexpected(_func_void *param_1);
undefined * std::set_unexpected(_func_void *param_1);
undefined * std::get_unexpected(void);
void std::unexpected(void);
void __gxx_exception_cleanup(_Unwind_Reason_Code param_1,_Unwind_Exception *param_2);
long __cxa_init_primary_exception(long param_1,undefined8 param_2,undefined8 param_3);
void __cxa_throw(undefined8 param_1,undefined8 param_2,undefined8 param_3);
void __cxa_rethrow(undefined8 param_1,undefined8 param_2);
undefined8 __cxxabiv1::__function_type_info::__is_function_p(void);
void __thiscall __cxxabiv1::__function_type_info::~__function_type_info(__function_type_info *this);
void __thiscall __cxxabiv1::__function_type_info::~__function_type_info(__function_type_info *this);
void __thiscall __cxxabiv1::__fundamental_type_info::~__fundamental_type_info(__fundamental_type_info *this);
void __thiscall __cxxabiv1::__fundamental_type_info::~__fundamental_type_info(__fundamental_type_info *this);
undefined8 __cxa_guard_acquire(uint *param_1);
void __cxa_guard_abort(uint *param_1);
void __cxa_guard_release(uint *param_1);
void __thiscall recursive_init_error::~recursive_init_error(recursive_init_error *this);
void __thiscall recursive_init_error::~recursive_init_error(recursive_init_error *this);
void __thiscall recursive_init_error::recursive_init_error(recursive_init_error *this);
void * operator.new(ulong param_1);
void * operator.new[](ulong param_1);
undefined8 __cxxabiv1::__pointer_type_info::__is_pointer_p(void);
void __thiscall __cxxabiv1::__pointer_type_info::~__pointer_type_info(__pointer_type_info *this);
void __thiscall __cxxabiv1::__pointer_type_info::~__pointer_type_info(__pointer_type_info *this);
ulong __thiscall __cxxabiv1::__pointer_type_info::__pointer_catch(__pointer_type_info *this,__pbase_type_info *param_1,void **param_2,uint param_3);
void __cxa_pure_virtual(void);
void __cxa_deleted_virtual(void);
void __thiscall __cxxabiv1::__si_class_type_info::~__si_class_type_info(__si_class_type_info *this);
void __thiscall __cxxabiv1::__si_class_type_info::~__si_class_type_info(__si_class_type_info *this);
undefined8 __thiscall __cxxabiv1::__si_class_type_info::__do_find_public_src(__si_class_type_info *this,long param_1,void *param_2,__class_type_info *param_3,void *param_4);
undefined8 __thiscall __cxxabiv1::__si_class_type_info::__do_dyncast(__si_class_type_info *this,long param_1,__sub_kind param_2,__class_type_info *param_3,void *param_4,__class_type_info *param_5,void *param_6,__dyncast_result *param_7);
void __thiscall __cxxabiv1::__si_class_type_info::__do_upcast(__si_class_type_info *this,__class_type_info *param_1,void *param_2,__upcast_result *param_3);
void __thiscall std::type_info::~type_info(type_info *this);
undefined8 std::type_info::__is_function_p(void);
undefined8 std::type_info::__do_upcast(__class_type_info *param_1,void **param_2);
void __thiscall std::type_info::~type_info(type_info *this);
undefined8 std::type_info::__do_catch(type_info *param_1,void **param_2,uint param_3);
void __thiscall __cxxabiv1::__vmi_class_type_info::~__vmi_class_type_info(__vmi_class_type_info *this);
void __thiscall __cxxabiv1::__vmi_class_type_info::~__vmi_class_type_info(__vmi_class_type_info *this);
uint __thiscall __cxxabiv1::__vmi_class_type_info::__do_find_public_src(__vmi_class_type_info *this,long param_1,void *param_2,__class_type_info *param_3,void *param_4);
char __thiscall __cxxabiv1::__vmi_class_type_info::__do_dyncast(__vmi_class_type_info *this,long param_1,__sub_kind param_2,__class_type_info *param_3,void *param_4,__class_type_info *param_5,void *param_6,__dyncast_result *param_7);
ulong __thiscall __cxxabiv1::__vmi_class_type_info::__do_upcast(__vmi_class_type_info *this,__class_type_info *param_1,void *param_2,__upcast_result *param_3);
void __verbose_terminate_handler(void);
undefined * (anonymous_namespace)::fopen_mode(_Ios_Openmode param_1);
long (anonymous_namespace)::xwrite(int param_1,char *param_2,long param_3);
void std::__basic_file<char>::__basic_file(pthread_mutex_t *param_1);
bool __thiscall std::__basic_file<char>::is_open(__basic_file<char> *this);
_IO_FILE * std::__basic_file<char>::sys_open(_IO_FILE *param_1,_Ios_Openmode param_2);
__basic_file<char> * __thiscall std::__basic_file<char>::sys_open(__basic_file<char> *this,int param_1,_Ios_Openmode param_2);
char * std::__basic_file<char>::open(char *param_1,_Ios_Openmode param_2,int param_3);
void __thiscall std::__basic_file<char>::fd(__basic_file<char> *this);
undefined8 __thiscall std::__basic_file<char>::file(__basic_file<char> *this);
__basic_file<char> * __thiscall std::__basic_file<char>::close(__basic_file<char> *this);
__basic_file<char> * __thiscall std::__basic_file<char>::~__basic_file(__basic_file<char> *this);
ssize_t __thiscall std::__basic_file<char>::xsgetn(__basic_file<char> *this,char *param_1,long param_2);
void __thiscall std::__basic_file<char>::xsputn(__basic_file<char> *this,char *param_1,long param_2);
long __thiscall std::__basic_file<char>::xsputn_2(__basic_file<char> *this,char *param_1,long param_2,char *param_3,long param_4);
void __thiscall std::__basic_file<char>::seekoff(__basic_file<char> *this,long param_1,_Ios_Seekdir param_2);
void __thiscall std::__basic_file<char>::sync(__basic_file<char> *this);
long __thiscall std::__basic_file<char>::showmanyc(__basic_file<char> *this);
undefined8 __thiscall std::codecvt<>::do_in(codecvt<> *this,__mbstate_t *param_1,char *param_2,char *param_3,char **param_4,char *param_5,char *param_6,char **param_7);
undefined8 __thiscall std::codecvt<>::do_unshift(codecvt<> *this,__mbstate_t *param_1,char *param_2,char *param_3,char **param_4);
undefined8 std::codecvt<>::do_max_length(void);
undefined8 std::codecvt<>::do_always_noconv(void);
ulong __thiscall std::codecvt<>::do_length(codecvt<> *this,__mbstate_t *param_1,char *param_2,char *param_3,ulong param_4);
undefined8 std::codecvt<>::do_always_noconv(void);
void __thiscall std::codecvt<>::~codecvt(codecvt<> *this);
void __thiscall std::codecvt<>::~codecvt(codecvt<> *this);
void __thiscall std::codecvt<>::~codecvt(codecvt<> *this);
void __thiscall std::codecvt<>::~codecvt(codecvt<> *this);
void __thiscall std::codecvt<>::codecvt(codecvt<> *this,ulong param_1);
void __thiscall std::codecvt<>::codecvt(codecvt<> *this,__locale_struct *param_1,ulong param_2);
void __thiscall std::codecvt<>::codecvt(codecvt<> *this,ulong param_1);
void __thiscall std::codecvt<>::codecvt(codecvt<> *this,__locale_struct *param_1,ulong param_2);
undefined8 __thiscall std::codecvt<>::do_out(codecvt<> *this,__mbstate_t *param_1,wchar_t *param_2,wchar_t *param_3,wchar_t **param_4,char *param_5,char *param_6,char **param_7);
undefined8 __thiscall std::codecvt<>::do_in(codecvt<> *this,__mbstate_t *param_1,char *param_2,char *param_3,char **param_4,wchar_t *param_5,wchar_t *param_6,wchar_t **param_7);
bool __thiscall std::codecvt<>::do_encoding(codecvt<> *this);
ulong __thiscall std::codecvt<>::do_max_length(codecvt<> *this);
int __thiscall std::codecvt<>::do_length(codecvt<> *this,__mbstate_t *param_1,char *param_2,char *param_3,ulong param_4);
istream * std::operator>>(istream *param_1,string *param_2);
istream * std::getline<>(istream *param_1,string *param_2,char param_3);
wistream * std::getline<>(wistream *param_1,wstring *param_2,wchar_t param_3);
void __thiscall std::ios_base::Init::Init(Init *this);
void __thiscall std::ios_base::Init::~Init(Init *this);
char std::ios_base::sync_with_stdio(bool param_1);
void __thiscall std::locale::facet::~facet(facet *this);
void __thiscall std::locale::facet::~facet(facet *this);
void std::locale::facet::_S_initialize_once(void);
void __thiscall __scoped_lock::~__scoped_lock(__scoped_lock *this);
void __thiscall std::locale::locale(locale *this,locale *param_1);
void __thiscall std::locale::locale(locale *this,_Impl *param_1);
void std::locale::name[abi:cxx11](void);
ulong __thiscall std::locale::operator==(locale *this,locale *param_1);
int std::locale::_S_normalize_category(int param_1);
undefined8 std::locale::facet::_S_get_c_locale(void);
undefined2 * std::locale::facet::_S_get_c_name(void);
void __thiscall std::locale::_Impl::~_Impl(_Impl *this);
void __thiscall std::locale::operator=(locale *this,locale *param_1);
void __thiscall std::locale::~locale(locale *this);
void __thiscall std::locale::_Impl::_Impl(_Impl *this,_Impl *param_1,ulong param_2);
long __thiscall std::locale::id::_M_id(id *this);
void __thiscall std::locale::_Impl::_M_install_facet(_Impl *this,id *param_1,facet *param_2);
void __thiscall std::locale::_Impl::_M_replace_facet(_Impl *this,_Impl *param_1,id *param_2);
void __thiscall std::locale::_Impl::_M_replace_category(_Impl *this,_Impl *param_1,id **param_2);
void __thiscall std::locale::_Impl::_M_install_cache(_Impl *this,facet *param_1,ulong param_2);
undefined1 * (anonymous_namespace)::get_locale_mutex(void);
void __thiscall std::locale::_Impl::_Impl(_Impl *this,ulong param_1);
void std::locale::_S_initialize_once(void);
void std::locale::_S_initialize(void);
void __thiscall std::locale::locale(locale *this);
undefined8 * std::locale::classic(void);
locale * __thiscall std::locale::global(locale *this,locale *param_1);
void std::moneypunct<char,true>::_M_initialize_moneypunct(__locale_struct *param_1,char *param_2);
void std::moneypunct<char,false>::_M_initialize_moneypunct(__locale_struct *param_1,char *param_2);
void __thiscall std::moneypunct<char,true>::~moneypunct(moneypunct<char,true> *this);
void __thiscall std::moneypunct<char,true>::~moneypunct(moneypunct<char,true> *this);
void __thiscall std::moneypunct<char,false>::~moneypunct(moneypunct<char,false> *this);
void __thiscall std::moneypunct<char,false>::~moneypunct(moneypunct<char,false> *this);
void std::moneypunct<>::_M_initialize_moneypunct(__locale_struct *param_1,char *param_2);
void std::moneypunct<>::_M_initialize_moneypunct(__locale_struct *param_1,char *param_2);
void __thiscall std::moneypunct<>::~moneypunct(moneypunct<> *this);
void __thiscall std::moneypunct<>::~moneypunct(moneypunct<> *this);
void __thiscall std::moneypunct<>::~moneypunct(moneypunct<> *this);
void __thiscall std::moneypunct<>::~moneypunct(moneypunct<> *this);
void __thiscall std::__moneypunct_cache<char,true>::~__moneypunct_cache(__moneypunct_cache<char,true> *this);
void __thiscall std::__moneypunct_cache<char,true>::~__moneypunct_cache(__moneypunct_cache<char,true> *this);
void __thiscall std::__moneypunct_cache<char,false>::~__moneypunct_cache(__moneypunct_cache<char,false> *this);
void __thiscall std::__moneypunct_cache<char,false>::~__moneypunct_cache(__moneypunct_cache<char,false> *this);
void __thiscall std::__moneypunct_cache<>::~__moneypunct_cache(__moneypunct_cache<> *this);
void __thiscall std::__moneypunct_cache<>::~__moneypunct_cache(__moneypunct_cache<> *this);
void __thiscall std::__moneypunct_cache<>::~__moneypunct_cache(__moneypunct_cache<> *this);
void __thiscall std::__moneypunct_cache<>::~__moneypunct_cache(__moneypunct_cache<> *this);
undefined4 std::money_base::_S_construct_pattern(char param_1,char param_2,char param_3);
void std::moneypunct<char,true>::_M_initialize_moneypunct(__locale_struct *param_1,char *param_2);
void std::moneypunct<char,false>::_M_initialize_moneypunct(__locale_struct *param_1,char *param_2);
void __thiscall std::moneypunct<char,true>::~moneypunct(moneypunct<char,true> *this);
void __thiscall std::moneypunct<char,true>::~moneypunct(moneypunct<char,true> *this);
void __thiscall std::moneypunct<char,false>::~moneypunct(moneypunct<char,false> *this);
void __thiscall std::moneypunct<char,false>::~moneypunct(moneypunct<char,false> *this);
void std::moneypunct<>::_M_initialize_moneypunct(__locale_struct *param_1,char *param_2);
void std::moneypunct<>::_M_initialize_moneypunct(__locale_struct *param_1,char *param_2);
void __thiscall std::moneypunct<>::~moneypunct(moneypunct<> *this);
void __thiscall std::moneypunct<>::~moneypunct(moneypunct<> *this);
void __thiscall std::moneypunct<>::~moneypunct(moneypunct<> *this);
void __thiscall std::moneypunct<>::~moneypunct(moneypunct<> *this);
void __thiscall std::numpunct<char>::_M_initialize_numpunct(numpunct<char> *this,__locale_struct *param_1);
void __thiscall std::numpunct<char>::~numpunct(numpunct<char> *this);
void __thiscall std::numpunct<char>::~numpunct(numpunct<char> *this);
void __thiscall std::numpunct<wchar_t>::_M_initialize_numpunct(numpunct<wchar_t> *this,__locale_struct *param_1);
void __thiscall std::numpunct<wchar_t>::~numpunct(numpunct<wchar_t> *this);
void __thiscall std::numpunct<wchar_t>::~numpunct(numpunct<wchar_t> *this);
void __thiscall std::__numpunct_cache<char>::~__numpunct_cache(__numpunct_cache<char> *this);
void __thiscall std::__numpunct_cache<char>::~__numpunct_cache(__numpunct_cache<char> *this);
void __thiscall std::__numpunct_cache<wchar_t>::~__numpunct_cache(__numpunct_cache<wchar_t> *this);
void __thiscall std::__numpunct_cache<wchar_t>::~__numpunct_cache(__numpunct_cache<wchar_t> *this);
undefined std::__narrow_multibyte_chars(char *param_1,__locale_struct *param_2);
void __thiscall std::numpunct<char>::_M_initialize_numpunct(numpunct<char> *this,__locale_struct *param_1);
void __thiscall std::numpunct<char>::~numpunct(numpunct<char> *this);
void __thiscall std::numpunct<char>::~numpunct(numpunct<char> *this);
void __thiscall std::numpunct<wchar_t>::_M_initialize_numpunct(numpunct<wchar_t> *this,__locale_struct *param_1);
void __thiscall std::numpunct<wchar_t>::~numpunct(numpunct<wchar_t> *this);
void __thiscall std::numpunct<wchar_t>::~numpunct(numpunct<wchar_t> *this);
long std::local_Rb_tree_decrement(_Rb_tree_node_base *param_1);
long std::_Rb_tree_increment(_Rb_tree_node_base *param_1);
long std::_Rb_tree_increment(_Rb_tree_node_base *param_1);
long std::_Rb_tree_decrement(_Rb_tree_node_base *param_1);
long std::_Rb_tree_decrement(_Rb_tree_node_base *param_1);
void std::_Rb_tree_rotate_left(_Rb_tree_node_base *param_1,_Rb_tree_node_base **param_2);
void std::_Rb_tree_rotate_right(_Rb_tree_node_base *param_1,_Rb_tree_node_base **param_2);
void std::_Rb_tree_insert_and_rebalance(bool param_1,_Rb_tree_node_base *param_2,_Rb_tree_node_base *param_3,_Rb_tree_node_base *param_4);
void std::_Rb_tree_rebalance_for_erase(_Rb_tree_node_base *param_1,_Rb_tree_node_base *param_2);
int std::_Rb_tree_black_count(_Rb_tree_node_base *param_1,_Rb_tree_node_base *param_2);
undefined8 __thiscall std::codecvt<>::do_unshift(codecvt<> *this,__mbstate_t *param_1,char *param_2,char *param_3,char **param_4);
undefined8 std::codecvt<>::do_encoding(void);
undefined8 std::codecvt<>::do_always_noconv(void);
undefined8 std::codecvt<>::do_max_length(void);
undefined8 __thiscall std::codecvt<>::do_unshift(codecvt<> *this,__mbstate_t *param_1,uchar *param_2,uchar *param_3,uchar **param_4);
int __thiscall std::__codecvt_utf8_base<char16_t>::do_max_length(__codecvt_utf8_base<char16_t> *this);
int __thiscall std::__codecvt_utf8_base<char32_t>::do_max_length(__codecvt_utf8_base<char32_t> *this);
int __thiscall std::__codecvt_utf8_base<wchar_t>::do_max_length(__codecvt_utf8_base<wchar_t> *this);
int __thiscall std::__codecvt_utf16_base<char16_t>::do_max_length(__codecvt_utf16_base<char16_t> *this);
int __thiscall std::__codecvt_utf16_base<char32_t>::do_max_length(__codecvt_utf16_base<char32_t> *this);
int __thiscall std::__codecvt_utf16_base<wchar_t>::do_max_length(__codecvt_utf16_base<wchar_t> *this);
int __thiscall std::__codecvt_utf8_utf16_base<char16_t>::do_max_length(__codecvt_utf8_utf16_base<char16_t> *this);
int __thiscall std::__codecvt_utf8_utf16_base<char32_t>::do_max_length(__codecvt_utf8_utf16_base<char32_t> *this);
int __thiscall std::__codecvt_utf8_utf16_base<wchar_t>::do_max_length(__codecvt_utf8_utf16_base<wchar_t> *this);
wchar32 std::(anonymous_namespace)::read_utf8_code_point<char>(range *param_1,ulong param_2);
wchar32 std::(anonymous_namespace)::read_utf8_code_point<char8_t>(range *param_1,ulong param_2);
void __thiscall std::codecvt<>::~codecvt(codecvt<> *this);
void __thiscall std::__codecvt_utf8_base<char16_t>::~__codecvt_utf8_base(__codecvt_utf8_base<char16_t> *this);
void __thiscall std::__codecvt_utf16_base<char16_t>::~__codecvt_utf16_base(__codecvt_utf16_base<char16_t> *this);
void __thiscall std::__codecvt_utf8_utf16_base<char16_t>::~__codecvt_utf8_utf16_base(__codecvt_utf8_utf16_base<char16_t> *this);
void __thiscall std::codecvt<>::~codecvt(codecvt<> *this);
void __thiscall std::__codecvt_utf8_base<char32_t>::~__codecvt_utf8_base(__codecvt_utf8_base<char32_t> *this);
void __thiscall std::__codecvt_utf16_base<char32_t>::~__codecvt_utf16_base(__codecvt_utf16_base<char32_t> *this);
void __thiscall std::__codecvt_utf8_utf16_base<char32_t>::~__codecvt_utf8_utf16_base(__codecvt_utf8_utf16_base<char32_t> *this);
void __thiscall std::codecvt<>::~codecvt(codecvt<> *this);
void __thiscall std::codecvt<>::~codecvt(codecvt<> *this);
void __thiscall std::codecvt<>::~codecvt(codecvt<> *this);
void __thiscall std::__codecvt_utf8_base<char16_t>::~__codecvt_utf8_base(__codecvt_utf8_base<char16_t> *this);
void __thiscall std::__codecvt_utf16_base<char16_t>::~__codecvt_utf16_base(__codecvt_utf16_base<char16_t> *this);
void __thiscall std::__codecvt_utf8_utf16_base<char16_t>::~__codecvt_utf8_utf16_base(__codecvt_utf8_utf16_base<char16_t> *this);
void __thiscall std::codecvt<>::~codecvt(codecvt<> *this);
void __thiscall std::__codecvt_utf8_base<char32_t>::~__codecvt_utf8_base(__codecvt_utf8_base<char32_t> *this);
void __thiscall std::__codecvt_utf16_base<char32_t>::~__codecvt_utf16_base(__codecvt_utf16_base<char32_t> *this);
void __thiscall std::__codecvt_utf8_utf16_base<char32_t>::~__codecvt_utf8_utf16_base(__codecvt_utf8_utf16_base<char32_t> *this);
void __thiscall std::codecvt<>::~codecvt(codecvt<> *this);
void __thiscall std::codecvt<>::~codecvt(codecvt<> *this);
bool std::(anonymous_namespace)::read_bom<>(range *param_1,unsigned_char *param_2);
wchar32 std::(anonymous_namespace)::read_utf16_code_point<false>(range *param_1,ulong param_2,codecvt_mode param_3);
void __thiscall std::__codecvt_utf8_base<wchar_t>::~__codecvt_utf8_base(__codecvt_utf8_base<wchar_t> *this);
void __thiscall std::__codecvt_utf8_base<wchar_t>::~__codecvt_utf8_base(__codecvt_utf8_base<wchar_t> *this);
void __thiscall std::__codecvt_utf16_base<wchar_t>::~__codecvt_utf16_base(__codecvt_utf16_base<wchar_t> *this);
void __thiscall std::__codecvt_utf16_base<wchar_t>::~__codecvt_utf16_base(__codecvt_utf16_base<wchar_t> *this);
void __thiscall std::__codecvt_utf8_utf16_base<wchar_t>::~__codecvt_utf8_utf16_base(__codecvt_utf8_utf16_base<wchar_t> *this);
void __thiscall std::__codecvt_utf8_utf16_base<wchar_t>::~__codecvt_utf8_utf16_base(__codecvt_utf8_utf16_base<wchar_t> *this);
bool std::(anonymous_namespace)::write_utf16_bom<false>(range *param_1,codecvt_mode param_2);
undefined __thiscall std::__codecvt_utf16_base<char16_t>::do_out(__codecvt_utf16_base<char16_t> *this,__mbstate_t *param_1,wchar16 *param_2,wchar16 *param_3,wchar16 **param_4,char *param_5,char *param_6,char **param_7);
bool std::(anonymous_namespace)::write_utf8_code_point<char>(range *param_1,wchar32 param_2);
bool std::(anonymous_namespace)::write_utf8_code_point<char8_t>(range *param_1,wchar32 param_2);
bool std::(anonymous_namespace)::write_utf8_bom<char>(range *param_1,codecvt_mode param_2);
result std::(anonymous_namespace)::utf16_out<>(range *param_1,range *param_2,ulong param_3,codecvt_mode param_4,surrogates param_5);
result __thiscall std::__codecvt_utf8_base<char16_t>::do_out(__codecvt_utf8_base<char16_t> *this,__mbstate_t *param_1,wchar16 *param_2,wchar16 *param_3,wchar16 **param_4,char *param_5,char *param_6,char **param_7);
void __thiscall std::codecvt<>::do_out(codecvt<> *this,__mbstate_t *param_1,wchar16 *param_2,wchar16 *param_3,wchar16 **param_4,char *param_5,char *param_6,char **param_7);
result std::(anonymous_namespace)::ucs4_out<char>(range *param_1,range *param_2,ulong param_3,codecvt_mode param_4);
void __thiscall std::__codecvt_utf8_base<char32_t>::do_out(__codecvt_utf8_base<char32_t> *this,__mbstate_t *param_1,wchar32 *param_2,wchar32 *param_3,wchar32 **param_4,char *param_5,char *param_6,char **param_7);
void __thiscall std::__codecvt_utf8_base<wchar_t>::do_out(__codecvt_utf8_base<wchar_t> *this,__mbstate_t *param_1,wchar_t *param_2,wchar_t *param_3,wchar_t **param_4,char *param_5,char *param_6,char **param_7);
void std::(anonymous_namespace)::read_utf16_bom<false>(range *param_1,codecvt_mode *param_2);
undefined8 std::(anonymous_namespace)::ucs4_in(range *param_1,range *param_2,ulong param_3,codecvt_mode param_4);
ulong __thiscall std::__codecvt_utf16_base<char32_t>::do_in(__codecvt_utf16_base<char32_t> *this,__mbstate_t *param_1,char *param_2,char *param_3,char **param_4,wchar32 *param_5,wchar32 *param_6,wchar32 **param_7);
ulong __thiscall std::__codecvt_utf16_base<wchar_t>::do_in(__codecvt_utf16_base<wchar_t> *this,__mbstate_t *param_1,char *param_2,char *param_3,char **param_4,wchar_t *param_5,wchar_t *param_6,wchar_t **param_7);
long __thiscall std::__codecvt_utf16_base<char32_t>::do_length(__codecvt_utf16_base<char32_t> *this,__mbstate_t *param_1,char *param_2,char *param_3,ulong param_4);
char __thiscall std::__codecvt_utf16_base<char16_t>::do_in(__codecvt_utf16_base<char16_t> *this,__mbstate_t *param_1,char *param_2,char *param_3,char **param_4,wchar16 *param_5,wchar16 *param_6,wchar16 **param_7);
long __thiscall std::__codecvt_utf16_base<char16_t>::do_length(__codecvt_utf16_base<char16_t> *this,__mbstate_t *param_1,char *param_2,char *param_3,ulong param_4);
bool std::(anonymous_namespace)::write_utf16_code_point<>(range *param_1,wchar32 param_2,codecvt_mode param_3);
undefined8 std::(anonymous_namespace)::ucs4_out(range *param_1,range *param_2,ulong param_3,codecvt_mode param_4);
undefined8 __thiscall std::__codecvt_utf16_base<wchar_t>::do_out(__codecvt_utf16_base<wchar_t> *this,__mbstate_t *param_1,wchar_t *param_2,wchar_t *param_3,wchar_t **param_4,char *param_5,char *param_6,char **param_7);
undefined8 __thiscall std::__codecvt_utf8_utf16_base<wchar_t>::do_out(__codecvt_utf8_utf16_base<wchar_t> *this,__mbstate_t *param_1,wchar_t *param_2,wchar_t *param_3,wchar_t **param_4,char *param_5,char *param_6,char **param_7);
undefined8 __thiscall std::__codecvt_utf8_utf16_base<char32_t>::do_out(__codecvt_utf8_utf16_base<char32_t> *this,__mbstate_t *param_1,wchar32 *param_2,wchar32 *param_3,wchar32 **param_4,char *param_5,char *param_6,char **param_7);
bool std::(anonymous_namespace)::read_bom<>(range *param_1,unsigned_char *param_2);
long __thiscall std::codecvt<>::do_length(codecvt<> *this,__mbstate_t *param_1,uchar *param_2,uchar *param_3,ulong param_4);
undefined8 __thiscall std::codecvt<>::do_in(codecvt<> *this,__mbstate_t *param_1,uchar *param_2,uchar *param_3,uchar **param_4,wchar32 *param_5,wchar32 *param_6,wchar32 **param_7);
int __thiscall std::codecvt<>::do_length(codecvt<> *this,__mbstate_t *param_1,uchar *param_2,uchar *param_3,ulong param_4);
undefined8 __thiscall std::codecvt<>::do_out(codecvt<> *this,__mbstate_t *param_1,wchar16 *param_2,wchar16 *param_3,wchar16 **param_4,uchar *param_5,uchar *param_6,uchar **param_7);
bool std::(anonymous_namespace)::read_bom<>(range *param_1,unsigned_char *param_2);
undefined8 __thiscall std::__codecvt_utf8_utf16_base<char32_t>::do_in(__codecvt_utf8_utf16_base<char32_t> *this,__mbstate_t *param_1,char *param_2,char *param_3,char **param_4,wchar32 *param_5,wchar32 *param_6,wchar32 **param_7);
undefined8 __thiscall std::__codecvt_utf8_utf16_base<wchar_t>::do_in(__codecvt_utf8_utf16_base<wchar_t> *this,__mbstate_t *param_1,char *param_2,char *param_3,char **param_4,wchar_t *param_5,wchar_t *param_6,wchar_t **param_7);
long __thiscall std::__codecvt_utf8_base<char16_t>::do_length(__codecvt_utf8_base<char16_t> *this,__mbstate_t *param_1,char *param_2,char *param_3,ulong param_4);
char * std::(anonymous_namespace)::utf16_span<char>(char *param_1,char *param_2,ulong param_3,wchar32 param_4,codecvt_mode param_5);
long __thiscall std::codecvt<>::do_length(codecvt<> *this,__mbstate_t *param_1,char *param_2,char *param_3,ulong param_4);
long __thiscall std::__codecvt_utf8_utf16_base<char16_t>::do_length(__codecvt_utf8_utf16_base<char16_t> *this,__mbstate_t *param_1,char *param_2,char *param_3,ulong param_4);
long __thiscall std::__codecvt_utf8_utf16_base<char32_t>::do_length(__codecvt_utf8_utf16_base<char32_t> *this,__mbstate_t *param_1,char *param_2,char *param_3,ulong param_4);
long __thiscall std::__codecvt_utf8_utf16_base<wchar_t>::do_length(__codecvt_utf8_utf16_base<wchar_t> *this,__mbstate_t *param_1,char *param_2,char *param_3,ulong param_4);
result std::(anonymous_namespace)::utf16_in<>(range *param_1,range *param_2,ulong param_3,codecvt_mode param_4,surrogates param_5);
void __thiscall std::codecvt<>::do_in(codecvt<> *this,__mbstate_t *param_1,char *param_2,char *param_3,char **param_4,wchar16 *param_5,wchar16 *param_6,wchar16 **param_7);
void __thiscall std::__codecvt_utf8_utf16_base<char16_t>::do_in(__codecvt_utf8_utf16_base<char16_t> *this,__mbstate_t *param_1,char *param_2,char *param_3,char **param_4,wchar16 *param_5,wchar16 *param_6,wchar16 **param_7);
void __thiscall std::__codecvt_utf8_base<char16_t>::do_in(__codecvt_utf8_base<char16_t> *this,__mbstate_t *param_1,char *param_2,char *param_3,char **param_4,wchar16 *param_5,wchar16 *param_6,wchar16 **param_7);
char * std::(anonymous_namespace)::ucs4_span<char>(char *param_1,char *param_2,ulong param_3,wchar32 param_4,codecvt_mode param_5);
long __thiscall std::codecvt<>::do_length(codecvt<> *this,__mbstate_t *param_1,char *param_2,char *param_3,ulong param_4);
long __thiscall std::__codecvt_utf8_base<char32_t>::do_length(__codecvt_utf8_base<char32_t> *this,__mbstate_t *param_1,char *param_2,char *param_3,ulong param_4);
long __thiscall std::__codecvt_utf8_base<wchar_t>::do_length(__codecvt_utf8_base<wchar_t> *this,__mbstate_t *param_1,char *param_2,char *param_3,ulong param_4);
result std::(anonymous_namespace)::ucs4_in<char>(range *param_1,range *param_2,ulong param_3,codecvt_mode param_4);
void __thiscall std::codecvt<>::do_in(codecvt<> *this,__mbstate_t *param_1,char *param_2,char *param_3,char **param_4,wchar32 *param_5,wchar32 *param_6,wchar32 **param_7);
void __thiscall std::__codecvt_utf8_base<char32_t>::do_in(__codecvt_utf8_base<char32_t> *this,__mbstate_t *param_1,char *param_2,char *param_3,char **param_4,wchar32 *param_5,wchar32 *param_6,wchar32 **param_7);
void __thiscall std::__codecvt_utf8_base<wchar_t>::do_in(__codecvt_utf8_base<wchar_t> *this,__mbstate_t *param_1,char *param_2,char *param_3,char **param_4,wchar_t *param_5,wchar_t *param_6,wchar_t **param_7);
undefined8 __thiscall std::codecvt<>::do_in(codecvt<> *this,__mbstate_t *param_1,uchar *param_2,uchar *param_3,uchar **param_4,wchar16 *param_5,wchar16 *param_6,wchar16 **param_7);
undefined8 __thiscall std::codecvt<>::do_out(codecvt<> *this,__mbstate_t *param_1,wchar32 *param_2,wchar32 *param_3,wchar32 **param_4,char *param_5,char *param_6,char **param_7);
undefined8 __thiscall std::__codecvt_utf16_base<char32_t>::do_out(__codecvt_utf16_base<char32_t> *this,__mbstate_t *param_1,wchar32 *param_2,wchar32 *param_3,wchar32 **param_4,char *param_5,char *param_6,char **param_7);
result __thiscall std::__codecvt_utf8_utf16_base<char16_t>::do_out(__codecvt_utf8_utf16_base<char16_t> *this,__mbstate_t *param_1,wchar16 *param_2,wchar16 *param_3,wchar16 **param_4,char *param_5,char *param_6,char **param_7);
long __thiscall std::__codecvt_utf16_base<wchar_t>::do_length(__codecvt_utf16_base<wchar_t> *this,__mbstate_t *param_1,char *param_2,char *param_3,ulong param_4);
undefined8 __thiscall std::codecvt<>::do_out(codecvt<> *this,__mbstate_t *param_1,wchar32 *param_2,wchar32 *param_3,wchar32 **param_4,uchar *param_5,uchar *param_6,uchar **param_7);
void __thiscall std::locale::_Impl::_M_init_extra(_Impl *this,facet **param_1);
void std::locale::_Impl::_M_init_extra(void *param_1,void *param_2,char *param_3,char *param_4);
void std::locale::name(void);
void std::__facet_shims::(anonymous_namespace)::collate_shim<char>::do_compare(char *param_1,char *param_2,char *param_3,char *param_4);
void std::__facet_shims::(anonymous_namespace)::time_get_shim<char>::do_get_year(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,undefined param_6,_Ios_Iostate *param_7,tm *param_8);
void std::__facet_shims::(anonymous_namespace)::time_get_shim<char>::do_get_monthname(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,undefined param_6,_Ios_Iostate *param_7,tm *param_8);
void std::__facet_shims::(anonymous_namespace)::time_get_shim<char>::do_get_weekday(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,undefined param_6,_Ios_Iostate *param_7,tm *param_8);
void std::__facet_shims::(anonymous_namespace)::time_get_shim<char>::do_get_date(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,undefined param_6,_Ios_Iostate *param_7,tm *param_8);
void std::__facet_shims::(anonymous_namespace)::time_get_shim<char>::do_get_time(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,undefined param_6,_Ios_Iostate *param_7,tm *param_8);
void std::__facet_shims::(anonymous_namespace)::time_get_shim<char>::do_date_order(void);
void std::__facet_shims::(anonymous_namespace)::money_get_shim<char>::do_get(istreambuf_iterator param_1,istreambuf_iterator param_2,bool param_3,ios_base *param_4,_Ios_Iostate *param_5,longdouble *param_6,ios_base *param_7,int *param_8,longdouble *param_9);
void std::__facet_shims::(anonymous_namespace)::money_put_shim<char>::do_put(ostreambuf_iterator param_1,bool param_2,ios_base *param_3,char param_4,longdouble param_5);
void std::__facet_shims::(anonymous_namespace)::messages_shim<char>::do_close(int param_1);
void std::__facet_shims::(anonymous_namespace)::messages_shim<char>::do_open(string *param_1,locale *param_2);
void std::__facet_shims::(anonymous_namespace)::collate_shim<wchar_t>::do_compare(wchar_t *param_1,wchar_t *param_2,wchar_t *param_3,wchar_t *param_4);
void std::__facet_shims::(anonymous_namespace)::time_get_shim<wchar_t>::do_get_year(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,undefined param_6,tm *param_7,undefined8 param_8);
void std::__facet_shims::(anonymous_namespace)::time_get_shim<wchar_t>::do_get_monthname(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,undefined param_6,tm *param_7,undefined8 param_8);
void std::__facet_shims::(anonymous_namespace)::time_get_shim<wchar_t>::do_get_weekday(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,undefined param_6,tm *param_7,undefined8 param_8);
void std::__facet_shims::(anonymous_namespace)::time_get_shim<wchar_t>::do_get_date(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,undefined param_6,tm *param_7,undefined8 param_8);
void std::__facet_shims::(anonymous_namespace)::time_get_shim<wchar_t>::do_get_time(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,undefined param_6,tm *param_7,undefined8 param_8);
void std::__facet_shims::(anonymous_namespace)::time_get_shim<wchar_t>::do_date_order(void);
void std::__facet_shims::(anonymous_namespace)::money_get_shim<wchar_t>::do_get(istreambuf_iterator param_1,istreambuf_iterator param_2,bool param_3,ios_base *param_4,_Ios_Iostate *param_5,longdouble *param_6,ios_base *param_7,int *param_8,longdouble *param_9);
void std::__facet_shims::(anonymous_namespace)::money_put_shim<wchar_t>::do_put(ostreambuf_iterator param_1,bool param_2,ios_base *param_3,wchar_t param_4,longdouble param_5);
void std::__facet_shims::(anonymous_namespace)::messages_shim<wchar_t>::do_close(int param_1);
void std::__facet_shims::(anonymous_namespace)::messages_shim<wchar_t>::do_open(string *param_1,locale *param_2);
undefined  [16]std::__facet_shims::(anonymous_namespace)::money_put_shim<wchar_t>::do_put(ostreambuf_iterator param_1,bool param_2,ios_base *param_3,wchar_t param_4,wstring *param_5,undefined param_6,wstring *param_7);
undefined  [16]std::__facet_shims::(anonymous_namespace)::money_put_shim<char>::do_put(ostreambuf_iterator param_1,bool param_2,ios_base *param_3,char param_4,string *param_5,char param_6,string *param_7);
char * std::__facet_shims::(anonymous_namespace)::collate_shim<char>::do_transform(char *param_1,char *param_2);
wchar_t * std::__facet_shims::(anonymous_namespace)::collate_shim<wchar_t>::do_transform(wchar_t *param_1,wchar_t *param_2);
string * std::__facet_shims::(anonymous_namespace)::messages_shim<char>::do_get(int param_1,int param_2,int param_3,string *param_4);
wstring * std::__facet_shims::(anonymous_namespace)::messages_shim<wchar_t>::do_get(int param_1,int param_2,int param_3,wstring *param_4);
void __thiscall std::__facet_shims::(anonymous_namespace)::moneypunct_shim<char,true>::~moneypunct_shim(moneypunct_shim<char,true> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::numpunct_shim<wchar_t>::~numpunct_shim(numpunct_shim<wchar_t> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::moneypunct_shim<>::~moneypunct_shim(moneypunct_shim<> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::numpunct_shim<char>::~numpunct_shim(numpunct_shim<char> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::moneypunct_shim<>::~moneypunct_shim(moneypunct_shim<> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::moneypunct_shim<char,false>::~moneypunct_shim(moneypunct_shim<char,false> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::collate_shim<char>::~collate_shim(collate_shim<char> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::collate_shim<wchar_t>::~collate_shim(collate_shim<wchar_t> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::messages_shim<wchar_t>::~messages_shim(messages_shim<wchar_t> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::messages_shim<char>::~messages_shim(messages_shim<char> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::money_put_shim<char>::~money_put_shim(money_put_shim<char> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::money_get_shim<char>::~money_get_shim(money_get_shim<char> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::money_put_shim<wchar_t>::~money_put_shim(money_put_shim<wchar_t> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::time_get_shim<wchar_t>::~time_get_shim(time_get_shim<wchar_t> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::money_get_shim<wchar_t>::~money_get_shim(money_get_shim<wchar_t> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::time_get_shim<char>::~time_get_shim(time_get_shim<char> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::messages_shim<char>::~messages_shim(messages_shim<char> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::numpunct_shim<wchar_t>::~numpunct_shim(numpunct_shim<wchar_t> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::messages_shim<wchar_t>::~messages_shim(messages_shim<wchar_t> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::numpunct_shim<char>::~numpunct_shim(numpunct_shim<char> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::time_get_shim<char>::~time_get_shim(time_get_shim<char> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::time_get_shim<wchar_t>::~time_get_shim(time_get_shim<wchar_t> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::collate_shim<char>::~collate_shim(collate_shim<char> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::money_put_shim<char>::~money_put_shim(money_put_shim<char> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::money_put_shim<wchar_t>::~money_put_shim(money_put_shim<wchar_t> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::money_get_shim<wchar_t>::~money_get_shim(money_get_shim<wchar_t> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::collate_shim<wchar_t>::~collate_shim(collate_shim<wchar_t> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::money_get_shim<char>::~money_get_shim(money_get_shim<char> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::moneypunct_shim<>::~moneypunct_shim(moneypunct_shim<> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::moneypunct_shim<char,true>::~moneypunct_shim(moneypunct_shim<char,true> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::moneypunct_shim<>::~moneypunct_shim(moneypunct_shim<> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::moneypunct_shim<char,false>::~moneypunct_shim(moneypunct_shim<char,false> *this);
void std::__facet_shims::(anonymous_namespace)::__destroy_string<wchar_t>(void *param_1);
void std::__facet_shims::(anonymous_namespace)::__destroy_string<char>(void *param_1);
undefined  [16]std::__facet_shims::(anonymous_namespace)::money_get_shim<wchar_t>::do_get(istreambuf_iterator param_1,istreambuf_iterator param_2,bool param_3,ios_base *param_4,_Ios_Iostate *param_5,wstring *param_6,ios_base *param_7,int *param_8,wstring *param_9);
undefined  [16]std::__facet_shims::(anonymous_namespace)::money_get_shim<char>::do_get(istreambuf_iterator param_1,istreambuf_iterator param_2,bool param_3,ios_base *param_4,_Ios_Iostate *param_5,string *param_6,ios_base *param_7,int *param_8,string *param_9);
void __thiscall std::locale::facet::_M_remove_reference(facet *this);
void std::__facet_shims::__numpunct_fill_cache<char>(integral_constant param_1,facet *param_2,__numpunct_cache *param_3);
void std::__facet_shims::__numpunct_fill_cache<wchar_t>(integral_constant param_1,facet *param_2,__numpunct_cache *param_3);
int std::__facet_shims::__collate_compare<char>(integral_constant param_1,facet *param_2,char *param_3,char *param_4,char *param_5,char *param_6);
int std::__facet_shims::__collate_compare<wchar_t>(integral_constant param_1,facet *param_2,wchar_t *param_3,wchar_t *param_4,wchar_t *param_5,wchar_t *param_6);
void std::__facet_shims::__collate_transform<char>(integral_constant param_1,facet *param_2,__any_string *param_3,char *param_4,char *param_5);
void std::__facet_shims::__collate_transform<wchar_t>(integral_constant param_1,facet *param_2,__any_string *param_3,wchar_t *param_4,wchar_t *param_5);
void std::__facet_shims::__moneypunct_fill_cache<char,true>(integral_constant param_1,facet *param_2,__moneypunct_cache *param_3);
void std::__facet_shims::__moneypunct_fill_cache<char,false>(integral_constant param_1,facet *param_2,__moneypunct_cache *param_3);
void std::__facet_shims::__moneypunct_fill_cache<>(integral_constant param_1,facet *param_2,__moneypunct_cache *param_3);
void std::__facet_shims::__moneypunct_fill_cache<>(integral_constant param_1,facet *param_2,__moneypunct_cache *param_3);
int std::__facet_shims::__messages_open<char>(integral_constant param_1,facet *param_2,char *param_3,ulong param_4,locale *param_5);
int std::__facet_shims::__messages_open<wchar_t>(integral_constant param_1,facet *param_2,char *param_3,ulong param_4,locale *param_5);
void std::__facet_shims::__messages_get<char>(integral_constant param_1,facet *param_2,__any_string *param_3,int param_4,int param_5,int param_6,char *param_7,ulong param_8);
void std::__facet_shims::__messages_get<wchar_t>(integral_constant param_1,facet *param_2,__any_string *param_3,int param_4,int param_5,int param_6,wchar_t *param_7,ulong param_8);
void std::__facet_shims::__messages_close<char>(integral_constant param_1,facet *param_2,int param_3);
void std::__facet_shims::__messages_close<wchar_t>(integral_constant param_1,facet *param_2,int param_3);
dateorder std::__facet_shims::__time_get_dateorder<char>(integral_constant param_1,facet *param_2);
dateorder std::__facet_shims::__time_get_dateorder<wchar_t>(integral_constant param_1,facet *param_2);
istreambuf_iterator __thiscall std::__facet_shims::__time_get<char>(__facet_shims *this,integral_constant param_1,facet *param_2,istreambuf_iterator param_3,istreambuf_iterator param_4,ios_base *param_5,_Ios_Iostate *param_6,tm *param_7,char param_8);
istreambuf_iterator __thiscall std::__facet_shims::__time_get<wchar_t>(__facet_shims *this,integral_constant param_1,facet *param_2,istreambuf_iterator param_3,istreambuf_iterator param_4,ios_base *param_5,_Ios_Iostate *param_6,tm *param_7,char param_8);
istreambuf_iterator __thiscall std::__facet_shims::__money_get<char>(__facet_shims *this,integral_constant param_1,facet *param_2,istreambuf_iterator param_3,istreambuf_iterator param_4,bool param_5,ios_base *param_6,_Ios_Iostate *param_7,longdouble *param_8,__any_string *param_9);
istreambuf_iterator __thiscall std::__facet_shims::__money_get<wchar_t>(__facet_shims *this,integral_constant param_1,facet *param_2,istreambuf_iterator param_3,istreambuf_iterator param_4,bool param_5,ios_base *param_6,_Ios_Iostate *param_7,longdouble *param_8,__any_string *param_9);
ostreambuf_iterator __thiscall std::__facet_shims::__money_put<char>(__facet_shims *this,integral_constant param_1,facet *param_2,ostreambuf_iterator param_3,bool param_4,ios_base *param_5,char param_6,longdouble param_7,__any_string *param_8);
ostreambuf_iterator __thiscall std::__facet_shims::__money_put<wchar_t>(__facet_shims *this,integral_constant param_1,facet *param_2,ostreambuf_iterator param_3,bool param_4,ios_base *param_5,wchar_t param_6,longdouble param_7,__any_string *param_8);
__locale_struct * __thiscall std::locale::facet::_M_cow_shim(facet *this,id *param_1);
long __thiscall std::stringbuf::showmanyc(stringbuf *this);
ulong __thiscall std::stringbuf::underflow(stringbuf *this);
int __thiscall std::stringbuf::pbackfail(stringbuf *this,int param_1);
long __thiscall std::wstringbuf::showmanyc(wstringbuf *this);
uint __thiscall std::wstringbuf::pbackfail(wstringbuf *this,uint param_1);
undefined4 __thiscall std::wstringbuf::underflow(wstringbuf *this);
void __thiscall std::wstringbuf::~wstringbuf(wstringbuf *this);
void __thiscall std::wstringstream::~wstringstream(wstringstream *this);
void __thiscall std::wstringstream::~wstringstream(wstringstream *this);
void __thiscall std::wstringstream::~wstringstream(wstringstream *this);
void __thiscall std::wostringstream::~wostringstream(wostringstream *this);
void __thiscall std::wostringstream::~wostringstream(wostringstream *this);
void __thiscall std::wostringstream::~wostringstream(wostringstream *this);
void __thiscall std::wostringstream::~wostringstream(wostringstream *this);
void __thiscall std::ostringstream::~ostringstream(ostringstream *this);
void __thiscall std::ostringstream::~ostringstream(ostringstream *this);
void __thiscall std::wstringstream::~wstringstream(wstringstream *this);
void __thiscall std::wstringstream::~wstringstream(wstringstream *this);
void __thiscall std::wstringstream::~wstringstream(wstringstream *this);
void __thiscall std::istringstream::~istringstream(istringstream *this);
void __thiscall std::istringstream::~istringstream(istringstream *this);
void __thiscall std::wistringstream::~wistringstream(wistringstream *this);
void __thiscall std::wistringstream::~wistringstream(wistringstream *this);
void __thiscall std::stringstream::~stringstream(stringstream *this);
void __thiscall std::stringstream::~stringstream(stringstream *this);
void __thiscall std::stringstream::~stringstream(stringstream *this);
void __thiscall std::ostringstream::~ostringstream(ostringstream *this);
void __thiscall std::ostringstream::~ostringstream(ostringstream *this);
void __thiscall std::istringstream::~istringstream(istringstream *this);
void __thiscall std::istringstream::~istringstream(istringstream *this);
void __thiscall std::stringstream::~stringstream(stringstream *this);
void __thiscall std::stringstream::~stringstream(stringstream *this);
void __thiscall std::stringstream::~stringstream(stringstream *this);
void __thiscall std::wistringstream::~wistringstream(wistringstream *this);
void __thiscall std::wistringstream::~wistringstream(wistringstream *this);
void __thiscall std::wstringbuf::~wstringbuf(wstringbuf *this);
void __thiscall std::stringbuf::stringbuf(stringbuf *this);
void __thiscall std::stringbuf::stringbuf(stringbuf *this,_Ios_Openmode param_1);
void __thiscall std::stringbuf::swap(stringbuf *this,stringbuf *param_1);
void std::stringbuf::str(void);
void __thiscall std::stringbuf::_M_update_egptr(stringbuf *this);
void __thiscall std::stringbuf::_M_pbump(stringbuf *this,char *param_1,char *param_2,long param_3);
void __thiscall std::stringbuf::_M_sync(stringbuf *this,char *param_1,ulong param_2,ulong param_3);
void __thiscall std::stringbuf::_M_stringbuf_init(stringbuf *this,_Ios_Openmode param_1);
stringbuf * __thiscall std::stringbuf::operator=(stringbuf *this,stringbuf *param_1);
int __thiscall std::stringbuf::overflow(stringbuf *this,int param_1);
stringbuf * __thiscall std::stringbuf::setbuf(stringbuf *this,char *param_1,long param_2);
void __thiscall std::stringbuf::stringbuf(stringbuf *this,stringbuf *param_1);
void __thiscall std::stringbuf::str(stringbuf *this,string *param_1);
void __thiscall std::stringbuf::stringbuf(stringbuf *this,string *param_1,_Ios_Openmode param_2);
undefined  [16] __thiscall std::stringbuf::seekoff(stringbuf *this,long param_1,_Ios_Seekdir param_2,_Ios_Openmode param_3);
undefined  [16] std::stringbuf::seekpos(fpos param_1,_Ios_Openmode param_2);
void __thiscall std::stringbuf::stringbuf(stringbuf *this,stringbuf *param_1,__xfer_bufptrs *param_2);
void __thiscall std::stringbuf::__xfer_bufptrs::__xfer_bufptrs(__xfer_bufptrs *this,stringbuf *param_1,stringbuf *param_2);
void __thiscall std::istringstream::istringstream(istringstream *this);
void __thiscall std::istringstream::istringstream(istringstream *this);
void __thiscall std::istringstream::istringstream(istringstream *this,_Ios_Openmode param_1);
void __thiscall std::istringstream::istringstream(istringstream *this,_Ios_Openmode param_1);
void __thiscall std::istringstream::istringstream(istringstream *this,string *param_1,_Ios_Openmode param_2);
void __thiscall std::istringstream::istringstream(istringstream *this,string *param_1,_Ios_Openmode param_2);
void __thiscall std::istringstream::~istringstream(istringstream *this);
void __thiscall std::istringstream::istringstream(istringstream *this,istringstream *param_1);
void __thiscall std::istringstream::istringstream(istringstream *this,istringstream *param_1);
istringstream * __thiscall std::istringstream::operator=(istringstream *this,istringstream *param_1);
void __thiscall std::istringstream::swap(istringstream *this,istringstream *param_1);
istringstream * __thiscall std::istringstream::rdbuf(istringstream *this);
void std::istringstream::str(void);
void __thiscall std::istringstream::str(istringstream *this,string *param_1);
void __thiscall std::ostringstream::ostringstream(ostringstream *this);
void __thiscall std::ostringstream::ostringstream(ostringstream *this);
void __thiscall std::ostringstream::ostringstream(ostringstream *this,_Ios_Openmode param_1);
void __thiscall std::ostringstream::ostringstream(ostringstream *this,_Ios_Openmode param_1);
void __thiscall std::ostringstream::ostringstream(ostringstream *this,string *param_1,_Ios_Openmode param_2);
void __thiscall std::ostringstream::ostringstream(ostringstream *this,string *param_1,_Ios_Openmode param_2);
void __thiscall std::ostringstream::~ostringstream(ostringstream *this);
void __thiscall std::ostringstream::ostringstream(ostringstream *this,ostringstream *param_1);
void __thiscall std::ostringstream::ostringstream(ostringstream *this,ostringstream *param_1);
ostringstream * __thiscall std::ostringstream::operator=(ostringstream *this,ostringstream *param_1);
void __thiscall std::ostringstream::swap(ostringstream *this,ostringstream *param_1);
ostringstream * __thiscall std::ostringstream::rdbuf(ostringstream *this);
void std::ostringstream::str(void);
void __thiscall std::ostringstream::str(ostringstream *this,string *param_1);
void __thiscall std::stringstream::stringstream(stringstream *this);
void __thiscall std::stringstream::stringstream(stringstream *this);
void __thiscall std::stringstream::stringstream(stringstream *this,_Ios_Openmode param_1);
void __thiscall std::stringstream::stringstream(stringstream *this,_Ios_Openmode param_1);
void __thiscall std::stringstream::stringstream(stringstream *this,string *param_1,_Ios_Openmode param_2);
void __thiscall std::stringstream::stringstream(stringstream *this,string *param_1,_Ios_Openmode param_2);
void __thiscall std::stringstream::~stringstream(stringstream *this);
void __thiscall std::stringstream::stringstream(stringstream *this,stringstream *param_1);
void __thiscall std::stringstream::stringstream(stringstream *this,stringstream *param_1);
stringstream * __thiscall std::stringstream::operator=(stringstream *this,stringstream *param_1);
void __thiscall std::stringstream::swap(stringstream *this,stringstream *param_1);
stringstream * __thiscall std::stringstream::rdbuf(stringstream *this);
void std::stringstream::str(void);
void __thiscall std::stringstream::str(stringstream *this,string *param_1);
void __thiscall std::wstringbuf::wstringbuf(wstringbuf *this);
void __thiscall std::wstringbuf::wstringbuf(wstringbuf *this,_Ios_Openmode param_1);
void __thiscall std::wstringbuf::swap(wstringbuf *this,wstringbuf *param_1);
void std::wstringbuf::str(void);
void __thiscall std::wstringbuf::_M_update_egptr(wstringbuf *this);
void __thiscall std::wstringbuf::_M_pbump(wstringbuf *this,wchar_t *param_1,wchar_t *param_2,long param_3);
void __thiscall std::wstringbuf::_M_sync(wstringbuf *this,wchar_t *param_1,ulong param_2,ulong param_3);
void __thiscall std::wstringbuf::_M_stringbuf_init(wstringbuf *this,_Ios_Openmode param_1);
wstringbuf * __thiscall std::wstringbuf::operator=(wstringbuf *this,wstringbuf *param_1);
uint __thiscall std::wstringbuf::overflow(wstringbuf *this,uint param_1);
wstringbuf * __thiscall std::wstringbuf::setbuf(wstringbuf *this,wchar_t *param_1,long param_2);
void __thiscall std::wstringbuf::wstringbuf(wstringbuf *this,wstringbuf *param_1);
void __thiscall std::wstringbuf::str(wstringbuf *this,wstring *param_1);
void __thiscall std::wstringbuf::wstringbuf(wstringbuf *this,wstring *param_1,_Ios_Openmode param_2);
undefined  [16] __thiscall std::wstringbuf::seekoff(wstringbuf *this,long param_1,_Ios_Seekdir param_2,_Ios_Openmode param_3);
undefined  [16] std::wstringbuf::seekpos(fpos param_1,_Ios_Openmode param_2);
void __thiscall std::wstringbuf::wstringbuf(wstringbuf *this,wstringbuf *param_1,__xfer_bufptrs *param_2);
void __thiscall std::wstringbuf::__xfer_bufptrs::__xfer_bufptrs(__xfer_bufptrs *this,wstringbuf *param_1,wstringbuf *param_2);
void __thiscall td::wistringstream::wistringstream(wistringstream *this);
void __thiscall td::wistringstream::wistringstream(wistringstream *this);
void __thiscall td::wistringstream::wistringstream(wistringstream *this,_Ios_Openmode param_1);
void __thiscall td::wistringstream::wistringstream(wistringstream *this,_Ios_Openmode param_1);
void __thiscall td::wistringstream::wistringstream(wistringstream *this,wstring *param_1,_Ios_Openmode param_2);
void __thiscall td::wistringstream::wistringstream(wistringstream *this,wstring *param_1,_Ios_Openmode param_2);
void __thiscall std::wistringstream::~wistringstream(wistringstream *this);
void __thiscall td::wistringstream::wistringstream(wistringstream *this,wistringstream *param_1);
void __thiscall td::wistringstream::wistringstream(wistringstream *this,wistringstream *param_1);
wistringstream * __thiscall std::wistringstream::operator=(wistringstream *this,wistringstream *param_1);
void __thiscall std::wistringstream::swap(wistringstream *this,wistringstream *param_1);
wistringstream * __thiscall std::wistringstream::rdbuf(wistringstream *this);
void std::wistringstream::str(void);
void __thiscall std::wistringstream::str(wistringstream *this,wstring *param_1);
void __thiscall std::wostringstream::wostringstream(wostringstream *this);
void __thiscall std::wostringstream::wostringstream(wostringstream *this);
void __thiscall std::wostringstream::wostringstream(wostringstream *this,_Ios_Openmode param_1);
void __thiscall std::wostringstream::wostringstream(wostringstream *this,_Ios_Openmode param_1);
void __thiscall std::wostringstream::wostringstream(wostringstream *this,wstring *param_1,_Ios_Openmode param_2);
void __thiscall std::wostringstream::wostringstream(wostringstream *this,wstring *param_1,_Ios_Openmode param_2);
void __thiscall std::wostringstream::~wostringstream(wostringstream *this);
void __thiscall std::wostringstream::wostringstream(wostringstream *this,wostringstream *param_1);
void __thiscall std::wostringstream::wostringstream(wostringstream *this,wostringstream *param_1);
wostringstream * __thiscall std::wostringstream::operator=(wostringstream *this,wostringstream *param_1);
void __thiscall std::wostringstream::swap(wostringstream *this,wostringstream *param_1);
wostringstream * __thiscall std::wostringstream::rdbuf(wostringstream *this);
void std::wostringstream::str(void);
void __thiscall std::wostringstream::str(wostringstream *this,wstring *param_1);
void __thiscall std::wstringstream::wstringstream(wstringstream *this);
void __thiscall std::wstringstream::wstringstream(wstringstream *this);
void __thiscall std::wstringstream::wstringstream(wstringstream *this,_Ios_Openmode param_1);
void __thiscall std::wstringstream::wstringstream(wstringstream *this,_Ios_Openmode param_1);
void __thiscall std::wstringstream::wstringstream(wstringstream *this,wstring *param_1,_Ios_Openmode param_2);
void __thiscall std::wstringstream::wstringstream(wstringstream *this,wstring *param_1,_Ios_Openmode param_2);
void __thiscall std::wstringstream::~wstringstream(wstringstream *this);
void __thiscall std::wstringstream::wstringstream(wstringstream *this,wstringstream *param_1);
void __thiscall std::wstringstream::wstringstream(wstringstream *this,wstringstream *param_1);
wstringstream * __thiscall std::wstringstream::operator=(wstringstream *this,wstringstream *param_1);
void __thiscall std::wstringstream::swap(wstringstream *this,wstringstream *param_1);
wstringstream * __thiscall std::wstringstream::rdbuf(wstringstream *this);
void std::wstringstream::str(void);
void __thiscall std::wstringstream::str(wstringstream *this,wstring *param_1);
undefined8 __thiscall std::string::_M_data(string *this);
char * __thiscall std::string::_M_data(string *this,char *param_1);
long __thiscall std::string::_M_rep(string *this);
undefined8 __thiscall std::string::_M_ibegin(string *this);
long __thiscall std::string::_M_iend(string *this);
void __thiscall std::string::_M_check(string *this,ulong param_1,char *param_2);
void __thiscall std::string::_M_check_length(string *this,ulong param_1,ulong param_2,char *param_3);
ulong __thiscall std::string::_M_limit(string *this,ulong param_1,ulong param_2);
bool __thiscall std::string::_M_disjunct(string *this,char *param_1);
void std::string::_M_copy(char *param_1,char *param_2,ulong param_3);
void std::string::_M_move(char *param_1,char *param_2,ulong param_3);
void std::string::_M_assign(char *param_1,ulong param_2,char param_3);
void std::string::_S_copy_chars(char *param_1,__normal_iterator param_2,__normal_iterator param_3);
void std::string::_S_copy_chars(char *param_1,__normal_iterator param_2,__normal_iterator param_3);
void std::string::_S_copy_chars(char *param_1,char *param_2,char *param_3);
void std::string::_S_copy_chars(char *param_1,char *param_2,char *param_3);
ulong std::string::_S_compare(ulong param_1,ulong param_2);
undefined8 * std::string::_S_empty_rep(void);
void __thiscall std::string::string(string *this);
void __thiscall std::string::string(string *this,string *param_1);
void __thiscall std::string::string(string *this,string *param_1,allocator *param_2);
undefined8 __thiscall std::string::begin(string *this);
long __thiscall std::string::end(string *this);
void std::string::rbegin(void);
void std::string::rend(void);
undefined8 __thiscall std::string::cbegin(string *this);
long __thiscall std::string::cend(string *this);
void std::string::crbegin(void);
void std::string::crend(void);
undefined8 __thiscall std::string::size(string *this);
undefined8 __thiscall std::string::length(string *this);
undefined8 std::string::max_size(void);
undefined8 __thiscall std::string::capacity(string *this);
undefined8 __thiscall std::string::empty(string *this);
long __thiscall std::string::operator[](string *this,ulong param_1);
long __thiscall std::string::at(string *this,ulong param_1);
undefined8 __thiscall std::string::front(string *this);
long __thiscall std::string::back(string *this);
size_t __thiscall std::string::copy(string *this,char *param_1,ulong param_2,ulong param_3);
void __thiscall std::string::swap(string *this,string *param_1);
string * __thiscall std::string::operator=(string *this,string *param_1);
string * __thiscall std::string::assign(string *this,string *param_1);
undefined8 __thiscall std::string::c_str(string *this);
undefined8 __thiscall std::string::data(string *this);
string * __thiscall std::string::get_allocator(string *this);
ulong __thiscall std::string::find(string *this,char *param_1,ulong param_2,ulong param_3);
void __thiscall std::string::find(string *this,string *param_1,ulong param_2);
void __thiscall std::string::find(string *this,char *param_1,ulong param_2);
long __thiscall std::string::find(string *this,char param_1,ulong param_2);
ulong __thiscall std::string::rfind(string *this,char *param_1,ulong param_2,ulong param_3);
void __thiscall std::string::rfind(string *this,string *param_1,ulong param_2);
void __thiscall std::string::rfind(string *this,char *param_1,ulong param_2);
ulong __thiscall std::string::rfind(string *this,char param_1,ulong param_2);
ulong __thiscall std::string::find_first_of(string *this,char *param_1,ulong param_2,ulong param_3);
void __thiscall std::string::find_first_of(string *this,string *param_1,ulong param_2);
void __thiscall std::string::find_first_of(string *this,char *param_1,ulong param_2);
void __thiscall std::string::find_first_of(string *this,char param_1,ulong param_2);
ulong __thiscall std::string::find_last_of(string *this,char *param_1,ulong param_2,ulong param_3);
void __thiscall std::string::find_last_of(string *this,string *param_1,ulong param_2);
void __thiscall std::string::find_last_of(string *this,char *param_1,ulong param_2);
void __thiscall std::string::find_last_of(string *this,char param_1,ulong param_2);
ulong __thiscall std::string::find_first_not_of(string *this,char *param_1,ulong param_2,ulong param_3);
void __thiscall std::string::find_first_not_of(string *this,string *param_1,ulong param_2);
void __thiscall std::string::find_first_not_of(string *this,char *param_1,ulong param_2);
ulong __thiscall std::string::find_first_not_of(string *this,char param_1,ulong param_2);
ulong __thiscall std::string::find_last_not_of(string *this,char *param_1,ulong param_2,ulong param_3);
void __thiscall std::string::find_last_not_of(string *this,string *param_1,ulong param_2);
void __thiscall std::string::find_last_not_of(string *this,char *param_1,ulong param_2);
ulong __thiscall std::string::find_last_not_of(string *this,char param_1,ulong param_2);
ulong __thiscall std::string::compare(string *this,string *param_1);
ulong __thiscall std::string::compare(string *this,ulong param_1,ulong param_2,string *param_3);
ulong __thiscall std::string::compare(string *this,ulong param_1,ulong param_2,string *param_3,ulong param_4,ulong param_5);
ulong __thiscall std::string::compare(string *this,char *param_1);
ulong __thiscall std::string::compare(string *this,ulong param_1,ulong param_2,char *param_3);
ulong __thiscall std::string::compare(string *this,ulong param_1,ulong param_2,char *param_3,ulong param_4);
void __thiscall std::string::_Alloc_hider::_Alloc_hider(_Alloc_hider *this,char *param_1,allocator *param_2);
undefined8 * std::string::_Rep::_S_empty_rep(void);
uint __thiscall std::string::_Rep::_M_is_leaked(_Rep *this);
undefined4 __thiscall std::string::_Rep::_M_is_shared(_Rep *this);
void __thiscall std::string::_Rep::_M_set_leaked(_Rep *this);
void __thiscall std::string::_Rep::_M_set_sharable(_Rep *this);
void __thiscall std::string::_Rep::_M_set_length_and_sharable(_Rep *this,ulong param_1);
_Rep * __thiscall std::string::_Rep::_M_refdata(_Rep *this);
void std::string::_Rep::_S_create(ulong param_1,ulong param_2,allocator *param_3);
ulong * std::string::_S_construct(ulong param_1,char param_2,allocator *param_3);
void __thiscall std::string::string(string *this,allocator *param_1);
void __thiscall std::string::string(string *this,ulong param_1,char param_2,allocator *param_3);
void std::string::_S_construct_aux_2(ulong param_1,char param_2,allocator *param_3);
char * std::string::_S_construct<>(char *param_1,char *param_2,allocator *param_3,forward_iterator_tag param_4);
void std::string::_Rep::_M_destroy(allocator *param_1);
void std::string::_Rep::_M_dispose(allocator *param_1);
void std::string::_Rep::_M_dispose(allocator *param_1);
void __thiscall std::string::~string(string *this);
void __thiscall std::string::clear(string *this);
void __thiscall std::string::_M_mutate(string *this,ulong param_1,ulong param_2,ulong param_3);
void __thiscall std::string::_M_leak_hard(string *this);
void __thiscall std::string::_M_leak(string *this);
long __thiscall std::string::front(string *this);
long __thiscall std::string::operator[](string *this,ulong param_1);
long __thiscall std::string::begin(string *this);
void std::string::rend(void);
long __thiscall std::string::end(string *this);
void std::string::rbegin(void);
long __thiscall std::string::back(string *this);
long __thiscall std::string::at(string *this,ulong param_1);
string * __thiscall std::string::erase(string *this,ulong param_1,ulong param_2);
long __thiscall std::string::erase(string *this,__normal_iterator param_1);
long __thiscall std::string::erase(string *this,__normal_iterator param_1,__normal_iterator param_2);
string * __thiscall std::string::_M_replace_aux(string *this,ulong param_1,ulong param_2,ulong param_3,char param_4);
void __thiscall std::string::assign(string *this,ulong param_1,char param_2);
string * __thiscall std::string::operator=(string *this,char param_1);
void __thiscall std::string::insert(string *this,ulong param_1,ulong param_2,char param_3);
long __thiscall std::string::insert(string *this,__normal_iterator param_1,char param_2);
void __thiscall std::string::replace(string *this,ulong param_1,ulong param_2,ulong param_3,char param_4);
void __thiscall std::string::replace(string *this,__normal_iterator param_1,__normal_iterator param_2,ulong param_3,char param_4);
void __thiscall std::string::insert(string *this,__normal_iterator param_1,ulong param_2,char param_3);
string * __thiscall std::string::_M_replace_safe(string *this,ulong param_1,ulong param_2,char *param_3,ulong param_4);
string * __thiscall std::string::assign(string *this,char *param_1,ulong param_2);
string * __thiscall std::string::operator=(string *this,initializer_list param_1);
void std::string::assign(string *param_1,ulong param_2,ulong param_3);
void __thiscall std::string::assign(string *this,char *param_1);
void __thiscall std::string::operator=(string *this,char *param_1);
string * std::string::assign(initializer_list param_1);
string * __thiscall std::string::insert(string *this,ulong param_1,char *param_2,ulong param_3);
void std::string::insert(__normal_iterator param_1,initializer_list param_2);
void __thiscall std::string::insert(string *this,ulong param_1,string *param_2,ulong param_3,ulong param_4);
void __thiscall std::string::insert(string *this,ulong param_1,char *param_2);
void __thiscall std::string::insert(string *this,ulong param_1,string *param_2);
void __thiscall std::string::pop_back(string *this);
_Rep * __thiscall std::string::_Rep::_M_refcopy(_Rep *this);
size_t * __thiscall std::string::_Rep::_M_clone(_Rep *this,allocator *param_1,ulong param_2);
void __thiscall std::string::reserve(string *this,ulong param_1);
void __thiscall std::string::shrink_to_fit(string *this);
string * __thiscall std::string::append(string *this,string *param_1);
string * __thiscall std::string::operator+=(string *this,string *param_1);
string * __thiscall std::string::append(string *this,string *param_1,ulong param_2,ulong param_3);
string * __thiscall std::string::append(string *this,char *param_1,ulong param_2);
string * __thiscall std::string::operator+=(string *this,initializer_list param_1);
void __thiscall std::string::append(string *this,char *param_1);
void __thiscall std::string::operator+=(string *this,char *param_1);
string * std::string::append(initializer_list param_1);
string * __thiscall std::string::append(string *this,ulong param_1,char param_2);
void __thiscall std::string::resize(string *this,ulong param_1,char param_2);
void __thiscall std::string::resize(string *this,ulong param_1);
void __thiscall std::string::push_back(string *this,char param_1);
string * __thiscall std::string::operator+=(string *this,char param_1);
allocator * std::string::_Rep::_M_grab(allocator *param_1,allocator *param_2);
void __thiscall std::string::string(string *this,string *param_1);
void __thiscall std::string::string(string *this,string *param_1,allocator *param_2);
string * __thiscall std::string::assign(string *this,string *param_1);
string * __thiscall std::string::operator=(string *this,string *param_1);
string * std::operator+(string *param_1,char *param_2,string *param_3);
string * std::operator+(string *param_1,char param_2,string *param_3);
string * std::operator+(string *param_1,string *param_2,string *param_3);
char * std::string::_S_construct<>(__normal_iterator param_1,__normal_iterator param_2,allocator *param_3,forward_iterator_tag param_4);
void __thiscall std::string::string<>(string *this,__normal_iterator param_1,__normal_iterator param_2,allocator *param_3);
char * std::string::_S_construct<char*>(char *param_1,char *param_2,allocator *param_3,forward_iterator_tag param_4);
void __thiscall std::string::string(string *this,string *param_1,ulong param_2,allocator *param_3);
void __thiscall std::string::string(string *this,string *param_1,ulong param_2,ulong param_3);
ulong std::string::substr(ulong param_1,ulong param_2);
void __thiscall std::string::string(string *this,string *param_1,ulong param_2,ulong param_3,allocator *param_4);
void __thiscall std::string::string<char*>(string *this,char *param_1,char *param_2,allocator *param_3);
char * std::string::_S_construct<>(char *param_1,char *param_2,allocator *param_3,forward_iterator_tag param_4);
void __thiscall std::string::string(string *this,char *param_1,ulong param_2,allocator *param_3);
string * __thiscall std::string::replace(string *this,ulong param_1,ulong param_2,char *param_3,ulong param_4);
void __thiscall std::string::replace(string *this,ulong param_1,ulong param_2,string *param_3);
void __thiscall std::string::replace(string *this,ulong param_1,ulong param_2,string *param_3,ulong param_4,ulong param_5);
void __thiscall std::string::replace(string *this,ulong param_1,ulong param_2,char *param_3);
void __thiscall std::string::replace(string *this,__normal_iterator param_1,__normal_iterator param_2,char *param_3,ulong param_4);
void __thiscall std::string::replace(string *this,__normal_iterator param_1,__normal_iterator param_2,string *param_3);
void __thiscall std::string::replace(string *this,__normal_iterator param_1,__normal_iterator param_2,char *param_3);
void __thiscall std::string::replace(string *this,__normal_iterator param_1,__normal_iterator param_2,char *param_3,char *param_4);
void __thiscall std::string::replace(string *this,__normal_iterator param_1,__normal_iterator param_2,char *param_3,char *param_4);
void std::string::replace(__normal_iterator param_1,__normal_iterator param_2,initializer_list param_3);
void __thiscall std::string::replace(string *this,__normal_iterator param_1,__normal_iterator param_2,__normal_iterator param_3,__normal_iterator param_4);
void __thiscall std::string::replace(string *this,__normal_iterator param_1,__normal_iterator param_2,__normal_iterator param_3,__normal_iterator param_4);
void __thiscall std::string::string(string *this,char *param_1,allocator *param_2);
void __thiscall std::string::string(string *this,initializer_list param_1,allocator *param_2);
void __thiscall std::string::string<>(string *this,char *param_1,char *param_2,allocator *param_3);
bool operator==(__normal_iterator *param_1,__normal_iterator *param_2);
bool operator==(__normal_iterator *param_1,__normal_iterator *param_2);
FILE * __thiscall std::random_device::_M_init(random_device *this,string *param_1);
void __thiscall std::random_device::_M_init_pretr1(random_device *this,string *param_1);
undefined8 __thiscall std::wstring::_M_data(wstring *this);
wchar_t * __thiscall std::wstring::_M_data(wstring *this,wchar_t *param_1);
long __thiscall std::wstring::_M_rep(wstring *this);
undefined8 __thiscall std::wstring::_M_ibegin(wstring *this);
long __thiscall std::wstring::_M_iend(wstring *this);
void __thiscall std::wstring::_M_check(wstring *this,ulong param_1,char *param_2);
void __thiscall std::wstring::_M_check_length(wstring *this,ulong param_1,ulong param_2,char *param_3);
ulong __thiscall std::wstring::_M_limit(wstring *this,ulong param_1,ulong param_2);
bool __thiscall std::wstring::_M_disjunct(wstring *this,wchar_t *param_1);
void std::wstring::_M_copy(wchar_t *param_1,wchar_t *param_2,ulong param_3);
void std::wstring::_M_move(wchar_t *param_1,wchar_t *param_2,ulong param_3);
void std::wstring::_M_assign(wchar_t *param_1,ulong param_2,wchar_t param_3);
void std::wstring::_S_copy_chars(wchar_t *param_1,__normal_iterator param_2,__normal_iterator param_3);
void std::wstring::_S_copy_chars(wchar_t *param_1,__normal_iterator param_2,__normal_iterator param_3);
void std::wstring::_S_copy_chars(wchar_t *param_1,wchar_t *param_2,wchar_t *param_3);
void std::wstring::_S_copy_chars(wchar_t *param_1,wchar_t *param_2,wchar_t *param_3);
ulong std::wstring::_S_compare(ulong param_1,ulong param_2);
undefined8 * std::wstring::_S_empty_rep(void);
void __thiscall std::wstring::wstring(wstring *this);
void __thiscall std::wstring::wstring(wstring *this,wstring *param_1);
void __thiscall std::wstring::wstring(wstring *this,wstring *param_1,allocator *param_2);
undefined8 __thiscall std::wstring::begin(wstring *this);
long __thiscall std::wstring::end(wstring *this);
void std::wstring::rbegin(void);
void std::wstring::rend(void);
undefined8 __thiscall std::wstring::cbegin(wstring *this);
long __thiscall std::wstring::cend(wstring *this);
void std::wstring::crbegin(void);
void std::wstring::crend(void);
undefined8 __thiscall std::wstring::size(wstring *this);
undefined8 __thiscall std::wstring::length(wstring *this);
undefined8 std::wstring::max_size(void);
undefined8 __thiscall std::wstring::capacity(wstring *this);
undefined8 __thiscall std::wstring::empty(wstring *this);
long __thiscall std::wstring::operator[](wstring *this,ulong param_1);
long __thiscall std::wstring::at(wstring *this,ulong param_1);
undefined8 __thiscall std::wstring::front(wstring *this);
long __thiscall std::wstring::back(wstring *this);
size_t __thiscall std::wstring::copy(wstring *this,wchar_t *param_1,ulong param_2,ulong param_3);
void __thiscall std::wstring::swap(wstring *this,wstring *param_1);
wstring * __thiscall std::wstring::operator=(wstring *this,wstring *param_1);
wstring * __thiscall std::wstring::assign(wstring *this,wstring *param_1);
undefined8 __thiscall std::wstring::c_str(wstring *this);
undefined8 __thiscall std::wstring::data(wstring *this);
wstring * __thiscall std::wstring::get_allocator(wstring *this);
ulong __thiscall std::wstring::find(wstring *this,wchar_t *param_1,ulong param_2,ulong param_3);
void __thiscall std::wstring::find(wstring *this,wstring *param_1,ulong param_2);
void __thiscall std::wstring::find(wstring *this,wchar_t *param_1,ulong param_2);
long __thiscall std::wstring::find(wstring *this,wchar_t param_1,ulong param_2);
ulong __thiscall std::wstring::rfind(wstring *this,wchar_t *param_1,ulong param_2,ulong param_3);
void __thiscall std::wstring::rfind(wstring *this,wstring *param_1,ulong param_2);
void __thiscall std::wstring::rfind(wstring *this,wchar_t *param_1,ulong param_2);
ulong __thiscall std::wstring::rfind(wstring *this,wchar_t param_1,ulong param_2);
ulong __thiscall std::wstring::find_first_of(wstring *this,wchar_t *param_1,ulong param_2,ulong param_3);
void __thiscall std::wstring::find_first_of(wstring *this,wstring *param_1,ulong param_2);
void __thiscall std::wstring::find_first_of(wstring *this,wchar_t *param_1,ulong param_2);
long __thiscall std::wstring::find_first_of(wstring *this,wchar_t param_1,ulong param_2);
ulong __thiscall std::wstring::find_last_of(wstring *this,wchar_t *param_1,ulong param_2,ulong param_3);
void __thiscall std::wstring::find_last_of(wstring *this,wstring *param_1,ulong param_2);
void __thiscall std::wstring::find_last_of(wstring *this,wchar_t *param_1,ulong param_2);
ulong __thiscall std::wstring::find_last_of(wstring *this,wchar_t param_1,ulong param_2);
ulong __thiscall std::wstring::find_first_not_of(wstring *this,wchar_t *param_1,ulong param_2,ulong param_3);
void __thiscall std::wstring::find_first_not_of(wstring *this,wstring *param_1,ulong param_2);
void __thiscall std::wstring::find_first_not_of(wstring *this,wchar_t *param_1,ulong param_2);
ulong __thiscall std::wstring::find_first_not_of(wstring *this,wchar_t param_1,ulong param_2);
ulong __thiscall std::wstring::find_last_not_of(wstring *this,wchar_t *param_1,ulong param_2,ulong param_3);
void __thiscall std::wstring::find_last_not_of(wstring *this,wstring *param_1,ulong param_2);
void __thiscall std::wstring::find_last_not_of(wstring *this,wchar_t *param_1,ulong param_2);
ulong __thiscall std::wstring::find_last_not_of(wstring *this,wchar_t param_1,ulong param_2);
ulong __thiscall std::wstring::compare(wstring *this,wstring *param_1);
ulong __thiscall std::wstring::compare(wstring *this,ulong param_1,ulong param_2,wstring *param_3);
ulong __thiscall std::wstring::compare(wstring *this,ulong param_1,ulong param_2,wstring *param_3,ulong param_4,ulong param_5);
ulong __thiscall std::wstring::compare(wstring *this,wchar_t *param_1);
ulong __thiscall std::wstring::compare(wstring *this,ulong param_1,ulong param_2,wchar_t *param_3);
ulong __thiscall std::wstring::compare(wstring *this,ulong param_1,ulong param_2,wchar_t *param_3,ulong param_4);
void __thiscall std::wstring::_Alloc_hider::_Alloc_hider(_Alloc_hider *this,wchar_t *param_1,allocator *param_2);
undefined8 * std::wstring::_Rep::_S_empty_rep(void);
uint __thiscall std::wstring::_Rep::_M_is_leaked(_Rep *this);
undefined4 __thiscall std::wstring::_Rep::_M_is_shared(_Rep *this);
void __thiscall std::wstring::_Rep::_M_set_leaked(_Rep *this);
void __thiscall std::wstring::_Rep::_M_set_sharable(_Rep *this);
void __thiscall std::wstring::_Rep::_M_set_length_and_sharable(_Rep *this,ulong param_1);
_Rep * __thiscall std::wstring::_Rep::_M_refdata(_Rep *this);
void std::wstring::_Rep::_S_create(ulong param_1,ulong param_2,allocator *param_3);
wchar_t * std::wstring::_S_construct(ulong param_1,wchar_t param_2,allocator *param_3);
void __thiscall std::wstring::wstring(wstring *this,allocator *param_1);
void __thiscall std::wstring::wstring(wstring *this,ulong param_1,wchar_t param_2,allocator *param_3);
wchar_t * std::wstring::_S_construct_aux_2(ulong param_1,wchar_t param_2,allocator *param_3);
wchar_t * std::wstring::_S_construct<>(wchar_t *param_1,wchar_t *param_2,allocator *param_3,forward_iterator_tag param_4);
void std::wstring::_Rep::_M_destroy(allocator *param_1);
void std::wstring::_Rep::_M_dispose(allocator *param_1);
void std::wstring::_Rep::_M_dispose(allocator *param_1);
void __thiscall std::wstring::~wstring(wstring *this);
void __thiscall std::wstring::clear(wstring *this);
void __thiscall std::wstring::_M_mutate(wstring *this,ulong param_1,ulong param_2,ulong param_3);
void __thiscall std::wstring::_M_leak_hard(wstring *this);
void __thiscall std::wstring::_M_leak(wstring *this);
long __thiscall std::wstring::front(wstring *this);
long __thiscall std::wstring::begin(wstring *this);
void std::wstring::rend(void);
long __thiscall std::wstring::operator[](wstring *this,ulong param_1);
long __thiscall std::wstring::end(wstring *this);
void std::wstring::rbegin(void);
long __thiscall std::wstring::back(wstring *this);
long __thiscall std::wstring::at(wstring *this,ulong param_1);
wstring * __thiscall std::wstring::erase(wstring *this,ulong param_1,ulong param_2);
long __thiscall std::wstring::erase(wstring *this,__normal_iterator param_1);
long __thiscall std::wstring::erase(wstring *this,__normal_iterator param_1,__normal_iterator param_2);
wstring * __thiscall std::wstring::_M_replace_aux(wstring *this,ulong param_1,ulong param_2,ulong param_3,wchar_t param_4);
void __thiscall std::wstring::assign(wstring *this,ulong param_1,wchar_t param_2);
wstring * __thiscall std::wstring::operator=(wstring *this,wchar_t param_1);
void __thiscall std::wstring::insert(wstring *this,ulong param_1,ulong param_2,wchar_t param_3);
long __thiscall std::wstring::insert(wstring *this,__normal_iterator param_1,wchar_t param_2);
void __thiscall std::wstring::replace(wstring *this,ulong param_1,ulong param_2,ulong param_3,wchar_t param_4);
void __thiscall std::wstring::replace(wstring *this,__normal_iterator param_1,__normal_iterator param_2,ulong param_3,wchar_t param_4);
void __thiscall std::wstring::insert(wstring *this,__normal_iterator param_1,ulong param_2,wchar_t param_3);
wstring * __thiscall std::wstring::_M_replace_safe(wstring *this,ulong param_1,ulong param_2,wchar_t *param_3,ulong param_4);
wstring * __thiscall std::wstring::assign(wstring *this,wchar_t *param_1,ulong param_2);
wstring * __thiscall std::wstring::operator=(wstring *this,initializer_list param_1);
void std::wstring::assign(wstring *param_1,ulong param_2,ulong param_3);
void __thiscall std::wstring::assign(wstring *this,wchar_t *param_1);
void __thiscall std::wstring::operator=(wstring *this,wchar_t *param_1);
wstring * std::wstring::assign(initializer_list param_1);
wstring * __thiscall std::wstring::insert(wstring *this,ulong param_1,wchar_t *param_2,ulong param_3);
void std::wstring::insert(__normal_iterator param_1,initializer_list param_2);
void __thiscall std::wstring::insert(wstring *this,ulong param_1,wstring *param_2,ulong param_3,ulong param_4);
void __thiscall std::wstring::insert(wstring *this,ulong param_1,wchar_t *param_2);
void __thiscall std::wstring::insert(wstring *this,ulong param_1,wstring *param_2);
void __thiscall std::wstring::pop_back(wstring *this);
_Rep * __thiscall std::wstring::_Rep::_M_refcopy(_Rep *this);
wchar_t * __thiscall std::wstring::_Rep::_M_clone(_Rep *this,allocator *param_1,ulong param_2);
void __thiscall std::wstring::reserve(wstring *this,ulong param_1);
void __thiscall std::wstring::shrink_to_fit(wstring *this);
wstring * __thiscall std::wstring::append(wstring *this,wstring *param_1);
wstring * __thiscall std::wstring::operator+=(wstring *this,wstring *param_1);
wstring * __thiscall std::wstring::append(wstring *this,wstring *param_1,ulong param_2,ulong param_3);
wstring * __thiscall std::wstring::append(wstring *this,wchar_t *param_1,ulong param_2);
wstring * __thiscall std::wstring::operator+=(wstring *this,initializer_list param_1);
void __thiscall std::wstring::append(wstring *this,wchar_t *param_1);
void __thiscall std::wstring::operator+=(wstring *this,wchar_t *param_1);
wstring * std::wstring::append(initializer_list param_1);
wstring * __thiscall std::wstring::append(wstring *this,ulong param_1,wchar_t param_2);
void __thiscall std::wstring::resize(wstring *this,ulong param_1,wchar_t param_2);
void __thiscall std::wstring::resize(wstring *this,ulong param_1);
void __thiscall std::wstring::push_back(wstring *this,wchar_t param_1);
wstring * __thiscall std::wstring::operator+=(wstring *this,wchar_t param_1);
allocator * std::wstring::_Rep::_M_grab(allocator *param_1,allocator *param_2);
void __thiscall std::wstring::wstring(wstring *this,wstring *param_1);
void __thiscall std::wstring::wstring(wstring *this,wstring *param_1,allocator *param_2);
wstring * __thiscall std::wstring::assign(wstring *this,wstring *param_1);
wstring * __thiscall std::wstring::operator=(wstring *this,wstring *param_1);
wstring * std::operator+(wstring *param_1,wchar_t *param_2,wstring *param_3);
wstring * std::operator+(wstring *param_1,wchar_t param_2,wstring *param_3);
wstring * std::operator+(wstring *param_1,wstring *param_2,wstring *param_3);
wchar_t * std::wstring::_S_construct<>(__normal_iterator param_1,__normal_iterator param_2,allocator *param_3,forward_iterator_tag param_4);
void __thiscall std::wstring::wstring<>(wstring *this,__normal_iterator param_1,__normal_iterator param_2,allocator *param_3);
wchar_t * std::wstring::_S_construct<wchar_t*>(wchar_t *param_1,wchar_t *param_2,allocator *param_3,forward_iterator_tag param_4);
void __thiscall std::wstring::wstring(wstring *this,wstring *param_1,ulong param_2,allocator *param_3);
void __thiscall std::wstring::wstring(wstring *this,wstring *param_1,ulong param_2,ulong param_3);
ulong std::wstring::substr(ulong param_1,ulong param_2);
void __thiscall std::wstring::wstring(wstring *this,wstring *param_1,ulong param_2,ulong param_3,allocator *param_4);
void __thiscall std::wstring::wstring<wchar_t*>(wstring *this,wchar_t *param_1,wchar_t *param_2,allocator *param_3);
wchar_t * std::wstring::_S_construct<>(wchar_t *param_1,wchar_t *param_2,allocator *param_3,forward_iterator_tag param_4);
void __thiscall std::wstring::wstring(wstring *this,wchar_t *param_1,ulong param_2,allocator *param_3);
wstring * __thiscall std::wstring::replace(wstring *this,ulong param_1,ulong param_2,wchar_t *param_3,ulong param_4);
void __thiscall std::wstring::replace(wstring *this,ulong param_1,ulong param_2,wstring *param_3);
void __thiscall std::wstring::replace(wstring *this,ulong param_1,ulong param_2,wstring *param_3,ulong param_4,ulong param_5);
void __thiscall std::wstring::replace(wstring *this,ulong param_1,ulong param_2,wchar_t *param_3);
void __thiscall std::wstring::replace(wstring *this,__normal_iterator param_1,__normal_iterator param_2,wchar_t *param_3,ulong param_4);
void __thiscall std::wstring::replace(wstring *this,__normal_iterator param_1,__normal_iterator param_2,wstring *param_3);
void __thiscall std::wstring::replace(wstring *this,__normal_iterator param_1,__normal_iterator param_2,wchar_t *param_3);
void __thiscall std::wstring::replace(wstring *this,__normal_iterator param_1,__normal_iterator param_2,wchar_t *param_3,wchar_t *param_4);
void __thiscall std::wstring::replace(wstring *this,__normal_iterator param_1,__normal_iterator param_2,wchar_t *param_3,wchar_t *param_4);
void std::wstring::replace(__normal_iterator param_1,__normal_iterator param_2,initializer_list param_3);
void __thiscall std::wstring::replace(wstring *this,__normal_iterator param_1,__normal_iterator param_2,__normal_iterator param_3,__normal_iterator param_4);
void __thiscall std::wstring::replace(wstring *this,__normal_iterator param_1,__normal_iterator param_2,__normal_iterator param_3,__normal_iterator param_4);
void __thiscall std::wstring::wstring(wstring *this,wchar_t *param_1,allocator *param_2);
void __thiscall std::wstring::wstring(wstring *this,initializer_list param_1,allocator *param_2);
void __thiscall std::wstring::wstring<>(wstring *this,wchar_t *param_1,wchar_t *param_2,allocator *param_3);
bool operator==(__normal_iterator *param_1,__normal_iterator *param_2);
bool operator==(__normal_iterator *param_1,__normal_iterator *param_2);
undefined4 std::ctype<char>::do_narrow(char param_1,char param_2);
void __thiscall std::ctype<char>::~ctype(ctype<char> *this);
void __thiscall std::ctype<wchar_t>::~ctype(ctype<wchar_t> *this);
void __thiscall std::ctype_byname<wchar_t>::~ctype_byname(ctype_byname<wchar_t> *this);
void __thiscall std::ctype<char>::~ctype(ctype<char> *this);
void __thiscall std::ctype<wchar_t>::~ctype(ctype<wchar_t> *this);
void __thiscall std::ctype_byname<wchar_t>::~ctype_byname(ctype_byname<wchar_t> *this);
char * __thiscall std::ctype<char>::do_narrow(ctype<char> *this,char *param_1,char *param_2,char param_3,char *param_4);
char * __thiscall std::ctype<char>::do_widen(ctype<char> *this,char *param_1,char *param_2,char *param_3);
void __thiscall std::ctype<char>::_M_narrow_init(ctype<char> *this);
void __thiscall std::ctype<char>::_M_widen_init(ctype<char> *this);
void __thiscall std::ctype<wchar_t>::ctype(ctype<wchar_t> *this,ulong param_1);
void __thiscall std::ctype<wchar_t>::ctype(ctype<wchar_t> *this,__locale_struct *param_1,ulong param_2);
void __thiscall std::ctype_byname<wchar_t>::ctype_byname(ctype_byname<wchar_t> *this,char *param_1,ulong param_2);
undefined8 std::ctype<char>::classic_table(void);
void __thiscall std::ctype<char>::ctype(ctype<char> *this,__locale_struct *param_1,ushort *param_2,bool param_3,ulong param_4);
void __thiscall std::ctype<char>::ctype(ctype<char> *this,ushort *param_1,bool param_2,ulong param_3);
undefined4 __thiscall std::ctype<char>::do_toupper(ctype<char> *this,char param_1);
void __thiscall std::ctype<char>::do_toupper(ctype<char> *this,char *param_1,char *param_2);
undefined4 __thiscall std::ctype<char>::do_tolower(ctype<char> *this,char param_1);
void __thiscall std::ctype<char>::do_tolower(ctype<char> *this,char *param_1,char *param_2);
void __thiscall std::ctype_byname<char>::~ctype_byname(ctype_byname<char> *this);
void __thiscall std::ctype_byname<char>::~ctype_byname(ctype_byname<char> *this);
void __thiscall std::ctype_byname<char>::ctype_byname(ctype_byname<char> *this,char *param_1,ulong param_2);
undefined8 __thiscall std::ctype<wchar_t>::_M_convert_to_wmask(ctype<wchar_t> *this,ushort param_1);
void __thiscall std::ctype<wchar_t>::do_toupper(ctype<wchar_t> *this,wchar_t param_1);
wchar_t * __thiscall std::ctype<wchar_t>::do_toupper(ctype<wchar_t> *this,wchar_t *param_1,wchar_t *param_2);
void __thiscall std::ctype<wchar_t>::do_tolower(ctype<wchar_t> *this,wchar_t param_1);
wchar_t * __thiscall std::ctype<wchar_t>::do_tolower(ctype<wchar_t> *this,wchar_t *param_1,wchar_t *param_2);
bool __thiscall std::ctype<wchar_t>::do_is(ctype<wchar_t> *this,ushort param_1,wchar_t param_2);
wchar_t * __thiscall std::ctype<wchar_t>::do_is(ctype<wchar_t> *this,wchar_t *param_1,wchar_t *param_2,ushort *param_3);
wchar_t * __thiscall std::ctype<wchar_t>::do_scan_is(ctype<wchar_t> *this,ushort param_1,wchar_t *param_2,wchar_t *param_3);
wchar_t * __thiscall std::ctype<wchar_t>::do_scan_not(ctype<wchar_t> *this,ushort param_1,wchar_t *param_2,wchar_t *param_3);
undefined4 __thiscall std::ctype<wchar_t>::do_widen(ctype<wchar_t> *this,char param_1);
char * __thiscall std::ctype<wchar_t>::do_widen(ctype<wchar_t> *this,char *param_1,char *param_2,wchar_t *param_3);
uint __thiscall std::ctype<wchar_t>::do_narrow(ctype<wchar_t> *this,wchar_t param_1,char param_2);
wchar_t * __thiscall std::ctype<wchar_t>::do_narrow(ctype<wchar_t> *this,wchar_t *param_1,wchar_t *param_2,char param_3,char *param_4);
void __thiscall std::ctype<wchar_t>::_M_initialize_ctype(ctype<wchar_t> *this);
undefined __thiscall std::moneypunct<char,false>::do_decimal_point(moneypunct<char,false> *this);
undefined __thiscall std::moneypunct<char,false>::do_thousands_sep(moneypunct<char,false> *this);
undefined4 __thiscall std::moneypunct<char,false>::do_frac_digits(moneypunct<char,false> *this);
undefined4 __thiscall std::moneypunct<char,false>::do_pos_format(moneypunct<char,false> *this);
undefined4 __thiscall std::moneypunct<char,false>::do_neg_format(moneypunct<char,false> *this);
undefined __thiscall std::moneypunct<char,true>::do_decimal_point(moneypunct<char,true> *this);
undefined __thiscall std::moneypunct<char,true>::do_thousands_sep(moneypunct<char,true> *this);
undefined4 __thiscall std::moneypunct<char,true>::do_frac_digits(moneypunct<char,true> *this);
undefined4 __thiscall std::moneypunct<char,true>::do_pos_format(moneypunct<char,true> *this);
undefined4 __thiscall std::moneypunct<char,true>::do_neg_format(moneypunct<char,true> *this);
void __thiscall std::moneypunct_byname<char,false>::~moneypunct_byname(moneypunct_byname<char,false> *this);
void __thiscall std::moneypunct_byname<char,true>::~moneypunct_byname(moneypunct_byname<char,true> *this);
undefined __thiscall std::numpunct<char>::do_decimal_point(numpunct<char> *this);
undefined __thiscall std::numpunct<char>::do_thousands_sep(numpunct<char> *this);
void __thiscall std::numpunct_byname<char>::~numpunct_byname(numpunct_byname<char> *this);
undefined8 std::time_get<>::do_date_order(void);
ulong __thiscall std::collate<char>::do_hash(collate<char> *this,char *param_1,char *param_2);
void __thiscall std::money_get<>::~money_get(money_get<> *this);
void __thiscall std::money_put<>::~money_put(money_put<> *this);
void __thiscall std::time_get<>::~time_get(time_get<> *this);
void __thiscall std::time_get_byname<>::~time_get_byname(time_get_byname<> *this);
void __thiscall std::moneypunct_byname<char,false>::~moneypunct_byname(moneypunct_byname<char,false> *this);
void __thiscall std::moneypunct_byname<char,true>::~moneypunct_byname(moneypunct_byname<char,true> *this);
void __thiscall std::money_get<>::~money_get(money_get<> *this);
void __thiscall std::money_put<>::~money_put(money_put<> *this);
void __thiscall std::numpunct_byname<char>::~numpunct_byname(numpunct_byname<char> *this);
void __thiscall std::time_get<>::~time_get(time_get<> *this);
void __thiscall std::time_get_byname<>::~time_get_byname(time_get_byname<> *this);
void __thiscall std::collate<char>::~collate(collate<char> *this);
void __thiscall std::collate<char>::~collate(collate<char> *this);
void __thiscall std::collate_byname<char>::~collate_byname(collate_byname<char> *this);
void __thiscall std::collate_byname<char>::~collate_byname(collate_byname<char> *this);
void __thiscall std::messages<char>::~messages(messages<char> *this);
void __thiscall std::messages<char>::~messages(messages<char> *this);
void __thiscall std::messages_byname<char>::~messages_byname(messages_byname<char> *this);
void __thiscall std::messages_byname<char>::~messages_byname(messages_byname<char> *this);
int __thiscall std::collate<char>::do_compare(collate<char> *this,char *param_1,char *param_2,char *param_3,char *param_4);
void std::numpunct<char>::do_falsename(void);
void std::numpunct<char>::do_grouping(void);
void std::numpunct<char>::do_truename(void);
void std::moneypunct<char,true>::do_negative_sign(void);
void std::moneypunct<char,true>::do_curr_symbol(void);
void std::moneypunct<char,true>::do_positive_sign(void);
void std::moneypunct<char,true>::do_grouping(void);
void std::moneypunct<char,false>::do_grouping(void);
void std::moneypunct<char,false>::do_curr_symbol(void);
void std::moneypunct<char,false>::do_positive_sign(void);
void std::moneypunct<char,false>::do_negative_sign(void);
char * std::collate<char>::do_transform(char *param_1,char *param_2);
int std::__convert_from_v(__locale_struct **param_1,char *param_2,int param_3,char *param_4,undefined param_5,undefined param_6,undefined param_7,...);
void __thiscall std::moneypunct<char,false>::moneypunct(moneypunct<char,false> *this,ulong param_1);
void __thiscall std::moneypunct<char,false>::moneypunct(moneypunct<char,false> *this,__moneypunct_cache *param_1,ulong param_2);
void __thiscall std::moneypunct<char,false>::moneypunct(moneypunct<char,false> *this,__locale_struct *param_1,char *param_2,ulong param_3);
ulong __thiscall std::moneypunct<char,false>::decimal_point(moneypunct<char,false> *this);
ulong __thiscall std::moneypunct<char,false>::thousands_sep(moneypunct<char,false> *this);
void std::moneypunct<char,false>::grouping(void);
void std::moneypunct<char,false>::curr_symbol(void);
void std::moneypunct<char,false>::positive_sign(void);
void std::moneypunct<char,false>::negative_sign(void);
ulong __thiscall std::moneypunct<char,false>::frac_digits(moneypunct<char,false> *this);
ulong __thiscall std::moneypunct<char,false>::pos_format(moneypunct<char,false> *this);
ulong __thiscall std::moneypunct<char,false>::neg_format(moneypunct<char,false> *this);
void __thiscall std::moneypunct<char,true>::moneypunct(moneypunct<char,true> *this,ulong param_1);
void __thiscall std::moneypunct<char,true>::moneypunct(moneypunct<char,true> *this,__moneypunct_cache *param_1,ulong param_2);
void __thiscall std::moneypunct<char,true>::moneypunct(moneypunct<char,true> *this,__locale_struct *param_1,char *param_2,ulong param_3);
ulong __thiscall std::moneypunct<char,true>::decimal_point(moneypunct<char,true> *this);
ulong __thiscall std::moneypunct<char,true>::thousands_sep(moneypunct<char,true> *this);
void std::moneypunct<char,true>::grouping(void);
void std::moneypunct<char,true>::curr_symbol(void);
void std::moneypunct<char,true>::positive_sign(void);
void std::moneypunct<char,true>::negative_sign(void);
ulong __thiscall std::moneypunct<char,true>::frac_digits(moneypunct<char,true> *this);
ulong __thiscall std::moneypunct<char,true>::pos_format(moneypunct<char,true> *this);
ulong __thiscall std::moneypunct<char,true>::neg_format(moneypunct<char,true> *this);
void __thiscall std::moneypunct_byname<char,false>::moneypunct_byname(moneypunct_byname<char,false> *this,char *param_1,ulong param_2);
void __thiscall std::moneypunct_byname<char,false>::moneypunct_byname(moneypunct_byname<char,false> *this,string *param_1,ulong param_2);
void __thiscall std::moneypunct_byname<char,true>::moneypunct_byname(moneypunct_byname<char,true> *this,char *param_1,ulong param_2);
void __thiscall std::moneypunct_byname<char,true>::moneypunct_byname(moneypunct_byname<char,true> *this,string *param_1,ulong param_2);
void __thiscall std::money_get<>::money_get(money_get<> *this,ulong param_1);
void std::money_get<>::get(istreambuf_iterator param_1,istreambuf_iterator param_2,bool param_3,ios_base *param_4,_Ios_Iostate *param_5,longdouble *param_6);
void std::money_get<>::get(istreambuf_iterator param_1,istreambuf_iterator param_2,bool param_3,ios_base *param_4,_Ios_Iostate *param_5,string *param_6);
void __thiscall std::money_put<>::money_put(money_put<> *this,ulong param_1);
void std::money_put<>::put(ostreambuf_iterator param_1,bool param_2,ios_base *param_3,char param_4,longdouble param_5);
void std::money_put<>::put(ostreambuf_iterator param_1,bool param_2,ios_base *param_3,char param_4,string *param_5);
istreambuf_iterator std::money_get<>::_M_extract<true>(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,string *param_5,undefined param_6,uint *param_7,string *param_8);
istreambuf_iterator std::money_get<>::_M_extract<false>(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,string *param_5,undefined param_6,uint *param_7,string *param_8);
undefined  [16]std::money_get<>::do_get(istreambuf_iterator param_1,istreambuf_iterator param_2,bool param_3,ios_base *param_4,_Ios_Iostate *param_5,longdouble *param_6,undefined8 param_7,_Ios_Iostate *param_8,longdouble *param_9);
undefined  [16]std::money_get<>::do_get(istreambuf_iterator param_1,istreambuf_iterator param_2,bool param_3,ios_base *param_4,_Ios_Iostate *param_5,string *param_6,long param_7,undefined8 param_8,string *param_9);
ostreambuf_iterator std::money_put<>::_M_insert<true>(ostreambuf_iterator param_1,ios_base *param_2,char param_3,string *param_4);
ostreambuf_iterator std::money_put<>::_M_insert<false>(ostreambuf_iterator param_1,ios_base *param_2,char param_3,string *param_4);
undefined  [16]std::money_put<>::do_put(ostreambuf_iterator param_1,bool param_2,ios_base *param_3,char param_4,longdouble param_5);
void std::money_put<>::do_put(ostreambuf_iterator param_1,bool param_2,ios_base *param_3,char param_4,string *param_5,undefined param_6,undefined8 param_7);
void __thiscall std::numpunct<char>::numpunct(numpunct<char> *this,ulong param_1);
void __thiscall std::numpunct<char>::numpunct(numpunct<char> *this,__numpunct_cache *param_1,ulong param_2);
void __thiscall std::numpunct<char>::numpunct(numpunct<char> *this,__locale_struct *param_1,ulong param_2);
ulong __thiscall std::numpunct<char>::decimal_point(numpunct<char> *this);
ulong __thiscall std::numpunct<char>::thousands_sep(numpunct<char> *this);
void std::numpunct<char>::grouping(void);
void std::numpunct<char>::truename(void);
void std::numpunct<char>::falsename(void);
void __thiscall std::numpunct_byname<char>::numpunct_byname(numpunct_byname<char> *this,char *param_1,ulong param_2);
void __thiscall std::numpunct_byname<char>::numpunct_byname(numpunct_byname<char> *this,string *param_1,ulong param_2);
istreambuf_iterator std::num_get<>::_M_extract_int[abi:cxx11]<long>(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,long *param_5,undefined param_6,uint *param_7,ulong *param_8);
istreambuf_iterator std::num_get<>::_M_extract_int[abi:cxx11]<>(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,ushort *param_5,undefined param_6,uint *param_7,ushort *param_8);
istreambuf_iterator std::num_get<>::_M_extract_int[abi:cxx11]<>(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,uint *param_5,undefined param_6,uint *param_7,uint *param_8);
istreambuf_iterator std::num_get<>::_M_extract_int[abi:cxx11]<>(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,ulong *param_5,undefined param_6,uint *param_7,ulong *param_8);
istreambuf_iterator std::num_get<>::_M_extract_int[abi:cxx11]<long_long>(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,longlong *param_5,undefined param_6,uint *param_7,ulong *param_8);
istreambuf_iterator std::num_get<>::_M_extract_int[abi:cxx11]<>(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,ulonglong *param_5,undefined param_6,uint *param_7,ulong *param_8);
void __thiscall std::time_put_byname<>::time_put_byname(time_put_byname<> *this,string *param_1,ulong param_2);
void __thiscall std::time_get<>::time_get(time_get<> *this,ulong param_1);
void __thiscall std::time_get<>::date_order(time_get<> *this);
void std::time_get<>::get_time(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5);
void std::time_get<>::get_date(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5);
void std::time_get<>::get_weekday(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5);
void std::time_get<>::get_monthname(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5);
void std::time_get<>::get_year(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5);
undefined  [16]std::time_get<>::_M_extract_num(istreambuf_iterator param_1,istreambuf_iterator param_2,int *param_3,int param_4,int param_5,ulong param_6,ios_base *param_7,_Ios_Iostate *param_8);
undefined  [16]std::time_get<>::do_get_year(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,undefined param_6,uint *param_7,long param_8);
undefined  [16]std::time_get<>::_M_extract_name(istreambuf_iterator param_1,istreambuf_iterator param_2,int *param_3,char **param_4,ulong param_5,ios_base *param_6,_Ios_Iostate *param_7);
undefined  [16]std::time_get<>::_M_extract_wday_or_month(istreambuf_iterator param_1,istreambuf_iterator param_2,int *param_3,char **param_4,ulong param_5,ios_base *param_6,_Ios_Iostate *param_7);
undefined  [16]std::time_get<>::do_get_weekday(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,undefined param_6,uint *param_7,long param_8);
undefined  [16]std::time_get<>::do_get_monthname(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,undefined param_6,uint *param_7,long param_8);
undefined  [16]std::time_get<>::_M_extract_via_format(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,char *param_6,uint *param_7,int *param_8,char *param_9);
undefined  [16]std::time_get<>::do_get_time(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,undefined param_6,uint *param_7,undefined8 param_8);
undefined  [16]std::time_get<>::do_get_date(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,undefined param_6,uint *param_7,undefined8 param_8);
undefined  [16]std::time_get<>::do_get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,char param_6,char param_7);
undefined  [16]std::time_get<>::get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,char param_6,char param_7);
undefined  [16]std::time_get<>::get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,char *param_6,char *param_7);
void __thiscall std::time_get_byname<>::time_get_byname(time_get_byname<> *this,char *param_1,ulong param_2);
void __thiscall std::time_get_byname<>::time_get_byname(time_get_byname<> *this,string *param_1,ulong param_2);
void __thiscall std::messages<char>::messages(messages<char> *this,ulong param_1);
void __thiscall std::messages<char>::messages(messages<char> *this,__locale_struct *param_1,char *param_2,ulong param_3);
void std::messages<char>::open(string *param_1,locale *param_2);
void __thiscall std::messages<char>::open(messages<char> *this,string *param_1,locale *param_2,char *param_3);
undefined8 std::messages<char>::get(int param_1,int param_2,int param_3,string *param_4);
void std::messages<char>::close(int param_1);
undefined8 __thiscall std::messages<char>::_M_convert_to_char(messages<char> *this,string *param_1);
char * std::messages<char>::_M_convert_from_char(char *param_1);
void __thiscall std::messages_byname<char>::messages_byname(messages_byname<char> *this,char *param_1,ulong param_2);
void __thiscall std::messages_byname<char>::messages_byname(messages_byname<char> *this,string *param_1,ulong param_2);
void __thiscall std::ctype_byname<char>::ctype_byname(ctype_byname<char> *this,string *param_1,ulong param_2);
void __thiscall std::codecvt_byname<>::codecvt_byname(codecvt_byname<> *this,string *param_1,ulong param_2);
void __thiscall std::collate<char>::collate(collate<char> *this,ulong param_1);
void __thiscall std::collate<char>::collate(collate<char> *this,__locale_struct *param_1,ulong param_2);
void std::collate<char>::compare(char *param_1,char *param_2,char *param_3,char *param_4);
char * std::collate<char>::transform(char *param_1,char *param_2);
void std::collate<char>::hash(char *param_1,char *param_2);
void __thiscall std::collate_byname<char>::collate_byname(collate_byname<char> *this,char *param_1,ulong param_2);
void __thiscall std::collate_byname<char>::collate_byname(collate_byname<char> *this,string *param_1,ulong param_2);
collate * std::use_facet<>(locale *param_1);
numpunct * std::use_facet<>(locale *param_1);
moneypunct * std::use_facet<>(locale *param_1);
moneypunct * std::use_facet<>(locale *param_1);
money_put * std::use_facet<>(locale *param_1);
money_get * std::use_facet<>(locale *param_1);
time_get * std::use_facet<>(locale *param_1);
messages * std::use_facet<>(locale *param_1);
bool std::has_facet<>(locale *param_1);
bool std::has_facet<>(locale *param_1);
bool std::has_facet<>(locale *param_1);
bool std::has_facet<>(locale *param_1);
bool std::has_facet<>(locale *param_1);
bool std::has_facet<>(locale *param_1);
bool std::has_facet<>(locale *param_1);
void std::__facet_shims::(anonymous_namespace)::__destroy_string<char>(void *param_1);
void std::__facet_shims::(anonymous_namespace)::__destroy_string<wchar_t>(void *param_1);
void std::__facet_shims::(anonymous_namespace)::collate_shim<char>::do_compare(char *param_1,char *param_2,char *param_3,char *param_4);
void std::__facet_shims::(anonymous_namespace)::time_get_shim<char>::do_get_year(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,undefined param_6,_Ios_Iostate *param_7,tm *param_8);
void std::__facet_shims::(anonymous_namespace)::time_get_shim<char>::do_get_monthname(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,undefined param_6,_Ios_Iostate *param_7,tm *param_8);
void std::__facet_shims::(anonymous_namespace)::time_get_shim<char>::do_get_weekday(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,undefined param_6,_Ios_Iostate *param_7,tm *param_8);
void std::__facet_shims::(anonymous_namespace)::time_get_shim<char>::do_get_date(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,undefined param_6,_Ios_Iostate *param_7,tm *param_8);
void std::__facet_shims::(anonymous_namespace)::time_get_shim<char>::do_get_time(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,undefined param_6,_Ios_Iostate *param_7,tm *param_8);
void std::__facet_shims::(anonymous_namespace)::time_get_shim<char>::do_date_order(void);
void std::__facet_shims::(anonymous_namespace)::money_get_shim<char>::do_get(istreambuf_iterator param_1,istreambuf_iterator param_2,bool param_3,ios_base *param_4,_Ios_Iostate *param_5,longdouble *param_6,ios_base *param_7,int *param_8,longdouble *param_9);
void std::__facet_shims::(anonymous_namespace)::money_put_shim<char>::do_put(ostreambuf_iterator param_1,bool param_2,ios_base *param_3,char param_4,longdouble param_5);
void std::__facet_shims::(anonymous_namespace)::messages_shim<char>::do_close(int param_1);
void std::__facet_shims::(anonymous_namespace)::messages_shim<char>::do_open(string *param_1,locale *param_2);
void std::__facet_shims::(anonymous_namespace)::collate_shim<wchar_t>::do_compare(wchar_t *param_1,wchar_t *param_2,wchar_t *param_3,wchar_t *param_4);
void std::__facet_shims::(anonymous_namespace)::time_get_shim<wchar_t>::do_get_year(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,undefined param_6,_Ios_Iostate *param_7,tm *param_8);
void std::__facet_shims::(anonymous_namespace)::time_get_shim<wchar_t>::do_get_monthname(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,undefined param_6,_Ios_Iostate *param_7,tm *param_8);
void std::__facet_shims::(anonymous_namespace)::time_get_shim<wchar_t>::do_get_weekday(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,undefined param_6,_Ios_Iostate *param_7,tm *param_8);
void std::__facet_shims::(anonymous_namespace)::time_get_shim<wchar_t>::do_get_date(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,undefined param_6,_Ios_Iostate *param_7,tm *param_8);
void std::__facet_shims::(anonymous_namespace)::time_get_shim<wchar_t>::do_get_time(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,undefined param_6,_Ios_Iostate *param_7,tm *param_8);
void std::__facet_shims::(anonymous_namespace)::time_get_shim<wchar_t>::do_date_order(void);
void std::__facet_shims::(anonymous_namespace)::money_get_shim<wchar_t>::do_get(istreambuf_iterator param_1,istreambuf_iterator param_2,bool param_3,ios_base *param_4,_Ios_Iostate *param_5,longdouble *param_6,ios_base *param_7,int *param_8,longdouble *param_9);
void std::__facet_shims::(anonymous_namespace)::money_put_shim<wchar_t>::do_put(ostreambuf_iterator param_1,bool param_2,ios_base *param_3,wchar_t param_4,longdouble param_5);
void std::__facet_shims::(anonymous_namespace)::messages_shim<wchar_t>::do_close(int param_1);
void std::__facet_shims::(anonymous_namespace)::messages_shim<wchar_t>::do_open(string *param_1,locale *param_2);
char * std::__facet_shims::(anonymous_namespace)::collate_shim<char>::do_transform(char *param_1,char *param_2);
long * std::__facet_shims::(anonymous_namespace)::messages_shim<char>::do_get(int param_1,int param_2,int param_3,string *param_4);
undefined  [16]std::__facet_shims::(anonymous_namespace)::money_put_shim<char>::do_put(ostreambuf_iterator param_1,bool param_2,ios_base *param_3,char param_4,string *param_5,char param_6,undefined8 *param_7);
wchar_t * std::__facet_shims::(anonymous_namespace)::collate_shim<wchar_t>::do_transform(wchar_t *param_1,wchar_t *param_2);
wchar_t * std::__facet_shims::(anonymous_namespace)::messages_shim<wchar_t>::do_get(int param_1,int param_2,int param_3,wstring *param_4);
undefined  [16]std::__facet_shims::(anonymous_namespace)::money_put_shim<wchar_t>::do_put(ostreambuf_iterator param_1,bool param_2,ios_base *param_3,wchar_t param_4,wstring *param_5,undefined param_6,undefined8 *param_7);
undefined  [16]std::__facet_shims::(anonymous_namespace)::money_get_shim<char>::do_get(istreambuf_iterator param_1,istreambuf_iterator param_2,bool param_3,ios_base *param_4,_Ios_Iostate *param_5,string *param_6,ios_base *param_7,int *param_8,undefined8 *param_9);
undefined  [16]std::__facet_shims::(anonymous_namespace)::money_get_shim<wchar_t>::do_get(istreambuf_iterator param_1,istreambuf_iterator param_2,bool param_3,ios_base *param_4,_Ios_Iostate *param_5,wstring *param_6,ios_base *param_7,int *param_8,undefined8 *param_9);
void __thiscall std::__facet_shims::(anonymous_namespace)::moneypunct_shim<>::~moneypunct_shim(moneypunct_shim<> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::moneypunct_shim<char,true>::~moneypunct_shim(moneypunct_shim<char,true> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::moneypunct_shim<char,false>::~moneypunct_shim(moneypunct_shim<char,false> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::numpunct_shim<wchar_t>::~numpunct_shim(numpunct_shim<wchar_t> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::moneypunct_shim<>::~moneypunct_shim(moneypunct_shim<> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::numpunct_shim<char>::~numpunct_shim(numpunct_shim<char> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::collate_shim<char>::~collate_shim(collate_shim<char> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::collate_shim<wchar_t>::~collate_shim(collate_shim<wchar_t> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::messages_shim<char>::~messages_shim(messages_shim<char> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::messages_shim<wchar_t>::~messages_shim(messages_shim<wchar_t> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::time_get_shim<char>::~time_get_shim(time_get_shim<char> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::money_put_shim<char>::~money_put_shim(money_put_shim<char> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::money_get_shim<char>::~money_get_shim(money_get_shim<char> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::time_get_shim<wchar_t>::~time_get_shim(time_get_shim<wchar_t> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::money_put_shim<wchar_t>::~money_put_shim(money_put_shim<wchar_t> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::money_get_shim<wchar_t>::~money_get_shim(money_get_shim<wchar_t> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::messages_shim<char>::~messages_shim(messages_shim<char> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::messages_shim<wchar_t>::~messages_shim(messages_shim<wchar_t> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::numpunct_shim<wchar_t>::~numpunct_shim(numpunct_shim<wchar_t> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::numpunct_shim<char>::~numpunct_shim(numpunct_shim<char> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::money_get_shim<wchar_t>::~money_get_shim(money_get_shim<wchar_t> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::collate_shim<wchar_t>::~collate_shim(collate_shim<wchar_t> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::money_put_shim<wchar_t>::~money_put_shim(money_put_shim<wchar_t> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::money_put_shim<char>::~money_put_shim(money_put_shim<char> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::time_get_shim<char>::~time_get_shim(time_get_shim<char> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::time_get_shim<wchar_t>::~time_get_shim(time_get_shim<wchar_t> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::money_get_shim<char>::~money_get_shim(money_get_shim<char> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::collate_shim<char>::~collate_shim(collate_shim<char> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::moneypunct_shim<char,true>::~moneypunct_shim(moneypunct_shim<char,true> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::moneypunct_shim<>::~moneypunct_shim(moneypunct_shim<> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::moneypunct_shim<>::~moneypunct_shim(moneypunct_shim<> *this);
void __thiscall std::__facet_shims::(anonymous_namespace)::moneypunct_shim<char,false>::~moneypunct_shim(moneypunct_shim<char,false> *this);
void std::__facet_shims::__numpunct_fill_cache<char>(integral_constant param_1,facet *param_2,__numpunct_cache *param_3);
void std::__facet_shims::__numpunct_fill_cache<wchar_t>(integral_constant param_1,facet *param_2,__numpunct_cache *param_3);
int std::__facet_shims::__collate_compare<char>(integral_constant param_1,facet *param_2,char *param_3,char *param_4,char *param_5,char *param_6);
int std::__facet_shims::__collate_compare<wchar_t>(integral_constant param_1,facet *param_2,wchar_t *param_3,wchar_t *param_4,wchar_t *param_5,wchar_t *param_6);
void std::__facet_shims::__collate_transform<char>(integral_constant param_1,facet *param_2,__any_string *param_3,char *param_4,char *param_5);
void std::__facet_shims::__collate_transform<wchar_t>(integral_constant param_1,facet *param_2,__any_string *param_3,wchar_t *param_4,wchar_t *param_5);
void std::__facet_shims::__moneypunct_fill_cache<char,true>(integral_constant param_1,facet *param_2,__moneypunct_cache *param_3);
void std::__facet_shims::__moneypunct_fill_cache<char,false>(integral_constant param_1,facet *param_2,__moneypunct_cache *param_3);
void std::__facet_shims::__moneypunct_fill_cache<>(integral_constant param_1,facet *param_2,__moneypunct_cache *param_3);
void std::__facet_shims::__moneypunct_fill_cache<>(integral_constant param_1,facet *param_2,__moneypunct_cache *param_3);
int std::__facet_shims::__messages_open<char>(integral_constant param_1,facet *param_2,char *param_3,ulong param_4,locale *param_5);
int std::__facet_shims::__messages_open<wchar_t>(integral_constant param_1,facet *param_2,char *param_3,ulong param_4,locale *param_5);
void std::__facet_shims::__messages_get<char>(integral_constant param_1,facet *param_2,__any_string *param_3,int param_4,int param_5,int param_6,char *param_7,ulong param_8);
void std::__facet_shims::__messages_get<wchar_t>(integral_constant param_1,facet *param_2,__any_string *param_3,int param_4,int param_5,int param_6,wchar_t *param_7,ulong param_8);
void std::__facet_shims::__messages_close<char>(integral_constant param_1,facet *param_2,int param_3);
void std::__facet_shims::__messages_close<wchar_t>(integral_constant param_1,facet *param_2,int param_3);
dateorder std::__facet_shims::__time_get_dateorder<char>(integral_constant param_1,facet *param_2);
dateorder std::__facet_shims::__time_get_dateorder<wchar_t>(integral_constant param_1,facet *param_2);
istreambuf_iterator __thiscall std::__facet_shims::__time_get<char>(__facet_shims *this,integral_constant param_1,facet *param_2,istreambuf_iterator param_3,istreambuf_iterator param_4,ios_base *param_5,_Ios_Iostate *param_6,tm *param_7,char param_8);
istreambuf_iterator std::__facet_shims::__time_get<wchar_t>(integral_constant param_1,facet *param_2,istreambuf_iterator param_3,istreambuf_iterator param_4,ios_base *param_5,_Ios_Iostate *param_6,tm *param_7,char param_8);
istreambuf_iterator __thiscall std::__facet_shims::__money_get<char>(__facet_shims *this,integral_constant param_1,facet *param_2,istreambuf_iterator param_3,istreambuf_iterator param_4,bool param_5,ios_base *param_6,_Ios_Iostate *param_7,longdouble *param_8,__any_string *param_9);
istreambuf_iterator __thiscall std::__facet_shims::__money_get<wchar_t>(__facet_shims *this,integral_constant param_1,facet *param_2,istreambuf_iterator param_3,istreambuf_iterator param_4,bool param_5,ios_base *param_6,_Ios_Iostate *param_7,longdouble *param_8,__any_string *param_9);
ostreambuf_iterator __thiscall std::__facet_shims::__money_put<char>(__facet_shims *this,integral_constant param_1,facet *param_2,ostreambuf_iterator param_3,bool param_4,ios_base *param_5,char param_6,longdouble param_7,__any_string *param_8);
ostreambuf_iterator __thiscall std::__facet_shims::__money_put<wchar_t>(__facet_shims *this,integral_constant param_1,facet *param_2,ostreambuf_iterator param_3,bool param_4,ios_base *param_5,wchar_t param_6,longdouble param_7,__any_string *param_8);
__locale_struct * __thiscall std::locale::facet::_M_sso_shim(facet *this,id *param_1);
undefined4 __thiscall std::moneypunct<>::do_decimal_point(moneypunct<> *this);
undefined4 __thiscall std::moneypunct<>::do_thousands_sep(moneypunct<> *this);
undefined4 __thiscall std::moneypunct<>::do_frac_digits(moneypunct<> *this);
undefined4 __thiscall std::moneypunct<>::do_pos_format(moneypunct<> *this);
undefined4 __thiscall std::moneypunct<>::do_neg_format(moneypunct<> *this);
undefined4 __thiscall std::moneypunct<>::do_decimal_point(moneypunct<> *this);
undefined4 __thiscall std::moneypunct<>::do_thousands_sep(moneypunct<> *this);
undefined4 __thiscall std::moneypunct<>::do_frac_digits(moneypunct<> *this);
undefined4 __thiscall std::moneypunct<>::do_pos_format(moneypunct<> *this);
undefined4 __thiscall std::moneypunct<>::do_neg_format(moneypunct<> *this);
void __thiscall std::moneypunct_byname<>::~moneypunct_byname(moneypunct_byname<> *this);
void __thiscall std::moneypunct_byname<>::~moneypunct_byname(moneypunct_byname<> *this);
undefined4 __thiscall std::numpunct<wchar_t>::do_decimal_point(numpunct<wchar_t> *this);
undefined4 __thiscall std::numpunct<wchar_t>::do_thousands_sep(numpunct<wchar_t> *this);
void __thiscall std::numpunct_byname<wchar_t>::~numpunct_byname(numpunct_byname<wchar_t> *this);
undefined8 std::time_get<>::do_date_order(void);
ulong __thiscall std::collate<wchar_t>::do_hash(collate<wchar_t> *this,wchar_t *param_1,wchar_t *param_2);
void __thiscall std::money_get<>::~money_get(money_get<> *this);
void __thiscall std::money_put<>::~money_put(money_put<> *this);
void __thiscall std::time_get<>::~time_get(time_get<> *this);
void __thiscall std::time_get_byname<>::~time_get_byname(time_get_byname<> *this);
void __thiscall std::moneypunct_byname<>::~moneypunct_byname(moneypunct_byname<> *this);
void __thiscall std::moneypunct_byname<>::~moneypunct_byname(moneypunct_byname<> *this);
void __thiscall std::money_get<>::~money_get(money_get<> *this);
void __thiscall std::money_put<>::~money_put(money_put<> *this);
void __thiscall std::numpunct_byname<wchar_t>::~numpunct_byname(numpunct_byname<wchar_t> *this);
void __thiscall std::time_get<>::~time_get(time_get<> *this);
void __thiscall std::time_get_byname<>::~time_get_byname(time_get_byname<> *this);
void __thiscall std::collate<wchar_t>::~collate(collate<wchar_t> *this);
void __thiscall std::collate<wchar_t>::~collate(collate<wchar_t> *this);
void __thiscall std::collate_byname<wchar_t>::~collate_byname(collate_byname<wchar_t> *this);
void __thiscall std::collate_byname<wchar_t>::~collate_byname(collate_byname<wchar_t> *this);
void __thiscall std::messages<wchar_t>::~messages(messages<wchar_t> *this);
void __thiscall std::messages<wchar_t>::~messages(messages<wchar_t> *this);
void __thiscall std::messages_byname<wchar_t>::~messages_byname(messages_byname<wchar_t> *this);
void __thiscall std::messages_byname<wchar_t>::~messages_byname(messages_byname<wchar_t> *this);
int __thiscall std::collate<wchar_t>::do_compare(collate<wchar_t> *this,wchar_t *param_1,wchar_t *param_2,wchar_t *param_3,wchar_t *param_4);
void std::moneypunct<>::do_grouping(void);
void std::moneypunct<>::do_grouping(void);
void std::numpunct<wchar_t>::do_grouping(void);
void std::moneypunct<>::do_negative_sign(void);
void std::moneypunct<>::do_positive_sign(void);
void std::moneypunct<>::do_negative_sign(void);
void std::numpunct<wchar_t>::do_truename(void);
void std::numpunct<wchar_t>::do_falsename(void);
void std::moneypunct<>::do_curr_symbol(void);
void std::moneypunct<>::do_positive_sign(void);
void std::moneypunct<>::do_curr_symbol(void);
wchar_t * std::collate<wchar_t>::do_transform(wchar_t *param_1,wchar_t *param_2);
void __thiscall std::moneypunct<>::moneypunct(moneypunct<> *this,ulong param_1);
void __thiscall std::moneypunct<>::moneypunct(moneypunct<> *this,__moneypunct_cache *param_1,ulong param_2);
void __thiscall std::moneypunct<>::moneypunct(moneypunct<> *this,__locale_struct *param_1,char *param_2,ulong param_3);
ulong __thiscall std::moneypunct<>::decimal_point(moneypunct<> *this);
ulong __thiscall std::moneypunct<>::thousands_sep(moneypunct<> *this);
void std::moneypunct<>::grouping(void);
void std::moneypunct<>::curr_symbol(void);
void std::moneypunct<>::positive_sign(void);
void std::moneypunct<>::negative_sign(void);
ulong __thiscall std::moneypunct<>::frac_digits(moneypunct<> *this);
ulong __thiscall std::moneypunct<>::pos_format(moneypunct<> *this);
ulong __thiscall std::moneypunct<>::neg_format(moneypunct<> *this);
void __thiscall std::moneypunct<>::moneypunct(moneypunct<> *this,ulong param_1);
void __thiscall std::moneypunct<>::moneypunct(moneypunct<> *this,__moneypunct_cache *param_1,ulong param_2);
void __thiscall std::moneypunct<>::moneypunct(moneypunct<> *this,__locale_struct *param_1,char *param_2,ulong param_3);
ulong __thiscall std::moneypunct<>::decimal_point(moneypunct<> *this);
ulong __thiscall std::moneypunct<>::thousands_sep(moneypunct<> *this);
void std::moneypunct<>::grouping(void);
void std::moneypunct<>::curr_symbol(void);
void std::moneypunct<>::positive_sign(void);
void std::moneypunct<>::negative_sign(void);
ulong __thiscall std::moneypunct<>::frac_digits(moneypunct<> *this);
ulong __thiscall std::moneypunct<>::pos_format(moneypunct<> *this);
ulong __thiscall std::moneypunct<>::neg_format(moneypunct<> *this);
void __thiscall std::moneypunct_byname<>::moneypunct_byname(moneypunct_byname<> *this,char *param_1,ulong param_2);
void __thiscall std::moneypunct_byname<>::moneypunct_byname(moneypunct_byname<> *this,string *param_1,ulong param_2);
void __thiscall std::moneypunct_byname<>::moneypunct_byname(moneypunct_byname<> *this,char *param_1,ulong param_2);
void __thiscall std::moneypunct_byname<>::moneypunct_byname(moneypunct_byname<> *this,string *param_1,ulong param_2);
void __thiscall std::money_get<>::money_get(money_get<> *this,ulong param_1);
void std::money_get<>::get(istreambuf_iterator param_1,istreambuf_iterator param_2,bool param_3,ios_base *param_4,_Ios_Iostate *param_5,longdouble *param_6);
void std::money_get<>::get(istreambuf_iterator param_1,istreambuf_iterator param_2,bool param_3,ios_base *param_4,_Ios_Iostate *param_5,wstring *param_6);
void __thiscall std::money_put<>::money_put(money_put<> *this,ulong param_1);
void std::money_put<>::put(ostreambuf_iterator param_1,bool param_2,ios_base *param_3,wchar_t param_4,longdouble param_5);
void std::money_put<>::put(ostreambuf_iterator param_1,bool param_2,ios_base *param_3,wchar_t param_4,wstring *param_5);
istreambuf_iterator std::money_get<>::_M_extract<true>(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,string *param_5,undefined param_6,uint *param_7,string *param_8);
istreambuf_iterator std::money_get<>::_M_extract<false>(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,string *param_5,undefined param_6,uint *param_7,string *param_8);
undefined  [16]std::money_get<>::do_get(istreambuf_iterator param_1,istreambuf_iterator param_2,bool param_3,ios_base *param_4,_Ios_Iostate *param_5,longdouble *param_6,undefined8 param_7,_Ios_Iostate *param_8,longdouble *param_9);
undefined  [16]std::money_get<>::do_get(istreambuf_iterator param_1,istreambuf_iterator param_2,bool param_3,ios_base *param_4,_Ios_Iostate *param_5,wstring *param_6,long param_7,undefined8 param_8,wstring *param_9);
ostreambuf_iterator std::money_put<>::_M_insert<true>(ostreambuf_iterator param_1,ios_base *param_2,wchar_t param_3,wstring *param_4);
ostreambuf_iterator std::money_put<>::_M_insert<false>(ostreambuf_iterator param_1,ios_base *param_2,wchar_t param_3,wstring *param_4);
undefined  [16]std::money_put<>::do_put(ostreambuf_iterator param_1,bool param_2,ios_base *param_3,wchar_t param_4,longdouble param_5);
void std::money_put<>::do_put(ostreambuf_iterator param_1,bool param_2,ios_base *param_3,wchar_t param_4,wstring *param_5,undefined param_6,undefined8 param_7);
void __thiscall std::numpunct<wchar_t>::numpunct(numpunct<wchar_t> *this,ulong param_1);
void __thiscall std::numpunct<wchar_t>::numpunct(numpunct<wchar_t> *this,__numpunct_cache *param_1,ulong param_2);
void __thiscall std::numpunct<wchar_t>::numpunct(numpunct<wchar_t> *this,__locale_struct *param_1,ulong param_2);
ulong __thiscall std::numpunct<wchar_t>::decimal_point(numpunct<wchar_t> *this);
ulong __thiscall std::numpunct<wchar_t>::thousands_sep(numpunct<wchar_t> *this);
void std::numpunct<wchar_t>::grouping(void);
void std::numpunct<wchar_t>::truename(void);
void std::numpunct<wchar_t>::falsename(void);
void __thiscall std::numpunct_byname<wchar_t>::numpunct_byname(numpunct_byname<wchar_t> *this,char *param_1,ulong param_2);
void __thiscall std::numpunct_byname<wchar_t>::numpunct_byname(numpunct_byname<wchar_t> *this,string *param_1,ulong param_2);
istreambuf_iterator std::num_get<>::_M_extract_int[abi:cxx11]<long>(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,long *param_5,undefined param_6,uint *param_7,ulong *param_8);
istreambuf_iterator std::num_get<>::_M_extract_int[abi:cxx11]<>(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,ushort *param_5,undefined param_6,uint *param_7,ushort *param_8);
istreambuf_iterator std::num_get<>::_M_extract_int[abi:cxx11]<>(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,uint *param_5,undefined param_6,uint *param_7,uint *param_8);
istreambuf_iterator std::num_get<>::_M_extract_int[abi:cxx11]<>(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,ulong *param_5,undefined param_6,uint *param_7,ulong *param_8);
istreambuf_iterator std::num_get<>::_M_extract_int[abi:cxx11]<long_long>(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,longlong *param_5,undefined param_6,uint *param_7,ulong *param_8);
istreambuf_iterator std::num_get<>::_M_extract_int[abi:cxx11]<>(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,ulonglong *param_5,undefined param_6,uint *param_7,ulong *param_8);
void __thiscall std::time_put_byname<>::time_put_byname(time_put_byname<> *this,string *param_1,ulong param_2);
void __thiscall std::time_get<>::time_get(time_get<> *this,ulong param_1);
void __thiscall std::time_get<>::date_order(time_get<> *this);
void std::time_get<>::get_time(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5);
void std::time_get<>::get_date(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5);
void std::time_get<>::get_weekday(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5);
void std::time_get<>::get_monthname(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5);
void std::time_get<>::get_year(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5);
undefined  [16]std::time_get<>::_M_extract_num(istreambuf_iterator param_1,istreambuf_iterator param_2,int *param_3,int param_4,int param_5,ulong param_6,ios_base *param_7,_Ios_Iostate *param_8);
undefined  [16]std::time_get<>::do_get_year(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,undefined param_6,uint *param_7,long param_8);
undefined  [16]std::time_get<>::_M_extract_name(istreambuf_iterator param_1,istreambuf_iterator param_2,int *param_3,wchar_t **param_4,ulong param_5,ios_base *param_6,_Ios_Iostate *param_7);
undefined  [16]std::time_get<>::_M_extract_wday_or_month(istreambuf_iterator param_1,istreambuf_iterator param_2,int *param_3,wchar_t **param_4,ulong param_5,ios_base *param_6,_Ios_Iostate *param_7);
undefined  [16]std::time_get<>::do_get_weekday(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,undefined param_6,uint *param_7,long param_8);
undefined  [16]std::time_get<>::do_get_monthname(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,undefined param_6,uint *param_7,long param_8);
undefined  [16]std::time_get<>::_M_extract_via_format(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,wchar_t *param_6,uint *param_7,int *param_8,wchar_t *param_9);
undefined  [16]std::time_get<>::do_get_time(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,undefined param_6,uint *param_7,undefined8 param_8);
undefined  [16]std::time_get<>::do_get_date(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,undefined param_6,uint *param_7,undefined8 param_8);
undefined  [16]std::time_get<>::do_get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,char param_6,char param_7);
undefined  [16]std::time_get<>::get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,char param_6,char param_7);
undefined  [16]std::time_get<>::get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,wchar_t *param_6,wchar_t *param_7);
void __thiscall std::time_get_byname<>::time_get_byname(time_get_byname<> *this,char *param_1,ulong param_2);
void __thiscall std::time_get_byname<>::time_get_byname(time_get_byname<> *this,string *param_1,ulong param_2);
void __thiscall std::messages<wchar_t>::messages(messages<wchar_t> *this,ulong param_1);
void __thiscall std::messages<wchar_t>::messages(messages<wchar_t> *this,__locale_struct *param_1,char *param_2,ulong param_3);
void std::messages<wchar_t>::open(string *param_1,locale *param_2);
void __thiscall std::messages<wchar_t>::open(messages<wchar_t> *this,string *param_1,locale *param_2,char *param_3);
undefined8 std::messages<wchar_t>::get(int param_1,int param_2,int param_3,wstring *param_4);
void std::messages<wchar_t>::close(int param_1);
undefined8 __thiscall std::messages<wchar_t>::_M_convert_to_char(messages<wchar_t> *this,wstring *param_1);
char * std::messages<wchar_t>::_M_convert_from_char(char *param_1);
void __thiscall std::messages_byname<wchar_t>::messages_byname(messages_byname<wchar_t> *this,char *param_1,ulong param_2);
void __thiscall std::messages_byname<wchar_t>::messages_byname(messages_byname<wchar_t> *this,string *param_1,ulong param_2);
void __thiscall std::ctype_byname<wchar_t>::ctype_byname(ctype_byname<wchar_t> *this,string *param_1,ulong param_2);
void __thiscall std::codecvt_byname<>::codecvt_byname(codecvt_byname<> *this,string *param_1,ulong param_2);
void __thiscall std::collate<wchar_t>::collate(collate<wchar_t> *this,ulong param_1);
void __thiscall std::collate<wchar_t>::collate(collate<wchar_t> *this,__locale_struct *param_1,ulong param_2);
void std::collate<wchar_t>::compare(wchar_t *param_1,wchar_t *param_2,wchar_t *param_3,wchar_t *param_4);
wchar_t * std::collate<wchar_t>::transform(wchar_t *param_1,wchar_t *param_2);
void std::collate<wchar_t>::hash(wchar_t *param_1,wchar_t *param_2);
void __thiscall std::collate_byname<wchar_t>::collate_byname(collate_byname<wchar_t> *this,char *param_1,ulong param_2);
void __thiscall std::collate_byname<wchar_t>::collate_byname(collate_byname<wchar_t> *this,string *param_1,ulong param_2);
collate * std::use_facet<>(locale *param_1);
numpunct * std::use_facet<>(locale *param_1);
moneypunct * std::use_facet<>(locale *param_1);
moneypunct * std::use_facet<>(locale *param_1);
money_put * std::use_facet<>(locale *param_1);
money_get * std::use_facet<>(locale *param_1);
time_get * std::use_facet<>(locale *param_1);
messages * std::use_facet<>(locale *param_1);
bool std::has_facet<>(locale *param_1);
bool std::has_facet<>(locale *param_1);
bool std::has_facet<>(locale *param_1);
bool std::has_facet<>(locale *param_1);
bool std::has_facet<>(locale *param_1);
bool std::has_facet<>(locale *param_1);
bool std::has_facet<>(locale *param_1);
void __thiscall stdio_sync_filebuf<>::~stdio_sync_filebuf(stdio_sync_filebuf<> *this);
void __thiscall stdio_sync_filebuf<>::~stdio_sync_filebuf(stdio_sync_filebuf<> *this);
void __thiscall stdio_sync_filebuf<>::~stdio_sync_filebuf(stdio_sync_filebuf<> *this);
void __thiscall stdio_sync_filebuf<>::~stdio_sync_filebuf(stdio_sync_filebuf<> *this);
void __thiscall stdio_sync_filebuf<>::uflow(stdio_sync_filebuf<> *this);
void __thiscall stdio_sync_filebuf<>::underflow(stdio_sync_filebuf<> *this);
void __thiscall stdio_sync_filebuf<>::pbackfail(stdio_sync_filebuf<> *this,int param_1);
void __thiscall stdio_sync_filebuf<>::sync(stdio_sync_filebuf<> *this);
void __thiscall stdio_sync_filebuf<>::sync(stdio_sync_filebuf<> *this);
int __thiscall stdio_sync_filebuf<>::overflow(stdio_sync_filebuf<> *this,int param_1);
undefined  [16]stdio_sync_filebuf<>::seekoff(long param_1,_Ios_Seekdir param_2,_Ios_Openmode param_3);
undefined  [16]stdio_sync_filebuf<>::seekoff(long param_1,_Ios_Seekdir param_2,_Ios_Openmode param_3);
void __thiscall stdio_sync_filebuf<>::uflow(stdio_sync_filebuf<> *this);
long __thiscall stdio_sync_filebuf<>::xsgetn(stdio_sync_filebuf<> *this,wchar_t *param_1,long param_2);
void __thiscall stdio_sync_filebuf<>::underflow(stdio_sync_filebuf<> *this);
void __thiscall stdio_sync_filebuf<>::pbackfail(stdio_sync_filebuf<> *this,uint param_1);
wint_t __thiscall stdio_sync_filebuf<>::overflow(stdio_sync_filebuf<> *this,uint param_1);
long __thiscall stdio_sync_filebuf<>::xsputn(stdio_sync_filebuf<> *this,wchar_t *param_1,long param_2);
void __thiscall stdio_sync_filebuf<>::xsputn(stdio_sync_filebuf<> *this,char *param_1,long param_2);
void __thiscall stdio_sync_filebuf<>::xsgetn(stdio_sync_filebuf<> *this,char *param_1,long param_2);
undefined  [16] stdio_sync_filebuf<>::seekpos(fpos param_1,_Ios_Openmode param_2);
undefined  [16] stdio_sync_filebuf<>::seekpos(fpos param_1,_Ios_Openmode param_2);
void __thiscall stdio_filebuf<>::~stdio_filebuf(stdio_filebuf<> *this);
void __thiscall stdio_filebuf<>::~stdio_filebuf(stdio_filebuf<> *this);
void __thiscall stdio_filebuf<>::~stdio_filebuf(stdio_filebuf<> *this);
void __thiscall stdio_filebuf<>::~stdio_filebuf(stdio_filebuf<> *this);
void __thiscall stdio_filebuf<>::stdio_filebuf(stdio_filebuf<> *this);
void __thiscall stdio_filebuf<>::stdio_filebuf(stdio_filebuf<> *this,int param_1,_Ios_Openmode param_2,ulong param_3);
void __thiscall stdio_filebuf<>::stdio_filebuf(stdio_filebuf<> *this,_IO_FILE *param_1,_Ios_Openmode param_2,ulong param_3);
void __thiscall stdio_filebuf<>::swap(stdio_filebuf<> *this,stdio_filebuf *param_1);
void __thiscall stdio_filebuf<>::fd(stdio_filebuf<> *this);
void __thiscall stdio_filebuf<>::file(stdio_filebuf<> *this);
void __thiscall stdio_sync_filebuf<>::stdio_sync_filebuf(stdio_sync_filebuf<> *this,_IO_FILE *param_1);
void __thiscall stdio_sync_filebuf<>::stdio_sync_filebuf(stdio_sync_filebuf<> *this,stdio_sync_filebuf *param_1);
stdio_sync_filebuf<> * __thiscall stdio_sync_filebuf<>::operator=(stdio_sync_filebuf<> *this,stdio_sync_filebuf *param_1);
void __thiscall stdio_sync_filebuf<>::swap(stdio_sync_filebuf<> *this,stdio_sync_filebuf *param_1);
undefined8 __thiscall stdio_sync_filebuf<>::file(stdio_sync_filebuf<> *this);
void __thiscall stdio_filebuf<>::stdio_filebuf(stdio_filebuf<> *this);
void __thiscall stdio_filebuf<>::stdio_filebuf(stdio_filebuf<> *this,int param_1,_Ios_Openmode param_2,ulong param_3);
void __thiscall stdio_filebuf<>::stdio_filebuf(stdio_filebuf<> *this,_IO_FILE *param_1,_Ios_Openmode param_2,ulong param_3);
void __thiscall stdio_filebuf<>::swap(stdio_filebuf<> *this,stdio_filebuf *param_1);
void __thiscall stdio_filebuf<>::fd(stdio_filebuf<> *this);
void __thiscall stdio_filebuf<>::file(stdio_filebuf<> *this);
void __thiscall stdio_sync_filebuf<>::stdio_sync_filebuf(stdio_sync_filebuf<> *this,_IO_FILE *param_1);
void __thiscall stdio_sync_filebuf<>::stdio_sync_filebuf(stdio_sync_filebuf<> *this,stdio_sync_filebuf *param_1);
stdio_sync_filebuf<> * __thiscall stdio_sync_filebuf<>::operator=(stdio_sync_filebuf<> *this,stdio_sync_filebuf *param_1);
void __thiscall stdio_sync_filebuf<>::swap(stdio_sync_filebuf<> *this,stdio_sync_filebuf *param_1);
undefined8 __thiscall stdio_sync_filebuf<>::file(stdio_sync_filebuf<> *this);
filebuf * __thiscall std::filebuf::setbuf(filebuf *this,char *param_1,long param_2);
wfilebuf * __thiscall std::wfilebuf::setbuf(wfilebuf *this,wchar_t *param_1,long param_2);
long __thiscall std::filebuf::showmanyc(filebuf *this);
long __thiscall std::wfilebuf::showmanyc(wfilebuf *this);
int __thiscall std::filebuf::sync(filebuf *this);
int __thiscall std::wfilebuf::sync(wfilebuf *this);
uint __thiscall std::filebuf::pbackfail(filebuf *this,int param_1);
uint __thiscall std::wfilebuf::pbackfail(wfilebuf *this,uint param_1);
ulong __thiscall std::filebuf::underflow(filebuf *this);
ulong __thiscall std::wfilebuf::underflow(wfilebuf *this);
long __thiscall std::filebuf::xsgetn(filebuf *this,char *param_1,long param_2);
long __thiscall std::wfilebuf::xsgetn(wfilebuf *this,wchar_t *param_1,long param_2);
long __thiscall std::filebuf::xsputn(filebuf *this,char *param_1,long param_2);
long __thiscall std::wfilebuf::xsputn(wfilebuf *this,wchar_t *param_1,long param_2);
void __thiscall std::filebuf::_M_create_pback(filebuf *this);
void __thiscall std::filebuf::_M_destroy_pback(filebuf *this);
void __thiscall std::filebuf::filebuf(filebuf *this);
void __thiscall std::filebuf::filebuf(filebuf *this,filebuf *param_1);
void __thiscall std::filebuf::swap(filebuf *this,filebuf *param_1);
void __thiscall std::filebuf::is_open(filebuf *this);
void __thiscall std::filebuf::_M_allocate_internal_buffer(filebuf *this);
void __thiscall std::filebuf::_M_destroy_internal_buffer(filebuf *this);
bool __thiscall std::filebuf::_M_convert_to_external(filebuf *this,char *param_1,long param_2);
int __thiscall std::filebuf::_M_get_ext_pos(filebuf *this,__mbstate_t *param_1);
bool __thiscall std::filebuf::_M_terminate_output(filebuf *this);
undefined  [16] __thiscall std::filebuf::_M_seek(filebuf *this,long param_1,_Ios_Seekdir param_2,__mbstate_t param_3);
int __thiscall std::filebuf::overflow(filebuf *this,int param_1);
undefined  [16] std::filebuf::seekoff(long param_1,_Ios_Seekdir param_2,_Ios_Openmode param_3);
undefined  [16] __thiscall std::filebuf::seekpos(filebuf *this,fpos param_1,_Ios_Openmode param_2);
void __thiscall std::filebuf::imbue(filebuf *this,locale *param_1);
void __thiscall std::filebuf::_M_set_buffer(filebuf *this,long param_1);
void __thiscall std::ifstream::ifstream(ifstream *this,ifstream *param_1);
void __thiscall std::ifstream::ifstream(ifstream *this,ifstream *param_1);
void __thiscall std::ifstream::swap(ifstream *this,ifstream *param_1);
ifstream * __thiscall std::ifstream::rdbuf(ifstream *this);
void __thiscall std::ifstream::is_open(ifstream *this);
void __thiscall std::ifstream::is_open(ifstream *this);
void __thiscall std::ofstream::ofstream(ofstream *this,ofstream *param_1);
void __thiscall std::ofstream::ofstream(ofstream *this,ofstream *param_1);
void __thiscall std::ofstream::swap(ofstream *this,ofstream *param_1);
ofstream * __thiscall std::ofstream::rdbuf(ofstream *this);
void __thiscall std::ofstream::is_open(ofstream *this);
void __thiscall std::ofstream::is_open(ofstream *this);
void __thiscall std::fstream::fstream(fstream *this,fstream *param_1);
void __thiscall std::fstream::fstream(fstream *this,fstream *param_1);
void __thiscall std::fstream::swap(fstream *this,fstream *param_1);
fstream * __thiscall std::fstream::rdbuf(fstream *this);
void __thiscall std::fstream::is_open(fstream *this);
void __thiscall std::fstream::is_open(fstream *this);
void __thiscall std::wfilebuf::_M_create_pback(wfilebuf *this);
void __thiscall std::wfilebuf::_M_destroy_pback(wfilebuf *this);
void __thiscall std::wfilebuf::wfilebuf(wfilebuf *this);
void __thiscall std::wfilebuf::wfilebuf(wfilebuf *this,wfilebuf *param_1);
void __thiscall std::wfilebuf::swap(wfilebuf *this,wfilebuf *param_1);
void __thiscall std::wfilebuf::is_open(wfilebuf *this);
void __thiscall std::wfilebuf::_M_allocate_internal_buffer(wfilebuf *this);
void __thiscall std::wfilebuf::_M_destroy_internal_buffer(wfilebuf *this);
bool __thiscall std::wfilebuf::_M_convert_to_external(wfilebuf *this,wchar_t *param_1,long param_2);
ulong __thiscall std::wfilebuf::_M_get_ext_pos(wfilebuf *this,__mbstate_t *param_1);
bool __thiscall std::wfilebuf::_M_terminate_output(wfilebuf *this);
undefined  [16] __thiscall std::wfilebuf::_M_seek(wfilebuf *this,long param_1,_Ios_Seekdir param_2,__mbstate_t param_3);
uint __thiscall std::wfilebuf::overflow(wfilebuf *this,uint param_1);
undefined  [16] std::wfilebuf::seekoff(long param_1,_Ios_Seekdir param_2,_Ios_Openmode param_3);
undefined  [16] __thiscall std::wfilebuf::seekpos(wfilebuf *this,fpos param_1,_Ios_Openmode param_2);
void __thiscall std::wfilebuf::imbue(wfilebuf *this,locale *param_1);
void __thiscall std::wfilebuf::_M_set_buffer(wfilebuf *this,long param_1);
void __thiscall std::wifstream::wifstream(wifstream *this,wifstream *param_1);
void __thiscall std::wifstream::wifstream(wifstream *this,wifstream *param_1);
void __thiscall std::wifstream::swap(wifstream *this,wifstream *param_1);
wifstream * __thiscall std::wifstream::rdbuf(wifstream *this);
void __thiscall std::wifstream::is_open(wifstream *this);
void __thiscall std::wifstream::is_open(wifstream *this);
void __thiscall std::wofstream::wofstream(wofstream *this,wofstream *param_1);
void __thiscall std::wofstream::wofstream(wofstream *this,wofstream *param_1);
void __thiscall std::wofstream::swap(wofstream *this,wofstream *param_1);
wofstream * __thiscall std::wofstream::rdbuf(wofstream *this);
void __thiscall std::wofstream::is_open(wofstream *this);
void __thiscall std::wofstream::is_open(wofstream *this);
void __thiscall std::wfstream::wfstream(wfstream *this,wfstream *param_1);
void __thiscall std::wfstream::wfstream(wfstream *this,wfstream *param_1);
void __thiscall std::wfstream::swap(wfstream *this,wfstream *param_1);
wfstream * __thiscall std::wfstream::rdbuf(wfstream *this);
void __thiscall std::wfstream::is_open(wfstream *this);
void __thiscall std::wfstream::is_open(wfstream *this);
void __thiscall std::filebuf::close()::__close_sentry::~__close_sentry(__close_sentry *this);
filebuf * __thiscall std::filebuf::close(filebuf *this);
void __thiscall std::filebuf::~filebuf(filebuf *this);
void __thiscall std::ifstream::ifstream(ifstream *this);
void __thiscall std::ofstream::ofstream(ofstream *this);
void __thiscall std::fstream::fstream(fstream *this);
void __thiscall std::ifstream::ifstream(ifstream *this);
void __thiscall std::ofstream::ofstream(ofstream *this);
void __thiscall std::fstream::fstream(fstream *this);
filebuf * __thiscall std::filebuf::operator=(filebuf *this,filebuf *param_1);
ifstream * __thiscall std::ifstream::operator=(ifstream *this,ifstream *param_1);
fstream * __thiscall std::fstream::operator=(fstream *this,fstream *param_1);
ofstream * __thiscall std::ofstream::operator=(ofstream *this,ofstream *param_1);
filebuf * __thiscall std::filebuf::open(filebuf *this,char *param_1,_Ios_Openmode param_2);
void __thiscall std::filebuf::open(filebuf *this,string *param_1,_Ios_Openmode param_2);
void __thiscall std::ifstream::open(ifstream *this,string *param_1,_Ios_Openmode param_2);
void __thiscall std::ofstream::open(ofstream *this,string *param_1,_Ios_Openmode param_2);
void __thiscall std::fstream::open(fstream *this,string *param_1,_Ios_Openmode param_2);
void __thiscall std::ifstream::open(ifstream *this,char *param_1,_Ios_Openmode param_2);
void __thiscall std::ofstream::open(ofstream *this,char *param_1,_Ios_Openmode param_2);
void __thiscall std::fstream::open(fstream *this,char *param_1,_Ios_Openmode param_2);
void __thiscall std::fstream::fstream(fstream *this,char *param_1,_Ios_Openmode param_2);
void __thiscall std::fstream::fstream(fstream *this,string *param_1,_Ios_Openmode param_2);
void __thiscall std::fstream::fstream(fstream *this,char *param_1,_Ios_Openmode param_2);
void __thiscall std::fstream::fstream(fstream *this,string *param_1,_Ios_Openmode param_2);
void __thiscall std::ofstream::ofstream(ofstream *this,char *param_1,_Ios_Openmode param_2);
void __thiscall std::ofstream::ofstream(ofstream *this,char *param_1,_Ios_Openmode param_2);
void __thiscall std::ifstream::ifstream(ifstream *this,char *param_1,_Ios_Openmode param_2);
void __thiscall std::ofstream::ofstream(ofstream *this,string *param_1,_Ios_Openmode param_2);
void __thiscall std::ofstream::ofstream(ofstream *this,string *param_1,_Ios_Openmode param_2);
void __thiscall std::ifstream::ifstream(ifstream *this,string *param_1,_Ios_Openmode param_2);
void __thiscall std::ifstream::ifstream(ifstream *this,char *param_1,_Ios_Openmode param_2);
void __thiscall std::ifstream::ifstream(ifstream *this,string *param_1,_Ios_Openmode param_2);
void __thiscall std::ifstream::close(ifstream *this);
void __thiscall std::ofstream::close(ofstream *this);
void __thiscall std::fstream::close(fstream *this);
void __thiscall std::ifstream::~ifstream(ifstream *this);
void __thiscall std::ifstream::~ifstream(ifstream *this);
void __thiscall std::fstream::~fstream(fstream *this);
void __thiscall std::fstream::~fstream(fstream *this);
void __thiscall std::fstream::~fstream(fstream *this);
void __thiscall std::ifstream::~ifstream(ifstream *this);
void __thiscall std::ifstream::~ifstream(ifstream *this);
void __thiscall std::fstream::~fstream(fstream *this);
void __thiscall std::fstream::~fstream(fstream *this);
void __thiscall std::fstream::~fstream(fstream *this);
void __thiscall std::ofstream::~ofstream(ofstream *this);
void __thiscall std::ofstream::~ofstream(ofstream *this);
void __thiscall std::ofstream::~ofstream(ofstream *this);
void __thiscall std::ofstream::~ofstream(ofstream *this);
void __thiscall std::filebuf::~filebuf(filebuf *this);
void __thiscall std::ofstream::~ofstream(ofstream *this);
void __thiscall std::ifstream::~ifstream(ifstream *this);
void __thiscall std::fstream::~fstream(fstream *this);
void __thiscall std::wfilebuf::close()::__close_sentry::~__close_sentry(__close_sentry *this);
wfilebuf * __thiscall std::wfilebuf::close(wfilebuf *this);
void __thiscall std::wfilebuf::~wfilebuf(wfilebuf *this);
void __thiscall std::wifstream::wifstream(wifstream *this);
void __thiscall std::wofstream::wofstream(wofstream *this);
void __thiscall std::wfstream::wfstream(wfstream *this);
void __thiscall std::wifstream::wifstream(wifstream *this);
void __thiscall std::wofstream::wofstream(wofstream *this);
void __thiscall std::wfstream::wfstream(wfstream *this);
wfilebuf * __thiscall std::wfilebuf::operator=(wfilebuf *this,wfilebuf *param_1);
wifstream * __thiscall std::wifstream::operator=(wifstream *this,wifstream *param_1);
wfstream * __thiscall std::wfstream::operator=(wfstream *this,wfstream *param_1);
wofstream * __thiscall std::wofstream::operator=(wofstream *this,wofstream *param_1);
wfilebuf * __thiscall std::wfilebuf::open(wfilebuf *this,char *param_1,_Ios_Openmode param_2);
void __thiscall std::wfilebuf::open(wfilebuf *this,string *param_1,_Ios_Openmode param_2);
void __thiscall std::wifstream::open(wifstream *this,string *param_1,_Ios_Openmode param_2);
void __thiscall std::wofstream::open(wofstream *this,string *param_1,_Ios_Openmode param_2);
void __thiscall std::wfstream::open(wfstream *this,string *param_1,_Ios_Openmode param_2);
void __thiscall std::wifstream::open(wifstream *this,char *param_1,_Ios_Openmode param_2);
void __thiscall std::wofstream::open(wofstream *this,char *param_1,_Ios_Openmode param_2);
void __thiscall std::wfstream::open(wfstream *this,char *param_1,_Ios_Openmode param_2);
void __thiscall std::wfstream::wfstream(wfstream *this,char *param_1,_Ios_Openmode param_2);
void __thiscall std::wfstream::wfstream(wfstream *this,string *param_1,_Ios_Openmode param_2);
void __thiscall std::wfstream::wfstream(wfstream *this,char *param_1,_Ios_Openmode param_2);
void __thiscall std::wfstream::wfstream(wfstream *this,string *param_1,_Ios_Openmode param_2);
void __thiscall std::wofstream::wofstream(wofstream *this,char *param_1,_Ios_Openmode param_2);
void __thiscall std::wofstream::wofstream(wofstream *this,char *param_1,_Ios_Openmode param_2);
void __thiscall std::wifstream::wifstream(wifstream *this,char *param_1,_Ios_Openmode param_2);
void __thiscall std::wofstream::wofstream(wofstream *this,string *param_1,_Ios_Openmode param_2);
void __thiscall std::wofstream::wofstream(wofstream *this,string *param_1,_Ios_Openmode param_2);
void __thiscall std::wifstream::wifstream(wifstream *this,string *param_1,_Ios_Openmode param_2);
void __thiscall std::wifstream::wifstream(wifstream *this,char *param_1,_Ios_Openmode param_2);
void __thiscall std::wifstream::wifstream(wifstream *this,string *param_1,_Ios_Openmode param_2);
void __thiscall std::wifstream::close(wifstream *this);
void __thiscall std::wofstream::close(wofstream *this);
void __thiscall std::wfstream::close(wfstream *this);
void __thiscall std::wifstream::~wifstream(wifstream *this);
void __thiscall std::wifstream::~wifstream(wifstream *this);
void __thiscall std::wofstream::~wofstream(wofstream *this);
void __thiscall std::wofstream::~wofstream(wofstream *this);
void __thiscall std::wfstream::~wfstream(wfstream *this);
void __thiscall std::wfstream::~wfstream(wfstream *this);
void __thiscall std::wfstream::~wfstream(wfstream *this);
void __thiscall std::wfstream::~wfstream(wfstream *this);
void __thiscall std::wfstream::~wfstream(wfstream *this);
void __thiscall std::wfstream::~wfstream(wfstream *this);
void __thiscall std::wifstream::~wifstream(wifstream *this);
void __thiscall std::wifstream::~wifstream(wifstream *this);
void __thiscall std::wofstream::~wofstream(wofstream *this);
void __thiscall std::wofstream::~wofstream(wofstream *this);
void __thiscall std::wfilebuf::~wfilebuf(wfilebuf *this);
void __thiscall std::wofstream::~wofstream(wofstream *this);
void __thiscall std::wifstream::~wifstream(wifstream *this);
void __thiscall std::wfstream::~wfstream(wfstream *this);
void std::__throw_out_of_range_fmt(char *param_1,undefined param_2,undefined param_3,undefined param_4,undefined param_5,undefined param_6,undefined param_7,...);
char * std::bad_function_call::what(void);
void __thiscall std::bad_function_call::~bad_function_call(bad_function_call *this);
void __thiscall std::bad_function_call::~bad_function_call(bad_function_call *this);
void __thiscall std::ios::~ios(ios *this);
void __thiscall std::wios::~wios(wios *this);
void __thiscall std::ios::~ios(ios *this);
void __thiscall std::wios::~wios(wios *this);
bool __thiscall std::ios::operator.cast.to.bool(ios *this);
bool __thiscall std::ios::operator!(ios *this);
undefined4 __thiscall std::ios::rdstate(ios *this);
void __thiscall std::ios::clear(ios *this,uint param_2);
void __thiscall std::ios::setstate(ios *this,uint param_2);
void __thiscall std::ios::_M_setstate(ios *this,uint param_2);
undefined4 __thiscall std::ios::good(ios *this);
uint __thiscall std::ios::eof(ios *this);
bool __thiscall std::ios::fail(ios *this);
uint __thiscall std::ios::bad(ios *this);
undefined4 __thiscall std::ios::exceptions(ios *this);
void __thiscall std::ios::exceptions(ios *this,undefined4 param_2);
undefined8 __thiscall std::ios::tie(ios *this);
undefined8 __thiscall std::ios::tie(ios *this,ostream *param_1);
undefined8 __thiscall std::ios::rdbuf(ios *this);
undefined8 __thiscall std::ios::rdbuf(ios *this,streambuf *param_1);
ulong __thiscall std::ios::fill(ios *this);
ulong __thiscall std::ios::fill(ios *this,char param_1);
ulong __thiscall std::ios::narrow(ios *this,char param_1,char param_2);
ulong __thiscall std::ios::widen(ios *this,char param_1);
void __thiscall std::ios::ios(ios *this);
void __thiscall std::ios::set_rdbuf(ios *this,streambuf *param_1);
void __thiscall std::ios::_M_cache_locale(ios *this,locale *param_1);
ios * __thiscall std::ios::copyfmt(ios *this,ios *param_1);
locale * std::ios::imbue(locale *param_1);
void __thiscall std::ios::init(ios *this,streambuf *param_1);
void __thiscall std::ios::ios(ios *this,streambuf *param_1);
void __thiscall std::ios::move(ios *this,ios *param_1);
void __thiscall std::ios::swap(ios *this,ios *param_1);
void __thiscall std::ios::move(ios *this,ios *param_1);
bool __thiscall std::wios::operator.cast.to.bool(wios *this);
bool __thiscall std::wios::operator!(wios *this);
undefined4 __thiscall std::wios::rdstate(wios *this);
void __thiscall std::wios::clear(wios *this,uint param_2);
void __thiscall std::wios::setstate(wios *this,uint param_2);
void __thiscall std::wios::_M_setstate(wios *this,uint param_2);
undefined4 __thiscall std::wios::good(wios *this);
uint __thiscall std::wios::eof(wios *this);
bool __thiscall std::wios::fail(wios *this);
uint __thiscall std::wios::bad(wios *this);
undefined4 __thiscall std::wios::exceptions(wios *this);
void __thiscall std::wios::exceptions(wios *this,undefined4 param_2);
undefined8 __thiscall std::wios::tie(wios *this);
undefined8 __thiscall std::wios::tie(wios *this,wostream *param_1);
undefined8 __thiscall std::wios::rdbuf(wios *this);
undefined8 __thiscall std::wios::rdbuf(wios *this,wstreambuf *param_1);
ulong __thiscall std::wios::fill(wios *this);
ulong __thiscall std::wios::fill(wios *this,wchar_t param_1);
void __thiscall std::wios::narrow(wios *this,wchar_t param_1,char param_2);
void __thiscall std::wios::widen(wios *this,char param_1);
void __thiscall std::wios::wios(wios *this);
void __thiscall std::wios::set_rdbuf(wios *this,wstreambuf *param_1);
void __thiscall std::wios::_M_cache_locale(wios *this,locale *param_1);
wios * __thiscall std::wios::copyfmt(wios *this,wios *param_1);
locale * std::wios::imbue(locale *param_1);
void __thiscall std::wios::init(wios *this,wstreambuf *param_1);
void __thiscall std::wios::wios(wios *this,wstreambuf *param_1);
void __thiscall std::wios::move(wios *this,wios *param_1);
void __thiscall std::wios::swap(wios *this,wios *param_1);
void __thiscall std::wios::move(wios *this,wios *param_1);
void __thiscall std::ios_base::ios_base(ios_base *this);
int std::ios_base::xalloc(void);
void __thiscall std::ios_base::register_callback(ios_base *this,_func_void_event_ios_base_ptr_int *param_1,int param_2);
ios_base * __thiscall std::ios_base::_M_grow_words(ios_base *this,int param_1,bool param_2);
void __thiscall std::ios_base::_M_call_callbacks(ios_base *this,event param_1);
void __thiscall std::ios_base::_M_dispose_callbacks(ios_base *this);
void __thiscall std::ios_base::~ios_base(ios_base *this);
void __thiscall std::ios_base::~ios_base(ios_base *this);
void __thiscall std::ios_base::_M_move(ios_base *this,ios_base *param_1);
void __thiscall std::ios_base::_M_swap(ios_base *this,ios_base *param_1);
void __thiscall std::iostream::~iostream(iostream *this);
void __thiscall std::iostream::~iostream(iostream *this);
void __thiscall std::iostream::~iostream(iostream *this);
void __thiscall std::iostream::~iostream(iostream *this);
void __thiscall std::iostream::~iostream(iostream *this);
void __thiscall std::iostream::~iostream(iostream *this);
void __thiscall std::wiostream::~wiostream(wiostream *this);
void __thiscall std::wiostream::~wiostream(wiostream *this);
void __thiscall std::wiostream::~wiostream(wiostream *this);
void __thiscall std::wiostream::~wiostream(wiostream *this);
void __thiscall std::wiostream::~wiostream(wiostream *this);
void __thiscall std::wiostream::~wiostream(wiostream *this);
_Setfill std::setfill<char>(char param_1);
void __thiscall std::iostream::iostream(iostream *this,streambuf *param_1);
void __thiscall std::iostream::iostream(iostream *this,streambuf *param_1);
void __thiscall std::iostream::~iostream(iostream *this);
void __thiscall std::iostream::iostream(iostream *this);
void __thiscall std::iostream::iostream(iostream *this);
void __thiscall std::iostream::iostream(iostream *this,iostream *param_1);
void __thiscall std::iostream::iostream(iostream *this,iostream *param_1);
iostream * __thiscall std::iostream::operator=(iostream *this,iostream *param_1);
void __thiscall std::iostream::swap(iostream *this,iostream *param_1);
_Setfill std::setfill<wchar_t>(wchar_t param_1);
void __thiscall std::wiostream::wiostream(wiostream *this,wstreambuf *param_1);
void __thiscall std::wiostream::wiostream(wiostream *this,wstreambuf *param_1);
void __thiscall std::wiostream::~wiostream(wiostream *this);
void __thiscall std::wiostream::wiostream(wiostream *this);
void __thiscall std::wiostream::wiostream(wiostream *this);
void __thiscall std::wiostream::wiostream(wiostream *this,wiostream *param_1);
void __thiscall std::wiostream::wiostream(wiostream *this,wiostream *param_1);
wiostream * __thiscall std::wiostream::operator=(wiostream *this,wiostream *param_1);
void __thiscall std::wiostream::swap(wiostream *this,wiostream *param_1);
void __thiscall std::istream::~istream(istream *this);
void __thiscall std::istream::~istream(istream *this);
void __thiscall std::istream::~istream(istream *this);
void __thiscall std::istream::~istream(istream *this);
void __thiscall std::wistream::~wistream(wistream *this);
void __thiscall std::wistream::~wistream(wistream *this);
void __thiscall std::wistream::~wistream(wistream *this);
void __thiscall std::wistream::~wistream(wistream *this);
void __thiscall std::istream::istream(istream *this,streambuf *param_1);
void __thiscall std::istream::istream(istream *this,streambuf *param_1);
void __thiscall std::istream::~istream(istream *this);
void __thiscall std::istream::operator>>(istream *this,_func_istream_ptr_istream_ptr *param_1);
istream * __thiscall std::istream::operator>>(istream *this,_func_ios_ptr_ios_ptr *param_1);
istream * __thiscall std::istream::operator>>(istream *this,_func_ios_base_ptr_ios_base_ptr *param_1);
undefined8 __thiscall std::istream::gcount(istream *this);
void __thiscall std::istream::getline(istream *this,char *param_1,long param_2);
void __thiscall std::istream::istream(istream *this);
void __thiscall std::istream::istream(istream *this);
void __thiscall std::istream::istream(istream *this,istream *param_1);
void __thiscall std::istream::istream(istream *this,istream *param_1);
istream * __thiscall std::istream::operator=(istream *this,istream *param_1);
void __thiscall std::istream::swap(istream *this,istream *param_1);
void __thiscall std::istream::sentry::sentry(sentry *this,istream *param_1,bool param_2);
istream * __thiscall std::istream::operator>>(istream *this,short *param_1);
istream * __thiscall std::istream::operator>>(istream *this,int *param_1);
istream * __thiscall std::istream::operator>>(istream *this,streambuf *param_1);
ulong __thiscall std::istream::get(istream *this);
istream * __thiscall std::istream::get(istream *this,char *param_1);
istream * __thiscall std::istream::get(istream *this,char *param_1,long param_2,char param_3);
void __thiscall std::istream::get(istream *this,char *param_1,long param_2);
istream * __thiscall std::istream::get(istream *this,streambuf *param_1,char param_2);
void __thiscall std::istream::get(istream *this,streambuf *param_1);
istream * __thiscall std::istream::ignore(istream *this);
ulong __thiscall std::istream::peek(istream *this);
istream * __thiscall std::istream::read(istream *this,char *param_1,long param_2);
undefined8 __thiscall std::istream::readsome(istream *this,char *param_1,long param_2);
istream * __thiscall std::istream::putback(istream *this,char param_1);
istream * __thiscall std::istream::unget(istream *this);
undefined4 __thiscall std::istream::sync(istream *this);
undefined  [16] __thiscall std::istream::tellg(istream *this);
istream * std::istream::seekg(fpos param_1);
istream * __thiscall std::istream::seekg(istream *this,long param_1,_Ios_Seekdir param_2);
bool __thiscall std::istream::sentry::operator.cast.to.bool(sentry *this);
istream * std::ws<>(istream *param_1);
istream * std::operator>>(istream *param_1,char *param_2);
istream * std::operator>>(istream *param_1,uchar *param_2);
istream * std::operator>>(istream *param_1,signed *param_2);
istream * std::operator>>(istream *param_1,uchar *param_2);
istream * std::operator>>(istream *param_1,signed *param_2);
istream * std::operator>>(istream *param_1,_Setfill param_2);
istream * std::operator>>(istream *param_1,_Setiosflags param_2);
istream * std::operator>>(istream *param_1,_Resetiosflags param_2);
istream * std::operator>>(istream *param_1,_Setbase param_2);
istream * std::operator>>(istream *param_1,_Setprecision param_2);
istream * std::operator>>(istream *param_1,_Setw param_2);
istream * __thiscall std::istream::_M_extract<>(istream *this,ushort *param_1);
istream * __thiscall std::istream::operator>>(istream *this,ushort *param_1);
istream * __thiscall std::istream::_M_extract<>(istream *this,uint *param_1);
istream * __thiscall std::istream::operator>>(istream *this,uint *param_1);
istream * __thiscall std::istream::_M_extract<long>(istream *this,long *param_1);
istream * __thiscall std::istream::operator>>(istream *this,long *param_1);
istream * __thiscall std::istream::_M_extract<>(istream *this,ulong *param_1);
istream * __thiscall std::istream::operator>>(istream *this,ulong *param_1);
istream * __thiscall std::istream::_M_extract<bool>(istream *this,bool *param_1);
istream * __thiscall std::istream::operator>>(istream *this,bool *param_1);
istream * __thiscall std::istream::_M_extract<long_long>(istream *this,longlong *param_1);
istream * __thiscall std::istream::operator>>(istream *this,longlong *param_1);
istream * __thiscall std::istream::_M_extract<>(istream *this,ulonglong *param_1);
istream * __thiscall std::istream::operator>>(istream *this,ulonglong *param_1);
istream * __thiscall std::istream::_M_extract<float>(istream *this,float *param_1);
istream * __thiscall std::istream::operator>>(istream *this,float *param_1);
istream * __thiscall std::istream::_M_extract<double>(istream *this,double *param_1);
istream * __thiscall std::istream::operator>>(istream *this,double *param_1);
istream * __thiscall std::istream::_M_extract<>(istream *this,longdouble *param_1);
istream * __thiscall std::istream::operator>>(istream *this,longdouble *param_1);
istream * __thiscall std::istream::_M_extract<void*>(istream *this,void **param_1);
istream * __thiscall std::istream::operator>>(istream *this,void **param_1);
void __thiscall std::wistream::wistream(wistream *this,wstreambuf *param_1);
void __thiscall std::wistream::wistream(wistream *this,wstreambuf *param_1);
void __thiscall std::wistream::~wistream(wistream *this);
void __thiscall std::wistream::operator>>(wistream *this,_func_wistream_ptr_wistream_ptr *param_1);
wistream * __thiscall std::wistream::operator>>(wistream *this,_func_wios_ptr_wios_ptr *param_1);
wistream * __thiscall std::wistream::operator>>(wistream *this,_func_ios_base_ptr_ios_base_ptr *param_1);
undefined8 __thiscall std::wistream::gcount(wistream *this);
void __thiscall std::wistream::getline(wistream *this,wchar_t *param_1,long param_2);
void __thiscall std::wistream::wistream(wistream *this);
void __thiscall std::wistream::wistream(wistream *this);
void __thiscall std::wistream::wistream(wistream *this,wistream *param_1);
void __thiscall std::wistream::wistream(wistream *this,wistream *param_1);
wistream * __thiscall std::wistream::operator=(wistream *this,wistream *param_1);
void __thiscall std::wistream::swap(wistream *this,wistream *param_1);
void __thiscall std::wistream::sentry::sentry(sentry *this,wistream *param_1,bool param_2);
wistream * __thiscall std::wistream::operator>>(wistream *this,short *param_1);
wistream * __thiscall std::wistream::operator>>(wistream *this,int *param_1);
wistream * __thiscall std::wistream::operator>>(wistream *this,wstreambuf *param_1);
ulong __thiscall std::wistream::get(wistream *this);
wistream * __thiscall std::wistream::get(wistream *this,wchar_t *param_1);
wistream * __thiscall std::wistream::get(wistream *this,wchar_t *param_1,long param_2,wchar_t param_3);
void __thiscall std::wistream::get(wistream *this,wchar_t *param_1,long param_2);
wistream * __thiscall std::wistream::get(wistream *this,wstreambuf *param_1,wchar_t param_2);
void __thiscall std::wistream::get(wistream *this,wstreambuf *param_1);
wistream * __thiscall std::wistream::ignore(wistream *this);
ulong __thiscall std::wistream::peek(wistream *this);
wistream * __thiscall std::wistream::read(wistream *this,wchar_t *param_1,long param_2);
undefined8 __thiscall std::wistream::readsome(wistream *this,wchar_t *param_1,long param_2);
wistream * __thiscall std::wistream::putback(wistream *this,wchar_t param_1);
wistream * __thiscall std::wistream::unget(wistream *this);
undefined4 __thiscall std::wistream::sync(wistream *this);
undefined  [16] __thiscall std::wistream::tellg(wistream *this);
wistream * std::wistream::seekg(fpos param_1);
wistream * __thiscall std::wistream::seekg(wistream *this,long param_1,_Ios_Seekdir param_2);
bool __thiscall std::wistream::sentry::operator.cast.to.bool(sentry *this);
wistream * std::ws<>(wistream *param_1);
wistream * std::operator>>(wistream *param_1,wchar_t *param_2);
wistream * std::operator>>(wistream *param_1,wchar_t *param_2);
wistream * std::operator>>(wistream *param_1,_Setfill param_2);
wistream * std::operator>>(wistream *param_1,_Setiosflags param_2);
wistream * std::operator>>(wistream *param_1,_Resetiosflags param_2);
wistream * std::operator>>(wistream *param_1,_Setbase param_2);
wistream * std::operator>>(wistream *param_1,_Setprecision param_2);
wistream * std::operator>>(wistream *param_1,_Setw param_2);
wistream * __thiscall std::wistream::_M_extract<>(wistream *this,ushort *param_1);
wistream * __thiscall std::wistream::operator>>(wistream *this,ushort *param_1);
wistream * __thiscall std::wistream::_M_extract<>(wistream *this,uint *param_1);
wistream * __thiscall std::wistream::operator>>(wistream *this,uint *param_1);
wistream * __thiscall std::wistream::_M_extract<long>(wistream *this,long *param_1);
wistream * __thiscall std::wistream::operator>>(wistream *this,long *param_1);
wistream * __thiscall std::wistream::_M_extract<>(wistream *this,ulong *param_1);
wistream * __thiscall std::wistream::operator>>(wistream *this,ulong *param_1);
wistream * __thiscall std::wistream::_M_extract<bool>(wistream *this,bool *param_1);
wistream * __thiscall std::wistream::operator>>(wistream *this,bool *param_1);
wistream * __thiscall std::wistream::_M_extract<long_long>(wistream *this,longlong *param_1);
wistream * __thiscall std::wistream::operator>>(wistream *this,longlong *param_1);
wistream * __thiscall std::wistream::_M_extract<>(wistream *this,ulonglong *param_1);
wistream * __thiscall std::wistream::operator>>(wistream *this,ulonglong *param_1);
wistream * __thiscall std::wistream::_M_extract<float>(wistream *this,float *param_1);
wistream * __thiscall std::wistream::operator>>(wistream *this,float *param_1);
wistream * __thiscall std::wistream::_M_extract<double>(wistream *this,double *param_1);
wistream * __thiscall std::wistream::operator>>(wistream *this,double *param_1);
wistream * __thiscall std::wistream::_M_extract<>(wistream *this,longdouble *param_1);
wistream * __thiscall std::wistream::operator>>(wistream *this,longdouble *param_1);
wistream * __thiscall std::wistream::_M_extract<void*>(wistream *this,void **param_1);
wistream * __thiscall std::wistream::operator>>(wistream *this,void **param_1);
undefined __thiscall std::moneypunct<char,false>::do_decimal_point(moneypunct<char,false> *this);
undefined __thiscall std::moneypunct<char,false>::do_thousands_sep(moneypunct<char,false> *this);
undefined4 __thiscall std::moneypunct<char,false>::do_frac_digits(moneypunct<char,false> *this);
undefined4 __thiscall std::moneypunct<char,false>::do_pos_format(moneypunct<char,false> *this);
undefined4 __thiscall std::moneypunct<char,false>::do_neg_format(moneypunct<char,false> *this);
undefined __thiscall std::moneypunct<char,true>::do_decimal_point(moneypunct<char,true> *this);
undefined __thiscall std::moneypunct<char,true>::do_thousands_sep(moneypunct<char,true> *this);
undefined4 __thiscall std::moneypunct<char,true>::do_frac_digits(moneypunct<char,true> *this);
undefined4 __thiscall std::moneypunct<char,true>::do_pos_format(moneypunct<char,true> *this);
undefined4 __thiscall std::moneypunct<char,true>::do_neg_format(moneypunct<char,true> *this);
void __thiscall std::moneypunct_byname<char,false>::~moneypunct_byname(moneypunct_byname<char,false> *this);
void __thiscall std::moneypunct_byname<char,true>::~moneypunct_byname(moneypunct_byname<char,true> *this);
undefined __thiscall std::numpunct<char>::do_decimal_point(numpunct<char> *this);
undefined __thiscall std::numpunct<char>::do_thousands_sep(numpunct<char> *this);
void __thiscall std::numpunct_byname<char>::~numpunct_byname(numpunct_byname<char> *this);
undefined8 std::time_get<>::do_date_order(void);
ulong __thiscall std::collate<char>::do_hash(collate<char> *this,char *param_1,char *param_2);
void __thiscall std::money_get<>::~money_get(money_get<> *this);
void __thiscall std::money_put<>::~money_put(money_put<> *this);
void __thiscall std::num_get<>::~num_get(num_get<> *this);
void __thiscall std::num_put<>::~num_put(num_put<> *this);
void __thiscall std::__timepunct_cache<char>::~__timepunct_cache(__timepunct_cache<char> *this);
void __thiscall std::time_put<>::~time_put(time_put<> *this);
void __thiscall std::time_put_byname<>::~time_put_byname(time_put_byname<> *this);
void __thiscall std::time_get<>::~time_get(time_get<> *this);
void __thiscall std::time_get_byname<>::~time_get_byname(time_get_byname<> *this);
void __thiscall std::moneypunct_byname<char,false>::~moneypunct_byname(moneypunct_byname<char,false> *this);
void __thiscall std::moneypunct_byname<char,true>::~moneypunct_byname(moneypunct_byname<char,true> *this);
void __thiscall std::money_get<>::~money_get(money_get<> *this);
void __thiscall std::money_put<>::~money_put(money_put<> *this);
void __thiscall std::numpunct_byname<char>::~numpunct_byname(numpunct_byname<char> *this);
void __thiscall std::num_get<>::~num_get(num_get<> *this);
void __thiscall std::num_put<>::~num_put(num_put<> *this);
void __thiscall std::__timepunct_cache<char>::~__timepunct_cache(__timepunct_cache<char> *this);
void __thiscall std::time_put<>::~time_put(time_put<> *this);
void __thiscall std::time_put_byname<>::~time_put_byname(time_put_byname<> *this);
void __thiscall std::time_get<>::~time_get(time_get<> *this);
void __thiscall std::time_get_byname<>::~time_get_byname(time_get_byname<> *this);
void std::moneypunct<char,false>::do_grouping(void);
void std::moneypunct<char,false>::do_curr_symbol(void);
void std::moneypunct<char,false>::do_positive_sign(void);
void std::moneypunct<char,false>::do_negative_sign(void);
void std::moneypunct<char,true>::do_grouping(void);
void std::moneypunct<char,true>::do_curr_symbol(void);
void std::moneypunct<char,true>::do_positive_sign(void);
void std::moneypunct<char,true>::do_negative_sign(void);
void std::numpunct<char>::do_grouping(void);
void std::numpunct<char>::do_truename(void);
void std::numpunct<char>::do_falsename(void);
void __thiscall std::collate<char>::~collate(collate<char> *this);
void __thiscall std::collate<char>::~collate(collate<char> *this);
void __thiscall std::collate_byname<char>::~collate_byname(collate_byname<char> *this);
void __thiscall std::collate_byname<char>::~collate_byname(collate_byname<char> *this);
void __thiscall std::__timepunct<char>::~__timepunct(__timepunct<char> *this);
void __thiscall std::__timepunct<char>::~__timepunct(__timepunct<char> *this);
void __thiscall std::messages<char>::~messages(messages<char> *this);
void __thiscall std::messages<char>::~messages(messages<char> *this);
void __thiscall std::messages_byname<char>::~messages_byname(messages_byname<char> *this);
void __thiscall std::messages_byname<char>::~messages_byname(messages_byname<char> *this);
void __thiscall std::codecvt_byname<>::~codecvt_byname(codecvt_byname<> *this);
void __thiscall std::codecvt_byname<>::~codecvt_byname(codecvt_byname<> *this);
void std::string::_Rep::_M_dispose(allocator *param_1);
void __thiscall std::streambuf::sbumpc(streambuf *this);
ulong std::istreambuf_iterator<>::_M_get(void);
int __thiscall std::collate<char>::do_compare(collate<char> *this,char *param_1,char *param_2,char *param_3,char *param_4);
char * std::collate<char>::do_transform(char *param_1,char *param_2);
char * __thiscall std::ctype<char>::widen(ctype<char> *this,char *param_1,char *param_2,char *param_3);
void __thiscall std::__moneypunct_cache<char,false>::__moneypunct_cache(__moneypunct_cache<char,false> *this,ulong param_1);
void __thiscall std::__moneypunct_cache<char,true>::__moneypunct_cache(__moneypunct_cache<char,true> *this,ulong param_1);
void __thiscall std::moneypunct<char,false>::moneypunct(moneypunct<char,false> *this,ulong param_1);
void __thiscall std::moneypunct<char,false>::moneypunct(moneypunct<char,false> *this,__moneypunct_cache *param_1,ulong param_2);
void __thiscall std::moneypunct<char,false>::moneypunct(moneypunct<char,false> *this,__locale_struct *param_1,char *param_2,ulong param_3);
ulong __thiscall std::moneypunct<char,false>::decimal_point(moneypunct<char,false> *this);
ulong __thiscall std::moneypunct<char,false>::thousands_sep(moneypunct<char,false> *this);
void std::moneypunct<char,false>::grouping(void);
void std::moneypunct<char,false>::curr_symbol(void);
void std::moneypunct<char,false>::positive_sign(void);
void std::moneypunct<char,false>::negative_sign(void);
ulong __thiscall std::moneypunct<char,false>::frac_digits(moneypunct<char,false> *this);
ulong __thiscall std::moneypunct<char,false>::pos_format(moneypunct<char,false> *this);
ulong __thiscall std::moneypunct<char,false>::neg_format(moneypunct<char,false> *this);
void __thiscall std::moneypunct<char,true>::moneypunct(moneypunct<char,true> *this,ulong param_1);
void __thiscall std::moneypunct<char,true>::moneypunct(moneypunct<char,true> *this,__moneypunct_cache *param_1,ulong param_2);
void __thiscall std::moneypunct<char,true>::moneypunct(moneypunct<char,true> *this,__locale_struct *param_1,char *param_2,ulong param_3);
ulong __thiscall std::moneypunct<char,true>::decimal_point(moneypunct<char,true> *this);
ulong __thiscall std::moneypunct<char,true>::thousands_sep(moneypunct<char,true> *this);
void std::moneypunct<char,true>::grouping(void);
void std::moneypunct<char,true>::curr_symbol(void);
void std::moneypunct<char,true>::positive_sign(void);
void std::moneypunct<char,true>::negative_sign(void);
ulong __thiscall std::moneypunct<char,true>::frac_digits(moneypunct<char,true> *this);
ulong __thiscall std::moneypunct<char,true>::pos_format(moneypunct<char,true> *this);
ulong __thiscall std::moneypunct<char,true>::neg_format(moneypunct<char,true> *this);
void __thiscall std::moneypunct_byname<char,false>::moneypunct_byname(moneypunct_byname<char,false> *this,char *param_1,ulong param_2);
void __thiscall std::moneypunct_byname<char,false>::moneypunct_byname(moneypunct_byname<char,false> *this,string *param_1,ulong param_2);
void __thiscall std::moneypunct_byname<char,true>::moneypunct_byname(moneypunct_byname<char,true> *this,char *param_1,ulong param_2);
void __thiscall std::moneypunct_byname<char,true>::moneypunct_byname(moneypunct_byname<char,true> *this,string *param_1,ulong param_2);
void __thiscall std::money_get<>::money_get(money_get<> *this,ulong param_1);
void std::money_get<>::get(istreambuf_iterator param_1,istreambuf_iterator param_2,bool param_3,ios_base *param_4,_Ios_Iostate *param_5,longdouble *param_6);
void std::money_get<>::get(istreambuf_iterator param_1,istreambuf_iterator param_2,bool param_3,ios_base *param_4,_Ios_Iostate *param_5,string *param_6);
void __thiscall std::money_put<>::money_put(money_put<> *this,ulong param_1);
void std::money_put<>::put(ostreambuf_iterator param_1,bool param_2,ios_base *param_3,char param_4,longdouble param_5);
void std::money_put<>::put(ostreambuf_iterator param_1,bool param_2,ios_base *param_3,char param_4,string *param_5);
void __thiscall std::__numpunct_cache<char>::__numpunct_cache(__numpunct_cache<char> *this,ulong param_1);
void __thiscall std::numpunct<char>::numpunct(numpunct<char> *this,ulong param_1);
void __thiscall std::numpunct<char>::numpunct(numpunct<char> *this,__numpunct_cache *param_1,ulong param_2);
void __thiscall std::numpunct<char>::numpunct(numpunct<char> *this,__locale_struct *param_1,ulong param_2);
ulong __thiscall std::numpunct<char>::decimal_point(numpunct<char> *this);
ulong __thiscall std::numpunct<char>::thousands_sep(numpunct<char> *this);
void std::numpunct<char>::grouping(void);
void std::numpunct<char>::truename(void);
void std::numpunct<char>::falsename(void);
void __thiscall std::numpunct_byname<char>::numpunct_byname(numpunct_byname<char> *this,char *param_1,ulong param_2);
void __thiscall std::numpunct_byname<char>::numpunct_byname(numpunct_byname<char> *this,string *param_1,ulong param_2);
void __thiscall std::num_get<>::num_get(num_get<> *this,ulong param_1);
void std::num_get<>::get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,bool *param_5);
void std::num_get<>::get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,float *param_5);
void std::num_get<>::get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,double *param_5);
void std::num_get<>::get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,longdouble *param_5);
void std::num_get<>::get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,void **param_5);
void __thiscall std::num_put<>::num_put(num_put<> *this,ulong param_1);
void std::num_put<>::put(ostreambuf_iterator param_1,ios_base *param_2,char param_3,bool param_4);
void std::num_put<>::put(ostreambuf_iterator param_1,ios_base *param_2,char param_3,double param_4);
void std::num_put<>::put(ostreambuf_iterator param_1,ios_base *param_2,char param_3,longdouble param_4);
void std::num_put<>::put(ostreambuf_iterator param_1,ios_base *param_2,char param_3,void *param_4);
void __thiscall std::__timepunct<char>::__timepunct(__timepunct<char> *this,ulong param_1);
void __thiscall std::__timepunct<char>::__timepunct(__timepunct<char> *this,__timepunct_cache *param_1,ulong param_2);
void __thiscall std::__timepunct<char>::__timepunct(__timepunct<char> *this,__locale_struct *param_1,char *param_2,ulong param_3);
void __thiscall std::__timepunct<char>::_M_date_formats(__timepunct<char> *this,char **param_1);
void __thiscall std::__timepunct<char>::_M_time_formats(__timepunct<char> *this,char **param_1);
void __thiscall std::__timepunct<char>::_M_date_time_formats(__timepunct<char> *this,char **param_1);
void std::__timepunct<char>::_M_am_pm_format(char *param_1);
void __thiscall std::__timepunct<char>::_M_am_pm(__timepunct<char> *this,char **param_1);
void __thiscall std::__timepunct<char>::_M_days(__timepunct<char> *this,char **param_1);
void __thiscall std::__timepunct<char>::_M_days_abbreviated(__timepunct<char> *this,char **param_1);
void __thiscall std::__timepunct<char>::_M_months(__timepunct<char> *this,char **param_1);
void __thiscall std::__timepunct<char>::_M_months_abbreviated(__timepunct<char> *this,char **param_1);
void __thiscall std::__timepunct_cache<char>::__timepunct_cache(__timepunct_cache<char> *this,ulong param_1);
void __thiscall std::time_put<>::time_put(time_put<> *this,ulong param_1);
void std::time_put<>::put(ostreambuf_iterator param_1,ios_base *param_2,char param_3,tm *param_4,char param_5,char param_6,undefined4 param_7,undefined4 param_8);
void __thiscall std::time_put_byname<>::time_put_byname(time_put_byname<> *this,char *param_1,ulong param_2);
void __thiscall std::time_put_byname<>::time_put_byname(time_put_byname<> *this,string *param_1,ulong param_2);
void __thiscall std::time_get<>::time_get(time_get<> *this,ulong param_1);
void __thiscall std::time_get<>::date_order(time_get<> *this);
void std::time_get<>::get_time(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5);
void std::time_get<>::get_date(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5);
void std::time_get<>::get_weekday(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5);
void std::time_get<>::get_monthname(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5);
void std::time_get<>::get_year(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5);
void __thiscall std::time_get_byname<>::time_get_byname(time_get_byname<> *this,char *param_1,ulong param_2);
void __thiscall std::time_get_byname<>::time_get_byname(time_get_byname<> *this,string *param_1,ulong param_2);
void __thiscall std::messages<char>::messages(messages<char> *this,ulong param_1);
void __thiscall std::messages<char>::messages(messages<char> *this,__locale_struct *param_1,char *param_2,ulong param_3);
void std::messages<char>::open(string *param_1,locale *param_2);
void __thiscall std::messages<char>::open(messages<char> *this,string *param_1,locale *param_2,char *param_3);
undefined8 std::messages<char>::get(int param_1,int param_2,int param_3,string *param_4);
void std::messages<char>::close(int param_1);
undefined8 __thiscall std::messages<char>::_M_convert_to_char(messages<char> *this,string *param_1);
char * std::messages<char>::_M_convert_from_char(char *param_1);
void __thiscall std::messages_byname<char>::messages_byname(messages_byname<char> *this,char *param_1,ulong param_2);
void __thiscall std::messages_byname<char>::messages_byname(messages_byname<char> *this,string *param_1,ulong param_2);
void __thiscall std::ctype_byname<char>::ctype_byname(ctype_byname<char> *this,string *param_1,ulong param_2);
void __thiscall std::codecvt_byname<>::codecvt_byname(codecvt_byname<> *this,char *param_1,ulong param_2);
void __thiscall std::codecvt_byname<>::codecvt_byname(codecvt_byname<> *this,string *param_1,ulong param_2);
void __thiscall std::collate<char>::collate(collate<char> *this,ulong param_1);
void __thiscall std::collate<char>::collate(collate<char> *this,__locale_struct *param_1,ulong param_2);
void std::collate<char>::compare(char *param_1,char *param_2,char *param_3,char *param_4);
char * std::collate<char>::transform(char *param_1,char *param_2);
void std::collate<char>::hash(char *param_1,char *param_2);
void __thiscall std::collate_byname<char>::collate_byname(collate_byname<char> *this,char *param_1,ulong param_2);
void __thiscall std::collate_byname<char>::collate_byname(collate_byname<char> *this,string *param_1,ulong param_2);
ctype * std::use_facet<>(locale *param_1);
undefined  [16]std::time_put<>::put(ostreambuf_iterator param_1,ios_base *param_2,char param_3,tm *param_4,char *param_5,char *param_6,ctype *param_7,ctype *param_8);
undefined  [16]std::time_get<>::_M_extract_num(istreambuf_iterator param_1,istreambuf_iterator param_2,int *param_3,int param_4,int param_5,ulong param_6,ios_base *param_7,_Ios_Iostate *param_8);
undefined  [16]std::time_get<>::do_get_year(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,undefined param_6,uint *param_7,long param_8);
undefined  [16]std::time_get<>::_M_extract_name(istreambuf_iterator param_1,istreambuf_iterator param_2,int *param_3,char **param_4,ulong param_5,ios_base *param_6,_Ios_Iostate *param_7);
undefined  [16]std::time_get<>::_M_extract_wday_or_month(istreambuf_iterator param_1,istreambuf_iterator param_2,int *param_3,char **param_4,ulong param_5,ios_base *param_6,_Ios_Iostate *param_7);
codecvt * std::use_facet<>(locale *param_1);
collate * std::use_facet<>(locale *param_1);
numpunct * std::use_facet<>(locale *param_1);
void __thiscall std::__numpunct_cache<char>::_M_cache(__numpunct_cache<char> *this,locale *param_1);
num_put * std::use_facet<>(locale *param_1);
num_get * std::use_facet<>(locale *param_1);
moneypunct * std::use_facet<>(locale *param_1);
void __thiscall std::__moneypunct_cache<char,true>::_M_cache(__moneypunct_cache<char,true> *this,locale *param_1);
moneypunct * std::use_facet<>(locale *param_1);
void __thiscall std::__moneypunct_cache<char,false>::_M_cache(__moneypunct_cache<char,false> *this,locale *param_1);
money_put * std::use_facet<>(locale *param_1);
money_get * std::use_facet<>(locale *param_1);
__timepunct * std::use_facet<>(locale *param_1);
undefined  [16]std::time_put<>::do_put(ostreambuf_iterator param_1,ios_base *param_2,char param_3,tm *param_4,char param_5,char param_6,undefined4 param_7,undefined4 param_8);
undefined  [16]std::time_get<>::do_get_weekday(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,undefined param_6,uint *param_7,long param_8);
undefined  [16]std::time_get<>::do_get_monthname(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,undefined param_6,uint *param_7,long param_8);
time_put * std::use_facet<>(locale *param_1);
time_get * std::use_facet<>(locale *param_1);
messages * std::use_facet<>(locale *param_1);
bool std::has_facet<>(locale *param_1);
bool std::has_facet<>(locale *param_1);
bool std::has_facet<>(locale *param_1);
bool std::has_facet<>(locale *param_1);
bool std::has_facet<>(locale *param_1);
bool std::has_facet<>(locale *param_1);
bool std::has_facet<>(locale *param_1);
bool std::has_facet<>(locale *param_1);
bool std::has_facet<>(locale *param_1);
bool std::has_facet<>(locale *param_1);
bool std::has_facet<>(locale *param_1);
bool std::has_facet<>(locale *param_1);
bool std::has_facet<>(locale *param_1);
char * std::__add_grouping<char>(char *param_1,char param_2,char *param_3,ulong param_4,char *param_5,char *param_6);
void __thiscall std::num_put<>::_M_group_float(num_put<> *this,char *param_1,ulong param_2,char param_3,char *param_4,char *param_5,char *param_6,int *param_7);
void __thiscall std::num_put<>::_M_group_int(num_put<> *this,char *param_1,ulong param_2,char param_3,ios_base *param_4,char *param_5,char *param_6,int *param_7);
ostreambuf_iterator std::money_put<>::_M_insert<true>(ostreambuf_iterator param_1,ios_base *param_2,char param_3,string *param_4);
ostreambuf_iterator std::money_put<>::_M_insert<false>(ostreambuf_iterator param_1,ios_base *param_2,char param_3,string *param_4);
undefined  [16]std::money_put<>::do_put(ostreambuf_iterator param_1,bool param_2,ios_base *param_3,char param_4,longdouble param_5);
void std::money_put<>::do_put(ostreambuf_iterator param_1,bool param_2,ios_base *param_3,char param_4,string *param_5,undefined param_6,undefined8 param_7);
void std::__pad<>::_S_pad(ios_base *param_1,char param_2,char *param_3,char *param_4,long param_5,long param_6);
void __thiscall std::num_put<>::_M_pad(num_put<> *this,char param_1,long param_2,ios_base *param_3,char *param_4,char *param_5,int *param_6);
ostreambuf_iterator std::num_put<>::_M_insert_float<double>(ostreambuf_iterator param_1,ios_base *param_2,char param_3,char param_4,double param_5);
void __thiscall std::num_put<>::do_put(num_put<> *this,ostreambuf_iterator param_1,ios_base *param_2,char param_3,double param_4);
ostreambuf_iterator std::num_put<>::_M_insert_float<>(ostreambuf_iterator param_1,ios_base *param_2,char param_3,char param_4,longdouble param_5);
void std::num_put<>::do_put(ostreambuf_iterator param_1,ios_base *param_2,char param_3,longdouble param_4);
int std::__int_to_char<>(char *param_1,ulong param_2,char *param_3,_Ios_Fmtflags param_4,bool param_5);
ostreambuf_iterator std::num_put<>::_M_insert_int<long>(ostreambuf_iterator param_1,ios_base *param_2,char param_3,long param_4);
void std::num_put<>::do_put(ostreambuf_iterator param_1,ios_base *param_2,char param_3,long param_4);
void std::num_put<>::put(ostreambuf_iterator param_1,ios_base *param_2,char param_3,long param_4);
ostreambuf_iterator std::num_put<>::_M_insert_int<>(ostreambuf_iterator param_1,ios_base *param_2,char param_3,ulong param_4);
void std::num_put<>::do_put(ostreambuf_iterator param_1,ios_base *param_2,char param_3,ulong param_4);
void std::num_put<>::do_put(ostreambuf_iterator param_1,ios_base *param_2,char param_3,void *param_4);
void std::num_put<>::put(ostreambuf_iterator param_1,ios_base *param_2,char param_3,ulong param_4);
int std::__int_to_char<>(char *param_1,ulonglong param_2,char *param_3,_Ios_Fmtflags param_4,bool param_5);
ostreambuf_iterator std::num_put<>::_M_insert_int<long_long>(ostreambuf_iterator param_1,ios_base *param_2,char param_3,longlong param_4);
void std::num_put<>::do_put(ostreambuf_iterator param_1,ios_base *param_2,char param_3,longlong param_4);
void std::num_put<>::put(ostreambuf_iterator param_1,ios_base *param_2,char param_3,longlong param_4);
ostreambuf_iterator std::num_put<>::_M_insert_int<>(ostreambuf_iterator param_1,ios_base *param_2,char param_3,ulonglong param_4);
void std::num_put<>::do_put(ostreambuf_iterator param_1,ios_base *param_2,char param_3,ulonglong param_4);
void std::num_put<>::put(ostreambuf_iterator param_1,ios_base *param_2,char param_3,ulonglong param_4);
long __thiscall std::__use_cache<>::operator()(__use_cache<> *this,locale *param_1);
undefined  [16]std::num_put<>::do_put(ostreambuf_iterator param_1,ios_base *param_2,char param_3,bool param_4);
bool __thiscall std::istreambuf_iterator<>::equal(istreambuf_iterator<> *this,istreambuf_iterator *param_1);
undefined  [16]std::time_get<>::_M_extract_via_format(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,char *param_6,uint *param_7,int *param_8,size_t *param_9);
undefined  [16]std::time_get<>::do_get_time(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,undefined param_6,uint *param_7,undefined8 param_8);
undefined  [16]std::time_get<>::do_get_date(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,undefined param_6,uint *param_7,undefined8 param_8);
undefined  [16]std::time_get<>::do_get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,char param_6,char param_7);
undefined  [16]std::time_get<>::get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,char param_6,char param_7);
undefined  [16]std::time_get<>::get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,char *param_6,char *param_7);
undefined  [16]std::num_get<>::_M_extract_float(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,string *param_5,undefined param_6,undefined4 *param_7,string *param_8);
undefined  [16]std::num_get<>::do_get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,float *param_5,undefined param_6,_Ios_Iostate *param_7,float *param_8);
undefined  [16]std::num_get<>::do_get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,double *param_5,undefined param_6,_Ios_Iostate *param_7,double *param_8);
undefined  [16]std::num_get<>::do_get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,longdouble *param_5,undefined param_6,_Ios_Iostate *param_7,longdouble *param_8);
istreambuf_iterator std::num_get<>::_M_extract_int<long>(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,long *param_5,undefined param_6,uint *param_7,ulong *param_8);
undefined  [16]std::num_get<>::do_get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,long *param_5);
void std::num_get<>::get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,long *param_5);
undefined  [16]std::num_get<>::do_get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,bool *param_5,undefined param_6,uint *param_7,byte *param_8);
istreambuf_iterator std::num_get<>::_M_extract_int<>(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,ushort *param_5,undefined param_6,uint *param_7,ushort *param_8);
undefined  [16]std::num_get<>::do_get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,ushort *param_5);
void std::num_get<>::get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,ushort *param_5);
istreambuf_iterator std::num_get<>::_M_extract_int<>(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,uint *param_5,undefined param_6,uint *param_7,uint *param_8);
undefined  [16]std::num_get<>::do_get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,uint *param_5);
void std::num_get<>::get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,uint *param_5);
istreambuf_iterator std::num_get<>::_M_extract_int<>(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,ulong *param_5,undefined param_6,uint *param_7,ulong *param_8);
undefined  [16]std::num_get<>::do_get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,ulong *param_5);
void std::num_get<>::do_get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,void **param_5,undefined param_6,undefined8 param_7,undefined8 *param_8);
void std::num_get<>::get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,ulong *param_5);
istreambuf_iterator std::num_get<>::_M_extract_int<long_long>(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,longlong *param_5,undefined param_6,uint *param_7,ulong *param_8);
undefined  [16]std::num_get<>::do_get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,longlong *param_5);
void std::num_get<>::get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,longlong *param_5);
istreambuf_iterator std::num_get<>::_M_extract_int<>(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,ulonglong *param_5,undefined param_6,uint *param_7,ulong *param_8);
undefined  [16]std::num_get<>::do_get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,ulonglong *param_5);
void std::num_get<>::get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,ulonglong *param_5);
istreambuf_iterator std::money_get<>::_M_extract<true>(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,string *param_5,undefined param_6,uint *param_7,string *param_8);
istreambuf_iterator std::money_get<>::_M_extract<false>(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,string *param_5,undefined param_6,uint *param_7,string *param_8);
undefined  [16]std::money_get<>::do_get(istreambuf_iterator param_1,istreambuf_iterator param_2,bool param_3,ios_base *param_4,_Ios_Iostate *param_5,longdouble *param_6,undefined8 param_7,_Ios_Iostate *param_8,longdouble *param_9);
undefined  [16]std::money_get<>::do_get(istreambuf_iterator param_1,istreambuf_iterator param_2,bool param_3,ios_base *param_4,_Ios_Iostate *param_5,string *param_6,long param_7,undefined8 param_8,string *param_9);
void __thiscall std::ostream::~ostream(ostream *this);
void __thiscall std::ostream::~ostream(ostream *this);
void __thiscall std::ostream::~ostream(ostream *this);
void __thiscall std::ostream::~ostream(ostream *this);
void __thiscall std::wostream::~wostream(wostream *this);
void __thiscall std::wostream::~wostream(wostream *this);
void __thiscall std::wostream::~wostream(wostream *this);
void __thiscall std::wostream::~wostream(wostream *this);
void __thiscall std::ostream::ostream(ostream *this,streambuf *param_1);
void __thiscall std::ostream::ostream(ostream *this,streambuf *param_1);
void __thiscall std::ostream::~ostream(ostream *this);
void __thiscall std::ostream::operator<<(ostream *this,_func_ostream_ptr_ostream_ptr *param_1);
ostream * __thiscall std::ostream::operator<<(ostream *this,_func_ios_ptr_ios_ptr *param_1);
ostream * __thiscall std::ostream::operator<<(ostream *this,_func_ios_base_ptr_ios_base_ptr *param_1);
void __thiscall std::ostream::_M_write(ostream *this,char *param_1,long param_2);
ostream * __thiscall std::ostream::flush(ostream *this);
undefined  [16] __thiscall std::ostream::tellp(ostream *this);
long * std::ostream::seekp(fpos param_1);
long std::ostream::seekp(long param_1,_Ios_Seekdir param_2);
void __thiscall std::ostream::ostream(ostream *this);
void __thiscall std::ostream::ostream(ostream *this);
void __thiscall std::ostream::ostream(ostream *this,iostream *param_1);
void __thiscall std::ostream::ostream(ostream *this,iostream *param_1);
void __thiscall std::ostream::ostream(ostream *this,ostream *param_1);
void __thiscall std::ostream::ostream(ostream *this,ostream *param_1);
ostream * __thiscall std::ostream::operator=(ostream *this,ostream *param_1);
void __thiscall std::ostream::swap(ostream *this,ostream *param_1);
void __thiscall std::ostream::sentry::sentry(sentry *this,ostream *param_1);
void __thiscall std::ostream::sentry::~sentry(sentry *this);
ostream * __thiscall std::ostream::operator<<(ostream *this,streambuf *param_1);
ostream * __thiscall std::ostream::put(ostream *this,char param_1);
ostream * __thiscall std::ostream::write(ostream *this,char *param_1,long param_2);
bool __thiscall std::ostream::sentry::operator.cast.to.bool(sentry *this);
ostream * std::endl<>(ostream *param_1);
ostream * std::ends<>(ostream *param_1);
ostream * std::flush<>(ostream *param_1);
ostream * std::operator<<(ostream *param_1,_Setfill param_2);
ostream * std::operator<<(ostream *param_1,_Setiosflags param_2);
ostream * std::operator<<(ostream *param_1,_Resetiosflags param_2);
ostream * std::operator<<(ostream *param_1,_Setbase param_2);
ostream * std::operator<<(ostream *param_1,_Setprecision param_2);
ostream * std::operator<<(ostream *param_1,_Setw param_2);
ostream * std::__ostream_insert<>(ostream *param_1,char *param_2,long param_3);
ostream * std::operator<<(ostream *param_1,char param_2);
ostream * std::operator<<(ostream *param_1,uchar param_2);
void std::operator<<(ostream *param_1,char param_2);
ostream * std::operator<<(ostream *param_1,char *param_2);
ostream * std::operator<<(ostream *param_1,uchar *param_2);
ostream * std::operator<<(ostream *param_1,signed *param_2);
ostream * __thiscall std::ostream::_M_insert<long>(ostream *this,long param_1);
ostream * __thiscall std::ostream::operator<<(ostream *this,long param_1);
void __thiscall std::ostream::operator<<(ostream *this,short param_1);
void __thiscall std::ostream::operator<<(ostream *this,int param_1);
ostream * __thiscall std::ostream::_M_insert<>(ostream *this,ulong param_1);
ostream * __thiscall std::ostream::operator<<(ostream *this,ulong param_1);
void __thiscall std::ostream::operator<<(ostream *this,ushort param_1);
void __thiscall std::ostream::operator<<(ostream *this,uint param_1);
ostream * __thiscall std::ostream::_M_insert<bool>(ostream *this,bool param_1);
void __thiscall std::ostream::operator<<(ostream *this,bool param_1);
ostream * __thiscall std::ostream::_M_insert<long_long>(ostream *this,longlong param_1);
ostream * __thiscall std::ostream::operator<<(ostream *this,longlong param_1);
ostream * __thiscall std::ostream::_M_insert<>(ostream *this,ulonglong param_1);
ostream * __thiscall std::ostream::operator<<(ostream *this,ulonglong param_1);
ostream * __thiscall std::ostream::_M_insert<double>(ostream *this,double param_1);
ostream * __thiscall std::ostream::operator<<(ostream *this,double param_1);
void __thiscall std::ostream::operator<<(ostream *this,float param_1);
ostream * std::ostream::_M_insert<>(longdouble param_1);
ostream * __thiscall std::ostream::operator<<(ostream *this,longdouble param_1);
ostream * __thiscall std::ostream::_M_insert<>(ostream *this,void *param_1);
ostream * __thiscall std::ostream::operator<<(ostream *this,void *param_1);
void __thiscall std::wostream::wostream(wostream *this,wstreambuf *param_1);
void __thiscall std::wostream::wostream(wostream *this,wstreambuf *param_1);
void __thiscall std::wostream::~wostream(wostream *this);
void __thiscall std::wostream::operator<<(wostream *this,_func_wostream_ptr_wostream_ptr *param_1);
wostream * __thiscall std::wostream::operator<<(wostream *this,_func_wios_ptr_wios_ptr *param_1);
wostream * __thiscall std::wostream::operator<<(wostream *this,_func_ios_base_ptr_ios_base_ptr *param_1);
void __thiscall std::wostream::_M_write(wostream *this,wchar_t *param_1,long param_2);
wostream * __thiscall std::wostream::flush(wostream *this);
undefined  [16] __thiscall std::wostream::tellp(wostream *this);
long * std::wostream::seekp(fpos param_1);
long std::wostream::seekp(long param_1,_Ios_Seekdir param_2);
void __thiscall std::wostream::wostream(wostream *this);
void __thiscall std::wostream::wostream(wostream *this);
void __thiscall std::wostream::wostream(wostream *this,wiostream *param_1);
void __thiscall std::wostream::wostream(wostream *this,wiostream *param_1);
void __thiscall std::wostream::wostream(wostream *this,wostream *param_1);
void __thiscall std::wostream::wostream(wostream *this,wostream *param_1);
wostream * __thiscall std::wostream::operator=(wostream *this,wostream *param_1);
void __thiscall std::wostream::swap(wostream *this,wostream *param_1);
void __thiscall std::wostream::sentry::sentry(sentry *this,wostream *param_1);
void __thiscall std::wostream::sentry::~sentry(sentry *this);
wostream * __thiscall std::wostream::operator<<(wostream *this,wstreambuf *param_1);
wostream * __thiscall std::wostream::put(wostream *this,wchar_t param_1);
wostream * __thiscall std::wostream::write(wostream *this,wchar_t *param_1,long param_2);
bool __thiscall std::wostream::sentry::operator.cast.to.bool(sentry *this);
wostream * std::endl<>(wostream *param_1);
wostream * std::ends<>(wostream *param_1);
wostream * std::flush<>(wostream *param_1);
wostream * std::operator<<(wostream *param_1,_Setfill param_2);
wostream * std::operator<<(wostream *param_1,_Setiosflags param_2);
wostream * std::operator<<(wostream *param_1,_Resetiosflags param_2);
wostream * std::operator<<(wostream *param_1,_Setbase param_2);
wostream * std::operator<<(wostream *param_1,_Setprecision param_2);
wostream * std::operator<<(wostream *param_1,_Setw param_2);
wostream * std::__ostream_insert<>(wostream *param_1,wchar_t *param_2,long param_3);
wostream * std::operator<<(wostream *param_1,wchar_t param_2);
wostream * std::operator<<(wostream *param_1,wchar_t *param_2);
wostream * std::operator<<(wostream *param_1,char param_2);
wostream * std::operator<<(wostream *param_1,char *param_2);
wostream * __thiscall std::wostream::_M_insert<long>(wostream *this,long param_1);
wostream * __thiscall std::wostream::operator<<(wostream *this,long param_1);
void __thiscall std::wostream::operator<<(wostream *this,short param_1);
void __thiscall std::wostream::operator<<(wostream *this,int param_1);
wostream * __thiscall std::wostream::_M_insert<>(wostream *this,ulong param_1);
wostream * __thiscall std::wostream::operator<<(wostream *this,ulong param_1);
void __thiscall std::wostream::operator<<(wostream *this,ushort param_1);
void __thiscall std::wostream::operator<<(wostream *this,uint param_1);
wostream * __thiscall std::wostream::_M_insert<bool>(wostream *this,bool param_1);
void __thiscall std::wostream::operator<<(wostream *this,bool param_1);
wostream * __thiscall std::wostream::_M_insert<long_long>(wostream *this,longlong param_1);
wostream * __thiscall std::wostream::operator<<(wostream *this,longlong param_1);
wostream * __thiscall std::wostream::_M_insert<>(wostream *this,ulonglong param_1);
wostream * __thiscall std::wostream::operator<<(wostream *this,ulonglong param_1);
wostream * __thiscall std::wostream::_M_insert<double>(wostream *this,double param_1);
wostream * __thiscall std::wostream::operator<<(wostream *this,double param_1);
void __thiscall std::wostream::operator<<(wostream *this,float param_1);
wostream * std::wostream::_M_insert<>(longdouble param_1);
wostream * __thiscall std::wostream::operator<<(wostream *this,longdouble param_1);
wostream * __thiscall std::wostream::_M_insert<>(wostream *this,void *param_1);
wostream * __thiscall std::wostream::operator<<(wostream *this,void *param_1);
void __throw_insufficient_space(char *param_1,char *param_2);
ulong __concat_size_t(char *param_1,ulong param_2,ulong param_3);
int __snprintf_lite(char *param_1,ulong param_2,char *param_3,__va_list_tag *param_4);
void std::streambuf::imbue(locale *param_1);
char * std::streambuf::setbuf(char *param_1,long param_2);
undefined  [16] std::streambuf::seekoff(long param_1,_Ios_Seekdir param_2,_Ios_Openmode param_3);
undefined  [16] std::streambuf::seekpos(fpos param_1,_Ios_Openmode param_2);
undefined8 std::streambuf::sync(void);
undefined8 std::streambuf::showmanyc(void);
undefined8 std::streambuf::underflow(void);
undefined8 std::streambuf::pbackfail(int param_1);
undefined8 std::streambuf::overflow(int param_1);
void std::wstreambuf::imbue(locale *param_1);
wchar_t * std::wstreambuf::setbuf(wchar_t *param_1,long param_2);
undefined  [16] std::wstreambuf::seekoff(long param_1,_Ios_Seekdir param_2,_Ios_Openmode param_3);
undefined  [16] std::wstreambuf::seekpos(fpos param_1,_Ios_Openmode param_2);
undefined8 std::wstreambuf::sync(void);
undefined8 std::wstreambuf::showmanyc(void);
undefined8 std::wstreambuf::underflow(void);
undefined8 std::wstreambuf::pbackfail(uint param_1);
undefined8 std::wstreambuf::overflow(uint param_1);
void __thiscall std::streambuf::~streambuf(streambuf *this);
void __thiscall std::wstreambuf::~wstreambuf(wstreambuf *this);
void __thiscall std::streambuf::~streambuf(streambuf *this);
void __thiscall std::wstreambuf::~wstreambuf(wstreambuf *this);
long __thiscall std::streambuf::xsputn(streambuf *this,char *param_1,long param_2);
long __thiscall std::wstreambuf::xsputn(wstreambuf *this,wchar_t *param_1,long param_2);
ulong __thiscall std::streambuf::uflow(streambuf *this);
undefined4 __thiscall std::wstreambuf::uflow(wstreambuf *this);
long __thiscall std::streambuf::xsgetn(streambuf *this,char *param_1,long param_2);
long __thiscall std::wstreambuf::xsgetn(wstreambuf *this,wchar_t *param_1,long param_2);
locale * std::streambuf::pubimbue(locale *param_1);
void std::streambuf::getloc(void);
char * std::streambuf::pubsetbuf(char *param_1,long param_2);
undefined  [16] std::streambuf::pubseekoff(long param_1,_Ios_Seekdir param_2,_Ios_Openmode param_3);
undefined  [16] std::streambuf::pubseekpos(fpos param_1,_Ios_Openmode param_2);
undefined8 __thiscall std::streambuf::pubsync(streambuf *this);
void __thiscall std::streambuf::in_avail(streambuf *this);
ulong __thiscall std::streambuf::snextc(streambuf *this);
ulong __thiscall std::streambuf::sbumpc(streambuf *this);
ulong __thiscall std::streambuf::sgetc(streambuf *this);
void std::streambuf::sgetn(char *param_1,long param_2);
ulong __thiscall std::streambuf::sputbackc(streambuf *this,char param_1);
ulong __thiscall std::streambuf::sungetc(streambuf *this);
ulong __thiscall std::streambuf::sputc(streambuf *this,char param_1);
void std::streambuf::sputn(char *param_1,long param_2);
void __thiscall std::streambuf::streambuf(streambuf *this);
undefined8 __thiscall std::streambuf::eback(streambuf *this);
undefined8 __thiscall std::streambuf::gptr(streambuf *this);
undefined8 __thiscall std::streambuf::egptr(streambuf *this);
void __thiscall std::streambuf::gbump(streambuf *this,int param_1);
void __thiscall std::streambuf::setg(streambuf *this,char *param_1,char *param_2,char *param_3);
undefined8 __thiscall std::streambuf::pbase(streambuf *this);
undefined8 __thiscall std::streambuf::pptr(streambuf *this);
undefined8 __thiscall std::streambuf::epptr(streambuf *this);
void __thiscall std::streambuf::pbump(streambuf *this,int param_1);
void __thiscall std::streambuf::setp(streambuf *this,char *param_1,char *param_2);
void __thiscall std::streambuf::stossc(streambuf *this);
void __thiscall std::streambuf::__safe_gbump(streambuf *this,long param_1);
void __thiscall std::streambuf::__safe_pbump(streambuf *this,long param_1);
void __thiscall std::streambuf::streambuf(streambuf *this,streambuf *param_1);
streambuf * __thiscall std::streambuf::operator=(streambuf *this,streambuf *param_1);
void __thiscall std::streambuf::swap(streambuf *this,streambuf *param_1);
long std::__copy_streambufs<>(streambuf *param_1,streambuf *param_2);
locale * std::wstreambuf::pubimbue(locale *param_1);
void std::wstreambuf::getloc(void);
wchar_t * std::wstreambuf::pubsetbuf(wchar_t *param_1,long param_2);
undefined  [16] std::wstreambuf::pubseekoff(long param_1,_Ios_Seekdir param_2,_Ios_Openmode param_3);
undefined  [16] std::wstreambuf::pubseekpos(fpos param_1,_Ios_Openmode param_2);
undefined8 __thiscall std::wstreambuf::pubsync(wstreambuf *this);
long __thiscall std::wstreambuf::in_avail(wstreambuf *this);
ulong __thiscall std::wstreambuf::snextc(wstreambuf *this);
ulong __thiscall std::wstreambuf::sbumpc(wstreambuf *this);
ulong __thiscall std::wstreambuf::sgetc(wstreambuf *this);
void std::wstreambuf::sgetn(wchar_t *param_1,long param_2);
ulong __thiscall std::wstreambuf::sputbackc(wstreambuf *this,wchar_t param_1);
ulong __thiscall std::wstreambuf::sungetc(wstreambuf *this);
ulong __thiscall std::wstreambuf::sputc(wstreambuf *this,wchar_t param_1);
void std::wstreambuf::sputn(wchar_t *param_1,long param_2);
void __thiscall std::wstreambuf::wstreambuf(wstreambuf *this);
undefined8 __thiscall std::wstreambuf::eback(wstreambuf *this);
undefined8 __thiscall std::wstreambuf::gptr(wstreambuf *this);
undefined8 __thiscall std::wstreambuf::egptr(wstreambuf *this);
void __thiscall std::wstreambuf::gbump(wstreambuf *this,int param_1);
void __thiscall std::wstreambuf::setg(wstreambuf *this,wchar_t *param_1,wchar_t *param_2,wchar_t *param_3);
undefined8 __thiscall std::wstreambuf::pbase(wstreambuf *this);
undefined8 __thiscall std::wstreambuf::pptr(wstreambuf *this);
undefined8 __thiscall std::wstreambuf::epptr(wstreambuf *this);
void __thiscall std::wstreambuf::pbump(wstreambuf *this,int param_1);
void __thiscall std::wstreambuf::setp(wstreambuf *this,wchar_t *param_1,wchar_t *param_2);
void __thiscall std::wstreambuf::stossc(wstreambuf *this);
void __thiscall std::wstreambuf::__safe_gbump(wstreambuf *this,long param_1);
void __thiscall std::wstreambuf::__safe_pbump(wstreambuf *this,long param_1);
void __thiscall std::wstreambuf::wstreambuf(wstreambuf *this,wstreambuf *param_1);
wstreambuf * __thiscall std::wstreambuf::operator=(wstreambuf *this,wstreambuf *param_1);
void __thiscall std::wstreambuf::swap(wstreambuf *this,wstreambuf *param_1);
long std::__copy_streambufs<>(wstreambuf *param_1,wstreambuf *param_2);
void __thiscall std::string::_M_data(string *this,char *param_1);
void __thiscall std::string::_M_length(string *this,ulong param_1);
undefined8 __thiscall std::string::_M_data(string *this);
string * __thiscall std::string::_M_local_data(string *this);
string * __thiscall std::string::_M_local_data(string *this);
void __thiscall std::string::_M_capacity(string *this,ulong param_1);
void __thiscall std::string::_M_set_length(string *this,ulong param_1);
undefined8 __thiscall std::string::_M_is_local(string *this);
void __thiscall std::string::_M_create(string *this,ulong *param_1,ulong param_2);
void __thiscall std::string::_M_dispose(string *this);
void std::string::_M_destroy(ulong param_1);
void __thiscall std::string::_M_construct(string *this,ulong param_1,char param_2);
void __thiscall std::string::_M_construct_aux_2(string *this,ulong param_1,char param_2);
string * __thiscall std::string::_M_get_allocator(string *this);
string * __thiscall std::string::_M_get_allocator(string *this);
void __thiscall std::string::_M_check(string *this,ulong param_1,char *param_2);
void __thiscall std::string::_M_check_length(string *this,ulong param_1,ulong param_2,char *param_3);
ulong __thiscall std::string::_M_limit(string *this,ulong param_1,ulong param_2);
bool __thiscall std::string::_M_disjunct(string *this,char *param_1);
void std::string::_S_copy(char *param_1,char *param_2,ulong param_3);
void std::string::_S_move(char *param_1,char *param_2,ulong param_3);
void std::string::_S_assign(char *param_1,ulong param_2,char param_3);
void std::string::_S_copy_chars(char *param_1,__normal_iterator param_2,__normal_iterator param_3);
void std::string::_S_copy_chars(char *param_1,__normal_iterator param_2,__normal_iterator param_3);
void std::string::_S_copy_chars(char *param_1,char *param_2,char *param_3);
void std::string::_S_copy_chars(char *param_1,char *param_2,char *param_3);
ulong std::string::_S_compare(ulong param_1,ulong param_2);
void __thiscall std::string::_M_assign(string *this,string *param_1);
void __thiscall std::string::_M_mutate(string *this,ulong param_1,ulong param_2,char *param_3,ulong param_4);
void __thiscall std::string::_M_erase(string *this,ulong param_1,ulong param_2);
void __thiscall std::string::string(string *this);
void __thiscall std::string::string(string *this,allocator *param_1);
void __thiscall std::string::string(string *this,ulong param_1,char param_2,allocator *param_3);
void __thiscall std::string::string(string *this,string *param_1);
void __thiscall std::string::string(string *this,string *param_1,allocator *param_2);
void __thiscall std::string::~string(string *this);
string * __thiscall std::string::operator=(string *this,string *param_1);
string * __thiscall std::string::operator=(string *this,string *param_1);
undefined8 __thiscall std::string::begin(string *this);
undefined8 __thiscall std::string::begin(string *this);
long __thiscall std::string::end(string *this);
long __thiscall std::string::end(string *this);
void std::string::rbegin(void);
void std::string::rbegin(void);
void std::string::rend(void);
void std::string::rend(void);
undefined8 __thiscall std::string::cbegin(string *this);
long __thiscall std::string::cend(string *this);
void std::string::crbegin(void);
void std::string::crend(void);
undefined8 __thiscall std::string::size(string *this);
undefined8 __thiscall std::string::length(string *this);
undefined8 std::string::max_size(void);
undefined8 __thiscall std::string::capacity(string *this);
void __thiscall std::string::reserve(string *this,ulong param_1);
void __thiscall std::string::shrink_to_fit(string *this);
void __thiscall std::string::clear(string *this);
bool __thiscall std::string::empty(string *this);
long __thiscall std::string::operator[](string *this,ulong param_1);
long __thiscall std::string::operator[](string *this,ulong param_1);
long __thiscall std::string::at(string *this,ulong param_1);
long __thiscall std::string::at(string *this,ulong param_1);
undefined8 __thiscall std::string::front(string *this);
undefined8 __thiscall std::string::front(string *this);
long __thiscall std::string::back(string *this);
long __thiscall std::string::back(string *this);
string * __thiscall std::string::operator+=(string *this,char param_1);
void __thiscall std::string::push_back(string *this,char param_1);
string * __thiscall std::string::assign(string *this,string *param_1);
string * __thiscall std::string::assign(string *this,string *param_1);
string * __thiscall std::string::erase(string *this,ulong param_1,ulong param_2);
long __thiscall std::string::erase(string *this,__normal_iterator param_1);
long __thiscall std::string::erase(string *this,__normal_iterator param_1,__normal_iterator param_2);
void __thiscall std::string::pop_back(string *this);
string * __thiscall std::string::_M_replace_aux(string *this,ulong param_1,ulong param_2,ulong param_3,char param_4);
void __thiscall std::string::append(string *this,ulong param_1,char param_2);
void __thiscall std::string::resize(string *this,ulong param_1,char param_2);
void __thiscall std::string::resize(string *this,ulong param_1);
void __thiscall std::string::assign(string *this,ulong param_1,char param_2);
string * __thiscall std::string::operator=(string *this,char param_1);
void __thiscall std::string::insert(string *this,ulong param_1,ulong param_2,char param_3);
long __thiscall std::string::insert(string *this,__normal_iterator param_1,char param_2);
void __thiscall std::string::replace(string *this,ulong param_1,ulong param_2,ulong param_3,char param_4);
void __thiscall std::string::replace(string *this,__normal_iterator param_1,__normal_iterator param_2,ulong param_3,char param_4);
long __thiscall std::string::insert(string *this,__normal_iterator param_1,ulong param_2,char param_3);
string * __thiscall std::string::_M_replace(string *this,ulong param_1,ulong param_2,char *param_3,ulong param_4);
void __thiscall std::string::assign(string *this,string *param_1,ulong param_2,ulong param_3);
void __thiscall std::string::assign(string *this,char *param_1,ulong param_2);
string * __thiscall std::string::operator=(string *this,initializer_list param_1);
void std::string::assign(initializer_list param_1);
void __thiscall std::string::assign(string *this,char *param_1);
void __thiscall std::string::replace(string *this,ulong param_1,ulong param_2,char *param_3,ulong param_4);
void __thiscall std::string::operator=(string *this,char *param_1);
void __thiscall std::string::insert(string *this,ulong param_1,char *param_2,ulong param_3);
void __thiscall std::string::replace(string *this,ulong param_1,ulong param_2,string *param_3);
void __thiscall std::string::insert(string *this,ulong param_1,string *param_2);
void __thiscall std::string::replace(string *this,ulong param_1,ulong param_2,char *param_3);
void __thiscall std::string::insert(string *this,ulong param_1,char *param_2);
void __thiscall std::string::replace(string *this,__normal_iterator param_1,__normal_iterator param_2,char *param_3,ulong param_4);
void __thiscall std::string::replace(string *this,__normal_iterator param_1,__normal_iterator param_2,char *param_3,char *param_4);
void __thiscall std::string::replace(string *this,__normal_iterator param_1,__normal_iterator param_2,char *param_3,char *param_4);
void __thiscall std::string::replace(string *this,__normal_iterator param_1,__normal_iterator param_2,string *param_3);
void std::string::replace(__normal_iterator param_1,__normal_iterator param_2,initializer_list param_3);
void __thiscall std::string::replace(string *this,__normal_iterator param_1,__normal_iterator param_2,__normal_iterator param_3,__normal_iterator param_4);
void __thiscall std::string::replace(string *this,__normal_iterator param_1,__normal_iterator param_2,__normal_iterator param_3,__normal_iterator param_4);
void __thiscall std::string::replace(string *this,__normal_iterator param_1,__normal_iterator param_2,char *param_3);
void std::string::insert(__normal_iterator param_1,initializer_list param_2);
void __thiscall std::string::replace(string *this,ulong param_1,ulong param_2,string *param_3,ulong param_4,ulong param_5);
void __thiscall std::string::insert(string *this,ulong param_1,string *param_2,ulong param_3,ulong param_4);
long std::string::insert(__normal_iterator param_1,initializer_list param_2);
string * __thiscall std::string::_M_append(string *this,char *param_1,ulong param_2);
void __thiscall std::string::append(string *this,string *param_1);
void __thiscall std::string::operator+=(string *this,string *param_1);
void std::string::append(string *param_1,ulong param_2,ulong param_3);
void __thiscall std::string::append(string *this,char *param_1,ulong param_2);
void __thiscall std::string::append(string *this,char *param_1);
void __thiscall std::string::operator+=(string *this,char *param_1);
void __thiscall std::string::operator+=(string *this,initializer_list param_1);
void std::string::append(initializer_list param_1);
size_t __thiscall std::string::copy(string *this,char *param_1,ulong param_2,ulong param_3);
void __thiscall std::string::swap(string *this,string *param_1);
undefined8 __thiscall std::string::c_str(string *this);
undefined8 __thiscall std::string::data(string *this);
string * __thiscall std::string::get_allocator(string *this);
ulong __thiscall std::string::find(string *this,char *param_1,ulong param_2,ulong param_3);
void __thiscall std::string::find(string *this,string *param_1,ulong param_2);
void __thiscall std::string::find(string *this,char *param_1,ulong param_2);
long __thiscall std::string::find(string *this,char param_1,ulong param_2);
ulong __thiscall std::string::rfind(string *this,char *param_1,ulong param_2,ulong param_3);
void __thiscall std::string::rfind(string *this,string *param_1,ulong param_2);
void __thiscall std::string::rfind(string *this,char *param_1,ulong param_2);
ulong __thiscall std::string::rfind(string *this,char param_1,ulong param_2);
ulong __thiscall std::string::find_first_of(string *this,char *param_1,ulong param_2,ulong param_3);
void __thiscall std::string::find_first_of(string *this,string *param_1,ulong param_2);
void __thiscall std::string::find_first_of(string *this,char *param_1,ulong param_2);
void __thiscall std::string::find_first_of(string *this,char param_1,ulong param_2);
ulong __thiscall std::string::find_last_of(string *this,char *param_1,ulong param_2,ulong param_3);
void __thiscall std::string::find_last_of(string *this,string *param_1,ulong param_2);
void __thiscall std::string::find_last_of(string *this,char *param_1,ulong param_2);
void __thiscall std::string::find_last_of(string *this,char param_1,ulong param_2);
ulong __thiscall std::string::find_first_not_of(string *this,char *param_1,ulong param_2,ulong param_3);
void __thiscall std::string::find_first_not_of(string *this,string *param_1,ulong param_2);
void __thiscall std::string::find_first_not_of(string *this,char *param_1,ulong param_2);
ulong __thiscall std::string::find_first_not_of(string *this,char param_1,ulong param_2);
ulong __thiscall std::string::find_last_not_of(string *this,char *param_1,ulong param_2,ulong param_3);
void __thiscall std::string::find_last_not_of(string *this,string *param_1,ulong param_2);
void __thiscall std::string::find_last_not_of(string *this,char *param_1,ulong param_2);
ulong __thiscall std::string::find_last_not_of(string *this,char param_1,ulong param_2);
ulong __thiscall std::string::compare(string *this,string *param_1);
ulong __thiscall std::string::compare(string *this,ulong param_1,ulong param_2,string *param_3);
ulong __thiscall std::string::compare(string *this,ulong param_1,ulong param_2,string *param_3,ulong param_4,ulong param_5);
ulong __thiscall std::string::compare(string *this,char *param_1);
ulong __thiscall std::string::compare(string *this,ulong param_1,ulong param_2,char *param_3);
ulong __thiscall std::string::compare(string *this,ulong param_1,ulong param_2,char *param_3,ulong param_4);
void __thiscall std::string::_Alloc_hider::_Alloc_hider(_Alloc_hider *this,char *param_1,allocator *param_2);
void __thiscall std::string::_Alloc_hider::_Alloc_hider(_Alloc_hider *this,char *param_1,allocator *param_2);
string * std::operator+(string *param_1,char *param_2,undefined8 *param_3);
string * std::operator+(string *param_1,char param_2,undefined8 *param_3);
void std::string::_M_construct<>(__normal_iterator param_1,__normal_iterator param_2,forward_iterator_tag param_3);
void __thiscall std::string::string<>(string *this,__normal_iterator param_1,__normal_iterator param_2,allocator *param_3);
void std::string::_M_construct<>(__normal_iterator param_1,__normal_iterator param_2,forward_iterator_tag param_3);
void __thiscall std::string::string(string *this,string *param_1,allocator *param_2);
void std::string::_M_construct<char*>(char *param_1,char *param_2,forward_iterator_tag param_3);
void __thiscall std::string::string(string *this,string *param_1);
string * std::operator+(string *param_1,undefined8 *param_2,undefined8 *param_3);
void __thiscall std::string::string<char*,void>(string *this,char *param_1,char *param_2,allocator *param_3);
void std::string::_M_construct<>(char *param_1,char *param_2,forward_iterator_tag param_3);
void __thiscall std::string::string(string *this,string *param_1,ulong param_2,allocator *param_3);
void __thiscall std::string::string(string *this,string *param_1,ulong param_2,ulong param_3);
void __thiscall std::string::string(string *this,string *param_1,ulong param_2,ulong param_3,allocator *param_4);
void __thiscall std::string::string(string *this,char *param_1,ulong param_2,allocator *param_3);
void __thiscall std::string::string(string *this,char *param_1,allocator *param_2);
void __thiscall std::string::string(string *this,initializer_list param_1,allocator *param_2);
void __thiscall std::string::string<>(string *this,char *param_1,char *param_2,allocator *param_3);
ulong std::string::substr(ulong param_1,ulong param_2);
bool operator==(__normal_iterator *param_1,__normal_iterator *param_2);
bool operator==(__normal_iterator *param_1,__normal_iterator *param_2);
char * (anonymous_namespace)::generic_error_category::name(void);
char * (anonymous_namespace)::system_error_category::name(void);
undefined  [16] __thiscall std::_V2::error_category::default_error_condition(error_category *this,int param_1);
bool __thiscall std::_V2::error_category::equivalent(error_category *this,int param_1,error_condition *param_2);
bool __thiscall std::_V2::error_category::equivalent(error_category *this,error_code *param_1,int param_2);
void __thiscall std::system_error::~system_error(system_error *this);
void __thiscall std::system_error::~system_error(system_error *this);
error_category * __thiscall std::_V2::error_category::_M_message[abi:cxx11](error_category *this,int param_1);
long * (anonymous_namespace)::system_error_category::message[abi:cxx11](int param_1);
void __thiscall std::_V2::error_category::~error_category(error_category *this);
void __thiscall(anonymous_namespace)::system_error_category::~system_error_category(system_error_category *this);
void __thiscall(anonymous_namespace)::system_error_category::~system_error_category(system_error_category *this);
void __thiscall(anonymous_namespace)::generic_error_category::~generic_error_category(generic_error_category *this);
void __thiscall(anonymous_namespace)::generic_error_category::~generic_error_category(generic_error_category *this);
void __thiscall std::_V2::error_category::~error_category(error_category *this);
undefined8 * std::_V2::system_category(void);
undefined8 * std::_V2::generic_category(void);
undefined  [16] __thiscall(anonymous_namespace)::system_error_category::default_error_condition(system_error_category *this,int param_1);
void __thiscall std::error_code::default_error_condition(error_code *this);
undefined4 __thiscall std::moneypunct<>::do_decimal_point(moneypunct<> *this);
undefined4 __thiscall std::moneypunct<>::do_thousands_sep(moneypunct<> *this);
undefined4 __thiscall std::moneypunct<>::do_frac_digits(moneypunct<> *this);
undefined4 __thiscall std::moneypunct<>::do_pos_format(moneypunct<> *this);
undefined4 __thiscall std::moneypunct<>::do_neg_format(moneypunct<> *this);
undefined4 __thiscall std::moneypunct<>::do_decimal_point(moneypunct<> *this);
undefined4 __thiscall std::moneypunct<>::do_thousands_sep(moneypunct<> *this);
undefined4 __thiscall std::moneypunct<>::do_frac_digits(moneypunct<> *this);
undefined4 __thiscall std::moneypunct<>::do_pos_format(moneypunct<> *this);
undefined4 __thiscall std::moneypunct<>::do_neg_format(moneypunct<> *this);
void __thiscall std::moneypunct_byname<>::~moneypunct_byname(moneypunct_byname<> *this);
void __thiscall std::moneypunct_byname<>::~moneypunct_byname(moneypunct_byname<> *this);
undefined4 __thiscall std::numpunct<wchar_t>::do_decimal_point(numpunct<wchar_t> *this);
undefined4 __thiscall std::numpunct<wchar_t>::do_thousands_sep(numpunct<wchar_t> *this);
void __thiscall std::numpunct_byname<wchar_t>::~numpunct_byname(numpunct_byname<wchar_t> *this);
undefined8 std::time_get<>::do_date_order(void);
ulong __thiscall std::collate<wchar_t>::do_hash(collate<wchar_t> *this,wchar_t *param_1,wchar_t *param_2);
void __thiscall std::money_get<>::~money_get(money_get<> *this);
void __thiscall std::money_put<>::~money_put(money_put<> *this);
void __thiscall std::num_get<>::~num_get(num_get<> *this);
void __thiscall std::num_put<>::~num_put(num_put<> *this);
void __thiscall std::__timepunct_cache<wchar_t>::~__timepunct_cache(__timepunct_cache<wchar_t> *this);
void __thiscall std::time_put<>::~time_put(time_put<> *this);
void __thiscall std::time_put_byname<>::~time_put_byname(time_put_byname<> *this);
void __thiscall std::time_get<>::~time_get(time_get<> *this);
void __thiscall std::time_get_byname<>::~time_get_byname(time_get_byname<> *this);
void __thiscall std::moneypunct_byname<>::~moneypunct_byname(moneypunct_byname<> *this);
void __thiscall std::moneypunct_byname<>::~moneypunct_byname(moneypunct_byname<> *this);
void __thiscall std::money_get<>::~money_get(money_get<> *this);
void __thiscall std::money_put<>::~money_put(money_put<> *this);
void __thiscall std::numpunct_byname<wchar_t>::~numpunct_byname(numpunct_byname<wchar_t> *this);
void __thiscall std::num_get<>::~num_get(num_get<> *this);
void __thiscall std::num_put<>::~num_put(num_put<> *this);
void __thiscall std::__timepunct_cache<wchar_t>::~__timepunct_cache(__timepunct_cache<wchar_t> *this);
void __thiscall std::time_put<>::~time_put(time_put<> *this);
void __thiscall std::time_put_byname<>::~time_put_byname(time_put_byname<> *this);
void __thiscall std::time_get<>::~time_get(time_get<> *this);
void __thiscall std::time_get_byname<>::~time_get_byname(time_get_byname<> *this);
void std::moneypunct<>::do_grouping(void);
void std::moneypunct<>::do_grouping(void);
void std::numpunct<wchar_t>::do_grouping(void);
void std::moneypunct<>::do_curr_symbol(void);
void std::moneypunct<>::do_positive_sign(void);
void std::moneypunct<>::do_negative_sign(void);
void std::moneypunct<>::do_curr_symbol(void);
void std::moneypunct<>::do_positive_sign(void);
void std::moneypunct<>::do_negative_sign(void);
void std::numpunct<wchar_t>::do_truename(void);
void std::numpunct<wchar_t>::do_falsename(void);
void __thiscall std::collate<wchar_t>::~collate(collate<wchar_t> *this);
void __thiscall std::collate<wchar_t>::~collate(collate<wchar_t> *this);
void __thiscall std::collate_byname<wchar_t>::~collate_byname(collate_byname<wchar_t> *this);
void __thiscall std::collate_byname<wchar_t>::~collate_byname(collate_byname<wchar_t> *this);
void __thiscall std::__timepunct<wchar_t>::~__timepunct(__timepunct<wchar_t> *this);
void __thiscall std::__timepunct<wchar_t>::~__timepunct(__timepunct<wchar_t> *this);
void __thiscall std::messages<wchar_t>::~messages(messages<wchar_t> *this);
void __thiscall std::messages<wchar_t>::~messages(messages<wchar_t> *this);
void __thiscall std::messages_byname<wchar_t>::~messages_byname(messages_byname<wchar_t> *this);
void __thiscall std::messages_byname<wchar_t>::~messages_byname(messages_byname<wchar_t> *this);
void __thiscall std::codecvt_byname<>::~codecvt_byname(codecvt_byname<> *this);
void __thiscall std::codecvt_byname<>::~codecvt_byname(codecvt_byname<> *this);
void __thiscall std::wstreambuf::sbumpc(wstreambuf *this);
ulong std::istreambuf_iterator<>::_M_get(void);
void std::string::_Rep::_M_dispose(allocator *param_1);
void std::wstring::_Rep::_M_dispose(allocator *param_1);
int __thiscall std::collate<wchar_t>::do_compare(collate<wchar_t> *this,wchar_t *param_1,wchar_t *param_2,wchar_t *param_3,wchar_t *param_4);
wchar_t * std::collate<wchar_t>::do_transform(wchar_t *param_1,wchar_t *param_2);
void __thiscall std::__moneypunct_cache<>::__moneypunct_cache(__moneypunct_cache<> *this,ulong param_1);
void __thiscall std::__moneypunct_cache<>::__moneypunct_cache(__moneypunct_cache<> *this,ulong param_1);
void __thiscall std::moneypunct<>::moneypunct(moneypunct<> *this,ulong param_1);
void __thiscall std::moneypunct<>::moneypunct(moneypunct<> *this,__moneypunct_cache *param_1,ulong param_2);
void __thiscall std::moneypunct<>::moneypunct(moneypunct<> *this,__locale_struct *param_1,char *param_2,ulong param_3);
ulong __thiscall std::moneypunct<>::decimal_point(moneypunct<> *this);
ulong __thiscall std::moneypunct<>::thousands_sep(moneypunct<> *this);
void std::moneypunct<>::grouping(void);
void std::moneypunct<>::curr_symbol(void);
void std::moneypunct<>::positive_sign(void);
void std::moneypunct<>::negative_sign(void);
ulong __thiscall std::moneypunct<>::frac_digits(moneypunct<> *this);
ulong __thiscall std::moneypunct<>::pos_format(moneypunct<> *this);
ulong __thiscall std::moneypunct<>::neg_format(moneypunct<> *this);
void __thiscall std::moneypunct<>::moneypunct(moneypunct<> *this,ulong param_1);
void __thiscall std::moneypunct<>::moneypunct(moneypunct<> *this,__moneypunct_cache *param_1,ulong param_2);
void __thiscall std::moneypunct<>::moneypunct(moneypunct<> *this,__locale_struct *param_1,char *param_2,ulong param_3);
ulong __thiscall std::moneypunct<>::decimal_point(moneypunct<> *this);
ulong __thiscall std::moneypunct<>::thousands_sep(moneypunct<> *this);
void std::moneypunct<>::grouping(void);
void std::moneypunct<>::curr_symbol(void);
void std::moneypunct<>::positive_sign(void);
void std::moneypunct<>::negative_sign(void);
ulong __thiscall std::moneypunct<>::frac_digits(moneypunct<> *this);
ulong __thiscall std::moneypunct<>::pos_format(moneypunct<> *this);
ulong __thiscall std::moneypunct<>::neg_format(moneypunct<> *this);
void __thiscall std::moneypunct_byname<>::moneypunct_byname(moneypunct_byname<> *this,char *param_1,ulong param_2);
void __thiscall std::moneypunct_byname<>::moneypunct_byname(moneypunct_byname<> *this,string *param_1,ulong param_2);
void __thiscall std::moneypunct_byname<>::moneypunct_byname(moneypunct_byname<> *this,char *param_1,ulong param_2);
void __thiscall std::moneypunct_byname<>::moneypunct_byname(moneypunct_byname<> *this,string *param_1,ulong param_2);
void __thiscall std::money_get<>::money_get(money_get<> *this,ulong param_1);
void std::money_get<>::get(istreambuf_iterator param_1,istreambuf_iterator param_2,bool param_3,ios_base *param_4,_Ios_Iostate *param_5,longdouble *param_6);
void std::money_get<>::get(istreambuf_iterator param_1,istreambuf_iterator param_2,bool param_3,ios_base *param_4,_Ios_Iostate *param_5,wstring *param_6);
void __thiscall std::money_put<>::money_put(money_put<> *this,ulong param_1);
void std::money_put<>::put(ostreambuf_iterator param_1,bool param_2,ios_base *param_3,wchar_t param_4,longdouble param_5);
void std::money_put<>::put(ostreambuf_iterator param_1,bool param_2,ios_base *param_3,wchar_t param_4,wstring *param_5);
void __thiscall std::__numpunct_cache<wchar_t>::__numpunct_cache(__numpunct_cache<wchar_t> *this,ulong param_1);
void __thiscall std::numpunct<wchar_t>::numpunct(numpunct<wchar_t> *this,ulong param_1);
void __thiscall std::numpunct<wchar_t>::numpunct(numpunct<wchar_t> *this,__numpunct_cache *param_1,ulong param_2);
void __thiscall std::numpunct<wchar_t>::numpunct(numpunct<wchar_t> *this,__locale_struct *param_1,ulong param_2);
ulong __thiscall std::numpunct<wchar_t>::decimal_point(numpunct<wchar_t> *this);
ulong __thiscall std::numpunct<wchar_t>::thousands_sep(numpunct<wchar_t> *this);
void std::numpunct<wchar_t>::grouping(void);
void std::numpunct<wchar_t>::truename(void);
void std::numpunct<wchar_t>::falsename(void);
void __thiscall std::numpunct_byname<wchar_t>::numpunct_byname(numpunct_byname<wchar_t> *this,char *param_1,ulong param_2);
void __thiscall std::numpunct_byname<wchar_t>::numpunct_byname(numpunct_byname<wchar_t> *this,string *param_1,ulong param_2);
void __thiscall std::num_get<>::num_get(num_get<> *this,ulong param_1);
void std::num_get<>::get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,bool *param_5);
void std::num_get<>::get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,float *param_5);
void std::num_get<>::get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,double *param_5);
void std::num_get<>::get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,longdouble *param_5);
void std::num_get<>::get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,void **param_5);
void __thiscall std::num_put<>::num_put(num_put<> *this,ulong param_1);
void std::num_put<>::put(ostreambuf_iterator param_1,ios_base *param_2,wchar_t param_3,bool param_4);
void std::num_put<>::put(ostreambuf_iterator param_1,ios_base *param_2,wchar_t param_3,double param_4);
void std::num_put<>::put(ostreambuf_iterator param_1,ios_base *param_2,wchar_t param_3,longdouble param_4);
void std::num_put<>::put(ostreambuf_iterator param_1,ios_base *param_2,wchar_t param_3,void *param_4);
void __thiscall std::__timepunct<wchar_t>::__timepunct(__timepunct<wchar_t> *this,ulong param_1);
void __thiscall std::__timepunct<wchar_t>::__timepunct(__timepunct<wchar_t> *this,__timepunct_cache *param_1,ulong param_2);
void __thiscall std::__timepunct<wchar_t>::__timepunct(__timepunct<wchar_t> *this,__locale_struct *param_1,char *param_2,ulong param_3);
void __thiscall std::__timepunct<wchar_t>::_M_date_formats(__timepunct<wchar_t> *this,wchar_t **param_1);
void __thiscall std::__timepunct<wchar_t>::_M_time_formats(__timepunct<wchar_t> *this,wchar_t **param_1);
void __thiscall std::__timepunct<wchar_t>::_M_date_time_formats(__timepunct<wchar_t> *this,wchar_t **param_1);
void std::__timepunct<wchar_t>::_M_am_pm_format(wchar_t *param_1);
void __thiscall std::__timepunct<wchar_t>::_M_am_pm(__timepunct<wchar_t> *this,wchar_t **param_1);
void __thiscall std::__timepunct<wchar_t>::_M_days(__timepunct<wchar_t> *this,wchar_t **param_1);
void __thiscall std::__timepunct<wchar_t>::_M_days_abbreviated(__timepunct<wchar_t> *this,wchar_t **param_1);
void __thiscall std::__timepunct<wchar_t>::_M_months(__timepunct<wchar_t> *this,wchar_t **param_1);
void __thiscall std::__timepunct<wchar_t>::_M_months_abbreviated(__timepunct<wchar_t> *this,wchar_t **param_1);
void __thiscall std::__timepunct_cache<wchar_t>::__timepunct_cache(__timepunct_cache<wchar_t> *this,ulong param_1);
void __thiscall std::time_put<>::time_put(time_put<> *this,ulong param_1);
void std::time_put<>::put(ostreambuf_iterator param_1,ios_base *param_2,wchar_t param_3,tm *param_4,char param_5,char param_6,undefined4 param_7,undefined4 param_8);
void __thiscall std::time_put_byname<>::time_put_byname(time_put_byname<> *this,char *param_1,ulong param_2);
void __thiscall std::time_put_byname<>::time_put_byname(time_put_byname<> *this,string *param_1,ulong param_2);
void __thiscall std::time_get<>::time_get(time_get<> *this,ulong param_1);
void __thiscall std::time_get<>::date_order(time_get<> *this);
void std::time_get<>::get_time(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5);
void std::time_get<>::get_date(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5);
void std::time_get<>::get_weekday(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5);
void std::time_get<>::get_monthname(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5);
void std::time_get<>::get_year(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5);
void __thiscall std::time_get_byname<>::time_get_byname(time_get_byname<> *this,char *param_1,ulong param_2);
void __thiscall std::time_get_byname<>::time_get_byname(time_get_byname<> *this,string *param_1,ulong param_2);
void __thiscall std::messages<wchar_t>::messages(messages<wchar_t> *this,ulong param_1);
void __thiscall std::messages<wchar_t>::messages(messages<wchar_t> *this,__locale_struct *param_1,char *param_2,ulong param_3);
void std::messages<wchar_t>::open(string *param_1,locale *param_2);
void __thiscall std::messages<wchar_t>::open(messages<wchar_t> *this,string *param_1,locale *param_2,char *param_3);
undefined8 std::messages<wchar_t>::get(int param_1,int param_2,int param_3,wstring *param_4);
void std::messages<wchar_t>::close(int param_1);
undefined8 __thiscall std::messages<wchar_t>::_M_convert_to_char(messages<wchar_t> *this,wstring *param_1);
char * std::messages<wchar_t>::_M_convert_from_char(char *param_1);
void __thiscall std::messages_byname<wchar_t>::messages_byname(messages_byname<wchar_t> *this,char *param_1,ulong param_2);
void __thiscall std::messages_byname<wchar_t>::messages_byname(messages_byname<wchar_t> *this,string *param_1,ulong param_2);
void __thiscall std::ctype_byname<wchar_t>::ctype_byname(ctype_byname<wchar_t> *this,string *param_1,ulong param_2);
void __thiscall std::codecvt_byname<>::codecvt_byname(codecvt_byname<> *this,char *param_1,ulong param_2);
void __thiscall std::codecvt_byname<>::codecvt_byname(codecvt_byname<> *this,string *param_1,ulong param_2);
void __thiscall std::collate<wchar_t>::collate(collate<wchar_t> *this,ulong param_1);
void __thiscall std::collate<wchar_t>::collate(collate<wchar_t> *this,__locale_struct *param_1,ulong param_2);
void std::collate<wchar_t>::compare(wchar_t *param_1,wchar_t *param_2,wchar_t *param_3,wchar_t *param_4);
wchar_t * std::collate<wchar_t>::transform(wchar_t *param_1,wchar_t *param_2);
void std::collate<wchar_t>::hash(wchar_t *param_1,wchar_t *param_2);
void __thiscall std::collate_byname<wchar_t>::collate_byname(collate_byname<wchar_t> *this,char *param_1,ulong param_2);
void __thiscall std::collate_byname<wchar_t>::collate_byname(collate_byname<wchar_t> *this,string *param_1,ulong param_2);
ctype * std::use_facet<>(locale *param_1);
undefined  [16]std::time_put<>::put(ostreambuf_iterator param_1,ios_base *param_2,wchar_t param_3,tm *param_4,wchar_t *param_5,wchar_t *param_6,int *param_7,int *param_8);
undefined  [16]std::time_get<>::_M_extract_num(istreambuf_iterator param_1,istreambuf_iterator param_2,int *param_3,int param_4,int param_5,ulong param_6,ios_base *param_7,_Ios_Iostate *param_8);
undefined  [16]std::time_get<>::do_get_year(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,undefined param_6,uint *param_7,long param_8);
undefined  [16]std::time_get<>::_M_extract_name(istreambuf_iterator param_1,istreambuf_iterator param_2,int *param_3,wchar_t **param_4,ulong param_5,ios_base *param_6,_Ios_Iostate *param_7);
undefined  [16]std::time_get<>::_M_extract_wday_or_month(istreambuf_iterator param_1,istreambuf_iterator param_2,int *param_3,wchar_t **param_4,ulong param_5,ios_base *param_6,_Ios_Iostate *param_7);
codecvt * std::use_facet<>(locale *param_1);
collate * std::use_facet<>(locale *param_1);
numpunct * std::use_facet<>(locale *param_1);
void __thiscall std::__numpunct_cache<wchar_t>::_M_cache(__numpunct_cache<wchar_t> *this,locale *param_1);
num_put * std::use_facet<>(locale *param_1);
num_get * std::use_facet<>(locale *param_1);
moneypunct * std::use_facet<>(locale *param_1);
void __thiscall std::__moneypunct_cache<>::_M_cache(__moneypunct_cache<> *this,locale *param_1);
moneypunct * std::use_facet<>(locale *param_1);
void __thiscall std::__moneypunct_cache<>::_M_cache(__moneypunct_cache<> *this,locale *param_1);
money_put * std::use_facet<>(locale *param_1);
money_get * std::use_facet<>(locale *param_1);
__timepunct * std::use_facet<>(locale *param_1);
undefined  [16]std::time_put<>::do_put(ostreambuf_iterator param_1,ios_base *param_2,wchar_t param_3,tm *param_4,char param_5,char param_6,undefined4 param_7,undefined4 param_8);
undefined  [16]std::time_get<>::do_get_weekday(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,undefined param_6,uint *param_7,long param_8);
undefined  [16]std::time_get<>::do_get_monthname(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,undefined param_6,uint *param_7,long param_8);
time_put * std::use_facet<>(locale *param_1);
time_get * std::use_facet<>(locale *param_1);
messages * std::use_facet<>(locale *param_1);
bool std::has_facet<>(locale *param_1);
bool std::has_facet<>(locale *param_1);
bool std::has_facet<>(locale *param_1);
bool std::has_facet<>(locale *param_1);
bool std::has_facet<>(locale *param_1);
bool std::has_facet<>(locale *param_1);
bool std::has_facet<>(locale *param_1);
bool std::has_facet<>(locale *param_1);
bool std::has_facet<>(locale *param_1);
bool std::has_facet<>(locale *param_1);
bool std::has_facet<>(locale *param_1);
bool std::has_facet<>(locale *param_1);
bool std::has_facet<>(locale *param_1);
wchar_t * std::__add_grouping<wchar_t>(wchar_t *param_1,wchar_t param_2,char *param_3,ulong param_4,wchar_t *param_5,wchar_t *param_6);
void __thiscall std::num_put<>::_M_group_float(num_put<> *this,char *param_1,ulong param_2,wchar_t param_3,wchar_t *param_4,wchar_t *param_5,wchar_t *param_6,int *param_7);
void __thiscall std::num_put<>::_M_group_int(num_put<> *this,char *param_1,ulong param_2,wchar_t param_3,ios_base *param_4,wchar_t *param_5,wchar_t *param_6,int *param_7);
ostreambuf_iterator std::money_put<>::_M_insert<true>(ostreambuf_iterator param_1,ios_base *param_2,wchar_t param_3,wstring *param_4);
ostreambuf_iterator std::money_put<>::_M_insert<false>(ostreambuf_iterator param_1,ios_base *param_2,wchar_t param_3,wstring *param_4);
undefined  [16]std::money_put<>::do_put(ostreambuf_iterator param_1,bool param_2,ios_base *param_3,wchar_t param_4,longdouble param_5);
void std::money_put<>::do_put(ostreambuf_iterator param_1,bool param_2,ios_base *param_3,wchar_t param_4,wstring *param_5,undefined param_6,undefined8 param_7);
void std::__pad<>::_S_pad(ios_base *param_1,wchar_t param_2,wchar_t *param_3,wchar_t *param_4,long param_5,long param_6);
void __thiscall std::num_put<>::_M_pad(num_put<> *this,wchar_t param_1,long param_2,ios_base *param_3,wchar_t *param_4,wchar_t *param_5,int *param_6);
ostreambuf_iterator std::num_put<>::_M_insert_float<double>(ostreambuf_iterator param_1,ios_base *param_2,wchar_t param_3,char param_4,double param_5);
void __thiscall std::num_put<>::do_put(num_put<> *this,ostreambuf_iterator param_1,ios_base *param_2,wchar_t param_3,double param_4);
ostreambuf_iterator std::num_put<>::_M_insert_float<>(ostreambuf_iterator param_1,ios_base *param_2,wchar_t param_3,char param_4,longdouble param_5);
void std::num_put<>::do_put(ostreambuf_iterator param_1,ios_base *param_2,wchar_t param_3,longdouble param_4);
int std::__int_to_char<>(wchar_t *param_1,ulong param_2,wchar_t *param_3,_Ios_Fmtflags param_4,bool param_5);
ostreambuf_iterator std::num_put<>::_M_insert_int<long>(ostreambuf_iterator param_1,ios_base *param_2,wchar_t param_3,long param_4);
undefined  [16]std::num_put<>::do_put(ostreambuf_iterator param_1,ios_base *param_2,wchar_t param_3,long param_4);
void std::num_put<>::put(ostreambuf_iterator param_1,ios_base *param_2,wchar_t param_3,long param_4);
ostreambuf_iterator std::num_put<>::_M_insert_int<>(ostreambuf_iterator param_1,ios_base *param_2,wchar_t param_3,ulong param_4);
undefined  [16]std::num_put<>::do_put(ostreambuf_iterator param_1,ios_base *param_2,wchar_t param_3,ulong param_4);
void std::num_put<>::do_put(ostreambuf_iterator param_1,ios_base *param_2,wchar_t param_3,void *param_4);
void std::num_put<>::put(ostreambuf_iterator param_1,ios_base *param_2,wchar_t param_3,ulong param_4);
int std::__int_to_char<>(wchar_t *param_1,ulonglong param_2,wchar_t *param_3,_Ios_Fmtflags param_4,bool param_5);
ostreambuf_iterator std::num_put<>::_M_insert_int<long_long>(ostreambuf_iterator param_1,ios_base *param_2,wchar_t param_3,longlong param_4);
undefined  [16]std::num_put<>::do_put(ostreambuf_iterator param_1,ios_base *param_2,wchar_t param_3,longlong param_4);
void std::num_put<>::put(ostreambuf_iterator param_1,ios_base *param_2,wchar_t param_3,longlong param_4);
ostreambuf_iterator std::num_put<>::_M_insert_int<>(ostreambuf_iterator param_1,ios_base *param_2,wchar_t param_3,ulonglong param_4);
undefined  [16]std::num_put<>::do_put(ostreambuf_iterator param_1,ios_base *param_2,wchar_t param_3,ulonglong param_4);
void std::num_put<>::put(ostreambuf_iterator param_1,ios_base *param_2,wchar_t param_3,ulonglong param_4);
long __thiscall std::__use_cache<>::operator()(__use_cache<> *this,locale *param_1);
undefined  [16]std::num_put<>::do_put(ostreambuf_iterator param_1,ios_base *param_2,wchar_t param_3,bool param_4);
bool __thiscall std::istreambuf_iterator<>::equal(istreambuf_iterator<> *this,istreambuf_iterator *param_1);
undefined  [16]std::time_get<>::_M_extract_via_format(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,wchar_t *param_6,uint *param_7,int *param_8,wchar_t *param_9);
undefined  [16]std::time_get<>::do_get_time(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,undefined param_6,uint *param_7,undefined8 param_8);
undefined  [16]std::time_get<>::do_get_date(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,undefined param_6,uint *param_7,undefined8 param_8);
undefined  [16]std::time_get<>::do_get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,char param_6,char param_7);
undefined  [16]std::time_get<>::get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,char param_6,char param_7);
undefined  [16]std::time_get<>::get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,tm *param_5,wchar_t *param_6,wchar_t *param_7);
undefined  [16]std::num_get<>::_M_extract_float(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,string *param_5,undefined param_6,undefined4 *param_7,string *param_8);
undefined  [16]std::num_get<>::do_get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,float *param_5,undefined param_6,_Ios_Iostate *param_7,float *param_8);
undefined  [16]std::num_get<>::do_get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,double *param_5,undefined param_6,_Ios_Iostate *param_7,double *param_8);
undefined  [16]std::num_get<>::do_get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,longdouble *param_5,undefined param_6,_Ios_Iostate *param_7,longdouble *param_8);
istreambuf_iterator std::num_get<>::_M_extract_int<long>(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,long *param_5,undefined param_6,uint *param_7,ulong *param_8);
undefined  [16]std::num_get<>::do_get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,long *param_5);
void std::num_get<>::get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,long *param_5);
undefined  [16]std::num_get<>::do_get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,bool *param_5,undefined param_6,uint *param_7,byte *param_8);
istreambuf_iterator std::num_get<>::_M_extract_int<>(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,ushort *param_5,undefined param_6,uint *param_7,ushort *param_8);
undefined  [16]std::num_get<>::do_get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,ushort *param_5);
void std::num_get<>::get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,ushort *param_5);
istreambuf_iterator std::num_get<>::_M_extract_int<>(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,uint *param_5,undefined param_6,uint *param_7,uint *param_8);
undefined  [16]std::num_get<>::do_get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,uint *param_5);
void std::num_get<>::get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,uint *param_5);
istreambuf_iterator std::num_get<>::_M_extract_int<>(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,ulong *param_5,undefined param_6,uint *param_7,ulong *param_8);
undefined  [16]std::num_get<>::do_get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,ulong *param_5);
void std::num_get<>::do_get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,void **param_5,undefined param_6,undefined8 param_7,undefined8 *param_8);
void std::num_get<>::get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,ulong *param_5);
istreambuf_iterator std::num_get<>::_M_extract_int<long_long>(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,longlong *param_5,undefined param_6,uint *param_7,ulong *param_8);
undefined  [16]std::num_get<>::do_get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,longlong *param_5);
void std::num_get<>::get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,longlong *param_5);
istreambuf_iterator std::num_get<>::_M_extract_int<>(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,ulonglong *param_5,undefined param_6,uint *param_7,ulong *param_8);
undefined  [16]std::num_get<>::do_get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,ulonglong *param_5);
void std::num_get<>::get(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,ulonglong *param_5);
istreambuf_iterator std::money_get<>::_M_extract<true>(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,string *param_5,undefined param_6,uint *param_7,string *param_8);
istreambuf_iterator std::money_get<>::_M_extract<false>(istreambuf_iterator param_1,istreambuf_iterator param_2,ios_base *param_3,_Ios_Iostate *param_4,string *param_5,undefined param_6,uint *param_7,string *param_8);
undefined  [16]std::money_get<>::do_get(istreambuf_iterator param_1,istreambuf_iterator param_2,bool param_3,ios_base *param_4,_Ios_Iostate *param_5,longdouble *param_6,undefined8 param_7,_Ios_Iostate *param_8,longdouble *param_9);
undefined  [16]std::money_get<>::do_get(istreambuf_iterator param_1,istreambuf_iterator param_2,bool param_3,ios_base *param_4,_Ios_Iostate *param_5,wstring *param_6,long param_7,undefined8 param_8,wstring *param_9);
void __thiscall std::wstring::_M_data(wstring *this,wchar_t *param_1);
void __thiscall std::wstring::_M_length(wstring *this,ulong param_1);
undefined8 __thiscall std::wstring::_M_data(wstring *this);
wstring * __thiscall std::wstring::_M_local_data(wstring *this);
wstring * __thiscall std::wstring::_M_local_data(wstring *this);
void __thiscall std::wstring::_M_capacity(wstring *this,ulong param_1);
void __thiscall std::wstring::_M_set_length(wstring *this,ulong param_1);
undefined8 __thiscall std::wstring::_M_is_local(wstring *this);
void __thiscall std::wstring::_M_create(wstring *this,ulong *param_1,ulong param_2);
void __thiscall std::wstring::_M_dispose(wstring *this);
void std::wstring::_M_destroy(ulong param_1);
void __thiscall std::wstring::_M_construct(wstring *this,ulong param_1,wchar_t param_2);
void __thiscall std::wstring::_M_construct_aux_2(wstring *this,ulong param_1,wchar_t param_2);
wstring * __thiscall std::wstring::_M_get_allocator(wstring *this);
wstring * __thiscall std::wstring::_M_get_allocator(wstring *this);
void __thiscall std::wstring::_M_check(wstring *this,ulong param_1,char *param_2);
void __thiscall std::wstring::_M_check_length(wstring *this,ulong param_1,ulong param_2,char *param_3);
ulong __thiscall std::wstring::_M_limit(wstring *this,ulong param_1,ulong param_2);
undefined8 __thiscall std::wstring::_M_disjunct(wstring *this,wchar_t *param_1);
void std::wstring::_S_copy(wchar_t *param_1,wchar_t *param_2,ulong param_3);
void std::wstring::_S_move(wchar_t *param_1,wchar_t *param_2,ulong param_3);
void std::wstring::_S_assign(wchar_t *param_1,ulong param_2,wchar_t param_3);
void std::wstring::_S_copy_chars(wchar_t *param_1,__normal_iterator param_2,__normal_iterator param_3);
void std::wstring::_S_copy_chars(wchar_t *param_1,__normal_iterator param_2,__normal_iterator param_3);
void std::wstring::_S_copy_chars(wchar_t *param_1,wchar_t *param_2,wchar_t *param_3);
void std::wstring::_S_copy_chars(wchar_t *param_1,wchar_t *param_2,wchar_t *param_3);
ulong std::wstring::_S_compare(ulong param_1,ulong param_2);
void __thiscall std::wstring::_M_assign(wstring *this,wstring *param_1);
void __thiscall std::wstring::_M_mutate(wstring *this,ulong param_1,ulong param_2,wchar_t *param_3,ulong param_4);
void __thiscall std::wstring::_M_erase(wstring *this,ulong param_1,ulong param_2);
void __thiscall std::wstring::wstring(wstring *this);
void __thiscall std::wstring::wstring(wstring *this,allocator *param_1);
void __thiscall std::wstring::wstring(wstring *this,ulong param_1,wchar_t param_2,allocator *param_3);
void __thiscall std::wstring::wstring(wstring *this,wstring *param_1);
void __thiscall std::wstring::wstring(wstring *this,wstring *param_1,allocator *param_2);
void __thiscall std::wstring::~wstring(wstring *this);
wstring * __thiscall std::wstring::operator=(wstring *this,wstring *param_1);
wstring * __thiscall std::wstring::operator=(wstring *this,wstring *param_1);
undefined8 __thiscall std::wstring::begin(wstring *this);
undefined8 __thiscall std::wstring::begin(wstring *this);
long __thiscall std::wstring::end(wstring *this);
long __thiscall std::wstring::end(wstring *this);
void std::wstring::rbegin(void);
void std::wstring::rbegin(void);
void std::wstring::rend(void);
void std::wstring::rend(void);
undefined8 __thiscall std::wstring::cbegin(wstring *this);
long __thiscall std::wstring::cend(wstring *this);
void std::wstring::crbegin(void);
void std::wstring::crend(void);
undefined8 __thiscall std::wstring::size(wstring *this);
undefined8 __thiscall std::wstring::length(wstring *this);
undefined8 std::wstring::max_size(void);
undefined8 __thiscall std::wstring::capacity(wstring *this);
void __thiscall std::wstring::reserve(wstring *this,ulong param_1);
void __thiscall std::wstring::shrink_to_fit(wstring *this);
void __thiscall std::wstring::clear(wstring *this);
bool __thiscall std::wstring::empty(wstring *this);
long __thiscall std::wstring::operator[](wstring *this,ulong param_1);
long __thiscall std::wstring::operator[](wstring *this,ulong param_1);
long __thiscall std::wstring::at(wstring *this,ulong param_1);
long __thiscall std::wstring::at(wstring *this,ulong param_1);
undefined8 __thiscall std::wstring::front(wstring *this);
undefined8 __thiscall std::wstring::front(wstring *this);
long __thiscall std::wstring::back(wstring *this);
long __thiscall std::wstring::back(wstring *this);
wstring * __thiscall std::wstring::operator+=(wstring *this,wchar_t param_1);
void __thiscall std::wstring::push_back(wstring *this,wchar_t param_1);
wstring * __thiscall std::wstring::assign(wstring *this,wstring *param_1);
wstring * __thiscall std::wstring::assign(wstring *this,wstring *param_1);
wstring * __thiscall std::wstring::erase(wstring *this,ulong param_1,ulong param_2);
long __thiscall std::wstring::erase(wstring *this,__normal_iterator param_1);
undefined4 * __thiscall std::wstring::erase(wstring *this,__normal_iterator param_1,__normal_iterator param_2);
void __thiscall std::wstring::pop_back(wstring *this);
wstring * __thiscall std::wstring::_M_replace_aux(wstring *this,ulong param_1,ulong param_2,ulong param_3,wchar_t param_4);
void __thiscall std::wstring::append(wstring *this,ulong param_1,wchar_t param_2);
void __thiscall std::wstring::resize(wstring *this,ulong param_1,wchar_t param_2);
void __thiscall std::wstring::resize(wstring *this,ulong param_1);
void __thiscall std::wstring::assign(wstring *this,ulong param_1,wchar_t param_2);
wstring * __thiscall std::wstring::operator=(wstring *this,wchar_t param_1);
void __thiscall std::wstring::insert(wstring *this,ulong param_1,ulong param_2,wchar_t param_3);
long __thiscall std::wstring::insert(wstring *this,__normal_iterator param_1,wchar_t param_2);
void __thiscall std::wstring::replace(wstring *this,ulong param_1,ulong param_2,ulong param_3,wchar_t param_4);
void __thiscall std::wstring::replace(wstring *this,__normal_iterator param_1,__normal_iterator param_2,ulong param_3,wchar_t param_4);
long __thiscall std::wstring::insert(wstring *this,__normal_iterator param_1,ulong param_2,wchar_t param_3);
wstring * __thiscall std::wstring::_M_replace(wstring *this,ulong param_1,ulong param_2,wchar_t *param_3,ulong param_4);
void __thiscall std::wstring::assign(wstring *this,wstring *param_1,ulong param_2,ulong param_3);
void __thiscall std::wstring::assign(wstring *this,wchar_t *param_1,ulong param_2);
wstring * __thiscall std::wstring::operator=(wstring *this,initializer_list param_1);
void std::wstring::assign(initializer_list param_1);
void __thiscall std::wstring::assign(wstring *this,wchar_t *param_1);
void __thiscall std::wstring::replace(wstring *this,ulong param_1,ulong param_2,wchar_t *param_3,ulong param_4);
void __thiscall std::wstring::operator=(wstring *this,wchar_t *param_1);
void __thiscall std::wstring::insert(wstring *this,ulong param_1,wchar_t *param_2,ulong param_3);
void __thiscall std::wstring::insert(wstring *this,ulong param_1,wstring *param_2);
void __thiscall std::wstring::replace(wstring *this,ulong param_1,ulong param_2,wstring *param_3);
void __thiscall std::wstring::insert(wstring *this,ulong param_1,wchar_t *param_2);
void __thiscall std::wstring::replace(wstring *this,ulong param_1,ulong param_2,wchar_t *param_3);
void __thiscall std::wstring::replace(wstring *this,__normal_iterator param_1,__normal_iterator param_2,wchar_t *param_3,ulong param_4);
void __thiscall std::wstring::replace(wstring *this,__normal_iterator param_1,__normal_iterator param_2,wstring *param_3);
void __thiscall std::wstring::replace(wstring *this,__normal_iterator param_1,__normal_iterator param_2,wchar_t *param_3,wchar_t *param_4);
void __thiscall std::wstring::replace(wstring *this,__normal_iterator param_1,__normal_iterator param_2,wchar_t *param_3,wchar_t *param_4);
void std::wstring::replace(__normal_iterator param_1,__normal_iterator param_2,initializer_list param_3);
void __thiscall std::wstring::replace(wstring *this,__normal_iterator param_1,__normal_iterator param_2,wchar_t *param_3);
long std::wstring::insert(__normal_iterator param_1,initializer_list param_2);
void std::wstring::insert(__normal_iterator param_1,initializer_list param_2);
void __thiscall std::wstring::replace(wstring *this,__normal_iterator param_1,__normal_iterator param_2,__normal_iterator param_3,__normal_iterator param_4);
void __thiscall std::wstring::replace(wstring *this,__normal_iterator param_1,__normal_iterator param_2,__normal_iterator param_3,__normal_iterator param_4);
void __thiscall std::wstring::insert(wstring *this,ulong param_1,wstring *param_2,ulong param_3,ulong param_4);
void __thiscall std::wstring::replace(wstring *this,ulong param_1,ulong param_2,wstring *param_3,ulong param_4,ulong param_5);
wstring * __thiscall std::wstring::_M_append(wstring *this,wchar_t *param_1,ulong param_2);
void __thiscall std::wstring::append(wstring *this,wstring *param_1);
void __thiscall std::wstring::operator+=(wstring *this,wstring *param_1);
void std::wstring::append(wstring *param_1,ulong param_2,ulong param_3);
void __thiscall std::wstring::append(wstring *this,wchar_t *param_1,ulong param_2);
void __thiscall std::wstring::append(wstring *this,wchar_t *param_1);
void __thiscall std::wstring::operator+=(wstring *this,wchar_t *param_1);
void __thiscall std::wstring::operator+=(wstring *this,initializer_list param_1);
void std::wstring::append(initializer_list param_1);
size_t __thiscall std::wstring::copy(wstring *this,wchar_t *param_1,ulong param_2,ulong param_3);
void __thiscall std::wstring::swap(wstring *this,wstring *param_1);
undefined8 __thiscall std::wstring::c_str(wstring *this);
undefined8 __thiscall std::wstring::data(wstring *this);
wstring * __thiscall std::wstring::get_allocator(wstring *this);
ulong __thiscall std::wstring::find(wstring *this,wchar_t *param_1,ulong param_2,ulong param_3);
void __thiscall std::wstring::find(wstring *this,wstring *param_1,ulong param_2);
void __thiscall std::wstring::find(wstring *this,wchar_t *param_1,ulong param_2);
long __thiscall std::wstring::find(wstring *this,wchar_t param_1,ulong param_2);
ulong __thiscall std::wstring::rfind(wstring *this,wchar_t *param_1,ulong param_2,ulong param_3);
void __thiscall std::wstring::rfind(wstring *this,wstring *param_1,ulong param_2);
void __thiscall std::wstring::rfind(wstring *this,wchar_t *param_1,ulong param_2);
ulong __thiscall std::wstring::rfind(wstring *this,wchar_t param_1,ulong param_2);
ulong __thiscall std::wstring::find_first_of(wstring *this,wchar_t *param_1,ulong param_2,ulong param_3);
void __thiscall std::wstring::find_first_of(wstring *this,wstring *param_1,ulong param_2);
void __thiscall std::wstring::find_first_of(wstring *this,wchar_t *param_1,ulong param_2);
long __thiscall std::wstring::find_first_of(wstring *this,wchar_t param_1,ulong param_2);
ulong __thiscall std::wstring::find_last_of(wstring *this,wchar_t *param_1,ulong param_2,ulong param_3);
void __thiscall std::wstring::find_last_of(wstring *this,wstring *param_1,ulong param_2);
void __thiscall std::wstring::find_last_of(wstring *this,wchar_t *param_1,ulong param_2);
ulong __thiscall std::wstring::find_last_of(wstring *this,wchar_t param_1,ulong param_2);
ulong __thiscall std::wstring::find_first_not_of(wstring *this,wchar_t *param_1,ulong param_2,ulong param_3);
void __thiscall std::wstring::find_first_not_of(wstring *this,wstring *param_1,ulong param_2);
void __thiscall std::wstring::find_first_not_of(wstring *this,wchar_t *param_1,ulong param_2);
ulong __thiscall std::wstring::find_first_not_of(wstring *this,wchar_t param_1,ulong param_2);
ulong __thiscall std::wstring::find_last_not_of(wstring *this,wchar_t *param_1,ulong param_2,ulong param_3);
void __thiscall std::wstring::find_last_not_of(wstring *this,wstring *param_1,ulong param_2);
void __thiscall std::wstring::find_last_not_of(wstring *this,wchar_t *param_1,ulong param_2);
ulong __thiscall std::wstring::find_last_not_of(wstring *this,wchar_t param_1,ulong param_2);
ulong __thiscall std::wstring::compare(wstring *this,wstring *param_1);
ulong __thiscall std::wstring::compare(wstring *this,ulong param_1,ulong param_2,wstring *param_3);
ulong __thiscall std::wstring::compare(wstring *this,ulong param_1,ulong param_2,wstring *param_3,ulong param_4,ulong param_5);
ulong __thiscall std::wstring::compare(wstring *this,wchar_t *param_1);
ulong __thiscall std::wstring::compare(wstring *this,ulong param_1,ulong param_2,wchar_t *param_3);
ulong __thiscall std::wstring::compare(wstring *this,ulong param_1,ulong param_2,wchar_t *param_3,ulong param_4);
void __thiscall std::wstring::_Alloc_hider::_Alloc_hider(_Alloc_hider *this,wchar_t *param_1,allocator *param_2);
void __thiscall std::wstring::_Alloc_hider::_Alloc_hider(_Alloc_hider *this,wchar_t *param_1,allocator *param_2);
wstring * std::operator+(wstring *param_1,wchar_t *param_2,undefined8 *param_3);
wstring * std::operator+(wstring *param_1,wchar_t param_2,undefined8 *param_3);
void std::wstring::_M_construct<>(__normal_iterator param_1,__normal_iterator param_2,forward_iterator_tag param_3);
void __thiscall std::wstring::wstring<>(wstring *this,__normal_iterator param_1,__normal_iterator param_2,allocator *param_3);
void std::wstring::_M_construct<>(__normal_iterator param_1,__normal_iterator param_2,forward_iterator_tag param_3);
void __thiscall std::wstring::wstring(wstring *this,wstring *param_1,allocator *param_2);
void std::wstring::_M_construct<wchar_t*>(wchar_t *param_1,wchar_t *param_2,forward_iterator_tag param_3);
void __thiscall std::wstring::wstring(wstring *this,wstring *param_1);
wstring * std::operator+(wstring *param_1,undefined8 *param_2,undefined8 *param_3);
void __thiscall std::wstring::wstring<>(wstring *this,wchar_t *param_1,wchar_t *param_2,allocator *param_3);
void std::wstring::_M_construct<>(wchar_t *param_1,wchar_t *param_2,forward_iterator_tag param_3);
void __thiscall std::wstring::wstring(wstring *this,wstring *param_1,ulong param_2,allocator *param_3);
void __thiscall std::wstring::wstring(wstring *this,wstring *param_1,ulong param_2,ulong param_3);
void __thiscall std::wstring::wstring(wstring *this,wstring *param_1,ulong param_2,ulong param_3,allocator *param_4);
void __thiscall std::wstring::wstring(wstring *this,wchar_t *param_1,ulong param_2,allocator *param_3);
void __thiscall std::wstring::wstring(wstring *this,wchar_t *param_1,allocator *param_2);
void __thiscall std::wstring::wstring(wstring *this,initializer_list param_1,allocator *param_2);
void __thiscall std::wstring::wstring<>(wstring *this,wchar_t *param_1,wchar_t *param_2,allocator *param_3);
ulong std::wstring::substr(ulong param_1,ulong param_2);
bool operator==(__normal_iterator *param_1,__normal_iterator *param_2);
bool operator==(__normal_iterator *param_1,__normal_iterator *param_2);
char * std::bad_alloc::what(void);
void __thiscall std::bad_alloc::~bad_alloc(bad_alloc *this);
void __thiscall std::bad_alloc::~bad_alloc(bad_alloc *this);
char * std::bad_cast::what(void);
void __thiscall std::bad_cast::~bad_cast(bad_cast *this);
void __thiscall std::bad_cast::~bad_cast(bad_cast *this);
char * std::bad_typeid::what(void);
void __thiscall std::bad_typeid::~bad_typeid(bad_typeid *this);
void __thiscall std::bad_typeid::~bad_typeid(bad_typeid *this);
undefined4 * d_make_comp(long param_1,undefined4 param_2,long param_3,long param_4);
undefined8 d_ref_qualifier(long param_1,undefined8 param_2);
void d_count_templates_scopes(long param_1,undefined4 *param_2);
void d_append_buffer(long param_1,undefined *param_2,long param_3);
int d_number.isra.0(long *param_1);
undefined4 * d_number_component(long param_1);
int d_compact_number(long param_1);
undefined4 * d_template_param(long param_1);
undefined8 * d_source_name(long param_1);
undefined8 d_abi_tags(long param_1,undefined8 param_2);
undefined4 * d_substitution(long param_1,uint param_2);
undefined8 d_call_offset(long param_1,int param_2);
uint next_is_type_qual.isra.0(char *param_1);
undefined8 d_discriminator(long param_1);
undefined8 d_index_template_argument.part.0(int *param_1,int param_2);
undefined8 d_lookup_template_argument.isra.0(long param_1,undefined8 *param_2);
int * d_find_pack(undefined8 param_1,undefined4 *param_2);
void d_growable_string_callback_adapter(void *param_1,size_t param_2,long *param_3);
uint * d_exprlist(long param_1,char param_2);
uint * d_expression_1(long param_1);
undefined8 d_template_arg(long param_1);
undefined8 d_template_args_1(long param_1);
undefined8 d_template_args(long param_1);
uint * d_encoding(long param_1,int param_2);
long d_name(long param_1);
int * d_type(long param_1);
undefined8 * d_operator_name(long param_1);
long d_parmlist(long param_1);
long * d_cv_qualifiers(long param_1,long *param_2,uint param_3);
undefined8 d_bare_function_type(long param_1,int param_2);
undefined8 d_function_type(long param_1);
int * d_unqualified_name(long param_1);
undefined8 d_expr_primary(long param_1);
void d_print_comp_inner(undefined *param_1,uint param_2,int *param_3);
void d_print_comp(long param_1,undefined8 param_2,long param_3);
void d_print_mod(undefined *param_1,uint param_2,undefined4 *param_3);
void d_print_function_type.isra.0(undefined2 *param_1,undefined4 param_2,long *param_3,long *param_4);
void d_print_mod_list(long param_1,uint param_2,long *param_3,int param_4);
void d_print_array_type.isra.0(undefined2 *param_1,undefined4 param_2,long *param_3,long *param_4);
void d_print_expr_op(long param_1,undefined8 param_2,int *param_3);
void d_print_subexpr(long param_1,ulong param_2,uint *param_3);
undefined8 d_maybe_print_fold_expression.isra.0(long param_1,undefined4 param_2,long param_3,long *param_4);
bool d_demangle_callback.constprop.0(byte *param_1,code *param_2,undefined8 param_3);
char * __cxa_demangle(long param_1,char *param_2,ulong *param_3,undefined4 *param_4);
uint __gcclibcxx_demangle_callback(long param_1,long param_2);
void __cxa_call_terminate(long *param_1);
long * __cxa_current_exception_type(void);
undefined8 std::set_new_handler(_func_void *param_1);
undefined8 std::get_new_handler(void);
void * operator.new[](ulong param_1,nothrow_t *param_2);
void __thiscall __cxxabiv1::__pbase_type_info::__pointer_catch(__pbase_type_info *this,__pbase_type_info *param_1,void **param_2,uint param_3);
void __thiscall __cxxabiv1::__pbase_type_info::~__pbase_type_info(__pbase_type_info *this);
void __thiscall __cxxabiv1::__pbase_type_info::~__pbase_type_info(__pbase_type_info *this);
undefined8 __thiscall __cxxabiv1::__pbase_type_info::__do_catch(__pbase_type_info *this,type_info *param_1,void **param_2,uint param_3);
void __thiscall __cxxabiv1::__pointer_to_member_type_info::~__pointer_to_member_type_info(__pointer_to_member_type_info *this);
void __thiscall __cxxabiv1::__pointer_to_member_type_info::~__pointer_to_member_type_info(__pointer_to_member_type_info *this);
undefined8 __thiscall __cxxabiv1::__pointer_to_member_type_info::__pointer_catch(__pointer_to_member_type_info *this,__pbase_type_info *param_1,void **param_2,uint param_3);
void __thiscall std::Catalogs::~Catalogs(Catalogs *this);
void std::__convert_to_v<float>(char *param_1,float *param_2,_Ios_Iostate *param_3,__locale_struct **param_4);
void std::__convert_to_v<double>(char *param_1,double *param_2,_Ios_Iostate *param_3,__locale_struct **param_4);
void std::__convert_to_v<>(char *param_1,longdouble *param_2,_Ios_Iostate *param_3,__locale_struct **param_4);
void std::locale::facet::_S_create_c_locale(__locale_struct **param_1,char *param_2,__locale_struct *param_3);
void std::locale::facet::_S_destroy_c_locale(__locale_struct **param_1);
void std::locale::facet::_S_clone_c_locale(__locale_struct **param_1);
void std::locale::facet::_S_lc_ctype_c_locale(__locale_struct *param_1,char *param_2);
void __thiscall std::Catalogs::_M_erase(Catalogs *this,int param_1);
int * __thiscall std::Catalogs::_M_get(Catalogs *this,int param_1);
undefined1 * std::get_catalogs(void);
void __thiscall std::vector<>::_M_realloc_insert(vector<> *this,__normal_iterator param_1,Catalog_info **param_2);
int __thiscall std::Catalogs::_M_add(Catalogs *this,locale *param_1,locale *param_3);
uint __thiscall std::collate<char>::_M_compare(collate<char> *this,char *param_1,char *param_2);
void __thiscall std::collate<char>::_M_transform(collate<char> *this,char *param_1,char *param_2,ulong param_3);
uint __thiscall std::collate<wchar_t>::_M_compare(collate<wchar_t> *this,wchar_t *param_1,wchar_t *param_2);
void __thiscall std::collate<wchar_t>::_M_transform(collate<wchar_t> *this,wchar_t *param_1,wchar_t *param_2,ulong param_3);
uint __thiscall std::collate<char>::_M_compare(collate<char> *this,char *param_1,char *param_2);
void __thiscall std::collate<char>::_M_transform(collate<char> *this,char *param_1,char *param_2,ulong param_3);
uint __thiscall std::collate<wchar_t>::_M_compare(collate<wchar_t> *this,wchar_t *param_1,wchar_t *param_2);
void __thiscall std::collate<wchar_t>::_M_transform(collate<wchar_t> *this,wchar_t *param_1,wchar_t *param_2,ulong param_3);
void __thiscall std::ios_base::_M_init(ios_base *this);
locale * std::ios_base::imbue(locale *param_1);
void * __thiscall std::ios::operator.cast.to.void*(ios *this);
void * __thiscall std::wios::operator.cast.to.void*(wios *this);
istream * __thiscall std::istream::getline(istream *this,char *param_1,long param_2,char param_3);
istream * __thiscall std::istream::ignore(istream *this,long param_1,int param_2);
istream * std::operator>>(istream *param_1,char *param_2);
wistream * __thiscall std::wistream::getline(wistream *this,wchar_t *param_1,long param_2,wchar_t param_3);
void FUN_001feb38(void);
wistream * __thiscall std::wistream::ignore(wistream *this,long param_1,uint param_2);
void std::__num_base::_S_format_float(ios_base *param_1,char *param_2,char param_3);
ulong std::__verify_grouping_impl(char *param_1,ulong param_2,char *param_3,ulong param_4);
void std::__verify_grouping(char *param_1,ulong param_2,string *param_3);
undefined4 __thiscall std::messages<char>::do_open(messages<char> *this,string *param_1,locale *param_2);
void __thiscall std::messages<wchar_t>::do_close(messages<wchar_t> *this,int param_1);
long * std::messages<char>::do_get(int param_1,int param_2,int param_3,string *param_4);
undefined4 __thiscall std::messages<wchar_t>::do_open(messages<wchar_t> *this,string *param_1,locale *param_2);
wchar_t * std::messages<wchar_t>::do_get(int param_1,int param_2,int param_3,wstring *param_4);
undefined4 __thiscall std::messages<char>::do_open(messages<char> *this,string *param_1,locale *param_2);
void __thiscall std::messages<wchar_t>::do_close(messages<wchar_t> *this,int param_1);
string * std::messages<char>::do_get(int param_1,int param_2,int param_3,string *param_4);
undefined4 __thiscall std::messages<wchar_t>::do_open(messages<wchar_t> *this,string *param_1,locale *param_2);
wstring * std::messages<wchar_t>::do_get(int param_1,int param_2,int param_3,wstring *param_4);
long __thiscall std::string::erase(string *this,__normal_iterator param_1);
long __thiscall std::string::erase(string *this,__normal_iterator param_1,__normal_iterator param_2);
void __thiscall std::string::insert(string *this,__normal_iterator param_1,ulong param_2,char param_3);
void __thiscall std::string::insert<>(string *this,__normal_iterator param_1,__normal_iterator param_2,__normal_iterator param_3);
long __thiscall std::string::insert(string *this,__normal_iterator param_1,char param_2);
void __thiscall std::string::replace(string *this,__normal_iterator param_1,__normal_iterator param_2,string *param_3);
void __thiscall std::string::replace(string *this,__normal_iterator param_1,__normal_iterator param_2,char *param_3,ulong param_4);
void __thiscall std::string::replace(string *this,__normal_iterator param_1,__normal_iterator param_2,char *param_3);
void __thiscall std::string::replace(string *this,__normal_iterator param_1,__normal_iterator param_2,ulong param_3,char param_4);
void __thiscall std::string::replace(string *this,__normal_iterator param_1,__normal_iterator param_2,char *param_3,char *param_4);
void __thiscall std::string::replace(string *this,__normal_iterator param_1,__normal_iterator param_2,char *param_3,char *param_4);
void __thiscall std::string::replace(string *this,__normal_iterator param_1,__normal_iterator param_2,__normal_iterator param_3,__normal_iterator param_4);
void __thiscall std::string::replace(string *this,__normal_iterator param_1,__normal_iterator param_2,__normal_iterator param_3,__normal_iterator param_4);
long __thiscall std::wstring::erase(wstring *this,__normal_iterator param_1);
undefined4 * __thiscall std::wstring::erase(wstring *this,__normal_iterator param_1,__normal_iterator param_2);
void __thiscall std::wstring::insert(wstring *this,__normal_iterator param_1,ulong param_2,wchar_t param_3);
void __thiscall std::wstring::insert<>(wstring *this,__normal_iterator param_1,__normal_iterator param_2,__normal_iterator param_3);
long __thiscall std::wstring::insert(wstring *this,__normal_iterator param_1,wchar_t param_2);
void __thiscall std::wstring::replace(wstring *this,__normal_iterator param_1,__normal_iterator param_2,wstring *param_3);
void __thiscall std::wstring::replace(wstring *this,__normal_iterator param_1,__normal_iterator param_2,wchar_t *param_3,ulong param_4);
void __thiscall std::wstring::replace(wstring *this,__normal_iterator param_1,__normal_iterator param_2,wchar_t *param_3);
void __thiscall std::wstring::replace(wstring *this,__normal_iterator param_1,__normal_iterator param_2,ulong param_3,wchar_t param_4);
void __thiscall std::wstring::replace(wstring *this,__normal_iterator param_1,__normal_iterator param_2,wchar_t *param_3,wchar_t *param_4);
void __thiscall std::wstring::replace(wstring *this,__normal_iterator param_1,__normal_iterator param_2,wchar_t *param_3,wchar_t *param_4);
void __thiscall std::wstring::replace(wstring *this,__normal_iterator param_1,__normal_iterator param_2,__normal_iterator param_3,__normal_iterator param_4);
void __thiscall std::wstring::replace(wstring *this,__normal_iterator param_1,__normal_iterator param_2,__normal_iterator param_3,__normal_iterator param_4);
void std::__verify_grouping(char *param_1,ulong param_2,string *param_3);
undefined8 __thiscall std::logic_error::what(logic_error *this);
undefined8 __thiscall std::runtime_error::what(runtime_error *this);
void __thiscall std::logic_error::~logic_error(logic_error *this);
void __thiscall std::logic_error::~logic_error(logic_error *this);
void __thiscall std::domain_error::~domain_error(domain_error *this);
void __thiscall std::domain_error::~domain_error(domain_error *this);
void __thiscall std::invalid_argument::~invalid_argument(invalid_argument *this);
void __thiscall std::invalid_argument::~invalid_argument(invalid_argument *this);
void __thiscall std::length_error::~length_error(length_error *this);
void __thiscall std::length_error::~length_error(length_error *this);
void __thiscall std::out_of_range::~out_of_range(out_of_range *this);
void __thiscall std::out_of_range::~out_of_range(out_of_range *this);
void __thiscall std::runtime_error::~runtime_error(runtime_error *this);
void __thiscall std::runtime_error::~runtime_error(runtime_error *this);
void __thiscall std::range_error::~range_error(range_error *this);
void __thiscall std::range_error::~range_error(range_error *this);
void __thiscall std::overflow_error::~overflow_error(overflow_error *this);
void __thiscall std::overflow_error::~overflow_error(overflow_error *this);
void __thiscall std::underflow_error::~underflow_error(underflow_error *this);
void __thiscall std::underflow_error::~underflow_error(underflow_error *this);
void __thiscall std::logic_error::logic_error(logic_error *this,string *param_1);
void __thiscall std::domain_error::domain_error(domain_error *this,string *param_1);
void __thiscall std::invalid_argument::invalid_argument(invalid_argument *this,string *param_1);
void __thiscall std::length_error::length_error(length_error *this,string *param_1);
void __thiscall std::out_of_range::out_of_range(out_of_range *this,string *param_1);
void __thiscall std::runtime_error::runtime_error(runtime_error *this,string *param_1);
void __thiscall std::range_error::range_error(range_error *this,string *param_1);
void __thiscall std::overflow_error::overflow_error(overflow_error *this,string *param_1);
void __thiscall std::underflow_error::underflow_error(underflow_error *this,string *param_1);
long std::__copy_streambufs_eof<>(streambuf *param_1,streambuf *param_2,bool *param_3);
long std::__copy_streambufs_eof<>(wstreambuf *param_1,wstreambuf *param_2,bool *param_3);
void __thiscall std::__timepunct<char>::_M_put(__timepunct<char> *this,char *param_1,ulong param_2,char *param_3,tm *param_4);
void __thiscall std::__timepunct<char>::_M_initialize_timepunct(__timepunct<char> *this,__locale_struct *param_1);
void __thiscall std::__timepunct<wchar_t>::_M_put(__timepunct<wchar_t> *this,wchar_t *param_1,ulong param_2,wchar_t *param_3,tm *param_4);
void __thiscall std::__timepunct<wchar_t>::_M_initialize_timepunct(__timepunct<wchar_t> *this,__locale_struct *param_1);
void _txnal_cow_string_D1_commit(void *param_1);
void __thiscall std::logic_error::logic_error(logic_error *this,logic_error *param_1);
logic_error * __thiscall std::logic_error::operator=(logic_error *this,logic_error *param_1);
void __thiscall std::logic_error::logic_error(logic_error *this,logic_error *param_1);
logic_error * __thiscall std::logic_error::operator=(logic_error *this,logic_error *param_1);
void __thiscall std::runtime_error::runtime_error(runtime_error *this,runtime_error *param_1);
runtime_error * __thiscall std::runtime_error::operator=(runtime_error *this,runtime_error *param_1);
void __thiscall std::runtime_error::runtime_error(runtime_error *this,runtime_error *param_1);
runtime_error * __thiscall std::runtime_error::operator=(runtime_error *this,runtime_error *param_1);
void __thiscall std::logic_error::logic_error(logic_error *this,char *param_1);
void __thiscall std::domain_error::domain_error(domain_error *this,char *param_1);
void __thiscall std::invalid_argument::invalid_argument(invalid_argument *this,char *param_1);
void __thiscall std::length_error::length_error(length_error *this,char *param_1);
void __thiscall std::out_of_range::out_of_range(out_of_range *this,char *param_1);
void __thiscall std::runtime_error::runtime_error(runtime_error *this,char *param_1);
void __thiscall std::range_error::range_error(range_error *this,char *param_1);
void __thiscall std::overflow_error::overflow_error(overflow_error *this,char *param_1);
void __thiscall std::underflow_error::underflow_error(underflow_error *this,char *param_1);
void __thiscall std::__sso_string::__sso_string(__sso_string *this,string *param_1);
void __thiscall std::__cow_string::__cow_string(__cow_string *this);
void __thiscall std::__cow_string::__cow_string(__cow_string *this,string *param_1);
void __thiscall std::__cow_string::__cow_string(__cow_string *this,char *param_1,ulong param_2);
void __thiscall std::__cow_string::__cow_string(__cow_string *this,__cow_string *param_1);
__cow_string * __thiscall std::__cow_string::operator=(__cow_string *this,__cow_string *param_1);
void __thiscall std::__cow_string::~__cow_string(__cow_string *this);
void __thiscall std::__cow_string::__cow_string(__cow_string *this,__cow_string *param_1);
__cow_string * __thiscall std::__cow_string::operator=(__cow_string *this,__cow_string *param_1);
error_category * __thiscall std::_V2::error_category::_M_message(error_category *this,int param_1);
void _txnal_cow_string_C1_for_exceptions(void *param_1,char *param_2,void *param_3);
void _txnal_cow_string_c_str(void *param_1);
void _txnal_sso_string_c_str(void *param_1);
void _txnal_cow_string_D1(void *param_1);
long _txnal_logic_error_get_msg(void *param_1);
long _txnal_runtime_error_get_msg(void *param_1);
void __thiscall std::logic_error::logic_error(logic_error *this,char *param_1);
void std::logic_error::logic_error(std::string_const&)(void *param_1,void *param_2);
void __thiscall std::logic_error::~logic_error(logic_error *this);
void __thiscall std::logic_error::~logic_error(logic_error *this);
void __thiscall std::logic_error::what(logic_error *this);
void __thiscall std::domain_error::domain_error(domain_error *this,char *param_1);
void std::domain_error::domain_error(std::string_const&)(void *param_1,void *param_2);
void __thiscall std::domain_error::~domain_error(domain_error *this);
void __thiscall std::domain_error::~domain_error(domain_error *this);
void __thiscall std::invalid_argument::invalid_argument(invalid_argument *this,char *param_1);
void std::invalid_argument::invalid_argument(std::string_const&)(void *param_1,void *param_2);
void __thiscall std::invalid_argument::~invalid_argument(invalid_argument *this);
void __thiscall std::invalid_argument::~invalid_argument(invalid_argument *this);
void __thiscall std::length_error::length_error(length_error *this,char *param_1);
void std::length_error::length_error(std::string_const&)(void *param_1,void *param_2);
void __thiscall std::length_error::~length_error(length_error *this);
void __thiscall std::length_error::~length_error(length_error *this);
void __thiscall std::out_of_range::out_of_range(out_of_range *this,char *param_1);
void std::out_of_range::out_of_range(std::string_const&)(void *param_1,void *param_2);
void __thiscall std::out_of_range::~out_of_range(out_of_range *this);
void __thiscall std::out_of_range::~out_of_range(out_of_range *this);
void __thiscall std::runtime_error::runtime_error(runtime_error *this,char *param_1);
void std::runtime_error::runtime_error(std::string_const&)(void *param_1,void *param_2);
void __thiscall std::runtime_error::~runtime_error(runtime_error *this);
void __thiscall std::runtime_error::~runtime_error(runtime_error *this);
void __thiscall std::runtime_error::what(runtime_error *this);
void __thiscall std::range_error::range_error(range_error *this,char *param_1);
void std::range_error::range_error(std::string_const&)(void *param_1,void *param_2);
void __thiscall std::range_error::~range_error(range_error *this);
void __thiscall std::range_error::~range_error(range_error *this);
void __thiscall std::overflow_error::overflow_error(overflow_error *this,char *param_1);
void std::overflow_error::overflow_error(std::string_const&)(void *param_1,void *param_2);
void __thiscall std::overflow_error::~overflow_error(overflow_error *this);
void __thiscall std::overflow_error::~overflow_error(overflow_error *this);
void __thiscall std::underflow_error::underflow_error(underflow_error *this,char *param_1);
void std::underflow_error::underflow_error(std::string_const&)(void *param_1,void *param_2);
void __thiscall std::underflow_error::~underflow_error(underflow_error *this);
void __thiscall std::underflow_error::~underflow_error(underflow_error *this);
char * (anonymous_namespace)::io_error_category::name(void);
void __thiscall(anonymous_namespace)::io_error_category::~io_error_category(io_error_category *this);
void __thiscall(anonymous_namespace)::io_error_category::~io_error_category(io_error_category *this);
void __thiscall std::ios_base::failure[abi:cxx11]::~failure(failure[abi:cxx11] *this);
void __thiscall std::ios_base::failure[abi:cxx11]::~failure(failure[abi:cxx11] *this);
undefined8 __thiscall std::ios_base::failure[abi:cxx11]::what(failure[abi:cxx11] *this);
void __thiscall std::__iosfail_type_info::~__iosfail_type_info(__iosfail_type_info *this);
void __thiscall std::__iosfail_type_info::~__iosfail_type_info(__iosfail_type_info *this);
void __thiscall std::__iosfail_type_info::__do_upcast(__iosfail_type_info *this,__class_type_info *param_1,void **param_2);
void __thiscall std::__ios_failure::~__ios_failure(__ios_failure *this);
void __thiscall std::__ios_failure::~__ios_failure(__ios_failure *this);
undefined8 (anonymous_namespace)::io_error_category::message[abi:cxx11](int param_1);
undefined8 * std::iostream_category(void);
void __thiscall std::ios_base::failure[abi:cxx11]::failure(failure[abi:cxx11] *this,string *param_1);
void __thiscall std::ios_base::failure[abi:cxx11]::failure(failure[abi:cxx11] *this,string *param_1,error_code *param_2);
void __thiscall std::ios_base::failure[abi:cxx11]::failure(failure[abi:cxx11] *this,char *param_1,error_code *param_2);
void __thiscall std::__cow_string::__cow_string(__cow_string *this,string *param_1);
void __thiscall std::logic_error::logic_error(logic_error *this,string *param_1);
void __thiscall std::domain_error::domain_error(domain_error *this,string *param_1);
void __thiscall std::invalid_argument::invalid_argument(invalid_argument *this,string *param_1);
void __thiscall std::length_error::length_error(length_error *this,string *param_1);
void __thiscall std::out_of_range::out_of_range(out_of_range *this,string *param_1);
void __thiscall std::runtime_error::runtime_error(runtime_error *this,string *param_1);
void __thiscall std::range_error::range_error(range_error *this,string *param_1);
void __thiscall std::overflow_error::overflow_error(overflow_error *this,string *param_1);
void __thiscall std::underflow_error::underflow_error(underflow_error *this,string *param_1);
void __thiscall std::__sso_string::__sso_string(__sso_string *this);
void __thiscall std::__sso_string::__sso_string(__sso_string *this,string *param_1);
void __thiscall std::__sso_string::__sso_string(__sso_string *this,char *param_1,ulong param_2);
void __thiscall std::__sso_string::__sso_string(__sso_string *this,__sso_string *param_1);
__sso_string * __thiscall std::__sso_string::operator=(__sso_string *this,__sso_string *param_1);
void __thiscall std::__sso_string::~__sso_string(__sso_string *this);
void __thiscall std::__sso_string::__sso_string(__sso_string *this,__sso_string *param_1);
__sso_string * __thiscall std::__sso_string::operator=(__sso_string *this,__sso_string *param_1);
istream * __thiscall std::istream::ignore(istream *this,long param_1);
wistream * __thiscall std::wistream::ignore(wistream *this,long param_1);
char * std::bad_array_new_length::what(void);
void __thiscall std::bad_array_new_length::~bad_array_new_length(bad_array_new_length *this);
void __thiscall std::bad_array_new_length::~bad_array_new_length(bad_array_new_length *this);
undefined8 __thiscall std::ios_base::failure::what(failure *this);
void __thiscall std::ios_base::failure::~failure(failure *this);
void __thiscall std::ios_base::failure::~failure(failure *this);
void __thiscall std::ios_base::failure::failure(failure *this,string *param_1);
void std::__construct_ios_failure(void *param_1,char *param_2);
void std::__destroy_ios_failure(void *param_1);
undefined8 std::__is_ios_failure_handler(__class_type_info *param_1);
uint * read_encoded_value_with_base(byte param_1,uint *param_2,uint *param_3,undefined8 *param_4);
undefined8 base_of_encoded_value(byte param_1,long param_2);
void execute_cfa_program(byte *param_1,byte *param_2,long param_3,undefined8 *param_4);
void init_dwarf_reg_size_table(void);
undefined8 uw_frame_state_for(long param_1,long *param_2);
long uw_install_context_1(long param_1,long param_2);
ulong execute_stack_op(byte *param_1,byte *param_2,long param_3,ulong param_4);
void uw_update_context_1(undefined8 *param_1,long *param_2);
void uw_init_context_1(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
void uw_update_context(long param_1,long param_2);
undefined8 _Unwind_RaiseException_Phase2(undefined8 *param_1,long param_2,long *param_3);
int _Unwind_ForcedUnwind_Phase2(undefined8 *param_1,undefined8 param_2,long *param_3);
undefined8 * _Unwind_GetGR(long param_1,int param_2);
undefined8 _Unwind_GetCFA(long param_1);
void _Unwind_SetGR(long param_1,int param_2,undefined8 param_3);
undefined8 _Unwind_GetIP(long param_1);
undefined8 _Unwind_GetIPInfo(long param_1,uint *param_2);
void _Unwind_SetIP(long param_1,undefined8 param_2);
undefined8 _Unwind_GetLanguageSpecificData(long param_1);
undefined8 _Unwind_GetRegionStart(long param_1);
long _Unwind_FindEnclosingFunction(long param_1);
undefined8 _Unwind_GetDataRelBase(long param_1);
undefined8 _Unwind_GetTextRelBase(long param_1);
long __frame_state_for(long param_1,long param_2);
void _Unwind_DebugHook(void);
undefined8 _Unwind_RaiseException(undefined8 *param_1,undefined8 param_2,undefined8 param_3);
undefined8 _Unwind_ForcedUnwind(long param_1,undefined8 param_2,undefined8 param_3);
undefined  [16] _Unwind_Resume(long param_1,undefined8 param_2,undefined8 param_3);
undefined8 _Unwind_Resume_or_Rethrow(long param_1,undefined8 param_2,undefined8 param_3);
void _Unwind_DeleteException(long param_1);
undefined4 _Unwind_Backtrace(code *param_1,undefined8 param_2);
int fde_unencoded_compare(undefined8 param_1,long param_2,long param_3);
void frame_downheap(undefined8 param_1,code *param_2,long param_3,int param_4,int param_5);
void frame_heapsort(undefined8 param_1,undefined8 param_2,long param_3);
undefined8 size_of_encoded_value(byte param_1);
undefined8 base_from_object(byte param_1,long param_2);
undefined8 base_from_cb_data(byte param_1,long param_2);
uint * read_encoded_value_with_base(byte param_1,uint *param_2,uint *param_3,undefined8 *param_4);
int fde_single_encoding_compare(long param_1,long param_2,long param_3);
byte get_cie_encoding(long param_1);
uint * linear_search_fdes(long param_1,uint *param_2,long param_3);
undefined8 _Unwind_IteratePhdrCallback(ulong *param_1,ulong param_2,ulong *param_3);
int fde_mixed_encoding_compare(undefined8 param_1,long param_2,long param_3);
long classify_object_over_fdes(ulong *param_1,uint *param_2);
void add_fdes(long param_1,long *param_2,uint *param_3);
long search_object(ulong *param_1,ulong param_2);
void __register_frame_info_bases.part.0(undefined8 param_1,undefined8 *param_2,undefined8 param_3,undefined8 param_4);
void __register_frame_info_bases(int *param_1);
void __register_frame_info(int *param_1,undefined8 param_2);
void __register_frame(int *param_1);
void __register_frame_info_table_bases(undefined8 param_1,undefined8 *param_2,undefined8 param_3,undefined8 param_4);
void __register_frame_info_table(undefined8 param_1,undefined8 param_2);
void __register_frame_table(undefined8 param_1);
long __deregister_frame_info_bases(int *param_1);
long __deregister_frame_info(int *param_1);
void __deregister_frame(int *param_1);
long _Unwind_Find_FDE(ulong param_1,ulong *param_2);
void __libc_csu_init(EVP_PKEY_CTX *param_1,undefined8 param_2,undefined8 param_3);
void __libc_csu_fini(void);
void _fini(void);
undefined dl_iterate_phdr();
undefined __strtof_l();
undefined __strtod_l();
double strtold_l(char * __nptr, char * * __endptr, __locale_t __loc);
undefined __newlocale();
undefined __freelocale();
undefined __duplocale();
undefined __strftime_l();
undefined __wcsftime_l();
undefined __strcoll_l();
undefined __strxfrm_l();
undefined __wcscoll_l();
undefined __wcsxfrm_l();
undefined bind_textdomain_codeset();
undefined dgettext();
int fseek(FILE * __stream, long __off, int __whence);
char * strtok_r(char * __s, char * __delim, char * * __save_ptr);
undefined _ZGTtdlPv();
undefined _ITM_memcpyRnWt();
undefined _ITM_addUserCommitAction();
undefined _ITM_RU8();
undefined _ITM_memcpyRtWn();
undefined _ZGTtnam();
undefined _ITM_RU1();
void * realloc(void * __ptr, size_t __size);
int putc(int __c, FILE * __stream);
wint_t getwc(__FILE * __stream);
wint_t ungetwc(wint_t __wc, __FILE * __stream);
wint_t putwc(wchar_t __wc, __FILE * __stream);
undefined gettext();
undefined __wctype_l();
undefined __towupper_l();
undefined __towlower_l();
undefined __iswctype_l();
int wctob(wint_t __c);
wint_t btowc(int __c);
undefined bindtextdomain();
__off64_t ftello64(FILE * __stream);
int fseeko64(FILE * __stream, __off64_t __off, int __whence);
int ungetc(int __c, FILE * __stream);
wchar_t * wmemset(wchar_t * __s, wchar_t __c, size_t __n);
wchar_t * wmemmove(wchar_t * __s1, wchar_t * __s2, size_t __n);
wchar_t * wmemcpy(wchar_t * __s1, wchar_t * __s2, size_t __n);
wchar_t * wmemchr(wchar_t * __s, wchar_t __c, size_t __n);
undefined __uselocale();
size_t wcsnrtombs(char * __dst, wchar_t * * __src, size_t __nwc, size_t __len, mbstate_t * __ps);
size_t wcrtomb(char * __s, wchar_t __wc, mbstate_t * __ps);
size_t mbsnrtowcs(wchar_t * __dst, char * * __src, size_t __nmc, size_t __len, mbstate_t * __ps);
size_t mbrtowc(wchar_t * __pwc, char * __s, size_t __n, mbstate_t * __p);
size_t __ctype_get_mb_cur_max(void);
int fputc(int __c, FILE * __stream);
int kill(__pid_t __pid, int __sig);
int getpriority(__priority_which_t __which, id_t __who);
int __xstat64(int __ver, char * __filename, stat64 * __stat_buf);
int semctl(int __semid, int __semnum, int __cmd, ...);
int sched_setaffinity(__pid_t __pid, size_t __cpusetsize, cpu_set_t * __cpuset);
int semget(key_t __key, int __nsems, int __semflg);
int semop(int __semid, sembuf * __sops, size_t __nsops);
int isalpha(int param_1);
int iconv_close(iconv_t __cd);
size_t iconv(iconv_t __cd, char * * __inbuf, size_t * __inbytesleft, char * * __outbuf, size_t * __outbytesleft);
iconv_t iconv_open(char * __tocode, char * __fromcode);
size_t mbsrtowcs(wchar_t * __dst, char * * __src, size_t __len, mbstate_t * __ps);
void * memchr(void * __s, int __c, size_t __n);
int __fxstat64(int __ver, int __fildes, stat64 * __stat_buf);
ssize_t writev(int __fd, iovec * __iovec, int __count);
int fileno(FILE * __stream);
long ftell(FILE * __stream);
FILE * fopen64(char * __filename, char * __modes);
FILE * fdopen(int __fd, char * __modes);
void abort(void);
undefined __nl_langinfo_l();
int pthread_once(pthread_once_t * __once_control, __init_routine * __init_routine);
int pthread_key_delete(pthread_key_t __key);
int system(char * __command);
int pthread_mutexattr_destroy(pthread_mutexattr_t * __attr);
__off64_t lseek64(int __fd, __off64_t __offset, int __whence);
undefined __pthread_key_create();
int sched_yield(void);
undefined dlclose();
undefined dlopen();
int fflush(FILE * __stream);
void rewind(FILE * __stream);
int pthread_attr_setstacksize(pthread_attr_t * __attr, size_t __stacksize);
int pthread_attr_init(pthread_attr_t * __attr);
int sched_setscheduler(__pid_t __pid, int __policy, sched_param * __param);
int sched_getparam(__pid_t __pid, sched_param * __param);
int sched_getscheduler(__pid_t __pid);
int setrlimit(__rlimit_resource_t __resource, rlimit * __rlimits);
int getrlimit(__rlimit_resource_t __resource, rlimit * __rlimits);
undefined __tls_get_addr();
int pthread_mutexattr_settype(pthread_mutexattr_t * __attr, int __kind);
int pthread_key_create(pthread_key_t * __key, __destr_function * __destr_function);
void * pthread_getspecific(pthread_key_t __key);
int pthread_setspecific(pthread_key_t __key, void * __pointer);
int pthread_mutexattr_init(pthread_mutexattr_t * __attr);
int closedir(DIR * __dirp);
char * fgets(char * __s, int __n, FILE * __stream);
dirent * readdir(DIR * __dirp);
DIR * opendir(char * __name);
int sigaction(int __sig, sigaction * __act, sigaction * __oact);
int printf(char * __format, ...);
int setpriority(__priority_which_t __which, id_t __who, int __prio);
__pid_t getppid(void);
void _exit(int __status);
__pid_t fork(void);
int pthread_cancel(pthread_t __th);
__pid_t getpid(void);
int pthread_setname_np(pthread_t __target_thread, char * __name);
int pthread_mutex_destroy(pthread_mutex_t * __mutex);
long syscall(long __sysno, ...);
undefined udev_device_get_parent_with_subsystem_devtype();
undefined udev_device_new_from_devnum();
undefined udev_new();
undefined udev_unref();
undefined udev_device_unref();
undefined udev_device_get_sysattr_value();
undefined udev_device_get_devnode();
undefined udev_device_new_from_syspath();
undefined udev_list_entry_get_name();
undefined udev_list_entry_get_next();
undefined udev_enumerate_unref();
undefined udev_enumerate_get_list_entry();
undefined udev_enumerate_scan_devices();
undefined udev_enumerate_add_match_subsystem();
undefined udev_enumerate_new();
char * strdup(char * __s);
int toupper(int __c);
int setvbuf(FILE * __stream, char * __buf, int __modes, size_t __n);
void exit(int __status);
int getc(FILE * __stream);
int rename(char * __old, char * __new);
int unlink(char * __name);
undefined dladdr();
char * getcwd(char * __buf, size_t __size);
int chdir(char * __path);
int chmod(char * __file, __mode_t __mode);
int fputs(char * __s, FILE * __stream);
char * strncpy(char * __dest, char * __src, size_t __n);
int snprintf(char * __s, size_t __maxlen, char * __format, ...);
int vsnprintf(char * __s, size_t __maxlen, char * __format, __gnuc_va_list __arg);
time_t time(time_t * __timer);
tm * localtime(time_t * __timer);
time_t mktime(tm * __tp);
size_t strftime(char * __s, size_t __maxsize, char * __format, tm * __tp);
int wmemcmp(wchar_t * __s1, wchar_t * __s2, size_t __n);
int putchar(int __c);
int pthread_mutex_lock(pthread_mutex_t * __mutex);
int wcsncmp(wchar_t * __s1, wchar_t * __s2, size_t __n);
undefined __cxa_atexit();
ulong strtoul(char * __nptr, char * * __endptr, int __base);
__pid_t waitpid(__pid_t __pid, int * __stat_loc, int __options);
void perror(char * __s);
FILE * fopen(char * __filename, char * __modes);
int open(char * __file, int __oflag, ...);
int poll(pollfd * __fds, nfds_t __nfds, int __timeout);
char * setlocale(int __category, char * __locale);
wchar_t * wcsdup(wchar_t * __s);
int clock_gettime(clockid_t __clock_id, timespec * __tp);
int sscanf(char * __s, char * __format, ...);
int __fxstat(int __ver, int __fildes, stat * __stat_buf);
int strncasecmp(char * __s1, char * __s2, size_t __n);
void * malloc(size_t __size);
int pthread_mutex_unlock(pthread_mutex_t * __mutex);
int __xstat(int __ver, char * __filename, stat * __stat_buf);
void * memcpy(void * __dest, void * __src, size_t __n);
long strtol(char * __nptr, char * * __endptr, int __base);
void * calloc(size_t __nmemb, size_t __size);
ulonglong strtoull(char * __nptr, char * * __endptr, int __base);
wchar_t * wcsncpy(wchar_t * __dest, wchar_t * __src, size_t __n);
ssize_t read(int __fd, void * __buf, size_t __nbytes);
int alphasort(dirent * * __e1, dirent * * __e2);
int close(int __fd);
int scandir(char * __dir, dirent * * * __namelist, __selector * __selector, __cmp * __cmp);
int ioctl(int __fd, ulong __request, ...);
int gettimeofday(timeval * __tv, __timezone_ptr_t __tz);
int pthread_mutex_init(pthread_mutex_t * __mutex, pthread_mutexattr_t * __mutexattr);
int uname(utsname * __name);
char * strrchr(char * __s, int __c);
int nanosleep(timespec * __requested_time, timespec * __remaining);
undefined dlerror();
size_t wcslen(wchar_t * __s);
undefined dlsym();
char * strchr(char * __s, int __c);
ssize_t write(int __fd, void * __buf, size_t __n);
ssize_t readlink(char * __path, char * __buf, size_t __len);
char * strerror(int __errnum);
size_t mbstowcs(wchar_t * __pwcs, char * __s, size_t __n);
int mkdir(char * __path, __mode_t __mode);
int strncmp(char * __s1, char * __s2, size_t __n);
int * __errno_location(void);
int strcasecmp(char * __s1, char * __s2);
int wcscmp(wchar_t * __s1, wchar_t * __s2);
void free(void * __ptr);
char * getenv(char * __name);
int vsprintf(char * __s, char * __format, __gnuc_va_list __arg);
undefined __libc_start_main();
void syslog(int __pri, char * __fmt, ...);
void openlog(char * __ident, int __option, int __facility);
undefined __cxa_finalize();
int sched_get_priority_min(int __algorithm);
int sched_get_priority_max(int __algorithm);
int pthread_getschedparam(pthread_t __target_thread, int * __policy, sched_param * __param);
int pthread_kill(pthread_t __threadid, int __signo);
int usleep(__useconds_t __useconds);
int pthread_create(pthread_t * __newthread, pthread_attr_t * __attr, __start_routine * __start_routine, void * __arg);
int pthread_join(pthread_t __th, void * * __thread_return);
int pthread_setschedparam(pthread_t __target_thread, int __policy, sched_param * __param);
pthread_t pthread_self(void);
int pthread_cond_wait(pthread_cond_t * __cond, pthread_mutex_t * __mutex);
int pthread_cond_timedwait(pthread_cond_t * __cond, pthread_mutex_t * __mutex, timespec * __abstime);
int pthread_cond_broadcast(pthread_cond_t * __cond);
int pthread_cond_signal(pthread_cond_t * __cond);
int pthread_cond_destroy(pthread_cond_t * __cond);
int pthread_cond_init(pthread_cond_t * __cond, pthread_condattr_t * __cond_attr);
size_t fread(void * __ptr, size_t __size, size_t __n, FILE * __stream);
int fclose(FILE * __stream);
size_t fwrite(void * __ptr, size_t __size, size_t __n, FILE * __s);
char * strstr(char * __haystack, char * __needle);
int strcmp(char * __s1, char * __s2);
undefined crc32();
undefined inflateEnd();
undefined inflateInit_();
void * memset(void * __s, int __c, size_t __n);
int sprintf(char * __s, char * __format, ...);
int puts(char * __s);
undefined deflateEnd();
undefined deflate();
undefined deflateInit_();
undefined inflate();
int memcmp(void * __s1, void * __s2, size_t __n);
void * memmove(void * __dest, void * __src, size_t __n);
int tolower(int __c);
size_t strlen(char * __s);
int remove(char * __filename);
undefined _ITM_registerTMCloneTable();
undefined _ITM_deregisterTMCloneTable();
undefined __gmon_start__();

