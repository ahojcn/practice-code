package cn.itcast_02;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;

public class IteratorTest {
	public static void main(String[] args) {
		Collection c = new ArrayList();

		Student s1 = new Student("a", 1);
		Student s2 = new Student("ab", 2);
		Student s3 = new Student("abc", 3);
		Student s4 = new Student("abcd", 4);
		Student s5 = new Student("abcde", 5);
		
		c.add(s1);
		c.add(s2);
		c.add(s3);
		c.add(s4);
		c.add(s5);
		
		Iterator it = c.iterator();
		
		while (it.hasNext()) {
			System.out.println(it.next());
		}
	}
}
