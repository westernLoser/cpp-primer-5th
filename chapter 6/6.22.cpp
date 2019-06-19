/*
  author : szz
  date : 2019/06/18
*/
#include<iostream>

void swap(int *&pp1, int *&pp2) {
    int *tmp = pp1;
    pp1 = pp2;
    pp2 = tmp;
}
int main() {
    int a = 2, b = 3, *p1 = &a, *p2 = &b;
    std::cout << "p1 point to " << p1 << " p2 point to " << p2 << std::endl;
    swap(p1, p2);
    std::cout << "p1 point to " << p1 << " p2 point to " << p2 << std::endl;
    system("pause");
    return 0;
}