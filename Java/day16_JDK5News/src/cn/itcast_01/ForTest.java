package cn.itcast_01;

import java.util.ArrayList;

public class ForTest {
	public static void main(String[] args) {
		int[] intArr = { 1, 2, 3, 4, 5 };
		for (int i : intArr) {
			System.out.println(i);
		}
		System.out.println("---------");

		String[] strArr = { "a1", "b2", "c3" };
		for (String s : strArr) {
			System.out.println(s);
		}
		System.out.println("---------");
		
		ArrayList<String> als = new ArrayList<String>();
		als.add("hello");
		als.add("world");
		als.add("java");
		for (String s : als) {
			System.out.println(s);
		}
	}
}
