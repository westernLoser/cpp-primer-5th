/*
  author : szz
  date : 2019/06/11
*/
#include<iostream>
#include<string>

int main() {
    std::string s1, s2;
    std::cin >> s1 >> s2;

    //比较大小
    if (s1 == s2) {
        std::cout << "s1 equals s2" << std::endl;
    }
    else if (s1 > s2) {
        std::cout << "The bigger one is " << s1 << std::endl;
    }
    else {
        std::cout << "The bigger one is " << s2 << std::endl;
    }

    //比较长短
    if (s1.size() == s2.size()) {
        std::cout << "s1 and s2 have same length" << std::endl;
    }
    else if (s1.size() > s2.size()) {
        std::cout << "The longer one is " << s1 << std::endl;
    }
    else {
        std::cout << "The longer one is " << s2 << std::endl;
    }

    system("pause");
    return 0;
}