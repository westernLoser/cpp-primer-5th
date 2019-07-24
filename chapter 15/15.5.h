/*
  author : szz
  date : 2019/07/20
*/
#ifndef C_15_5_H
#define C_15_5_H

#include<string>
#include"15.3.h"

class Bulk_quote: public Quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &s, double p, size_t qty, double disc):
               Quote(s, p), min_qty(qty), discount(disc) { }
    double net_price(std::size_t n) const override {
        return n >= min_qty ? n * (1 - discount) * price : n * price;
    } 
private:
    size_t min_qty = 0;
    double discount = 0.0;
};

#endif