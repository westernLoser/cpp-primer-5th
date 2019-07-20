/*
  author : szz
  date : 2019/07/19
*/
#include<iostream>
#include<functional>
#include<map>
#include<string>

using std::string; using std::map;

int multi(int a, int b) {
    return a * b;
}

struct divide {
    int operator()(int a, int b) {
        return a / b;
    }
};

int main() {
    map<string, std::function<int(int, int)>> binops;
    binops["+"] = std::plus<int>();
    binops["-"] = [](int a, int b) { return a - b; };
    binops["*"] = multi;        
    binops["/"] = divide();
    auto mod = [](int a, int b) { return a % b; };
    binops["%"] = mod;
    for (auto &p : binops) {
        std::cout << p.first << " ";
        std::cout << p.second(4, 2) << std::endl;
    }
    system("pause");
    return 0;
}