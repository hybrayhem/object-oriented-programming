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

        private:
            int month;
            int day;

            int isvalidDate();
        };

        DayOfYearSet();
        DayOfYearSet(int size);
        DayOfYearSet(const std::vector<DayOfYear> dayOfYears);
        ~DayOfYearSet();

        int getCapacity() const { return capacity; }
        int getUsed() const { return used; }

    private:
        DayOfYear *set;
        int capacity;
        int used;
    };
}