#include <assert.h>
#include <string>
#include <iostream>
#include "include/leveldb/db.h"
//  验证计算机是大端存储还是小端存储

#include <stdio.h>

int main()
{
    int a = 1;
    char *p;
    p = (char *)(&a);
    if(*p == 0 )
        printf("当前计算机是大端存储\n");
    else
        printf("当前计算机是小端存储\n");
    return 0;

}

