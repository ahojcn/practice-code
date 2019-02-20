package cn.itcast_02;

import java.util.HashMap;
import java.util.Set;

/*
 * HashMap<Integer,String>
 */
public class HashMapDemo2 {
	public static void main(String[] args) {
		HashMap<Integer, String> hm = new HashMap<Integer, String>();
		
		hm.put(007, "周星驰");
		hm.put(9527, "周星驰");
		
		Set<Integer> set = hm.keySet();
		
		for (Integer key : set) {
			String val = hm.get(key);
			System.out.println(key + "---" + val);
		}
	}
}
