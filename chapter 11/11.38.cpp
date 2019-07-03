/*
  author : szz
  date : 2019/07/03
*/
#include<iostream>
#include<fstream>
#include<sstream>
#include<unordered_map>
#include<string>
#include<stdexcept>

using std::ifstream; using std::istringstream; using std::string; using std::unordered_map;

unordered_map<string, string> build_map(ifstream &trans) {
    unordered_map<string, string> rule_map;
    string key, value;
    while (trans >> key && std::getline(trans, value)) {
        if (value.size() > 1) {
            rule_map[key] = value.substr(1);
        }
        else {
            throw std::runtime_error("no rule for: " + key);
        }
    }
    return rule_map;
}

string transform(const unordered_map<string, string> &rule_map, const string &word) {
    auto it = rule_map.find(word);
    if (it != rule_map.end())
        return it -> second;
    return word;
}

void word_transform(ifstream &transformer, ifstream &input) {
    auto rule_map = build_map(transformer);
    string text;
    while (std::getline(input, text)) {
        istringstream stream(text);
        string word;
        auto isFirst = true;
        while (stream >> word) {
            if (isFirst)
                isFirst = false;
            else
                std::cout << " ";
            std::cout << transform(rule_map, word);
        }
        std::cout << std::endl;
    }
}

int main() {
    string dir = "C:\\Users\\admin\\Desktop\\cpp-primer\\cpp-primer-5th\\chapter 11";
    ifstream transformer(dir + "\\transformer.txt"), input(dir + "\\input.txt");
    word_transform(transformer, input);
    system("pause");
    return 0;
}