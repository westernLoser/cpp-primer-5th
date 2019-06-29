/*
  author : szz
  date : 2019/06/29
*/
#include<iostream>

int main() {
    int a = 5;
    auto f = [&a]() { return a-- != 0; };   
    while (f())
        std::cout << a << std::endl; 
    system("pause");
    return 0;
}