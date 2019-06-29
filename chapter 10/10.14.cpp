/*
  author : szz
  date : 2019/06/29
*/
#include<iostream>

int main() {
    auto add = [](int a, int b) { return a + b; };
    std::cout << add(1, 2) << std::endl;    
    system("pause");
    return 0;
}