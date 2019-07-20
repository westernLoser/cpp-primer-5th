/*
  author : szz
  date : 2019/07/18
*/
#include<iostream>
#include<vector>
#include<algorithm>

using std::vector;

class IsEqual {
public:
    bool operator()(int a, int b) { return a == b; }
};

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6};
    IsEqual ie;
    std::replace_if(v.begin(), v.end(), [&ie](int a) { return ie(3, a); }, 5);
    for (auto i : v) 
        std::cout << i << std::endl;
    system("pause");
    return 0;
}