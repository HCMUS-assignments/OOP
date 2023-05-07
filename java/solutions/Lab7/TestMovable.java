import java.lang.*;

public class TestMovable {
    public static void main(String[] args) {
        Movable m = new MovablePoint(0,0,3,5);
        m.moveUp();
        System.out.println(m);

        m = new MovableCircle(0,0,3,5,7);
        m.moveDown();
        System.out.println(m);
    }
}