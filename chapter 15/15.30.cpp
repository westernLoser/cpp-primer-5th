/*
  author : szz
  date : 2019/07/24
*/
#include<iostream>
#include"15.30.h"

int main() {
    Basket b;
    b.add_item(Quote("111", 30));
    b.add_item(Bulk_quote("222", 30, 1, 0.5));
    b.total_receipt(std::cout);
    system("pause");
    return 0;
}