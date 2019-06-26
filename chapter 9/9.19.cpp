/*
  author : szz
  date : 2019/06/26
*/
#include<iostream>
#include<list>
#include<string>

using std::string; using std::list;
int main() {
    list<string> dq;
    string s;
    while (std::cin >> s)
        dq.push_back(s);
    for (auto &s : dq)
        std::cout << s << std::endl;
    system("pause");
    return 0;
}