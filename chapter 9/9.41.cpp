/*
  author : szz
  date : 2019/06/27
*/
#include<iostream>
#include<vector>
#include<string>

using std::string; using std::vector;

int main() {
    vector<char> v = {'a', 'b', 'c'};
    string s(v.begin(), v.end());
    std::cout << s << std::endl;    
    system("pause");
    return 0;
}