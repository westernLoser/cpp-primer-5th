/*
  author : szz
  date : 2019/07/25
*/
#ifndef C_16_21_H
#define C_16_21_H

#include<iostream>

class DebugDelete {
public:
    DebugDelete(std::ostream &s = std::cerr): os(s) { }
    template<typename T>
    void operator()(T *p) const {
        os << "deleting shared_ptr" << std::endl;
        delete p;
    }
private:
    std::ostream &os;
};

#endif