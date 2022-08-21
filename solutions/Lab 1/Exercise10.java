// Write a function to sum the first digit and the last digit of a number

import java.util.Scanner;

public class Exercise10 {
    public static int sumFirstAndLastDigit(int n) {
        int firstDigit = n % 10;
        int lastDigit = n / 10;
        while (lastDigit > 10) {
            lastDigit /= 10;
        }
        return firstDigit + lastDigit;
    }
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter n: ");
        int n = input.nextInt();
        System.out.println("Sum: " + sumFirstAndLastDigit(n));
    }
}