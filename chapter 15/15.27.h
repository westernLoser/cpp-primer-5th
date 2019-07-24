/*
  author : szz
  date : 2019/07/23
*/
#ifndef C_15_27_H
#define C_15_27_H

#include"15.3.h"
#include<string>
class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const std::string &s, double price, size_t qty, double disc):
               Quote(s, price), quantity(qty), discount(disc) { }
    double net_price(size_t) const override = 0;
protected:
    size_t quantity = 0;
    double discount = 0.0;
};


class Bulk_quote : public Disc_quote {
public:
    using Disc_quote::Disc_quote;
    double net_price(size_t) const override;
};

double Bulk_quote::net_price(size_t n) const {
    return n >= quantity ? n * (1 - discount) * price : n * price;
}

#endif