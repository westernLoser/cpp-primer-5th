/*
  author : szz
  date : 2019/07/24
*/
#include<iostream>

template<typename T, unsigned N>
constexpr unsigned len(T (&arr)[N]) {
    return N;
}

int main() {
    int a[] = {1, 2, 3};
    std::cout << len(a) << std::endl;
    int b[len(a)];
    system("pause");
    return 0;
}