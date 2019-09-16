/*
  author : szz
  date : 2019/09/05
*/
#include<iostream>
#include<tuple>
#include<string>
#include<vector>

using std::tuple; using std::vector; using std::pair; using std::string;

int main() {
    tuple<string, vector<string>, pair<string, int>> t("aaa", {"aaa", "bbb", "ccc"}, {"aaa", 1});    
    system("pause");
    return 0;
}