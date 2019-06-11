/*
  author : szz
  date : 2019/06/11
*/
#include<iostream>
#include<vector>

using std::vector;

int main() {
    vector<int> v;
    int cur;
    while (std::cin >> cur) {
        v.push_back(cur);
    }
    for (decltype(v.size()) i = 0; i < v.size() - 1; ++i) {
        std::cout << v[i] + v[i + 1] << std::endl;
    }
    for (decltype(v.size()) i = 0; i < v.size(); ++i) {
        std::cout << v[i] + v[v.size() - i - 1] << std::endl;
    }
    system("pause");
    return 0;
}