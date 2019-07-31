/*
  author : szz
  date : 2019/07/29
*/
#include<iostream>
#include<string>

using std::string;

template<typename T, typename ... Args>
void foo(const T &t, const Args& ... rest) {
    std::cout << sizeof...(Args) << std::endl;
    std::cout << sizeof...(rest) << std::endl;
}

int main() {
    int i = 0;
    double d = 3.14;
    string s = "aaa";
    foo(i, s, 42, d);
    foo(s, 42, "hi");
    foo(d, s);
    foo("hi");    
    system("pause");
    return 0;
}