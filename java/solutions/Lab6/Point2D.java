public class Point2D {
    // attributes
    protected float x = 0.0f;
    protected float y = 0.0f;

    // methods and constructors
    public Point2D() {
        // do nothing
    }

    public Point2D(float x, float y) {
        this.x = x;
        this.y = y;
    }

    public float getX() {
        return this.x;
    }

    public float getY() {
        return this.y;
    }

    public void setX(float x) {
        this.x = x;
    }

    public void setY(float y) {
        this.y = y;
    }

    public void setXY(float x, float y) {
        this.x = x;
        this.y = y;
    }

    public float[] getXY() {
        float[] xy = new float[2];
        xy[0] = x;
        xy[1] = y;
        return xy;
    }

    @Override
    public String toString() {
        return "x: " + x + " - y: " + y;
    }
}