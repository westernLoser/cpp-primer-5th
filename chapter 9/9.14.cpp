/*
  author : szz
  date : 2019/06/25
*/
#include<iostream>
#include<list>
#include<vector>
#include<string>

using std::list; using std::vector; using std::string;

int main() {
    list<char *> l = {"aaa", "bbb", "ccc"};
    vector<string> v;
    v.assign(l.begin(), l.end());
    for (auto &s : v) {
        std::cout << s << std::endl;
    }
    system("pause");
    return 0;
}