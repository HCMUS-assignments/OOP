public class _Circle extends Shape {
    protected double radius = 1.0;

    // methods and constructors
    public _Circle() {
        super();
    }

    public _Circle (double radius, String color, boolean filled) {
        super(color, filled);
        this.radius = radius;
    }

    public double getRadius() {
        return radius;
    }

    public void setRadius (double radius) {
        this.radius = radius;
    }

    public double getArea() {
        return radius * radius * 3.14;
    }

    public double getPerimeter() {
        return 2 * 3.14 * radius;
    }

    @Override
    public String toString() {
        return "Circle | " + super.toString() + " - radius: " + radius + " - Perimeter: " + getPerimeter() + " - Area: " + getArea();
    }
}