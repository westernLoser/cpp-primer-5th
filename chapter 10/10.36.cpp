/*
  author : szz
  date : 2019/07/01
*/
#include<iostream>
#include<list>
#include<algorithm>

using std::list;

int main() {
    list<int> li{1, 2, 0, 1, 2, 0, 1};
    auto it = std::find(li.crbegin(), li.crend(), 0);
    std::cout << *it << std::endl;    
    system("pause");
    return 0;
}