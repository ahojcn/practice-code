class Student {

	private String name;
	private int age;

	public Student() {
		this.name = "test";
		this.age = -1;
		System.out.println("这是构造方法");
	}
}

class ConstructDemo {
	public static void main(String[] args) {
		Student s = new Student();
		System.out.println(s);	// Student@xxxxx
	}
}