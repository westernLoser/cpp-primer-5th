/*
  author : szz
  date : 2019/09/03
*/
#include<iostream>
#include<unordered_set>
#include"16.62.h"

using std::unordered_set;

int main() {
    unordered_set<Sales_data> s;
    s.emplace("aaa");
    for (auto &sd : s) {
        std::cout << sd.isbn() << std::endl;
    }
    system("pause");
    return 0;
}