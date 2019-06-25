/*
  author : szz
  date : 2019/06/25
*/
#include<iostream>
#include<vector>

using std::vector;

bool equal(const vector<int> &a, const vector<int> &b) {
    auto it1 = a.begin(), it2 = b.begin();
    for (; it1 != a.end() && it2 != b.end(); ++it1, ++it2) {
            if (*it1 != *it2) 
                break; 
        }
    return it1 == a.end() && it2 == b.end();
}
int main() {
    vector<int> v1 = {1, 2, 3}, v2 = {1, 2, 3, 4}, v3 = {1, 2, 3};
    std::cout << std::boolalpha << equal(v1, v2) << " " << equal(v1, v3) << std::endl;
    system("pause");
    return 0;
}