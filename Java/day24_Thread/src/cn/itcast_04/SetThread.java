package cn.itcast_04;

public class SetThread implements Runnable {

	private Student s = new Student();
	private int x = 0;

	public SetThread(Student s) {
		this.s = s;
	}

	@Override
	public void run() {
		while (true) {
			synchronized (s) {
				if (x % 2 == 0) {
					s.set("xiaohei", 21);
				} else {
					s.set("baozi", 20);
				}
				x++;
			}
		}
	}

}
