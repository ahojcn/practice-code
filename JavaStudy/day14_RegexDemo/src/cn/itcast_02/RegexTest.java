package cn.itcast_02;

import java.util.Scanner;

/*
 * 校验邮箱
 */
public class RegexTest {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("input a email address > ");
		String email = sc.nextLine();
		
		//String regex = "[a-zA-Z_0-9]+@[a-zA-Z_0-9]{2,6}(\\.[a-zA-Z_0-9]{2,3})+ ";
		String regex = "\\w+@\\w{2,6}(\\.\\w{2,3})+ ";
		System.out.println(email.matches(regex));
		
		sc.close();
	}
}
