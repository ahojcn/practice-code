package cn.itcast_04;

public class StudentDemo {
	public static void main(String[] args) throws CloneNotSupportedException {
		Student s = new Student("liming", 10);
		
		Object obj = s.clone();
		
		Student s2 = (Student)obj;
		
		System.out.println(s2.getName() + "," + s2.getAge());
	}
}
