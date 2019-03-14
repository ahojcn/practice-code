package cn.itcast_03;

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
				if (s.flag) {
					try {
						s.wait();
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
				}
				
				if (x % 2 == 0) {
					s.name = "xiaohei";
					s.age = 21;
				} else {
					s.name = "baozi";
					s.age = 20;
				}
				x++;
				
				s.flag = true;
				s.notify();
			}
		}
	}

}
