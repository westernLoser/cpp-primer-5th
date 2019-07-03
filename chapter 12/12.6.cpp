/*
  author : szz
  date : 2019/07/03
*/
#include<iostream>
#include<vector>

using std::vector;

void input(vector<int> *v) {
    int n;
    while (std::cin >> n)
        v->push_back(n);
}

void output(vector<int> *v) {
    for (auto n : *v)
        std::cout << n << std::endl;
}

int main() {
    auto v = new vector<int>;
    input(v);
    output(v);
    delete v;
    system("pause");
    return 0;
}