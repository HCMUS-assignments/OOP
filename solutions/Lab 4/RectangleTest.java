import package4.*;

public class RectangleTest {
    public static void main(String args[]) {
        Rectangle rect1 = new Rectangle();
        Rectangle rect2 = new Rectangle(4, 5);

        System.out.println("Rectangle 1 : \n" + rect1.toString());
        System.out.println("Rectangle 2 : \n" + rect2.toString());

        System.out.println("Area: \nRectangle 1: " + rect1.getArea() + "\nRectangle 2: " + rect2.getArea());

        System.out.println("Perimeter: \nRectangle 1: " + rect1.getPerimeter() + "\nRectangle 2: " + rect2.getPerimeter());
        
    }
}