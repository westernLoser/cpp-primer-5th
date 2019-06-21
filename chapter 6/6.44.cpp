/*
  author : szz
  date : 2019/06/19
*/
#include<iostream>
#include<string>

using std::string;

inline bool isShorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}

int main() {
    string s1 = "abc", s2 = "abcd";
    std::cout << std::boolalpha << isShorter(s1, s2) << std::endl;     
    system("pause");
    return 0;
}