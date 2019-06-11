/*
  author : szz
  date : 2019/06/11
*/
#include<iostream>
#include<string>

//直接连接
void func1() {
    std::string s, cur;

    while (std::cin >> cur) {
        if (cur == "#") {
            break;
        }
        s += cur;
    }

    std::cout << s << std::endl;
}

//用空格分隔
void func2() {
    std::string s, cur;

    while (std::cin >> cur) {
        if (cur == "#") {
            break;
        }
        s += cur + ' ';
    }
    s.pop_back();
    std::cout << s << std::endl;
}

int main() {
    func1();
    func2();
    system("pause");
    return 0;
}