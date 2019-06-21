/*
  author : szz
  date : 2019/06/19
*/
#include<iostream>
#include<vector>

using std::vector;

void recur_print(vector<int>::iterator begin, vector<int>::iterator end) {
    if (begin != end) {
        std::cout << *begin << std::endl;
        recur_print(begin + 1, end);
    }
}
int main() {
    vector<int> v{1, 2, 3, 4, 5};
    recur_print(v.begin(), v.end());
    system("pause");
    return 0;
}