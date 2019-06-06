package Chapter10;

/**
 * 10.4
 */
public class MyPoint {
    private double x;
    private double y;

    public double getY() {
        return y;
    }

    public void setY(double y) {
        this.y = y;
    }

    public double getX() {
        return x;
    }

    public void setX(double x) {
        this.x = x;
    }

    public MyPoint() {
        x = y = 0;
    }

    public MyPoint(double x, double y) {
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

    public double distance(double x, double y) {
        return this.distance(new MyPoint(x, y));
    }

    public static void main(String[] args) {
        MyPoint p1 = new MyPoint(); // 0, 0
        MyPoint p2 = new MyPoint(10, 30.5); // 10, 30.5
        System.out.println(p1.distance(p2));
    }
}
