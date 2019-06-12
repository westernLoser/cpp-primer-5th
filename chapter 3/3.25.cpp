/*
  author : szz
  date : 2019/06/12
*/
#include<iostream>
#include<vector>

using std::vector;

int main() {
    vector<unsigned> scores(11, 0);
    unsigned grade;
    auto it = scores.begin();
    while (std::cin >> grade) {
        if (grade <= 100) {
            *(it + grade / 10) += 1;
        }
    }    
    for (auto &n : scores) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    system("pause");
    return 0;
}