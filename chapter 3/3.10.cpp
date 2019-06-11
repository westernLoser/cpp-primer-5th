/*
  author : szz
  date : 2019/06/11
*/
#include<iostream>
#include<string>
using std::string;

int main() {
    string s;
    std::cin >> s;
    for (auto &c : s) {
        if (!ispunct(c)) {
            std::cout << c;
        }
    }    
    system("pause");
    return 0;
}