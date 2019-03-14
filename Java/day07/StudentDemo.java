class Student {
	private String name;
	private int age;

	public Student() {
	}

	public Student(String name, int age) {
		this.name = name;
		this.age = age;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getAge() {
		return age;
	}

	public void setAge() {
		this.age = age;
	}

	public void show() {
		System.out.println(name + "," + age);
	}
}

class StudentDemo {
	public static void main(String[] args) {
		Student s = new Student("liming", 19);
		s.show();
	}
}