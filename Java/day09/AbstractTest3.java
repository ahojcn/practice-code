/*
	学生案例：
	具体事物：基础班学员，就业班学员
	共性：姓名，年龄，班级，学习，吃饭

	分析：
		基础班：
			成员变量：姓名，年龄，班级
			成员方法：学习，吃饭
		就业班：
			成员变量：姓名，年龄，班级
			成员方法：学习，吃饭

		得到一个学员类：
			成员变量：姓名，年龄，班级
			成员方法：学习，吃饭

	实现：
		学员类
		基础班学员
		就业班学员
*/

abstract class Student {
	private String name;
	private int age;
	private String grand;

	public Student() {}

	public Student(String name, int age, String grand) {
		this.name = name;
		this.age = age;
		this.grand = grand;
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

	public String getGrand() {
		return grand;
	}

	public void setGrand(String grand) {
		this.grand = grand;
	}

	public abstract void study();

	public void eat() {
		System.out.println(this.name + " eat food");
	}
}

class BasicStudent extends Student {
	public BasicStudent() {}

	public BasicStudent(String name, int age, String grand) {
		super(name, age, grand);
	}

	public void study() {
		System.out.println("BasicStudent Study JavaSE");
	}
}

class WorkStudent extends Student {
	public WorkStudent() {}

	public WorkStudent(String name, int age, String grand) {
		super(name, age, grand);
	}

	public void study() {
		System.out.println("WorkStudent Study JavaEE");
	}
}

class AbstractTest3 {
	public static void main(String[] args) {
		Student s = new BasicStudent("LiMing", 19, "BasicClass");
		System.out.println(s.getName() + "," + s.getAge() + "," + s.getGrand());
		s.study();
		s.eat();
	}
}