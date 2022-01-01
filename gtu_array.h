#ifndef GTU_ARRAY
#define GTU_ARRAY

#include "iterable.h"
#include <cstddef> // for size_t
#include <memory>

namespace GTU {

    template <class T, size_t SIZE>
    class GTUArray : public Iterable<T> {
    public:
        bool empty() const override;
        size_t getSize() const override;
        void erase(GTUIteratorConst<T> position) override;
        void clear() override;
        GTUIterator<T> begin() override;
        GTUIterator<T> end() override;
        GTUIteratorConst<T> constBegin() const override;
        GTUIteratorConst<T> constEnd() const override;

    private:
        std::shared_ptr<T> items;
        size_t size;
    };

}
#endif