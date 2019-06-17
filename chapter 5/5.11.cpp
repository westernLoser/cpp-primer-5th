/*
  author : szz
  date : 2019/06/17
*/
#include<iostream>
#include<string>

using std::string;

int main() {
    char c;
    int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0, spaceCnt = 0, tabCnt = 0, newLineCnt = 0;
    while (std::cin >> std::noskipws >> c) {
        auto ch = tolower(c);
        if (ch == 'a') ++aCnt;
        else if (ch == 'e') ++eCnt;
        else if (ch == 'i') ++iCnt;
        else if (ch == 'o') ++oCnt;
        else if (ch == 'u') ++uCnt;
        else if (ch == ' ') ++spaceCnt;
        else if (ch == '\t') ++tabCnt;
        else if (ch == '\n') ++newLineCnt;
    }
    std::cout << "Number of vowel a: \t" << aCnt << '\n'
            << "Number of vowel e: \t" << eCnt << '\n'
            << "Number of vowel i: \t" << iCnt << '\n'
            << "Number of vowel o: \t" << oCnt << '\n'
            << "Number of vowel u: \t" << uCnt << '\n'
            << "Number of space: \t" << spaceCnt << '\n'
            << "Number of tab char: \t" << tabCnt << '\n'
            << "Number of new line: \t" << newLineCnt << std:: endl;
    system("pause");
    return 0;
}