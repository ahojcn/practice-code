package cn.itcast_03;

public class StudentDemo {
	public static void main(String[] args) {
		Student s1 = new Student("liming", 19);
		Student s2 = new Student("liming", 19);
		System.out.println(s1 == s2);
		Student s3 = s1;
		System.out.println(s1 == s3);
		
		System.out.println("--------");
		
		System.out.println(s1.equals(s2));	// f
		System.out.println(s1.equals(s1));	// t
		System.out.println(s1.equals(s3));	// t
	}
}
