cmake_minimum_required(VERSION 3.2)

project(pam_sqlite3)

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    include_directories(/usr/include)
endif()

if(${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD")    
    include_directories(/usr/local/include /usr/include)
endif()

set(CMAKE_C_FLAGS 
    "${CMAKE_C_FLAGS} -lsqlite3 -lpam")

set(LIBS
    src/md5.c
    src/sqlite_error_handling.c
    src/sqlite_query.c
)

set(SOURCES
    ${LIBS}
    src/pam_sqlite3.c
)

add_library(pam_sqlite3 SHARED
    ${SOURCES}
)

install(TARGETS pam_sqlite3
    LIBRARY DESTINATION /lib/security)

configure_file(config.h.in ../src/config.h)