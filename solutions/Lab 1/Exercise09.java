/* Write a function that displays the Hailstone sequence:
• With some positive number (n > 0):
1. If n is an even number, divide by 2.
2. If n is an odd number, multiply it by 3 and add 1.
3. Repeat two steps above until n equals 1. */

import java.util.Scanner;

public class Exercise09 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter n: ");
        int n = input.nextInt();
        System.out.println("Hailstone sequence: ");
        while (n != 1) {
            if (n % 2 == 0) {
                n /= 2;
            } else {
                n = n * 3 + 1;
            }
            System.out.println(n);
        }
    }
}