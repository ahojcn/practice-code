/*
	多态练习：猫狗案例
*/

class Animal {
	public void eat() {
		System.out.println("吃饭");
	}
}

class Dog extends Animal {
	public void eat() {
		System.out.println("狗吃肉");
	}

	public void lookDoor() {
		System.out.println("狗看门");
	}
}

class Cat extends Animal {
	public void eat() {
		System.out.println("猫吃鱼");
	}

	public void playGame() {
		System.out.println("猫玩游戏");
	}
}

class DuoTaiTest {
	public static void main(String[] args) {
		Animal a = new Dog();
		a.eat();
		System.out.println("-----");
		Dog d = (Dog)a;
		d.eat();
		d.lookDoor();

		System.out.println("-----");
		a = new Cat();
		a.eat();
		System.out.println("-----");
		Cat c = (Cat)a;
		c.eat();
		c.playGame();
	}
}