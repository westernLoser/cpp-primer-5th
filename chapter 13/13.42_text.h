/*
  author : szz
  date : 2019/07/12
*/
#ifndef C_13_42_text_H
#define C_13_42_text_H

#include<fstream>
#include<map>
#include<vector>
#include<string>
#include<set>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<memory>
#include"13.42_StrVec.h"

class QueryResult;
class TextQuery {
public:
    TextQuery(std::ifstream &ifs);
    QueryResult query(std::string);
private:
    std::map<std::string, std::shared_ptr<std::set<int>>> s2r;
    std::shared_ptr<StrVec> file;
};


class QueryResult {
public:
    friend std::ostream& print(std::ostream &os, const QueryResult &qr);
    QueryResult(std::shared_ptr<StrVec> f,
                std::shared_ptr<std::set<int>> r):
                file(f), res(r) { }
    std::set<int>::iterator begin();
    std::set<int>::iterator end();
    std::shared_ptr<StrVec> get_file();
private:
    std::shared_ptr<StrVec> file;
    std::shared_ptr<std::set<int>> res;
};

TextQuery::TextQuery(std::ifstream &ifs) {
    file = std::make_shared<StrVec>();
    std::string cur;
    while (getline(ifs, cur)) {
        file->push_back(cur);
    }
}

QueryResult TextQuery::query(const std::string s) {
    auto p = s2r.find(s);
    if (p == s2r.end()) {
        s2r[s] = std::make_shared<std::set<int>>();
        for (int i = 0; i < file->size(); ++i) {
            std::string cur = (*file)[i];
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

std::set<int>::iterator QueryResult::begin() {
    return res->begin();
}

std::set<int>::iterator QueryResult::end() {
    return res->end();
}

std::shared_ptr<StrVec> QueryResult::get_file() {
    return file;
}

std::ostream& print(std::ostream &os, const QueryResult &qr) {
    for (auto n : *qr.res) {
        os << "(line " << n + 1 << ")" << (*qr.file)[n] << std::endl;
    }
    return os;
}

#endif