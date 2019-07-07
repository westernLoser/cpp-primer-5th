/*
  author : szz
  date : 2019/07/07
*/
#ifndef C_12_32_H
#define C_12_32_H

#include<fstream>
#include<map>
#include<vector>
#include<string>
#include<set>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<memory>
#include"12.22.h"

class QueryResult;
class TextQuery {
public:
    TextQuery(std::ifstream &ifs);
    QueryResult query(std::string);
private:
    std::map<std::string, std::shared_ptr<std::set<int>>> s2r;
    std::shared_ptr<StrBolb> file;
};


class QueryResult {
public:
    friend std::ostream& print(std::ostream &os, const QueryResult &qr);
    QueryResult(std::shared_ptr<StrBolb> f,
                std::shared_ptr<std::set<int>> r):
                file(f), res(r) { }
private:
    std::shared_ptr<StrBolb> file;
    std::shared_ptr<std::set<int>> res;
};

TextQuery::TextQuery(std::ifstream &ifs) {
    file = std::make_shared<StrBolb>();
    std::string cur;
    while (getline(ifs, cur)) {
        file->push_back(cur);
    }
}

QueryResult TextQuery::query(const std::string s) {
    auto p = s2r.find(s);
    if (p == s2r.end()) {
        s2r[s] = std::make_shared<std::set<int>>();
        int i = 0;
        for (auto p = (*file).begin(); p != (*file).end(); p.incr(), ++i) {
            std::string cur = p.deref();
            std::istringstream iss(cur);
            std::string word;
            while (iss >> word) {
                if (word == s) {
                    s2r[s]->insert(i);
                    break;
                }
            } 

        }
    }
    return QueryResult(file, s2r[s]);
}

std::ostream& print(std::ostream &os, const QueryResult &qr) {
    for (auto n : *qr.res) {
        StrBolbPtr p(*qr.file, n);
        os << "(line " << n + 1 << ")" << p.deref() << std::endl;
    }
    return os;
}

#endif