/*
  author : szz
  date : 2019/06/26
*/
#include<iostream>
#include<forward_list>

using std::forward_list;

int main() {
    forward_list<int> li = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto it = li.begin(), prev = li.before_begin();
    while (it != li.end()) {
        if (*it % 2) {
            it = li.insert_after(it, *it);
            std::advance(it, 1);
            std::advance(prev, 2);
        }
        else {
            it = li.erase_after(prev);
        }
    }
    for (auto n : li) {
        std::cout << n << std::endl;
    }
    system("pause");
    return 0;
}