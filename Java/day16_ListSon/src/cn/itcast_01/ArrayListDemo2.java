package cn.itcast_01;

import java.util.ArrayList;
import java.util.Iterator;

/*
 * 去除 ArrayList 集合中的重复元素，方法 2 。
 * 不创建新的集合
 */
public class ArrayListDemo2 {
	public static void main(String[] args) {
		ArrayList arr = new ArrayList();

		arr.add("hello");
		arr.add("java");
		arr.add("world");
		arr.add("hello");
		arr.add("java");
		arr.add("world");
		arr.add("hello");
		arr.add("java");
		arr.add("world");

		for (int i = 0; i < arr.size() - 1; i++) {
			for (int j = i + 1; j < arr.size(); j++) {
				if (arr.get(i).equals(arr.get(j))) {
					arr.remove(j);
					j--;
				}
			}
		}

		Iterator it = arr.iterator();
		while (it.hasNext()) {
			String s = (String) it.next();
			System.out.println(s);
		}
	}
}
