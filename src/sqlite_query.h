/**
 * @file sqlite_query.h
 * @author alirezaarzehgar (alirezaarzehgar82@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-07-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#if !defined(_SQLITE_QUERY_H)
#define _SQLITE_QUERY_H

typedef struct sqlite_query
{
    char *username;
    char *password;
} sqlite_query_t;

char *sqlite_query_get_password(const char *username);

#endif // _SQLITE_QUERY_H
