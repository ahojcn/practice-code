package q12;

import java.util.Scanner;

/*
 * 3.12 回文数字
 * 输入：一个三位数
 * 输出：是否为回文数
 */

public class PalindromeNumber {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		System.out.print("input a number(100-999) : ");
		
		int num = sc.nextInt();
		
		if (num < 100 && num > 999) {
			System.out.println("input error !");
		} else {
			if (num/100 == num%10) {
				System.out.println("yes !");
			} else {
				System.out.println("no !");
			}
		}
		
		sc.close();
	}
}
