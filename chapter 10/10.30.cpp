/*
  author : szz
  date : 2019/07/01
*/
#include<iostream>
#include<iterator>
#include<algorithm>
#include<vector>

using std::vector;

int main() {
    std::istream_iterator<int> in(std::cin), end;
    vector<int> v(in, end);
    std::sort(v.begin(), v.end());
    std::ostream_iterator<int> out(std::cout, " ");
    std::copy(v.begin(), v.end(), out);    
    system("pause");
    return 0;
}