/*
  author : szz
  date : 2019/07/03
*/
#ifndef C_12_2_H
#define C_12_2_H

#include<string>
#include<vector>
#include<memory>
#include<stdexcept>

class StrBolb {
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBolb();
    StrBolb(std::initializer_list<std::string> il);
    size_type size() const { return data->size(); };
    bool empty() const { return data->empty(); };
    void push_back(const std::string &t) { data->push_back(t); };
    void pop_back();
    std::string& front();
    std::string& back();
    const std::string& front() const;
    const std::string& back() const;
private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};

StrBolb::StrBolb(): data(std::make_shared<std::vector<std::string>>()) { }

StrBolb::StrBolb(std::initializer_list<std::string> il):
                 data(std::make_shared<std::vector<std::string>>(il)) { }

void StrBolb::check(size_type i, const std::string &msg) const {
    if (i >= data->size())
        throw std::out_of_range(msg);
}

std::string& StrBolb::front() {
    check(0, "front on empty strBolb");
    return data->front();
} 

std::string& StrBolb::back() {
    check(0, "back on empty strBolb");
    return data->back();
} 

const std::string& StrBolb::front() const {
    check(0, "front on empty strBolb");
    return data->front();
} 

const std::string& StrBolb::back() const {
    check(0, "back on empty strBolb");
    return data->back();
} 

void StrBolb::pop_back() {
    check(0, "pop back on empty strBolb");
    data->pop_back();
}

#endif