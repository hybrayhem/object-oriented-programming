package DateTime;

import java.util.ArrayList;

/**
 * Class {@code DayOfYearSet} is a set implementation of the {@code DayOfYear}
 * objects.
 * All items are unique. {@code add} and {@code remove} for modify the set.
 * {@code union}, {@code difference}, {@code intersection} and
 * {@code complement} operates De Morgan's laws.
 * 
 * @author Halil I. ILHAN
 * @version 1.0
 */
public class DayOfYearSet implements Cloneable {
    /** Unique id of the instance */
    private int id;
    private static int count = 0;
    static final String[] monthNames = { "January", "February", "March", "April", "May", "June", "July", "August",
            "September", "October", "November", "December" };
    static final int[] monthLengths = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    /**
     * The array which the items of the DayOfYearSet are stored.
     * The capacity of the DayOfYearSet is the length of this array.
     */
    private DayOfYear[] set;

    /**
     * Default initial capacity.
     */
    private int capacity = 20;

    /**
     * The number of items it contains.
     *
     * @serial
     */
    private int used = 0;

    public int getID() {
        return id;
    }

    public static int getTotalNumberOfObjects() {
        return count;
    }

    /**
     * Constructs an empty set with an initial capacity of twenty.
     */
    public DayOfYearSet() {
        set = new DayOfYear[this.capacity];
        id = ++count;
    }

    /**
     * Constructs an empty set with the specified size.
     *
     * @param size the initial capacity of the set
     */
    public DayOfYearSet(int size) {
        this.capacity = size;
        set = new DayOfYear[this.capacity];
        id = ++count;
    }

    /**
     * Constructs a set containing the elements of the specified ArrayList.
     *
     * @param dList the ArrayList whose elements are to be placed into this set
     */
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

    /**
     * Returns a deep copy of this {@code DayOfYearSet} instance.
     *
     * @return a clone of this {@code DayOfYearSet} instance
     */
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

    /**
     * Adds the specified item to the end of this
     * set. Expands capacity if set is full.
     * 
     * @param dayOfYear item to be inserted
     */
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

    /**
     * Removes the item at the given index. Shift all items one left starting from
     * the specified index.
     *
     * @param index the index of the item to be removed
     */
    public void remove(int index) {
        if (index < used) {
            for (int i = index; i < used; i++)
                set[i] = set[i + 1];
            used--;
        } else
            System.out.printf("Invalid index to remove: %d\n", index);
    }

    /**
     * Returns the number of items in this set.
     *
     * @return the number of items in this set
     */
    public int size() {
        return used;
    }

    /**
     * Returns sum of this and specified set with no duplicate.
     * 
     * @param dSet the set, which the elements of the set are to be added onto this
     * @return sum of this and specified set
     */
    public DayOfYearSet union(final DayOfYearSet dSet) {
        DayOfYearSet unionSet = new DayOfYearSet(capacity + dSet.capacity);

        for (int i = 0; i < used; i++) {
            unionSet.add(set[i]);
        }

        for (int j = 0; j < dSet.used; j++) { // add elements from second set,
            if (unionSet.contains(dSet.set[j]) == false) { // no duplicate
                unionSet.add(dSet.set[j]);
            }
        }

        return unionSet;
    }

    /**
     * Removes elements which is part of the both specified set and this, from this
     * set. And returns the result.
     * 
     * @param dSet the set, which the common elements are to be removed from this
     * @return difference set which {@code this} - {@code dSet}
     */
    public DayOfYearSet difference(final DayOfYearSet dSet) {
        DayOfYearSet differenceSet = new DayOfYearSet(capacity);
        for (int i = 0; i < used; i++) {
            if (dSet.contains(set[i]) == false) {
                differenceSet.add(set[i]);
            }
        }

        return differenceSet;
    }

    /**
     * Returns the set formed by the elements in both sets.
     * 
     * @return intersection set of {@code this} and {@code dSet}
     */
    public DayOfYearSet intersection(final DayOfYearSet dSet) {
        DayOfYearSet intersectionSet = new DayOfYearSet(capacity);
        for (int i = 0; i < used; i++) {
            if (dSet.contains(set[i])) {
                intersectionSet.add(set[i]);
            }
        }

        return intersectionSet;
    }

    /**
     * Returns the set which created by removing elements of this set from the all
     * days of a year.
     * 
     */
    public DayOfYearSet complement() {
        DayOfYearSet complementSet = new DayOfYearSet(capacity);
        for (var i = 1; i <= 12; i++) {
            for (var j = 1; j <= monthLengths[i-1]; j++) {
                var dayOfYear = new DayOfYear(i, j);
                if (this.contains(dayOfYear) == false)
                    complementSet.add(dayOfYear);
            }
        }

        return complementSet;
    }

    /**
     * Returns {@code true} if this set contains the specified element. if not
     * {@code false}
     *
     * @param dayOfYear item whose existence in this set to be chechked
     * @return {@code true} if this set contains the specified element
     */
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

    /**
     * Subclass {@code DayOfYear} is representing a day from a regular
     * year(non-leap).
     */
    public static class DayOfYear {
        /** month index from 1 to 12 */
        private int month = 1;
        /** day number from 1 to 28-31 various on different months */
        private int day = 1;

        /**
         * Constructs a {@code DayOfYear} which showing day with number {@code day} of
         * {@code month}, if date is valid.
         */
        public DayOfYear(int month, int day) {
            if (isValidDate(month, day)) {
                this.month = month;
                this.day = day;
            }
        }

        /**
         * Constructs a {@code DayOfYear} which showing day with initial value number 1
         * of
         * {@code month}, if date is valid.
         */
        public DayOfYear(int month) {
            if (isValidDate(month, this.day))
                this.month = month;
        }

        // getters
        public int getMonth() {
            return month;
        }

        public int getDay() {
            return day;
        }

        // setters
        public void setMonth(int month) {
            if (isValidDate(month, this.day))
                this.month = month;
        }

        public void setDay(int day) {
            if (isValidDate(this.month, day))
                this.day = day;
        }

        /**
         * Validates the day with number {@code day} of {@code month}
         * 
         * @param month month index to be checked
         * @param day   day number to be checked
         */
        private boolean isValidDate(int month, int day) {
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
