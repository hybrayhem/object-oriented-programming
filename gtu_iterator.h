#ifndef GTU_ITERATOR
#define GTU_ITERATOR

#include <iterator>

namespace GTU {

    template <class T>
    class GTUIterator {
        using iterator_category = std::random_access_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using ptr = T *;
        using ref = T &;

    public:
        GTUIterator() : p_it(nullptr) {}
        GTUIterator(ptr p) : p_it(p) {
            //Intentionally left empty
        }

        // *, ->, ++, --, =, and ==, +, -
        ref operator*() const { return *p_it; }
        ptr operator->() { return p_it; }

        GTUIterator<T> operator++(int junk) { p_it++; return *this; }               // Prefix increment
        GTUIterator<T> operator++() { GTUIterator<T> p = *this; p_it++; return p; } // Postfix increment
        GTUIterator<T> operator--(int junk) { p_it--; return *this; }               // Prefix decrement
        GTUIterator<T> operator--() { GTUIterator<T> p = *this; p_it--; return p; } // Postfix decrement

        GTUIterator<T> operator=(T *p) { p_it = p; *this; }
        bool operator==(const GTUIterator<T> &it) { return p_it == it.p_it; }
        bool operator!=(const GTUIterator<T> &it) { return p_it != it.p_it; }
        GTUIterator<T> operator+(difference_type d) { return GTUIterator<T>(p_it + d); }
        GTUIterator<T> operator-(difference_type d) { return GTUIterator<T>(p_it - d); }

    private:
        ptr p_it;
    };
}
#endif