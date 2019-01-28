abstract class Animal {
	//public abstract void eat() {}	// 空方法体，报错
	public abstract void eat();
}

abstract class Dog extends Animal {}

class Cat extends Animal {
	public void eat() {
		System.out.println("cat eat fish");
	}
}

class AbstractDemo {
	public static void main(String[] args) {
		Animal a = new Cat();
		a.eat();
	}
}