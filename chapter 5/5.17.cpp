/*
  author : szz
  date : 2019/06/17
*/
#include<iostream>
#include<vector>

using std::vector;

int main() {
    vector<int> v1{0, 1, 1, 2}, v2{0, 1, 1, 2, 3, 5, 8};
    int i;
    bool flag = true;
    for (auto it1 = v1.begin(), it2 = v2.begin();
         it1 != v1.end() && it2 != v2.end(); ++it1, ++it2) {
             if (*it1 != *it2) {
                 flag = false;
             }
         } 
    std::cout << "The answer is " << (flag ? "true" : "false") << std::endl;
    system("pause");
    return 0;
}