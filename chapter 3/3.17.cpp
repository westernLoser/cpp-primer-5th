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
    vector<string> vs;
    string cur;
    while (std::cin >> cur) {
        vs.push_back(cur);
    }

    for (auto &s : vs) {
        for (auto &c : s) {
            c = toupper(c);
        }
        std::cout << s << std::endl;
    }

    system("pause");
    return 0;
}