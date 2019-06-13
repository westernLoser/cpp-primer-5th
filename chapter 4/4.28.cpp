/*
  author : szz
  date : 2019/06/13
*/
#include<iostream>

using std::cout;
using std::endl;

int main() {
    cout <<"short: "<< sizeof(short) << endl;
		cout << "pointer: " << sizeof(void*) << endl;
		cout << "long double: " << sizeof(long double) << endl;
		cout << "bool: " << sizeof(bool) << endl;
		cout << "double: " << sizeof(double) << endl;
		cout << "float: " << sizeof(float) << endl;
		cout << "long long: " << sizeof(long long) << endl;
		cout << "long: " << sizeof(long) << endl;
		cout << "int: " << sizeof(int) << endl;
		cout << "char: " << sizeof(char) << endl;
    system("pause");
    return 0;
}