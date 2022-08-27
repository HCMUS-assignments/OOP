// write a function to count how many specific elements in an array

import java.util.Scanner;

public class Ex04 {
    public  static int count(int arr[], int x) {
        int count = 0;
        for (int value : arr) {
            if (value == x) {
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
        System.out.println("Enter the element to count: ");
        int x = sc.nextInt();
        System.out.println("The number of " + x + " in the array is: " + count(arr, x));
    }
}