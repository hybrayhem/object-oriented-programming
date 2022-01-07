package DateTime;

import java.util.ArrayList;

public class DayOfYearSet implements Cloneable {
    private int id;
    private static int count = 0;
    static final String[] monthNames = { "January", "February", "March", "April", "May", "June", "July", "August",
            "September", "October", "November", "December" };

    private DayOfYear[] set;
    private int capacity = 20;
    private int used = 0;

    public int getID() {
        return id;
    }

    public static int getTotalNumberOfObjects() {
        return count;
    }

    public DayOfYearSet() {
        set = new DayOfYear[this.capacity];
        id = ++count;
    }

    public DayOfYearSet(int size) {
        this.capacity = size;
        set = new DayOfYear[this.capacity];
        id = ++count;
    }

    public DayOfYearSet(ArrayList<DayOfYear> dList) {
        used = dList.size();
        capacity = used * 2;
        set = new DayOfYear[capacity];
        for (int i = 0; i < used; i++) {
            set[i] = new DayOfYear(dList.get(i).month, dList.get(i).day);
        }

        // for (int i = 0; i < used; i++) {
        // add(dList.get(i));
        // }

        id = ++count;
    }

    @Override
    protected DayOfYearSet clone() throws CloneNotSupportedException {
        DayOfYearSet copy = new DayOfYearSet(this.capacity);
        copy.used = this.used;
        for (int i = 0; i < used; i++) {
            copy.set[i] = this.set[i];
        }
        return copy;
    }

    // @Override
    // @Deprecated
    // protected void finalize() throws Throwable {
    // count--;
    // }

    public void add(final DayOfYear dayOfYear) {
        if (used >= capacity) {
            DayOfYear[] temp = new DayOfYear[capacity];
            temp = set;

            capacity *= 2;
            set = new DayOfYear[capacity];
            for (int i = 0; i < used; i++)
                set[i] = temp[i];
        }
        set[used] = dayOfYear;
        used++;
        // System.out.println("used: "+this.used);
    }

    public void remove(int index) {
        if (index < used) {
            for (int i = index; i < used; i++)
                set[i] = set[i + 1];
            used--;
        } else
            System.out.printf("Invalid index to remove: %d\n", index);
    }

    public int size() {
        return used;
    }

    public DayOfYearSet union(final DayOfYearSet dSet) {
        DayOfYearSet unionSet = new DayOfYearSet(capacity + dSet.capacity);

        for (int i = 0; i < used; i++) {
            unionSet.add(set[i]);
        }

        for (int j = 0; j < dSet.used; j++) { // add elements from second set,
            if (!unionSet.contains(dSet.set[j])) { // no duplicate
                unionSet.add(dSet.set[j]);
            }
        }

        return unionSet;
    }

    public DayOfYearSet difference(final DayOfYearSet dSet) {
        DayOfYearSet differenceSet = new DayOfYearSet(capacity);
        for (int i = 0; i < used; i++) {
            if (!dSet.contains(set[i])) {
                differenceSet.add(set[i]);
            }
        }

        return differenceSet;
    }

    public DayOfYearSet intersection(final DayOfYearSet dSet) {
        DayOfYearSet intersectionSet = new DayOfYearSet(capacity);
        for (int i = 0; i < used; i++) {
            if (dSet.contains(set[i])) {
                intersectionSet.add(set[i]);
            }
        }

        return intersectionSet;
    }

    public DayOfYearSet complement() {
        DayOfYearSet complementSet = new DayOfYearSet(capacity);
        for (var i = 1; i < 12; i++) {
            for (var j = 1; j < 30; j++) {
                var dayOfYear = new DayOfYear(i, j);
                if (!contains(dayOfYear))
                    complementSet.add(dayOfYear);
            }
        }

        return complementSet;
    }

    private boolean contains(final DayOfYear dayOfYear) {
        for (int i = 0; i < used; i++) {
            if (set[i] == dayOfYear)
                return true;
        }
        return false;
    }

    @Override
    public String toString() {
        String dString;
        // System.out.println("dayofyearset.tostring");
        dString = String.format("\nSet ID: %d\n[", id);
        for (int i = 0; i < used; i++) {
            dString += String.format("%d. %s", i + 1, set[i].toString());
            if (i != used - 1)
                dString += "\n ";
            // System.out.println("dString: " + dString + "," + set[i].toString());
        }
        dString += "]\n";
        return dString;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null || getClass() != obj.getClass())
            return false;
        DayOfYearSet dayOfYearSet = (DayOfYearSet) obj;

        if (used == dayOfYearSet.used) {
            for (int i = 0; i < used; i++) {
                if (!contains(dayOfYearSet.set[i]))
                    return false;
            }
        } else
            return false;

        return true;
    }

    public static class DayOfYear {
        private int month = 1;
        private int day = 1;

        public DayOfYear(int month, int day) {
            if (isValidDate(month, day)) {
                this.month = month;
                this.day = day;
            }
        }

        public DayOfYear(int month) {
            if (isValidDate(month, this.day))
                this.month = month;
        }

        public int getMonth() {
            return month;
        }

        public int getDay() {
            return day;
        }

        public void setMonth(int month) {
            if (isValidDate(month, this.day))
                this.month = month;
        }

        public void setDay(int day) {
            if (isValidDate(this.month, day))
                this.day = day;
        }

        private boolean isValidDate(int month, int day) {
            final int[] monthLengths = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
            return (((month >= 1) || (month <= 12)) && ((day >= 1) || (day <= monthLengths[month - 1])));
        }

        @Override
        public String toString() {
            // System.out.println("dayofyear.tostring: " + this.day + " " +
            // DayOfYearSet.monthNames[this.month - 1]);
            return this.day + " " + DayOfYearSet.monthNames[this.month - 1];
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj)
                return true;
            if (obj == null || getClass() != obj.getClass())
                return false;
            DayOfYear dayOfYear = (DayOfYear) obj;
            return (this.day == dayOfYear.day) && (this.month == dayOfYear.month);
        }
    }

}
