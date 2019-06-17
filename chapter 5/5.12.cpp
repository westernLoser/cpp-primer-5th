/*
  author : szz
  date : 2019/06/17
*/
#include<iostream>

int main() {
    int ffCnt = 0, flCnt = 0, fiCnt = 0;
    char c, pre = '#';
    while (std::cin >> c) {
        if (pre == 'f') {
            if (c == 'f') ++ffCnt;
            else if (c == 'l') ++flCnt;
            else if (c == 'i') ++fiCnt;
        }
        pre = c;
    }
    std::cout << "The number of ff is : \t" << ffCnt << '\n'
            << "The number of fl is : \t" << flCnt << '\n'
            << "The number of fi is : \t" << fiCnt << std::endl;
    system("pause");
    return 0;
}