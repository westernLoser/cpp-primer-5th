/*
  author : szz
  date : 2019/09/06
*/
#include<iostream>
#include<random>

unsigned gen_unsigned(int sd) {
    static std::default_random_engine e;
    e.seed(sd);
    static std::uniform_int_distribution<unsigned> u;
    return u(e);
}

int main() {
    for (int i = 0; i < 10; ++i) {
        std::cout << gen_unsigned(i) << std::endl;
    }
    system("pause");
    return 0;
}