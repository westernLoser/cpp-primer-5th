/*
  author : szz
  date : 2019/07/23
*/
#ifndef C_15_30_H
#define C_15_30_H

#include<iostream>
#include<set>
#include<memory>

class Quote {
public:
    Quote() = default;
    Quote(const std::string &s, double sales_price): bookNo(s), price(sales_price) { }
    std::string isbn() const { return bookNo; }
    virtual Quote* clone() const & { return new Quote(*this); }
    virtual Quote* clone() && { return new Quote(std::move(*this)); }
    virtual double net_price(size_t n) const { return n * price; }
    virtual ~Quote() = default;
protected:
    double price = 0.0;
private:
    std::string bookNo;
};


class Bulk_quote: public Quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &s, double p, size_t qty, double disc):
               Quote(s, p), min_qty(qty), discount(disc) { }
    double net_price(std::size_t n) const override {
        return n >= min_qty ? n * (1 - discount) * price : n * price;
    } 
    Bulk_quote* clone() const & { return new Bulk_quote(*this); }
    Bulk_quote* clone() && { return new Bulk_quote(std::move(*this)); }
private:
    size_t min_qty = 0;
    double discount = 0.0;
};


class Basket {
public:
    void add_item(const Quote &q) {
        items.insert(std::shared_ptr<Quote>(q.clone()));
    }
    void add_item(Quote &&q) {
        items.insert(std::shared_ptr<Quote>(std::move(q).clone()));
    }
    double total_receipt(std::ostream&) const;
private:
    static bool compare(const std::shared_ptr<Quote> &lhs,
                        const std::shared_ptr<Quote> &rhs) {
        return lhs->isbn() < rhs->isbn();
    }
    std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{compare};
};

double print_total(std::ostream &os, const Quote &item, size_t n) {
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
    return ret;
}

double Basket::total_receipt(std::ostream &os) const {
    double sum = 0.0;
    for (auto it = items.cbegin();
              it != items.cend();
              it = items.upper_bound(*it)) {
        sum += print_total(os, **it, items.count(*it));
    }
    os << "Total Sale: " << sum << std::endl;
    return sum;
}

#endif