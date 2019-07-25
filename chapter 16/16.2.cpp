/*
  author : szz
  date : 2019/07/24
*/
#include<iostream>
#include<functional>

template<typename T>
int compare(const T &lhs, const T &rhs) {
    if (std::less<T>()(lhs, rhs)) {
        return -1;
    }
    else if (std::less<T>()(rhs, lhs)) {
        return 1;
    }
    return 0;
}
int main() {
    std::cout << compare(1, 2) << std::endl;
    system("pause");
    return 0;
}