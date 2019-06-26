/*
  author : szz
  date : 2019/06/26
*/
#include<iostream>
#include<vector>
#include<list>

using std::vector; using std::list;

int main() {
    int ia[] = {0, 1, 1 ,2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> v;
    list<int> l;
    for (auto n : ia) {
        v.push_back(n);
        l.push_back(n);
    }
    auto it1 = v.begin();
    auto it2 = l.begin();
    while (it1 != v.end()) {
        if (*it1 % 2 == 0) {
            it1 = v.erase(it1);
        }
        else {
            ++it1;
        }
    
        
    }
    while (it2 != l.end()) {
        if (*it2 % 2) {
            it2 = l.erase(it2);
        }
        else {
            ++it2;
        }
    }
    for (auto n : v) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    for (auto n : l) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    system("pause");
    return 0;
}