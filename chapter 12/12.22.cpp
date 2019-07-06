/*
  author : szz
  date : 2019/07/05
*/
#include<iostream>
#include"12.22.h"

int main() {   
    const StrBolb sb = {"aaa", "bbb", "ccc"};
    for (auto it = sb.begin(); it != sb.end(); it.incr()) {
        std::cout << it.deref() << std::endl;
    }
    system("pause");
    return 0;
}