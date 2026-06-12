#pragma once

#include <cstddef>
#include <iterator>
#include <memory>
#include <stdexcept>
#include <utility>

// Вузловий контейнер однозв'язного списку
template <typename T>
class SimpleForwardList
{
private:
    // Структура внутрішнього вузла списку
    struct Node
    {
        T value;
        Node *next{};
    };

    Node *head_{};       // Вказівник на перший елемент
    std::size_t size_{}; // Поточна кількість елементів у списку

public:
    class const_iterator;

    class iterator
    {
        friend class const_iterator;
        friend class SimpleForwardList;

    public:
        // Обов'язкові типи для інтеграції з STL алгоритмами та концептами C++20
        using iterator_concept = std::forward_iterator_tag;
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T *;
        using reference = T &;

        iterator() = default;
        explicit iterator(Node *current) noexcept : current_(current) {}

        reference operator*() const noexcept { return current_->value; }
        pointer operator->() const noexcept { return std::addressof(current_->value); }

        // Префіксний інкремент
        iterator &operator++() noexcept
        {
            current_ = current_->next;
            return *this;
        }

        // Постфіксний інкремент
        iterator operator++(int) noexcept
        {
            iterator old = *this;
            ++(*this);
            return old;
        }

        friend bool operator==(iterator lhs, iterator rhs) noexcept
        {
            return lhs.current_ == rhs.current_;
        }

        friend bool operator!=(iterator lhs, iterator rhs) noexcept
        {
            return !(lhs == rhs);
        }

    private:
        Node *current_{};
    };

    // Клас const ітератора для безпечного читання
    class const_iterator
    {
    public:
        using iterator_concept = std::forward_iterator_tag;
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = const T *;
        using reference = const T &;

        const_iterator() = default;
        explicit const_iterator(const Node *current) noexcept : current_(current) {}
        const_iterator(iterator it) noexcept : current_(it.current_) {}

        reference operator*() const noexcept { return current_->value; }
        pointer operator->() const noexcept { return std::addressof(current_->value); }

        const_iterator &operator++() noexcept
        {
            current_ = current_->next;
            return *this;
        }

        const_iterator operator++(int) noexcept
        {
            const_iterator old = *this;
            ++(*this);
            return old;
        }

        friend bool operator==(const_iterator lhs, const_iterator rhs) noexcept
        {
            return lhs.current_ == rhs.current_;
        }

        friend bool operator!=(const_iterator lhs, const_iterator rhs) noexcept
        {
            return !(lhs == rhs);
        }

    private:
        const Node *current_{};
    };

    SimpleForwardList() = default;

    // Конструктор копіювання
    SimpleForwardList(const SimpleForwardList &other)
    {
        copy_from(other);
    }

    // Конструктор переміщення
    SimpleForwardList(SimpleForwardList &&other) noexcept
        : head_(other.head_), size_(other.size_)
    {
        other.head_ = nullptr;
        other.size_ = 0;
    }

    // Оператор копіюючого присвоювання
    SimpleForwardList &operator=(const SimpleForwardList &other)
    {
        if (this != &other)
        {
            clear();
            copy_from(other);
        }
        return *this;
    }

    // Оператор переміщуючого присвоювання
    SimpleForwardList &operator=(SimpleForwardList &&other) noexcept
    {
        if (this != &other)
        {
            clear();
            head_ = other.head_;
            size_ = other.size_;
            other.head_ = nullptr;
            other.size_ = 0;
        }
        return *this;
    }

    ~SimpleForwardList()
    {
        clear();
    }

    bool empty() const noexcept { return head_ == nullptr; }
    std::size_t size() const noexcept { return size_; }

    // Доступ до першого елементу списку
    T &front()
    {
        if (empty())
            throw std::out_of_range("SimpleForwardList::front");
        return head_->value;
    }

    const T &front() const
    {
        if (empty())
            throw std::out_of_range("SimpleForwardList::front");
        return head_->value;
    }

    // Додавання елемента на початок списку
    void push_front(const T &value)
    {
        head_ = new Node{value, head_};
        ++size_;
    }

    // Конструювання елемента безпосередньо в пам'яті вузла
    template <typename... Args>
    T &emplace_front(Args &&...args)
    {
        head_ = new Node{T(std::forward<Args>(args)...), head_};
        ++size_;
        return head_->value;
    }

    // Видалення першого елемента
    void pop_front()
    {
        if (empty())
            throw std::out_of_range("SimpleForwardList::pop_front");
        Node *old_head = head_;
        head_ = head_->next;
        delete old_head;
        --size_;
    }

    // Вставка нового вузла після вказаної позиції ітератора
    iterator insert_after(iterator pos, const T &value)
    {
        if (pos.current_ == nullptr)
        {
            throw std::out_of_range("SimpleForwardList::insert_after");
        }
        Node *current = pos.current_;
        current->next = new Node{value, current->next};
        ++size_;
        return iterator{current->next};
    }

    // Видалення вузла після вказаної позиції ітератора
    iterator erase_after(iterator pos)
    {
        if (pos.current_ == nullptr || pos.current_->next == nullptr)
        {
            throw std::out_of_range("SimpleForwardList::erase_after");
        }
        Node *erased = pos.current_->next;
        pos.current_->next = erased->next;
        delete erased;
        --size_;
        return iterator{pos.current_->next};
    }

    // Очищення списку та звільнення динамічної пам'яті
    void clear() noexcept
    {
        while (head_ != nullptr)
        {
            Node *old_head = head_;
            head_ = head_->next;
            delete old_head;
        }
        size_ = 0;
    }

    // Методи для підтримки range-based for та алгоритмів STL
    iterator begin() noexcept { return iterator{head_}; }
    iterator end() noexcept { return iterator{nullptr}; }
    const_iterator begin() const noexcept { return const_iterator{head_}; }
    const_iterator end() const noexcept { return const_iterator{nullptr}; }
    const_iterator cbegin() const noexcept { return const_iterator{head_}; }
    const_iterator cend() const noexcept { return const_iterator{nullptr}; }

private:
    // Глибоке копіювання зв'язаного списку вузол за вузлом
    void copy_from(const SimpleForwardList &other)
    {
        if (other.head_ == nullptr)
            return;
        head_ = new Node{other.head_->value, nullptr};
        Node *dest = head_;
        Node *src = other.head_->next;
        while (src != nullptr)
        {
            dest->next = new Node{src->value, nullptr};
            dest = dest->next;
            src = src->next;
        }
        size_ = other.size_;
    }
};