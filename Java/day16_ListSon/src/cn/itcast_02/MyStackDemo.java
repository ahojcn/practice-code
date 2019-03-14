package cn.itcast_02;

public class MyStackDemo {
	public static void main(String[] args) {
		MyStack ms = new MyStack();
		
		ms.add("hello");
		ms.add("java");
		
//		System.out.println(ms.get());
//		System.out.println(ms.get());
		
		while (!ms.isEmpty()) {
			System.out.println(ms.get());
		}
	}
}
