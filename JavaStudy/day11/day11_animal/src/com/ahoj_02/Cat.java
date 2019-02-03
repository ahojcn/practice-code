package com.ahoj_02;
/**
 * 这是具体的猫类
 * 
 * @author hanoi_ahoj
 * @version V1.0
 */
public class Cat extends Animal {

	@Override
	public void eat() {
		System.out.println("cat eat fish ...");
	}

	@Override
	public void sleep() {
		System.out.println("cat sleeping ...");
	}

}
