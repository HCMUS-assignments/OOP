public class ResizableCircle extends Circle  implements Resizable {
    public ResizableCircle() {
        super();
    }

    @Override
    public void resize(int percent) {
        radius = radius * percent / 100;
    }
}