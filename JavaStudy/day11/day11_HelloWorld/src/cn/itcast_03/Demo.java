package cn.itcast_03;

import java.util.Scanner;

public class Demo {
	public static void main(String[] args) {
		System.out.println("Demo");

		String string = new String();
		string = "Hello World!";
		System.out.println(string);
		
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		System.out.println(a);
		sc.close();
	}
}
