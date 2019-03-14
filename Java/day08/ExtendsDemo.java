class Father {
	public int num = 10;
}

class Son extends Father {
	public int num = 20;

	public void show() {
		int num = 30;
		System.out.println(num);
		System.out.println(this.num);
		System.out.println(super.num);
	}
}

class ExtendsDemo {
	public static void main(String[] args) {
		Son s = new Son();
		s.show();
	}
}