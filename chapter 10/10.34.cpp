/*
  author : szz
  date : 2019/07/01
*/
#include<iostream>
#include<vector>

using std::vector;

int main() {
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto it = v.rbegin(); it != v.rend(); ++it) {
        std::cout << *it << std::endl;
    }    
    system("pause");
    return 0;
}