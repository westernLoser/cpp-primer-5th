/*
  author : szz
  date : 2019/06/27
*/
#include<iostream>
#include<string>
#include<vector>

using std::vector; using std::string;

int main() {
    vector<string> vs = {"0", "1", "2"};
    int sum = 0;
    for (auto &s : vs) {
        sum += stoi(s);
    }    
    std::cout << sum << std::endl;
    system("pause");
    return 0;
}