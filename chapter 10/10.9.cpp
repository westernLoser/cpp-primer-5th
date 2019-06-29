/*
  author : szz
  date : 2019/06/28
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using std::vector; using std::string;

void input(vector<string> &v) {
    string cur;
    while (std::cin >> cur) {
        v.push_back(cur);
    }
}

void print(const vector<string> &v) {
    int i = 0;
    for (auto &s : v) {
        std::cout << i++ << " " << s << " ";
    }
    std::cout << std::endl;
}

void elimDups(vector<string> &v) {
    std::sort(v.begin(), v.end());
    auto end_unique = std::unique(v.begin(), v.end());
    print(v);
    v.erase(end_unique, v.end());
    print(v);
}

int main() {
    vector<string> v;
    input(v);
    print(v);
    elimDups(v);    
    system("pause");
    return 0;
}