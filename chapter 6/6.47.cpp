/*
  author : szz
  date : 2019/06/19
*/
#include<iostream>
#include<vector>
#define NDEBUG
using std::vector;

void recur_print(vector<int> v) {
    #ifndef NDEBUG
        std::cout << "current size: " << v.size() << std::endl;
    #endif
    if (!v.empty()) {
        auto last = v.back();
        v.pop_back();
        recur_print(v);
        std::cout << last << std::endl;
    }
    
}
int main() {
    vector<int> v{1, 2, 3, 4, 5};
    recur_print(v);
    system("pause");
    return 0;
}