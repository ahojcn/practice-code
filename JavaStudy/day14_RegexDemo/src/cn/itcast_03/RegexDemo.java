package cn.itcast_03;

/*
 * 正则表达式的分割功能
 */
public class RegexDemo {
	public static void main(String[] args) {
		// 搜索规定年龄范围内的人
		String ages = "18-24";
		
		// 定义规则
		String regex = "-";
		
		String[] strArr = ages.split(regex);
		
		for (int i = 0; i < strArr.length; i ++) {
			System.out.println(strArr[i]);
		}
		
		int startAge = Integer.valueOf(strArr[0]);
		int endAge = Integer.valueOf(strArr[1]);
		
		System.out.println("-----");
		System.out.println(startAge);
		System.out.println(endAge);
	}
}
