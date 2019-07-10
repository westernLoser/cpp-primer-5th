/*
  author : szz
  date : 2019/07/09
*/
#ifndef C_13_26_H
#define C_13_26_H

#include<string>
#include<vector>
#include<memory>
#include<stdexcept>

class StrBolbPtr;
class ConstStrBolbPtr;
class StrBolb {
public:
    friend class StrBolbPtr;
    friend class ConstStrBolbPtr;
    StrBolbPtr begin();
    StrBolbPtr end();
    ConstStrBolbPtr begin() const;
    ConstStrBolbPtr end() const;
    typedef std::vector<std::string>::size_type size_type;
    StrBolb();
    StrBolb(std::initializer_list<std::string> il);
    StrBolb(const StrBolb &orig):
            data(std::make_shared<std::vector<std::string>>(*orig.data)) { };
    StrBolb& operator=(const StrBolb &rhs);
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


class StrBolbPtr {
public:
    StrBolbPtr(): curr(0) { }
    StrBolbPtr(StrBolb& a, size_t sz = 0): wptr(a.data), curr(sz) { }
    bool operator!=(const StrBolbPtr& p) { return p.curr != curr; }
    std::string& deref() const;
    StrBolbPtr& incr();
private:
    std::shared_ptr<std::vector<std::string>>
        check(size_t, const std::string&) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    size_t curr;
};


class ConstStrBolbPtr {
public:
    ConstStrBolbPtr(): curr(0) { }
    ConstStrBolbPtr(const StrBolb& a, size_t sz = 0): wptr(a.data), curr(sz) { }
    bool operator!=(const ConstStrBolbPtr& p) { return p.curr != curr; }
    const std::string& deref() const;
    ConstStrBolbPtr& incr();
private:
    std::shared_ptr<std::vector<std::string>>
        check(size_t, const std::string&) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    size_t curr;
};

std::shared_ptr<std::vector<std::string>>
    ConstStrBolbPtr::check(size_t sz, const std::string& msg) const
{
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound ConstStrBolbPtr");
    if (sz >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

const std::string& ConstStrBolbPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

ConstStrBolbPtr& ConstStrBolbPtr::incr() {
    check(curr, "increment past end of ConstStrBolbPtr");
    ++curr;
    return *this;
}

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

ConstStrBolbPtr StrBolb::begin() const {
    return ConstStrBolbPtr(*this);
}

ConstStrBolbPtr StrBolb::end() const {
    return ConstStrBolbPtr(*this, data->size());
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

StrBolb& StrBolb::operator=(const StrBolb &rhs) {
    auto temp = std::make_shared<std::vector<std::string>>(*rhs.data);
    data = temp;
    return *this;
}

#endif