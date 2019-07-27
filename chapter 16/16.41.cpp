/*
  author : szz
  date : 2019/07/26
*/
#include<iostream>

template<typename T>
auto sum(const T &lhs, const T &rhs) -> decltype(lhs + rhs) {
    return lhs + rhs;
}

int main() {
    
    system("pause");
    return 0;
}