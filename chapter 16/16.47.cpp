/*
  author : szz
  date : 2019/07/27
*/
#include<iostream>
#include<utility>

void f(int &&a, int &b) {
    std::cout << a << " " << ++b << std::endl; 
}

template<typename F, typename T1, typename T2>
void flip(F f, T1 &&v1, T2 &&v2) {
    f(std::forward<T2>(v2), std::forward<T1>(v1));
}

int main() {
    int a = 1;
    flip(f, a, 42);
    std::cout << a << std::endl;
    system("pause");
    return 0;
}