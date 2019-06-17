/*
  author : szz
  date : 2019/06/17
*/
#include<iostream>
#include<string>

using std::string;

int main() {
    string cur, pre;
    bool flag = false;
    while (std::cin >> cur) {
        if (cur == pre && !cur.empty() && isupper(cur[0])) {
            flag = true;
            break;
        }
        pre = cur;
    }
    if (flag) {
        std::cout << "the word is: " << cur << std::endl;
    }
    else {
        std::cout << "no word starting with upper character was repeated." << std::endl;
    }
    system("pause");
    return 0;
}