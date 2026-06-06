#pragma once

// Кастомний розумний вказівник із забороною копіювання
template <typename T>
class Simple_ptr
{
private:
    T *ptr_;

public:
    explicit Simple_ptr(T *ptr = nullptr) : ptr_(ptr) {}
    ~Simple_ptr() { delete ptr_; }

    // Заборона копіювання
    Simple_ptr(const Simple_ptr &) = delete;
    Simple_ptr &operator=(const Simple_ptr &) = delete;

    T &operator*() const { return *ptr_; }
    T *operator->() const { return ptr_; }
    T *get() const { return ptr_; }
};