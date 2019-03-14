interface Inter {
	public abstract void show1();
	public abstract void show2();
}

class Outer {
	public void fun() {
		Inter i = new Inter() {
			public void show1() {
				System.out.println("show1");
			}

			public void show2() {
				System.out.println("show2");
			}
		};

		i.show1();
		i.show2();
	}
}

class InnerClassDemo {
	public static void main(String[] args) {
		Outer o = new Outer();
		o.fun();
	}
}