/*
  author : szz
  date : 2019/07/19
*/
#ifndef C_14_38_H
#define C_14_38_H

#include<string>

class CheckString {
    int lower, upper;
public:
    CheckString(int n): lower(n), upper(n) { }
    CheckString(int n, int m): lower(n), upper(m) { }
    bool operator()(const std::string &s) {
        return s.size()>= lower && s.size() <= upper;
    }

};

#endif