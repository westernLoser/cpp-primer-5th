/*
  author : szz
  date : 2019/06/28
*/
#include<iostream>
#include<vector>
#include<algorithm>

using std::vector;

int main() {
    vector<int> v{1, 2, 3};
    std::fill_n(v.begin(), v.size(), 0);
    for (auto n : v) std::cout << n << std::endl;    
    system("pause");
    return 0;
}