class Fu {
	public int num = 100;

	public void show() {
		System.out.println("show() in class Fu");
	}
}

class Zi extends Fu {
	public int num = 10000;
	public int num2 = 200;

	public void show() {
		System.out.println("show() in class Zi");
	}
}

class DouTaiDemo {
	public static void main(String[] args) {
		Fu f = new Zi();
		System.out.println(f.num);
	//	System.out.println(f.num2);
		
	}
}