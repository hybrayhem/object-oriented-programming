#ifndef GTU_ARRAY
#define GTU_ARRAY

#include "iterable.h"
#include <cstddef> // for size_t
#include <memory>

namespace GTU {

    /* -------------------------------------------------------------------------- */
    /*                             GTUArray Definition                            */
    /* -------------------------------------------------------------------------- */
    template <class T, size_t SIZE>
    class GTUArray : public Iterable<T> {
    public:
        GTUArray<T, SIZE>(); // default constructor
        GTUArray<T, SIZE>(const GTUArray<T, SIZE> &copy); // copy constructor
        ~GTUArray<T, SIZE>();                        // destructor

        bool empty() const override;                       // Test whether container is empty
        size_t size() const override;                      // Return container size
        void erase(GTUIteratorConst<T> position) override; // Erase element pointed by the given iterator
        void clear() override;                             // Clear all content
        GTUIterator<T> begin() override;                   // Return iterator to beginning
        GTUIterator<T> end() override;                     // Return iterator to end
        GTUIteratorConst<T> constBegin() const override;   // Return a constant iterator to beginning
        GTUIteratorConst<T> constEnd() const override;     // Return a constant iterator to end

    private:
        std::shared_ptr<T> items;
        size_t len;
    };

    /* -------------------------------------------------------------------------- */
    /*                           GTUArray Implementation                          */
    /* -------------------------------------------------------------------------- */
    template <class T, size_t SIZE>
    GTUArray<T, SIZE>::GTUArray() : len(SIZE){
        items = std::shared_ptr<T>(new T[len], std::default_delete<T[]>());
    }

    template <class T, size_t SIZE>
    GTUArray<T, SIZE>::GTUArray(const GTUArray<T, SIZE> &copy) : len(copy.len){
        items = std::shared_ptr<T>(new T[len], std::default_delete<T[]>());
        for (size_t i = 0; i < len; i++)
            items.get()[i] = copy.items.get()[i];
    }

    template <class T, size_t SIZE>
    GTUArray<T, SIZE>::~GTUArray() {
        // delete[] items;
    }

    template <class T, size_t SIZE>
    bool GTUArray<T, SIZE>::empty() const {
        return (len == 0);
    }

    template <class T, size_t SIZE>
    size_t GTUArray<T, SIZE>::size() const {
        return len;
    }

    template <class T, size_t SIZE>
    void GTUArray<T, SIZE>::erase(GTUIteratorConst<T> position) {
        throw 404;
    }

    template <class T, size_t SIZE>
    void GTUArray<T, SIZE>::clear() {
        items.reset();
        len = 0;
    }

    template <class T, size_t SIZE>
    GTUIterator<T> GTUArray<T, SIZE>::begin() {
        return GTUIterator<T>(items.get());
    }

    template <class T, size_t SIZE>
    GTUIterator<T> GTUArray<T, SIZE>::end() {
        return GTUIterator<T>(items.get() + len);
    }

    template <class T, size_t SIZE>
    GTUIteratorConst<T> GTUArray<T, SIZE>::constBegin() const {
        return GTUIteratorConst<T>(items.get());
    }

    template <class T, size_t SIZE>
    GTUIteratorConst<T> GTUArray<T, SIZE>::constEnd() const {
        return GTUIteratorConst<T>(items.get() + len);
    }

}
#endif