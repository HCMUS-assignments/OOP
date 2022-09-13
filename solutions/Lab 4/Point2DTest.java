import package4.*;

public class Point2DTest{
    public static void main(String args[]) {
        Point2D p1 = new Point2D();
        Point2D p2 = new Point2D(1.0, 2.0);
        System.out.println("p1: " + p1.getX() + ", " + p1.getY());
        System.out.println("p2: " + p2.getX() + ", " + p2.getY());
    }
}