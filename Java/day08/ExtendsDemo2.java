class Father {
	public Father() {
		System.out.println("Father 的无参构造");
	}

	public Father(String name) {
		System.out.println("Father 的带参构造");
	}
}

class Son extends Father {
	public Son() {
		System.out.println("Son 的无参构造");
	}

	public Son(String name) {
		System.out.println("Son 的带参构造");
	}
}

class ExtendsDemo2 {
	public static void main(String[] args) {
		Son s = new Son();
		System.out.println("-----------");
		Son s2 = new Son("liming");
	}
}