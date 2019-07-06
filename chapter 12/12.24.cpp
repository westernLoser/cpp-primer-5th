/*
  author : szz
  date : 2019/07/06
*/
#include<iostream>
#include<string>

int main() {
    std::cout<< "input size:";
    int size = 0;
    std::cin >> size;
    char *p = new char[size + 1]();
    std::cin.ignore();
    std::cout << "input string: ";
    std::cin.get(p, size + 1);
    std::cout << p << std::endl;    
    system("pause");
    return 0;
}