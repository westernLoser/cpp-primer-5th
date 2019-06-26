/*
  author : szz
  date : 2019/06/26
*/
#include<iostream>
#include<forward_list>

using std::forward_list;

int main() {
    forward_list<int> fl= {1, 2, 3, 4, 5};
    auto prev = fl.before_begin(), curr = fl.begin();
    while (curr != fl.end()) {
        if (*curr % 2 == 1) {
            curr = fl.erase_after(prev);
        }
        else {
            ++curr;
            ++prev;
        }
    }    
    for (auto n : fl) {
        std::cout << n << std::endl;
    }
    system("pause");
    return 0;
}