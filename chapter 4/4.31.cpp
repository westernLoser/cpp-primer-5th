/*
  author : szz
  date : 2019/06/13
*/
#include<iostream>
#include<vector>

using std::vector;

int main() {
    vector<int> v(5);
    auto cnt = v.size();
    for (vector<int>::size_type ix = 0;
         ix != v.size(); ix++, cnt--) {
             v[ix] = cnt;
        }
    for (auto &n : v) {
        std::cout << n << std::endl;
    }
    system("pause");
    return 0;
}