/*
  author : szz
  date : 2019/09/05
*/
#include<iostream>
#include<vector>
#include<tuple>
#include<string>
#include<algorithm>
#include<numeric>
#include"..\chapter 14\14.45.h"

using std::vector; using std::string; using std::pair;


typedef vector<Sales_data>::const_iterator const_it;

bool operator<(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.isbn() < rhs.isbn();
}

vector<int>
findBook(const vector<vector<Sales_data>> &files, const string &book, vector<pair<const_it, const_it>> &its) {
    vector<int> ret;

    for (auto it = files.cbegin(); it != files.cend(); ++it) {
        auto found = std::equal_range(it->cbegin(), it->cend(), Sales_data(book));
        if (found.first != found.second)
            ret.push_back(it - files.cbegin());
            its.emplace_back(found.first, found.second);
    }

    return ret;
}

void reportResults(std::istream &in, std::ostream &os, const vector<vector<Sales_data>> &files) {
    string s;
    while (in >> s) {
        vector<pair<const_it, const_it>> its;
        auto trans = findBook(files, s, its);
        if (trans.empty()) {
            std::cout << s << " not found in any stores" << std::endl;
            continue;
        }
        for (int i = 0; i < trans.size(); ++i) {
            os << "store: " << trans[i] << " sales: "
               << std::accumulate(its[i].first, its[i].second, Sales_data(s)) << std::endl;
        }
    }
}

int main() {
    vector<vector<Sales_data>> files(1);
    files[0].emplace_back("aaa", 1, 1);
    reportResults(std::cin, std::cout, files);
    system("pause");
    return 0;
}