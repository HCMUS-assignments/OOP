// Write a function to count number of digits in a number.

import java.util.Scanner;

public class Exercise11 {
    public static int countDigits(int n) {
        int count = 0;
        int temp = n;
        while (temp != 0) {
            temp /= 10;
            count++;
        }
        return n == 0 ? 1 : count;
    }
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter n: ");
        int n = input.nextInt();
        System.out.println("Number of digits: " + countDigits(n));
    }
}