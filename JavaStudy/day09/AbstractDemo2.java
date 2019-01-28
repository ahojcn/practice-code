/*
	抽象类的成员特点
*/

abstract class Animal {
	public int num = 10;

	public Animal() {}
}

class Dog extends Animal {

}

class AbstractDemo2 {
	public static void main(String[] args) {
		Animal a = new Dog();
		a.num = 20;
		System.out.println(a.num);
	}
}