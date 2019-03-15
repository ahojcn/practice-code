package q10;

/*
 * Game : addition quiz
 * 随机产生两个小于 100 的整数
 * 输入：这两个数的和
 * 输出：输入是否正确
 */

import java.util.Scanner;

public class AddClass {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int num1 = (int)(Math.random() * 100);
		int num2 = (int)(Math.random() * 100);
		
		System.out.println("what is " + num1 + " + " + num2 + " = ?");
		
		int ans = sc.nextInt();
		
		if(ans == num1 + num2) {
			System.out.println("you're right !");
		} else {
			System.out.println("you're wrong !\n" + num1 + " + " + num2 + " = " + (num1 + num2));
		}
		
		sc.close();
	}
}
