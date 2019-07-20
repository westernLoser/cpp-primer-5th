/*
  author : szz
  date : 2019/07/19
*/
#include<iostream>
#include<functional>
#include<algorithm>
#include<vector>

using std::vector;

int main() {
    vector<int> v{1, 2, 3, 4};
    std::modulus<int> mod;
    int num = 24;
    bool is_divisible = std::any_of(v.begin(), v.end(), [&](int i) {
        return mod(num, i) == 0;
    });
    std::cout << std::boolalpha << is_divisible << std::endl;    
    system("pause");
    return 0;
}