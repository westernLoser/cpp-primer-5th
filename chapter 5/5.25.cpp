/*
  author : szz
  date : 2019/06/17
*/
#include<iostream>
#include<stdexcept>
#include<string>

using std::string;

int main() {
    int a, b;
    while (true) {
        try {
            std::cin >> a >> b;
            if (b == 0) {
                throw std::runtime_error("divisor can not be zero!");
            }
            std::cout << a / b << std::endl;
            break;
        } catch (std::runtime_error e) {
            std::cout << e.what() << std::endl;
            std::cout << "input new numbers? y/n ";
            string yn;
            std::cin >> yn;
            if (yn.empty() || tolower(yn[0]) != 'y') {
                break;
            }
        }
    }
    system("pause");
    return 0;
}