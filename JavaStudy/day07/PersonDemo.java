class Person {
	String name;
	int age;
	static String country;	// 国籍

	public Person(String name, int age, String country) {
		this.name = name;
		this.age = age;
		this.country = country;
	}

	public Person(String name, int age) {
		this.name = name;
		this.age = age;
	}

	public void show() {
		System.out.println(name + "," + age + "," + country);
	}
}

class PersonDemo {
	public static void main(String[] args) {
		Person p1 = new Person("xiaoming", 16, "china");
		p1.show();
		Person p2 = new Person("xiaohong", 17, "china");
		//p2.country = "usa";
		p2.show();
		Person p3 = new Person("lihua", 18);
		p3.show();
		Person p4 = new Person("xiongxiong", 19);
		p4.show();
	}
}