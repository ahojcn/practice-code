package cn.itcast_01;

import java.util.ArrayList;

/*
 * 集合的嵌套遍历
 */
public class ArrayListTest {
	public static void main(String[] args) {
		ArrayList<ArrayList<Student>> school = new ArrayList<ArrayList<Student>>();
		
		ArrayList<Student> class1 = new ArrayList<Student>();
		Student a1 = new Student("a1", 11);
		Student a2 = new Student("a2", 12);
		Student a3 = new Student("a3", 13);
		Student a4 = new Student("a4", 14);
		class1.add(a1);
		class1.add(a2);
		class1.add(a3);
		class1.add(a4);
		school.add(class1);
		
		ArrayList<Student> class2 = new ArrayList<Student>();
		Student b1 = new Student("b1", 21);
		Student b2 = new Student("b2", 22);
		Student b3 = new Student("b3", 23);
		class2.add(b1);
		class2.add(b2);
		class2.add(b3);
		school.add(class2);
		
		// 遍历集合
		for (ArrayList<Student> sch : school) {
			for (Student stu : sch) {
				System.out.println(" " + stu);
			}
			System.out.println("--------------");
		}
	}
}
