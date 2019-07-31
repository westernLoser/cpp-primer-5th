/*
  author : szz
  date : 2019/07/26
*/
#ifndef C_16_28_SHARED_PTR_H
#define C_16_28_SHARED_PTR_H

#include<functional>

template<typename T>
class SharedPointer;

template<typename T>
void swap(SharedPointer<T> &lhs, SharedPointer<T> &rhs) {
    using std::swap;
    swap(lhs.ptr, rhs.ptr);
    swap(lhs.count, rhs.count);
    swap(lhs.deleter, rhs.deleter);
}

struct default_deleter {
public:
    template<typename T>
    void operator()(T *p) const {
        delete p;
    }
};

template<typename T>
class SharedPointer {
    friend void swap<T>(SharedPointer &lhs, SharedPointer &rhs);
public:
    //constructor
    SharedPointer(): ptr(nullptr), count(new size_t(1)), deleter(default_deleter()) { }
    explicit SharedPointer(T *raw_pointer): ptr(raw_pointer), count(new size_t(1)), deleter(default_deleter()) { }
    //copy constructor
    SharedPointer(const SharedPointer &other):
        ptr(other.ptr), count(other.count), deleter(other.deleter) {
            ++*count;
    }
    //move constructor
    SharedPointer(SharedPointer &&other) noexcept:
        ptr(other.ptr), count(other.count), deleter(other.deleter) {
            other.ptr = nullptr;
            other.count = nullptr;
    }
    //copy assignment
    SharedPointer& operator=(const SharedPointer &rhs) {
        ++*rhs.count;
        decrement_and_destory();
        ptr = rhs.ptr; count = rhs.count; deleter = rhs.deleter;
        return *this;
    }
    //move assignment
    SharedPointer& operator=(SharedPointer &&rhs) noexcept {
        swap(*this, rhs);
        rhs.decrement_and_destory();
        return *this;
    }
    //conversion operator
    operator bool() const {
        return ptr ? true : false;
    }
    //dereference
    T& operator*() const {
        return *ptr;
    }
    //arrow
    T* operator->() const {
        return ptr;
    }
    //use_count
    size_t use_count() const {
        return *count;
    }
    //get raw_pointer
    T* get() const {
        return ptr;
    }
    //check if the unique user
    bool unique() const {
        return *count == 1;
    }
    //swap
    void swap(SharedPointer &rhs) {
        swap(*this, rhs);
    }
    //reset
    void reset() {
        decrement_and_destory();
    }
    void reset(T *pointer) {
        if (ptr != pointer) {
            decrement_and_destory();
            ptr = pointer;
            count = new size_t(1);
        }
    }
    void reset(T *pointer, const std::function<void(T*)> &del) {
        reset(pointer);
        deleter = del;
    }
    //destructor
    ~SharedPointer() {
        decrement_and_destory();
    }
private:
    T *ptr;
    size_t *count;
    std::function<void(T*)> deleter;
    void decrement_and_destory() {
        if (ptr && (--*count == 0)) {
            delete count;
            deleter(ptr);
        }
        else if (!ptr) {
            delete count;
        }
        count = nullptr;
        ptr = nullptr;
    }
};

template<typename T, typename... Args>
SharedPointer<T> makeShared(Args&& ... args) {
    T* raw = new T(std::forward<Args>(args)...);
    return SharedPointer<T>(raw);
}

#endif