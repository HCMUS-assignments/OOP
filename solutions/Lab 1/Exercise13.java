// Write a function to check whether a number is palindrome or not

import java.util.Scanner;

public class Exercise13 {
    public static boolean isPalindrome(int n) {
        int reverse = 0;
        int copy = n;
        while (copy > 0) {
            reverse = reverse * 10 + copy % 10;
            copy /= 10;
        }
        return n == reverse;
    }
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter n: ");
        int n = input.nextInt();
        System.out.println("Palindrome: " + isPalindrome(n));
    }
}