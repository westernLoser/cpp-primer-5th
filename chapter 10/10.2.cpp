/*
  author : szz
  date : 2019/06/28
*/
#include<iostream>
#include<string>
#include<list>
#include<algorithm>

using std::string; using std::list;

int main() {
    list<string> ls;
    string cur;
    while (std::cin >> cur) ls.push_back(cur);
    string val = "hello";
    std::cout << "hello occurs " << std::count(ls.begin(), ls.end(), val) << " times" << std::endl;    
    system("pause");
    return 0;
}