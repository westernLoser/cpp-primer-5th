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

using std::vector; using std::string; using std::tuple;

typedef tuple<vector<Sales_data>::size_type,
              vector<Sales_data>::const_iterator,
              vector<Sales_data>::const_iterator> matches;

bool operator<(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.isbn() < rhs.isbn();
}

vector<matches>
findBook(const vector<vector<Sales_data>> &files, const string &book) {
    vector<matches> ret;

    for (auto it = files.cbegin(); it != files.cend(); ++it) {
        auto found = std::equal_range(it->cbegin(), it->cend(), Sales_data(book));
        if (found.first != found.second)
            ret.push_back(std::make_tuple(it - files.cbegin(), found.first, found.second));
    }

    return ret;
}

void reportResults(std::istream &in, std::ostream &os, const vector<vector<Sales_data>> &files) {

    string s;
    while (in >> s) {
        auto trans = findBook(files, s);
        if (trans.empty()) {
            std::cout << s << " not found in any stores" << std::endl;
            continue;
        }
        for (const auto &store : trans) {
            os << "store " << std::get<0>(store) << " sales: "
               << std::accumulate(std::get<1>(store), std::get<2>(store), Sales_data(s)) << std::endl;
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