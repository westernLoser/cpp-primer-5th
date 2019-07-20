/*
  author : szz
  date : 2019/07/19
*/
#include<iostream>
#include<string>
#include<fstream>
#include"14.38.h"

int main() {
    for (int i = 1; i <= 10; ++i) {
        CheckString cs(i);
        std::ifstream ifs("C:\\Users\\admin\\Desktop\\cpp-primer\\cpp-primer-5th\\chapter 14\\14.38.txt");
        std::string word;
        int res = 0;
        while (ifs >> word) {
            if (cs(word))
                ++res;
        }
        std::cout << "the number of word with length " << i << " is " << res << std::endl;
    }
    system("pause");
    return 0;
}