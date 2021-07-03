/**
 * @file sqlite_test.c
 * @author alirezaarzehgar (alirezaarzehgar82@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-07-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "../src/config.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../src/md5.h"
#include "../src/sqlite_query.h"

/**
 * @brief main func
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char const *argv[])
{
    sqlite_query_get_password("ali");

    return 0;
}
