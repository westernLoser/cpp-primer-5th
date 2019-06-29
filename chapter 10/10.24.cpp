/*
  author : szz
  date : 2019/06/29
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>

using std::vector; using std::string; using namespace std::placeholders;

bool check_size(const string &s, string::size_type sz) { return s.size() < sz; }

int main() {
    vector<int> v;
    for (int i = 1; i < 10; ++i) v.push_back(i);
    string s = "abcd";
    auto it = std::find_if(v.begin(), v.end(), std::bind(check_size, s, _1));
    if (it != v.end()) {
        std::cout << *it << std::endl;
    }    
    system("pause");
    return 0;
}