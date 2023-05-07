public class Circle implements GeometricObject {
    protected double radius;

    public Circle() {
        radius = 0 ;
    }

    public Circle(double radius) {
        this.radius = radius;
    }

    @Override
    public double getArea() {
        return radius * radius * 3.14;
    }

    @Override
    public double getPerimeter() {
        return 2 * 3.14 * radius;
    }

}