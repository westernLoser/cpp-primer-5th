/*
  author : szz
  date : 2019/07/06
*/
#ifndef C_12_27_H
#define C_12_27_H

#include<fstream>
#include<map>
#include<vector>
#include<string>
#include<set>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<memory>

class QueryResult;
class TextQuery {
public:
    TextQuery(std::ifstream &ifs);
    QueryResult query(std::string);
private:
    std::map<std::string, std::shared_ptr<std::set<int>>> s2r;
    std::shared_ptr<std::vector<std::string>> file;
};


class QueryResult {
public:
    QueryResult(std::shared_ptr<std::vector<std::string>> f,
                std::shared_ptr<std::set<int>> r):
                file(f), res(r) { }
    void print();
private:
    std::shared_ptr<std::vector<std::string>> file;
    std::shared_ptr<std::set<int>> res;
};

TextQuery::TextQuery(std::ifstream &ifs) {
    file = std::make_shared<std::vector<std::string>>();
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

void QueryResult::print() {
    for (auto n : *res) {
        std::cout << "(line " << n << " ) " << (*file)[n] << std::endl;
    }
}

#endif