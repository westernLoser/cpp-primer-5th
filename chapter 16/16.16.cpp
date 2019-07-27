/*
  author : szz
  date : 2019/07/25
*/
#include<iostream>
#include"16.16.h"

int main() {
    Vec<int> v;
    v.push_back(1);
    v.resize(3);
    for (auto p = v.begin(); p != v.end(); ++p) {
        std::cout << *p << std::endl;
    }    
    system("pause");
    return 0;
}