// write a function to count how many prime numbers in an array

import java.util.Scanner;
import java.lang.Math;

public class Ex05 {
    public static boolean isPrime(int x) {
        if (x <= 1 ) {
            return false;
        }
        for (int i=2; i<= Math.sqrt(x); i++) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }

    public static int countPrime(int arr[]) {
        int count = 0;
        for (int value : arr) {
            if (isPrime(value)) {
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of elements in the array: ");
        int n = sc.nextInt();

        int arr[] = new int[n];
        System.out.println("Enter the elements of the array: ");
        for (int i=0; i<n; i++) {
            arr[i] = sc.nextInt();
        }
        System.out.println("The number of prime numbers in the array is: " + countPrime(arr));
    }
}