/*
  author : szz
  date : 2019/06/15
*/
#include<iostream>
#include<vector>
#include<string>

using std::vector;
using std::string;

int main() {
    const vector<string> scores{"F", "D", "C", "B", "A", "A++"};
    int grade;
    std::cin >> grade;
    if (grade < 60) {
        std::cout << scores[0] << std::endl;
    }
    else {
        std::cout << scores[(grade - 50) / 10];
        if (grade != 100) {
            if (grade % 10 > 7) {
                std::cout << "+";
            }
            else if (grade % 10 < 3) {
                std::cout << "-";
            }
        }
        std::cout << std::endl;
    }
    system("pause");
    return 0;
}