#include "allocator.h"
#include <cstdlib>
#include <iostream>
#define MAX_AVALIBLE_SIZE 100000
char *block;
size_t last = 0, block_size;

void makeAllocator(size_t num)
{

    if (block = (char *)malloc(num))
        block_size = num;
    else
        block_size = 0;
}

char *alloc(size_t num)
{

    int t = last;

    if (last + num > block_size)
        return nullptr;

    last += num;

    return block + t;
}

void reset()
{

    last = 0;
}
