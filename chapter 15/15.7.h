/*
  author : szz
  date : 2019/07/20
*/
#ifndef C_15_7_H
#define C_15_7_H

#include<string>
#include"15.3.h"

class Bulk_quote_II: public Quote {
public:
    Bulk_quote_II() = default;
    Bulk_quote_II(const std::string &s, double p, size_t qty, double disc):
               Quote(s, p), max_qty(qty), discount(disc) { }
    double net_price(std::size_t n) const override {
        double ret = 0;
        if (n > max_qty) {
            ret = price * ((n - max_qty) + max_qty * (1 - discount)); 
        }
        else {
            ret = price * n * (1 - discount);
        }
        return ret;
    } 
private:
    size_t max_qty = 0;
    double discount = 0.0;
};

#endif