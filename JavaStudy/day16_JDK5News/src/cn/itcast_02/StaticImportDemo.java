package cn.itcast_02;

public class StaticImportDemo {
	public static void main(String[] args) {
		System.out.println(sum(1, 2));
		System.out.println(sum(1, 2, 3, 4));
		System.out.println(sum(1, 2, 5, 6, 7, 8, 9));
	}

	public static int sum(int... a) {
		int ret = 0;
		
		for (int x : a) {
			ret += x;
		}
		
		return ret;
	}
}