/*
  author : szz
  date : 2019/06/21
*/
#include"7.4.h"

istream &read(istream &is, Person &p) {
    is >> p.Name >> p.Address;
    return is;
}

ostream &print(ostream &os, const Person &p) {
    os << p.name() << "  " << p.address();
    return os;
}