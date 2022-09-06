// arrays class:
// 1. copyOf
// 2. copyOfRange
// 3. toString
// 4. sort
// 5. binarySearch

// class string
// 1. length
// 2. charAt
// 3. compareTo
// 4. concat
// 5. substring
// 6. indexOf
// 7. replace
// 8. equals
// 9. split
// 10. trim

// write a java program (don't use arrays class, just use the primitive array like lab2)
// 1. write a func to remove the first specific element from an array and return true, if the element does not exist in an array return false
// 2. write a func to insert an element a specific position into an array. (after insertion you can replace the last element with the element before) 
// 3. write a func to find the duplicate values of an array of integer values
// 4. write a func to remove the duplicate values of an array of integer values

public class Ex01 {
    public static boolean removeFirstElement(int[] arr, int element) {
        int index = -1;
        for (int i = 0; i< arr.length; i++) {
            if (arr[i] == element) {
                index = i;
                break;
            }
        }
        if (index == -1 ) {
            return false;
        }

        for (int i = index; i< arr.length - 1; i++ ) {
            arr[i] = arr[i+1];
        }
    }
    public static void insertElement(int arr[], int element, int pos) {
        for (int i = arr.length - 1; i > pos; i--) {
            arr[i] = arr[i-1];
        }
        arr[pos] = element;
        }
    public static void findDuplicateArr(int arr[]) {
        for (int i = 0; i < arr.length; i++) {
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[i] == arr[j]) {
                    System.out.println(arr[j]);
                    break;
                }
            }
        }        
    }

    public static void remove duplicateValues(int arr[]) {
        
    }

    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int[] arr2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int[] arr3 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int[] arr4 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int[] arr5 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int[] arr6 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int[] arr7 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int[] arr8 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int[] arr9 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int[] arr10 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int[] arr11 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int[] arr12 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int[] arr13 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int[] arr14 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    }
}