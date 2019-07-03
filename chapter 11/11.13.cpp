/*
  author : szz
  date : 2019/07/01
*/
#include<iostream>
#include<vector>
#include<utility>
#include<string>

using std::vector; using std::pair; using std::string;

int main() {
    vector<pair<string, int>> vp;
    string s;
    int i;
    while (std::cin >> s >> i) {
        vp.emplace_back(s, i);
        vp.push_back({s, i});
        vp.push_back(std::make_pair(s, i));
        vp.push_back(pair<string, int>(s, i));
    }

    for (auto &p : vp) {
        std::cout << p.first << " " << p.second << std::endl; 
    }

    system("pause");
    return 0;
}