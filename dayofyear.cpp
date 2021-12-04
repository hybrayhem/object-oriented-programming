#include "dayofyear.h"

// secure cin function that gets the selection for menu with a bullet-proof error handling
int get_selection(const std::string msg, int lower, int upper) {
    int flag = 0;
    int selection = 0;

    while (!flag) {
        if (msg[0] != '\0') std::cout << msg;
        std::cin >> selection;
        std::cin.ignore(80, '\n'); // remove unnecessary characters
        if (selection < lower || selection > upper) {
            std::cout << "Invalid!" << std::endl;
            continue;
        }
        flag = 1;
    }
    return selection;
}

namespace DateTime {
    DayOfYearSet::DayOfYearSet() : capacity(20), used(0) {
        set = new DayOfYear[capacity];
    }

    DayOfYearSet::DayOfYearSet(int size) : capacity(size), used(0) {
        set = new DayOfYear[capacity];
    }

    DayOfYearSet::DayOfYearSet(std::vector<DayOfYear> dayOfYears) : capacity(dayOfYears.capacity()), used(dayOfYears.size()) {
        set = new DayOfYear[capacity];
        for (int i = 0; i < used; i++) {
            set[i] = dayOfYears[i];
        }
    }

    DayOfYearSet::~DayOfYearSet() {
        // delete set;
    }

    /* -------------------------------------------------------------------------- */
    /*                          DayOfYear Implemantation                          */
    /* -------------------------------------------------------------------------- */
    DayOfYearSet::DayOfYear::DayOfYear(int monthValue, int dayValue) : month(monthValue), day(dayValue) {
        if (isvalidDate() == -1) exit(1);
    }

    DayOfYearSet::DayOfYear::DayOfYear(int monthValue) : month(monthValue), day(1) {
        if (isvalidDate() == -1) exit(1);
    }

    DayOfYearSet::DayOfYear::DayOfYear() : month(1), day(1) {
        /* Body intentionally left empty */
    }

    int DayOfYearSet::DayOfYear::isvalidDate() {

        if ((month < 1) || (month > 12)) {
            std::cout << "Invalid month value!\n";
            return -1;
        }

        if ((day < 1) || (day > 31)) {
            std::cout << "Invalid day value!\n";
            return -1;
        }
        return 1;
    }

    void DayOfYearSet::DayOfYear::input() {
        month = get_selection("Month: ", 1, 12);
        day = get_selection("Day: ", 1, 30);
    }

    void DayOfYearSet::DayOfYear::output() const {

        switch (month) {

        case 1:
            std::cout << "January ";
            break;
        case 2:
            std::cout << "February ";
            break;
        case 3:
            std::cout << "March ";
            break;
        case 4:
            std::cout << "April ";
            break;
        case 5:
            std::cout << "May ";
            break;
        case 6:
            std::cout << "June ";
            break;
        case 7:
            std::cout << "July ";
            break;
        case 8:
            std::cout << "August ";
            break;
        case 9:
            std::cout << "September ";
            break;
        case 10:
            std::cout << "October ";
            break;
        case 11:
            std::cout << "November ";
            break;
        case 12:
            std::cout << "December ";
            break;
        default:
            std::cout << "Invalid month in date.";
        }

        std::cout << day << std::endl;
    }
    
}