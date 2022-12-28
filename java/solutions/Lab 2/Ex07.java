// write a func to square all the elements of an array

import java.util.Scanner;

public class Ex07 {
    public static void squareAll(int arr[]) {
        for (int i=0; i<arr.length; i++) {
            arr[i] = arr[i] * arr[i];
        }
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
        squareAll(arr);
        for (int i=0; i<n; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}