package cn.itcast_02;

import java.util.ArrayList;
import java.util.Random;

/*
 * 产生 10 个不同的 1~20 之间的随机数。
 */
public class RandomDemo {
	public static void main(String[] args) {
		ArrayList<Integer> s = new ArrayList<Integer>();

		Random r = new Random();

		int count = 0;
		while (count < 10) {
			int num = r.nextInt(20) + 1; // 1 ~ 20
			if (!s.contains(num)) {
				s.add(num);
				count++;
			}
		}
		
		for (Integer i : s) {
			System.out.println(i);
		}
	}
}
