#ifndef GTU_ITERATOR_CONST
#define GTU_ITERATOR_CONST

#include <iterator>

namespace GTU {

    template <class T>
    class GTUIteratorConst {
        using iterator_category = std::random_access_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using ptr = T *;
        using ref = T &;

    public:
        GTUIteratorConst() : p_it(nullptr) {}
        GTUIteratorConst(ptr p) : p_it(p) {
            //Intentionally left empty
        }

        // *, ->, ++, --, =, and ==, +, -
        const ref operator*() const { return *p_it; }
        const ptr operator->() { return p_it; }

        GTUIteratorConst<T> operator++(int junk) { p_it++; return *this; }               // Prefix increment
        GTUIteratorConst<T> operator++() { GTUIteratorConst<T> p = *this; p_it++; return p; } // Postfix increment
        GTUIteratorConst<T> operator--(int junk) { p_it--; return *this; }               // Prefix decrement
        GTUIteratorConst<T> operator--() { GTUIteratorConst<T> p = *this; p_it--; return p; } // Postfix decrement

        GTUIteratorConst<T> operator=(T *p) { p_it = p; *this; }
        bool operator==(const GTUIteratorConst<T> &it) { return p_it == it.p_it; }
        bool operator!=(const GTUIteratorConst<T> &it) { return p_it != it.p_it; }
        GTUIteratorConst<T> operator+(difference_type d) { return GTUIteratorConst<T>(p_it + d); }
        GTUIteratorConst<T> operator-(difference_type d) { return GTUIteratorConst<T>(p_it - d); }

    private:
        ptr p_it;
    };

}
#endif