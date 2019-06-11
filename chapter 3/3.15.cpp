/*
  author : szz
  date : 2019/06/11
*/
#include<iostream>
#include<vector>
#include<string>

using std::vector;
using std::string;

int main() {
    vector<string> v;
    string s;
    while (std::cin >> s) {
        v.push_back(s);
    }

    for (auto &x : v) {
        std::cout << x << std::endl;
    }
    system("pause");
    return 0;
}