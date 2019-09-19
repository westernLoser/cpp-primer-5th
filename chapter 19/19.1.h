/*
  author : szz
  date : 2019/09/16
*/

#ifndef C_19_1_H
#define C_19_1_H

#include<cstdlib>
#include<new>

void* operator new(size_t size) {
    if (void *mem = malloc(size)) {
        return mem;
    }
    throw std::bad_alloc();
}

void operator delete(void* mem) noexcept {
    free(mem);
}

#endif