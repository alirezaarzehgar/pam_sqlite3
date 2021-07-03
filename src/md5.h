/**
 * @file md5.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-07-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#ifndef _MD5_H
#define _MD5_H

/**
 * @brief convert to byte
 * 
 * @param val char type input parameter
 * @param bytes int pointer for containing casted char
 */
void to_bytes(
    uint32_t val,  /* char type input parameter */
    uint8_t *bytes /* int pointer for containing casted char */
);

/**
 * @brief convert uint8_t to uint32_t (int)
 * 
 * @param bytes input byte code
 * @return uint32_t 
 */
uint32_t to_int32(
    const uint8_t *bytes /* input byte code */
);

/**
 * @brief create md5
 * 
 * @param initial_msg text argument for converting to md5 hash
 * @param initial_len text lenght
 * @param digest md5 result
 */
void md5(
    const uint8_t *initial_msg, /* text argument for converting to md5 hash */
    size_t initial_len,         /* text lenght */
    uint8_t *digest             /* md5 result */
);

/**
 * @brief convert string to md5
 * 
 * @param digest digest raw resulted md5
 * @return char* 
 */
char *str2md5(
    uint8_t *digest /* digest raw resulted md5 */
);

/**
 * @brief create md5 hash and return string
 * 
 * @param initial_msg simple text
 * @return char* 
 */
char *MD5(
    const uint8_t *initial_msg /* simple text */
);

#endif /* md5.h */