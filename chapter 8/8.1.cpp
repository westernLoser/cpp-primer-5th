/*
  author : szz
  date : 2019/06/24
*/
#include<iostream>
#include<string>
std::istream &read(std::istream &is) {
    std::string buf;
    while (is >> buf) std::cout << buf << std::endl;
    is.clear();
    return is;
}
int main() {
    std::istream &is = read(std::cin);
    std::cout << is.rdstate() << std::endl;
    system("pause");
    return 0;
}