package cn.itcast_03;

import java.util.TreeSet;

public class TreeSetDemo1 {
	public static void main(String[] args) {
		TreeSet<Student> ts = new TreeSet<Student>();
		Student s1 = new Student("ahoj", 17);
		Student s2 = new Student("liu", 17);
		Student s3 = new Student("baozi", 20);
		
		ts.add(s1);
		ts.add(s2);
		ts.add(s3);
		
		for (Student s : ts) {
			System.out.println(s);
		}
	}
}
