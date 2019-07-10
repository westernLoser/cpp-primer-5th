/*
  author : szz
  date : 2019/07/09
*/
#ifndef C_13_27_H
#define C_13_27_H

#include<string>

class HasPtr {
public:
    HasPtr(const std::string &s): ps(new std::string(s)), i(0), use(new std::size_t(1)) { }
    HasPtr(const HasPtr &orig): ps(orig.ps), i(orig.i), use(orig.use) { ++*use; }
    HasPtr& operator=(const HasPtr &rhs) {
        ++*rhs.use;
        if (--*use == 0) {
            delete ps;
            delete use;
        }
        ps = rhs.ps;
        i = rhs.i;
        use = rhs.use;
        return *this;
    }
    ~HasPtr() {
        if (--*use == 0) {
            delete ps;
            delete use;
        }
    }
private:
    std::string *ps;
    int i;
    size_t *use;
};

#endif
