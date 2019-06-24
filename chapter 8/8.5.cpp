/*
  author : szz
  date : 2019/06/24
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using std::vector;
using std::string;

int main() {
    std::ifstream is("C:\\Users\\admin\\Desktop\\cpp-primer\\cpp-primer-5th\\chapter 8\\8.1.txt");
    vector<char> content;
    string cur;
    if (is) {
        while (std::getline(is, cur)) {
            for (auto c : cur) content.push_back(c);
        }
    }
    for (auto c : content) 
        std::cout << c << std::endl;    
    system("pause");
    return 0;
}