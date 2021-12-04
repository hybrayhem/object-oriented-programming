#include <iostream>
#include <vector>

namespace DateTime {
    class DayOfYearSet {
    public:
        class DayOfYear {

        public:
            DayOfYear(int monthValue, int dayValue);
            DayOfYear(int monthValue);
            DayOfYear();

            void input();
            void output() const;
            int getMonthNumber() const { return month; }
            int getDay() const { return day; }

            // DayOfYear& operator =(const DayOfYear& rightSide);
            friend std::ostream &operator<<(std::ostream &outs, const DayOfYear &dof);
            bool operator==(const DayOfYear &dof);
            bool operator!=(const DayOfYear &dof);

        private:
            int month;
            int day;

            int isvalidDate();
        };

        DayOfYearSet();
        DayOfYearSet(int size);
        DayOfYearSet(const std::vector<DayOfYear> dayOfYears);
        DayOfYearSet(const DayOfYearSet &dofs); // copy constructor
        ~DayOfYearSet();                        // destructor

        int getCapacity() const { return capacity; }
        int getUsed() const { return used; }

        DayOfYearSet &operator=(const DayOfYearSet &rValue); // copy assignment operator
        friend std::ostream &operator<<(std::ostream &outs, const DayOfYearSet &dofs);
        bool operator==(const DayOfYearSet &dofs);
        bool operator!=(const DayOfYearSet &dofs);
        DayOfYear &operator[](int index);

    private:
        DayOfYear *set;
        int capacity;
        int used;

        int isExists(const DayOfYear &dof);
    };
}