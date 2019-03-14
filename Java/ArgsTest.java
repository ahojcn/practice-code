class Student {
	public void show() {
		System.out.println("i love study");
	}
}

class StudentDemo {
	public void method(Student s) {
		s.show();
	}
}

class ArgsTest {
	public static void main(String[] args) {
		StudentDemo sd = new StudentDemo();
		Student s = new Student();
		sd.method(s);
	}
}