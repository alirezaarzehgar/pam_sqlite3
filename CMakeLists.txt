cmake_minimum_required(VERSION 3.2)

project(pam_sqlite3)

set(CMAKE_C_FLAGS 
    "${CMAKE_C_FLAGS} -lsqlite3 -lpam -lpam_misc")

set(LIBS
    src/md5.c
    src/sqlite_error_handling.c
    src/sqlite_query.c
)

set(SOURCES
    ${LIBS}
    src/pam_sqlite3.c
)

set(TEST_SOURCES    
    ${LIBS}
    test/sqlite_test.c
)

add_library(pam_sqlite3 SHARED
    ${SOURCES}
)

install(TARGETS pam_sqlite3
    LIBRARY DESTINATION /lib/security)

add_executable(unit_tests
    ${TEST_SOURCES}
)

add_test(test_all unit_tests)

configure_file(config.h.in ../src/config.h)