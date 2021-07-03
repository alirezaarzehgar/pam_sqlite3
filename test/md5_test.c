/**
 * @file md5_test.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-07-03
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../src/md5.h";
#include <stdio.h>

int main(int argc, char const *argv[])
{
    const char *password = md5_create("ali");

    puts(password);
    return 0;
}
