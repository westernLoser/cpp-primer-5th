/*
  author : szz
  date : 2019/06/24
*/

#ifndef C_7_57_H
#define C_7_57_H

#include<iostream>

class Account {
public:
    void calculate() { amount += amount * interestRate; }
    static double rate() { return interestRate; }
    static void rate(double newRate) { interestRate = newRate; }
private:
    std::string owner;
    double amount;
    static double interestRate = 0;
    static double initRate() { return todayRate; }; 
    static constexpr double todayRate = 42.42;
};

double Account::interestRate = initRate();

#endif