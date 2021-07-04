/**
 * @file pam_get_password.h
 * @author alirezaarzehgar (alirezaarzehgar82@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-07-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#if !defined(_PAM_GET_PASSWORD_H)
#define _PAM_GET_PASSWORD_H

#include <security/pam_appl.h>

/**
 * @brief Get the password object
 * 
 * @param pamh pam handler for passing to another functions
 * @param prompt custom prompt
 * @return char* 
 */
char *pam_get_password(
    pam_handle_t *pamh, /* pam handler for passing to another functions */
    const char *prompt  /* custom prompt */
);

#endif // _PAM_GET_PASSWORD_H
