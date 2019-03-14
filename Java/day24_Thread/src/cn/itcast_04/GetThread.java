package cn.itcast_04;

public class GetThread implements Runnable {
	
	private Student s = new Student();
	
	public GetThread(Student s) {
		this.s = s;
	}

	@Override
	public void run() {
		while (true) {
			synchronized (s) {
				s.get();
			}
		}
	}

}
