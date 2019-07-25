/*
  author : szz
  date : 2019/07/24
*/
#ifndef C_16_12_H
#define C_16_12_H

#include<vector>
#include<memory>
#include<stdexcept>

template<typename> class BolbPtr;

template<typename T>
class Bolb {
public:
    friend class BolbPtr<T>;
    BolbPtr<T> begin();
    BolbPtr<T> end();
    typedef typename std::vector<T>::size_type size_type;
    Bolb();
    Bolb(std::initializer_list<T> il);
    size_type size() const { return data->size(); };
    bool empty() const { return data->empty(); };
    void push_back(const T &t) { data->push_back(t); };
    void pop_back();
    T& front();
    T& back();
    const T& front() const;
    const T& back() const;
private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const std::string&) const;
};

template<typename T>
class BolbPtr {
public:
    BolbPtr(): curr(0) { }
    BolbPtr(Bolb<T> &a, size_t sz = 0): wptr(a.data), curr(sz) { }
    bool operator!=(const BolbPtr& p) { return p.curr != curr; }
    T& deref() const;
    BolbPtr& incr();
private:
    std::shared_ptr<std::vector<T>>
        check(size_t, const std::string&) const;
    std::weak_ptr<std::vector<T>> wptr;
    size_t curr;
};

template<typename T>
std::shared_ptr<std::vector<T>>
    BolbPtr<T>::check(size_t sz, const std::string& msg) const
{
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound BolbPtr");
    if (sz >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

template<typename T>
T& BolbPtr<T>::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

template<typename T>
BolbPtr<T>& BolbPtr<T>::incr() {
    check(curr, "increment past end of BolbPtr");
    ++curr;
    return *this;
}

template<typename T>
BolbPtr<T> Bolb<T>::begin() {
    return BolbPtr<T>(*this);
}

template<typename T>
BolbPtr<T> Bolb<T>::end() {
    return BolbPtr<T>(*this, data->size());
}

template<typename T>
Bolb<T>::Bolb(): data(std::make_shared<std::vector<T>>()) { }

template<typename T>
Bolb<T>::Bolb(std::initializer_list<T> il):
                 data(std::make_shared<std::vector<T>>(il)) { }

template<typename T>
void Bolb<T>::check(size_type i, const std::string &msg) const {
    if (i >= data->size())
        throw std::out_of_range(msg);
}

template<typename T>
T& Bolb<T>::front() {
    check(0, "front on empty Bolb");
    return data->front();
} 

template<typename T>
T& Bolb<T>::back() {
    check(0, "back on empty Bolb");
    return data->back();
} 

template<typename T>
const T& Bolb<T>::front() const {
    check(0, "front on empty Bolb");
    return data->front();
} 

template<typename T>
const T& Bolb<T>::back() const {
    check(0, "back on empty Bolb");
    return data->back();
} 

template<typename T>
void Bolb<T>::pop_back() {
    check(0, "pop back on empty Bolb");
    data->pop_back();
}

#endif