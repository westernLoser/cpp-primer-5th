/*
  author : szz
  date : 2019/07/03
*/
#include<iostream>
#include<map>
#include<string>
#include<algorithm>
#include<set>

using std::string; using std::multimap; using std::map; using std::multiset;

int main() {
    multimap<string, string> painter{
        {"mary", "sky"},
        {"mary", "house"},
        {"jack", "flower"},
        {"jack", "bird"}
    };

    map<string, multiset<string>> ordered_painter;
    for (auto &p : painter) {
        ordered_painter[p.first].insert(p.second);
    }

    for (auto &p : ordered_painter) {
        std::cout << "author: " << p.first << std::endl;
        std::cout << "worker: ";
        for (auto &s : p.second) {
            std::cout << " " << s;
        } 
        std::cout << std::endl;
    }
    system("pause");
    return 0;
}