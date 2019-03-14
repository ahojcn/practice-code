class Student {
	String name;	// null
	int age;	// 0
	String address;	// null

	public void study() {
		System.out.println("学习");
	}

	public void eat() {
		System.out.println("吃饭");
	}

	public void sleep() {
		System.out.println("睡觉");
	}
}

// 学生测试类
class StudentDemo {
	public static void main(String[] args) {
		Student liming = new Student();

		System.out.println(liming.name + "---" + liming.age + "---" + liming.address);

		liming.name = "黎明";
		liming.age = 19;
		liming.address = "西安";
		System.out.println(liming.name + "---" + liming.age + "---" + liming.address);		

		liming.study();
		liming.eat();
		liming.sleep();
	}
}


