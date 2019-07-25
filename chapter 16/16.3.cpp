/*
  author : szz
  date : 2019/07/24
*/
#include<iostream>
#include<string>
#include<functional>

class Sales_data {
public:
    Sales_data(const std::string &s = "", unsigned n = 0, double p = 0.0):
        bookNo(s), units_sold(n), revenue(n * p) { }
    std::string isbn() const { return bookNo; }
private:
    std::string bookNo;
    unsigned units_sold;
    double revenue;    
};

template<typename T>
int compare(const T &lhs, const T &rhs) {
    if (std::less<T>()(lhs, rhs)) {
        return -1;
    }
    else if (std::less<T>()(rhs, lhs)) {
        return 1;
    }
    return 0;
}

int main() {
    Sales_data s1, s2;
    std::cout << compare(s1, s2) << std::endl;
    system("pause");
    return 0;
}