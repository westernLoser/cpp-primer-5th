/*
  author : szz
  date : 2019/07/22
*/
#ifndef C_15_26_H
#define C_15_26_H

#include<string>
#include<iostream>

class Quote {
public:
    Quote() { std::cout << "Quote: constructor no arguments" << std::endl; }
    Quote(const std::string &s, double sales_price): bookNo(s), price(sales_price) {
        std::cout << "Quote: constructor 2arguments" << std::endl;
    }
    Quote(const Quote &q): bookNo(q.bookNo), price(q.price) { std::cout << "Quote: copy constructor" << std::endl; }
    Quote(Quote &&q) noexcept : bookNo(std::move(q.bookNo)), price(std::move(q.price)) { 
        std::cout << "Quote: move constructor" << std::endl; 
    } 
    Quote& operator=(const Quote &rhs) {
        if (&rhs != this) {
            bookNo = rhs.bookNo;
            price = rhs.price;
        }
        std::cout << "Quote: copy=()" << std::endl;
        return *this;
    }
    Quote& operator=(Quote &&rhs) noexcept {
        if (this != &rhs) {
            bookNo = std::move(rhs.bookNo);
            price = std::move(rhs.price);
        }
        std::cout << "Quote: move=()" << std::endl;
        return *this;
    }
    std::string isbn() const { return bookNo; }
    virtual double net_price(size_t n) const { return n * price; }
    virtual ~Quote() { std::cout << "destructing Quote" << std::endl; }
protected:
    double price = 0.0;
private:
    std::string bookNo;
};


class Bulk_quote: public Quote {
public:
    Bulk_quote() { std::cout << "Bulk_quote: constructor no arguments" << std::endl; }
    Bulk_quote(const std::string &s, double p, size_t qty, double disc):
               Quote(s, p), min_qty(qty), discount(disc) { std::cout << "Bulk_quote: constructor four arguments" << std::endl; }
    Bulk_quote(const Bulk_quote &bq): Quote(bq), min_qty(bq.min_qty), discount(bq.discount) {
        std::cout << "Bulk_quote: copy constructor" << std::endl;
    }
    Bulk_quote(Bulk_quote &&bq) noexcept : Quote(std::move(bq)), min_qty(std::move(bq.min_qty)), discount(std::move(bq.discount)) {
        std::cout << "Bulk_quote: move constructor" << std::endl;
    }
    Bulk_quote& operator=(const Bulk_quote &rhs) {
        if (this != &rhs) {
            Quote::operator=(rhs);
            min_qty = rhs.min_qty;
            discount = rhs.discount;
        }
        std::cout << "Bulk_quote: copy=()" << std::endl;
        return *this;
    }
    Bulk_quote& operator=(Bulk_quote &&rhs) noexcept {
        if (this != &rhs) {
            Quote::operator=(std::move(rhs));
            min_qty = std::move(rhs.min_qty);
            discount = std::move(rhs.discount);
        }
        std::cout << "Bulk_quote: move=()" << std::endl;
        return *this;
    }
    double net_price(std::size_t n) const override {
        return n >= min_qty ? n * (1 - discount) * price : n * price;
    } 
    ~Bulk_quote() {
        std::cout << "destructing Bulk_quote" << std::endl;
    }
private:
    size_t min_qty = 0;
    double discount = 0.0;
};

#endif