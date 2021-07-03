/**
 * @file sqlite_query.c
 * @author alirezaarzehgar (alirezaarzehgar82@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-07-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "config.h"

#include <sqlite3.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "sqlite_query.h"
#include "sqlite_error_handling.h"

char *sqlite_query_get_password(const char *username)
{
    sqlite3 *db;
    char *err;
    unsigned int retval;

    retval = sqlite3_open(DB_PATH, &db);
    RN(db, retval);
}