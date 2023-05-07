public class Shape {
    // attributes
    protected String color = "red";
    protected boolean filled = true;

    // constructors and methods
    public Shape() {
        // do nothing
    }

    public Shape(String color, boolean filled) {
        this. color = color;
        this.filled = filled;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public boolean isFilled() {
        return filled;
    }

    public void setFilled(boolean filled) {
        this.filled = filled;
    }

    @Override
    public String toString() {
        return "Color: " + color + " - Filled: " + filled;
    }
}