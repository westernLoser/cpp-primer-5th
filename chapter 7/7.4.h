/*
  author : szz
  date : 2019/06/21
*/
#ifndef C_7_4_H
#define C_7_4_H

#include<string>

using std::string;

class Person {
    string Name;
    string Address;
public:
    string name() const {
        return Name;
    }
    string address() const {
        return Address;
    }
};

#endif