/*
  author : szz
  date : 2019/07/29
*/
#include<iostream>

using std::ostream;

template<typename T>
ostream& print(ostream &os, const T &t) {
    return os << t << std::endl;;
} 

template<typename T, typename... Args>
ostream& print(ostream &os, const T &t, const Args& ... rest) {
    os << t << ", ";
    return print(os, rest...);
}

int main() {
    int i = 0;
    double d = 3.14;
    long long ll = 0;
    char c = 'a';
    print(std::cout, i);
    print(std::cout, i, d);
    print(std::cout, i, d, ll, c);
    system("pause");
    return 0;
}