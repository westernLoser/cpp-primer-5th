/*
  author : szz
  date : 2019/07/10
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include"13.31.h"

using std::vector;

int main() {
    vector<HasPtr> v;
    v.emplace_back("ccc");
    v.emplace_back("bbb");
    v.emplace_back("aaa");
    for (auto &p : v) p.show(); 
    std::sort(v.begin(), v.end());   
    for (auto &p : v) p.show(); 
    system("pause");
    return 0;
}