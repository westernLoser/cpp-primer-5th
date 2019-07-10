/*
  author : szz
  date : 2019/07/10
*/
#ifndef C_13_30_H
#define C_13_30_H

#include <string>
#include<iostream>
class HasPtr
{
public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr &orig) : ps(new std::string(*orig.ps)), i(orig.i) {}
    friend void swap(HasPtr&, HasPtr&);
    HasPtr& operator=(const HasPtr &rhs);
    void show() { std::cout << *ps << std::endl; }
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

inline
void swap(HasPtr &lhs, HasPtr &rhs) {
    std::cout << "call swap(HasPtr &lhs, HasPtr &rhs)" << std::endl;
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, lhs.i);
}

#endif
