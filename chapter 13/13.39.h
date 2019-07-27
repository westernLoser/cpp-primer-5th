/*
  author : szz
  date : 2019/07/11
*/
#ifndef C_13_39_H
#define C_13_39_H

#include<string>
#include<utility>
#include<memory>
#include<algorithm>

class StrVec {
    friend bool operator==(const StrVec&, const StrVec&);
    friend bool operator!=(const StrVec&, const StrVec&);
    friend bool operator<(const StrVec&, const StrVec&);
    friend bool operator>(const StrVec&, const StrVec&);
    friend bool operator<=(const StrVec&, const StrVec&);
    friend bool operator>=(const StrVec&, const StrVec&);
public:
    StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr) { }
    StrVec(std::initializer_list<std::string>);
    StrVec(const StrVec&);
    StrVec(StrVec &&) noexcept;
    StrVec& operator=(const StrVec&);
    StrVec& operator=(std::initializer_list<std::string>);
    StrVec& operator=(StrVec&&) noexcept;
    ~StrVec();
    void push_back(const std::string&);
    void reserve(size_t);
    void resize(size_t n, const std::string &s = std::string());
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    std::string* begin() const { return elements; }
    std::string* end() const { return first_free;}
    std::string& operator[](size_t n) { return elements[n]; }
    const std::string& operator[](size_t n) const { return elements[n]; }
private:
    static std::allocator<std::string> alloc;
    void check_n_alloc() { if (size() == capacity()) reallocate(); }
    std::pair<std::string*, std::string*> alloc_n_copy
        (const std::string*, const std::string*);
    void free();
    void do_reallocate(size_t);
    void reallocate();
    std::string *elements;
    std::string *first_free;
    std::string *cap;
};

std::allocator<std::string> StrVec::alloc;

StrVec::StrVec(std::initializer_list<std::string> il) {
    auto p = alloc_n_copy(il.begin(), il.end());
    elements = p.first;
    first_free = cap = p.second;
}

StrVec::StrVec(const StrVec &v) {
    auto p = alloc_n_copy(v.begin(), v.end());
    elements = p.first;
    first_free = cap = p.second;
}

StrVec::StrVec(StrVec &&v) noexcept : elements(v.elements), first_free(v.first_free), cap(v.cap) {
    v.elements = v.first_free = v.cap = nullptr;
}

StrVec& StrVec::operator=(const StrVec &rhs) {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

StrVec& StrVec::operator=(std::initializer_list<std::string> il) {
    auto data = alloc_n_copy(il.begin(), il.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

StrVec& StrVec::operator=(StrVec &&rhs) noexcept {
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

StrVec::~StrVec() {
    free();
}

void StrVec::push_back(const std::string &s) {
    check_n_alloc();
    alloc.construct(first_free++, s);
}

void StrVec::reserve(size_t n) {
    if (n > capacity()) {
        do_reallocate(n);
    }
}

void StrVec::resize(size_t n, const std::string &s) {
    if (n > size()) {
        if (n > capacity()) reserve(n * 2);
        for (size_t i = size(); i != n; ++i) {
            alloc.construct(first_free++, s);
        }
    }
    else {
        for (size_t i = size(); i != n; --i) {
            alloc.destroy(--first_free);
        }
    }
}

std::pair<std::string*, std::string*> StrVec::alloc_n_copy
    (const std::string *begin, const std::string *end) {
    auto data = alloc.allocate(end - begin);
    return {data, std::uninitialized_copy(begin, end, data)};
}

void StrVec::free() {
    for (auto p = first_free; p != elements; /* 空 */) {
        alloc.destroy(--p);
    }
    alloc.deallocate(elements, cap - elements);
}

void StrVec::reallocate() {
    auto newcapacity = size() ? 2 * size() : 1;
    do_reallocate(newcapacity);
}

void StrVec::do_reallocate(size_t newcapacity) {
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i) {
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

bool operator==(const StrVec &lhs, const StrVec &rhs) {
    auto p = lhs.begin(), q = rhs.begin();
    for (; p != lhs.end() && q != rhs.end(); ++p, ++q) {
        if (*p != *q)
            break;
    }
    return p == lhs.end() && q == rhs.end();
}

bool operator!=(const StrVec &lhs, const StrVec &rhs) {
    return !(lhs == rhs);
}

bool operator<(const StrVec &lhs, const StrVec &rhs) {
    return std::lexicographical_compare(lhs.begin(), lhs.end(),
                                        rhs.begin(), rhs.end());
}

bool operator>(const StrVec &lhs, const StrVec &rhs) {
    return rhs < lhs;
}

bool operator<=(const StrVec &lhs, const StrVec &rhs) {
    return !(lhs > rhs);
}

bool operator>=(const StrVec &lhs, const StrVec &rhs) {
    return !(lhs < rhs);
}

#endif