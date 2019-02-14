package cn.itcast_01;

import java.util.Scanner;

public class ScannerDemo {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		if (sc.hasNextInt()) {
			int x = sc.nextInt();
			System.out.println(x);
		} else {
			System.out.println("input error!");
		}

		sc.close();
	}
}
