// write a function public static int findMin(int arr[]) to find the minimum value in an array.

import java.util.Scanner;

public class Ex02 {
    public static int findMin(int arr[]) {
        int min = arr[0] ;
        for (int value : arr) {
            if (value <min) {
                min = value;
            }
        }
        return min;
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
        System.out.println("The minimum value in the array is: " + findMin(arr));
    }
}