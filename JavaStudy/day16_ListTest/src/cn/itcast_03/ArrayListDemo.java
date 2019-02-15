package cn.itcast_03;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

/*
 * 键盘录入多个数据，输入 0 结束，输出这些数据中的最大值。
 */
public class ArrayListDemo {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		ArrayList<Integer> arr = new ArrayList<Integer>();
		
		while (true) {
			System.out.print("input num > ");
			int num = sc.nextInt();
			if (num == 0) {
				break;
			} else {
				arr.add(num);
			}
		}
		
		Integer[] intArr = new Integer[arr.size()];
		arr.toArray(intArr);
		
		Arrays.sort(intArr);
		
		System.out.println("arr : " + arr2String(intArr));
		System.out.println("max : " + intArr[intArr.length - 1]);
	}
	
	public static String arr2String(Integer[] i) {
		StringBuilder sb = new StringBuilder();
		
		sb.append("[");
		for (int j = 0; j < i.length; j++) {
			if (j == i.length - 1) {
				sb.append(i[j]);
			} else {
				sb.append(i[j]).append(", ");
			}
		}
		sb.append("]");
		
		return sb.toString();
	}
}
