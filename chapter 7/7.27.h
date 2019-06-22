/*
  author : szz
  date : 2019/06/22
*/
#ifndef C_7_27_H
#define C_7_27_H

#include<string>
#include<iostream>

using std::string;

class Screen {
public:
    using pos = string::size_type;
    Screen() = default;
    Screen(pos h, pos w): height(h), width(w), contents(h * w, ' ') {};
    Screen(pos h, pos w, char c): height(h), width(w), contents(h * w, c) {};
    Screen &move(pos r, pos c);
    Screen &set(char c);
    Screen &set(pos r, pos c, char ch);
    Screen &display(std::ostream &os);
    const Screen &display(std::ostream &os) const;
private:
    pos height = 0, width = 0, cursor = 0;
    string contents;
    void do_display(std::ostream &os) const;
};

inline Screen &Screen::move(pos r, pos c) {
    cursor = r * width + c;
    return *this;
}

inline Screen &Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos r, pos c, char ch) {
    contents[r * width + c] = ch;
    return *this;
}

inline Screen &Screen::display(std::ostream &os) {
    do_display(os);
    return *this;
}

inline const Screen &Screen::display(std::ostream &os) const {
    do_display(os);
    return *this;
}

inline void Screen::do_display(std::ostream &os) const {
    os << contents;
}

#endif