import java.util.Scanner;

class Rectangle {
	private int length;
	private int width;

	public Rectangle() {}

	public void setLength(int length) {
		this.length = length;
	}

	public void setWidth(int width) {
		this.width = width;
	}

	public int getZhouChang() {
		return (length+width)*2;
	}

	public int getArea() {
		return length * width;
	}
}

class RectangleDemo {
	public static void main(String[] args) {
		Rectangle r = new Rectangle();
		Scanner sc = new Scanner(System.in);
		System.out.print("input length:");
		int length = sc.nextInt();
		System.out.print("input width:");
		int width = sc.nextInt();

		r.setLength(length);
		r.setWidth(width);

		System.out.println("周长:" + r.getZhouChang());
		System.out.println("面积:" + r.getArea());
	}
}