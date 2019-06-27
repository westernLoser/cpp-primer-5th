/*
  author : szz
  date : 2019/06/27
*/
#include<iostream>
#include<string>

using std::string;

string complete(string s, const string &prefix, const string &suffix) {
    s.insert(0, prefix);
    s.insert(s.size(), suffix);
    return s;
}
int main() {
    string s = "Jack";
    std::cout << complete(s, "Mr.", "Jr.");
    system("pause");
    return 0;
}