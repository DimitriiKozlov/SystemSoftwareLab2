//
// Created by dimirtii on 11.11.15.
//

#ifndef SPZLAB2_ALLOCATOR_H
#define SPZLAB2_ALLOCATOR_H
#include <iostream>


// Show memory status
void mem_dump();

// Take memory space in byte
void *mem_allocByte(size_t);

// Take memory space in page
void *mem_alloc(size_t);

// Get index of memory
size_t getIndexOfMemory(void*);

// Get address of memory
void *getAddressOfMemory(size_t);



#endif //SPZLAB2_ALLOCATOR_H
