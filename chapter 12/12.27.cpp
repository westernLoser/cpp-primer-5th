/*
  author : szz
  date : 2019/07/06
*/
#include<iostream>
#include<fstream>
#include"12.27.h"

int main() {
    std::ifstream ifs("C:\\Users\\admin\\Desktop\\cpp-primer\\cpp-primer-5th\\chapter 12\\12.27.txt");
    TextQuery tq(ifs);
    tq.query("aaa").print();
    system("pause");
    return 0;
}