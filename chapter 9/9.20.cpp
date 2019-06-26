/*
  author : szz
  date : 2019/06/26
*/
#include<iostream>
#include<list>
#include<deque>

using std::list; using std::deque;

int main() {
    list<int> li = {1, 2, 3, 4, 5};
    deque<int> d1, d2;
    for (auto n : li) {
        if (n % 2)
            d1.push_back(n);
        else
            d2.push_back(n);
        
    }

    for (auto n : d1) std::cout << n << std::endl;
    for (auto n : d2) std::cout << n << std::endl;        
    
    system("pause");
    return 0;
}