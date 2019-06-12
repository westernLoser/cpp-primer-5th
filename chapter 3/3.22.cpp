/*
  author : szz
  date : 2019/06/12
*/
#include<iostream>
#include<vector>
#include<string>

using std::string;
using std::vector;

int main() {
    vector<string> vs;
    string tmp;
    while (std::cin >> tmp) {
      vs.push_back(tmp);
      vs.push_back("");
    }

    for (auto it = vs.begin();
         it != vs.end() && !it -> empty(); ++it) {
             for (auto &c : *it) {
               c = toupper(c);
             }
             std::cout << *it << std::endl;

         }
    system("pause");
    return 0;
}