package it.cast_01;

import java.util.Calendar;
import java.util.Scanner;

/*
 * 获取任意年份2月有多少天
 */
public class CalenderDemo {
	public static void main(String[] args) {
		Calendar c = Calendar.getInstance();
		Scanner sc = new Scanner(System.in);
		int year = sc.nextInt();
		c.set(year, 2, 1); // year-3-1
		c.add(Calendar.DATE, -1);
		
		System.out.println(c.get(Calendar.DATE));
	}
}
