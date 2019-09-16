/*
  author : szz
  date : 2019/09/06
*/
#include<iostream>
#include<random>

unsigned gen_unsigned(int sd, int min, int max) {
    static std::default_random_engine e(sd);
    static std::uniform_int_distribution<unsigned> u(min, max);
    return u(e);
}

int main() {
    for (int i = 0; i < 10; ++i) {
        std::cout << gen_unsigned(i, 0, 9) << std::endl;
    }
    system("pause");
    return 0;
}