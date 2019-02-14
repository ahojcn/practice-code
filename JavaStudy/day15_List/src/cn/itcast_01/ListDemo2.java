package cn.itcast_01;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class ListDemo2 {
	public static void main(String[] args) {
		List list = new ArrayList();
		
		Student s1 = new Student("a1", 11);
		Student s2 = new Student("a2", 22);
		Student s3 = new Student("a3", 33);
		
		list.add(s1);
		list.add(s2);
		list.add(s3);
		
		Iterator it = list.iterator();
		
		while (it.hasNext()) {
			Student s = (Student)it.next();
			System.out.println(s);
		}
	}
}
