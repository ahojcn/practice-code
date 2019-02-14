package cn.itcast_02;

import java.util.ArrayList;
import java.util.List;
import java.util.ListIterator;

public class ListDemo {
	public static void main(String[] args) {
		List list = new ArrayList();
		list.add("hello");
		list.add("world");
		list.add("java");

		ListIterator lit = list.listIterator();

		while (lit.hasNext()) {
			System.out.println(lit.next());
		}

		System.out.println("-----------");

		while (lit.hasPrevious()) {
			System.out.println(lit.previous());
		}
	}
}
