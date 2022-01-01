#ifndef GTU_VECTOR
#define GTU_VECTOR

#include "iterable.h"
#include <cstddef> // for size_t
#include <memory>

namespace GTU {

    /* -------------------------------------------------------------------------- */
    /*                            GTUVector Definition                            */
    /* -------------------------------------------------------------------------- */
    template <class T>
    class GTUVector : public Iterable<T> {
    public:
        GTUVector<T>(); // default constructor
        GTUVector<T>(int size);
        GTUVector<T>(const GTUVector<T> &copy); // copy constructor
        ~GTUVector<T>();                        // destructor

        bool empty() const override;
        size_t size() const override;
        void erase(GTUIteratorConst<T> position) override;
        void clear() override;
        GTUIterator<T> begin() override;
        GTUIterator<T> end() override;
        GTUIteratorConst<T> constBegin() const override;
        GTUIteratorConst<T> constEnd() const override;

        void add(const T &item);
        T &operator[](int index);

    private:
        std::shared_ptr<T> items;
        size_t capacity;
        size_t used;
    };

    /* -------------------------------------------------------------------------- */
    /*                          GTUVector Implementation                          */
    /* -------------------------------------------------------------------------- */
    template <class T>
    GTUVector<T>::GTUVector() : capacity(10), used(0) {
        // std::shared_ptr<T> p(new T[capacity], std::default_delete<T[]>());
        // items = p;
        items = std::shared_ptr<T>(new T[capacity], std::default_delete<T[]>());
    }

    template <class T>
    GTUVector<T>::GTUVector(int size) : capacity(size), used(0) {
        items = std::shared_ptr<T>(new T[capacity], std::default_delete<T[]>());
    }

    template <class T>
    GTUVector<T>::GTUVector(const GTUVector<T> &copy) : capacity(copy.capacity), used(copy.used) {
        items = std::shared_ptr<T>(new T[capacity], std::default_delete<T[]>());
        for (size_t i = 0; i < used; i++)
            items.get()[i] = copy.items.get()[i];
    }

    template <class T>
    GTUVector<T>::~GTUVector() {
        // delete[] items;
    }

    template <class T>
    bool GTUVector<T>::empty() const {
        return (used == 0);
    }

    template <class T>
    size_t GTUVector<T>::size() const {
        return used;
    }

    template <class T>
    void GTUVector<T>::erase(GTUIteratorConst<T> position) {
        // GTUIteratorConst<T> temp = position;
        // To be implemented
        for (GTUIteratorConst<T> i = position; i != constEnd(); i++)
            i = i + 1;
        used--;
    }

    template <class T>
    void GTUVector<T>::clear() {
        items.reset();
    }

    template <class T>
    GTUIterator<T> GTUVector<T>::begin() {
        return GTUIterator<T>(items.get());
    }

    template <class T>
    GTUIterator<T> GTUVector<T>::end() {
        return GTUIterator<T>(items.get() + used);
    }

    template <class T>
    GTUIteratorConst<T> GTUVector<T>::constBegin() const {
        return GTUIteratorConst<T>(items.get());
    }

    template <class T>
    GTUIteratorConst<T> GTUVector<T>::constEnd() const {
        return GTUIteratorConst<T>(items.get() + used);
    }

    template <class T>
    void GTUVector<T>::add(const T &item) {
        if (used >= capacity) {
            std::shared_ptr<T> temp(new T[capacity], std::default_delete<T[]>());
            temp = items;

            capacity *= 2;
            items = std::shared_ptr<T>(new T[capacity], std::default_delete<T[]>());
            for (int i = 0; i < used; i++)
                items.get()[i] = temp.get()[i];
        }
        items.get()[used] = item;
        used++;
    }

    template <class T>
    T &GTUVector<T>::operator[](int index) {
        return items.get()[index];
    }
}
#endif