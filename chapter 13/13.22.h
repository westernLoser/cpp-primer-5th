/*
  author : szz
  date : 2019/07/09
*/
#ifndef C_13_22_H
#define C_13_22_H

#include <string>

class HasPtr
{
public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr &orig) : ps(new std::string(*orig.ps)), i(orig.i) {}
    HasPtr& operator=(const HasPtr &rhs);
    ~HasPtr() { delete ps; }
private:
    std::string *ps;
    int i;
};

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    if (this != &rhs)
    {
        *ps = *rhs.ps;
        i = rhs.i;
    }
    return *this;
}

#endif
