#define _POSIX_SOURCE
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>
#include <string.h>
#include <math.h>
#include <setjmp.h>
#include <float.h>
#include <time.h>
#include <assert.h>
#include <signal.h>
#include <setjmp.h>

#include <unistd.h>
#include <process.h>
#include <io.h>
#include <direct.h>
#include <fcntl.h>

/*
 * math module dtoa
 */
#define __LITTLE_ENDIAN

   /* there must be a Win32 header macro for endian-ness!!! */


typedef unsigned char	uchar;
typedef unsigned int	uint;
typedef unsigned long	ulong;
typedef signed char	schar;
typedef unsigned short	ushort;
typedef unsigned int Rune;
typedef __int64		vlong;
typedef unsigned __int64		uvlong;
typedef unsigned int u32int;
typedef uvlong u64int;

typedef unsigned int	mpdigit;	/* for /sys/include/mp.h */
typedef unsigned short u16int;
typedef unsigned char u8int;
typedef unsigned long uintptr;

typedef signed char	int8;
typedef unsigned char	uint8;
typedef short	int16;
typedef unsigned short	uint16;
typedef int	int32;
typedef unsigned int	uint32;
typedef long long	int64;
typedef unsigned long long	uint64;
