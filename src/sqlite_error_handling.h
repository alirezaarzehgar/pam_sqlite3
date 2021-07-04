/**
 * @file sqlite_error_handling.h
 * @author alirezaarzehgar (alirezaarzehgar82@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-07-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#if !defined(_SQLITE_ERROR_HANDLING_H)
#define _SQLITE_ERROR_HANDLING_H

#include <sqlite3.h>

/**
 * @brief sqlite_report helper macro 
 * @param db database handler for getting error messages
 * @param msg custom error message for alert
 * @param retval returned error code
 * @param callback custom function callback for extra functionality
 */
#define R(db, retval, msg, callback) ({ sqlite_report(db, retval, msg, callback); })

/**
 * @brief R macro helper macro
 * 
 * @param db database handler for getting error messages
 * @param retval returned error code
 * 
 */
#define RN(db, retval) ({ sqlite_report(db, retval, NULL, NULL); })

/**
 * @brief reporting sqlite errors
 * 
 * @param db database handler for getting error messages
 * @param retval returned error code
 * @param msg custom error message for alert
 * @param callback custom function callback for extra functionality
 */
void sqlite_report(
    sqlite3 *db,       /* database handler for getting error messages */
    int retval,        /* returned error code */
    const char *msg,   /* custom error message for alert */
    void (*callback)() /* custom function callback for extra functionality */
);

#endif // _SQLITE_ERROR_HANDLING_H
