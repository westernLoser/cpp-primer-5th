/*
  author : szz
  date : 2019/06/29
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using std::vector; using std::string;

bool isLonger(const string &s) { return s.size() <= 6; }

int main() {
    vector<string> vs;
    for (int i = 1; i < 10; ++i) vs.emplace_back(i, 'a');
    std::cout << std::count_if(vs.begin(), vs.end(), isLonger) << std::endl;;    
    system("pause");
    return 0;
}