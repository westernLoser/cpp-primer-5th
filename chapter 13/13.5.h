/*
  author : szz
  date : 2019/07/08
*/
#ifndef C_13_5_H
#define C_13_5_H

#include<string>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()) :
        ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr &orig) :
        ps(new std::string(*orig.ps)), i(orig.i) { }
private:
    std::string *ps;
    int i;
};

#endif