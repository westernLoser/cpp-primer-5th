/*
  author : szz
  date : 2019/06/26
*/
#include<iostream>
#include<forward_list>
#include<string>

using std::string; using std::forward_list;

void find_and_insert(forward_list<string> &l, const string &s1, const string &s2) {
    auto prev = l.before_begin();
    for (auto curr = l.begin(); curr != l.end(); prev = curr++) {
        if (*curr == s1) {
            l.insert_after(curr, s2);
            return;
        }
    }
    l.insert_after(prev, s2);
}
int main() {
    forward_list<string> fls = {"aaa", "bbb", "ddd"};
    find_and_insert(fls, "bbb", "ccc");
    for (auto &s : fls) {
        std::cout << s << std::endl;
    }
    system("pause");
    return 0;
}