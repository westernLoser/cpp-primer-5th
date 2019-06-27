/*
  author : szz
  date : 2019/06/27
*/
#include<iostream>
#include<string>

using std::string;

void func1(const string &s) {
    string numbers = "0123456789";
    string alphas = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string::size_type pos = 0;
    while (pos < s.size()) {
        pos = s.find_first_of(numbers, pos);
        if (pos != string::npos) {
            std::cout << s[pos] << " ";
            ++pos;
        }
        else {
            break;
        }
    }
    std::cout << std::endl;
    pos = 0;
    while (pos < s.size()) {
        pos = s.find_first_of(alphas, pos);
        if (pos != string::npos) {
            std::cout << s[pos] << " ";
            ++pos;
        }
        else {
            break;
        }
    }
    std::cout << std::endl;
}

void func2(const string &s) {
    string numbers = "0123456789";
    string alphas = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string::size_type pos = 0;
    while (pos < s.size()) {
        pos = s.find_first_not_of(alphas, pos);
        if (pos != string::npos) {
            std::cout << s[pos] << " ";
            ++pos;
        }
        else {
            break;
        }
    }
    std::cout << std::endl;
    pos = 0;
    while (pos < s.size()) {
        pos = s.find_first_not_of(numbers, pos);
        if (pos != string::npos) {
            std::cout << s[pos] << " ";
            ++pos;
        }
        else {
            break;
        }
    }
    std::cout << std::endl;
}

int main() {
    string s = "ab2c3d7R4E6";
    func1(s);
    func2(s);    
    system("pause");
    return 0;
}