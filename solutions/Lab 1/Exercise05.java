// Write a function to check whether a year is a leap year or not

import java.util.Scanner;

public class Exercise05 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter the year: ");
        int year = input.nextInt();
        if (isLeapYear(year)) {
            System.out.println("The year " + year + " is a leap year");
        } else {
            System.out.println("The year " + year + " is not a leap year");
        }
    }
    
    public static boolean isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    }
}