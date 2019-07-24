/*
  author : szz
  date : 2019/07/20
*/
#ifndef C_15_16_H
#define C_15_16_H

#include<string>
#include"15.15.h"

class Bulk_quote_II: public Disc_quote {
public:
    Bulk_quote_II() = default;
    Bulk_quote_II(const std::string &s, double p, size_t qty, double disc):
               Disc_quote(s, p, qty, disc) { }
    double net_price(std::size_t n) const override {
        double ret = 0;
        if (n > quantity) {
            ret = price * ((n - quantity) + quantity * (1 - discount)); 
        }
        else {
            ret = price * n * (1 - discount);
        }
        return ret;
    } 
};

#endif