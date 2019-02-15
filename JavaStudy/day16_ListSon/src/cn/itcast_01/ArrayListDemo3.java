package cn.itcast_01;

import java.util.ArrayList;
import java.util.Iterator;

/*
 * 去除集合中自定义对象的重复值（对象的成员变量值都相同）
 */
public class ArrayListDemo3 {
	public static void main(String[] args) {
		ArrayList arr = new ArrayList();
		ArrayList newArr = new ArrayList();

		Student s1 = new Student("a1", 11);
		Student s2 = new Student("a2", 22);
		Student s3 = new Student("a3", 33);
		Student s4 = new Student("a4", 22);
		Student s5 = new Student("a1", 11);
		Student s6 = new Student("a1", 13);

		arr.add(s1);
		arr.add(s2);
		arr.add(s3);
		arr.add(s4);
		arr.add(s5);
		arr.add(s6);

		Iterator it = arr.iterator();

		while (it.hasNext()) {
			Student s = (Student) it.next();

			if (!newArr.contains(s)) {
				newArr.add(s);
			}
		}

		for (int i = 0; i < newArr.size(); i++) {
			Student s = (Student) newArr.get(i);
			System.out.println(s);
		}

	}
}
