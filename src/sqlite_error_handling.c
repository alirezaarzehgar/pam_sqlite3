/**
 * @file sqlite_error_handling.c
 * @author alirezaarzehgar (alirezaarzehgar82@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-07-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "sqlite_error_handling.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief reporting sqlite errors
 * 
 * @param db database handler for getting error messages
 * @param retval returned error code
 * @param msg custom error message for alert
 * @param callback custom function callback for extra functionality
 */
void sqlite_report(sqlite3 *db, int retval, const char *msg, void (*callback)())
{
    /* run callback function is it does exists */
    if (*callback != NULL)
    {
        (*callback)(); /* run custom user callback */
    }

    if (retval != SQLITE_OK)
    {
        fprintf(stderr, "%s%s%s\n",
                msg == NULL ? "" : msg,
                msg == NULL ? "" : ": ",
                sqlite3_errmsg(db));

        exit(EXIT_FAILURE);
    }
}
