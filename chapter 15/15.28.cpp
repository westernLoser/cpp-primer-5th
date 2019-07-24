/*
  author : szz
  date : 2019/07/23
*/
#include<iostream>
#include<vector>
#include<memory>
#include"15.5.h"

using std::vector;

int main() {
    vector<Quote> v;
    v.push_back(Quote("111", 10));
    v.push_back(Bulk_quote("222", 10, 10, 0.5));
    double total = 0;
    for (auto &q: v) {
        total += q.net_price(15);
    }    
    std::cout << "vector of Quote: total: " << total << std::endl;

    vector<std::shared_ptr<Quote>> v1;
    v1.push_back(std::make_shared<Quote>("111", 10));
    v1.push_back(std::make_shared<Bulk_quote>("222", 10, 10, 0.5));
    double total1 = 0;
    for (auto &q: v1) {
        total1 += q->net_price(15);
    }    
    std::cout << "vector of Quote: total: " << total1 << std::endl;
    system("pause");
    return 0;
}