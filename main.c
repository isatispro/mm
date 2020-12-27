#include <stdio.h>
#include <stdlib.h>
#include "main.h"

#define PAGE_SIZE (4096)
#define SIZE_1K (1024)

char *pText = "The  mallopt()  function  adjusts parameters that control the behavior of the memory-allocation functions (see malloc(3)).  The param argument specifies the parameter to be modi‐fied, and value specifies the new value for that parameter.";

int gData[PAGE_SIZE * 1024] = {1};

int gBss[PAGE_SIZE * 1024] = {0};

int main(int argc, char *argv[]) {
    
    char *pHeap = NULL;
    char *pMmap = NULL;

    pHeap = malloc(SIZE_1K * 64);
    pMmap = malloc(SIZE_1K * 1024 * 4);

    printf("################################ main start ########################################### \r\n");
    printf("text addr:%p, data addr:%p, bss addr:%p\r\n", pText, gData, gBss);
    printf("heap addr:%p, mmap addr:%p\r\n", pHeap, pMmap);
    printf("################################ main end ############################################# \r\n");

    mm_lib_init();

    getchar();

    free(pHeap);
    free(pMmap);
    return 0;
}
