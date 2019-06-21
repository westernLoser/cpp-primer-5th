/*
  author : szz
  date : 2019/06/19
*/
#include<iostream>
#include<initializer_list>

using std::initializer_list;

int sum(initializer_list<int> il) {
    int sum = 0;
    for (auto &n : il) {
        sum += n;
    }
    return sum;
}

int main() {
    std::cout << sum({1, 2, 3, 4, 5}) << std::endl;
    system("pause");
    return 0;
}