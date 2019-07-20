/*
  author : szz
  date : 2019/07/12
*/
#include<iostream>
#include"13.44.h"

int main() {
    String s("aaa");
    s.show();    
    for (int i = 0; i < 10; ++i) {
        s.push_back('a');
        std::cout << s.size() << " " << s.capacity() << std::endl;
        s.show();
    }
    //for 14.7
    std::cout << "s: " << s << std::endl;
    system("pause");
    return 0;
}