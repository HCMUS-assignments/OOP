// write a func to find the third largest element in an array

import java.math.BigDecimal;

public class Ex10 {
    public static BigDecimal findThirdLargest(BigDecimal arr[]) {
        BigDecimal max = arr[0];
        BigDecimal secondMax = arr[0];
        BigDecimal thirdMax = arr[0];
        for (int i=0; i<arr.length; i++) {
            if (arr[i].compareTo(max) > 0) {
                thirdMax = secondMax;
                secondMax = max;
                max = arr[i];
            }
            else if (arr[i].compareTo(secondMax) > 0) {
                thirdMax = secondMax;
                secondMax = arr[i];
            }
            else if (arr[i].compareTo(thirdMax) > 0) {
                thirdMax = arr[i];
            }
        }
        return thirdMax;
        }
    public static void main(String[] args) {
        BigDecimal arr[] = {new BigDecimal(1), new BigDecimal(2), new BigDecimal(3), new BigDecimal(4), new BigDecimal(5)};
        System.out.println(findThirdLargest(arr));
    }
}