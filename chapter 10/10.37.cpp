/*
  author : szz
  date : 2019/07/01
*/
#include<iostream>
#include<vector>
#include<list>
#include<iterator>
#include<algorithm>

using std::vector; using std::list;

int main() {
    vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> li;
    std::copy(v.cbegin() + 3, v.cbegin() + 8, std::front_inserter(li));
    for (auto n : li) std::cout << n << std::endl;
    system("pause");
    return 0;
}