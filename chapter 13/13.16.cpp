/*
  author : szz
  date : 2019/07/09
*/
#include<iostream>

class numbered {
public:
    numbered(): mysn(unique++) { }
    numbered(const numbered&): mysn(unique++) { }
    int mysn;
    static int unique;
};

int numbered::unique = 10;

void f(const numbered &s) { std::cout << s.mysn << std::endl; }

int main() {
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);    
    system("pause");
    return 0;
}