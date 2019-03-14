package cn.itcast_04;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Set;

public class HashMapDemo2 {
	public static void main(String[] args) {
		HashMap<String, ArrayList<String>> hm = new HashMap<String, ArrayList<String>>();
		
		ArrayList<String> arr1 = new ArrayList<String>();
		arr1.add("arr1_1");
		arr1.add("arr1_2");
		ArrayList<String> arr2 = new ArrayList<String>();
		arr2.add("arr2_1");
		arr2.add("arr2_2");
		ArrayList<String> arr3 = new ArrayList<String>();
		arr3.add("arr3_1");
		arr3.add("arr3_2");
		
		hm.put("a1", arr1);
		hm.put("a2", arr2);
		hm.put("a3", arr3);
		
		Set<String> set = hm.keySet();
		
		for (String key : set) {
			System.out.println(key);
			ArrayList<String> val = hm.get(key);
			for (String str : val) {
				System.out.println("\t" + str);
			}
		}
	}
}
