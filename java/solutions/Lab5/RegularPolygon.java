
import java.lang.*;
import java.util.*;

public class RegularPolygon {
    // attributes
    private String name;
    private int edgeAmount;
    private double edgeLength;

    // constructors
    public RegularPolygon() {
        this("", 3, 1);
    }

    public RegularPolygon(String name, int edgeAmount, double edgeLength) {
        this.name = name;
        this.edgeAmount = edgeAmount;
        this.edgeLength = edgeLength;
    }

    public RegularPolygon(String name, int edgeAmount) {
        this(name, edgeAmount, 1);
    }

    public RegularPolygon(RegularPolygon another) {
        this.name = another.name;
        this.edgeAmount = another.edgeAmount;
        this.edgeLength = another.edgeLength;
    }

    // methods
    public String getName() {
        return name;
    }

    public int getEdgeAmount() {
        return edgeAmount;
    }

    public double getEdgeLength() {
        return edgeLength;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setEdgeAmount(int num ) {
        this.edgeAmount = num;
    }

    public void setEdgeLength(double len) {
        this.edgeLength = len;
    }

    public String getPolygon() {
        switch (edgeAmount) {
            case 3:
                return "Triangle";
            case 4:
                return "Quadrangle";
            case 5:
                return "Pentagon";
            case 6:
                return "Hexagon";
            default:
                return "Polygon has the number of edges greater than 6";
        }
    }

    public double getPerimeter() {
        return edgeLength * edgeAmount;
    }

    public double getArea() {
        double a;
        switch(edgeAmount) {
            case 3:
                a = 0.433;
                break;
            case 4:
                a = 1;
                break;
            case 5:
                a = 1.72;
                break;
            case 6:
                a = 2.595;
                break;
            default:
                return -1;
        }
        return edgeLength * edgeLength * a;
    }

    @Override
    public String toString() {
        return name + " - " + getPolygon() + " - " + getArea() ;
    }
}