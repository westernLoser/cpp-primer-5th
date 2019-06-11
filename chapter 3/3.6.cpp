/*
  author : szz
  date : 2019/06/11
*/
#include<iostream>
#include<string>

int main() {
    std::string s("abc");
    for (auto &c :s) {
        c = 'X';
    }
    std::cout << s << std::endl;
    system("pause");
    return 0;
}