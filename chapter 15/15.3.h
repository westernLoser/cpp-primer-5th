/*
  author : szz
  date : 2019/07/20
*/
#ifndef C_15_3_H
#define C_15_3_H

#include<string>
#include<iostream>

class Quote {
public:
    Quote() = default;
    Quote(const std::string &s, double sales_price): bookNo(s), price(sales_price) { }
    std::string isbn() const { return bookNo; }
    virtual double net_price(size_t n) const { return n * price; }
    virtual void debug() const;
    virtual ~Quote() = default;
protected:
    double price = 0.0;
private:
    std::string bookNo;
};

void Quote::debug() const {
    std::cout << "data members of this class:\n"
              << "bookNo= " <<this->bookNo << " "
              << "price= " <<this->price<< " ";
}
#endif