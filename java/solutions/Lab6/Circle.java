import java.lang.*;

public class Circle {
    // attributes
    protected double radius = 1.0;
    protected String color = "red";

    // constructors and methods
    public Circle() {

    }

    public Circle(double radius) {
        this.radius = radius;
    }

    public Circle (double radius, String color) {
        this.radius = radius;
        this.color = color;
    }

    public double getRadius () {
        return radius;
    }

    public String getColor () {
        return color;
    }

    public void setRadius (double radius) {
        this.radius = radius;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public double getArea() {
        return radius*radius*3.14;
    }

    @Override
    public String toString() {
        return "Circle" + " - color: " + color + " - Area: " + getArea();
    }

}