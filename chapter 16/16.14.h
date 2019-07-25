/*
  author : szz
  date : 2019/07/25
*/
#ifndef C_16_14_H
#define C_16_14_H

#include<iostream>
#include<string>

template<unsigned H, unsigned W>
class Screen {
public:
    friend std::istream& operator>>(std::istream &is, const Screen &);
    friend std::ostream& operator<<(std::ostream &os, Screen &);
    typedef std::string::size_type pos;
    Screen(char c = ' '): contents(H * W, c) { }
    char get() const { return contents[cur]; }
    Screen& move(pos r, pos c) {
        cur = r * width + c;
        return *this;
    }
private:
    pos cur = 0;
    pos height = H, width = W;
    std::string contents;
};

template<unsigned H, unsigned W>
std::istream& operator>>(std::istream &is, const Screen<H, W> &s) {
   char c;
   is >> c;
   s.contents = std::string(H * W, c);
   return is;
}

template<unsigned H, unsigned W>
std::ostream& operator<<(std::ostream &os, Screen<H, W> &s) {
    for (int i = 0; i < H; ++i) {
        os << s.contents.substr(0, W) << std::endl;
    }
    return os;
}

#endif