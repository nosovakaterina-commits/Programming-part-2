#pragma once

#include <cstddef>
#include <memory>
#include <stdexcept>
#include <utility>

// Вектороподібний контейнер
template <typename T, typename Allocator = std::allocator<T>>
class SimpleVector
{
private:
    using AllocTraits = std::allocator_traits<Allocator>;

    Allocator alloc_;
    T *data_{};
    std::size_t size_{};
    std::size_t capacity_{};

public:
    using iterator = T *;
    using const_iterator = const T *;

    SimpleVector() = default;

    // Конструктор копіювання з копіюванням елементів
    SimpleVector(const SimpleVector &other)
        : alloc_(AllocTraits::select_on_container_copy_construction(other.alloc_))
    {
        reserve(other.size_);
        for (std::size_t i = 0; i < other.size_; ++i)
        {
            AllocTraits::construct(alloc_, data_ + i, other.data_[i]);
        }
        size_ = other.size_;
    }

    // Конструктор переміщення пам'яті
    SimpleVector(SimpleVector &&other) noexcept
        : alloc_(std::move(other.alloc_)), data_(other.data_), size_(other.size_), capacity_(other.capacity_)
    {
        other.data_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }

    // Оператор копіюючого присвоювання
    SimpleVector &operator=(const SimpleVector &other)
    {
        if (this != &other)
        {
            clear();
            if constexpr (AllocTraits::propagate_on_container_copy_assignment::value)
            {
                alloc_ = other.alloc_;
            }
            reserve(other.size_);
            for (std::size_t i = 0; i < other.size_; ++i)
            {
                AllocTraits::construct(alloc_, data_ + i, other.data_[i]);
            }
            size_ = other.size_;
        }
        return *this;
    }

    // Оператор переміщуючого присвоювання
    SimpleVector &operator=(SimpleVector &&other) noexcept
    {
        if (this != &other)
        {
            clear();
            if (data_)
            {
                AllocTraits::deallocate(alloc_, data_, capacity_);
            }
            if constexpr (AllocTraits::propagate_on_container_move_assignment::value)
            {
                alloc_ = std::move(other.alloc_);
            }
            data_ = other.data_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            other.data_ = nullptr;
            other.size_ = 0;
            other.capacity_ = 0;
        }
        return *this;
    }

    ~SimpleVector()
    {
        clear();
        if (data_)
        {
            AllocTraits::deallocate(alloc_, data_, capacity_);
        }
    }

    std::size_t size() const noexcept { return size_; }
    std::size_t capacity() const noexcept { return capacity_; }
    bool empty() const noexcept { return size_ == 0; }
    T *data() noexcept { return data_; }
    const T *data() const noexcept { return data_; }

    // Доступ по індексу без перевірки меж
    T &operator[](std::size_t idx) noexcept { return data_[idx]; }
    const T &operator[](std::size_t idx) const noexcept { return data_[idx]; }

    // Доступ по індексу із безпечною перевіркою меж
    T &at(std::size_t idx)
    {
        if (idx >= size_)
            throw std::out_of_range("SimpleVector::at");
        return data_[idx];
    }

    const T &at(std::size_t idx) const
    {
        if (idx >= size_)
            throw std::out_of_range("SimpleVector::at");
        return data_[idx];
    }

    T &front()
    {
        if (empty())
            throw std::out_of_range("SimpleVector::front");
        return data_[0];
    }

    const T &front() const
    {
        if (empty())
            throw std::out_of_range("SimpleVector::front");
        return data_[0];
    }

    T &back()
    {
        if (empty())
            throw std::out_of_range("SimpleVector::back");
        return data_[size_ - 1];
    }

    const T &back() const
    {
        if (empty())
            throw std::out_of_range("SimpleVector::back");
        return data_[size_ - 1];
    }

    // Перевиділення сирої пам'яті при розширенні вектора
    void reserve(std::size_t new_cap)
    {
        if (new_cap <= capacity_)
            return;
        T *new_data = AllocTraits::allocate(alloc_, new_cap);
        for (std::size_t i = 0; i < size_; ++i)
        {
            AllocTraits::construct(alloc_, new_data + i, std::move_if_noexcept(data_[i]));
        }
        for (std::size_t i = 0; i < size_; ++i)
        {
            AllocTraits::destroy(alloc_, data_ + i);
        }
        if (data_)
        {
            AllocTraits::deallocate(alloc_, data_, capacity_);
        }
        data_ = new_data;
        capacity_ = new_cap;
    }

    void resize(std::size_t new_size)
    {
        if (new_size < size_)
        {
            for (std::size_t i = new_size; i < size_; ++i)
            {
                AllocTraits::destroy(alloc_, data_ + i);
            }
            size_ = new_size;
        }
        else if (new_size > size_)
        {
            if (new_size > capacity_)
            {
                reserve(new_size);
            }
            for (std::size_t i = size_; i < new_size; ++i)
            {
                AllocTraits::construct(alloc_, data_ + i);
            }
            size_ = new_size;
        }
    }

    // Додавання елемента в кінець вектора
    void push_back(const T &value)
    {
        if (size_ == capacity_)
        {
            reserve(capacity_ == 0 ? 1 : capacity_ * 2);
        }
        AllocTraits::construct(alloc_, data_ + size_, value);
        ++size_;
    }

    // Створення елемента безпосередньо наприкінці пам'яті вектора
    template <typename... Args>
    T &emplace_back(Args &&...args)
    {
        if (size_ == capacity_)
        {
            reserve(capacity_ == 0 ? 1 : capacity_ * 2);
        }
        AllocTraits::construct(alloc_, data_ + size_, std::forward<Args>(args)...);
        T &ref = data_[size_];
        ++size_;
        return ref;
    }

    // Видалення останнього елемента
    void pop_back()
    {
        if (empty())
            throw std::out_of_range("SimpleVector::pop_back");
        --size_;
        AllocTraits::destroy(alloc_, data_ + size_);
    }

    // Знищення всіх об'єктів всередині вектора
    void clear() noexcept
    {
        for (std::size_t i = 0; i < size_; ++i)
        {
            AllocTraits::destroy(alloc_, data_ + i);
        }
        size_ = 0;
    }

    // Початок та кінець безперервного масиву
    iterator begin() noexcept { return data_; }
    iterator end() noexcept { return data_ + size_; }
    const_iterator begin() const noexcept { return data_; }
    const_iterator end() const noexcept { return data_ + size_; }
    const_iterator cbegin() const noexcept { return data_; }
    const_iterator cend() const noexcept { return data_ + size_; }
};