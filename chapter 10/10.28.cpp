/*
  author : szz
  date : 2019/06/29
*/
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<iterator>

using std::vector; using std::list;

template<typename Sequence>
void print(Sequence const& seq)
{
    for (const auto& i : seq)
        std::cout << i << " ";
    std::cout << std::endl;
}

int main() {
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> l1, l2, l3;
    std::copy(v.begin(), v.end(), std::back_inserter(l1));
    std::copy(v.begin(), v.end(), std::front_inserter(l2));
    std::copy(v.begin(), v.end(), std::inserter(l3, l3.begin()));
    print(l1);
    print(l2);
    print(l3);
    system("pause");
    return 0;
}