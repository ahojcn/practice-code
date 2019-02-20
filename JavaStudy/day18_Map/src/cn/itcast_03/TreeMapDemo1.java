package cn.itcast_03;

import java.util.Comparator;
import java.util.Set;
import java.util.TreeMap;

public class TreeMapDemo1 {
	public static void main(String[] args) {
		TreeMap<Student, String> tm = new TreeMap<Student, String>(new Comparator<Student>() {
			@Override
			public int compare(Student s1, Student s2) {
				int num1 = s1.getAge() - s2.getAge();
				int num2 = num1 == 0 ? s1.getName().compareTo(s2.getName()) : num1;
				return num2;
			}
		});

		Student s1 = new Student("s1", 30);
		Student s2 = new Student("s2", 31);
		Student s3 = new Student("s3", 33);
		Student s8 = new Student("s1", 30);

		tm.put(s1, "111");
		tm.put(s2, "222");
		tm.put(s3, "333");
		tm.put(s8, "888");
		
		Set<Student> set = tm.keySet();

		for (Student key : set) {
			String val = tm.get(key);
			System.out.println(key + "," + val);
		}
	}
}
