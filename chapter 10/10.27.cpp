/*
  author : szz
  date : 2019/06/29
*/
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<iterator>

using std::vector; using std::list;
int main() {
    vector<int> v{1, 1, 1, 2, 2, 3};
    list<int> li;
    std::unique_copy(v.begin(), v.end(), std::back_inserter(li));
    for (auto n : li) std::cout << n << std::endl;
    system("pause");
    return 0;
}