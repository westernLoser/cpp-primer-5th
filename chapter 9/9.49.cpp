/*
  author : szz
  date : 2019/06/27
*/
#include<iostream>
#include<string>
#include<fstream>

using std::string;

int main() {
    std::ifstream ifs("C:\\Users\\admin\\Desktop\\cpp-primer\\cpp-primer-5th\\chapter 9\\9.49.txt");    
    if (!ifs) return -1;
    string res;
    string::size_type longest = 0;
    for (string cur; ifs >> cur; ) {
        if (cur.find_first_not_of("aceimnorsuvwxz") == string::npos) {
            if (cur.size() > longest) {
                longest = cur.size();
                res = cur;
            }
        }
    }
    std:: cout << res << std::endl;
    system("pause");
    return 0;
}