/*
	定义一个学生类：
		成员变量：name，age
		成员方法：show()
*/

class Student {
	String name;
	private int age;

	// 写一个方法对数据进行校验
	public void setAge(int a) {
		if (a < 0 || a > 120) {
			System.out.println("你给的年龄有问题");
		} else {
			age = a;
		}
	}

	public void show() {
		System.out.print(name + "---" + age);
		System.out.println();
	}
}

class StudentDemo2 {
	public static void main(String[] args) {
		Student s = new Student();
		s.show();

		s.name = "liming";
		// s.age = 19;
		s.setAge(19);
		s.show();

		//s.age = -27;	// 这个数据是不合理的
		s.setAge(-27);
		s.show();
	}
}

