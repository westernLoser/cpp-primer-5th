/*
  author : szz
  date : 2019/09/03
*/
#include<iostream>
#include<string>
#include<sstream>

using std::ostream; using std::string; using std::ostringstream;

template<typename T> string debug_rep(const T&);
template<typename T> string debug_rep(T*);
string debug_rep(const string&);

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

template<>
string debug_rep(char *p) {
    return debug_rep(string(p));
}

template<>
string debug_rep(const char* p) {
    return debug_rep(string(p));
}

template<typename T>
ostream& print(ostream &os, const T &t) {
    return os << t << std::endl;;
} 

template<typename T, typename... Args>
ostream& print(ostream &os, const T &t, const Args& ... rest) {
    os << t << ", ";
    return print(os, rest...);
}

template<typename... Args>
ostream& errorMsg(ostream &os, const Args& ... rest) {
    return print(os, debug_rep(rest)...);
}

int main() {
    errorMsg(std::cout, 1, 2, 1.2, "abc");    
    system("pause");
    return 0;
}