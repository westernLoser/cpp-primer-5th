/*
  author : szz
  date : 2019/06/12
*/
#include<iostream>
#include<vector>

using std::vector;

int main() {
    vector<int> v{1, 2, 3, 4, 5};
    int *res = (int *)malloc(sizeof(int) * v.size());
    decltype(v.size()) x = 0;
    for (auto &n : v) {
        res[x++] = n;
    }    
    for (int i = 0; i < x; ++i) {
        std::cout << res[i] << std::endl;
    }
    system("pause");
    return 0;
}