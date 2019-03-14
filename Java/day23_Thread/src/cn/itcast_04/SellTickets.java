package cn.itcast_04;

public class SellTickets implements Runnable {

	private static int tickets = 100;
	
	@Override
	public void run() {
		while (true) {
			sellTickets();
		}
	}

	private static synchronized void sellTickets() {
		if (tickets > 0) {
			try {
				Thread.sleep(100);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			System.out.println(Thread.currentThread().getName() + "正在出售第 " + (tickets--) + " 张票");
		}
	}

}
