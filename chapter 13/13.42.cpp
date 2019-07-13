/*
  author : szz
  date : 2019/07/12
*/
#include<iostream>
#include<fstream>
#include"13.42_text.h"

void runQueries(std::ifstream &infile) {
    TextQuery tq(infile);
    while (true) {
        std::cout << "enter word to look for, or q to quit: ";
        std::string s;
        if (!(std::cin >> s) || s == "q") break;
        print(std::cout, tq.query(s));
    }
}
int main() {
    std::ifstream ifs("C:\\Users\\admin\\Desktop\\cpp-primer\\cpp-primer-5th\\chapter 12\\12.27.txt");
    runQueries(ifs);
    system("pause");
    return 0;
}