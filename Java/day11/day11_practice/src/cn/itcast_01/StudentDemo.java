package cn.itcast_01;

public class StudentDemo {
	public static void main(String[] args) {
		Student s1 = new Student("liming", 19);
		s1.show();
		
		Student s2 = new Student();
		s2.setAge(19);
		s2.setName("lihua");
		s2.show();
	}
}
