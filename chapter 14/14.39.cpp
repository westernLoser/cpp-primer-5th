/*
  author : szz
  date : 2019/07/19
*/
#include<iostream>
#include<fstream>
#include<string>
#include<limits.h>
#include"14.38.h"

int main() {
    int res1 = 0, res2 = 0;
    std::ifstream ifs("C:\\Users\\admin\\Desktop\\cpp-primer\\cpp-primer-5th\\chapter 14\\14.38.txt");
    std::string word;
    CheckString cs1(1, 9), cs2(10, INT_MAX);
    while (ifs >> word) {
        if (cs1(word))
            ++res1;
        if (cs2(word))
            ++res2;
    }    
    std::cout << "the number of word with length in [1, 9] is " << res1 << std::endl;
    std::cout << "the number of word with length bigger than 10 is " << res2 << std::endl;
    system("pause");
    return 0;
}