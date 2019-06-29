/*
  author : szz
  date : 2019/06/29
*/
#include<iostream>

int main() {
    int a = 1;
    auto add_a = [a](int b) { return a + b; };
    std::cout << add_a(2) << std::endl;     
    system("pause");
    return 0;
}