// Write a function to find the minimum between three numbers

import java.util.Scanner;

public class Exercise06 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter the first number: ");
        int first = input.nextInt();
        System.out.println("Enter the second number: ");
        int second = input.nextInt();
        System.out.println("Enter the third number: ");
        int third = input.nextInt();
        System.out.println("The minimum is " + min(first, second, third));
    }
    
    public static int min(int a, int b, int c) {
        return Math.min(Math.min(a, b), c);
    }
}