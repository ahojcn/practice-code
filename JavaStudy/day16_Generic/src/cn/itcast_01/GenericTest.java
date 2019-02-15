package cn.itcast_01;

import java.util.ArrayList;
import java.util.Iterator;

public class GenericTest {
	public static void main(String[] args) {
		ArrayList<Student> arr = new ArrayList<Student>();
		
		Student s1 = new Student("s1", 11);
		Student s2 = new Student("s2", 22);
		Student s3 = new Student("s3", 33);
		
		arr.add(s1);
		arr.add(s2);
		arr.add(s3);
		
		Iterator<Student> it = arr.iterator();
		
		while (it.hasNext()) {
			System.out.println(it.next());
		}
		
		System.out.println("-------------");
		
		for (int i = 0; i < arr.size(); i++) {
			System.out.println(arr.get(i));
		}
	}
}
