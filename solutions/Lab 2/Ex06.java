// write a func to find the index of an element k in an array, if the element doesn't exist, return -1

import java.util.Scanner;

public class Ex06 {
    public static int findIndex(int arr[], int k) {
        for (int i=0; i<arr.length; i++) {
            if (arr[i] == k) {
                return i;
            }
        }
        return -1;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of the array: ");
        int n = sc.nextInt();
        int arr[] = new int[n];
        System.out.println("Enter the elements of the array: ");
        for (int i=0; i<n; i++) {
            arr[i] = sc.nextInt();
        }
        System.out.println("Enter the element to be searched: ");
        int k = sc.nextInt();
        int index = findIndex(arr, k);
        if (index == -1) {
            System.out.println("Element not found");
        } else {
            System.out.println("Element found at index " + index);
        }
    }
}