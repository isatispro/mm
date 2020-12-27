#include <stdio.h>
#include <stdlib.h>

#define PAGE_SIZE (4096)

char *pTextLib = "The  mallopt()  function  adjusts parameters that control the behavior of the memory-allocation functions (see malloc(3)).  The param argument specifies the parameter to be modi‐fied, and value specifies the new value for that parameter.";

int gDataLib[PAGE_SIZE * 1024] = {1};

int gBssLib[PAGE_SIZE * 1024] = {0};

void mm_lib_init(void) {

    printf("################################ lib start ########################################### \r\n");
    printf("text addr:%p, data addr:%p, bss addr:%p\r\n", pTextLib, gDataLib, gBssLib);
    printf("################################ lib end ############################################# \r\n");

    return;
}
