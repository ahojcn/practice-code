package cn.itcast_04;

import java.util.HashMap;
import java.util.Set;

public class HashMapDemo1 {
	public static void main(String[] args) {
		HashMap<String, HashMap<String, Integer>> czbkMap = new HashMap<String, HashMap<String, Integer>>();
		
		HashMap<String, Integer> jcMap = new HashMap<String, Integer>();
		jcMap.put("ahojcn", 20);
		jcMap.put("baozi", 21);
		
		HashMap<String, Integer> jyMap = new HashMap<String, Integer>();
		jyMap.put("fancheng", 22);
		jyMap.put("peiqi", 23);
		
		czbkMap.put("jc", jcMap);
		czbkMap.put("jy", jyMap);
		
		// 遍历
		Set<String> set1 = czbkMap.keySet();
		for (String key1 : set1) {
			System.out.println(key1);
			HashMap<String, Integer> val1 = czbkMap.get(key1);
			Set<String> set2 = val1.keySet();
			for (String key2 : set2) {
				Integer val2 = val1.get(key2);
				System.out.println("\t" + key2 + " => " + val2);
			}
		}
	}
}
