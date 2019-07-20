/*
  author : szz
  date : 2019/07/12
*/
#ifndef C_13_44_H
#define C_13_44_H

#include<memory>
#include<algorithm>
#include<iostream>

class String {
    friend std::ostream& operator<<(std::ostream&, const String&);
    friend bool operator==(const String&, const String&);
    friend bool operator!=(const String&, const String&);
    friend bool operator<(const String&, const String&);
    friend bool operator>(const String&, const String&);
    friend bool operator<=(const String&, const String&);
    friend bool operator>=(const String&, const String&);
public:
    String(): elements(nullptr), first_free(nullptr), cap(nullptr) { }
    String(const char*);
    String(const String&);
    String(String&&) noexcept;
    String& operator=(const String&);
    String& operator=(String &&) noexcept;
    ~String();
    void push_back(char);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    char* begin() const { return elements; }
    char* end() const { return first_free; }
    void show() const;
    char& operator[](size_t n) { return elements[n]; }
    const char& operator[](size_t n) const { return elements[n]; }
private:
    static std::allocator<char> alloc;
    char *elements;
    char *first_free;
    char *cap;
    void check_n_alloc() { if (size() == capacity()) reallocate(); }
    std::pair<char*, char*> alloc_n_copy(const char*, const char*);
    void range_initializer(const char*, const char*);
    void free();
    void reallocate();
};

std::allocator<char> String::alloc;

String::String(const char *s): elements(nullptr), first_free(nullptr), cap(nullptr) {
    char *s1 = const_cast<char*>(s);
    while (*s1) ++s1;
    range_initializer(s, s1); 
}

String::String(const String &s) {
    range_initializer(s.begin(), s.end());
    std::cout << "call String::String(const String &s)" << std::endl;
}

String::String(String &&s) noexcept : elements(s.elements), first_free(s.first_free), cap(s.cap) {
    s.elements = s.first_free = s.cap = nullptr;
    std::cout << "call String::String(String &&s) noexcept" << std::endl;
}

String& String::operator=(const String &s) {
    auto p = alloc_n_copy(s.begin(), s.end());
    free();
    elements = p.first;
    first_free = cap = p.second;
    std::cout << "call String& String::operator=(const String &s)" << std::endl;
    return *this;
}

String& String::operator=(String &&rhs) noexcept {
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    std::cout << "call String& String::operator=(String &&rhs) noexcept" << std::endl;
    return *this;
}

String::~String() {
    free();
}

void String::push_back(char c) {
    check_n_alloc();
    *first_free++ = c;
}

void String::show() const {
    for (auto p = elements; p != first_free; ++p) {
        std::cout << *p;
    }
    std::cout << std::endl;
}
std::pair<char*, char*> String::alloc_n_copy(const char *begin, const char *end) {
    auto data = alloc.allocate(end - begin);
    return {data, std::uninitialized_copy(begin, end, data)};
}

void String::range_initializer(const char *begin, const char *end) {
    auto p = alloc_n_copy(begin, end);
    elements = p.first;
    first_free = cap = p.second;
}

void String::free() {
    std::for_each(elements, first_free, [this](char &c) {
        alloc.destroy(&c);
    });
    alloc.deallocate(elements, cap - elements);
}

void String::reallocate() {
    auto newcapacity = size() ? 2 * size() : 1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i) {
        alloc.construct(dest++, *elem++);
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

std::ostream& operator<<(std::ostream& os, const String &s) {
    for (auto p = s.elements; p != s.first_free; ++p) {
        os << *p;
    }
    return os;
}

bool operator==(const String &lhs, const String &rhs) {
    auto p = lhs.begin(), q = rhs.begin();
    for (; p != lhs.end() && q != rhs.end(); ++p, ++q) {
        if (*p != *q)
            break;
    }
    return p == lhs.end() && q == rhs.end();
}

bool operator!=(const String &lhs, const String &rhs) {
    return !(lhs == rhs);
}

bool operator<(const String &lhs, const String &rhs) {
    return std::lexicographical_compare(lhs.begin(), lhs.end(),
                                        rhs.begin(), rhs.end());
}

bool operator>(const String &lhs, const String &rhs) {
    return rhs < lhs;
}

bool operator<=(const String &lhs, const String &rhs) {
    return !(lhs > rhs);
}

bool operator>=(const String &lhs, const String &rhs) {
    return !(lhs < rhs);
}

#endif








