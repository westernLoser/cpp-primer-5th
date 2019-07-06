/*
  author : szz
  date : 2019/07/04
*/
#include<iostream>
#include<memory>

int main() {
    std::unique_ptr<int> p(new int(0));
    auto q = p;    
    system("pause");
    return 0;
}