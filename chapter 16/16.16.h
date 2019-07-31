/*
  author : szz
  date : 2019/07/25
*/
#ifndef C_16_16_H
#define C_16_16_H

#include<utility>
#include<memory>
#include<algorithm>

template<typename T> class Vec;
template<typename T>
bool operator==(const Vec<T>&, const Vec<T>&);
template<typename T>
bool operator!=(const Vec<T>&, const Vec<T>&);
template<typename T>
bool operator<(const Vec<T>&, const Vec<T>&);
template<typename T>
bool operator>(const Vec<T>&, const Vec<T>&);
template<typename T>
bool operator<=(const Vec<T>&, const Vec<T>&);
template<typename T>
bool operator>=(const Vec<T>&, const Vec<T>&);

template<typename T>
class Vec {
    friend bool operator==(const Vec<T>&, const Vec<T>&);
    friend bool operator!=(const Vec<T>&, const Vec<T>&);
    friend bool operator<(const Vec<T>&, const Vec<T>&);
    friend bool operator>(const Vec<T>&, const Vec<T>&);
    friend bool operator<=(const Vec<T>&, const Vec<T>&);
    friend bool operator>=(const Vec<T>&, const Vec<T>&);
public:
    Vec(): elements(nullptr), first_free(nullptr), cap(nullptr) { }
    Vec(std::initializer_list<T>);
    Vec(const Vec&);
    Vec(Vec &&) noexcept;
    Vec& operator=(const Vec&);
    Vec& operator=(std::initializer_list<T>);
    Vec& operator=(Vec&&) noexcept;
    ~Vec();
    void push_back(const T&);
    template<typename... Args>
    void emplace_back(Args&& ... args) {
        check_n_alloc();
        alloc.construct(first_free++, std::forward<Args>(args)...);
    }
    void reserve(size_t);
    void resize(size_t n, const T &s = T());
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    T* begin() const { return elements; }
    T* end() const { return first_free;}
    T& operator[](size_t n) { return elements[n]; }
    const T& operator[](size_t n) const { return elements[n]; }
private:
    static std::allocator<T> alloc;
    void check_n_alloc() { if (size() == capacity()) reallocate(); }
    std::pair<T*, T*> alloc_n_copy
        (const T*, const T*);
    void free();
    void do_reallocate(size_t);
    void reallocate();
    T *elements;
    T *first_free;
    T *cap;
};

template<typename T>
std::allocator<T> Vec<T>::alloc;

template<typename T>
Vec<T>::Vec(std::initializer_list<T> il) {
    auto p = alloc_n_copy(il.begin(), il.end());
    elements = p.first;
    first_free = cap = p.second;
}

template<typename T>
Vec<T>::Vec(const Vec &v) {
    auto p = alloc_n_copy(v.begin(), v.end());
    elements = p.first;
    first_free = cap = p.second;
}

template<typename T>
Vec<T>::Vec(Vec &&v) noexcept : elements(v.elements), first_free(v.first_free), cap(v.cap) {
    v.elements = v.first_free = v.cap = nullptr;
}

template<typename T>
Vec<T>& Vec<T>::operator=(const Vec &rhs) {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

template<typename T>
Vec<T>& Vec<T>::operator=(std::initializer_list<T> il) {
    auto data = alloc_n_copy(il.begin(), il.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

template<typename T>
Vec<T>& Vec<T>::operator=(Vec &&rhs) noexcept {
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

template<typename T>
Vec<T>::~Vec() {
    free();
}

template<typename T>
void Vec<T>::push_back(const T &s) {
    check_n_alloc();
    alloc.construct(first_free++, s);
}

template<typename T>
void Vec<T>::reserve(size_t n) {
    if (n > capacity()) {
        do_reallocate(n);
    }
}

template<typename T>
void Vec<T>::resize(size_t n, const T &s) {
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

template<typename T>
std::pair<T*, T*> Vec<T>::alloc_n_copy
    (const T *begin, const T *end) {
    auto data = alloc.allocate(end - begin);
    return {data, std::uninitialized_copy(begin, end, data)};
}

template<typename T>
void Vec<T>::free() {
    for (auto p = first_free; p != elements; /* 空 */) {
        alloc.destroy(--p);
    }
    alloc.deallocate(elements, cap - elements);
}

template<typename T>
void Vec<T>::reallocate() {
    auto newcapacity = size() ? 2 * size() : 1;
    do_reallocate(newcapacity);
}

template<typename T>
void Vec<T>::do_reallocate(size_t newcapacity) {
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

template<typename T>
bool operator==(const Vec<T> &lhs, const Vec<T> &rhs) {
    auto p = lhs.begin(), q = rhs.begin();
    for (; p != lhs.end() && q != rhs.end(); ++p, ++q) {
        if (*p != *q)
            break;
    }
    return p == lhs.end() && q == rhs.end();
}

template<typename T>
bool operator!=(const Vec<T> &lhs, const Vec<T> &rhs) {
    return !(lhs == rhs);
}

template<typename T>
bool operator<(const Vec<T> &lhs, const Vec<T> &rhs) {
    return std::lexicographical_compare(lhs.begin(), lhs.end(),
                                        rhs.begin(), rhs.end());
}

template<typename T>
bool operator>(const Vec<T> &lhs, const Vec<T> &rhs) {
    return rhs < lhs;
}

template<typename T>
bool operator<=(const Vec<T> &lhs, const Vec<T> &rhs) {
    return !(lhs > rhs);
}

template<typename T>
bool operator>=(const Vec<T> &lhs, const Vec<T> &rhs) {
    return !(lhs < rhs);
}

#endif