package Chapter10;

public class MyPoint {
    private int x;
    private int y;

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }

    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public MyPoint() {
        this.x = this.y = 0;
    }

    public MyPoint(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public MyPoint(MyPoint p) {
        this.x = p.x;
        this.y = p.y;
    }

    private double distance(MyPoint p) {
        return Math.sqrt(Math.pow(Math.abs(this.x - p.x), 2)
                + Math.pow(Math.abs(this.y - p.y), 2));
    }

    public static double distance(MyPoint p1, MyPoint p2) {
        return p1.distance(p2);
    }

    public static void main(String[] args) {
        MyPoint p1 = new MyPoint(-20, 20);
        MyPoint p2 = new MyPoint(20, -10);
        System.out.println(p1.distance(p2));
        System.out.println(MyPoint.distance(p1,p2));
    }
}
