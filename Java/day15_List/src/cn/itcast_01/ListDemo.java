package cn.itcast_01;

import java.util.List;
import java.util.ArrayList;
import java.util.Iterator;

/*
 * List存储字符串并遍历。
 */
public class ListDemo {
	public static void main(String[] args) {
		List list = new ArrayList();
		
		list.add("hello");
		list.add("world");
		list.add("java");
		
		Iterator it = list.iterator();
		
		while (it.hasNext()) {
			String s = (String)it.next();
			System.out.println(s);
		}
	}
}
