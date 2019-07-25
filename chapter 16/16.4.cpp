/*
  author : szz
  date : 2019/07/24
*/
#include<iostream>
#include<vector>
#include<list>
#include<string>

using std::vector; using std::list; using std::string;

template<typename _iter, typename _val>
_iter find(_iter begin, _iter end, const _val &v) {
    for (_iter p = begin; p != end; ++p) {
        if (*p == v)
            return p;
    }
    return end;
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    auto p = find(v.begin(), v.end(), 3);
    if (p != v.end()) {
        std::cout << *p << std::endl;
    }
    list<string> ls = {"aaa", "bbb", "ccc"};
    auto it = find(ls.begin(), ls.end(), "bbb");
    if (it != ls.end()) {
        std::cout << *it << std::endl;
    }
    system("pause");
    return 0;
}