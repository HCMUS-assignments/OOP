

import java.util.*;

public class test {

    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter 2 identical strings:");
    String str1 = sc.nextLine();
    String str2 = sc.nextLine();
    System.out.println(str1 == str2);
    System.out.println(str1.equals(str2));
}
}

