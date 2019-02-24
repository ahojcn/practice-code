package cn.itcast_01;

public class MyThreadTest {
	public static void main(String[] args) {
		MyThread my1 = new MyThread();
		MyThread my2 = new MyThread();
		
		my1.setName("ahoj");
		my2.setName("baozi");
		
		my1.start();
		my2.start();
		
		System.out.println(Thread.currentThread().getName());
	}
}
