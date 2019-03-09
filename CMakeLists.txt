cmake_minimum_required(VERSION 3.0)

project(SteveScratchC)

set(CMAKE_C_STANDARD 11)

set(PROJECT_DIR
    src
    src/ssc
    src/ssc/interface
    src/ssc/lua
    src/ssc
    src/ssc/core
    src/ssc/core/scratch
)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

foreach(DIR ${PROJECT_DIR})
    aux_source_directory(${DIR} TEMP_VAR)
    set(SOURCE_FILE ${SOURCE_FILE} ${TEMP_VAR})
endforeach(DIR)

if(WIN32)
    add_definitions("-DWINDOWS")
elseif(UNIX)
    add_definitions("-DUNIX")
elseif(APPLE)
    add_definitions("-DOSX")
endif(WIN32)

if (CMAKE_BUILD_TYPE MATCHES "Debug")
    add_definitions("-DDEBUG")
endif(CMAKE_BUILD_TYPE MATCHES "Debug")

add_executable(SteveScratchC ${SOURCE_FILE})
add_definitions (${GTK3_CFLAGS_OTHER})
target_link_libraries (SteveScratchC ${GTK3_LIBRARIES})
