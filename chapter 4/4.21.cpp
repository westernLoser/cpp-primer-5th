/*
  author : szz
  date : 2019/06/13
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
    for (auto &n : v) {
        n = n % 2 == 1 ? n * 2 : n;
        std::cout << n <<std::endl;
    }
    system("pause");
    return 0;
}