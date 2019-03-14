package cn.itcast_04;

import java.util.Scanner;
import java.util.Set;
import java.util.TreeMap;

/*
 * "aababcabcdabcde",获取字符串中每一个字母出现的次数要求结果:a(5)b(4)c(3)d(2)e(1)
 */
public class MapTest {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("input : ");
		String src = sc.nextLine();
		sc.close();

		char[] charSrc = src.toCharArray();

		TreeMap<Character, Integer> tm = new TreeMap<Character, Integer>();

		for (char ch : charSrc) {
			Integer i = tm.get(ch);
			if (i == null) {
				tm.put(ch, 1);
			} else {
				i++;
				tm.put(ch, i);
			}
		}
		
		Set<Character> set = tm.keySet();
		
		StringBuilder sb = new StringBuilder();
		
		for (Character key : set) {
			Integer val = tm.get(key);
			sb.append(key).append("(").append(val).append(")");
		}
		
		System.out.println("ans : " + sb.toString());
	}
}
