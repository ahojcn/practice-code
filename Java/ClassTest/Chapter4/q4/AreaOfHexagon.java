package q4;

import java.util.Scanner;

public class AreaOfHexagon {
	public static void main(String[] args) {
		double s = 0, area = 0;
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the side: ");
		s = sc.nextDouble();
		area = (6 * s * s) / (Math.tan(Math.PI / 6) * 4);
		System.out.printf("The area of the hexagon is %.2f", area);
		sc.close();
	}
}
