/*
  author : szz
  date : 2019/06/12
*/
#include<iostream>
#include<vector>

using std::vector;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    vector<int> v(std::begin(arr), std::end(arr));
    for (auto &n :v) {
        std::cout << n << std::endl;
    }    
    system("pause");
    return 0;
}