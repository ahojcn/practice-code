package cn.itcast_03;

import java.util.TreeSet;

public class TreeSetDemo2 {
	public static void main(String[] args) {
		TreeSet<Integer> ts = new TreeSet<Integer>();

		ts.add(11);
		ts.add(9);
		ts.add(22);
		ts.add(1);
		ts.add(18);
		ts.add(1);
		ts.add(11);

		for (Integer i : ts) {
			System.out.println(i);
		}

	}
}
