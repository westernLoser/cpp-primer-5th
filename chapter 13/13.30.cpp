/*
  author : szz
  date : 2019/07/10
*/
#include<iostream>
#include"13.30.h"

int main() {
    HasPtr sp1("aaa"), sp2("bbb");
    swap(sp1, sp2);
    sp1.show();
    sp2.show();
    system("pause");
    return 0;
}