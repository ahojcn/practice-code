/*
	猫
		成员变量：姓名、年龄、颜色
		构造方法：无参、带参
		成员方法：
				getXxx(),setXxx(),eat()
				playGame()
	狗
		成员变量：姓名、年龄、颜色
		构造方法：无参、带参
		成员方法：
				getXxx(),setXxx(),eat()
				lookDoor()
*/

class Animal {
	private String name;
	private int age;
	private String color;

	public Animal() {}

	public Animal(String name, int age, String color) {
		this.name = name;
		this.age = age;
		this.color = color;
	}

	public String getName() {
		return name;
	}

	public int getAge() {
		return age;
	}

	public String getColor() {
		return color;
	}

	public void setName(String name) {
		this.name = name;
	}

	public void setAge(int age) {
		this.age = age;
	}

	public void setColor(String color) {
		this.color = color;
	}

	public void eat() {
		System.out.println("eatting");
	}
}

class Cat extends Animal {
	public Cat() {}

	public Cat(String name, int age, String color) {
		super(name, age, color);
	}

	public void playGame() {
		System.out.println("cat play you");
	}
}

class Dog extends Animal {
	public Dog() {}

	public Dog(String name, int age, String color) {
		super(name, age, color);
	}

	public void lookDoor() {
		System.out.println("dog look door for you");
	}
}

class CatAndDog {
	public static void main(String[] args) {
		Cat tom = new Cat("tom", 2, "blue");
		Dog jim = new Dog("xiongxiong", 1, "white");

		System.out.println(tom.getName() + "," + tom.getAge() + "," + tom.getColor());
		System.out.println(jim.getName() + "," + jim.getAge() + "," + jim.getColor());
		tom.eat();
		tom.playGame();
		jim.eat();
		jim.lookDoor();
	}
}