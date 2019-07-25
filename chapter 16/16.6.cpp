/*
  author : szz
  date : 2019/07/24
*/
#include<iostream>

template<typename T, unsigned N>
T* begin(T (&arr)[N]) {
    return arr;
}

template<typename T, unsigned N>
T* end(T (&arr)[N]) {
    return arr + N;
}

int main() {
    int a[] = {1, 2, 3};
    for (auto p = begin(a); p != end(a); ++p) {
        std::cout << *p << std::endl;
    }    
    system("pause");
    return 0;
}