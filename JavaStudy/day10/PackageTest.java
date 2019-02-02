package cn.ahoj;

class PackageTest {
	public static void main(String[] args) {
		// PackageDemo d = new PackageDemo();
		com.ahoj.PackageDemo d = new com.ahoj.PackageDemo();
		System.out.println(d.sum(10,20));
	}
}