/*
	教练和运动员案例
		乒乓球运动员和篮球运动员
		乒乓球教练和篮球教练
		为了出国交流，跟乒乓球相关的人要学习英语
*/

// 说英语的接口
interface SpeakEnglish {
	// 说英语
	public abstract void speak();
}

abstract class Person {
	private String name;
	private int age;

	public Person() {}

	public Person(String name, int age) {
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

	// 睡觉
	public void sleep() {
		System.out.println(name + " is sleepping ...");
	}

	// 吃饭
	public abstract void eat();
}

// 运动员
abstract class Player extends Person {
	public Player() {}

	public Player(String name, int age) {
		super(name, age);
	}

	public abstract void study();
}

// 教练
abstract class Coach extends Person {
	public Coach() {}

	public Coach(String name, int age) {
		super(name, age);
	}

	public abstract void teach();
}

// 乒乓球运动员
class PingPangPlayer extends Player implements SpeakEnglish {
	public PingPangPlayer() {}

	public PingPangPlayer(String name, int age) {
		super(name, age);
	}

	public void eat() {
		System.out.println("乒乓球运动员 eat ...");
	}

	public void study() {
		System.out.println("乒乓球运动员 study ...");
	}

	public void speak() {
		System.out.println("乒乓球运动员 speak english ...");
	}
}

// 篮球运动员
class BasketballPlayer extends Player {
	public BasketballPlayer() {}

	public BasketballPlayer(String name, int age) {
		super(name, age);
	}

	public void eat() {
		System.out.println("篮球运动员 eat ...");
	}

	public void study() {
		System.out.println("篮球运动员 study ...");
	}
}

// 乒乓球教练
class PingPangCoach extends Coach implements SpeakEnglish {
	public PingPangCoach() {}

	public PingPangCoach(String name, int age) {
		super(name, age);
	}

	public void eat() {
		System.out.println("乒乓球教练 eat ...");
	}

	public void teach() {
		System.out.println("乒乓球教练教乒乓球 ...");
	}

	public void speak() {
		System.out.println("乒乓球教练说英语 ...");
	}
}

// 篮球教练
class BaskerballCoach extends Coach {
	public BaskerballCoach() {}

	public BaskerballCoach(String name, int age) {
		super(name, age);
	}

	public void eat() {
		System.out.println("篮球教练 eat ...");
	}

	public void teach() {
		System.out.println("篮球教练教篮球 ...");
	}
}

class InterfaceDemo1 {
	public static void main(String[] args) {
		// test player
		PingPangPlayer ppp = new PingPangPlayer("WangHao", 33);
		ppp.eat();
		ppp.sleep();
		ppp.study();
		ppp.speak();

		// test coach
		BaskerballCoach bc = new BaskerballCoach("YaoMing", 34);
		bc.eat();
		bc.sleep();
		bc.teach();
	}
}