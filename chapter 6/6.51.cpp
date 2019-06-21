/*
  author : szz
  date : 2019/06/20
*/
#include<iostream>

void f() {
    std::cout << "no parameter" << std::endl;
}

void f(int) {
    std::cout << "int" << std::endl;
}

void f(int, int) {
    std::cout << "int, int" << std::endl;
}

void f(double, double = 3.14) {
    std::cout << "double, double = 3.14" << std::endl;
}

int main() {
    //f(2.56, 42);
    f(42);
    f(42, 0);
    f(2.56, 3.14);
    system("pause");
    return 0;
}