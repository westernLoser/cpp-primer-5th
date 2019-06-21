/*
  author : szz
  date : 2019/06/19
*/
#include<iostream>
#include<string>

using std::string;

string make_plural(size_t ctr, const string &word, const string &ending = "s") {
    return (ctr > 1) ? word + ending : word;
}

int main() {
    string s1 = "success", s2 = "failure";
    std::cout << make_plural(1, s1, "es") << std::endl;
    std::cout << make_plural(2, s1, "es") << std::endl;
    std::cout << make_plural(1, s2) << std::endl;
    std::cout << make_plural(2, s2) << std::endl;
    system("pause");
    return 0;
}