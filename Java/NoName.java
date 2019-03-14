class Student {
	public void show() {
		System.out.println("i love study");
	}
}

class StudentDemo {
	public void method(Student s) {
		System.out.println("in StudentDemo method:");
		s.show();
	}
}

class NoName {
	public static void main(String[] args) {
		// 带名字的调用
		Student s = new Student();
		s.show();

		// 匿名对象
		new Student().show();

		// 匿名对象做实际参数
		StudentDemo sd = new StudentDemo();
		sd.method(new Student());

		// 再来一个
		new StudentDemo().method(new Student());
	}
}
