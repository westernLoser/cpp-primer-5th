/*
  author : szz
  date : 2019/07/18
*/
#include<iostream>
#include<vector>
#include<string>
#include"14.35.h"

using std::vector; using std::string;

int main() {
    InputString in;
    vector<string> vs;
    string cur;
    while (!(cur = in()).empty())
        vs.push_back(cur);
    for (auto &s : vs) {
        std::cout << s << std::endl;
    }
    system("pause");
    return 0;
}