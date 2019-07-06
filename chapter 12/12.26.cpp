/*
  author : szz
  date : 2019/07/06
*/
#include<iostream>
#include<memory>
#include<string>

using std::string;

int main() {
    std::allocator<string> a;
    int n = 10;
    auto p = a.allocate(n);
    string s;
    auto q = p;
    while (q != p + n && std::cin >> s) {
        a.construct(q++, s);
    }
    while (q != p) {
        std::cout << *--q << std::endl;
        a.destroy(q);
    }
    a.deallocate(p, n);
    system("pause");
    return 0;
}