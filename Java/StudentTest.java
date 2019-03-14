class Student {

	private String name;
	private int age;

	public int getAge() {
		return age;
	}

	public void setAge(int a) {
		age = a;
	}

	public String getName() {
		return name;
	}

	public void setName(String n) {
		name = n;
	}

}

class StudentTest {
	public static void main(String[] args) {
		Student s = new Student();
		s.setName("liming");
		s.setAge(19);
		System.out.println(s.getName() + "," + s.getAge());
	}
}