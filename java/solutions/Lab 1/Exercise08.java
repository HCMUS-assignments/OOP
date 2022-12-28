// Write functions to calculate the below formulas with n is provided by user (each formula is one 
// function):

import java.util.Scanner;

public class Exercise08 {
    // S = 1 + 2 + 3 +... + n
    public static int sum(int n) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += i;
        }
        return sum;
    }

    // P = 1 * 2 * 3 *... * n
    public static int product(int n) {
        int product = 1;
        for (int i = 1; i <= n; i++) {
            product *= i;
        }
        return product;
    }

    // S = 1 +2^1 + 2^2 + 2^3 +... + 2^n
    public static int power(int n) {
        int power = 0;
        for (int i = 1; i <= n; i++) {
            power += Math.pow(2, i);
        }
        return power;
    }

    // S = 1/2 + 1/4 + 1/8 +... + 1/2^n
    public static double inverse(int n) {
        double inverse = 0;
        for (int i = 1; i <= n; i++) {
            inverse += 1.0 / Math.pow(2, i);
        }
        return inverse;
    }

    // S = 1^2 + 2^2 + 3^2 +... + n^2
    public static int square(int n) {
        int square = 0;
        for (int i = 1; i <= n; i++) {
            square += Math.pow(i, 2);
        }
        return square;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter n: ");
        int n = input.nextInt();
        System.out.println("Sum: " + sum(n));
        System.out.println("Product: " + product(n));
        System.out.println("Power: " + power(n));
        System.out.println("Inverse: " + inverse(n));
        System.out.println("Square: " + square(n));
    }
}

