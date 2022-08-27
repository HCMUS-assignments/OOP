// write a func to find the maximum value of an BigDecimal object array

import java.math.BigDecimal;

public class Ex08 {
    public static BigDecimal findMax(BigDecimal arr[]) {
        BigDecimal max = arr[0];
        for (int i=0; i<arr.length; i++) {
            if (arr[i].compareTo(max) > 0) {
                max = arr[i];
            }
        }
        return max;
        }

    public static void main(String[] args) {
        BigDecimal arr[] = {new BigDecimal(1), new BigDecimal(2), new BigDecimal(3), new BigDecimal(4), new BigDecimal(5)};
        System.out.println(findMax(arr));

    }
}