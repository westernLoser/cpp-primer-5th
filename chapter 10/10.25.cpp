/*
  author : szz
  date : 2019/06/29
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
using std::string; using std::vector; using namespace std::placeholders;

void elimDups(vector<string> &v) {
    std::sort(v.begin(), v.end());
    auto end_unique = std::unique(v.begin(), v.end());
    v.erase(end_unique, v.end());
}

bool check_size(const string &s, string::size_type sz) { return s.size() < sz; }

void biggies(vector<string> &words, vector<string>::size_type sz) {
    elimDups(words);
    std::stable_sort(words.begin(), words.end(), 
                     [](const string &s1, const string &s2) 
                     { return s1.size() < s2.size(); });
    auto wc = std::partition(words.begin(), words.end(), std::bind(check_size, _1, sz));
    std::for_each(words.begin(), wc, [](const string &s) { std::cout << s << " "; });
    std::cout << std::endl;
}

int main() {
    vector<string> vs;
    for (int i = 1; i < 10; ++i) vs.emplace_back(i, 'a');
    biggies(vs, 5);
    system("pause");
    return 0;
}