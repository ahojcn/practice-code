class Fu {
	public void show() {
		System.out.println("show fu");
	}
}

class Zi extends Fu {
	public void show() {
		System.out.println("show zi");
	}

	public void method() {
		System.out.println("method zi");
	}
}

class DuoTaiDemo2 {
	public static void main(String[] args) {
		Fu f = new Zi();
		f.show();

		Zi z = (Zi)f;	// 向下转型
		z.show();
		z.method();
	}
}