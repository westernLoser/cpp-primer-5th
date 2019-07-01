/*
  author : szz
  date : 2019/07/01
*/
#include<iostream>
#include<iterator>
#include<fstream>
#include<string>

int main() {
    std::string path = "C:\\Users\\admin\\Desktop\\cpp-primer\\cpp-primer-5th\\chapter 10\\";
    std::ifstream ifs(path + "in.txt");
    std::ofstream out1(path + "out1.txt");
    std::ofstream out2(path + "out2.txt");
    std::istream_iterator<int> in(ifs), end;
    std::ostream_iterator<int> o1(out1, " "), o2(out2, "\n");
    while (in != end) {
        if (*in % 2) {
            *o1++ = *in;
        }
        else {
            *o2++ = *in;
        }
        in++;
    }
    out1.flush();    
    system("pause");
    return 0;
}