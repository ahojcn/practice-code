class Phone {
	public void call(String name) {
		System.out.println("call to" + name);
	}
}

class NewPhone extends Phone{
	public void call(String name) {
		super.call(name);
		System.out.println("listen to text");
	}
}

class ExtendsDemo3 {
	public static void main(String[] args) {
		NewPhone np = new NewPhone();
		np.call("liming");
	}
}