package cn.itcast_01;

public class StringDemo {
	public static void main(String[] args) {
		String s1 = new String();
		s1 = "abcd123";
		System.out.println("s1 : " + s1);
		System.out.println("s1.length() : " + s1.length());
		System.out.println("-------");

		byte[] bs = { 97, 98, 99, 100, 101 };
		String s2 = new String(bs);
		System.out.println("s2 : " + s2);
		System.out.println("-------");

		String s3 = new String(bs, 1, 3);
		System.out.println("s3 : " + s3);
		System.out.println("s3.length() : " + s3.length());
		System.out.println("-------");

		char[] cs = { 'a', 'b', 'c', 'i', 'l', 'o' };
		String s4 = new String(cs);
		System.out.println("s4 : " + s4);
		System.out.println("s4.length() : " + s4.length());
		System.out.println("-------");
		
		
	}
}
