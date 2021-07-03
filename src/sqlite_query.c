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

sqlite_query_t sqq;
char *pass = "NULL";

int callback(void *pt, int argc, char **argv,
             char **azCol)
{
    char **result_str = (char **)pt;

    *result_str = (char *)calloc(strlen(argv[0]), sizeof(char));

    strcpy(*result_str, argv[0]);

    return SQLITE_OK;
}

char *sqlite_query_get_password(const char *username)
{
    sqlite3 *db;
    char *err;
    unsigned int retval;
    char *password = malloc(sizeof(char) * 100);

    retval = sqlite3_open(DB_PATH, &db);
    RN(db, retval);

    char *sql = malloc(sizeof(char) * 100);

    sprintf(sql, "SELECT password FROM users WHERE username = '%s';", username);

    retval = sqlite3_exec(db, sql, callback, &password, &err);
    RN(db, retval);

    return password;
}