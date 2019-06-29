/*
  author : szz
  date : 2019/06/28
*/
#include<iostream>
#include<vector>
#include<algorithm>

using std::vector;

int main() {
    vector<int> v;
    int cur;
    while (std::cin >> cur) v.push_back(cur);
    int val = 1;
    std::cout << "1 occurs " << std::count(v.begin(), v.end(), val) << " times" << std::endl;    
    system("pause");
    return 0;
}