#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Jerry.h"

int main(int argc, char* argv[])
{
    printf("Hello World \n");

    if(argc > 1)
    {
        printf("%s \n", argv[1]);
        printf("%s \n", argv[2]);
        printf("%s \n", argv[3]);
    }
    return 0;

    
}