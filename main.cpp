#include "gtu_array.h"
#include "gtu_set.h"
#include "gtu_vector.h"

#include <algorithm>
#include <iostream>

using namespace std;
using namespace GTU;

int main() {
    GTUVector<int> testVec;

    testVec.add(2);
    testVec.add(3);
    testVec.add(5);
    testVec.add(4);
    testVec.add(1);
    testVec.add(7);
    testVec.add(6);
    testVec.add(11);
    testVec.add(9);
    testVec.add(10);
    testVec.add(12);
    testVec.add(8);
    testVec.add(15);
    testVec.add(14);
    testVec.add(13);
    cout << "> TESTING range based for loop" << endl;
    for (auto i : testVec)
        std::cout << i << " ";
    cout << endl;

    cout << "> TESTING for each loop after sort" << endl;
    std::for_each(testVec.begin(), testVec.end(), [](int i) { std::cout << i << " "; });
    cout << endl;

    return 0;
}