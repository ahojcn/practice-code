package com.ahoj_02;

import com.ahoj_01.Jump;

/**
 * 这是具体的狗类
 * 
 * @author hanoi_ahoj
 * @version V1.0
 */
public class Dog extends Animal implements Jump {

	@Override
	public void jump() {
		System.out.println("dog jumpping ...");
	}

	@Override
	public void eat() {
		System.out.println("dog eatting ...");
	}

	@Override
	public void sleep() {
		System.out.println("dog sleeping ...");
	}

}
