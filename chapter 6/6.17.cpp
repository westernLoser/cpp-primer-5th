/*
  author : szz
  date : 2019/06/18
*/
#include<iostream>
#include<string>

using std::string;

bool hasUpper(const string &s) {
    for (auto &c : s) {
        if (isupper(c)) {
            return true;
        }
    }
    return false;
}

void convert(string &s) {
    for (auto &c : s) {
        c = tolower(c);
    }
}

int main() {
    string s = "Abc";
    std::cout << s << " " << std::boolalpha << hasUpper(s) << std::endl;
    convert(s);
    std::cout << s << " " << std::boolalpha << hasUpper(s) << std::endl;
    system("pause");
    return 0;
}