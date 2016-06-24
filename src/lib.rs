#![allow(dead_code,
         non_camel_case_types,
         non_upper_case_globals,
         non_snake_case)]
pub type __u_char = ::std::os::raw::c_uchar;
pub type __u_short = ::std::os::raw::c_ushort;
pub type __u_int = ::std::os::raw::c_uint;
pub type __u_long = ::std::os::raw::c_ulong;
pub type __int8_t = ::std::os::raw::c_char;
pub type __uint8_t = ::std::os::raw::c_uchar;
pub type __int16_t = ::std::os::raw::c_short;
pub type __uint16_t = ::std::os::raw::c_ushort;
pub type __int32_t = ::std::os::raw::c_int;
pub type __uint32_t = ::std::os::raw::c_uint;
pub type __int64_t = ::std::os::raw::c_long;
pub type __uint64_t = ::std::os::raw::c_ulong;
pub type __quad_t = ::std::os::raw::c_long;
pub type __u_quad_t = ::std::os::raw::c_ulong;
pub type __dev_t = ::std::os::raw::c_ulong;
pub type __uid_t = ::std::os::raw::c_uint;
pub type __gid_t = ::std::os::raw::c_uint;
pub type __ino_t = ::std::os::raw::c_ulong;
pub type __ino64_t = ::std::os::raw::c_ulong;
pub type __mode_t = ::std::os::raw::c_uint;
pub type __nlink_t = ::std::os::raw::c_ulong;
pub type __off_t = ::std::os::raw::c_long;
pub type __off64_t = ::std::os::raw::c_long;
pub type __pid_t = ::std::os::raw::c_int;
#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct __fsid_t {
    pub __val: [::std::os::raw::c_int; 2usize],
}
impl ::std::default::Default for __fsid_t {
    fn default() -> Self {
        unsafe { ::std::mem::zeroed() }
    }
}
pub type __clock_t = ::std::os::raw::c_long;
pub type __rlim_t = ::std::os::raw::c_ulong;
pub type __rlim64_t = ::std::os::raw::c_ulong;
pub type __id_t = ::std::os::raw::c_uint;
pub type __time_t = ::std::os::raw::c_long;
pub type __useconds_t = ::std::os::raw::c_uint;
pub type __suseconds_t = ::std::os::raw::c_long;
pub type __daddr_t = ::std::os::raw::c_int;
pub type __key_t = ::std::os::raw::c_int;
pub type __clockid_t = ::std::os::raw::c_int;
pub type __timer_t = *mut ::std::os::raw::c_void;
pub type __blksize_t = ::std::os::raw::c_long;
pub type __blkcnt_t = ::std::os::raw::c_long;
pub type __blkcnt64_t = ::std::os::raw::c_long;
pub type __fsblkcnt_t = ::std::os::raw::c_ulong;
pub type __fsblkcnt64_t = ::std::os::raw::c_ulong;
pub type __fsfilcnt_t = ::std::os::raw::c_ulong;
pub type __fsfilcnt64_t = ::std::os::raw::c_ulong;
pub type __fsword_t = ::std::os::raw::c_long;
pub type __ssize_t = ::std::os::raw::c_long;
pub type __syscall_slong_t = ::std::os::raw::c_long;
pub type __syscall_ulong_t = ::std::os::raw::c_ulong;
pub type __loff_t = __off64_t;
pub type __qaddr_t = *mut __quad_t;
pub type __caddr_t = *mut ::std::os::raw::c_char;
pub type __intptr_t = ::std::os::raw::c_long;
pub type __socklen_t = ::std::os::raw::c_uint;
pub type pint8 = ::std::os::raw::c_char;
pub type puint8 = ::std::os::raw::c_uchar;
pub type pint16 = ::std::os::raw::c_short;
pub type puint16 = ::std::os::raw::c_ushort;
pub type pint32 = ::std::os::raw::c_int;
pub type puint32 = ::std::os::raw::c_uint;
pub type pint64 = ::std::os::raw::c_long;
pub type puint64 = ::std::os::raw::c_ulong;
pub type ppointer = *mut ::std::os::raw::c_void;
pub type pconstpointer = *const ::std::os::raw::c_void;
pub type pboolean = ::std::os::raw::c_int;
pub type pchar = ::std::os::raw::c_char;
pub type pshort = ::std::os::raw::c_short;
pub type pint = ::std::os::raw::c_int;
pub type plong = ::std::os::raw::c_long;
pub type puchar = ::std::os::raw::c_uchar;
pub type pushort = ::std::os::raw::c_ushort;
pub type puint = ::std::os::raw::c_uint;
pub type pulong = ::std::os::raw::c_ulong;
pub type pfloat = ::std::os::raw::c_float;
pub type pdouble = ::std::os::raw::c_double;
pub type pssize = ::std::os::raw::c_long;
pub type psize = ::std::os::raw::c_ulong;
pub type pintptr = ::std::os::raw::c_long;
pub type puintptr = ::std::os::raw::c_ulong;
pub type poffset = pint64;
pub type P_HANDLE = *mut ::std::os::raw::c_void;
pub type PTraverseFunc = ::std::option::Option<extern "C" fn(key: ppointer,
                                                               value: ppointer,
                                                               user_data: ppointer)
                                                               -> pboolean>;
pub type PFunc = ::std::option::Option<extern "C" fn(data: ppointer, user_data: ppointer)>;
pub type PDestroyFunc = ::std::option::Option<extern "C" fn(data: ppointer)>;
pub type PCompareFunc = ::std::option::Option<extern "C" fn(a: pconstpointer, b: pconstpointer)
                                                              -> pint>;
pub type PCompareDataFunc = ::std::option::Option<extern "C" fn(a: pconstpointer,
                                                                  b: pconstpointer,
                                                                  data: ppointer)
                                                                  -> pint>;
pub enum PMutex_ { }
pub type PMutex = PMutex_;
pub enum PCondVariable_ { }
pub type PCondVariable = PCondVariable_;
pub enum PCryptoHash_ { }
pub type PCryptoHash = PCryptoHash_;
#[derive(Copy, Clone)]
#[repr(u32)]
#[derive(Debug)]
pub enum PCryptoHashType_ {
    P_CRYPTO_HASH_TYPE_MD5 = 0,
    P_CRYPTO_HASH_TYPE_SHA1 = 1,
    P_CRYPTO_HASH_TYPE_SHA2_224 = 2,
    P_CRYPTO_HASH_TYPE_SHA2_256 = 3,
    P_CRYPTO_HASH_TYPE_SHA2_384 = 4,
    P_CRYPTO_HASH_TYPE_SHA2_512 = 5,
    P_CRYPTO_HASH_TYPE_GOST = 6,
}
pub type PCryptoHashType = PCryptoHashType_;
#[derive(Copy, Clone)]
#[repr(u32)]
#[derive(Debug)]
pub enum PErrorDomain_ {
    P_ERROR_DOMAIN_NONE = 0,
    P_ERROR_DOMAIN_IO = 500,
    P_ERROR_DOMAIN_IPC = 600,
}
pub type PErrorDomain = PErrorDomain_;
#[derive(Copy, Clone)]
#[repr(u32)]
#[derive(Debug)]
pub enum PErrorIO_ {
    P_ERROR_IO_NONE = 500,
    P_ERROR_IO_NO_RESOURCES = 501,
    P_ERROR_IO_NOT_AVAILABLE = 502,
    P_ERROR_IO_ACCESS_DENIED = 503,
    P_ERROR_IO_CONNECTED = 504,
    P_ERROR_IO_IN_PROGRESS = 505,
    P_ERROR_IO_ABORTED = 506,
    P_ERROR_IO_INVALID_ARGUMENT = 507,
    P_ERROR_IO_NOT_SUPPORTED = 508,
    P_ERROR_IO_TIMED_OUT = 509,
    P_ERROR_IO_WOULD_BLOCK = 510,
    P_ERROR_IO_ADDRESS_IN_USE = 511,
    P_ERROR_IO_CONNECTION_REFUSED = 512,
    P_ERROR_IO_NOT_CONNECTED = 513,
    P_ERROR_IO_QUOTA = 514,
    P_ERROR_IO_IS_DIRECTORY = 515,
    P_ERROR_IO_NOT_DIRECTORY = 516,
    P_ERROR_IO_NAMETOOLONG = 517,
    P_ERROR_IO_EXISTS = 518,
    P_ERROR_IO_NOT_EXISTS = 519,
    P_ERROR_IO_NO_MORE = 520,
    P_ERROR_IO_NOT_IMPLEMENTED = 521,
    P_ERROR_IO_FAILED = 522,
}
pub type PErrorIO = PErrorIO_;
#[derive(Copy, Clone)]
#[repr(u32)]
#[derive(Debug)]
pub enum PErrorIPC_ {
    P_ERROR_IPC_NONE = 600,
    P_ERROR_IPC_ACCESS = 601,
    P_ERROR_IPC_EXISTS = 602,
    P_ERROR_IPC_NOT_EXISTS = 603,
    P_ERROR_IPC_NO_RESOURCES = 604,
    P_ERROR_IPC_OVERFLOW = 605,
    P_ERROR_IPC_NAMETOOLONG = 606,
    P_ERROR_IPC_INVALID_ARGUMENT = 607,
    P_ERROR_IPC_NOT_IMPLEMENTED = 608,
    P_ERROR_IPC_DEADLOCK = 609,
    P_ERROR_IPC_FAILED = 610,
}
pub type PErrorIPC = PErrorIPC_;
pub enum PError_ { }
pub type PError = PError_;
pub enum PDir_ { }
pub type PDir = PDir_;
#[derive(Copy, Clone)]
#[repr(u32)]
#[derive(Debug)]
pub enum PDirEntryType_ {
    P_DIR_ENTRY_TYPE_DIR = 1,
    P_DIR_ENTRY_TYPE_FILE = 2,
    P_DIR_ENTRY_TYPE_OTHER = 3,
}
pub type PDirEntryType = PDirEntryType_;
#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct PDirEntry_ {
    pub name: *mut ::std::os::raw::c_char,
    pub type_: PDirEntryType,
    _bindgen_padding_0_: [u8; 4usize],
}
impl ::std::default::Default for PDirEntry_ {
    fn default() -> Self {
        unsafe { ::std::mem::zeroed() }
    }
}
pub type PDirEntry = PDirEntry_;
pub type PList = PList_;
#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct PList_ {
    pub data: ppointer,
    pub next: *mut PList,
}
impl ::std::default::Default for PList_ {
    fn default() -> Self {
        unsafe { ::std::mem::zeroed() }
    }
}
pub enum PHashTable_ { }
pub type PHashTable = PHashTable_;
pub enum PIniFile_ { }
pub type PIniFile = PIniFile_;
pub enum PLibraryLoader_ { }
pub type PLibraryLoader = PLibraryLoader_;
pub type PFuncAddr = ::std::option::Option<extern "C" fn()>;
#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct PMemVTable_ {
    pub malloc: ::std::option::Option<extern "C" fn(n_bytes: psize) -> ppointer>,
    pub realloc: ::std::option::Option<extern "C" fn(mem: ppointer, n_bytes: psize) -> ppointer>,
    pub free: ::std::option::Option<extern "C" fn(mem: ppointer)>,
}
impl ::std::default::Default for PMemVTable_ {
    fn default() -> Self {
        unsafe { ::std::mem::zeroed() }
    }
}
pub type PMemVTable = PMemVTable_;
pub enum PRWLock_ { }
pub type PRWLock = PRWLock_;
#[derive(Copy, Clone)]
#[repr(u32)]
#[derive(Debug)]
pub enum PSemaphoreAccessMode_ {
    P_SEM_ACCESS_OPEN = 0,
    P_SEM_ACCESS_CREATE = 1,
}
pub type PSemaphoreAccessMode = PSemaphoreAccessMode_;
pub enum PSemaphore_ { }
pub type PSemaphore = PSemaphore_;
#[derive(Copy, Clone)]
#[repr(u32)]
#[derive(Debug)]
pub enum PShmAccessPerms_ {
    P_SHM_ACCESS_READONLY = 0,
    P_SHM_ACCESS_READWRITE = 1,
}
pub type PShmAccessPerms = PShmAccessPerms_;
pub enum PShm_ { }
pub type PShm = PShm_;
pub enum PShmBuffer_ { }
pub type PShmBuffer = PShmBuffer_;
pub type u_char = __u_char;
pub type u_short = __u_short;
pub type u_int = __u_int;
pub type u_long = __u_long;
pub type quad_t = __quad_t;
pub type u_quad_t = __u_quad_t;
pub type fsid_t = __fsid_t;
pub type loff_t = __loff_t;
pub type ino_t = __ino_t;
pub type dev_t = __dev_t;
pub type gid_t = __gid_t;
pub type mode_t = __mode_t;
pub type nlink_t = __nlink_t;
pub type uid_t = __uid_t;
pub type pid_t = __pid_t;
pub type id_t = __id_t;
pub type daddr_t = __daddr_t;
pub type caddr_t = __caddr_t;
pub type key_t = __key_t;
pub type ulong = ::std::os::raw::c_ulong;
pub type ushort = ::std::os::raw::c_ushort;
pub type uint_ = ::std::os::raw::c_uint;
pub type int8_t = i8;
pub type int16_t = i16;
pub type int32_t = i32;
pub type int64_t = i64;
pub type u_int8_t = ::std::os::raw::c_uchar;
pub type u_int16_t = ::std::os::raw::c_ushort;
pub type u_int32_t = ::std::os::raw::c_uint;
pub type u_int64_t = ::std::os::raw::c_ulong;
pub type register_t = ::std::os::raw::c_long;
pub type blksize_t = __blksize_t;
pub type blkcnt_t = __blkcnt_t;
pub type fsblkcnt_t = __fsblkcnt_t;
pub type fsfilcnt_t = __fsfilcnt_t;
pub type pthread_t = ::std::os::raw::c_ulong;
#[repr(C)]
#[derive(Copy)]
pub struct pthread_attr_t {
    pub _bindgen_data_: [u64; 7usize],
}
impl pthread_attr_t {
    pub unsafe fn __size(&mut self) -> *mut [::std::os::raw::c_char; 56usize] {
        let raw: *mut u8 = ::std::mem::transmute(&self._bindgen_data_);
        ::std::mem::transmute(raw.offset(0))
    }
    pub unsafe fn __align(&mut self) -> *mut ::std::os::raw::c_long {
        let raw: *mut u8 = ::std::mem::transmute(&self._bindgen_data_);
        ::std::mem::transmute(raw.offset(0))
    }
}
impl ::std::clone::Clone for pthread_attr_t {
    fn clone(&self) -> Self {
        *self
    }
}
impl ::std::default::Default for pthread_attr_t {
    fn default() -> Self {
        unsafe { ::std::mem::zeroed() }
    }
}
#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct __pthread_internal_list {
    pub __prev: *mut __pthread_internal_list,
    pub __next: *mut __pthread_internal_list,
}
impl ::std::default::Default for __pthread_internal_list {
    fn default() -> Self {
        unsafe { ::std::mem::zeroed() }
    }
}
pub type __pthread_list_t = __pthread_internal_list;
#[repr(C)]
#[derive(Copy)]
pub struct pthread_mutex_t {
    pub _bindgen_data_: [u64; 5usize],
}
impl pthread_mutex_t {
    pub unsafe fn __data(&mut self) -> *mut __pthread_mutex_s {
        let raw: *mut u8 = ::std::mem::transmute(&self._bindgen_data_);
        ::std::mem::transmute(raw.offset(0))
    }
    pub unsafe fn __size(&mut self) -> *mut [::std::os::raw::c_char; 40usize] {
        let raw: *mut u8 = ::std::mem::transmute(&self._bindgen_data_);
        ::std::mem::transmute(raw.offset(0))
    }
    pub unsafe fn __align(&mut self) -> *mut ::std::os::raw::c_long {
        let raw: *mut u8 = ::std::mem::transmute(&self._bindgen_data_);
        ::std::mem::transmute(raw.offset(0))
    }
}
impl ::std::clone::Clone for pthread_mutex_t {
    fn clone(&self) -> Self {
        *self
    }
}
impl ::std::default::Default for pthread_mutex_t {
    fn default() -> Self {
        unsafe { ::std::mem::zeroed() }
    }
}
#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct __pthread_mutex_s {
    pub __lock: ::std::os::raw::c_int,
    pub __count: ::std::os::raw::c_uint,
    pub __owner: ::std::os::raw::c_int,
    pub __nusers: ::std::os::raw::c_uint,
    pub __kind: ::std::os::raw::c_int,
    pub __spins: ::std::os::raw::c_short,
    pub __elision: ::std::os::raw::c_short,
    pub __list: __pthread_list_t,
}
impl ::std::default::Default for __pthread_mutex_s {
    fn default() -> Self {
        unsafe { ::std::mem::zeroed() }
    }
}
#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct pthread_mutexattr_t {
    pub _bindgen_data_: [u32; 1usize],
}
impl pthread_mutexattr_t {
    pub unsafe fn __size(&mut self) -> *mut [::std::os::raw::c_char; 4usize] {
        let raw: *mut u8 = ::std::mem::transmute(&self._bindgen_data_);
        ::std::mem::transmute(raw.offset(0))
    }
    pub unsafe fn __align(&mut self) -> *mut ::std::os::raw::c_int {
        let raw: *mut u8 = ::std::mem::transmute(&self._bindgen_data_);
        ::std::mem::transmute(raw.offset(0))
    }
}
impl ::std::default::Default for pthread_mutexattr_t {
    fn default() -> Self {
        unsafe { ::std::mem::zeroed() }
    }
}
#[repr(C)]
#[derive(Copy)]
pub struct pthread_cond_t {
    pub _bindgen_data_: [u64; 6usize],
}
impl pthread_cond_t {
    pub unsafe fn __data(&mut self) -> *mut Struct_Unnamed1 {
        let raw: *mut u8 = ::std::mem::transmute(&self._bindgen_data_);
        ::std::mem::transmute(raw.offset(0))
    }
    pub unsafe fn __size(&mut self) -> *mut [::std::os::raw::c_char; 48usize] {
        let raw: *mut u8 = ::std::mem::transmute(&self._bindgen_data_);
        ::std::mem::transmute(raw.offset(0))
    }
    pub unsafe fn __align(&mut self) -> *mut ::std::os::raw::c_longlong {
        let raw: *mut u8 = ::std::mem::transmute(&self._bindgen_data_);
        ::std::mem::transmute(raw.offset(0))
    }
}
impl ::std::clone::Clone for pthread_cond_t {
    fn clone(&self) -> Self {
        *self
    }
}
impl ::std::default::Default for pthread_cond_t {
    fn default() -> Self {
        unsafe { ::std::mem::zeroed() }
    }
}
#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct Struct_Unnamed1 {
    pub __lock: ::std::os::raw::c_int,
    pub __futex: ::std::os::raw::c_uint,
    pub __total_seq: ::std::os::raw::c_ulonglong,
    pub __wakeup_seq: ::std::os::raw::c_ulonglong,
    pub __woken_seq: ::std::os::raw::c_ulonglong,
    pub __mutex: *mut ::std::os::raw::c_void,
    pub __nwaiters: ::std::os::raw::c_uint,
    pub __broadcast_seq: ::std::os::raw::c_uint,
}
impl ::std::default::Default for Struct_Unnamed1 {
    fn default() -> Self {
        unsafe { ::std::mem::zeroed() }
    }
}
#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct pthread_condattr_t {
    pub _bindgen_data_: [u32; 1usize],
}
impl pthread_condattr_t {
    pub unsafe fn __size(&mut self) -> *mut [::std::os::raw::c_char; 4usize] {
        let raw: *mut u8 = ::std::mem::transmute(&self._bindgen_data_);
        ::std::mem::transmute(raw.offset(0))
    }
    pub unsafe fn __align(&mut self) -> *mut ::std::os::raw::c_int {
        let raw: *mut u8 = ::std::mem::transmute(&self._bindgen_data_);
        ::std::mem::transmute(raw.offset(0))
    }
}
impl ::std::default::Default for pthread_condattr_t {
    fn default() -> Self {
        unsafe { ::std::mem::zeroed() }
    }
}
pub type pthread_key_t = ::std::os::raw::c_uint;
pub type pthread_once_t = ::std::os::raw::c_int;
#[repr(C)]
#[derive(Copy)]
pub struct pthread_rwlock_t {
    pub _bindgen_data_: [u64; 7usize],
}
impl pthread_rwlock_t {
    pub unsafe fn __data(&mut self) -> *mut Struct_Unnamed2 {
        let raw: *mut u8 = ::std::mem::transmute(&self._bindgen_data_);
        ::std::mem::transmute(raw.offset(0))
    }
    pub unsafe fn __size(&mut self) -> *mut [::std::os::raw::c_char; 56usize] {
        let raw: *mut u8 = ::std::mem::transmute(&self._bindgen_data_);
        ::std::mem::transmute(raw.offset(0))
    }
    pub unsafe fn __align(&mut self) -> *mut ::std::os::raw::c_long {
        let raw: *mut u8 = ::std::mem::transmute(&self._bindgen_data_);
        ::std::mem::transmute(raw.offset(0))
    }
}
impl ::std::clone::Clone for pthread_rwlock_t {
    fn clone(&self) -> Self {
        *self
    }
}
impl ::std::default::Default for pthread_rwlock_t {
    fn default() -> Self {
        unsafe { ::std::mem::zeroed() }
    }
}
#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct Struct_Unnamed2 {
    pub __lock: ::std::os::raw::c_int,
    pub __nr_readers: ::std::os::raw::c_uint,
    pub __readers_wakeup: ::std::os::raw::c_uint,
    pub __writer_wakeup: ::std::os::raw::c_uint,
    pub __nr_readers_queued: ::std::os::raw::c_uint,
    pub __nr_writers_queued: ::std::os::raw::c_uint,
    pub __writer: ::std::os::raw::c_int,
    pub __shared: ::std::os::raw::c_int,
    pub __pad1: ::std::os::raw::c_ulong,
    pub __pad2: ::std::os::raw::c_ulong,
    pub __flags: ::std::os::raw::c_uint,
    _bindgen_padding_0_: [u8; 4usize],
}
impl ::std::default::Default for Struct_Unnamed2 {
    fn default() -> Self {
        unsafe { ::std::mem::zeroed() }
    }
}
#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct pthread_rwlockattr_t {
    pub _bindgen_data_: [u64; 1usize],
}
impl pthread_rwlockattr_t {
    pub unsafe fn __size(&mut self) -> *mut [::std::os::raw::c_char; 8usize] {
        let raw: *mut u8 = ::std::mem::transmute(&self._bindgen_data_);
        ::std::mem::transmute(raw.offset(0))
    }
    pub unsafe fn __align(&mut self) -> *mut ::std::os::raw::c_long {
        let raw: *mut u8 = ::std::mem::transmute(&self._bindgen_data_);
        ::std::mem::transmute(raw.offset(0))
    }
}
impl ::std::default::Default for pthread_rwlockattr_t {
    fn default() -> Self {
        unsafe { ::std::mem::zeroed() }
    }
}
pub type pthread_spinlock_t = ::std::os::raw::c_int;
#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct pthread_barrier_t {
    pub _bindgen_data_: [u64; 4usize],
}
impl pthread_barrier_t {
    pub unsafe fn __size(&mut self) -> *mut [::std::os::raw::c_char; 32usize] {
        let raw: *mut u8 = ::std::mem::transmute(&self._bindgen_data_);
        ::std::mem::transmute(raw.offset(0))
    }
    pub unsafe fn __align(&mut self) -> *mut ::std::os::raw::c_long {
        let raw: *mut u8 = ::std::mem::transmute(&self._bindgen_data_);
        ::std::mem::transmute(raw.offset(0))
    }
}
impl ::std::default::Default for pthread_barrier_t {
    fn default() -> Self {
        unsafe { ::std::mem::zeroed() }
    }
}
#[repr(C)]
#[derive(Copy, Clone)]
#[derive(Debug)]
pub struct pthread_barrierattr_t {
    pub _bindgen_data_: [u32; 1usize],
}
impl pthread_barrierattr_t {
    pub unsafe fn __size(&mut self) -> *mut [::std::os::raw::c_char; 4usize] {
        let raw: *mut u8 = ::std::mem::transmute(&self._bindgen_data_);
        ::std::mem::transmute(raw.offset(0))
    }
    pub unsafe fn __align(&mut self) -> *mut ::std::os::raw::c_int {
        let raw: *mut u8 = ::std::mem::transmute(&self._bindgen_data_);
        ::std::mem::transmute(raw.offset(0))
    }
}
impl ::std::default::Default for pthread_barrierattr_t {
    fn default() -> Self {
        unsafe { ::std::mem::zeroed() }
    }
}
#[derive(Copy, Clone)]
#[repr(u32)]
#[derive(Debug)]
pub enum __socket_type {
    SOCK_STREAM = 1,
    SOCK_DGRAM = 2,
    SOCK_RAW = 3,
    SOCK_RDM = 4,
    SOCK_SEQPACKET = 5,
    SOCK_DCCP = 6,
    SOCK_PACKET = 10,
    SOCK_CLOEXEC = 524288,
    SOCK_NONBLOCK = 2048,
}
#[derive(Copy, Clone)]
#[repr(u32)]
#[derive(Debug)]
pub enum PSocketFamily_ {
    P_SOCKET_FAMILY_UNKNOWN = 0,
    P_SOCKET_FAMILY_INET = 2,
    P_SOCKET_FAMILY_INET6 = 10,
}
pub type PSocketFamily = PSocketFamily_;
pub enum PSocketAddress_ { }
pub type PSocketAddress = PSocketAddress_;
#[derive(Copy, Clone)]
#[repr(i32)]
#[derive(Debug)]
pub enum PSocketProtocol_ {
    P_SOCKET_PROTOCOL_UNKNOWN = -1,
    P_SOCKET_PROTOCOL_DEFAULT = 0,
    P_SOCKET_PROTOCOL_TCP = 6,
    P_SOCKET_PROTOCOL_UDP = 17,
    P_SOCKET_PROTOCOL_SCTP = 132,
}
pub type PSocketProtocol = PSocketProtocol_;
#[derive(Copy, Clone)]
#[repr(u32)]
#[derive(Debug)]
pub enum PSocketType_ {
    P_SOCKET_TYPE_UNKNOWN = 0,
    P_SOCKET_TYPE_STREAM = 1,
    P_SOCKET_TYPE_DATAGRAM = 2,
    P_SOCKET_TYPE_SEQPACKET = 3,
}
pub type PSocketType = PSocketType_;
#[derive(Copy, Clone)]
#[repr(u32)]
#[derive(Debug)]
pub enum PSocketDirection_ {
    P_SOCKET_DIRECTION_SND = 0,
    P_SOCKET_DIRECTION_RCV = 1,
}
pub type PSocketDirection = PSocketDirection_;
#[derive(Copy, Clone)]
#[repr(u32)]
#[derive(Debug)]
pub enum PSocketIOCondition_ {
    P_SOCKET_IO_CONDITION_POLLIN = 1,
    P_SOCKET_IO_CONDITION_POLLOUT = 2,
}
pub type PSocketIOCondition = PSocketIOCondition_;
pub enum PSocket_ { }
pub type PSocket = PSocket_;
pub enum PSpinLock_ { }
pub type PSpinLock = PSpinLock_;
pub enum PTimeProfiler_ { }
pub type PTimeProfiler = PTimeProfiler_;
pub enum PTree_ { }
pub type PTree = PTree_;
#[derive(Copy, Clone)]
#[repr(u32)]
#[derive(Debug)]
pub enum PTreeType_ {
    P_TREE_TYPE_BINARY = 0,
    P_TREE_TYPE_RB = 1,
    P_TREE_TYPE_AVL = 2,
}
pub type PTreeType = PTreeType_;
pub type PUThreadFunc = ::std::option::Option<extern "C" fn(arg: ppointer) -> ppointer>;
pub enum PUThread_ { }
pub type PUThread = PUThread_;
pub enum PUThreadKey_ { }
pub type PUThreadKey = PUThreadKey_;
#[derive(Copy, Clone)]
#[repr(u32)]
#[derive(Debug)]
pub enum PUThreadPriority_ {
    P_UTHREAD_PRIORITY_INHERIT = 0,
    P_UTHREAD_PRIORITY_IDLE = 1,
    P_UTHREAD_PRIORITY_LOWEST = 2,
    P_UTHREAD_PRIORITY_LOW = 3,
    P_UTHREAD_PRIORITY_NORMAL = 4,
    P_UTHREAD_PRIORITY_HIGH = 5,
    P_UTHREAD_PRIORITY_HIGHEST = 6,
    P_UTHREAD_PRIORITY_TIMECRITICAL = 7,
}
pub type PUThreadPriority = PUThreadPriority_;
extern "C" {
    pub fn p_atomic_int_get(atomic: *const pint) -> pint;
    pub fn p_atomic_int_set(atomic: *mut pint, val: pint);
    pub fn p_atomic_int_inc(atomic: *mut pint);
    pub fn p_atomic_int_dec_and_test(atomic: *mut pint) -> pboolean;
    pub fn p_atomic_int_compare_and_exchange(atomic: *mut pint,
                                             oldval: pint,
                                             newval: pint)
                                             -> pboolean;
    pub fn p_atomic_int_add(atomic: *mut pint, val: pint) -> pint;
    pub fn p_atomic_int_and(atomic: *mut puint, val: puint) -> puint;
    pub fn p_atomic_int_or(atomic: *mut puint, val: puint) -> puint;
    pub fn p_atomic_int_xor(atomic: *mut puint, val: puint) -> puint;
    pub fn p_atomic_pointer_get(atomic: *const ::std::os::raw::c_void) -> ppointer;
    pub fn p_atomic_pointer_set(atomic: *mut ::std::os::raw::c_void, val: ppointer);
    pub fn p_atomic_pointer_compare_and_exchange(atomic: *mut ::std::os::raw::c_void,
                                                 oldval: ppointer,
                                                 newval: ppointer)
                                                 -> pboolean;
    pub fn p_atomic_pointer_add(atomic: *mut ::std::os::raw::c_void, val: pssize) -> pssize;
    pub fn p_atomic_pointer_and(atomic: *mut ::std::os::raw::c_void, val: psize) -> psize;
    pub fn p_atomic_pointer_or(atomic: *mut ::std::os::raw::c_void, val: psize) -> psize;
    pub fn p_atomic_pointer_xor(atomic: *mut ::std::os::raw::c_void, val: psize) -> psize;
    pub fn p_atomic_is_lock_free() -> pboolean;
    pub fn p_mutex_new() -> *mut PMutex;
    pub fn p_mutex_lock(mutex: *mut PMutex) -> pboolean;
    pub fn p_mutex_trylock(mutex: *mut PMutex) -> pboolean;
    pub fn p_mutex_unlock(mutex: *mut PMutex) -> pboolean;
    pub fn p_mutex_free(mutex: *mut PMutex);
    pub fn p_cond_variable_new() -> *mut PCondVariable;
    pub fn p_cond_variable_free(cond: *mut PCondVariable);
    pub fn p_cond_variable_wait(cond: *mut PCondVariable, mutex: *mut PMutex) -> pboolean;
    pub fn p_cond_variable_signal(cond: *mut PCondVariable) -> pboolean;
    pub fn p_cond_variable_broadcast(cond: *mut PCondVariable) -> pboolean;
    pub fn p_crypto_hash_new(type_: PCryptoHashType) -> *mut PCryptoHash;
    pub fn p_crypto_hash_update(hash: *mut PCryptoHash, data: *const puchar, len: psize);
    pub fn p_crypto_hash_reset(hash: *mut PCryptoHash);
    pub fn p_crypto_hash_get_string(hash: *mut PCryptoHash) -> *mut pchar;
    pub fn p_crypto_hash_get_digest(hash: *mut PCryptoHash, buf: *mut puchar, len: *mut psize);
    pub fn p_crypto_hash_get_length(hash: *const PCryptoHash) -> pssize;
    pub fn p_crypto_hash_get_type(hash: *const PCryptoHash) -> PCryptoHashType;
    pub fn p_crypto_hash_free(hash: *mut PCryptoHash);
    pub fn p_error_new() -> *mut PError;
    pub fn p_error_new_literal(code: pint,
                               native_code: pint,
                               message: *const pchar)
                               -> *mut PError;
    pub fn p_error_get_message(error: *mut PError) -> *const pchar;
    pub fn p_error_get_code(error: *mut PError) -> pint;
    pub fn p_error_get_native_code(error: *mut PError) -> pint;
    pub fn p_error_get_domain(error: *mut PError) -> PErrorDomain;
    pub fn p_error_copy(error: *mut PError) -> *mut PError;
    pub fn p_error_set_error(error: *mut PError,
                             code: pint,
                             native_code: pint,
                             message: *const pchar);
    pub fn p_error_set_error_p(error: *mut *mut PError,
                               code: pint,
                               native_code: pint,
                               message: *const pchar);
    pub fn p_error_set_code(error: *mut PError, code: pint);
    pub fn p_error_set_native_code(error: *mut PError, native_code: pint);
    pub fn p_error_set_message(error: *mut PError, message: *const pchar);
    pub fn p_error_clear(error: *mut PError);
    pub fn p_error_free(error: *mut PError);
    pub fn p_dir_new(path: *const pchar, error: *mut *mut PError) -> *mut PDir;
    pub fn p_dir_create(path: *const pchar, mode: pint, error: *mut *mut PError) -> pboolean;
    pub fn p_dir_remove(path: *const pchar, error: *mut *mut PError) -> pboolean;
    pub fn p_dir_is_exists(path: *const pchar) -> pboolean;
    pub fn p_dir_get_path(dir: *const PDir) -> *mut pchar;
    pub fn p_dir_get_next_entry(dir: *mut PDir, error: *mut *mut PError) -> *mut PDirEntry;
    pub fn p_dir_rewind(dir: *mut PDir, error: *mut *mut PError) -> pboolean;
    pub fn p_dir_entry_free(entry: *mut PDirEntry);
    pub fn p_dir_free(dir: *mut PDir);
    pub fn p_file_is_exists(file: *const pchar) -> pboolean;
    pub fn p_file_remove(file: *const pchar, error: *mut *mut PError) -> pboolean;
    pub fn p_list_append(list: *mut PList, data: ppointer) -> *mut PList;
    pub fn p_list_remove(list: *mut PList, data: ppointer) -> *mut PList;
    pub fn p_list_foreach(list: *mut PList, func: PFunc, user_data: ppointer);
    pub fn p_list_free(list: *mut PList);
    pub fn p_list_last(list: *mut PList) -> *mut PList;
    pub fn p_list_length(list: *const PList) -> psize;
    pub fn p_list_prepend(list: *mut PList, data: ppointer) -> *mut PList;
    pub fn p_list_reverse(list: *mut PList) -> *mut PList;
    pub fn p_hash_table_new() -> *mut PHashTable;
    pub fn p_hash_table_insert(table: *mut PHashTable, key: ppointer, value: ppointer);
    pub fn p_hash_table_lookup(table: *const PHashTable, key: pconstpointer) -> ppointer;
    pub fn p_hash_table_keys(table: *const PHashTable) -> *mut PList;
    pub fn p_hash_table_values(table: *const PHashTable) -> *mut PList;
    pub fn p_hash_table_free(table: *mut PHashTable);
    pub fn p_hash_table_remove(table: *mut PHashTable, key: pconstpointer);
    pub fn p_hash_table_lookup_by_value(table: *const PHashTable,
                                        val: pconstpointer,
                                        func: PCompareFunc)
                                        -> *mut PList;
    pub fn p_ini_file_new(path: *const pchar) -> *mut PIniFile;
    pub fn p_ini_file_free(file: *mut PIniFile);
    pub fn p_ini_file_parse(file: *mut PIniFile, error: *mut *mut PError) -> pboolean;
    pub fn p_ini_file_is_parsed(file: *const PIniFile) -> pboolean;
    pub fn p_ini_file_sections(file: *const PIniFile) -> *mut PList;
    pub fn p_ini_file_keys(file: *const PIniFile, section: *const pchar) -> *mut PList;
    pub fn p_ini_file_is_key_exists(file: *const PIniFile,
                                    section: *const pchar,
                                    key: *const pchar)
                                    -> pboolean;
    pub fn p_ini_file_parameter_string(file: *const PIniFile,
                                       section: *const pchar,
                                       key: *const pchar,
                                       default_val: *const pchar)
                                       -> *mut pchar;
    pub fn p_ini_file_parameter_int(file: *const PIniFile,
                                    section: *const pchar,
                                    key: *const pchar,
                                    default_val: pint)
                                    -> pint;
    pub fn p_ini_file_parameter_double(file: *const PIniFile,
                                       section: *const pchar,
                                       key: *const pchar,
                                       default_val: ::std::os::raw::c_double)
                                       -> ::std::os::raw::c_double;
    pub fn p_ini_file_parameter_boolean(file: *const PIniFile,
                                        section: *const pchar,
                                        key: *const pchar,
                                        default_val: pboolean)
                                        -> pboolean;
    pub fn p_ini_file_parameter_list(file: *const PIniFile,
                                     section: *const pchar,
                                     key: *const pchar)
                                     -> *mut PList;
    pub fn p_library_loader_new(path: *const pchar) -> *mut PLibraryLoader;
    pub fn p_library_loader_get_symbol(loader: *mut PLibraryLoader,
                                       sym: *const pchar)
                                       -> PFuncAddr;
    pub fn p_library_loader_free(loader: *mut PLibraryLoader);
    pub fn p_library_loader_get_last_error() -> *mut pchar;
    pub fn p_malloc(n_bytes: psize) -> ppointer;
    pub fn p_malloc0(n_bytes: psize) -> ppointer;
    pub fn p_realloc(mem: ppointer, n_bytes: psize) -> ppointer;
    pub fn p_free(mem: ppointer);
    pub fn p_mem_set_vtable(table: *const PMemVTable) -> pboolean;
    pub fn p_mem_restore_vtable();
    pub fn p_mem_mmap(n_bytes: psize, error: *mut *mut PError) -> ppointer;
    pub fn p_mem_munmap(mem: ppointer, n_bytes: psize, error: *mut *mut PError) -> pboolean;
    pub fn p_libsys_init();
    pub fn p_libsys_init_full(vtable: *const PMemVTable);
    pub fn p_libsys_shutdown();
    pub fn p_libsys_version() -> *const pchar;
    pub fn p_process_get_current_pid() -> puint32;
    pub fn p_process_is_running(pid: puint32) -> pboolean;
    pub fn p_rwlock_new() -> *mut PRWLock;
    pub fn p_rwlock_reader_lock(lock: *mut PRWLock) -> pboolean;
    pub fn p_rwlock_reader_trylock(lock: *mut PRWLock) -> pboolean;
    pub fn p_rwlock_reader_unlock(lock: *mut PRWLock) -> pboolean;
    pub fn p_rwlock_writer_lock(lock: *mut PRWLock) -> pboolean;
    pub fn p_rwlock_writer_trylock(lock: *mut PRWLock) -> pboolean;
    pub fn p_rwlock_writer_unlock(lock: *mut PRWLock) -> pboolean;
    pub fn p_rwlock_free(lock: *mut PRWLock);
    pub fn p_semaphore_new(name: *const pchar,
                           init_val: pint,
                           mode: PSemaphoreAccessMode,
                           error: *mut *mut PError)
                           -> *mut PSemaphore;
    pub fn p_semaphore_take_ownership(sem: *mut PSemaphore);
    pub fn p_semaphore_acquire(sem: *mut PSemaphore, error: *mut *mut PError) -> pboolean;
    pub fn p_semaphore_release(sem: *mut PSemaphore, error: *mut *mut PError) -> pboolean;
    pub fn p_semaphore_free(sem: *mut PSemaphore);
    pub fn p_shm_new(name: *const pchar,
                     size: psize,
                     perms: PShmAccessPerms,
                     error: *mut *mut PError)
                     -> *mut PShm;
    pub fn p_shm_take_ownership(shm: *mut PShm);
    pub fn p_shm_free(shm: *mut PShm);
    pub fn p_shm_lock(shm: *mut PShm, error: *mut *mut PError) -> pboolean;
    pub fn p_shm_unlock(shm: *mut PShm, error: *mut *mut PError) -> pboolean;
    pub fn p_shm_get_address(shm: *const PShm) -> ppointer;
    pub fn p_shm_get_size(shm: *const PShm) -> psize;
    pub fn p_shm_buffer_new(name: *const pchar,
                            size: psize,
                            error: *mut *mut PError)
                            -> *mut PShmBuffer;
    pub fn p_shm_buffer_free(buf: *mut PShmBuffer);
    pub fn p_shm_buffer_take_ownership(buf: *mut PShmBuffer);
    pub fn p_shm_buffer_read(buf: *mut PShmBuffer,
                             storage: ppointer,
                             len: psize,
                             error: *mut *mut PError)
                             -> pint;
    pub fn p_shm_buffer_write(buf: *mut PShmBuffer,
                              data: ppointer,
                              len: psize,
                              error: *mut *mut PError)
                              -> pssize;
    pub fn p_shm_buffer_get_free_space(buf: *mut PShmBuffer, error: *mut *mut PError) -> pssize;
    pub fn p_shm_buffer_get_used_space(buf: *mut PShmBuffer, error: *mut *mut PError) -> pssize;
    pub fn p_shm_buffer_clear(buf: *mut PShmBuffer);
    pub fn p_socket_address_new_from_native(native: pconstpointer,
                                            len: psize)
                                            -> *mut PSocketAddress;
    pub fn p_socket_address_new(address: *const pchar, port: puint16) -> *mut PSocketAddress;
    pub fn p_socket_address_new_any(family: PSocketFamily, port: puint16) -> *mut PSocketAddress;
    pub fn p_socket_address_new_loopback(family: PSocketFamily,
                                         port: puint16)
                                         -> *mut PSocketAddress;
    pub fn p_socket_address_to_native(addr: *const PSocketAddress,
                                      dest: ppointer,
                                      destlen: psize)
                                      -> pboolean;
    pub fn p_socket_address_get_native_size(addr: *const PSocketAddress) -> psize;
    pub fn p_socket_address_get_family(addr: *const PSocketAddress) -> PSocketFamily;
    pub fn p_socket_address_get_address(addr: *const PSocketAddress) -> *mut pchar;
    pub fn p_socket_address_get_port(addr: *const PSocketAddress) -> puint16;
    pub fn p_socket_address_get_flow_info(addr: *const PSocketAddress) -> puint32;
    pub fn p_socket_address_get_scope_id(addr: *const PSocketAddress) -> puint32;
    pub fn p_socket_address_set_flow_info(addr: *mut PSocketAddress, flowinfo: puint32);
    pub fn p_socket_address_set_scope_id(addr: *mut PSocketAddress, scope_id: puint32);
    pub fn p_socket_address_is_flow_info_supported() -> pboolean;
    pub fn p_socket_address_is_scope_id_supported() -> pboolean;
    pub fn p_socket_address_is_any(addr: *const PSocketAddress) -> pboolean;
    pub fn p_socket_address_is_loopback(addr: *const PSocketAddress) -> pboolean;
    pub fn p_socket_address_free(addr: *mut PSocketAddress);
    pub fn p_socket_new_from_fd(fd: pint, error: *mut *mut PError) -> *mut PSocket;
    pub fn p_socket_new(family: PSocketFamily,
                        type_: PSocketType,
                        protocol: PSocketProtocol,
                        error: *mut *mut PError)
                        -> *mut PSocket;
    pub fn p_socket_get_fd(socket: *const PSocket) -> pint;
    pub fn p_socket_get_family(socket: *const PSocket) -> PSocketFamily;
    pub fn p_socket_get_type(socket: *const PSocket) -> PSocketType;
    pub fn p_socket_get_protocol(socket: *const PSocket) -> PSocketProtocol;
    pub fn p_socket_get_keepalive(socket: *const PSocket) -> pboolean;
    pub fn p_socket_get_blocking(socket: *mut PSocket) -> pboolean;
    pub fn p_socket_get_listen_backlog(socket: *const PSocket) -> pint;
    pub fn p_socket_get_timeout(socket: *const PSocket) -> pint;
    pub fn p_socket_get_local_address(socket: *const PSocket,
                                      error: *mut *mut PError)
                                      -> *mut PSocketAddress;
    pub fn p_socket_get_remote_address(socket: *const PSocket,
                                       error: *mut *mut PError)
                                       -> *mut PSocketAddress;
    pub fn p_socket_is_connected(socket: *const PSocket) -> pboolean;
    pub fn p_socket_is_closed(socket: *const PSocket) -> pboolean;
    pub fn p_socket_check_connect_result(socket: *mut PSocket,
                                         error: *mut *mut PError)
                                         -> pboolean;
    pub fn p_socket_set_keepalive(socket: *mut PSocket, keepalive: pboolean);
    pub fn p_socket_set_blocking(socket: *mut PSocket, blocking: pboolean);
    pub fn p_socket_set_listen_backlog(socket: *mut PSocket, backlog: pint);
    pub fn p_socket_set_timeout(socket: *mut PSocket, timeout: pint);
    pub fn p_socket_bind(socket: *const PSocket,
                         address: *mut PSocketAddress,
                         allow_reuse: pboolean,
                         error: *mut *mut PError)
                         -> pboolean;
    pub fn p_socket_connect(socket: *mut PSocket,
                            address: *mut PSocketAddress,
                            error: *mut *mut PError)
                            -> pboolean;
    pub fn p_socket_listen(socket: *mut PSocket, error: *mut *mut PError) -> pboolean;
    pub fn p_socket_accept(socket: *const PSocket, error: *mut *mut PError) -> *mut PSocket;
    pub fn p_socket_receive(socket: *const PSocket,
                            buffer: *mut pchar,
                            buflen: psize,
                            error: *mut *mut PError)
                            -> pssize;
    pub fn p_socket_receive_from(socket: *const PSocket,
                                 address: *mut *mut PSocketAddress,
                                 buffer: *mut pchar,
                                 buflen: psize,
                                 error: *mut *mut PError)
                                 -> pssize;
    pub fn p_socket_send(socket: *const PSocket,
                         buffer: *const pchar,
                         buflen: psize,
                         error: *mut *mut PError)
                         -> pssize;
    pub fn p_socket_send_to(socket: *const PSocket,
                            address: *mut PSocketAddress,
                            buffer: *const pchar,
                            buflen: psize,
                            error: *mut *mut PError)
                            -> pssize;
    pub fn p_socket_close(socket: *mut PSocket, error: *mut *mut PError) -> pboolean;
    pub fn p_socket_shutdown(socket: *mut PSocket,
                             shutdown_read: pboolean,
                             shutdown_write: pboolean,
                             error: *mut *mut PError)
                             -> pboolean;
    pub fn p_socket_free(socket: *mut PSocket);
    pub fn p_socket_set_buffer_size(socket: *const PSocket,
                                    dir: PSocketDirection,
                                    size: psize,
                                    error: *mut *mut PError)
                                    -> pboolean;
    pub fn p_socket_io_condition_wait(socket: *const PSocket,
                                      condition: PSocketIOCondition,
                                      error: *mut *mut PError)
                                      -> pboolean;
    pub fn p_spinlock_new() -> *mut PSpinLock;
    pub fn p_spinlock_lock(spinlock: *mut PSpinLock) -> pboolean;
    pub fn p_spinlock_trylock(spinlock: *mut PSpinLock) -> pboolean;
    pub fn p_spinlock_unlock(spinlock: *mut PSpinLock) -> pboolean;
    pub fn p_spinlock_free(spinlock: *mut PSpinLock);
    pub fn p_strdup(str: *const pchar) -> *mut pchar;
    pub fn p_strchomp(str: *const pchar) -> *mut pchar;
    pub fn p_strtok(str: *mut pchar, delim: *const pchar, buf: *mut *mut pchar) -> *mut pchar;
    pub fn p_strtod(str: *const pchar) -> ::std::os::raw::c_double;
    pub fn p_time_profiler_new() -> *mut PTimeProfiler;
    pub fn p_time_profiler_reset(profiler: *mut PTimeProfiler);
    pub fn p_time_profiler_elapsed_usecs(profiler: *const PTimeProfiler) -> puint64;
    pub fn p_time_profiler_free(profiler: *mut PTimeProfiler);
    pub fn p_tree_new(type_: PTreeType, func: PCompareFunc) -> *mut PTree;
    pub fn p_tree_new_with_data(type_: PTreeType,
                                func: PCompareDataFunc,
                                data: ppointer)
                                -> *mut PTree;
    pub fn p_tree_new_full(type_: PTreeType,
                           func: PCompareDataFunc,
                           data: ppointer,
                           key_destroy: PDestroyFunc,
                           value_destroy: PDestroyFunc)
                           -> *mut PTree;
    pub fn p_tree_insert(tree: *mut PTree, key: ppointer, value: ppointer);
    pub fn p_tree_remove(tree: *mut PTree, key: pconstpointer) -> pboolean;
    pub fn p_tree_lookup(tree: *mut PTree, key: pconstpointer) -> ppointer;
    pub fn p_tree_foreach(tree: *mut PTree, traverse_func: PTraverseFunc, user_data: ppointer);
    pub fn p_tree_clear(tree: *mut PTree);
    pub fn p_tree_get_type(tree: *const PTree) -> PTreeType;
    pub fn p_tree_get_nnodes(tree: *const PTree) -> pint;
    pub fn p_tree_free(tree: *mut PTree);
    pub fn p_uthread_create_full(func: PUThreadFunc,
                                 data: ppointer,
                                 joinable: pboolean,
                                 prio: PUThreadPriority,
                                 stack_size: psize)
                                 -> *mut PUThread;
    pub fn p_uthread_create(func: PUThreadFunc,
                            data: ppointer,
                            joinable: pboolean)
                            -> *mut PUThread;
    pub fn p_uthread_exit(code: pint);
    pub fn p_uthread_join(thread: *mut PUThread) -> pint;
    pub fn p_uthread_sleep(msec: puint32) -> pint;
    pub fn p_uthread_set_priority(thread: *mut PUThread, prio: PUThreadPriority) -> pboolean;
    pub fn p_uthread_yield();
    pub fn p_uthread_current_id() -> P_HANDLE;
    pub fn p_uthread_current() -> *mut PUThread;
    pub fn p_uthread_ref(thread: *mut PUThread);
    pub fn p_uthread_unref(thread: *mut PUThread);
    pub fn p_uthread_local_new(free_func: PDestroyFunc) -> *mut PUThreadKey;
    pub fn p_uthread_local_free(key: *mut PUThreadKey);
    pub fn p_uthread_get_local(key: *mut PUThreadKey) -> ppointer;
    pub fn p_uthread_set_local(key: *mut PUThreadKey, value: ppointer);
    pub fn p_uthread_replace_local(key: *mut PUThreadKey, value: ppointer);
}
