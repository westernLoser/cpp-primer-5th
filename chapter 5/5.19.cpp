/*
  author : szz
  date : 2019/06/17
*/
#include<iostream>
#include<string>

using std::string;

int main() {
    string rsp;
    do {
        std::cout << "Input two strings: ";
        string s1, s2;
        std::cin >> s1 >> s2;
        std::cout << (s1.size() > s2.size() ? s2: s1)
                  << " is shorter. " << std::endl;
        std::cout << "continue? y/n ";
        std::cin >> rsp;
    }while (!rsp.empty() && tolower(rsp[0]) == 'y');    
    system("pause");
    return 0;
}