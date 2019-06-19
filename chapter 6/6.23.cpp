/*
  author : szz
  date : 2019/06/18
*/
#include<iostream>

void print(const int a[], size_t len) {
    while (len--) {
        std:: cout << *a++ << std::endl;
    }
}
int main() {
    int i = 0;
    int j[2] = {0, 1};
    print(&i, 1);
    print(j, 2);
    system("pause");
    return 0;
}