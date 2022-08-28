// write a func public static int[] divisibleNumbers(int arr[], int k) to find
// the elements which divisible by k in an array. 

import java.util.ArrayList;

public class Ex09 {
    public static int[] divisibleNumbers(int arr[], int k) {
        ArrayList<Integer> list = new ArrayList<Integer>();
        for (int i=0; i<arr.length; i++) {
            if (arr[i] % k == 0) {
                list.add(arr[i]);
            }
        }
        int[] result = new int[list.size()];
        for (int i=0; i<list.size(); i++) {
            result[i] = list.get(i);
        }
        return result;
    }
    public static void main(String[] args) {
        int arr[] = {1, 2, 3, 4, 5};
        int[] result = divisibleNumbers(arr, 2);
        for (int i=0; i<result.length; i++) {
            System.out.println(result[i]);
        }
    }
}