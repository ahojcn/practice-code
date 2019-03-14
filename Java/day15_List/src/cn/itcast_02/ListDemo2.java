package cn.itcast_02;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.ListIterator;

/*
 * 判断集合中是否有“world”元素，如果有，加入一个“javaee”元素。
 */
public class ListDemo2 {
	public static void main(String[] args) {
		List list = new ArrayList();
		
		list.add("hello");
		list.add("world");
		list.add("java");
		
//		Iterator it = list.iterator();
		//ConcurrentModificationException
//		while (it.hasNext()) {
//			if ("world".equals(it.next())) {
//				list.add("javaee");
//			}
//		}
		
		ListIterator lit = list.listIterator();
		while (lit.hasNext()) {
			if ("world".equals(lit.next())) {
				lit.add("javaee");
			}
		}
		
		System.out.println("list:" + list);
	}
}
