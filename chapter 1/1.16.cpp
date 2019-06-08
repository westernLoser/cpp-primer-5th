#include<iostream>

int main() {
    int val, sum = 0;

    while (std::cin >> val) {
        sum += val;
    }

    std::cout << "The sum is " << sum << std::endl;
    system("pause");
    return 0;
}