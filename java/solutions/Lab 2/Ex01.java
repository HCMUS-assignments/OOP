// write a function public static int findMax(int arr[]) to find the maximum value in an array.

import java.util.Scanner;

public class Ex01 {
    public static int findMax(int arr[]) {
            int max = arr[0];
            for (int value : arr) {
                if (value > max) {
                    max = value;
                }
            }
            return max;
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
        System.out.println("The maximum value in the array is: " + findMax(arr));
    }
}