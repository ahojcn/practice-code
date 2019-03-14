package cn.itcast_01;

import java.util.Scanner;

public class RegexDemo {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("input a qq number > ");
		String qq = sc.nextLine();

		System.out.println(checkQQ(qq));

		sc.close();
	}

	public static boolean checkQQ(String qq) {
//		return qq.matches("[1-9][0-9]{4,14}");
		return qq.matches("[1-9]\\d{4,14}");
	}
}
