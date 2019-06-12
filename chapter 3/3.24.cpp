/*
  author : szz
  date : 2019/06/12
*/
#include<iostream>
#include<vector>

using std::vector;

int main() {
    vector<int> v{1, 2, 3, 4, 5};

    for (auto it = v.begin();
         it != v.end() - 1; ++it) {
             std::cout << *it + *(it + 1) << std::endl;
         }    
    
    for (auto it = v.begin(), it1 = v.end() - 1;
         it != v.end(); ++it, --it1) {
             std::cout << *it + *it1 << std::endl;
         }
    system("pause");
    return 0;
}