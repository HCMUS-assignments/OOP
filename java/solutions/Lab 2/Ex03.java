// write a function to sum all even numbers in a array

import java.util.Scanner;

public class Ex03 {
    public static int sumEven(int arr[]) {
        int sum = 0;
        for (int value: arr ) {
            if (value % 2 == 0) {
                sum += value;
            }
        }
        return sum;
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
        System.out.println("The sum of even numbers in the array is: " + sumEven(arr));
    }
}