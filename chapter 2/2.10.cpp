/*
  author : szz
  date : 2019/06/08
*/
#include<iostream>
#include<string>

std::string global_str;
int global_int;

int main() {
    int local_int;
    std::string local_str;
    
    std::cout<< global_str << std::endl;
    std::cout<< global_int << std::endl;
    std::cout<< local_str << std::endl;
    std::cout<< local_int << std::endl;

    system("pause");
    return 0;
}