#include "dayofyear.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using namespace DateTime;

void writeSet(const DayOfYearSet &dofs, string filename) {
    ofstream outStream;

    outStream.open(filename, fstream::out);
    if (outStream.fail()) {
        cerr << "Couldn't open file: " << filename << endl;
        exit(0);
    }

    outStream << dofs.id << dofs << endl;
    outStream.close();
}

int DayOfYearSet::totalObject = 0;

int main() {
    /* ---------------------------- Constructor Tests --------------------------- */
    DayOfYearSet s1, s2(20);
    cout << "> Default constructor (empty set)" << endl
         << s1;
    cout << "> Construct by size (empty set)" << endl
         << s2;

    cout << "> Construct by vector" << endl;
    vector<DateTime::DayOfYearSet::DayOfYear> dayVector = {DateTime::DayOfYearSet::DayOfYear(1, 2), DateTime::DayOfYearSet::DayOfYear(2, 3), DateTime::DayOfYearSet::DayOfYear(4, 5), DateTime::DayOfYearSet::DayOfYear(6, 7)};
    DayOfYearSet s3(dayVector);
    cout << s3;

    cout << "> Copy constructor (from the set upward)" << endl;
    DayOfYearSet s4(s3);
    cout << s4;

    cout << "Total Number Of Objects: " << DayOfYearSet::getTotalNumberOfObjects() << endl
         << endl;

    
    writeSet(s1, "s1.txt");
    writeSet(s2, "s2.txt");
    writeSet(s3, "s3.txt");
    /* ----------------------------- Function tests ----------------------------- */
    cout << "> Add two element to Set 1" << endl;
    s1.add(DayOfYearSet::DayOfYear(12, 5));
    s1.add(DayOfYearSet::DayOfYear(2, 3));
    cout << s1;

    cout << "> Add element to Set 3" << endl;
    s3.add(DayOfYearSet::DayOfYear(12, 5));
    cout << s3;

    cout << "> Remove middle element from Set 3" << endl;
    s3.remove(2);
    cout << s3 << "Size: " << s3.size() << endl;

    cout << "> Remove first element from Set 4" << endl;
    s4.remove(0);
    cout << s4 << "Size: " << s4.size() << endl;

    /* ----------------------------- Operator Tests ----------------------------- */

    cout << "> Set 1 + Set 3 " << endl << (s1 + s3);
    cout << "> Set 3 + Set 4 " << endl << (s3 + s4);

    cout << "> Set 1 - Set 3 " << endl << (s1 - s3);
    cout << "> Set 3 - Set 4 " << endl << (s3 - s4);

    cout << "> Set 1 ^ Set 3 " << endl << (s1 ^ s3);
    cout << "> Set 3 ^ Set 4 " << endl << (s3 ^ s4);
    
    /* ----------------------------- De Morgan's Tests ----------------------------- */
    cout << "> !s1 ^ !s2 == (!s1 + s4) " << endl << ((!(s1 + s4)) == ((!s1) ^ (!s2)));

    /* ----------------------------- ! Operator Test ---------------------------- */
    DateTime::get_selection("Press 1 to see ! operator: ", 1, 1);
    cout << "> !Set 3 " << endl << (!s3);


    /*
    DateTime::DayOfYearSet::DayOfYear dayofyear(1, 1), dof1;

    cout << dayofyear.getDay() << endl;
    cout << dayofyear.getMonthNumber() << endl;
    cout << dayofyear << endl;
    // dayofyear.input();
    dayofyear.output();

    vector<DateTime::DayOfYearSet::DayOfYear> dayVector = {DateTime::DayOfYearSet::DayOfYear(1, 2), DateTime::DayOfYearSet::DayOfYear(2, 3), DateTime::DayOfYearSet::DayOfYear(4, 5), DateTime::DayOfYearSet::DayOfYear(6, 7)};
    vector<DateTime::DayOfYearSet::DayOfYear> dayVector1 = {DateTime::DayOfYearSet::DayOfYear(1, 2), DateTime::DayOfYearSet::DayOfYear(2, 3), DateTime::DayOfYearSet::DayOfYear(4, 5)};
    vector<DateTime::DayOfYearSet::DayOfYear> dayVector2 = {DateTime::DayOfYearSet::DayOfYear(1, 2), DateTime::DayOfYearSet::DayOfYear(4, 5), DateTime::DayOfYearSet::DayOfYear(2, 3), DateTime::DayOfYearSet::DayOfYear(6, 7)};
    vector<DateTime::DayOfYearSet::DayOfYear> dayVector3 = {DateTime::DayOfYearSet::DayOfYear(11, 12), DateTime::DayOfYearSet::DayOfYear(9, 10), DateTime::DayOfYearSet::DayOfYear(2, 3), DateTime::DayOfYearSet::DayOfYear(6, 7), DateTime::DayOfYearSet::DayOfYear(3, 4)};
    vector<DateTime::DayOfYearSet::DayOfYear> dayVector4 = {DateTime::DayOfYearSet::DayOfYear(1, 2), DateTime::DayOfYearSet::DayOfYear(2, 3), DateTime::DayOfYearSet::DayOfYear(4, 5), DateTime::DayOfYearSet::DayOfYear(6, 7)};
    DateTime::DayOfYearSet daySet(dayVector);
    DateTime::DayOfYearSet daySet1(dayVector1);
    DateTime::DayOfYearSet daySet2(dayVector2);
    DateTime::DayOfYearSet daySet3(dayVector3);
    DateTime::DayOfYearSet daySet4(dayVector4);
    cout << daySet;
    daySet.add(dayofyear);
    daySet.add(dayofyear);
    daySet.add(dayofyear);
    cout << daySet;
    daySet.remove(6);
    daySet.remove(4);
    daySet.remove(2);
    daySet.remove(10);
    cout << daySet;

    cout << (dayofyear == dof1) << (dayofyear != dof1) << endl;
    cout << (daySet == daySet1) << (daySet != daySet1) << endl;
    cout << (daySet == daySet2) << (daySet != daySet2) << endl;
    cout << (daySet == daySet3) << (daySet != daySet3) << endl;
    cout << (daySet == daySet4) << (daySet != daySet4) << endl;



    cout << (daySet1 + daySet2) << endl;
    cout << (daySet1 + daySet3) << endl;

    cout << "DaySet3\n" << daySet3;
    cout << "DaySet2\n" << daySet2;
    cout << "DaySet3 - DaySet2\n" << (daySet3 - daySet2);
    
    cout << "DaySet3 ^ DaySet2\n" << (daySet3 ^ daySet2);
*/
    return 0;
}