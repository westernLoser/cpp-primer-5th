/*
  author : szz
  date : 2019/06/26
*/
#include<iostream>
#include<deque>
#include<string>

using std::string; using std::deque;
int main() {
    deque<string> dq;
    string s;
    while (std::cin >> s)
        dq.push_back(s);
    for (auto &s : dq)
        std::cout << s << std::endl;
    system("pause");
    return 0;
}