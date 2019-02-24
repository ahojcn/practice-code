package cn.itcast_04;

public class StudentDemo {
	public static void main(String[] args) {
		Student s = new Student();
		
		GetThread gt = new GetThread(s);
		SetThread st = new SetThread(s);
		
		Thread t1 = new Thread(gt);
		Thread t2 = new Thread(st);
		
		t1.start();
		t2.start();
	}
}
