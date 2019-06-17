/*
  author : szz
  date : 2019/06/17
*/
#include<iostream>

int main() {
    int a, b;
    std::cin >> a >> b;
    if (b != 0) {
        std::cout << a / b << std::endl;
    }   
    else {
        std::cout << "divisor can not be zero! " << std::endl;
    }
    system("pause");
    return 0;
}