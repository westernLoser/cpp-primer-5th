/*
  author : szz
  date : 2019/07/20
*/
#include<iostream>
#include"15.5.h"

double print_total(std::ostream &os, const Quote &item, size_t n) {
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
    return ret;
}

int main() {
    Bulk_quote q("111-1", 20, 3, 0.5);
    print_total(std::cout, q, 5);
    system("pause");
    return 0;
}