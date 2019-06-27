/*
  author : szz
  date : 2019/06/27
*/
#include<iostream>
#include<string>

using std::string;

void replace_with(string &s, const string &oldVal, const string &newVal) {
    for (auto cur = s.begin(); cur <= s.end() - oldVal.size(); ) {
        if (oldVal == string(cur, cur + oldVal.size())) {
            cur = s.erase(cur, cur + oldVal.size());
            cur = s.insert(cur, newVal.begin(), newVal.end());
            cur += newVal.size();
        }
        else {
            ++cur;
        }
    }
}
int main() {
    string s = "tho tho tho";
    replace_with(s, "tho", "though");
    std::cout << s << std::endl;    
    system("pause");
    return 0;
}