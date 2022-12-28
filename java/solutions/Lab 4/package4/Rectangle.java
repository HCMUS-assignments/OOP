package package4;

public class Rectangle {
    private float width;
    private float length;

    public Rectangle() {
        this.width = 1.0f;
        this.length = 1.0f;
    }

    public Rectangle(float w, float l) {
        this.width = w;
        this.length = l;
    }

    public float getWidth() {
        return this.width;
    }

    public float getLength() {
        return this.length;
    }

    public float getArea() {
        return this.width*this.length;
    }

    public float getPerimeter() {
        return (this.width + this.length) * 2;
    }

    public void setWidth(float w) {
        this.width = w;
    }

    public void setLength(float l) {
        this.length = l;
    }

    public String toString() {
        return "Rectangle [width: " + this.width + ", length: " + this.length + "]";
    }
}