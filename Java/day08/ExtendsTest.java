class Person {
	private String name;
	private int age;

	public Person() {}

	public Person(String name, int age) {
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

	public void setAge(int age) {
		this.age = age;
	}
}

class Student extends Person {
	public Student() {}

	public Student(String name, int age) {
		super(name, age);
	}
}

class Teacher extends Person {
	public Teacher() {}
	
	public Teacher(String name, int age) {
		super(name, age);
	}
}

class ExtendsTest3 {
	public static void main(String[] args) {
		Student s = new Student("liming", 17);
		Teacher t = new Teacher("laoli", 33);

		System.out.println("Student: name " + s.getName() + ",age " + s.getAge());
		System.out.println("Teacher: name " + t.getName() + ",age " + t.getAge());
	}
}