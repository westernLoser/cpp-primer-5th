/*
  author : szz
  date : 2019/07/20
*/
#include<iostream>
#include"15.3.h"

double print_total(std::ostream &os, const Quote &item, size_t n) {
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
    return ret;
}

int main() {
    Quote q("111-1", 20);
    print_total(std::cout, q, 3);
    system("pause");
    return 0;
}