/*
  author : szz
  date : 2019/07/18
*/
#ifndef C_14_35_H
#define C_14_35_H

#include<iostream>

class InputString {
public:
    InputString(std::istream &is = std::cin): _is(is) { };
    std::string operator()();
private:
    std::istream& _is;
};

std::string InputString::operator()() {
    std::string cur;
    std::getline(_is, cur);
    if (!_is)
        cur = "";
    return cur;
}

#endif