/*
  author : szz
  date : 2019/06/21
*/
#ifndef C_7_4_H
#define C_7_4_H

#include<string>
#include<iostream>

using std::string; using std::istream; using std::ostream;

class Person {
    friend istream &read(istream &is, Person &p);
    friend ostream &print(ostream &os, const Person &p);
private:
    string Name;
    string Address;
public:
    Person() = default;
    Person(string name, string addr): Name(name), Address(addr) {};
    Person(istream &is);
    string name() const {
        return Name;
    }
    string address() const {
        return Address;
    }
};
istream &read(istream &is, Person &p);
ostream &print(ostream &os, const Person &p);
#endif