package cn.itcast_02;

import java.util.HashMap;
import java.util.Set;

/*
 * HashMap<String,String>
 */
public class HashMapDemo1 {
	public static void main(String[] args) {
		HashMap<String, String> hm = new HashMap<String, String>();
		
		hm.put("007", "s7");
		hm.put("008", "s8");
		hm.put("001", "s1");
		hm.put("007", "s222");
		
		Set<String> set = hm.keySet();
		
		// 遍历
		for (String key : set) {
			String val = hm.get(key);
			System.out.println(key + "---" + val);
		}
	}
}
