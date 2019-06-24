/*
  author : szz
  date : 2019/06/24
*/
#include<iostream>
#include<sstream>
#include<string>
std::istream &read(std::istream &is) {
    std::string buf;
    while (is >> buf) std::cout << buf << std::endl;
    is.clear();
    return is;
}
int main() {
    std::string s = "a b c";
    std::istringstream is(s);
    read(is);
    system("pause");
    return 0;
}