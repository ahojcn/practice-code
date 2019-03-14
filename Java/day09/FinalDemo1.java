class Fu {
	public final void show() {
		System.out.println("show() in class Fu");
	}
}

class Zi extends Fu {
	public void show() {	// 这里会报错，不能覆盖父类中的show()
		System.out.println("show() in class Zi");
	}
}

class FinalDemo1 {
	public static void main(String[] args) {
		Zi z = new Zi();
	}
}