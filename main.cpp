#include "dayofyear.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main() {
    DateTime::DayOfYearSet::DayOfYear dayofyear(1, 1);

    cout << dayofyear.getDay();
    cout << dayofyear.getMonthNumber();
    dayofyear.input();
    dayofyear.output();
    
    return 0;
}