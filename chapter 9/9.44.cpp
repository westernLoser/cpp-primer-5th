/*
  author : szz
  date : 2019/06/27
*/
#include<iostream>
#include<string>

using std::string;

void replace_with(string &s, const string &oldVal, const string &newVal) {
    for (auto i = 0; i <= s.size() - oldVal.size(); ) {
        if (s.substr(i, oldVal.size()) == oldVal) {
            s.replace(i, oldVal.size(), newVal);
            i += newVal.size();
        }
        else {
            ++i;
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