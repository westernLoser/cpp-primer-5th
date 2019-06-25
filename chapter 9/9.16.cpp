/*
  author : szz
  date : 2019/06/25
*/
#include<iostream>
#include<vector>
#include<list>

using std::vector; using std::list; 

int cmp(const vector<int> &a, const list<int> &b) {
    auto it1 = a.begin();
    auto it2 = b.begin();
    while (it1 != a.end() || it2 != b.end()) {
        if (it1 == a.end()) return 1;
        if (it2 == b.end()) return -1;
        if (*it1 < *it2) return 1;
        else if (*it1 > *it2) return -1; 
        ++it1;
        ++it2;
    }
    return 0;
}
int main() {
    vector<int> v1 = {1, 2, 3};
    list<int> l1 = {0, 1, 2}, l2 = {1, 2, 3}, l3 = {2};
    std::cout << cmp(v1, l1) << " " << cmp(v1, l2) << " " << cmp(v1, l3) << std::endl;
    system("pause");
    return 0;
}