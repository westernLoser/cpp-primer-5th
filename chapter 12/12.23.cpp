/*
  author : szz
  date : 2019/07/05
*/
#include<iostream>
#include<string>
#include<string.h>

int main() {
    char *p = new char[100]();
    strcat(p, "hello ");
    strcat(p, "world");
    std::cout << p << std::endl;
    delete[] p;

    std::string s1{"hello "}, s2{"world"};
    std::cout << s1 + s2 << std::endl;
    system("pause");
    return 0;
}