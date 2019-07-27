/*
  author : szz
  date : 2019/07/25
*/
#include<iostream>
#include<vector>

using std::vector;

template<typename Sequence>
void print(const Sequence &seq) {
    typename Sequence::size_type i = 0;
    for (; i != seq.size(); ++i) {
        std::cout << seq[i] << std::endl;
    }
}

int main() {
    vector<int> v = {1, 2, 3};
    print(v);
    system("pause");
    return 0;
}