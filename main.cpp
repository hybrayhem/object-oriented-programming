#include "gtu_array.h"
#include "gtu_set.h"
#include "gtu_vector.h"

#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
using namespace GTU;

int main() {

    cout << "\n/* -------------------------------------------------------------------------- */\n"
         << "/*                               TEST GTUVector                               */\n"
         << "/* -------------------------------------------------------------------------- */\n\n";
    GTUVector<int> testVector;

    cout << "\nIs vector empty: " << testVector.empty() << ". Size: " << testVector.size() << endl;
    cout << "Adding random integers to vector...\n";
    testVector.add(2);
    testVector.add(3);
    testVector.add(5);
    testVector.add(4);
    testVector.add(1);
    testVector.add(7);
    testVector.add(6);
    testVector.add(11);
    testVector.add(9);
    testVector.add(10);
    testVector.add(12);
    testVector.add(8);
    testVector.add(15);
    testVector.add(14);
    testVector.add(13);
    cout << "Is vector EMPTY: " << testVector.empty() << ". Size: " << testVector.size() << endl
         << endl;

    cout << "> testing RANGE BASED for loop" << endl;
    for (auto i : testVector)
        std::cout << i << " ";
    cout << endl
         << endl;

    try {
        cout << "ERASE last item from vector...\n";
        testVector.erase(testVector.constEnd());
        for (auto i : testVector)
            std::cout << i << " ";
    } catch (int e) {
        cout << "Exception " << e << ": on erase method of vector";
    }

    GTUIterator<int> resultv;
    int numv = 50;
    resultv = std::find(testVector.begin(), testVector.end(), numv);
    (resultv != testVector.end())
        ? std::cout << "\nFIND testVector contains " << numv << "\n\n"
        : std::cout << "\nFIND testVector does not contain " << numv << "\n\n";

    sort(testVector.begin(), testVector.end());
    cout << "> TESTING for each loop after sort" << endl;
    std::for_each(testVector.begin(), testVector.end(), [](int i) { std::cout << i << " "; });
    cout << endl;

    try {
        testVector.clear();
        cout << "\nafter CLEAR is vector empty: " << testVector.empty() << ". Size: " << testVector.size() << endl;
    } catch (int e) {
        cout << "Exception " << e << ": on clear method of vector";
    }

    cout << "\n/* -------------------------------------------------------------------------- */\n"
         << "/*                                 TEST GTUSet                                */\n"
         << "/* -------------------------------------------------------------------------- */\n\n";
    GTUSet<int> testSet;

    cout << "\nIs set empty: " << testSet.empty() << ". Size: " << testSet.size() << endl;
    cout << "Adding random integers to set...\n";
    testSet.add(2);
    testSet.add(3);
    testSet.add(5);
    testSet.add(4);
    testSet.add(1);
    testSet.add(7);
    testSet.add(6);
    testSet.add(11);
    testSet.add(9);
    testSet.add(10);
    testSet.add(12);
    testSet.add(8);
    testSet.add(15);
    testSet.add(14);
    testSet.add(13);
    cout << "Is set EMPTY: " << testSet.empty() << ". Size: " << testSet.size() << endl
         << endl;

    cout << "> testing RANGE BASED for loop" << endl;
    for (auto i : testSet)
        std::cout << i << " ";
    cout << endl
         << endl;

    cout << "DELETE 4. item from set...\n";
    testSet.delete_(3);
    for (auto i : testSet)
        std::cout << i << " ";

    cout << "\n\nERASE last item from set...\n";
    testSet.erase(testSet.constEnd());
    for (auto i : testSet)
        std::cout << i << " ";

    GTUIterator<int> results;
    int nums = 50;
    results = std::find(testSet.begin(), testSet.end(), nums);
    (results != testSet.end())
        ? std::cout << "\n\nFIND testSet contains " << nums << "\n\n"
        : std::cout << "\n\nFIND testSet does not contain " << nums << "\n\n";

    sort(testSet.begin(), testSet.end());
    cout << "> TESTING for each loop after sort" << endl;
    std::for_each(testSet.begin(), testSet.end(), [](int i) { std::cout << i << " "; });
    cout << endl;

    testSet.clear();
    cout << "\nafter CLEAR is set empty: " << testSet.empty() << ". Size: " << testSet.size() << endl;

    try {
        GTUSet<int> unionSet1, unionSet2, unionResult;
        unionSet1.add(1);
        unionSet1.add(2);
        unionSet1.add(3);
        unionSet2.add(3);
        unionSet2.add(6);
        unionSet2.add(9);
        unionResult = unionSet1.union_(unionSet2);
        cout << "\n\nUNION ";
        for (auto i : unionSet1)
            std::cout << i << " ";
        cout << " + ";
        for (auto i : unionSet2)
            std::cout << i << " ";
        cout << " = ";
        for (auto i : unionResult)
            std::cout << i << " ";
        cout << endl;
    } catch (int e) {
        cout << "Exception " << e << ": on union method of set";
    }

    try {
        GTUSet<int> intersectSet1, intersectSet2, intersectResult;
        intersectSet1.add(1);
        intersectSet1.add(2);
        intersectSet1.add(3);
        intersectSet2.add(3);
        intersectSet2.add(6);
        intersectSet2.add(9);
        intersectResult = intersectSet1.intersect(intersectSet2);
        cout << "\n\nINTERSECT ";
        for (auto i : intersectSet1)
            std::cout << i << " ";
        cout << " ^ ";
        for (auto i : intersectSet2)
            std::cout << i << " ";
        cout << " = ";
        for (auto i : intersectResult)
            std::cout << i << " ";
        cout << endl;
    } catch (int e) {
        cout << "Exception " << e << ": on intersect method of set";
    }

    /* -------------------------------------------------------------------------- */
    /*                                TEST GTUArray                               */
    /* -------------------------------------------------------------------------- */
    cout << "\n/* -------------------------------------------------------------------------- */\n"
         << "/*                                TEST GTUArray                               */\n"
         << "/* -------------------------------------------------------------------------- */\n\n";
    GTUVector<int> testArray;

    cout << "\nIs array empty: " << testArray.empty() << ". Size: " << testArray.size() << endl;
    cout << "Adding random integers to array...\n";
    testArray.add(5);
    testArray.add(4);
    testArray.add(1);
    testArray.add(7);
    testArray.add(12);
    testArray.add(13);
    cout << "Is array EMPTY: " << testArray.empty() << ". Size: " << testArray.size() << endl
         << endl;

    cout << "> testing RANGE BASED for loop" << endl;
    for (auto i : testArray)
        std::cout << i << " ";
    cout << endl
         << endl;

    try {
        cout << "ERASE last item from array...\n";
        testArray.erase(testArray.constEnd());
        for (auto i : testArray)
            std::cout << i << " ";
    } catch (int e) {
        cout << "Exception " << e << ": on erase method of array";
    }

    GTUIterator<int> resulta;
    int numa = 50;
    resulta = std::find(testArray.begin(), testArray.end(), numa);
    (resulta != testArray.end())
        ? std::cout << "\nFIND testArray contains " << numa << "\n\n"
        : std::cout << "\nFIND testArray does not contain " << numa << "\n\n";

    sort(testArray.begin(), testArray.end());
    cout << "> TESTING for each loop after sort" << endl;
    std::for_each(testArray.begin(), testArray.end(), [](int i) { std::cout << i << " "; });
    cout << endl;

    try {
        testArray.clear();
        cout << "\nafter CLEAR is array empty: " << testArray.empty() << ". Size: " << testArray.size() << endl;
    } catch (int e) {
        cout << "Exception " << e << ": on clear method of array";
    }

    return 0;
}