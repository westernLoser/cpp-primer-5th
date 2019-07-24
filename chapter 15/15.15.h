/*
  author : szz
  date : 2019/07/20
*/
#ifndef C_15_15_H
#define C_15_15_H

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
    Bulk_quote() = default;
    Bulk_quote(const std::string &s, double price, size_t qty, double disc):
               Disc_quote(s, price, qty, disc) { };
    double net_price(size_t) const override;
};

double Bulk_quote::net_price(size_t n) const {
    return n >= quantity ? n * (1 - discount) * price : n * price;
}

#endif