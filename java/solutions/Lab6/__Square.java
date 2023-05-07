public class __Square extends _Rectangle {
    public __Square() {
        super();
    }

    public __Square(double side) {
        super(side, side);
    }

    public __Square(double side, String color, boolean filled) {
        super(side, side, color, filled);
    }

    public double getSide() {
        return super.getWidth();
    }

    public void setSide(double side) {
        super.setWidth(side);
        super.setLength(side);
    }

    @Override
    public void setWidth(double w) {
        width = w;
        length = w;
    }

    @Override
    public void setLength(double len) {
        width = len;
        length = len;
    }

    @Override
    public String toString() {
        return "Square | " + "side: " + width + " - Perimeter: " + getPerimeter() + " - Area: " + getArea() ;
    }
}