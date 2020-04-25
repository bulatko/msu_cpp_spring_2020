template <class T>
class Allocator
{
public:
    T *alloc(size_t count)
    {
        return static_cast<T *>(operator new[](count * sizeof(T)));
    }
    void unalloc(T *pointer, size_t count)
    {
        operator delete[](pointer, count * sizeof(T));
    }
    template <class... Args>
    void construct(T *p, Args &&... args)
    {
        new (p) T(std::forward<Args>(args)...);
    }
    void destroy(T *ptr) noexcept
    {
        ptr->~T();
    }
};

template <class T>
class Iterator : public std::iterator<std::random_access_iterator_tag, T>
{
    T *pointer_;

public:
    explicit Iterator(T *pointer) : pointer_(pointer) {}

    T &operator*() const
    {
        return *pointer_;
    }
    Iterator operator+(size_t n) const
    {
        return Iterator(pointer_ + n);
    }
    Iterator operator-(size_t n) const
    {
        return Iterator(pointer_ - n);
    }
    Iterator &operator+=(size_t n)
    {
        *this = *this + n;
        return *this;
    }
    Iterator &operator-=(size_t n)
    {
        *this = *this - n;
        return *this;
    }
    Iterator &operator++()
    {
        *this = *this + 1;
        return *this;
    }
    Iterator &operator--()
    {
        *this = *this - 1;
        return *this;
    }
    Iterator &operator[](int n)
    {
        return pointer_[n];
    }
    bool operator==(const Iterator<T> &a) const
    {
        return pointer_ == a.pointer_;
    }
    bool operator!=(const Iterator<T> &a) const
    {
        return !(*this == a);
    }
    bool operator<(const Iterator<T> &a)
    {
        return (*this - a > 0);
    }
    bool operator>(const Iterator<T> &a)
    {
        return a < *this;
    }
    bool operator>=(const Iterator<T> &a)
    {
        return !(*this < a);
    }
    bool operator<=(const Iterator<T> &a)
    {
        return !(*this > a);
    }
};

template <class T, class Alloc = Allocator<T>>
class Vector
{
private:
    Alloc allocator_;
    T *elements_;
    size_t size_;
    size_t max_size_;

public:
    Vector(size_t size = 0) : size_(size), max_size_(size + 5)
    {
        elements_ = allocator_.alloc(max_size_);
        for (size_t i = 0; i < size; ++i)
        {
            allocator_.construct(elements_ + i);
        }
    }

    T &operator[](size_t idx)
    {
        if (idx < size_)
        {
            return elements_[idx];
        }
        else
        {
            throw std::out_of_range("Error");
        }
    }

    void reserve(size_t new_size)
    {
        if (new_size > max_size_)
        {
            T *tmp = allocator_.alloc(new_size);
            for (size_t i = 0; i < size_; ++i)
            {
                new (tmp + i) T(elements_[i]);
                (elements_ + i)->~T();
            }
            allocator_.unalloc(elements_, max_size_);
            max_size_ = new_size;
            elements_ = tmp;
        }
    }

    void push_back(const T &elem)
    {
        if (size_ >= max_size_)
            reserve(max_size_ + max_size_);
        new (elements_ + size_) T(elem);
        size_++;
    }

    void pop_back()
    {
        if (size_)
        {
            size_--;
            (elements_ + size_)->~T();
        }
    }

    bool empty() const
    {
        return size_ == 0;
    }

    size_t size() const
    {
        return size_;
    }

    void clear()
    {
        for (size_t i = 0; i < size_; ++i)
        {
            allocator_.destroy(elements_ + i);
        }
        size_ = 0;
    }

    Iterator<T> begin()
    {
        return Iterator<T>(elements_);
    }

    Iterator<T> end()
    {
        return Iterator<T>(elements_ + size_);
    }

    std::reverse_iterator<Iterator<T>> rbegin()
    {
        return std::reverse_iterator<Iterator<T>>(Iterator<T>(elements_ + size_));
    }

    std::reverse_iterator<Iterator<T>> rend()
    {
        return std::reverse_iterator<Iterator<T>>(Iterator<T>(elements_));
    }

    size_t capacity() const
    {
        return max_size_;
    }

    void resize(size_t new_size)
    {
        if (new_size >= size_)
        {
            if (new_size > max_size_)
            {
                reserve(new_size);
            }
            for (size_t i = size_; i < new_size; ++i)
            {
                allocator_.construct(elements_ + i);
            }
        }
        else
        {
            for (size_t i = new_size; i < size_; ++i)
            {
                allocator_.destroy(elements_ + i);
            }
        }
        size_ = new_size;
    }

    ~Vector()
    {
        for (size_t i = 0; i < size_; ++i)
        {
            allocator_.destroy(elements_ + i);
        }
    }
};