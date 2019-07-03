/*
  author : szz
  date : 2019/07/03
*/
#include<iostream>
#include<map>
#include<string>

using std::map; using std::string;

int main() {
    string cur;
    map<string, string::size_type> m;
    while (std::cin >> cur) {
        auto ret = m.insert({cur, 1});
        if (!ret.second) {
            ++ret.first -> second;
        }
    }
    for (auto &p : m) {
        std::cout << p.first << " " << p.second << std::endl;
    }
    system("pause");
    return 0;
}