/*
  author : szz
  date : 2019/07/19
*/
#ifndef C_14_45_H
#define C_14_45_H

#include<string>
#include<iostream>

class Sales_data {
    friend std::istream& operator>>(std::istream&, Sales_data&);
    friend std::ostream& operator<<(std::ostream&, Sales_data&);
    friend Sales_data operator+(const Sales_data&, const Sales_data&);
public:
    Sales_data(const std::string &s = "", unsigned n = 0, double p = 0.0):
        bookNo(s), units_sold(n), revenue(n * p) { }
    Sales_data& operator+=(const Sales_data&);
    Sales_data& operator=(const std::string&);
    std::string isbn() const { return bookNo; }
    operator std::string() const { return bookNo; }
    operator double() const { return revenue; }
private:
    std::string bookNo;
    unsigned units_sold;
    double revenue;    
};

Sales_data& Sales_data::operator=(const std::string &s) {
    bookNo = s;
    units_sold = revenue = 0;
    return *this;
}

Sales_data& Sales_data::operator+=(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

std::istream& operator>>(std::istream &is, Sales_data &item) {
    double price = 0.0;
    is >> item.bookNo >> item.units_sold >> price;
    if (is)
        item.revenue = item.units_sold * price;
    else
        item = Sales_data();
    return is;
}

std::ostream& operator<<(std::ostream &os, Sales_data &item) {
    os << item.bookNo << item.units_sold << item.revenue;
    return os;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data temp = lhs;
    temp += lhs;
    return temp;
}

#endif