/*
  author : szz
  date : 2019/09/03
*/
#include<iostream>
#include<vector>
#include<string>
#include<cstring>

using std::string; using std::vector;

template<typename T>
int count(const vector<T> &v, const T &val) {
    int res = 0;
    for (const T& t : v) {
        if (t == val)
            ++res;
    }
    return res;
}

template<>
int count(const vector<const char*> &v, const char* const &val) {
    int res = 0;
    for (auto p : v) {
        if (strcmp(val, p) == 0)
            ++res;
    }
    return res;
}

int main() {
    vector<int> v1 = {1, 2, 3, 3, 4, 5};
    std::cout << count(v1, 3) << std::endl;

    vector<const char*> v2 = {"aaa", "aaa", "bbb"};
    const char *s = "aaa";
    std::cout << count(v2, s) << std::endl;
    system("pause");
    return 0;
}