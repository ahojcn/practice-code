package cn.itcast_03;

public class GetThread implements Runnable {
	
	private Student s = new Student();
	
	public GetThread(Student s) {
		this.s = s;
	}

	@Override
	public void run() {
		while (true) {
			synchronized (s) {
				if (!s.flag) {
					try {
						s.wait();
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
				}
				System.out.println(s.name + "---" + s.age);
				
				s.flag = false;
				s.notify();
			}
		}
	}

}
