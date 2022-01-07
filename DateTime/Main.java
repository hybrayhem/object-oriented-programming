package DateTime;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

import DateTime.DayOfYearSet.DayOfYear;

class Main {

    // secure cin function that gets the selection for menu with a bullet-proof
    // error handling
    public static int get_selection(String msg, int lower, int upper) {
        boolean flag = false;
        int selection = 0;

        Scanner scanner = new Scanner(System.in);
        while (!flag) {
            if (!msg.isEmpty())
                System.out.printf("%s", msg);
            selection = scanner.nextInt();
            // System.out.println(scanner.next()); // remove unnecessary characters
            if (selection < lower || selection > upper) {
                System.out.printf("Invalid!\n");
                continue;
            }
            flag = true;
        }
        scanner.close();
        return selection;
    }

    public static void writeSet(final DayOfYearSet DayOfYearSet, String filename) {
        try {
            FileWriter fWriter = new FileWriter(filename);
            fWriter.write(DayOfYearSet.toString());
            fWriter.close();
        } catch (IOException e) {
            System.out.println("An error occurred. Err: " + e.getMessage());
        }
    }

    public static void main(String[] args) {
        // Constructor & Clone Tests
        System.out.printf("\n/* -------------------------------------------------------------------------- */\n"
                + "/*                          Constructor & Clone Tests                         */\n"
                + "/* -------------------------------------------------------------------------- */\n\n");
        DayOfYearSet s1 = new DayOfYearSet(); // default constructor
        DayOfYearSet s2 = new DayOfYearSet(50); // construct by size

        System.out.printf("> Default constructor (empty set)\n %s", s1.toString());
        System.out.printf("> Construct by size (empty set)\n %s", s2.toString());

        System.out.println("\n> Construct by vector");
        DayOfYear d1 = new DayOfYear(1, 2);
        DayOfYear d2 = new DayOfYear(2, 3);
        DayOfYear d3 = new DayOfYear(4, 5);
        DayOfYear d4 = new DayOfYear(6, 7);
        ArrayList<DayOfYear> dArrayList = new ArrayList<>(Arrays.asList(d1, d2, d3, d4));
        DayOfYearSet s3 = new DayOfYearSet(dArrayList);
        System.out.println(s3.toString());

        System.out.println("> Clone set 3 into set 4 (from the set upwards)");
        DayOfYearSet s4 = new DayOfYearSet();
        try {
            s4 = s3.clone();
            System.out.println(s4.toString());
        } catch (Exception e) {
            System.out.println("An error occurred. Err: " + e.getMessage());
        }

        System.out.println("> Total number of objects: " + DayOfYearSet.getTotalNumberOfObjects() + "\n");

        writeSet(s1, "s1.txt");
        writeSet(s2, "s2.txt");
        writeSet(s3, "s3.txt");

        // Function Tests
        System.out.printf("\n/* -------------------------------------------------------------------------- */\n"
                + "/*                               Function Tests                               */\n"
                + "/* -------------------------------------------------------------------------- */\n\n");
        System.out.println("> Add two element to Set 1");
        DayOfYear d5 = new DayOfYear(12, 5);
        DayOfYear d6 = new DayOfYear(2, 3);
        s1.add(d5);
        s1.add(d6);
        System.out.println(s1.toString());

        System.out.println("> Add one element to Set 3");
        DayOfYear d7 = new DayOfYear(12, 5);
        s3.add(d7);
        System.out.println(s3.toString());

        System.out.println("> Remove middle element from Set 3");
        s3.remove(2);
        System.out.println(s3.toString() + "Size = " + s3.size() + "\n");

        System.out.println("> Remove first element from Set 4");
        s4.remove(0);
        System.out.println(s4.toString() + "Size = " + s4.size() + "\n");

        // Set Operation Tests
        System.out.printf("\n/* -------------------------------------------------------------------------- */\n"
                + "/*                             Set Operation Tests                            */\n"
                + "/* -------------------------------------------------------------------------- */\n\n");
        System.out.println("> Set 1 union Set 3 " + s1 + "+" + s3 + "=" + s1.union(s3));
        System.out.println("> Set 3 union Set 4 " + s3 + "+" + s4 + "=" + s3.union(s4));

        System.out.println("> Set 1 difference Set 3 " + s1 + "-" + s3 + "=" + s1.difference(s3));
        System.out.println("> Set 3 difference Set 4 " + s3 + "-" + s4 + "=" + s3.difference(s4));

        System.out.println("> Set 1 intersection Set 3 " + s1 + "^" + s3 + "=" + s1.intersection(s3));
        System.out.println("> Set 3 intersection Set 4 " + s3 + "^" + s4 + "=" + s3.intersection(s4));

        // De Morgan's Tests
        System.out.printf("\n/* -------------------------------------------------------------------------- */\n"
                + "/*                              De Morgan's Tests                             */\n"
                + "/* -------------------------------------------------------------------------- */\n\n");
        DayOfYearSet lSet = (s1.union(s2)).complement();
        DayOfYearSet rSet = (s1.complement()).intersection(s2.complement());
        System.out.println("> !(s1 + s2) == !s1 ^ !s2 " + lSet.equals(rSet));
        // System.out.println("sizes: " + lSet.size() + ", " + rSet.size());

        // Complement Test
        System.out.printf("\n/* -------------------------------------------------------------------------- */\n"
                + "/*                               Complement Test                              */\n"
                + "/* -------------------------------------------------------------------------- */\n\n");
        get_selection("Press 1 to see Complement operation: ", 1, 1);
        System.out.println("> Complement of set 3" + s3.complement().toString());
        // System.out.println("size: " + s3.complement().size() + ", " + s3.size());

    }
}
