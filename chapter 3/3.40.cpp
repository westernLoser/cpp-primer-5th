/*
  author : szz
  date : 2019/06/12
*/
#include<iostream>
#include<cstring>

int main() {
    char s1[20] = "hello,";
    char s2[20] = "world";
    char s3[20];
    strcpy(s3, strcat(s1, s2));
    std::cout << s3 << std::endl;
    system("pause");
    return 0;
}