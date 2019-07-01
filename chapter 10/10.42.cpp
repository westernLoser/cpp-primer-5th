/*
  author : szz
  date : 2019/07/01
*/
#include<iostream>
#include<list>

using std::list;

int main() {
    list<int> li{1, 2, 3, 4, 5, 1, 2, 3, 4 ,5};
    li.sort();
    li.unique();
    for (auto n : li) std::cout << n << std::endl;    
    system("pause");
    return 0;
}