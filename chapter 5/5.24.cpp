/*
  author : szz
  date : 2019/06/17
*/
#include<iostream>
#include<stdexcept>

int main() {
    int a, b;
    std::cin >> a >> b;
    if (b == 0) {
        throw std::runtime_error("divisor can not be zero!");
    }
    std::cout << a / b << std::endl;
    system("pause");
    return 0;
}