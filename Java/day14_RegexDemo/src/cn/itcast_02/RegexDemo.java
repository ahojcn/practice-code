package cn.itcast_02;

import java.util.Scanner;

/*
 * 校验手机号码是否满足要求
 */

public class RegexDemo {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("input a phone number > ");
		String phoneNum = sc.nextLine();
		System.out.println(checkPhoneNum(phoneNum));
		sc.close();
	}
	
	// 13......
	// 18......
	public static boolean checkPhoneNum(String phoneNum) {
		return phoneNum.matches("1[38]\\d{9}");
	}
}
