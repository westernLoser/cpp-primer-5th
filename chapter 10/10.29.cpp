/*
  author : szz
  date : 2019/07/01
*/
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iterator>

using std::string; using std::vector; using std::ifstream; using std::istream_iterator;

int main() {
    ifstream ifs("C:\\Users\\admin\\Desktop\\cpp-primer\\cpp-primer-5th\\chapter 10\\10.29.txt");
    istream_iterator<string> it(ifs), end;
    vector<string> vs(it, end);
    for (auto &s : vs) std::cout << s << std::endl;
    system("pause");
    return 0;
}