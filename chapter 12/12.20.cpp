/*
  author : szz
  date : 2019/07/05
*/
#include<iostream>
#include<fstream>
#include"12.19.h"

int main() {
    std::ifstream ifs("C:\\Users\\admin\\Desktop\\cpp-primer\\cpp-primer-5th\\chapter 12\\12.20.txt");    
    StrBolb sb;
    std::string cur;
    while (ifs >> cur) {
        sb.push_back(cur);
    }
    for (auto it = sb.begin(); it != sb.end(); it.incr()) {
        std::cout << it.deref() << std::endl;
    }
    system("pause");
    return 0;
}