#ifndef GTU_ITERATOR
#define GTU_ITERATOR

#include <iterator>
#include <memory>

namespace GTU {

    template <class T>
    class GTUIterator {
    public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T *;
        using reference = T &;

        GTUIterator() : p_it(nullptr) {}
        GTUIterator(pointer p) : p_it(p) {
            //Intentionally left empty
        }
        ~GTUIterator() {}

        GTUIterator<T> &operator=(pointer p) {
            p_it = p;
            return *this;
        };
        operator bool() const {
            if (p_it) return true;
            return false;
        }

        bool operator==(const GTUIterator<T> &it) const { return (p_it == it.p_it); }
        bool operator!=(const GTUIterator<T> &it) const { return (p_it != it.p_it); }

        GTUIterator<T> operator++() { ++p_it; return *this; } // Prefix increment
        GTUIterator<T> operator++(int junk) { GTUIterator<T> p = *this; ++p_it; return p; } // Postfix increment
        GTUIterator<T> operator--() { --p_it; return *this; } // Prefix decrement
        GTUIterator<T> operator--(int junk) { GTUIterator<T> p = *this; --p_it; return p; } // Postfix decrement

        GTUIterator<T> operator+(const difference_type &d) { auto old = p_it; p_it += d; GTUIterator<T> p = *this; p_it = old; return p; }
        GTUIterator<T> operator+(int d) { auto old = p_it; p_it += d; GTUIterator<T> p = *this; p_it = old; return p; }
        GTUIterator<T> operator-(const difference_type &d) { auto old = p_it; p_it -= d; GTUIterator<T> p = *this; p_it = old; return p; }
        GTUIterator<T> operator-(int d) { auto old = p_it; p_it -= d; GTUIterator<T> p = *this; p_it = old; return p; }

        reference operator*() { return *p_it; }
        pointer operator->() { return p_it; }

    private:
        pointer p_it;
    };
}
#endif