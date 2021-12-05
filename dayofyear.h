#include <iostream>
#include <vector>

namespace DateTime {
    int get_selection(const std::string msg, int lower, int upper);


    class DayOfYearSet {
    public:
        int id;
        static int totalObject;
        static int getTotalNumberOfObjects() { return totalObject; };

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
            friend std::ofstream &operator<<(std::ofstream &outs, const DayOfYear &dof);
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

        void add(const DayOfYear &dof);
        void remove(int index);
        int size();

        DayOfYearSet &operator=(const DayOfYearSet &dofs); // copy assignment operator
        friend std::ostream &operator<<(std::ostream &outs, const DayOfYearSet &dofs);
        friend std::ofstream &operator<<(std::ofstream &outs, const DayOfYearSet &dofs);
        bool operator==(const DayOfYearSet &dofs);
        bool operator!=(const DayOfYearSet &dofs);
        DayOfYear &operator[](int index);
        DayOfYearSet operator+(const DayOfYearSet &dofs); // union set
        DayOfYearSet operator-(DayOfYearSet &dofs);       // difference set
        DayOfYearSet operator^(const DayOfYearSet &dofs);       // intersection set
        DayOfYearSet operator!();                         // complement set

    private:
        DayOfYear *set;
        int capacity;
        int used;

        int isExists(const DayOfYear &dof) const;
    };
}