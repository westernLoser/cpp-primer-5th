/*
  author : szz
  date : 2019/06/22
*/
#include<iostream>
#include"7.27.h"

int main() {
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(std::cout);
    std::cout << std::endl;
    myScreen.display(std::cout);
    std::cout << std::endl;
    system("pause");
    return 0;
}