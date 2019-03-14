
/*
	老师和学生案例，加入抽烟的额外功能

	具体：从具体到抽象
		老师：姓名，年龄，吃饭，睡觉
		学生：姓名，年龄，吃饭，睡觉

		提取共性：人类
		人类：
			姓名，年龄，
			吃饭()
			睡觉() {}

		抽烟的额外功能，不是人、老师、学生一开始就应该具备的，所以把它定义为接口

		部分老师、学生抽烟。

	实现：从抽象到具体

*/

interface Smoking {
	// 抽烟的抽象方法
	public abstract void smoke();
}

abstract class Person {
	private String name;
    private int age;

    public Person() {}

    public Person(String name, int age) {
            this.name = name;
            this.age = age;
    }

    public abstract void eat();

    public void sleep() {
    	System.out.println(name + " sleeping");
    }
}

class Teacher extends Person {
	public Teacher() {}

	public Teacher(String name, int age) {
		super(name, age);
	}

	public void eat() {
		System.out.println("teacter eat food");
	}
}

class Student extends Person {
	public Student() {}

	public Student(String name, int age) {
		super(name, age);
	}

	public void eat() {
		System.out.println("student eat food");
	}
}

class SmokingTeacher extends Teacher implements Smoking {
	public SmokingTeacher() {}

	public SmokingTeacher(String name, int age) {
		super(name, age);
	}

	public void smoke() {
		System.out.println("teacter smoke");
	}
}

class SmokingStudent extends Student implements Smoking {
	public SmokingStudent() {}

	public SmokingStudent(String name, int age) {
		super(name, age);
	}

	public void smoke() {
		System.out.println("student smoke");
	}
}

class TestDemo2 {
	public static void main(String[] args) {
		SmokingStudent ss = new SmokingStudent("ahoj", 19);
		ss.eat();
		ss.sleep();
		ss.smoke();
	}
}