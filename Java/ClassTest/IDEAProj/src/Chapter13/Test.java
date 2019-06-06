package Chapter13;

class Circle {
    private double r = 0;

    public Circle(double r) {
        this.r = r;
    }

    public void setR(double r) {
        this.r = r;
    }

    public double getR() {
        return r;
    }
}

class ComparableCircle extends Circle implements Comparable<Circle> {

    public ComparableCircle(double r) {
        super(r);
    }

    @Override
    public int compareTo(Circle o) {
        return (int) (this.getR() - o.getR());
    }
}

public class Test {
    public static void main(String[] args) {
        Circle c1 = new ComparableCircle(1.1);
        Circle c2 = new ComparableCircle(1.2);
        //System.out.println(c1.compareTo(c2));
    }
}
