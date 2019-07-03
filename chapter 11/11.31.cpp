/*
  author : szz
  date : 2019/07/03
*/
#include<iostream>
#include<map>
#include<string>
#include<algorithm>

using std::string; using std::multimap;

int main() {
    multimap<string, string> painter{
        {"jack", "bird"},
        {"jack", "flower"},
        {"mary", "sky"},
        {"mary", "house"}
    };
    for (auto pos = painter.equal_range("mary");
         pos.first != pos.second; ++pos.first) {
        if (pos.first -> second == "house") {
            painter.erase(pos.first);
            break;
        }
    }   
    for (auto &p : painter) {
        std::cout << p.first << " " << p.second << std::endl;
    }
    
    system("pause");
    return 0;
}