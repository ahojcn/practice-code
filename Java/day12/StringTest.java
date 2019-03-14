public class StringTest {
	public static void main(String[] args) {
		String s1 = "hello";
		String s2 = "world";
		String s3 = "helloworld";
		System.out.println(s3 == s1 + s2);	// false
		System.out.println(s3.equals((s1 + s2)));	// true
		System.out.println(s3 == "hello" + "world");	// true
		System.out.println(s3.equals("hello" + "world"));	// true
	}
}