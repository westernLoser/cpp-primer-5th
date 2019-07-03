/*
  author : szz
  date : 2019/07/03
*/
#include<iostream>
#include<vector>
#include<memory>

using std::vector;

void input(std::shared_ptr<vector<int>> v) {
    int n;
    while (std::cin >> n)
        v->push_back(n);
}

void output(std::shared_ptr<vector<int>> v) {
    for (auto n : *v)
        std::cout << n << std::endl;
}

int main() {
    auto v = std::make_shared<vector<int>>();
    input(v);
    output(v);
    system("pause");
    return 0;
}