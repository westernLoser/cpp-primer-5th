/*
  author : szz
  date : 2019/06/22
*/
#ifndef C_7_23_H
#define C_7_23_H

#include<string>
using std::string;
class Screen {
public:
    using pos = string::size_type;
    Screen() = default;
    Screen(pos h, pos w): height(h), width(w), contents(h * w, ' ') {};
    Screen(pos h, pos w, char c): height(h), width(w), contents(h * w, c) {};
private:
    pos height = 0, width = 0, cursor = 0;
    string contents;
};

#endif