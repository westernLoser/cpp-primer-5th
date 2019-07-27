/*
  author : szz
  date : 2019/07/26
*/
#include<iostream>
#include"16.29.h"

int main() {
    Bolb<int> b;
    b.push_back(1);
    b.push_back(2);
    std::cout << b[1] << std::endl;    
    system("pause");
    return 0;
}