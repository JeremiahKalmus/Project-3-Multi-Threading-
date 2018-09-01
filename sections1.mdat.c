typedef unsigned long size_t;
typedef unsigned char __u_char;
typedef unsigned short __u_short;
typedef unsigned int __u_int;
typedef unsigned long __u_long;
typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short __int16_t;
typedef unsigned short __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;
typedef signed long __int64_t;
typedef unsigned long __uint64_t;
typedef long __quad_t;
typedef unsigned long __u_quad_t;
typedef unsigned long __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long __ino_t;
typedef unsigned long __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long __nlink_t;
typedef long __off_t;
typedef long __off64_t;
typedef int __pid_t;
typedef struct {
  int __val[2];
} __fsid_t;
typedef long __clock_t;
typedef unsigned long __rlim_t;
typedef unsigned long __rlim64_t;
typedef unsigned int __id_t;
typedef long __time_t;
typedef unsigned int __useconds_t;
typedef long __suseconds_t;
typedef int __daddr_t;
typedef int __key_t;
typedef int __clockid_t;
typedef void *__timer_t;
typedef long __blksize_t;
typedef long __blkcnt_t;
typedef long __blkcnt64_t;
typedef unsigned long __fsblkcnt_t;
typedef unsigned long __fsblkcnt64_t;
typedef unsigned long __fsfilcnt_t;
typedef unsigned long __fsfilcnt64_t;
typedef long __fsword_t;
typedef long __ssize_t;
typedef long __syscall_slong_t;
typedef unsigned long __syscall_ulong_t;
typedef __off64_t __loff_t;
typedef __quad_t *__qaddr_t;
typedef char *__caddr_t;
typedef long __intptr_t;
typedef unsigned int __socklen_t;
struct _IO_FILE ;
typedef struct _IO_FILE FILE;
typedef struct _IO_FILE __FILE;
typedef struct {
  int __count;
  union {
    unsigned int __wch;
    char __wchb[4];
  } __value;
} __mbstate_t;
typedef struct {
  __off_t __pos;
  __mbstate_t __state;
} _G_fpos_t;
typedef struct {
  __off64_t __pos;
  __mbstate_t __state;
} _G_fpos64_t;
typedef __builtin_va_list __gnuc_va_list;
struct _IO_jump_t ;
struct _IO_FILE ;
typedef void _IO_lock_t;
struct _IO_marker {
  struct _IO_marker *_next;
  struct _IO_FILE *_sbuf;
  int _pos;
} ;
enum __codecvt_result { __codecvt_ok, __codecvt_partial, __codecvt_error, __codecvt_noconv } ;
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
  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];
  _IO_lock_t *_lock;
  __off64_t _offset;
  void *__pad1;
  void *__pad2;
  void *__pad3;
  void *__pad4;
  size_t __pad5;
  int _mode;
  char _unused2[15 * sizeof(int ) - 4 * sizeof(void *) - sizeof(size_t )];
} ;
typedef struct _IO_FILE _IO_FILE;
struct _IO_FILE_plus ;
extern struct _IO_FILE_plus _IO_2_1_stdin_;
extern struct _IO_FILE_plus _IO_2_1_stdout_;
extern struct _IO_FILE_plus _IO_2_1_stderr_;
typedef __ssize_t __io_read_fn(void *__cookie, char *__buf, size_t __nbytes);
typedef __ssize_t __io_write_fn(void *__cookie, const char *__buf, size_t __n);
typedef int __io_seek_fn(void *__cookie, __off64_t *__pos, int __w);
typedef int __io_close_fn(void *__cookie);
extern int __underflow(_IO_FILE *);
extern int __uflow(_IO_FILE *);
extern int __overflow(_IO_FILE *, int );
extern int _IO_getc(_IO_FILE *__fp);
extern int _IO_putc(int __c, _IO_FILE *__fp);
extern int _IO_feof(_IO_FILE *__fp) __attribute__ ((__nothrow__ , __leaf__));
extern int _IO_ferror(_IO_FILE *__fp) __attribute__ ((__nothrow__ , __leaf__));
extern int _IO_peekc_locked(_IO_FILE *__fp);
extern void _IO_flockfile(_IO_FILE *) __attribute__ ((__nothrow__ , __leaf__));
extern void _IO_funlockfile(_IO_FILE *) __attribute__ ((__nothrow__ , __leaf__));
extern int _IO_ftrylockfile(_IO_FILE *) __attribute__ ((__nothrow__ , __leaf__));
extern int _IO_vfscanf(_IO_FILE *, const char *, __gnuc_va_list , int *);
extern int _IO_vfprintf(_IO_FILE *, const char *, __gnuc_va_list );
extern __ssize_t _IO_padn(_IO_FILE *, int , __ssize_t );
extern size_t _IO_sgetn(_IO_FILE *, void *, size_t );
extern __off64_t _IO_seekoff(_IO_FILE *, __off64_t , int , int );
extern __off64_t _IO_seekpos(_IO_FILE *, __off64_t , int );
extern void _IO_free_backup_area(_IO_FILE *) __attribute__ ((__nothrow__ , __leaf__));
typedef __gnuc_va_list va_list;
typedef __off_t off_t;
typedef __ssize_t ssize_t;
typedef _G_fpos_t fpos_t;
extern struct _IO_FILE *stdin;
extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;
extern int remove(const char *__filename) __attribute__ ((__nothrow__ , __leaf__));
extern int rename(const char *__old, const char *__new) __attribute__ ((__nothrow__ , __leaf__));
extern int renameat(int __oldfd, const char *__old, int __newfd, const char *__new) __attribute__ ((__nothrow__ , __leaf__));
extern FILE *tmpfile();
extern char *tmpnam(char *__s) __attribute__ ((__nothrow__ , __leaf__));
extern char *tmpnam_r(char *__s) __attribute__ ((__nothrow__ , __leaf__));
extern char *tempnam(const char *__dir, const char *__pfx) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__));
extern int fclose(FILE *__stream);
extern int fflush(FILE *__stream);
extern int fflush_unlocked(FILE *__stream);
extern FILE *fopen(const char *__filename, const char *__modes);
extern FILE *freopen(const char *__filename, const char *__modes, FILE *__stream);
extern FILE *fdopen(int __fd, const char *__modes) __attribute__ ((__nothrow__ , __leaf__));
extern FILE *fmemopen(void *__s, size_t __len, const char *__modes) __attribute__ ((__nothrow__ , __leaf__));
extern FILE *open_memstream(char **__bufloc, size_t *__sizeloc) __attribute__ ((__nothrow__ , __leaf__));
extern void setbuf(FILE *__stream, char *__buf) __attribute__ ((__nothrow__ , __leaf__));
extern int setvbuf(FILE *__stream, char *__buf, int __modes, size_t __n) __attribute__ ((__nothrow__ , __leaf__));
extern void setbuffer(FILE *__stream, char *__buf, size_t __size) __attribute__ ((__nothrow__ , __leaf__));
extern void setlinebuf(FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int fprintf(FILE *__stream, const char *__format, ...);
extern int printf(const char *__format, ...);
extern int sprintf(char *__s, const char *__format, ...) __attribute__ ((__nothrow__));
extern int vfprintf(FILE *__s, const char *__format, __gnuc_va_list __arg);
extern int vprintf(const char *__format, __gnuc_va_list __arg);
extern int vsprintf(char *__s, const char *__format, __gnuc_va_list __arg) __attribute__ ((__nothrow__));
extern int snprintf(char *__s, size_t __maxlen, const char *__format, ...) __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 4)));
extern int vsnprintf(char *__s, size_t __maxlen, const char *__format, __gnuc_va_list __arg) __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 0)));
extern int vdprintf(int __fd, const char *__fmt, __gnuc_va_list __arg) __attribute__ ((__format__ (__printf__, 2, 0)));
extern int dprintf(int __fd, const char *__fmt, ...) __attribute__ ((__format__ (__printf__, 2, 3)));
extern int fscanf(FILE *__stream, const char *__format, ...);
extern int scanf(const char *__format, ...);
extern int sscanf(const char *__s, const char *__format, ...) __attribute__ ((__nothrow__ , __leaf__));
extern int fscanf(FILE *__stream, const char *__format, ...) __asm__  ("" "__isoc99_fscanf");
extern int scanf(const char *__format, ...) __asm__  ("" "__isoc99_scanf");
extern int sscanf(const char *__s, const char *__format, ...) __asm__  ("" "__isoc99_sscanf") __attribute__ ((__nothrow__ , __leaf__));
extern int vfscanf(FILE *__s, const char *__format, __gnuc_va_list __arg) __attribute__ ((__format__ (__scanf__, 2, 0)));
extern int vscanf(const char *__format, __gnuc_va_list __arg) __attribute__ ((__format__ (__scanf__, 1, 0)));
extern int vsscanf(const char *__s, const char *__format, __gnuc_va_list __arg) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__format__ (__scanf__, 2, 0)));
extern int vfscanf(FILE *__s, const char *__format, __gnuc_va_list __arg) __asm__  ("" "__isoc99_vfscanf") __attribute__ ((__format__ (__scanf__, 2, 0)));
extern int vscanf(const char *__format, __gnuc_va_list __arg) __asm__  ("" "__isoc99_vscanf") __attribute__ ((__format__ (__scanf__, 1, 0)));
extern int vsscanf(const char *__s, const char *__format, __gnuc_va_list __arg) __asm__  ("" "__isoc99_vsscanf") __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__format__ (__scanf__, 2, 0)));
extern int fgetc(FILE *__stream);
extern int getc(FILE *__stream);
extern int getchar();
extern int getc_unlocked(FILE *__stream);
extern int getchar_unlocked();
extern int fgetc_unlocked(FILE *__stream);
extern int fputc(int __c, FILE *__stream);
extern int putc(int __c, FILE *__stream);
extern int putchar(int __c);
extern int fputc_unlocked(int __c, FILE *__stream);
extern int putc_unlocked(int __c, FILE *__stream);
extern int putchar_unlocked(int __c);
extern int getw(FILE *__stream);
extern int putw(int __w, FILE *__stream);
extern char *fgets(char *__s, int __n, FILE *__stream);
extern char *gets(char *__s) __attribute__ ((__deprecated__));
extern __ssize_t __getdelim(char **__lineptr, size_t *__n, int __delimiter, FILE *__stream);
extern __ssize_t getdelim(char **__lineptr, size_t *__n, int __delimiter, FILE *__stream);
extern __ssize_t getline(char **__lineptr, size_t *__n, FILE *__stream);
extern int fputs(const char *__s, FILE *__stream);
extern int puts(const char *__s);
extern int ungetc(int __c, FILE *__stream);
extern size_t fread(void *__ptr, size_t __size, size_t __n, FILE *__stream);
extern size_t fwrite(const void *__ptr, size_t __size, size_t __n, FILE *__s);
extern size_t fread_unlocked(void *__ptr, size_t __size, size_t __n, FILE *__stream);
extern size_t fwrite_unlocked(const void *__ptr, size_t __size, size_t __n, FILE *__stream);
extern int fseek(FILE *__stream, long __off, int __whence);
extern long ftell(FILE *__stream);
extern void rewind(FILE *__stream);
extern int fseeko(FILE *__stream, __off_t __off, int __whence);
extern __off_t ftello(FILE *__stream);
extern int fgetpos(FILE *__stream, fpos_t *__pos);
extern int fsetpos(FILE *__stream, const fpos_t *__pos);
extern void clearerr(FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int feof(FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int ferror(FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern void clearerr_unlocked(FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int feof_unlocked(FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int ferror_unlocked(FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern void perror(const char *__s);
extern int sys_nerr;
extern const char *const sys_errlist[];
extern int fileno(FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int fileno_unlocked(FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern FILE *popen(const char *__command, const char *__modes);
extern int pclose(FILE *__stream);
extern char *ctermid(char *__s) __attribute__ ((__nothrow__ , __leaf__));
extern void flockfile(FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int ftrylockfile(FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern void funlockfile(FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
typedef int wchar_t;
static __inline unsigned int __bswap_32(unsigned int __bsx)
{
  int T_1;

  T_1 = __builtin_bswap32(__bsx);
  return T_1;
}


static __inline __uint64_t __bswap_64(__uint64_t __bsx)
{
  long long T_2;

  T_2 = __builtin_bswap64(__bsx);
  return T_2;
}


union wait {
  int w_status;
  struct {
    unsigned int __w_termsig:7;
    unsigned int __w_coredump:1;
    unsigned int __w_retcode:8;
    unsigned int :16;
  } __wait_terminated;
  struct {
    unsigned int __w_stopval:8;
    unsigned int __w_stopsig:8;
    unsigned int :16;
  } __wait_stopped;
} ;
typedef union {
  union wait *__uptr;
  int *__iptr;
} __WAIT_STATUS __attribute__ ((__transparent_union__));
typedef struct {
  int quot;
  int rem;
} div_t;
typedef struct {
  long quot;
  long rem;
} ldiv_t;
typedef struct {
  long long quot;
  long long rem;
} lldiv_t;
extern size_t __ctype_get_mb_cur_max() __attribute__ ((__nothrow__ , __leaf__));
extern double atof(const char *__nptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern int atoi(const char *__nptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern long atol(const char *__nptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern long long atoll(const char *__nptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern double strtod(const char *__nptr, char **__endptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern float strtof(const char *__nptr, char **__endptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern long double strtold(const char *__nptr, char **__endptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern long strtol(const char *__nptr, char **__endptr, int __base) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern unsigned long strtoul(const char *__nptr, char **__endptr, int __base) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern long long strtoq(const char *__nptr, char **__endptr, int __base) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern unsigned long long strtouq(const char *__nptr, char **__endptr, int __base) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern long long strtoll(const char *__nptr, char **__endptr, int __base) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern unsigned long long strtoull(const char *__nptr, char **__endptr, int __base) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern char *l64a(long __n) __attribute__ ((__nothrow__ , __leaf__));
extern long a64l(const char *__s) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;
typedef __loff_t loff_t;
typedef __ino_t ino_t;
typedef __dev_t dev_t;
typedef __gid_t gid_t;
typedef __mode_t mode_t;
typedef __nlink_t nlink_t;
typedef __uid_t uid_t;
typedef __pid_t pid_t;
typedef __id_t id_t;
typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;
typedef __key_t key_t;
typedef __clock_t clock_t;
typedef __time_t time_t;
typedef __clockid_t clockid_t;
typedef __timer_t timer_t;
typedef unsigned long ulong;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef int int8_t __attribute__ ((__mode__ (__QI__)));
typedef int int16_t __attribute__ ((__mode__ (__HI__)));
typedef int int32_t __attribute__ ((__mode__ (__SI__)));
typedef int int64_t __attribute__ ((__mode__ (__DI__)));
typedef unsigned int u_int8_t __attribute__ ((__mode__ (__QI__)));
typedef unsigned int u_int16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int u_int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int u_int64_t __attribute__ ((__mode__ (__DI__)));
typedef int register_t __attribute__ ((__mode__ (__word__)));
typedef int __sig_atomic_t;
typedef struct {
  unsigned long __val[1024 / (8 * sizeof(unsigned long ))];
} __sigset_t;
typedef __sigset_t sigset_t;
struct timespec {
  __time_t tv_sec;
  __syscall_slong_t tv_nsec;
} ;
struct timeval {
  __time_t tv_sec;
  __suseconds_t tv_usec;
} ;
typedef __suseconds_t suseconds_t;
typedef long __fd_mask;
typedef struct {
  __fd_mask __fds_bits[1024 / (8 * (int ) (sizeof(__fd_mask )))];
} fd_set;
typedef __fd_mask fd_mask;
extern int select(int __nfds, fd_set *__readfds, fd_set *__writefds, fd_set *__exceptfds, struct timeval *__timeout);
extern int pselect(int __nfds, fd_set *__readfds, fd_set *__writefds, fd_set *__exceptfds, struct timespec *__timeout, const __sigset_t *__sigmask);
extern unsigned int gnu_dev_major(unsigned long long __dev) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern unsigned int gnu_dev_minor(unsigned long long __dev) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern unsigned long long gnu_dev_makedev(unsigned int __major, unsigned int __minor) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
typedef __blksize_t blksize_t;
typedef __blkcnt_t blkcnt_t;
typedef __fsblkcnt_t fsblkcnt_t;
typedef __fsfilcnt_t fsfilcnt_t;
typedef unsigned long pthread_t;
union pthread_attr_t {
  char __size[56];
  long __align;
} ;
typedef union pthread_attr_t pthread_attr_t;
typedef struct __pthread_internal_list {
  struct __pthread_internal_list *__prev;
  struct __pthread_internal_list *__next;
} __pthread_list_t;
typedef union {
  struct __pthread_mutex_s {
    int __lock;
    unsigned int __count;
    int __owner;
    unsigned int __nusers;
    int __kind;
    short __spins;
    short __elision;
    __pthread_list_t __list;
  } __data;
  char __size[40];
  long __align;
} pthread_mutex_t;
typedef union {
  char __size[4];
  int __align;
} pthread_mutexattr_t;
typedef union {
  struct {
    int __lock;
    unsigned int __futex;
    unsigned long long __total_seq;
    unsigned long long __wakeup_seq;
    unsigned long long __woken_seq;
    void *__mutex;
    unsigned int __nwaiters;
    unsigned int __broadcast_seq;
  } __data;
  char __size[48];
  long long __align;
} pthread_cond_t;
typedef union {
  char __size[4];
  int __align;
} pthread_condattr_t;
typedef unsigned int pthread_key_t;
typedef int pthread_once_t;
typedef union {
  struct {
    int __lock;
    unsigned int __nr_readers;
    unsigned int __readers_wakeup;
    unsigned int __writer_wakeup;
    unsigned int __nr_readers_queued;
    unsigned int __nr_writers_queued;
    int __writer;
    int __shared;
    unsigned long __pad1;
    unsigned long __pad2;
    unsigned int __flags;
  } __data;
  char __size[56];
  long __align;
} pthread_rwlock_t;
typedef union {
  char __size[8];
  long __align;
} pthread_rwlockattr_t;
typedef volatile int pthread_spinlock_t;
typedef union {
  char __size[32];
  long __align;
} pthread_barrier_t;
typedef union {
  char __size[4];
  int __align;
} pthread_barrierattr_t;
extern long random() __attribute__ ((__nothrow__ , __leaf__));
extern void srandom(unsigned int __seed) __attribute__ ((__nothrow__ , __leaf__));
extern char *initstate(unsigned int __seed, char *__statebuf, size_t __statelen) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern char *setstate(char *__statebuf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
struct random_data {
  int32_t *fptr;
  int32_t *rptr;
  int32_t *state;
  int rand_type;
  int rand_deg;
  int rand_sep;
  int32_t *end_ptr;
} ;
extern int random_r(struct random_data *__buf, int32_t *__result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int srandom_r(unsigned int __seed, struct random_data *__buf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int initstate_r(unsigned int __seed, char *__statebuf, size_t __statelen, struct random_data *__buf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)));
extern int setstate_r(char *__statebuf, struct random_data *__buf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int rand() __attribute__ ((__nothrow__ , __leaf__));
extern void srand(unsigned int __seed) __attribute__ ((__nothrow__ , __leaf__));
extern int rand_r(unsigned int *__seed) __attribute__ ((__nothrow__ , __leaf__));
extern double drand48() __attribute__ ((__nothrow__ , __leaf__));
extern double erand48(unsigned short __xsubi[3]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern long lrand48() __attribute__ ((__nothrow__ , __leaf__));
extern long nrand48(unsigned short __xsubi[3]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern long mrand48() __attribute__ ((__nothrow__ , __leaf__));
extern long jrand48(unsigned short __xsubi[3]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void srand48(long __seedval) __attribute__ ((__nothrow__ , __leaf__));
extern unsigned short *seed48(unsigned short __seed16v[3]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void lcong48(unsigned short __param[7]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
struct drand48_data {
  unsigned short __x[3];
  unsigned short __old_x[3];
  unsigned short __c;
  unsigned short __init;
  unsigned long long __a;
} ;
extern int drand48_r(struct drand48_data *__buffer, double *__result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int erand48_r(unsigned short __xsubi[3], struct drand48_data *__buffer, double *__result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int lrand48_r(struct drand48_data *__buffer, long *__result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int nrand48_r(unsigned short __xsubi[3], struct drand48_data *__buffer, long *__result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int mrand48_r(struct drand48_data *__buffer, long *__result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int jrand48_r(unsigned short __xsubi[3], struct drand48_data *__buffer, long *__result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int srand48_r(long __seedval, struct drand48_data *__buffer) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int seed48_r(unsigned short __seed16v[3], struct drand48_data *__buffer) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int lcong48_r(unsigned short __param[7], struct drand48_data *__buffer) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *malloc(size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__));
extern void *calloc(size_t __nmemb, size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__));
extern void *realloc(void *__ptr, size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern void free(void *__ptr) __attribute__ ((__nothrow__ , __leaf__));
extern void cfree(void *__ptr) __attribute__ ((__nothrow__ , __leaf__));
extern void *alloca(size_t __size) __attribute__ ((__nothrow__ , __leaf__));
extern void *valloc(size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__));
extern int posix_memalign(void **__memptr, size_t __alignment, size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void abort() __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
extern int atexit(void (*__func)()) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int on_exit(void (*__func)(int __status, void *__arg), void *__arg) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void exit(int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
extern void _Exit(int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
extern char *getenv(const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int putenv(char *__string) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int setenv(const char *__name, const char *__value, int __replace) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int unsetenv(const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int clearenv() __attribute__ ((__nothrow__ , __leaf__));
extern char *mktemp(char *__template) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int mkstemp(char *__template) __attribute__ ((__nonnull__ (1)));
extern int mkstemps(char *__template, int __suffixlen) __attribute__ ((__nonnull__ (1)));
extern char *mkdtemp(char *__template) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int system(const char *__command);
extern char *realpath(const char *__name, char *__resolved) __attribute__ ((__nothrow__ , __leaf__));
typedef int (*__compar_fn_t)(const void *, const void *);
extern void *bsearch(const void *__key, const void *__base, size_t __nmemb, size_t __size, __compar_fn_t __compar) __attribute__ ((__nonnull__ (1, 2, 5)));
extern void qsort(void *__base, size_t __nmemb, size_t __size, __compar_fn_t __compar) __attribute__ ((__nonnull__ (1, 4)));
extern int abs(int __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long labs(long __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long long llabs(long long __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern div_t div(int __numer, int __denom) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern ldiv_t ldiv(long __numer, long __denom) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern lldiv_t lldiv(long long __numer, long long __denom) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern char *ecvt(double __value, int __ndigit, int *__decpt, int *__sign) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4)));
extern char *fcvt(double __value, int __ndigit, int *__decpt, int *__sign) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4)));
extern char *gcvt(double __value, int __ndigit, char *__buf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3)));
extern char *qecvt(long double __value, int __ndigit, int *__decpt, int *__sign) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4)));
extern char *qfcvt(long double __value, int __ndigit, int *__decpt, int *__sign) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4)));
extern char *qgcvt(long double __value, int __ndigit, char *__buf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3)));
extern int ecvt_r(double __value, int __ndigit, int *__decpt, int *__sign, char *__buf, size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int fcvt_r(double __value, int __ndigit, int *__decpt, int *__sign, char *__buf, size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int qecvt_r(long double __value, int __ndigit, int *__decpt, int *__sign, char *__buf, size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int qfcvt_r(long double __value, int __ndigit, int *__decpt, int *__sign, char *__buf, size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int mblen(const char *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));
extern int mbtowc(wchar_t *__pwc, const char *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));
extern int wctomb(char *__s, wchar_t __wchar) __attribute__ ((__nothrow__ , __leaf__));
extern size_t mbstowcs(wchar_t *__pwcs, const char *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));
extern size_t wcstombs(char *__s, const wchar_t *__pwcs, size_t __n) __attribute__ ((__nothrow__ , __leaf__));
extern int rpmatch(const char *__response) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int getsubopt(char **__optionp, char *const *__tokens, char **__valuep) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2, 3)));
extern int getloadavg(double __loadavg[], int __nelem) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int *__errno_location() __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
struct sched_param {
  int __sched_priority;
} ;
struct __sched_param {
  int __sched_priority;
} ;
typedef unsigned long __cpu_mask;
typedef struct {
  __cpu_mask __bits[1024 / (8 * sizeof(__cpu_mask ))];
} cpu_set_t;
extern int __sched_cpucount(size_t __setsize, const cpu_set_t *__setp) __attribute__ ((__nothrow__ , __leaf__));
extern cpu_set_t *__sched_cpualloc(size_t __count) __attribute__ ((__nothrow__ , __leaf__));
extern void __sched_cpufree(cpu_set_t *__set) __attribute__ ((__nothrow__ , __leaf__));
extern int sched_setparam(__pid_t __pid, struct sched_param *__param) __attribute__ ((__nothrow__ , __leaf__));
extern int sched_getparam(__pid_t __pid, struct sched_param *__param) __attribute__ ((__nothrow__ , __leaf__));
extern int sched_setscheduler(__pid_t __pid, int __policy, struct sched_param *__param) __attribute__ ((__nothrow__ , __leaf__));
extern int sched_getscheduler(__pid_t __pid) __attribute__ ((__nothrow__ , __leaf__));
extern int sched_yield() __attribute__ ((__nothrow__ , __leaf__));
extern int sched_get_priority_max(int __algorithm) __attribute__ ((__nothrow__ , __leaf__));
extern int sched_get_priority_min(int __algorithm) __attribute__ ((__nothrow__ , __leaf__));
extern int sched_rr_get_interval(__pid_t __pid, struct timespec *__t) __attribute__ ((__nothrow__ , __leaf__));
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
  const char *tm_zone;
} ;
struct itimerspec {
  struct timespec it_interval;
  struct timespec it_value;
} ;
struct sigevent ;
extern clock_t clock() __attribute__ ((__nothrow__ , __leaf__));
extern time_t time(time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));
extern double difftime(time_t __time1, time_t __time0) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern time_t mktime(struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));
extern size_t strftime(char *__s, size_t __maxsize, const char *__format, struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));
typedef struct __locale_struct {
  struct __locale_data *__locales[13];
  const unsigned short *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;
  const char *__names[13];
} *__locale_t;
typedef __locale_t locale_t;
extern size_t strftime_l(char *__s, size_t __maxsize, const char *__format, struct tm *__tp, __locale_t __loc) __attribute__ ((__nothrow__ , __leaf__));
extern struct tm *gmtime(const time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));
extern struct tm *localtime(const time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));
extern struct tm *gmtime_r(const time_t *__timer, struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));
extern struct tm *localtime_r(const time_t *__timer, struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));
extern char *asctime(struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));
extern char *ctime(const time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));
extern char *asctime_r(struct tm *__tp, char *__buf) __attribute__ ((__nothrow__ , __leaf__));
extern char *ctime_r(const time_t *__timer, char *__buf) __attribute__ ((__nothrow__ , __leaf__));
extern char *__tzname[2];
extern int __daylight;
extern long __timezone;
extern char *tzname[2];
extern void tzset() __attribute__ ((__nothrow__ , __leaf__));
extern int daylight;
extern long timezone;
extern int stime(const time_t *__when) __attribute__ ((__nothrow__ , __leaf__));
extern time_t timegm(struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));
extern time_t timelocal(struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));
extern int dysize(int __year) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int nanosleep(struct timespec *__requested_time, struct timespec *__remaining);
extern int clock_getres(clockid_t __clock_id, struct timespec *__res) __attribute__ ((__nothrow__ , __leaf__));
extern int clock_gettime(clockid_t __clock_id, struct timespec *__tp) __attribute__ ((__nothrow__ , __leaf__));
extern int clock_settime(clockid_t __clock_id, struct timespec *__tp) __attribute__ ((__nothrow__ , __leaf__));
extern int clock_nanosleep(clockid_t __clock_id, int __flags, struct timespec *__req, struct timespec *__rem);
extern int clock_getcpuclockid(pid_t __pid, clockid_t *__clock_id) __attribute__ ((__nothrow__ , __leaf__));
extern int timer_create(clockid_t __clock_id, struct sigevent *__evp, timer_t *__timerid) __attribute__ ((__nothrow__ , __leaf__));
extern int timer_delete(timer_t __timerid) __attribute__ ((__nothrow__ , __leaf__));
extern int timer_settime(timer_t __timerid, int __flags, struct itimerspec *__value, struct itimerspec *__ovalue) __attribute__ ((__nothrow__ , __leaf__));
extern int timer_gettime(timer_t __timerid, struct itimerspec *__value) __attribute__ ((__nothrow__ , __leaf__));
extern int timer_getoverrun(timer_t __timerid) __attribute__ ((__nothrow__ , __leaf__));
typedef long __jmp_buf[8];
enum { PTHREAD_CREATE_JOINABLE, PTHREAD_CREATE_DETACHED } ;
enum { PTHREAD_MUTEX_TIMED_NP, PTHREAD_MUTEX_RECURSIVE_NP, PTHREAD_MUTEX_ERRORCHECK_NP, PTHREAD_MUTEX_ADAPTIVE_NP, PTHREAD_MUTEX_NORMAL = PTHREAD_MUTEX_TIMED_NP, PTHREAD_MUTEX_RECURSIVE = PTHREAD_MUTEX_RECURSIVE_NP, PTHREAD_MUTEX_ERRORCHECK = PTHREAD_MUTEX_ERRORCHECK_NP, PTHREAD_MUTEX_DEFAULT = PTHREAD_MUTEX_NORMAL } ;
enum { PTHREAD_MUTEX_STALLED, PTHREAD_MUTEX_STALLED_NP = PTHREAD_MUTEX_STALLED, PTHREAD_MUTEX_ROBUST, PTHREAD_MUTEX_ROBUST_NP = PTHREAD_MUTEX_ROBUST } ;
enum { PTHREAD_PRIO_NONE, PTHREAD_PRIO_INHERIT, PTHREAD_PRIO_PROTECT } ;
enum { PTHREAD_RWLOCK_PREFER_READER_NP, PTHREAD_RWLOCK_PREFER_WRITER_NP, PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP, PTHREAD_RWLOCK_DEFAULT_NP = PTHREAD_RWLOCK_PREFER_READER_NP } ;
enum { PTHREAD_INHERIT_SCHED, PTHREAD_EXPLICIT_SCHED } ;
enum { PTHREAD_SCOPE_SYSTEM, PTHREAD_SCOPE_PROCESS } ;
enum { PTHREAD_PROCESS_PRIVATE, PTHREAD_PROCESS_SHARED } ;
struct _pthread_cleanup_buffer {
  void (*__routine)(void *);
  void *__arg;
  int __canceltype;
  struct _pthread_cleanup_buffer *__prev;
} ;
enum { PTHREAD_CANCEL_ENABLE, PTHREAD_CANCEL_DISABLE } ;
enum { PTHREAD_CANCEL_DEFERRED, PTHREAD_CANCEL_ASYNCHRONOUS } ;
extern int pthread_create(pthread_t *__newthread, const pthread_attr_t *__attr, void *(*__start_routine)(void *), void *__arg) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 3)));
extern void pthread_exit(void *__retval) __attribute__ ((__noreturn__));
extern int pthread_join(pthread_t __th, void **__thread_return);
extern int pthread_detach(pthread_t __th) __attribute__ ((__nothrow__ , __leaf__));
extern pthread_t pthread_self() __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int pthread_equal(pthread_t __thread1, pthread_t __thread2) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int pthread_attr_init(pthread_attr_t *__attr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_destroy(pthread_attr_t *__attr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_getdetachstate(const pthread_attr_t *__attr, int *__detachstate) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_setdetachstate(pthread_attr_t *__attr, int __detachstate) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_getguardsize(const pthread_attr_t *__attr, size_t *__guardsize) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_setguardsize(pthread_attr_t *__attr, size_t __guardsize) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_getschedparam(const pthread_attr_t *__attr, struct sched_param *__param) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_setschedparam(pthread_attr_t *__attr, struct sched_param *__param) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_getschedpolicy(const pthread_attr_t *__attr, int *__policy) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_setschedpolicy(pthread_attr_t *__attr, int __policy) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_getinheritsched(const pthread_attr_t *__attr, int *__inherit) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_setinheritsched(pthread_attr_t *__attr, int __inherit) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_getscope(const pthread_attr_t *__attr, int *__scope) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_setscope(pthread_attr_t *__attr, int __scope) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_getstackaddr(const pthread_attr_t *__attr, void **__stackaddr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) __attribute__ ((__deprecated__));
extern int pthread_attr_setstackaddr(pthread_attr_t *__attr, void *__stackaddr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__deprecated__));
extern int pthread_attr_getstacksize(const pthread_attr_t *__attr, size_t *__stacksize) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_attr_setstacksize(pthread_attr_t *__attr, size_t __stacksize) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_attr_getstack(const pthread_attr_t *__attr, void **__stackaddr, size_t *__stacksize) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2, 3)));
extern int pthread_attr_setstack(pthread_attr_t *__attr, void *__stackaddr, size_t __stacksize) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_setschedparam(pthread_t __target_thread, int __policy, struct sched_param *__param) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3)));
extern int pthread_getschedparam(pthread_t __target_thread, int *__policy, struct sched_param *__param) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
extern int pthread_setschedprio(pthread_t __target_thread, int __prio) __attribute__ ((__nothrow__ , __leaf__));
extern int pthread_once(pthread_once_t *__once_control, void (*__init_routine)()) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_setcancelstate(int __state, int *__oldstate);
extern int pthread_setcanceltype(int __type, int *__oldtype);
extern int pthread_cancel(pthread_t __th);
extern void pthread_testcancel();
typedef struct {
  struct {
    __jmp_buf __cancel_jmp_buf;
    int __mask_was_saved;
  } __cancel_jmp_buf[1];
  void *__pad[4];
} __pthread_unwind_buf_t __attribute__ ((__aligned__));
struct __pthread_cleanup_frame {
  void (*__cancel_routine)(void *);
  void *__cancel_arg;
  int __do_it;
  int __cancel_type;
} ;
extern void __pthread_register_cancel(__pthread_unwind_buf_t *__buf);
extern void __pthread_unregister_cancel(__pthread_unwind_buf_t *__buf);
extern void __pthread_unwind_next(__pthread_unwind_buf_t *__buf) __attribute__ ((__noreturn__)) __attribute__ ((__weak__));
struct __jmp_buf_tag ;
extern int __sigsetjmp(struct __jmp_buf_tag *__env, int __savemask) __attribute__ ((__nothrow__));
extern int pthread_mutex_init(pthread_mutex_t *__mutex, const pthread_mutexattr_t *__mutexattr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutex_destroy(pthread_mutex_t *__mutex) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutex_trylock(pthread_mutex_t *__mutex) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutex_lock(pthread_mutex_t *__mutex) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutex_timedlock(pthread_mutex_t *__mutex, struct timespec *__abstime) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_mutex_unlock(pthread_mutex_t *__mutex) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutex_getprioceiling(const pthread_mutex_t *__mutex, int *__prioceiling) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_mutex_setprioceiling(pthread_mutex_t *__mutex, int __prioceiling, int *__old_ceiling) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3)));
extern int pthread_mutex_consistent(pthread_mutex_t *__mutex) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutexattr_init(pthread_mutexattr_t *__attr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutexattr_destroy(pthread_mutexattr_t *__attr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutexattr_getpshared(const pthread_mutexattr_t *__attr, int *__pshared) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_mutexattr_setpshared(pthread_mutexattr_t *__attr, int __pshared) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutexattr_gettype(const pthread_mutexattr_t *__attr, int *__kind) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_mutexattr_settype(pthread_mutexattr_t *__attr, int __kind) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutexattr_getprotocol(const pthread_mutexattr_t *__attr, int *__protocol) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_mutexattr_setprotocol(pthread_mutexattr_t *__attr, int __protocol) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutexattr_getprioceiling(const pthread_mutexattr_t *__attr, int *__prioceiling) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_mutexattr_setprioceiling(pthread_mutexattr_t *__attr, int __prioceiling) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_mutexattr_getrobust(const pthread_mutexattr_t *__attr, int *__robustness) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_mutexattr_setrobust(pthread_mutexattr_t *__attr, int __robustness) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlock_init(pthread_rwlock_t *__rwlock, const pthread_rwlockattr_t *__attr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlock_destroy(pthread_rwlock_t *__rwlock) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlock_rdlock(pthread_rwlock_t *__rwlock) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlock_tryrdlock(pthread_rwlock_t *__rwlock) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlock_timedrdlock(pthread_rwlock_t *__rwlock, struct timespec *__abstime) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_rwlock_wrlock(pthread_rwlock_t *__rwlock) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlock_trywrlock(pthread_rwlock_t *__rwlock) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlock_timedwrlock(pthread_rwlock_t *__rwlock, struct timespec *__abstime) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_rwlock_unlock(pthread_rwlock_t *__rwlock) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlockattr_init(pthread_rwlockattr_t *__attr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlockattr_destroy(pthread_rwlockattr_t *__attr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlockattr_getpshared(const pthread_rwlockattr_t *__attr, int *__pshared) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_rwlockattr_setpshared(pthread_rwlockattr_t *__attr, int __pshared) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_rwlockattr_getkind_np(const pthread_rwlockattr_t *__attr, int *__pref) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_rwlockattr_setkind_np(pthread_rwlockattr_t *__attr, int __pref) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_cond_init(pthread_cond_t *__cond, const pthread_condattr_t *__cond_attr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_cond_destroy(pthread_cond_t *__cond) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_cond_signal(pthread_cond_t *__cond) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_cond_broadcast(pthread_cond_t *__cond) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_cond_wait(pthread_cond_t *__cond, pthread_mutex_t *__mutex) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_cond_timedwait(pthread_cond_t *__cond, pthread_mutex_t *__mutex, struct timespec *__abstime) __attribute__ ((__nonnull__ (1, 2, 3)));
extern int pthread_condattr_init(pthread_condattr_t *__attr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_condattr_destroy(pthread_condattr_t *__attr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_condattr_getpshared(const pthread_condattr_t *__attr, int *__pshared) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_condattr_setpshared(pthread_condattr_t *__attr, int __pshared) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_condattr_getclock(const pthread_condattr_t *__attr, __clockid_t *__clock_id) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_condattr_setclock(pthread_condattr_t *__attr, __clockid_t __clock_id) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_spin_init(volatile pthread_spinlock_t *__lock, int __pshared) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_spin_destroy(volatile pthread_spinlock_t *__lock) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_spin_lock(volatile pthread_spinlock_t *__lock) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_spin_trylock(volatile pthread_spinlock_t *__lock) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_spin_unlock(volatile pthread_spinlock_t *__lock) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_barrier_init(pthread_barrier_t *__barrier, const pthread_barrierattr_t *__attr, unsigned int __count) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_barrier_destroy(pthread_barrier_t *__barrier) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_barrier_wait(pthread_barrier_t *__barrier) __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_barrierattr_init(pthread_barrierattr_t *__attr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_barrierattr_destroy(pthread_barrierattr_t *__attr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_barrierattr_getpshared(const pthread_barrierattr_t *__attr, int *__pshared) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int pthread_barrierattr_setpshared(pthread_barrierattr_t *__attr, int __pshared) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_key_create(pthread_key_t *__key, void (*__destr_function)(void *)) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int pthread_key_delete(pthread_key_t __key) __attribute__ ((__nothrow__ , __leaf__));
extern void *pthread_getspecific(pthread_key_t __key) __attribute__ ((__nothrow__ , __leaf__));
extern int pthread_setspecific(pthread_key_t __key, const void *__pointer) __attribute__ ((__nothrow__ , __leaf__));
extern int pthread_getcpuclockid(pthread_t __thread_id, __clockid_t *__clock_id) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int pthread_atfork(void (*__prepare)(), void (*__parent)(), void (*__child)()) __attribute__ ((__nothrow__ , __leaf__));
typedef union {
  char __size[32];
  long __align;
} sem_t;
extern int sem_init(sem_t *__sem, int __pshared, unsigned int __value) __attribute__ ((__nothrow__ , __leaf__));
extern int sem_destroy(sem_t *__sem) __attribute__ ((__nothrow__ , __leaf__));
extern sem_t *sem_open(const char *__name, int __oflag, ...) __attribute__ ((__nothrow__ , __leaf__));
extern int sem_close(sem_t *__sem) __attribute__ ((__nothrow__ , __leaf__));
extern int sem_unlink(const char *__name) __attribute__ ((__nothrow__ , __leaf__));
extern int sem_wait(sem_t *__sem);
extern int sem_timedwait(sem_t *__sem, struct timespec *__abstime);
extern int sem_trywait(sem_t *__sem) __attribute__ ((__nothrow__));
extern int sem_post(sem_t *__sem) __attribute__ ((__nothrow__));
extern int sem_getvalue(sem_t *__sem, int *__sval) __attribute__ ((__nothrow__ , __leaf__));
void think();
void eat();
void sectionInitGlobals(int numPhilosophers);
void sectionRunPhilosopher(int philosopherID, int numRounds);
typedef const char *(*CheckerFuncPtr)(int , const char *, const char *);
void mdat_init(int numThreads, char *traceName, CheckerFuncPtr checkerFunc, int useInteractive, int useSeed, unsigned int seed);
void mdat_thread_start(int id, const char *property);
void mdat_thread_finish();
void mdat_invoke_scheduler(int location);
void mdat_mutex_init(const char *name, pthread_mutex_t *lock, pthread_mutexattr_t *attr);
void mdat_mutex_lock(pthread_mutex_t *lock);
void mdat_mutex_unlock(pthread_mutex_t *lock);
void mdat_sem_init(const char *name, sem_t *sem, int pshared, int value);
void mdat_sem_wait(sem_t *sem);
void mdat_sem_post(sem_t *sem);
void mdat_enter_section(const char *section);
pthread_mutex_t *count;
pthread_mutex_t *forks;
int totalPhilosophers;
int counter;
void sectionInitGlobals(int numPhilosophers)
{
  int i;
  char name[30];
  void *T_3;
  int T_4;

  mdat_invoke_scheduler(1);
  i = 0;
  mdat_invoke_scheduler(2);
  totalPhilosophers = numPhilosophers;
  mdat_invoke_scheduler(3);
  counter = 0;
  mdat_invoke_scheduler(4);
  T_3 = calloc(numPhilosophers,sizeof(pthread_mutex_t *));

  mdat_invoke_scheduler(5);
  forks = (pthread_mutex_t *) (T_3);
  mdat_invoke_scheduler(6);
  i = 0;
  mdat_invoke_scheduler(7);
  T_4 = i < numPhilosophers;
  mdat_invoke_scheduler(8);
  for (; T_4; )
  {
    mdat_invoke_scheduler(9);
    sprintf(name,"fork %d",i);

    mdat_invoke_scheduler(10);
    mdat_mutex_init(name,&forks[i],(void *) (0));

    mdat_invoke_scheduler(11);
    i = i + 1;
    mdat_invoke_scheduler(12);
    T_4 = i < numPhilosophers;
    mdat_invoke_scheduler(8);
  }


  mdat_invoke_scheduler(13);
  mdat_mutex_init("thread count",count,(void *) (0));

}


void sectionRunPhilosopher(int philosopherID, int numRounds)
{
  int second_fork;
  int first_fork;
  int i;
  int T_5;
  int T_6;
  int T_7;
  int T_8;

  mdat_invoke_scheduler(14);
  second_fork = 0;
  mdat_invoke_scheduler(15);
  first_fork = 0;
  mdat_invoke_scheduler(16);
  i = 0;
  mdat_invoke_scheduler(17);
  T_5 = totalPhilosophers - 1;
  mdat_invoke_scheduler(18);
  T_6 = philosopherID == T_5;
  mdat_invoke_scheduler(19);
  if (T_6)
  {
    mdat_invoke_scheduler(20);
    first_fork = philosopherID;
    mdat_invoke_scheduler(21);
    second_fork = 0;
  }

  else
  {
    mdat_invoke_scheduler(22);
    first_fork = philosopherID;
    mdat_invoke_scheduler(23);
    second_fork = philosopherID + 1;
  }


  mdat_invoke_scheduler(24);
  i = 0;
  mdat_invoke_scheduler(25);
  T_7 = i < numRounds;
  mdat_invoke_scheduler(26);
  for (; T_7; )
  {
    mdat_invoke_scheduler(27);
    mdat_mutex_lock(&forks[first_fork]);

    mdat_mutex_lock(&forks[second_fork]);

    eat();

    mdat_invoke_scheduler(28);
    mdat_mutex_unlock(&forks[second_fork]);

    mdat_mutex_unlock(&forks[first_fork]);

    think();

    mdat_invoke_scheduler(29);
    i = i + 1;
    mdat_invoke_scheduler(30);
    T_7 = i < numRounds;
    mdat_invoke_scheduler(26);
  }


  mdat_invoke_scheduler(31);
  T_8 = counter < totalPhilosophers;
  mdat_invoke_scheduler(32);
  if (T_8)
  {
    mdat_invoke_scheduler(33);
    mdat_mutex_lock(count);

    counter = counter + 1;
    mdat_invoke_scheduler(34);
    mdat_mutex_unlock(count);

  }

  else
  {
    mdat_invoke_scheduler(35);
    free(forks);

  }


}



