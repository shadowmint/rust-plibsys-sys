/*
 * Copyright (C) 2010-2016 Alexander Saprykin <xelfium@gmail.com>
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

/**
 * @file pmacros.h
 * @brief Miscellaneous macros
 * @author Alexander Saprykin
 *
 * All the macros are completely independent of any other platform-specific
 * headers, thus gurantee to work with any compiler under any operating system
 * in the same way as they are used within the library.
 *
 * Provided macros can be divided into the three groups:
 * - operating system detection (P_OS_x);
 * - compiler detection (P_CC_x);
 * - other general macros (compiler hints, attributes, version, etc.).
 *
 * Macros from the first two groups are defined only for the particularly
 * detected operating systems and compilers. Macros from the latter group are
 * always defined.
 */

#if !defined (PLIBSYS_H_INSIDE) && !defined (PLIBSYS_COMPILATION)
#  error "Header files shouldn't be included directly, consider using <plibsys.h> instead."
#endif

#ifndef PLIBSYS_HEADER_PMACROS_H
#define PLIBSYS_HEADER_PMACROS_H

#include <stdio.h>

/*
 * List of supported operating systems (P_OS_x):
 *
 * DARWIN            - Any Darwin based system
 * DARWIN32          - Any 32-bit Darwin based system
 * DARWIN64          - Any 64-bit Darwin based system
 * BSD4              - Any BSD 4.x based system
 * FREEBSD           - FreeBSD
 * DRAGONFLY         - DragonFlyBSD
 * NETBSD            - NetBSD
 * OPENBSD           - OpenBSD
 * AIX               - IBM AIX
 * HPUX              - HP-UX
 * SOLARIS           - Sun (Oracle) Solaris
 * QNX               - QNX 4.x
 * QNX6              - QNX Neutrino 6.x
 * SCO               - SCO OpenServer 5/6
 * UNIXWARE          - UnixWare 7
 * IRIX              - SGI IRIX
 * HAIKU             - Haiku
 * VMS               - VMS
 * UNIX              - Any UNIX BSD/SYSV based system
 * LINUX             - Linux
 * MAC9              - Mac OS 9 (Classic)
 * MAC               - Any Mac OS X
 * MAC32             - 32-bit Mac OS X
 * MAC64             - 64-bit Mac OS X
 * CYGWIN            - Cygwin
 * WIN               - 32-bit Windows
 * WIN64             - 64-bit Windows
 */

/**
 * @def P_OS_DARWIN
 * @brief Darwin based operating system (i.e. Mac OS X).
 * @since 0.0.1
 */

/**
 * @def P_OS_DARWIN32
 * @brief Darwin based 32-bit operating system.
 * @since 0.0.1
 */

/**
 * @def P_OS_DARWIN64
 * @brief Darwin based 64-bit operating system.
 * @since 0.0.1
 */

/**
 * @def P_OS_BSD4
 * @brief BSD 4.x based operating system.
 * @since 0.0.1
 */

/**
 * @def P_OS_FREEBSD
 * @brief FreeBSD operating system.
 * @since 0.0.1
 */

/**
 * @def P_OS_DRAGONFLY
 * @brief DragonFlyBSD operating system.
 * @since 0.0.1
 */

/**
 * @def P_OS_NETBSD
 * @brief NetBSD operating system.
 * @since 0.0.1
 */

/**
 * @def P_OS_OPENBSD
 * @brief OpenBSD operating system.
 * @since 0.0.1
 */

/**
 * @def P_OS_AIX
 * @brief IBM AIX operating system.
 * @since 0.0.1
 */

/**
 * @def P_OS_HPUX
 * @brief HP-UX operating system.
 * @since 0.0.1
 */

/**
 * @def P_OS_SOLARIS
 * @brief Sun (Oracle) Solaris operating system.
 * @since 0.0.1
 */

/**
 * @def P_OS_QNX
 * @brief QNX 4.x operating system.
 * @since 0.0.1
 */

/**
 * @def P_OS_QNX6
 * @brief QNX Neutrino 6.x operating system.
 * @since 0.0.1
 */

/**
 * @def P_OS_SCO
 * @brief SCO OpenServer operating system.
 * @since 0.0.1
 */

/**
 * @def P_OS_UNIXWARE
 * @brief UnixWare 7 operating system.
 * @since 0.0.1
 */

/**
 * @def P_OS_IRIX
 * @brief SGI's IRIX operating system.
 * @since 0.0.1
 */

/**
 * @def P_OS_HAIKU
 * @brief Haiku operating system.
 * @since 0.0.1
 */

/**
 * @def P_OS_VMS
 * @brief VMS operating system.
 * @since 0.0.1
 */

/**
 * @def P_OS_UNIX
 * @brief UNIX based operating system.
 * @since 0.0.1
 */

/**
 * @def P_OS_LINUX
 * @brief Linux based operating system.
 * @since 0.0.1
 */

/**
 * @def P_OS_MAC9
 * @brief Apple's Mac OS 9 operating system.
 * @since 0.0.1
 */

/**
 * @def P_OS_MAC
 * @brief Apple's Mac OS X operating system.
 * @since 0.0.1
 */

/**
 * @def P_OS_MAC32
 * @brief Apple's Mac OS X 32-bit operating system.
 * @since 0.0.1
 */

/**
 * @def P_OS_MAC64
 * @brief Apple's Mac OS X 64-bit operating system.
 * @since 0.0.1
 */

/**
 * @def P_OS_CYGWIN
 * @brief Microsoft Windows POSIX runtime environment.
 * @since 0.0.1
 */

/**
 * @def P_OS_MSYS
 * @brief Microsoft Windows POSIX development environment.
 * @since 0.0.1
 */

/**
 * @def P_OS_WIN
 * @brief Microsoft Windows 32-bit operating system.
 * @since 0.0.1
 */

/**
 * @def P_OS_WIN64
 * @brief Microsoft Windows 64-bit operating system.
 * @since 0.0.1
 */

/* We need this to disable Doxygen warnings */

#ifdef DOXYGEN
#  define P_OS_DARWIN
#  define P_OS_DARWIN32
#  define P_OS_DARWIN64
#  define P_OS_BSD4
#  define P_OS_FREEBSD
#  define P_OS_DRAGONFLY
#  define P_OS_NETBSD
#  define P_OS_OPENBSD
#  define P_OS_AIX
#  define P_OS_HPUX
#  define P_OS_SOLARIS
#  define P_OS_QNX
#  define P_OS_QNX6
#  define P_OS_SCO
#  define P_OS_UNIXWARE
#  define P_OS_IRIX
#  define P_OS_HAIKU
#  define P_OS_VMS
#  define P_OS_UNIX
#  define P_OS_LINUX
#  define P_OS_MAC9
#  define P_OS_MAC
#  define P_OS_MAC32
#  define P_OS_MAC64
#  define P_OS_CYGWIN
#  define P_OS_MSYS
#  define P_OS_WIN
#  define P_OS_WIN64
#endif

#if defined(__APPLE__) && (defined(__GNUC__) || defined(__xlC__) || defined(__xlc__))
#  define P_OS_DARWIN
#  define P_OS_BSD4
#  ifdef __LP64__
#    define P_OS_DARWIN64
#  else
#    define P_OS_DARWIN32
#  endif
# elif defined(Macintosh) || defined(macintosh)
#  define P_OS_MAC9
#elif defined(__MSYS__)
#  define P_OS_MSYS
#elif defined(__CYGWIN__)
#  define P_OS_CYGWIN
#elif defined(_WIN64) || defined(_M_X64) || defined(_M_AMD64)
#  define P_OS_WIN64
#elif defined(__WIN32__) || defined(_WIN32) || defined(WIN32)
#  define P_OS_WIN
#elif defined(__linux) || defined(__linux__)
#  define P_OS_LINUX
#elif defined(__FreeBSD__)
#  define P_OS_FREEBSD
#  define P_OS_BSD4
#elif defined(__DragonFly__)
#  define P_OS_DRAGONFLY
#  define P_OS_BSD4
#elif defined(__NetBSD__)
#  define P_OS_NETBSD
#  define P_OS_BSD4
#elif defined(__OpenBSD__)
#  define P_OS_OPENBSD
#  define P_OS_BSD4
#elif defined(_AIX)
#  define P_OS_AIX
#elif defined(hpux) || defined(__hpux)
#  define P_OS_HPUX
#elif defined(__sun) || defined(sun)
#  define P_OS_SOLARIS
#elif defined(__QNXNTO__)
#  define P_OS_QNX6
#elif defined(__QNX__)
#  define P_OS_QNX
#elif defined(_SCO_DS)
#  define P_OS_SCO
#elif defined(__USLC__) || defined(__UNIXWARE__)
#  define P_OS_UNIXWARE
#elif defined(__svr4__) && defined(i386)
#  define P_OS_UNIXWARE
#elif defined(__sgi) || defined(sgi)
#  define P_OS_IRIX
#elif defined(__HAIKU__)
#  define P_OS_HAIKU
#elif defined(VMS) || defined(__VMS)
#  define P_OS_VMS
#endif

#ifdef P_OS_WIN64
#  define P_OS_WIN
#endif

#if defined(P_OS_DARWIN)
#  define P_OS_MAC
#  if defined(P_OS_DARWIN64)
#     define P_OS_MAC64
#  elif defined(P_OS_DARWIN32)
#     define P_OS_MAC32
#  endif
#endif

#if defined(P_OS_WIN) || defined(P_OS_MAC9)
#  undef P_OS_UNIX
#elif !defined(P_OS_UNIX)
#  define P_OS_UNIX
#endif

/*
 * List of supported compilers (P_CC_x):
 *
 * MSVC            - Microsoft Visual C/C++
 * GNU             - GNU C/C++
 * MINGW           - MinGW C/C++
 * INTEL           - Intel C/C++
 * CLANG           - LLVM Clang C/C++
 * SUN             - Sun WorkShop/Studio C/C++
 * XLC             - IBM XL C/C++
 * HP              - HP C/aC++
 * MIPS            - MIPSpro C/C++
 * USLC            - SCO OUDK and UDK C/C++
 * WATCOM          - Watcom C/C++
 * BORLAND         - Borland C/C++
 */

/**
 * @def P_CC_MSVC
 * @brief Microsoft Visual C/C++ compiler.
 * @since 0.0.1
 */

/**
 * @def P_CC_GNU
 * @brief GNU C/C++ compiler.
 * @since 0.0.1
 */

/**
 * @def P_CC_MINGW
 * @brief MinGW C/C++ compiler.
 * @since 0.0.1
 */

/**
 * @def P_CC_INTEL
 * @brief Intel C/C++ compiler.
 * @since 0.0.1
 */

/**
 * @def P_CC_CLANG
 * @brief LLVM Clang C/C++ compiler.
 * @since 0.0.1
 */

/**
 * @def P_CC_SUN
 * @brief Sun WorkShop/Studio C/C++ compiler.
 * @since 0.0.1
 */

/**
 * @def P_CC_XLC
 * @brief IBM XL C/C++ compiler.
 * @since 0.0.1
 */

/**
 * @def P_CC_HP
 * @brief HP C/aC++ compiler.
 * @since 0.0.1
 */

/**
 * @def P_CC_MIPS
 * @brief MIPSpro C/C++ compiler.
 * @since 0.0.1
 */

/**
 * @def P_CC_USLC
 * @brief SCO OUDK and UDK C/C++ compiler.
 * @since 0.0.1
 */

/**
 * @def P_CC_WATCOM
 * @brief Watcom C/C++ compiler.
 * @since 0.0.1
 */

/**
 * @def P_CC_BORLAND
 * @brief Borland C/C++ compiler.
 * @since 0.0.1
 */

#ifdef DOXYGEN
#  define P_CC_MSVC
#  define P_CC_GNU
#  define P_CC_MINGW
#  define P_CC_INTEL
#  define P_CC_CLANG
#  define P_CC_SUN
#  define P_CC_XLC
#  define P_CC_HP
#  define P_CC_MIPS
#  define P_CC_USLC
#  define P_CC_WATCOM
#  define P_CC_BORLAND
#endif

#if defined(_MSC_VER)
#  define P_CC_MSVC
#  if defined(__INTEL_COMPILER)
#    define P_CC_INTEL
#  endif
#elif defined(__GNUC__)
#  define P_CC_GNU
#  if defined(__MINGW32__)
#    define P_CC_MINGW
#  endif
#  if defined(__INTEL_COMPILER)
#    define P_CC_INTEL
#  endif
#  if defined(__clang__)
#    define P_CC_CLANG
#  endif
#elif defined(__SUNPRO_C) || defined(__SUNPRO_CC)
#  define P_CC_SUN
#elif defined(__xlc__) || defined(__xlC__)
#  define P_CC_XLC
#elif defined(__HP_cc) || defined(__HP_aCC)
#  define P_CC_HP
#elif (defined(__sgi) || defined(sgi)) && \
      (defined(_COMPILER_VERSION) || defined(_SGI_COMPILER_VERSION))
#  define P_CC_MIPS
#elif defined(__USLC__) && defined(__SCO_VERSION__)
#  define P_CC_USLC
#elif defined(__WATCOMC__)
#  define P_CC_WATCOM
#elif defined(__BORLANDC__)
#  define P_CC_BORLAND
#elif defined(__INTEL_COMPILER)
#  define P_CC_INTEL
#endif

/* For Clang */
#ifndef __has_attribute
#  define __has_attribute(x) 0
#endif

#ifndef __has_builtin
#  define __has_builtin(x) 0
#endif

/**
 * @def P_GNUC_WARN_UNUSED_RESULT
 * @brief Gives a warning if the result returned from a function is not being
 * used.
 * @since 0.0.1
 */

#if (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4)) || \
    __has_attribute(warn_unused_result)
#  define P_GNUC_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#else
#  define P_GNUC_WARN_UNUSED_RESULT
#endif

/**
 * @def P_LIB_API
 * @brief Exports a symbol from a shared library.
 * @since 0.0.1
 */

#if defined(P_CC_MSVC) || defined(P_CC_BORLAND) || defined(P_CC_WATCOM)
#  define P_LIB_API __declspec(dllexport)
#else
#  define P_LIB_API
#endif

/* Oracle Solaris Studio at least since 12.2 has ((noreturn)) attribute */

/**
 * @def P_NO_RETURN
 * @brief Notifies a compiler that a function will never return a value (i.e.
 * due to the abort () call).
 * @since 0.0.1
 */

#if defined (__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L)
#  define P_NO_RETURN _Noreturn
#elif defined(P_CC_MSVC) || (defined(P_CC_BORLAND) && __BORLANDC__ >= 0x0550)
#  define P_NO_RETURN __declspec(noreturn)
#elif __has_attribute(noreturn) || \
      defined(P_CC_GNU) || \
     (defined(P_CC_SUN) && __SUNPRO_C >= 0x5110) || \
     (defined(P_CC_SUN) && __SUNPRO_CC >= 0x5110)
#  define P_NO_RETURN __attribute__((noreturn))
#else
#  define P_NO_RETURN
#endif

/**
 * @def P_LIKELY
 * @brief Hints a compiler that a condition is likely to be true so it can
 * perform code optimizations.
 * @since 0.0.1
 */

/**
 * @def P_UNLIKELY
 * @brief Hints a compiler that a condition is likely to be false so it can
 * perform code optimizations.
 * @since 0.0.1
 */

#if (defined(P_CC_GNU) && (__GNUC__ > 2 && __GNUC_MINOR__ > 0)) || \
    (defined(P_CC_INTEL) && __INTEL_COMPILER >= 800) || \
    (defined(P_CC_XLC) && __xlC__ >= 0x0900) || \
    __has_builtin(__builtin_expect)
#  define P_LIKELY(x) __builtin_expect(!!(x), 1)
#  define P_UNLIKELY(x) __builtin_expect(!!(x), 0)
#else
#  define P_LIKELY(x) (x)
#  define P_UNLIKELY(x) (x)
#endif

/**
 * @def P_UNUSED
 * @brief Macro to by-pass a compiler warning on unused variables.
 * @since 0.0.1
 */
#define P_UNUSED(a) ((void) a)

/**
 * @def P_WARNING
 * @brief Prints a warning message.
 * @param msg Message to print.
 * @since 0.0.1
 */
#define P_WARNING(msg) printf ("** Warning: %s **\n", msg)

/**
 * @def P_ERROR
 * @brief Prints an error message.
 * @param msg Message to print.
 * @since 0.0.1
 */
#define P_ERROR(msg) printf ("** Error: %s **\n", msg)

/**
 * @def P_DEBUG
 * @brief Prints a debug message.
 * @param msg Message to print.
 * @since 0.0.1
 */
#define P_DEBUG(msg) printf ("** Debug: %s **\n", msg)

#ifdef DOXYGEN
#  define PLIBSYS_VERSION_MAJOR
#  define PLIBSYS_VERSION_MINOR
#  define PLIBSYS_VERSION_PATCH
#  define PLIBSYS_VERSION_STR
#  define PLIBSYS_VERSION
#endif

/**
 * @def PLIBSYS_VERSION_MAJOR
 * @brief Library major version number.
 * @since 0.0.1
 * @note This is the version against which the application is compiled.
 */

/**
 * @def PLIBSYS_VERSION_MINOR
 * @brief Library minor version number.
 * @since 0.0.1
 * @note This is the version against which the application is compiled.
 */

/**
 * @def PLIBSYS_VERSION_PATCH
 * @brief Library patch version number.
 * @since 0.0.1
 * @note This is the version against which the application is compiled.
 */

/**
 * @def PLIBSYS_VERSION_STR
 * @brief Library full version in the string form, i.e. "0.0.1".
 * @since 0.0.1
 * @note This is the version against which the application is compiled.
 * @sa p_libsys_version()
 */

/**
 * @def PLIBSYS_VERSION
 * @brief Library full version in the form 0xMMNNPP (MM = major, NN = minor,
 * PP = patch), i.e. 0x000001.
 * @since 0.0.1
 * @note This is the version against which the application is compiled.
 * @sa p_libsys_version()
 */

/**
 * @def PLIBSYS_VERSION_CHECK
 * @brief Makes a library version number which can be used to check the library
 * version against which the application is compiled.
 * @param major Major version number to check.
 * @param minor Minor version number to check.
 * @param patch Minor version number to check.
 * @since 0.0.1
 * @sa p_libsys_version()
 *
 * @code
 * if (PLIBSYS_VERSION >= PLIBSYS_VERSION_CHECK (0, 0, 1))
 * ...
 * @endcode
 */
#define PLIBSYS_VERSION_CHECK(major, minor, patch) ((major << 16) | (minor << 8) | (patch))

/**
 * @def P_BEGIN_DECLS
 * @brief Starts .h file declarations to be exported as C functions.
 * @since 0.0.1
 */

/**
 * @def P_END_DECLS
 * @brief Closes .h file declarations to be exported as C functions, should be
 * always used after #P_BEGIN_DECLS.
 * @since 0.0.1
 */

#ifdef __cplusplus
#  define P_BEGIN_DECLS extern "C" {
#  define P_END_DECLS }
#else
#  define P_BEGIN_DECLS
#  define P_END_DECLS
#endif

#endif /* PLIBSYS_HEADER_PMACROS_H */
