/*
	猫狗案例，假如跳高的额外功能

	分析：从具体到抽象
		猫：
			姓名，年龄
			吃饭，睡觉
		狗：
			姓名，年龄
			吃饭，睡觉

		由于有共性功能，所以抽取出一个父类。
		动物：
			姓名，年龄
			吃饭();
			睡觉() {}

		猫：继承自动物
		狗：继承自动物

		跳高的额外功能是一个新的扩展功能，定义一个接口
		接口：跳高

		部分猫、部分狗实现跳高。

	实现：从抽象到具体
*/

// 定义跳高接口
interface Jumpping {
	public abstract void jump();
}

abstract class Animal {
	private String name;
	private int age;

	public Animal() {}

	public Animal(String name, int age) {
		this.name = name;
		this.age = age;
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

	public abstract void eat();

	public void sleep() {
		System.out.println("sleeping");
	}
}

class Cat extends Animal {
	public Cat() {}

	public Cat(String name, int age) {
		super(name, age);
	}

	public void eat() {
		System.out.println("cat " + this.getName() + " eat fash");
	}
}

class Dog extends Animal {
	public Dog() {}

	public Dog(String name, int age) {
		super(name, age);
	}

	public void eat() {
		System.out.println("dog " + this.getName() + " eat meet");
	}
}

// 有跳高功能的猫
class JumpCat extends Cat implements Jumpping {
	public JumpCat() {}

	public JumpCat(String name, int age) {
		super(name, age);
	}

	public void jump() {
		System.out.println("Jumpping cat");
	}
}

// 有跳高功能的狗
class JumpDog extends Dog implements Jumpping {
	public JumpDog() {}

	public JumpDog(String name, int age) {
		super(name, age);
	}

	public void jump() {
		System.out.println("Jumpping dog");
	}
}

class TestDemo {
	public static void main(String[] args) {
		JumpCat jc = new JumpCat("Tom", 2);
		jc.jump();
		jc.eat();
		jc.sleep();
	}
}