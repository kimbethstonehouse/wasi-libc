#ifndef	_SETJMP_H
#define	_SETJMP_H

#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>

#ifdef __wasilibc_unmodified_upstream /* WASI has no setjmp */
#include <bits/setjmp.h>

typedef struct __jmp_buf_tag {
	__jmp_buf __jb;
	unsigned long __fl;
	unsigned long __ss[128/sizeof(long)];
} jmp_buf[1];

// #if defined(_POSIX_SOURCE) || defined(_POSIX_C_SOURCE) \
//  || defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) \
//  || defined(_BSD_SOURCE)
typedef jmp_buf sigjmp_buf;
int sigsetjmp (sigjmp_buf, int);
_Noreturn void siglongjmp (sigjmp_buf, int);
// #endif

// #if defined(_XOPEN_SOURCE) || defined(_GNU_SOURCE) \
//  || defined(_BSD_SOURCE)
int _setjmp (jmp_buf);
_Noreturn void _longjmp (jmp_buf, int);
// #endif

int setjmp (jmp_buf);
_Noreturn void longjmp (jmp_buf, int);

#define setjmp setjmp
#else
#warning setjmp is not yet implemented for WASI
#endif

#ifdef __cplusplus
}
#endif

#endif
