/*
  author : szz
  date : 2019/07/29
*/
#include<iostream>
#include<string>
#include<sstream>

using std::string; using std::ostringstream;

template<typename T> string debug_rep(const T&);
template<typename T> string debug_rep(T*);
string debug_rep(const string&);
string debug_rep(char*);
string debug_rep(const char*);

template<typename T>
string debug_rep(const T &t) {
    ostringstream os;
    os << t;
    return os.str();
}

template<typename T>
string debug_rep(T *p) {
    ostringstream os;
    os << "pointer: " << p;
    if (p)
        os << " " << debug_rep(*p);
    else
        os << " null pointer";
    return os.str();
}

string debug_rep(const string &s) {
    return '"' + s + '"';
}

string debug_rep(char *p) {
    return debug_rep(string(p));
}

string debug_rep(const char *p) {
    return debug_rep(string(p));
}

int main() {
    std::cout << debug_rep("abc") << std::endl;    
    system("pause");
    return 0;
}