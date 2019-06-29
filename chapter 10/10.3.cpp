/*
  author : szz
  date : 2019/06/28
*/
#include<iostream>
#include<vector>
#include<numeric>

using std::vector;

int main() {
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "the sum of vector is " << std::accumulate(v.begin(), v.end(), 0) << std::endl;    
    system("pause");
    return 0;
}