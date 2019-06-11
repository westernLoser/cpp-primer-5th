/*
  author : szz
  date : 2019/06/11
*/
#include<iostream>
#include<vector>

using std::vector;

int main() {
    vector<int> v;
    int n;
    while (std::cin >> n) {
        v.push_back(n);
    }

    for (auto &x : v) {
        std::cout << x << std::endl;
    }
    system("pause");
    return 0;
}