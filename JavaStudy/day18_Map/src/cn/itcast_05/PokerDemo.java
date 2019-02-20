package cn.itcast_05;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.TreeSet;

public class PokerDemo {
	public static void main(String[] args) {
		HashMap<Integer, String> hm = new HashMap<Integer, String>();

		ArrayList<Integer> array = new ArrayList<Integer>();

		String[] colors = { "♠️", "♥️", "♣️", "♦️" };
		String[] numbers = { "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A", "1", "2" };
		int index = 0;
		for (String number : numbers) {
			for (String color : colors) {
				String poker = color.concat(number);
				hm.put(index, poker);
				array.add(index);
				index++;
			}
		}
		hm.put(index, "小王");
		array.add(index);
		index++;
		hm.put(index, "大王");
		array.add(index);

		// 洗牌
		Collections.shuffle(array);

		TreeSet<Integer> p1 = new TreeSet<Integer>();
		TreeSet<Integer> p2 = new TreeSet<Integer>();
		TreeSet<Integer> p3 = new TreeSet<Integer>();
		TreeSet<Integer> diPai = new TreeSet<Integer>();
		
		// 发牌
		for (int i = 0; i < array.size(); i ++) {
			if (i >= array.size() - 3) {
				diPai.add(array.get(i));
			} else if (i % 3 == 0) {
				p1.add(array.get(i));
			} else if (i %2==0) {
				p2.add(array.get(i));
			} else if (i%1==0) {
				p3.add(array.get(i));
			}
		}
		
		lookPoker("p1", p1, hm);
		lookPoker("p2", p2, hm);
		lookPoker("p3", p3, hm);
		lookPoker("diPai", diPai, hm);
	}

	public static void lookPoker(String name, TreeSet<Integer> ts, HashMap<Integer, String> hm) {
		System.out.println(name + "的牌 : ");
		for (Integer key : ts) {
			String val = hm.get(key);
			System.out.print(val + " ");
		}
		System.out.println();
	}
}
