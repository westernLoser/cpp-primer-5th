/*
  author : szz
  date : 2019/07/24
*/
#include<iostream>

template<unsigned N, typename T>
void print(T (&arr)[N]) {
    for (size_t i = 0; i != N; ++i) {
        std::cout << arr[i] << std::endl;
    }
}

int main() {
    int a[3] = {1, 2, 3};
    char b[5] = {'a', 'b', 'c', 'd', 'e'};
    print(a);
    print(b);    
    system("pause");
    return 0;
}