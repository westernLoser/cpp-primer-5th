/*
  author : szz
  date : 2019/06/10
*/
#include<iostream>
#include<string>

struct Sales_data {
    std::string bookNo;
    unsigned int sold = 0; //已售数量
    double total = 0.0; //总价
};

int main() {
    Sales_data data1, data2;
    double price = 0.0;
    std::cin >> data1.bookNo >> data1.sold >> price;
    data1.total = price * data1.sold;
    std::cin >> data2.bookNo >> data2.sold >> price;
    data2.total = price * data1.sold;
    if (data1.bookNo == data2.bookNo) {
        unsigned int total_sold = data1.sold + data2.sold;
        double total_money = data1.total + data2.total;
        std::cout << data1.bookNo << " " << total_sold
                  << " " << total_money << std::endl;
        if (total_sold > 0) {
            std::cout << total_money / total_sold << std::endl;
        }
        else {
            std:: cout << "No Sale!" << std::endl;
        }
    }
    else {
        std::cerr << "Data must refer to the same ISBN" << std::endl;
        return -1;
    }
    system("pause");
    return 0;
}