/*
  author : szz
  date : 2019/09/05
*/
#include<tuple>
#include<iostream>

using std::tuple;
int main() {
    tuple<int, int, int> t(10, 20, 30);
    std::cout << std::get<0>(t) << std::endl;
    system("pause");
    return 0;
}