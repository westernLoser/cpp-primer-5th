/*
  author : szz
  date : 2019/06/17
*/
#include<iostream>
#include<string>

using std::string;

int main() {
    string s;
    std::cin >> s;
    int cnt = 0;
    for (auto &c : s) {
        auto c1 = tolower(c);
        if (c1 == 'a' || c1 == 'e' || c1 == 'i' || c1 == 'o' || c1 == 'u') {
            ++cnt;
        }
    }
    std::cout << cnt << std::endl;
    system("pause");
    return 0;
}