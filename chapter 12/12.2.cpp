/*
  author : szz
  date : 2019/07/03
*/
#include<iostream>
#include"12.2.h"

int main() {
    StrBolb b1;
    {
        StrBolb b2 = {"a", "b", "c"};
        b1 = b2;
    }
    std::cout << b1.size() << std::endl;

    system("pause");
    return 0;
}