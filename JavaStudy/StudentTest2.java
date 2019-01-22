class Student {

	private String name;
	private int age;

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

class StudentTest2 {
	public static void main(String[] args) {
		Student s1 = new Student();
		s1.setName("liming");
		s1.setAge(19);
		System.out.println(s1.getAge() + "," + s1.getName());

		Student s2 = new Student();
		s2.setName("xiaohong");
		s2.setAge(18);
		System.out.println(s2.getAge() + "," + s2.getName());
	}
}