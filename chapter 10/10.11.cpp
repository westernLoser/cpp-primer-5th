/*
  author : szz
  date : 2019/06/28
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using std::string; using std::vector;

bool isShorter(const string &s1, const string &s2) { return s1.size() < s2.size(); }

int main() {
    vector<string> v{"fox", "jumps", "over", "quick", "red", "slow", "the", "turtle"};
    std::stable_sort(v.begin(), v.end(), isShorter);
    for (auto &s : v) {
        std::cout << s << " " << std::endl;
    }    
    std::cout << std::endl;
    system("pause");
    return 0;
}