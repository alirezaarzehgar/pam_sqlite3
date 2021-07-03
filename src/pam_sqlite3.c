/**
 * @file pam_sqlite3.c
 * @author alirezaarzehgar (alirezaarzehgar82@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-07-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "config.h"

#include <security/pam_appl.h>
#include <security/pam_modules.h>
#include <security/pam_ext.h>

#include "sqlite_query.h"

#include "md5.h"

/**
 * @brief define password and username prompt
 * 
 */
#define USERNAME_PROMPT "Username: "
#define PASSWORD_PROMPT "Password: "

/**
 * @brief set credentioal
 * 
 * @param pamh pam handler
 * @param flags pam flags
 * @param argc count of external pam.d config arguments
 * @param argv external pam.d config arguments
 * @return int 
 */
PAM_EXTERN int pam_sm_setcred(pam_handle_t *pamh, int flags, int argc, const char **argv)
{
    return PAM_SUCCESS;
}

/**
 * @brief handle account management
 * 
 * @param pamh pam handler
 * @param flags pam flags
 * @param argc count of external pam.d config arguments
 * @param argv external pam.d config arguments
 * @return int
 */
PAM_EXTERN int pam_sm_acct_mgmt(pam_handle_t *pamh, int flags, int argc, const char **argv)
{
    return PAM_SUCCESS;
}

/**
 * @brief handle authentication
 * 
 * @param pamh pam handler
 * @param flags pam flags
 * @param argc count of external pam.d config arguments
 * @param argv external pam.d config arguments
 * @return int
 */
PAM_EXTERN int pam_sm_authenticate(pam_handle_t *pamh, int flags, int argc, const char **argv)
{
    const char *username;
    const char *password;

    pam_get_user(pamh, &username, USERNAME_PROMPT);

    pam_get_authtok(pamh, PAM_AUTHTOK, &password, NULL);

    const char *excepted_password = sqlite_query_get_password(username);

    if (strcmp(excepted_password, MD5(password)) == 0)
    {
        return PAM_SUCCESS;
    }

    return PAM_AUTH_ERR;
}