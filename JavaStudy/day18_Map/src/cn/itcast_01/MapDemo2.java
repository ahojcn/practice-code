package cn.itcast_01;

import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class MapDemo2 {
	public static void main(String[] args) {
		Map<String, String> map = new HashMap<String, String>();
		
		map.put("a1", "b1");
		map.put("a2", "b2");
		map.put("a3", "b3");
		
		Set<Map.Entry<String, String>> set = map.entrySet();
		
		for (Map.Entry<String, String> me : set) {
			System.out.println(me.getKey() + "---" + me.getValue());
		}
	}
}
