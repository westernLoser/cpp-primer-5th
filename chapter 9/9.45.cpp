/*
  author : szz
  date : 2019/06/27
*/
#include<iostream>
#include<string>

using std::string;

string complete(string s, const string &prefix, const string &suffix) {
    s.insert(s.begin(), prefix.begin(), prefix.end());
    s.append(suffix);
    return s;
}
int main() {
    string s = "Jack";
    std::cout << complete(s, "Mr.", "Jr.");
    system("pause");
    return 0;
}