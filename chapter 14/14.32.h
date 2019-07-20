/*
  author : szz
  date : 2019/07/18
*/
#ifndef C_14_32_H
#define C_14_32_H

#include"..\chapter 12\12.19.h"

class StrBolbPtrPtr {
public:
    StrBolbPtrPtr(StrBolbPtr *p) : pointer(p) { }
    StrBolbPtr* operator->() const { return pointer; }
private:
    StrBolbPtr *pointer;
};

#endif