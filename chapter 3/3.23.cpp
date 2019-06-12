/*
  author : szz
  date : 2019/06/12
*/
#include<iostream>
#include<vector>

using std::vector;

int main() {
    vector<int> v(10, 1);
    for (auto it = v.begin();
         it != v.end(); ++it) {
             *it *= 2;
         }
    
    for (auto &n : v) {
        std::cout << n << std::endl;
    }
    system("pause");
    return 0;
}