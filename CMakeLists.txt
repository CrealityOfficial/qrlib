if(CMAKE_USE_PTHREADS_INIT)
    add_definitions(-DHAVE_LIBPTHREAD=1)
    # for libqrencode.pc
    set(LIBPTHREAD ${CMAKE_THREAD_LIBS_INIT})
endif()

## Check for system include files
include(CheckIncludeFile)
include(CheckFunctionExists)

check_include_file(dlfcn.h    HAVE_DLFCN_H   )
check_include_file(inttypes.h HAVE_INTTYPES_H)
check_include_file(memory.h   HAVE_MEMORY_H  )
check_include_file(stdint.h   HAVE_STDINT_H  )
check_include_file(stdlib.h   HAVE_STDLIB_H  )
check_include_file(strings.h  HAVE_STRINGS_H )
check_include_file(string.h   HAVE_STRING_H  )
check_include_file(getopt.h   HAVE_GETOPT_H  )
check_include_file(sys/time.h HAVE_SYS_TIME_H)
check_include_file(time.h     HAVE_TIME_H    )
check_include_file(pthread.h  HAVE_PTHREAD_H )

check_function_exists(strdup HAVE_STRDUP)

if(HAVE_STRDUP)
    add_definitions(-DHAVE_STRDUP=1)
endif()

if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
endif()

if(GPROF)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pg")
endif()

if(COVERAGE)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage")
endif()

if(ASAN)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls")
endif()

add_definitions(-DMAJOR_VERSION=4)
add_definitions(-DMINOR_VERSION=1)
add_definitions(-DMICRO_VERSION=0)
add_definitions(-DVERSION="4.1.0")
add_definitions(-DHAVE_SDL=0)

if(MSVC)
    add_definitions(-Dstrcasecmp=_stricmp)
    add_definitions(-Dstrncasecmp=_strnicmp)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    add_definitions(-D_CRT_NONSTDC_NO_DEPRECATE)
endif(MSVC)
add_definitions(-DSTATIC_IN_RELEASE=static)

set(QRENCODE_SRCS internal/qrencode.c
                  internal/qrinput.c
                  internal/bitstream.c
                  internal/qrspec.c
                  internal/rsecc.c
                  internal/split.c
                  internal/mask.c
                  internal/mqrspec.c
                  internal/mmask.c)

set(QRENCODE_HDRS internal/qrencode_inner.h
				  internal/qrencode.h
                  internal/qrinput.h
                  internal/bitstream.h
                  internal/qrspec.h
                  internal/rsecc.h
                  internal/split.h
                  internal/mask.h
                  internal/mqrspec.h
                  internal/mmask.h)

if(MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()


set(SRCS interface/qrlib/interface.h
		 interface/qrlib/urlqrcode.h
		 impl/urlqrcode.cpp
		 ${QRENCODE_SRCS}
		 ${QRENCODE_HDRS}
		 )
		 
set(INCS ${CMAKE_CURRENT_SOURCE_DIR}/interface/
		 ${CMAKE_CURRENT_SOURCE_DIR}/internal/)
		 
set(INERTFACES ${CMAKE_CURRENT_SOURCE_DIR}/interface/)

__add_platform_library(qrlib)