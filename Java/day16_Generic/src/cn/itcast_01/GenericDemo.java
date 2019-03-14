package cn.itcast_01;

import java.util.ArrayList;
import java.util.Iterator;

public class GenericDemo {
	public static void main(String[] args) {
		ArrayList<String> arr = new ArrayList<String>();

		arr.add("hello");
		arr.add("java");

		Iterator<String> it = arr.iterator();

		while (it.hasNext()) {
			System.out.println(it.next());
		}
	}
}
