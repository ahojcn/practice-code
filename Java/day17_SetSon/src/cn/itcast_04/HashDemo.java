package cn.itcast_04;

import java.util.HashSet;
import java.util.Random;

public class HashDemo {
	public static void main(String[] args) {
		HashSet<Integer> hs = new HashSet<Integer>();
		Random r = new Random();
		while (hs.size() < 10) {
			hs.add(r.nextInt(20) + 1);
		}
		
		System.out.println("hs : " + hs);
	}
}
