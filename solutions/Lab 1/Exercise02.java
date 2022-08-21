import java.util.*;

public class Exercise02 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter height: ");
        double height = sc.nextDouble();
        System.out.print("Enter base: ");
        double base = sc.nextDouble();
        System.out.println("Area of triangle is: " + (height * base) / 2);
    }
}