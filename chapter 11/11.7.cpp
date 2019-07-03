/*
  author : szz
  date : 2019/07/01
*/
#include<iostream>
#include<map>
#include<vector>
#include<string>

using std::map; using std::vector; using std::string;
using family = map<string, vector<string>>;

void addFamily(family &f, const string &s) {
    f.insert({s, {}});
}

void addChild(family &f, const string &last, const string &child) {
    f[last].push_back(child);
}

int main() {
    family familys;   
    addFamily(familys, "Joyce");
    addChild(familys, "Joyce", "Ketty");
    addChild(familys, "Joyce", "Berry");

    for (auto &it : familys) {
        auto last = it.first;
        auto children = it.second;
        std::cout << last << "'s family has:" << std::endl;
        for (auto &child : children) std::cout << child << std::endl;
    }
    system("pause");
    return 0;
}