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
public:
    String(): elements(nullptr), first_free(nullptr), cap(nullptr) { }
    String(const char*);
    String(const String&);
    String& operator=(const String&);
    ~String();
    void push_back(char);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    char* begin() const { return elements; }
    char* end() const { return first_free; }
    void show() const;
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

String& String::operator=(const String &s) {
    auto p = alloc_n_copy(s.begin(), s.end());
    free();
    elements = p.first;
    first_free = cap = p.second;
    std::cout << "call String& String::operator=(const String &s)" << std::endl;
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



#endif








