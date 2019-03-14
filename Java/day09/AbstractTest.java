/*
	猫狗案例
		具体事物：猫、狗
		共性：姓名、年龄、吃饭

	分析：从具体到抽象
		猫：
			成员变量：姓名，年龄
			构造方法：无参、带参
			成员方法：吃饭（猫吃鱼）
		狗：
			成员变量：姓名，年龄
			构造方法：无参、带参
			成员方法：吃饭（狗吃肉）
		因为有共性的内容，所以就提取了一个父类（动物）。
		但是又因为吃饭的内容不一样，所以吃饭的方法是抽象的。
		而方法是抽象的类，类就必须定义为抽象类。

		抽象动物类：
			成员变量：姓名，年龄
			构造方法：无参、带参
			成员方法：吃饭（抽象的）

	实现：从抽象到具体
*/

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

	// 定义一个抽象方法
	public abstract void eat();
}

class Dog extends Animal {
	public Dog() {}

	public Dog(String name, int age) {
		super(name, age);
	}

	public void eat() {
		System.out.println("dog eat meet");
	}
}

class Cat extends Animal {
	public Cat() {}

	public Cat(String name, int age) {
		super(name, age);
	}

	public void eat() {
		System.out.println("cat eat fish");
	}
}

class AbstractTest {
	public static void main(String[] args) {
		Animal d = new Dog("tom", 19);
		d.eat();

		Animal a = new Cat();
		a.setName("jam");
		a.setAge(10);
		System.out.println(a.getName() + "," + a.getAge());
		a.eat();
	}
}