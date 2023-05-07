public class _Rectangle extends Shape {
    protected double width = 1.0;
    protected double length = 1.0;

    // methods and constructors
    public _Rectangle() {
        super();
        // do nothing
    }

    public _Rectangle(double w, double len) {
        this.width = w;
        this.length = len;
    }

    public _Rectangle(double w, double len, String color, boolean filled) {
        super(color, filled);
        this.width = w;
        this.length = len;
    }

    public double getWidth() {
        return this.width;
    }

    public double getLength() {
        return this.length;
    }

    public void setWidth(double w) {
        this.width = w;
    }

    public void setLength(double len) {
        this.length = len;
    }

    public double getArea() {
        return this.width * this.length;
    }

    public double getPerimeter() {
        return (width + length) * 2;
    }

    @Override
    public String toString() {
        return "Rectangle | " + super.toString() + " - Width: " + width + " - Length: " + length + " - Perimeter: " + getPerimeter() + " - Area: " + getArea(); 
    }


}