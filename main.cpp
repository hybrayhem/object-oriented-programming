#include "dayofyear.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    DateTime::DayOfYearSet::DayOfYear dayofyear(1, 1), dof1;

    cout << dayofyear.getDay() << endl;
    cout << dayofyear.getMonthNumber() << endl;
    cout << dayofyear << endl;
    dayofyear.input();
    dayofyear.output();

    vector<DateTime::DayOfYearSet::DayOfYear> dayVector = {DateTime::DayOfYearSet::DayOfYear(1, 2), DateTime::DayOfYearSet::DayOfYear(2, 3), DateTime::DayOfYearSet::DayOfYear(4, 5), DateTime::DayOfYearSet::DayOfYear(6, 7)};
    vector<DateTime::DayOfYearSet::DayOfYear> dayVector1 = {DateTime::DayOfYearSet::DayOfYear(1, 2), DateTime::DayOfYearSet::DayOfYear(2, 3), DateTime::DayOfYearSet::DayOfYear(4, 5)};
    vector<DateTime::DayOfYearSet::DayOfYear> dayVector2 = {DateTime::DayOfYearSet::DayOfYear(1, 2), DateTime::DayOfYearSet::DayOfYear(4, 5), DateTime::DayOfYearSet::DayOfYear(2, 3), DateTime::DayOfYearSet::DayOfYear(6, 7)};
    vector<DateTime::DayOfYearSet::DayOfYear> dayVector3 = {DateTime::DayOfYearSet::DayOfYear(12, 12), DateTime::DayOfYearSet::DayOfYear(11, 11), DateTime::DayOfYearSet::DayOfYear(10, 10), DateTime::DayOfYearSet::DayOfYear(9, 9), DateTime::DayOfYearSet::DayOfYear(8, 8)};
    vector<DateTime::DayOfYearSet::DayOfYear> dayVector4 = {DateTime::DayOfYearSet::DayOfYear(1, 2), DateTime::DayOfYearSet::DayOfYear(2, 3), DateTime::DayOfYearSet::DayOfYear(4, 5), DateTime::DayOfYearSet::DayOfYear(6, 7)};
    DateTime::DayOfYearSet daySet(dayVector);
    DateTime::DayOfYearSet daySet1(dayVector1);
    DateTime::DayOfYearSet daySet2(dayVector2);
    DateTime::DayOfYearSet daySet3(dayVector3);
    DateTime::DayOfYearSet daySet4(dayVector4);
    cout << daySet;

    cout << (dayofyear == dof1) << endl;
    cout << (daySet == daySet1) << endl;
    cout << (daySet == daySet2) << endl;
    cout << (daySet == daySet3) << endl;
    cout << (daySet == daySet4) << endl;

    return 0;
}