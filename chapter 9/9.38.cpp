/*
  author : szz
  date : 2019/06/27
*/
#include<iostream>
#include<vector>

using std::vector;

int main() {
    vector<int> v;
    int pre = -1;
    for (int i = 0; i < 10000; ++i) {
        v.push_back(0);
        if (v.capacity() != pre) {
            std::cout << v.capacity() << std::endl;
            pre = v.capacity();
        }
    }    
    system("pause");
    return 0;
}