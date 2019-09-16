/*
  author : szz
  date : 2019/09/03
*/
#ifndef C_16_62_H
#define C_16_62_H

#include<string>

//template<typename T> class std::hash;

class Sales_data {
    friend class std::hash<Sales_data>;
    friend bool operator==(const Sales_data &lhs, const Sales_data &rhs);
public:
    Sales_data(const std::string &s = "", unsigned n = 0, double p = 0.0):
        bookNo(s), units_sold(n), revenue(n * p) { }
    std::string isbn() const { return bookNo; }
private:
    std::string bookNo;
    unsigned units_sold;
    double revenue;    
};

bool operator==(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.bookNo == rhs.bookNo &&
           lhs.revenue == rhs.revenue &&
           lhs.units_sold == rhs.units_sold;
}

namespace std {
    template<>
    struct hash<Sales_data> {
        typedef size_t result_type;
        typedef Sales_data argument_type;
        size_t operator() (const Sales_data& s) const;
    };
    size_t hash<Sales_data>::operator() (const Sales_data& s) const {
        return hash<string>()(s.bookNo) ^
               hash<unsigned>()(s.units_sold) ^
               hash<double>()(s.revenue);
    }
}

#endif