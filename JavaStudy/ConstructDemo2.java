class Student {
	private String name;
	private int age;

	public Student() {
		System.out.println("Student的无参构造");
	}

	public Student(String name) {
		this.name = name;
	}

	public Student(int age) {
		this.age = age;
	}

	public Student(String name, int age) {
		this.name = name;
		this.age = age;
	}

	public void show() {
		System.out.println(this.name + "," + this.age);
	}
}

class ConstructDemo2 {
	public static void main(String[] args) {
		Student s = new Student();	// 系统提供了一个默认的构造方法
		s.show();

		Student s2 = new Student("liming");
		s2.show();

		Student s3 = new Student(17);
		s3.show();

		Student s4 = new Student("xiaohong", 16);
		s4.show();
	}
}
