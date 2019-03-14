package cn.itcast_02;

import com.ahoj_02.Animal;
import com.ahoj_02.Cat;
import com.ahoj_02.Dog;

public class AnimalDemo {
	public static void main(String[] args) {
//		 抽象类不能实例化
//		Animal a = new Animal();
		Animal a = new Dog();
		a.eat();
		a.sleep();
		
		System.out.println("------");
		
		a = new Cat();
		a.eat();
		a.sleep();
		
		Dog d = new Dog();
		d.jump();
	}
}
