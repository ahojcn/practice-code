class Demo {
	private int num = 10;

	public void showNum() {
		System.out.println(num);
	}

	private void privateFun() {
		System.out.println("In Private Function");
	}

	public void fun() {
		privateFun();
	}
}

class PrivateDemo {
	public static void main(String[] args) {
		Demo d = new Demo();
		d.showNum();
		d.fun();
	}
}