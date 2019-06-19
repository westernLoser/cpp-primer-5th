/*
  author : szz
  date : 2019/06/18
*/
#include<iostream>

int cmp(int a, const int *p) {
    if (a > *p) {
        return a;
    }
    return *p;
}
int main() {
    int a = 1, b = 2;
    std::cout << cmp(a, &b) << std::endl;
    system("pause");
    return 0;
}