/*
  author : szz
  date : 2019/06/11
*/
#include<iostream>
#include<string>
using std::string;

int main() {
    string s("abc");
    string::size_type i = 0;
    while (i < s.size()) {
        s[i++] = 'X';
    }
    std::cout << s << std::endl;

    s = "abc";
    for (decltype(s.size()) idx = 0; idx < s.size(); ++idx) {
        s[idx] = 'X';
    }     
    std::cout << s << std::endl;
    system("pause");
    return 0;
}