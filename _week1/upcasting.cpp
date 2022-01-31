#include <iostream>
using namespace std;

class Base {
public:
    string name;
    virtual void print();
};

void Base::print() {
    cout << "base.print: " << name << endl;
}

class Sub : public Base {
public:
    string type;
    void print();
};

void Sub::print() {
    cout << "sub.print: " << name << ", " << type << endl;
};

int main() {
// Dynamically allocated using "new" operator, created in the heap memory
// No Slicing Problem
    Base *base = new Base;
    Sub *sub = new Sub;

    base->name = "Cat";
    sub->name = "Dog";
    sub->type = "HavHav";

    // base->print();
    // sub->print();

    base = sub;
    base->print(); // sub.print: Dog, HavHav

    // sub = base;
    // sub->print();


// Created on the stack memory, they are destroyed automatically when they go out of scope
// This one has Slicing Problem
    Base base2;
    Sub sub2;

    base2.name = "Cat";
    sub2.name = "Dog";
    sub2.type = "HavHav";

    base2 = sub2;
    base2.print(); // base.print: Dog

    return 0;
}
