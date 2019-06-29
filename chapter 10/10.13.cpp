/*
  author : szz
  date : 2019/06/28
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using std::string; using std::vector;

bool longer_than_four(const string &s) { return s.size() >= 5; }

int main() {
    vector<string> v;
    for (int i = 1; i < 10; ++i) v.emplace_back(i, 'a');
    auto end = std::partition(v.begin(), v.end(), longer_than_four);
    for (auto it = v.begin(); it != end; ++it) {
        std::cout << *it << std::endl;
    }    
    system("pause");
    return 0;
}