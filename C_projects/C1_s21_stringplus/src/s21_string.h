#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

struct format {
  int flag_plus;
  int flag_minus;
  int flag_space;
  int flag_hash;
  int flag_zero;
  char spec;
  int wight;
  int accur;
  int accur_spec_d;
  char lenght;
  int minus;
  int negative;
};

struct fsc {
  int wight;
  char lenght;
  int minus;
  int result;
  int ast;
  int error;
  char *str;
  char spec;
  char *start;
};

typedef unsigned s21_size_t;
typedef unsigned long s21_size_t_long;

#define s21_NULL ((void *)0)

#if defined(__APPLE__)
#define MAX_NUM 107
#define ERRLIST                                         \
    {"Undefined error: 0",                              \
     "Operation not permitted",                         \
     "No such file or directory",                       \
     "No such process",                                 \
     "Interrupted system call",                         \
     "Input/output error",                              \
     "Device not configured",                           \
     "Argument list too long",                          \
     "Exec format error",                               \
     "Bad file descriptor",                             \
     "No child processes",                              \
     "Resource deadlock avoided",                       \
     "Cannot allocate memory",                          \
     "Permission denied",                               \
     "Bad address",                                     \
     "Block device required",                           \
     "Resource busy",                                   \
     "File exists",                                     \
     "Cross-device link",                               \
     "Operation not supported by device",               \
     "Not a directory",                                 \
     "Is a directory",                                  \
     "Invalid argument",                                \
     "Too many open files in system",                   \
     "Too many open files",                             \
     "Inappropriate ioctl for device",                  \
     "Text file busy",                                  \
     "File too large",                                  \
     "No space left on device",                         \
     "Illegal seek",                                    \
     "Read-only file system",                           \
     "Too many links",                                  \
     "Broken pipe",                                     \
     "Numerical argument out of domain",                \
     "Result too large",                                \
     "Resource temporarily unavailable",                \
     "Operation now in progress",                       \
     "Operation already in progress",                   \
     "Socket operation on non-socket",                  \
     "Destination address required",                    \
     "Message too long",                                \
     "Protocol wrong type for socket",                  \
     "Protocol not available",                          \
     "Protocol not supported",                          \
     "Socket type not supported",                       \
     "Operation not supported",                         \
     "Protocol family not supported",                   \
     "Address family not supported by protocol family", \
     "Address already in use",                          \
     "Can't assign requested address",                  \
     "Network is down",                                 \
     "Network is unreachable",                          \
     "Network dropped connection on reset",             \
     "Software caused connection abort",                \
     "Connection reset by peer",                        \
     "No buffer space available",                       \
     "Socket is already connected",                     \
     "Socket is not connected",                         \
     "Can't send after socket shutdown",                \
     "Too many references: can't splice",               \
     "Operation timed out",                             \
     "Connection refused",                              \
     "Too many levels of symbolic links",               \
     "File name too long",                              \
     "Host is down",                                    \
     "No route to host",                                \
     "Directory not empty",                             \
     "Too many processes",                              \
     "Too many users",                                  \
     "Disc quota exceeded",                             \
     "Stale NFS file handle",                           \
     "Too many levels of remote in path",               \
     "RPC struct is bad",                               \
     "RPC version wrong",                               \
     "RPC prog. not avail",                             \
     "Program version wrong",                           \
     "Bad procedure for program",                       \
     "No locks available",                              \
     "Function not implemented",                        \
     "Inappropriate file type or format",               \
     "Authentication error",                            \
     "Need authenticator",                              \
     "Device power is off",                             \
     "Device error",                                    \
     "Value too large to be stored in data type",       \
     "Bad executable (or shared library)",              \
     "Bad CPU type in executable",                      \
     "Shared library version mismatch",                 \
     "Malformed Mach-o file",                           \
     "Operation canceled",                              \
     "Identifier removed",                              \
     "No message of desired type",                      \
     "Illegal byte sequence",                           \
     "Attribute not found",                             \
     "Bad message",                                     \
     "EMULTIHOP (Reserved)",                            \
     "No message available on STREAM",                  \
     "ENOLINK (Reserved)",                              \
     "No STREAM resources",                             \
     "Not a STREAM",                                    \
     "Protocol error",                                  \
     "STREAM ioctl timeout",                            \
     "Operation not supported on socket",               \
     "Policy not found",                                \
     "State not recoverable",                           \
     "Previous owner died",                             \
     "Interface output queue is full"};

#elif defined(__linux__)
#define MAX_NUM 134
#define ERRLIST                                           \
    {"Success",                                           \
     "Operation not permitted",                           \
     "No such file or directory",                         \
     "No such process",                                   \
     "Interrupted system call",                           \
     "Input/output error",                                \
     "No such device or address",                         \
     "Argument list too long",                            \
     "Exec format error",                                 \
     "Bad file descriptor",                               \
     "No child processes",                                \
     "Resource temporarily unavailable",                  \
     "Cannot allocate memory",                            \
     "Permission denied",                                 \
     "Bad address",                                       \
     "Block device required",                             \
     "Device or resource busy",                           \
     "File exists",                                       \
     "Invalid cross-device link",                         \
     "No such device",                                    \
     "Not a directory",                                   \
     "Is a directory",                                    \
     "Invalid argument",                                  \
     "Too many open files in system",                     \
     "Too many open files",                               \
     "Inappropriate ioctl for device",                    \
     "Text file busy",                                    \
     "File too large",                                    \
     "No space left on device",                           \
     "Illegal seek",                                      \
     "Read-only file system",                             \
     "Too many links",                                    \
     "Broken pipe",                                       \
     "Numerical argument out of domain",                  \
     "Numerical result out of range",                     \
     "Resource deadlock avoided",                         \
     "File name too long",                                \
     "No locks available",                                \
     "Function not implemented",                          \
     "Directory not empty",                               \
     "Too many levels of symbolic links",                 \
     "Unknown error 41",                                  \
     "No message of desired type",                        \
     "Identifier removed",                                \
     "Channel number out of range",                       \
     "Level 2 not synchronized",                          \
     "Level 3 halted",                                    \
     "Level 3 reset",                                     \
     "Link number out of range",                          \
     "Protocol driver not attached",                      \
     "No CSI structure available",                        \
     "Level 2 halted",                                    \
     "Invalid exchange",                                  \
     "Invalid request descriptor",                        \
     "Exchange full",                                     \
     "No anode",                                          \
     "Invalid request code",                              \
     "Invalid slot",                                      \
     "Unknown error 58",                                  \
     "Bad font file format",                              \
     "Device not a stream",                               \
     "No data available",                                 \
     "Timer expired",                                     \
     "Out of streams resources",                          \
     "Machine is not on the network",                     \
     "Package not installed",                             \
     "Object is remote",                                  \
     "Link has been severed",                             \
     "Advertise error",                                   \
     "Srmount error",                                     \
     "Communication error on send",                       \
     "Protocol error",                                    \
     "Multihop attempted",                                \
     "RFS specific error",                                \
     "Bad message",                                       \
     "Value too large for defined data type",             \
     "Name not unique on network",                        \
     "File descriptor in bad state",                      \
     "Remote address changed",                            \
     "Can not access a needed shared library",            \
     "Accessing a corrupted shared library",              \
     ".lib section in a.out corrupted",                   \
     "Attempting to link in too many shared libraries",   \
     "Cannot exec a shared library directly",             \
     "Invalid or incomplete multibyte or wide character", \
     "Interrupted system call should be restarted",       \
     "Streams pipe error",                                \
     "Too many users",                                    \
     "Socket operation on non-socket",                    \
     "Destination address required",                      \
     "Message too long",                                  \
     "Protocol wrong type for socket",                    \
     "Protocol not available",                            \
     "Protocol not supported",                            \
     "Socket type not supported",                         \
     "Operation not supported",                           \
     "Protocol family not supported",                     \
     "Address family not supported by protocol",          \
     "Address already in use",                            \
     "Cannot assign requested address",                   \
     "Network is down",                                   \
     "Network is unreachable",                            \
     "Network dropped connection on reset",               \
     "Software caused connection abort",                  \
     "Connection reset by peer",                          \
     "No buffer space available",                         \
     "Transport endpoint is already connected",           \
     "Transport endpoint is not connected",               \
     "Cannot send after transport endpoint shutdown",     \
     "Too many references: cannot splice",                \
     "Connection timed out",                              \
     "Connection refused",                                \
     "Host is down",                                      \
     "No route to host",                                  \
     "Operation already in progress",                     \
     "Operation now in progress",                         \
     "Stale file handle",                                 \
     "Structure needs cleaning",                          \
     "Not a XENIX named type file",                       \
     "No XENIX semaphores available",                     \
     "Is a named type file",                              \
     "Remote I/O error",                                  \
     "Disk quota exceeded",                               \
     "No medium found",                                   \
     "Wrong medium type",                                 \
     "Operation canceled",                                \
     "Required key not available",                        \
     "Key has expired",                                   \
     "Key has been revoked",                              \
     "Key was rejected by service",                       \
     "Owner died",                                        \
     "State not recoverable",                             \
     "Operation not possible due to RF-kill",             \
     "Memory page has hardware error"};
#endif

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
s21_size_t s21_strspn(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
int s21_sprintf(char *str, const char *format, ...);
int s21_sscanf(const char *str, const char *format, ...);
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);
void itoa(int n, char *str);
void reverse(char *str);
void convert(unsigned int num, int x, struct format *S, char *str);
void convert_f_long(unsigned long int num, int x, struct format *S, char *str);
void utoa(s21_size_t n, char *str);
void lutoa(s21_size_t_long n, char *str);
void ltoa(long int n, char *str, struct format *S);
void flagHash(char *c, struct format *S, int i);
void flagMinus(char *c, struct format *S);
void flagPlusSpase(char *c, struct format *S);
void accur_s(char *c, struct format *S);
void accur_d(char *str, struct format *S);
void wight(char *c, struct format *S);
void wight_foroxX(char *c, struct format *S);
void lenght(int x, char *str, struct format *S);
void format(struct format *S, char *str);
void formatF(struct format *S, char *str, int num);
void ftos(double num, char *c, struct format *S);
void etos(double num, char *str, int count, struct format *S);
void *p_sprintf(char *str, void *ptr);
void n_sprintf(const char *str, const char *start, int *path);
void init(struct format *S);
void badflags(struct format *S);
char *f_sprintf(struct format *S, char *str, long double num);
char *oxX_sprintf(struct format *S, char *str, int num);
char *loxX_sprintf(struct format *S, char *str, long int num);
char *c_sprintf(struct format *S, char *str, int C);
char *s_sprintf(struct format *S, char *str, char *C);
char *ls_sprintf(struct format *S, char *str, wchar_t *C);
char *u_sprintf(struct format *S, char *str, s21_size_t num);
char *lu_sprintf(struct format *S, char *str, s21_size_t_long num);
char *p_convert(long x, int hex);
char *d_sprintf(struct format *S, char *str, int num);
char *ld_sprintf(struct format *S, char *str, long int num);
void init_scanf(struct fsc *S);
int is_error(struct fsc *S);
void spaces_sign(struct fsc *S);
void c_sscanf(struct fsc *S, va_list ap);
void lc_sscanf(struct fsc *S, va_list ap);
int s_valid(char *c);
void s_sscanf(struct fsc *S, va_list ap);
void ls_sscanf(struct fsc *S, va_list ap);
void d_isresult(int res, struct fsc *S, int *path);
void ld_isresult(int res, struct fsc *S, long *path);
int d_valid(char c);
int o_convert(int value);
int x_convert(int value);
int o_valid(int value);
void strtoi(int *res, struct fsc *S, int n, int *path);
void strtoli(int *res, struct fsc *S, int n, long *path);
void d_sscanf(struct fsc *S, va_list ap);
void ld_sscanf(struct fsc *S, va_list ap);
void o_sscanf(struct fsc *S, va_list ap);
void lo_sscanf(struct fsc *S, va_list ap);
int x_valid(int value);
void x_sscanf(struct fsc *S, va_list ap);
void lx_sscanf(struct fsc *S, va_list ap);
void i_sscanf(struct fsc *S, va_list ap);
void li_sscanf(struct fsc *S, va_list ap);
void n_sscanf(struct fsc *S, va_list ap);
void f_sscanf(struct fsc *S, va_list ap);
void lf_sscanf(struct fsc *S, va_list ap);
void p_sscanf(struct fsc *S, va_list ap);
int spec_scanf(char spec, struct fsc *S, va_list ap);

#endif  // SRC_S21_STRING_H_
