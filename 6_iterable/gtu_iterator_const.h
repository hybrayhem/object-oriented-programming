#ifndef GTU_ITERATOR_CONST
#define GTU_ITERATOR_CONST

#include <iterator>

namespace GTU {

    template <class T>
    class GTUIteratorConst {
        public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T *;
        using reference = T &;

        GTUIteratorConst() : p_it(nullptr) {}
        GTUIteratorConst(pointer p) : p_it(p) {
            //Intentionally left empty
        }
        ~GTUIteratorConst() {}

        GTUIteratorConst<T> &operator=(pointer p) {
            p_it = p;
            return *this;
        };
        operator bool() const {
            if (p_it) return true;
            return false;
        }

        bool operator==(const GTUIteratorConst<T> &it) const { return (p_it == it.p_it); }
        bool operator!=(const GTUIteratorConst<T> &it) const { return (p_it != it.p_it); }

        GTUIteratorConst<T> operator++() { ++p_it; return *this; } // Prefix increment
        GTUIteratorConst<T> operator++(int junk) { GTUIteratorConst<T> p = *this; ++p_it; return p; } // Postfix increment
        GTUIteratorConst<T> operator--() { --p_it; return *this; } // Prefix decrement
        GTUIteratorConst<T> operator--(int junk) { GTUIteratorConst<T> p = *this; --p_it; return p; } // Postfix decrement

        GTUIteratorConst<T> operator+(const difference_type &d) { auto old = p_it; p_it += d; GTUIteratorConst<T> p = *this; p_it = old; return p; }
        GTUIteratorConst<T> operator+(int d) { auto old = p_it; p_it += d; GTUIteratorConst<T> p = *this; p_it = old; return p; }
        GTUIteratorConst<T> operator-(const difference_type &d) { auto old = p_it; p_it -= d; GTUIteratorConst<T> p = *this; p_it = old; return p; }
        GTUIteratorConst<T> operator-(int d) { auto old = p_it; p_it -= d; GTUIteratorConst<T> p = *this; p_it = old; return p; }

        const reference operator*() const { return *p_it; }
        const pointer operator->() { return p_it; }

    private:
        pointer p_it;
    };
}
#endif