/*
  author : szz
  date : 2019/06/17
*/
#include<iostream>

void swap(int *p1, int *p2) {
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}
int main() {
    int a = 2, b = 3;
    std::cout << "a: " << a << " b: " << b << std::endl;
    std::cout << "after swap: " << std::endl;
    swap(&a, &b);
    std::cout << "a: " << a << " b: " << b << std::endl;
    system("pause");
    return 0;
}