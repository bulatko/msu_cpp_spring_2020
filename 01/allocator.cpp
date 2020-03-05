#include "allocator.h"
#include <cstdlib>

char* block;
int last = 0, block_size;


void makeAllocator(int num){

block = (char*)malloc(num);
block_size = num;
}

char* alloc(int num){

int t = last;
if(last + num > block_size)
    return nullptr;
last += num;
return block + t;
}

void reset(){

last = 0;

}
