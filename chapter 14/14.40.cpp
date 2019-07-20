/*
  author : szz
  date : 2019/07/19
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using std::string; using std::vector;

class CompareSize {
public:
    bool operator()(const string &a, const string &b) {
        return a.size() < b.size();
    }
};

class CompareWith {
    int sz;
public:
    CompareWith(int n): sz(n) { }
    bool operator()(const string& s) {
        return s.size() >= sz;
    }
};

class Print {
public:
    void operator()(const string &s) {
        std::cout << s << " ";
    }
};

void elimDups(vector<string> &v) {
    std::sort(v.begin(), v.end());
    auto end_unique = std::unique(v.begin(), v.end());
    v.erase(end_unique, v.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz) {
    elimDups(words);
    std::stable_sort(words.begin(), words.end(), CompareSize());
    auto wc = std::find_if(words.begin(), words.end(),CompareWith(sz));
    std::for_each(wc, words.end(), Print());
    std::cout << std::endl;
}

int main() {
    vector<string> vs;
    for (int i = 1; i < 10; ++i) vs.emplace_back(i, 'a');
    biggies(vs, 5);
    system("pause");
    return 0;
}