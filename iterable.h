#ifndef GTU_ITERABLE
#define GTU_ITERABLE

#include "gtu_iterator.h"
#include "gtu_iterator_const.h"
#include <iostream>

namespace GTU {

    template <class T>
    class Iterable {
        virtual bool empty() const = 0;                       // Test whether container is empty
        virtual size_t size() const = 0;                      // Return container size
        virtual void erase(GTUIteratorConst<T> position) = 0; // Erase element pointed by the given iterator
        virtual void clear() = 0;                             // Clear all content
        virtual GTUIterator<T> begin() = 0;                   // Return iterator to beginning
        virtual GTUIterator<T> end() = 0;                     // Return iterator to end
        virtual GTUIteratorConst<T> constBegin() const = 0;   // Return a constant iterator to beginning
        virtual GTUIteratorConst<T> constEnd() const = 0;     // Return a constant iterator to end
    };

}
#endif