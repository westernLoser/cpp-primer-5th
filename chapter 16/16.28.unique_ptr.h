/*
  author : szz
  date : 2019/07/26
*/
#ifndef C_16_28_UNIQUE_PTR_H
#define C_16_28_UNIQUE_PTR_H

#include<utility>

template<typename T, typename D>
class UniquePointer;

template<typename T, typename D>
void swap(UniquePointer<T, D> &lhs, UniquePointer<T, D> &rhs) {
    using std::swap;
    swap(lhs.ptr, rhs.ptr);
    swap(lhs.deleter, rhs.deleter);
}

template<typename T, typename D>
class UniquePointer {
    friend void swap<T, D>(UniquePointer &lhs, UniquePointer &rhs);
public:
    UniquePointer() = default;
    explicit UniquePointer(T *raw_pointer): ptr(raw_pointer) { }
    UniquePointer(const UniquePointer&) = delete;
    UniquePointer& operator=(const UniquePointer&) = delete;
    UniquePointer(UniquePointer &&up) noexcept : ptr(up.ptr) { up.ptr = nullptr; }
    UniquePointer& operator=(UniquePointer &&rhs) noexcept { 
        if (this->ptr != rhs.ptr) {
            deleter(ptr);
            ptr = nullptr;
            swap(*this, rhs);
        }
        return *this;
    }
    ~UniquePointer() { deleter(ptr); }
    void swap(UniquePointer &rhs) { swap(*this, rhs); }
    T& operator*() const { return *ptr; }
    T* operator->() const { return & this-> operator *(); }
    operator bool() const { return ptr ? true : false; }
    T* get() const { return ptr; }
    void reset() noexcept { deleter(ptr); ptr = nullptr; }
    void reset(T *p) noexcept { deleter(ptr); ptr = p; }
    T* release() {
        T *ret = ptr;
        ptr = nullptr;
        return ret;
    }
private:
    T *ptr = nullptr;
    D deleter = D();
};

#endif