package cn.itcast_02;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;

/*
 * Iterator iterator(); 迭代器，集合的专用遍历方式
 * 
 * Object next(); 获取元素，并移动到下一个元素的位置
 */
public class IteratorDemo {
	public static void main(String[] args) {
		Collection c = new ArrayList();
		
		c.add("hello");
		c.add("world");
		c.add("java");
		
		Iterator it = c.iterator();
		
		while (it.hasNext()) {
			System.out.println(it.next());
		}
	}
}
