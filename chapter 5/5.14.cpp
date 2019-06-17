/*
  author : szz
  date : 2019/06/17
*/
#include<iostream>
#include<string>

using std::string;

int main() {
    string pre, cur, maxS;
    int curCount, maxCount = 0;
    while (std::cin >> cur) {
        curCount = cur == pre ? curCount + 1 : 1;
        if (curCount > maxCount) {
            maxCount = curCount;
            maxS = cur;
        } 
        pre = cur;
    }
    if (maxCount > 1) {
        std::cout << "the word " << maxS << " occurred " << maxCount << " times." << std::endl;
    } 
    else {
        std::cout << "There's no duplicated string." << std::endl;
    }
    system("pause");
    return 0;
}