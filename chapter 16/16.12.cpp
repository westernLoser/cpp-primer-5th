/*
  author : szz
  date : 2019/07/25
*/
#include<iostream>
#include"16.12.h"

int main() {
    Bolb<int> b = {1, 2, 3};
    for (auto p = b.begin(); p != b.end(); p.incr()) {
        std::cout << p.deref() << std::endl;
    }
    system("pause");
    return 0;
}