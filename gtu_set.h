#ifndef GTU_SET
#define GTU_SET

#include "iterable.h"
#include <cstddef> // for size_t
#include <memory>

namespace GTU {

    /* -------------------------------------------------------------------------- */
    /*                              GTUSet Definiton                              */
    /* -------------------------------------------------------------------------- */
    template <class T>
    class GTUSet : public Iterable<T> {
    public:
        GTUSet<T>(); // default constructor
        GTUSet<T>(int size);
        GTUSet<T>(const GTUSet<T> &copy); // copy constructor
        ~GTUSet<T>();                     // destructor

        bool empty() const override;
        size_t size() const override;
        void erase(GTUIteratorConst<T> position) override;
        void clear() override;
        GTUIterator<T> begin() override;
        GTUIterator<T> end() override;
        GTUIteratorConst<T> constBegin() const override;
        GTUIteratorConst<T> constEnd() const override;

        void add(const T &item);
        void delete_(int index);
        GTUSet<T> intersect(const GTUSet<T> &set) const;
        GTUSet<T> union_(const GTUSet<T> &set) const;

    private:
        std::shared_ptr<T> set;
        size_t capacity;
        size_t used;

        int search(const T &value) const; // search value return index or -1 for non-exist
    };

    /* -------------------------------------------------------------------------- */
    /*                            GTUSet Implementation                           */
    /* -------------------------------------------------------------------------- */
    template <class T>
    GTUSet<T>::GTUSet() : capacity(10), used(0) {
        set = std::shared_ptr<T>(new T[capacity], std::default_delete<T[]>());
    }

    template <class T>
    GTUSet<T>::GTUSet(int size) : capacity(size), used(0) {
        set = std::shared_ptr<T>(new T[capacity], std::default_delete<T[]>());
    }

    template <class T>
    GTUSet<T>::GTUSet(const GTUSet<T> &copy) : capacity(copy.capacity), used(copy.used) {
        set = std::shared_ptr<T>(new T[capacity], std::default_delete<T[]>());
        for (size_t i = 0; i < used; i++)
            set.get()[i] = copy.set.get()[i];
    }

    template <class T>
    GTUSet<T>::~GTUSet() {
        // delete[] set;
    }

    template <class T>
    bool GTUSet<T>::empty() const {
        return (used == 0);
    }

    template <class T>
    size_t GTUSet<T>::size() const {
        return used;
    }

    template <class T>
    void GTUSet<T>::erase(GTUIteratorConst<T> position) {
        // GTUIteratorConst<T> temp = position;
        // To be implemented
        for (GTUIteratorConst<T> i = position; i != constEnd(); i++)
            i = i + 1;
        used--;
    }

    template <class T>
    void GTUSet<T>::clear() {
        set.reset();
    }

    template <class T>
    GTUIterator<T> GTUSet<T>::begin() {
        return GTUIterator<T>(set.get());
    }

    template <class T>
    GTUIterator<T> GTUSet<T>::end() {
        return GTUIterator<T>(set.get() + used);
    }

    template <class T>
    GTUIteratorConst<T> GTUSet<T>::constBegin() const {
        return GTUIteratorConst<T>(set.get());
    }

    template <class T>
    GTUIteratorConst<T> GTUSet<T>::constEnd() const {
        return GTUIteratorConst<T>(set.get() + used);
    }

    template <class T>
    void GTUSet<T>::add(const T &item) {
        if (search(item) != -1) return; // set items must be unique

        if (used >= capacity) {
            std::shared_ptr<T> temp(new T[capacity], std::default_delete<T[]>());
            temp = set;

            capacity *= 2;
            set = std::shared_ptr<T>(new T[capacity], std::default_delete<T[]>());
            for (int i = 0; i < used; i++)
                set.get()[i] = temp.get()[i];
        }
        set.get()[used] = item;
        used++;
    }

    template <class T>
    void GTUSet<T>::delete_(int index) {
        if (index < used) {
            for (int i = index; i < used; i++)
                set.get()[i] = set.get()[i + 1];
            used--;
        } else
            std::cout << "Invalid index to remove: " << index << std::endl;
    }

    template <class T>
    GTUSet<T> GTUSet<T>::intersect(const GTUSet<T> &set) const {}

    template <class T>
    GTUSet<T> GTUSet<T>::union_(const GTUSet<T> &set) const {}

    template <class T>
    int GTUSet<T>::search(const T &value) const {}

}
#endif