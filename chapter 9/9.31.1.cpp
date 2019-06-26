/*
  author : szz
  date : 2019/06/26
*/
#include<iostream>
#include<list>

using std::list;

int main() {
    list<int> li = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto it = li.begin();
    while (it != li.end()) {
        if (*it % 2) {
            it = li.insert(it, *it);
            std::advance(it, 2);
        }
        else {
            it = li.erase(it);
        }
    }
    for (auto n : li) {
        std::cout << n << std::endl;
    }
    system("pause");
    return 0;
}