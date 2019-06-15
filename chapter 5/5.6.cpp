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
    string letter = grade < 60 ? scores[0] : scores[(grade - 50) / 10];
    letter += (grade < 60 || grade == 100) ? "" : grade % 10 > 7 ? "+" : grade % 10 < 3 ? "-" : "";
    std::cout << letter << std::endl;
    system("pause");
    return 0;
}