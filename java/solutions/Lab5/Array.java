import java.lang.*;
import java.util.*;

public class Array {
    public static int maxEven(int[] a) {
        int max = 0;
        int count = 0;
        for (int x : a) {
            if (x % 2 == 0 ) { 
                if (count == 0) {
                    max = x;
                    count ++;
                } else if (max < x) {
                    max = x;
                }
            }
        }
        return max;
    }

    public static int minOdd(int [] a) {
        int min = 0;
        int count = 0;
        for (int x : a) {
            if (x % 2 == 1) {
                if (count == 0) {
                    min = x;
                    count ++;
                } else if (min > x) {
                    min = x;
                }
            }
        }
        return min;
    }

    public static int sumMEMO(int [] a) {
        int min = minOdd(a);
        int max = maxEven(a);
        return min + max;
    }

    public static int sumEven(int[] a ) {
        int sum = 0;
        for (int x : a) {
            if (x % 2 == 0) {
                sum += x;
            }
        }
        return sum;
    }

    public static int proOdd(int[] a) {
        int product = 0;
        int count = 0;
        for (int x : a) {
            if (x % 2 == 1) {
                if (count == 0) {
                    product = x;
                    count ++;
                } else {
                    product *= x;
                }
                // System.out.println("odd " + x +  ", product: " + product );
            }
        }
        return product;
    }

    public static int idxFirstEven(int[] a) {
        for (int i = 0; i < a.length; i++) {
            if (a[i] % 2 == 0) {
                return i;
            }
        }
        return -1;
    }

    public static int idxLastOdd(int[] a) {
        for (int i = a.length - 1 ; i >= 0; i--) {
            if (a[i] % 2 == 1) {
                return i;
            }
        }
        return -1;
    }

    public static int[] input(int n) {
        int a[] = new int[n];
        for (int i = 0; i < n; i++) {
            System.out.print("Nhap vao so thu " +  (i+1)  + ": ");
            Scanner sc = new Scanner(System.in);
            a[i] = sc.nextInt();
        }
        return a;
    }

    public static void main(String [] args) {
        System.out.print("Nhap so phan tu cua mang : ");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = input(n);
        System.out.println("Greatest even in array: " + maxEven(a) );
        System.out.println("Smallest odd in array: " + minOdd(a) );
        System.out.println("Sum of greatest even and smallest odd in array: " + sumMEMO(a) );
        System.out.println("Sum of even numbers in array: " + sumEven(a) );
        System.out.println("Product of odd in array: " + proOdd(a) );
        System.out.println("Index of first even in array: " + idxFirstEven(a) );
        System.out.println("Index of last odd in array: " + idxLastOdd(a) );

    }
}