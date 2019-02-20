package cn.itcast_02;

import java.util.HashMap;
import java.util.Set;

/*
 * HashMap<String,Student>
 */
public class HashMapDemo3 {
	public static void main(String[] args) {
		HashMap<String, Student> hm = new HashMap<String, Student>();

		Student s1 = new Student("s1", 17);
		Student s2 = new Student("s2", 19);
		Student s3 = new Student("s3", 23);

		hm.put("9527", s1);
		hm.put("007", s2);
		hm.put("s7", s3);

		Set<String> set = hm.keySet();

		for (String key : set) {
			Student val = hm.get(key);
			System.out.println(key + "---" + val.getName() + "," + val.getAge());
		}
	}
}
