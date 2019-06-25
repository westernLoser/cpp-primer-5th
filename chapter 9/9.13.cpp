/*
  author : szz
  date : 2019/06/25
*/
#include<iostream>
#include<vector>
#include<list>

using std::vector;
using std::list;

int main() {
    list<int> li = {1, 2, 3, 4, 5};
    vector<int> vi = {1, 2, 3, 4, 5};
    vector<double> vb_li(li.begin(), li.end());
    vector<double> vb_vi(vi.begin(), vi.end());
    for (auto n : vb_li) {
        std::cout << n << std::endl;
    }
    for (auto n : vb_vi) {
        std::cout << n << std::endl;
    }
    system("pause");
    return 0;
}