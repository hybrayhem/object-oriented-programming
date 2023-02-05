#include "dayofyear.h"

namespace DateTime {
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

    /* -------------------------------------------------------------------------- */
    /*                          DayOfYearSet Implemantation                          */
    /* -------------------------------------------------------------------------- */
    DayOfYearSet::DayOfYearSet() : capacity(20), used(0) {
        set = new DayOfYear[capacity];
        id = ++totalObject;
    }

    DayOfYearSet::DayOfYearSet(int size) : capacity(size), used(0) {
        set = new DayOfYear[capacity];
        id = ++totalObject;
    }

    DayOfYearSet::DayOfYearSet(std::vector<DayOfYear> dayOfYears) : capacity(dayOfYears.capacity()), used(dayOfYears.size()) {
        set = new DayOfYear[capacity];
        for (int i = 0; i < used; i++) {
            set[i] = dayOfYears[i];
        }
        id = ++totalObject;
    }

    DayOfYearSet::DayOfYearSet(const DayOfYearSet &dayOfYears) : capacity(dayOfYears.getCapacity()), used(dayOfYears.getUsed()) {
        set = new DayOfYear[capacity];
        for (int i = 0; i < used; i++)
            set[i] = dayOfYears.set[i];
        id = ++totalObject;
    }

    DayOfYearSet::~DayOfYearSet() {
        delete[] set;
        totalObject--;
    }

    int DayOfYearSet::isExists(const DayOfYear &dof) {
        for (int i = 0; i < used; i++) {
            if (set[i] == dof) return i;
        }
        return -1;
    }

    void DayOfYearSet::add(const DayOfYearSet::DayOfYear &dof) {
        if (used >= capacity) {
            // std::cout << "add capacity\n";
            DayOfYear *temp = new DayOfYear[capacity];
            temp = set;

            capacity *= 2;
            set = new DayOfYear[capacity];
            for (int i = 0; i < used; i++)
                set[i] = temp[i];
        }
        set[used] = dof;
        used++;
    }

    void DayOfYearSet::remove(int index) {
        if (index < used) {
            for (int i = index; i < used; i++)
                set[i] = set[i + 1];
            used--;
        } else
            std::cout << "Invalid index to remove: " << index << std::endl;
    }

    int DayOfYearSet::size() {
        return used;
    }

    DayOfYearSet &DayOfYearSet::operator=(const DayOfYearSet &dofs) {
        if (capacity != dofs.capacity) {
            delete[] set;
            set = new DayOfYear[dofs.capacity];
        }
        capacity = dofs.capacity;
        used = dofs.used;
        for (int i = 0; i < used; i++)
            set[i] = dofs.set[i];

        return *this;
    }

    std::ostream &operator<<(std::ostream &outs, const DayOfYearSet &dofs) {
        outs << std::endl
             << "Set ID: " << dofs.id << std::endl;
        for (int i = 0; i < dofs.getUsed(); i++) {
            outs << i + 1 << ". " << dofs.set[i] << std::endl;
        }
        outs << std::endl;
        return outs;
    }

    std::ofstream &operator<<(std::ofstream &outs, const DayOfYearSet &dofs) {
        outs << std::endl
             << "Set ID: " << dofs.id << std::endl;
        for (int i = 0; i < dofs.getUsed(); i++) {
            outs << i + 1 << ". " << dofs.set[i] << std::endl;
        }
        outs << std::endl;
        return outs;
    }

    bool DayOfYearSet::operator==(const DayOfYearSet &dofs) {
        if (used == dofs.used) {
            for (int i = 0; i < used; i++) {
                if (isExists(dofs.set[i]) == -1) return 0;
            }
        } else
            return 0;

        return 1;
    }

    bool DayOfYearSet::operator!=(const DayOfYearSet &dofs) {
        if (used == dofs.used) {
            for (int i = 0; i < used; i++) {
                if (isExists(dofs.set[i]) == -1) return 1;
            }
        } else
            return 1;

        return 0;
    }

    DayOfYearSet::DayOfYear &DayOfYearSet::operator[](int index) {
        if (index >= used) {
            std::cout << "Illegal index in DayOfYearSet." << std::endl;
            exit(0);
        }

        return set[index];
    }

    DayOfYearSet DayOfYearSet::operator+(const DayOfYearSet &dofs) {

        DayOfYearSet unionSet(capacity + dofs.capacity);
        int i;
        for (i = 0; i < used; i++) {
            // unionSet.set[i] = set[i];
            unionSet.add(set[i]);
            // unionSet.used++;
        }

        for (int j = 0; j < dofs.used; j++) {           // add elements from second set,
            if (unionSet.isExists(dofs.set[j]) == -1) { // no duplicate
                // unionSet.set[i + j] = dofs.set[j];
                unionSet.add(dofs.set[j]);
                // unionSet.used++;
            }
        }

        return unionSet;
    }

    DayOfYearSet DayOfYearSet::operator-(DayOfYearSet &dofs) {

        DayOfYearSet unionSet(capacity);
        for (int i = 0; i < used; i++) {
            if (dofs.isExists(set[i]) == -1) {
                unionSet.add(set[i]);
                // unionSet.used++;
            }
        }

        return unionSet;
    }

    DayOfYearSet DayOfYearSet::operator^(const DayOfYearSet &dofs) {

        DayOfYearSet unionSet(capacity);
        for (int i = 0; i < used; i++) {
            if (dofs.isExists(set[i]) != -1) {
                unionSet.add(set[i]);
                // unionSet.used++;
            }
        }

        return unionSet;
    }

    DayOfYearSet DayOfYearSet::operator!() {

        DayOfYearSet unionSet;
        for (auto i = 1; i < 12; i++) {
            for (decltype(i) j = 1; j < 30; j++) {
                if (isExists(DayOfYear(i, j)) == -1) unionSet.add(DayOfYear(i, j));
            }
        }

        return unionSet;
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

    std::ostream &operator<<(std::ostream &outs, const DayOfYearSet::DayOfYear &dof) {
        const std::string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        // std::cout << dof.getMonthNumber() << " " << dof.getDay();
        outs << months[dof.getMonthNumber() - 1] << " " << dof.getDay();
        return outs;
    }

    std::ofstream &operator<<(std::ofstream &outs, const DayOfYearSet::DayOfYear &dof) {
        const std::string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        // std::cout << dof.getMonthNumber() << " " << dof.getDay();
        outs << months[dof.getMonthNumber() - 1] << " " << dof.getDay();
        return outs;
    }

    bool DayOfYearSet::DayOfYear::operator==(const DayOfYearSet::DayOfYear &dof) {
        return (month == dof.month && day == dof.day);
    }
    bool DayOfYearSet::DayOfYear::operator!=(const DayOfYearSet::DayOfYear &dof) {
        return (month != dof.month || day != dof.day);
    }
}