package cn.itcast_01;

import java.util.HashMap;
import java.util.Map;
import java.util.Set;

/*
 * Map集合的遍历。
 * Map -- 夫妻对
 * 思路：
 * 		A:把所有的丈夫给集中起来。
 * 		B:遍历丈夫的集合，获取得到每一个丈夫。
 * 		C:让丈夫去找自己的妻子。
 * 
 * 转换：
 * 		A:获取所有的键
 * 		B:遍历键的集合，获取得到每一个键
 * 		C:根据键去找值
 */
public class MapDemo1 {
	public static void main(String[] args) {
		Map<String, String> map = new HashMap<String, String>();
		
		map.put("a1", "b1");
		map.put("a2", "b2");
		map.put("a3", "b3");
		
		Set<String> set = map.keySet();
		
		for (String key : set) {
			String val = map.get(key);
			System.out.println(key + "--" + val);
		}
	}
}
