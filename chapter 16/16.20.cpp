/*
  author : szz
  date : 2019/07/25
*/
#include<iostream>
#include<list>

using std::list;

template<typename Sequence>
void print(const Sequence &seq) {
    for (auto p = seq.begin(); p != seq.end(); ++p) {
        std::cout<< *p << std::endl;
    }
}

int main() {
    list<int> li = {1, 2, 3};
    print(li);    
    system("pause");
    return 0;
}