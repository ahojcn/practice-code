interface Inter {
	public int num = 10;
	public final int num2 = 20;
}

// 接口名 + Impl 这种格式是接口的实现类格式
class InterImpl implements Inter {

}

class InterfaceDemo2 {
	public static void main(String[] args) {
		Inter i = new InterImpl();
		System.out.println(i.num);
		System.out.println(i.num2);

		/*i.num = 100;	// error!
		i.num2 = 200;	// error!
		System.out.println(i.num);
		System.out.println(i.num2);*/

		System.out.println(Inter.num);
		System.out.println(Inter.num2);
	}
}