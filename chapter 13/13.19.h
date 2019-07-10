/*
  author : szz
  date : 2019/07/09
*/
#ifndef C_13_19_H
#define C_13_19_H

#include<string>

class Employee {
public:
    Employee(std::string s = "No Name"): name(s), id(unique++) { }
    Employee(const Employee&) = delete;
    Employee& operator=(const Employee&) = delete;
private:
    std::string name;
    static int unique;
    int id;
};

int Employee::unique = 0;

#endif