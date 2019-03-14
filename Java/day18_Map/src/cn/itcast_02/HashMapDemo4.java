package cn.itcast_02;

import java.util.HashMap;
import java.util.Set;

/*
 * HashMap<Student,String>
 */
public class HashMapDemo4 {
	public static void main(String[] args) {
		HashMap<Student, String> hm = new HashMap<Student, String>();
		
		Student s1 = new Student("西施", 27);
		Student s2 = new Student("貂蝉", 22);
		Student s3 = new Student("杨玉环", 25);
		Student s4 = new Student("王昭君", 30);
		Student s5 = new Student("杨玉环", 25);	// ooo
		
		hm.put(s1, "8888");
		hm.put(s2, "6666");
		hm.put(s4, "7777");
		hm.put(s3, "5555");
		hm.put(s5, "9999");
		
		Set<Student> set = hm.keySet();
		
		for (Student key : set) {
			String val = hm.get(key);
			System.out.println(key + " ... " + val);
		}
	}
}
