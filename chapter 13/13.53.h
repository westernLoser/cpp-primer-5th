/*
  author : szz
  date : 2019/07/14
*/
#ifndef C_13_53_H
#define C_13_53_H

#include <string>
#include<iostream>

class HasPtr
{
public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr &orig) : ps(new std::string(*orig.ps)), i(orig.i) {}
    HasPtr(HasPtr&&) noexcept;
    friend void swap(HasPtr&, HasPtr&);
    friend bool operator<(const HasPtr &lhs, const HasPtr &rhs);
    HasPtr& operator=(const HasPtr&);
    HasPtr& operator=(HasPtr&&) noexcept;
    void show() { std::cout << *ps << std::endl; }
    ~HasPtr() { delete ps; }
private:
    std::string *ps;
    int i;
};

inline
void swap(HasPtr &lhs, HasPtr &rhs) {
    std::cout << "call swap(HasPtr &lhs, HasPtr &rhs)" << std::endl;
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

bool operator<(const HasPtr &lhs, const HasPtr &rhs) {
    return *lhs.ps < *rhs.ps;
}

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    if (this != &rhs)
    {
        *ps = *rhs.ps;
        i = rhs.i;
    }
    return *this;
}

HasPtr& HasPtr::operator=(HasPtr &&rhs) noexcept {
    if (this != &rhs) {
        delete ps;
        ps = rhs.ps;
        i = rhs.i;
        rhs.ps = nullptr;
        rhs.i = 0;
    }
    return *this;
}

HasPtr::HasPtr(HasPtr &&p) noexcept : ps(p.ps), i(p.i) {
    p.ps = nullptr;
}

#endif