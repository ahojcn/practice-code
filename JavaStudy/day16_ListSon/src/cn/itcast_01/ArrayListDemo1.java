package cn.itcast_01;

import java.util.ArrayList;
import java.util.Iterator;

/*
 * 去除 ArrayList 中的重复元素，方法 1 。
 */
public class ArrayListDemo1 {
	public static void main(String[] args) {
		ArrayList oldArr = new ArrayList();
		ArrayList newArr = new ArrayList();

		oldArr.add("hello");
		oldArr.add("world");
		oldArr.add("java");
		oldArr.add("world");
		oldArr.add("java");
		oldArr.add("world");
		oldArr.add("java");
		oldArr.add("world");
		oldArr.add("java");
		
		Iterator it = oldArr.iterator();
		
		while (it.hasNext()) {
			String s = (String) it.next();
			
			if (!newArr.contains(s)) {
				newArr.add(s);
			}
		}
		
		for (int i = 0; i < newArr.size(); i++) {
			String s = (String) newArr.get(i);
			System.out.println(s);
		}
	}
}
