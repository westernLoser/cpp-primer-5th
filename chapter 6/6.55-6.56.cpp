/*
  author : szz
  date : 2019/06/21
*/
#include<iostream>
#include<vector>
#include<stdexcept>

using std::vector;
int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

int _div(int a, int b) {
    if (b == 0) {
        throw std::runtime_error("divisor can not be zero");
    }
    return a / b;
}

int main() {
    vector<decltype(add)*> v{add, sub, mul, _div};
    for (auto &f : v) {
        std::cout << (*f)(2, 2) << std::endl;
    }
    system("pause");
    return 0;
}