/*
  author : szz
  date : 2019/07/05
*/
#ifndef C_12_19_H
#define C_12_19_H

#include<string>
#include<vector>
#include<memory>
#include<stdexcept>
#include<algorithm>

class StrBolbPtr;
class StrBolb {
    friend bool operator==(const StrBolb&, const StrBolb&);
    friend bool operator!=(const StrBolb&, const StrBolb&);
    friend bool operator<(const StrBolb&, const StrBolb&);
    friend bool operator>(const StrBolb&, const StrBolb&);
    friend bool operator<=(const StrBolb&, const StrBolb&);
    friend bool operator>=(const StrBolb&, const StrBolb&);
public:
    friend class StrBolbPtr;
    StrBolbPtr begin();
    StrBolbPtr end();
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
    std::string& operator[](size_t);
    const std::string& operator[](size_t) const;
private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};


class StrBolbPtr {
    friend bool operator==(const StrBolbPtr&, const StrBolbPtr&);
    friend bool operator!=(const StrBolbPtr&, const StrBolbPtr&);
    friend bool operator<(const StrBolbPtr&, const StrBolbPtr&);
    friend bool operator>(const StrBolbPtr&, const StrBolbPtr&);
    friend bool operator<=(const StrBolbPtr&, const StrBolbPtr&);
    friend bool operator>=(const StrBolbPtr&, const StrBolbPtr&);
public:
    StrBolbPtr(): curr(0) { }
    StrBolbPtr(StrBolb& a, size_t sz = 0): wptr(a.data), curr(sz) { }
    bool operator!=(const StrBolbPtr& p) { return p.curr != curr; }
    std::string& operator[](size_t);
    const std::string& operator[](size_t) const;
    StrBolbPtr& operator++();
    StrBolbPtr& operator--();
    StrBolbPtr operator++(int);
    StrBolbPtr operator--(int);
    StrBolbPtr& operator+=(size_t);
    StrBolbPtr& operator-=(size_t);
    StrBolbPtr operator+(size_t);
    StrBolbPtr operator-(size_t);
    std::string& operator*() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    std::string* operator->() const { return &this->operator*(); }
    std::string& deref() const;
    StrBolbPtr& incr();
private:
    std::shared_ptr<std::vector<std::string>>
        check(size_t, const std::string&) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    size_t curr;
};

std::shared_ptr<std::vector<std::string>>
    StrBolbPtr::check(size_t sz, const std::string& msg) const
{
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound StrBolbPtr");
    if (sz >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

std::string& StrBolbPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

StrBolbPtr& StrBolbPtr::incr() {
    check(curr, "increment past end of StrBolbPtr");
    ++curr;
    return *this;
}

StrBolbPtr StrBolb::begin() {
    return StrBolbPtr(*this);
}

StrBolbPtr StrBolb::end() {
    return StrBolbPtr(*this, data->size());
}

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

bool operator==(const StrBolb &lhs, const StrBolb &rhs) {
    return *lhs.data == *rhs.data;
}

bool operator!=(const StrBolb &lhs, const StrBolb &rhs) {
    return !(lhs == rhs);
}

bool operator<(const StrBolb &lhs, const StrBolb &rhs) {
    return std::lexicographical_compare(lhs.data->begin(), lhs.data->end(),
                                        rhs.data->begin(), rhs.data->end());
}

bool operator>(const StrBolb &lhs, const StrBolb &rhs) {
    return rhs < lhs;
}

bool operator<=(const StrBolb &lhs, const StrBolb &rhs) {
    return !(lhs > rhs);
}

bool operator>=(const StrBolb &lhs, const StrBolb &rhs) {
    return !(lhs < rhs);
}

bool operator==(const StrBolbPtr &lhs, const StrBolbPtr &rhs) {
    return lhs.curr == rhs.curr;
}

bool operator!=(const StrBolbPtr &lhs, const StrBolbPtr &rhs) {
    return !(lhs == rhs);
}

bool operator<(const StrBolbPtr &lhs, const StrBolbPtr &rhs) {
    return lhs.curr < rhs.curr;
}

bool operator>(const StrBolbPtr &lhs, const StrBolbPtr &rhs) {
    return lhs.curr > rhs.curr;
}

bool operator<=(const StrBolbPtr &lhs, const StrBolbPtr &rhs) {
    return lhs.curr <= rhs.curr;
}

bool operator>=(const StrBolbPtr &lhs, const StrBolbPtr &rhs) {
    return lhs.curr >= rhs.curr;
}

std::string& StrBolb::operator[](size_t n) {
    check(n, "out of range");
    return data->at(n);
}

const std::string& StrBolb::operator[](size_t n) const {
    check(n, "out of range");
    return data->at(n);
}

std::string& StrBolbPtr::operator[](size_t n) {
    auto p = check(n, "dereference out of range.");
    return (*p)[n];
}

const std::string& StrBolbPtr::operator[](size_t n) const {
    auto p = check(n, "dereference out of range.");
    return (*p)[n];
}

StrBolbPtr& StrBolbPtr::operator++() {
    check(curr, "increment past end of StrBolbPtr");
    ++curr;
    return *this;
}

StrBolbPtr& StrBolbPtr::operator--() {
    --curr;
    check(curr, "decrement past begin of StrBolbPtr");
    return *this;
}

StrBolbPtr StrBolbPtr::operator++(int) {
    StrBolbPtr ret = *this;
    ++*this;
    return ret;
}

StrBolbPtr StrBolbPtr::operator--(int) {
    StrBolbPtr ret = *this;
    --*this;
    return ret;
}

StrBolbPtr& StrBolbPtr::operator+=(size_t n) {
    curr += n;
    check(curr, "increment past end of StrBolbPtr");
    return *this;
}

StrBolbPtr& StrBolbPtr::operator-=(size_t n) {
    curr -= n;
    check(curr, "decrement past begin of StrBolbPtr");
    return *this;
}
StrBolbPtr StrBolbPtr::operator+(size_t n) {
    StrBolbPtr ret = *this;
    ret += n;
    return ret;
}
StrBolbPtr StrBolbPtr::operator-(size_t n) {
    StrBolbPtr ret = *this;
    ret -= n;
    return ret;
}
#endif