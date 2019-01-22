class Student {

	private String name;
	private int age;

	public int getAge() {
		return age;
	}

	public void setAge(int age) {
		this.age = age;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

}

class This {
	public static void main(String[] args) {
		Student s = new Student();
		s.setAge(19);
		s.setName("liming");
		System.out.println(s.getName() + "," + s.getAge());
	}
}