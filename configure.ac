#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

# AC_INIT(package, version, [bug-report], [tarname], [url])
AC_INIT([bgp_platform], [0.1.0],
    [liuxf19@163.com], [bgp_platform], [https://github.com/Timothy-Liuxf/bgp_platform])
AC_CONFIG_SRCDIR([src/bgp_platform/main.cc])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIRS([m4 third_party/autoconf-archive/m4])
AC_PROG_RANLIB

AM_INIT_AUTOMAKE([foreign subdir-objects tar-pax])

AX_CXX_COMPILE_STDCXX_17([noext], [mandatory])
CXXFLAGS=""

AS_CASE([X$BUILD_CONFIG],
    [XRelease|Xrelease|X], [
        AX_APPEND_COMPILE_FLAGS([                                                      dnl
                -O2 -DSIMPLE_LOGGER_ENABLE_LOG_INFO                                    dnl
            ], [CXXFLAGS])
    ],
    [XDebug|Xdebug], [
        AX_APPEND_COMPILE_FLAGS([                                                      dnl
                -g -Og -DSIMPLE_LOGGER_ENABLE_LOG_DEBUG                                dnl
            ], [CXXFLAGS])
    ],
    [AC_MSG_ERROR([Unknown build configuration: $BUILD_CONFIG!])])

AX_APPEND_COMPILE_FLAGS([-Wall -Wpedantic -Wextra], [CXXFLAGS])
AX_APPEND_COMPILE_FLAGS([-pthread], [CXXFLAGS])
AX_APPEND_COMPILE_FLAGS([                                                              dnl
    -Isrc                                                                              dnl
    -Ithird_party/jsoncons/include                                                     dnl
    -Ithird_party/inotify-cpp/src/include                                              dnl
    -Ithird_party/fmt/include -DFMT_HEADER_ONLY                                        dnl
    -Ithird_party/simple_logger/include                                                dnl
    -Ithird_party/tclap/include                                                        dnl
], [CXXFLAGS])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CPP
AC_PROG_MAKE_SET

# Checks for libraries.
AX_CHECK_LIBPQXX_VERSION
AC_CHECK_LIB([pq], [PQconnectdb], [], [AC_MSG_ERROR([libpq not found])])
AC_CHECK_LIB([pqxx], [PQconnectdb], [], [AC_MSG_ERROR([libpqxx not found])])

# Checks for programs
AC_CHECK_PROG([BGPDUMP], [bgpdump], [yes])
AS_IF([test X"$BGPDUMP" != X"yes"], [AC_MSG_ERROR([bgpdump not found])])
AC_CHECK_PROG([PYTHON3], [python3], [yes])
AS_IF([test X"$PYTHON3" != X"yes"], [AC_MSG_ERROR([python3 not found])])

# Checks for header files.
AC_CHECK_HEADERS([unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_INT16_T
AC_TYPE_INT32_T
AC_TYPE_INT64_T
AC_TYPE_INT8_T
AC_TYPE_SIZE_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T
AC_TYPE_UINT8_T
AC_CHECK_TYPES([ptrdiff_t])

# Checks for library functions.
AC_FUNC_ERROR_AT_LINE
AC_FUNC_MALLOC
AC_FUNC_STRTOD
AC_FUNC_MKTIME
AC_CHECK_FUNCS([dup2 floor localeconv memmove memset pow select sqrt strtol strtoul])

# Build third party libraries
AX_BUILD_THIRD_PARTY

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
