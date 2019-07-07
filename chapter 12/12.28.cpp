/*
  author : szz
  date : 2019/07/06
*/
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<set>
#include<map>

using namespace std;

void print(vector<string> &file, set<int> &lines) {
    if (lines.size() == 0) {
        cout << "this word dosen't occur!" << endl;
    }
    for (auto n : lines) {
        cout << "(line " << n << ")" << file[n] << endl;
    }
}
int main() {
    ifstream ifs("C:\\Users\\admin\\Desktop\\cpp-primer\\cpp-primer-5th\\chapter 12\\12.27.txt");
    vector<string> file;
    map<string, set<int>> res;
    string line, word;
    int i = 0;
    while (getline(ifs, line)) {
        file.push_back(line);
        istringstream iss(line);
        while (iss >> word) {
            res[word].insert(i);    
        }
        ++i;
    }
    while (true) {
        string q;
        cout << "input the word you want to look for(q to quit): ";
        cin >> q;
        if (q == "q")
            break;
        print(file, res[q]);
    }
    system("pause");
    return 0;
}