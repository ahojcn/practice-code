package cn.itcast_01;

public class StudentTest {
	public static void main(String[] args) {
		Student s1 = new Student();
		System.out.println(s1.hashCode());
		Student s2 = new Student();
		System.out.println(s2.hashCode());
		Student s3 = s1;
		System.out.println(s3.hashCode());
		
		System.out.println(s3.getClass().getName());
	}
}
