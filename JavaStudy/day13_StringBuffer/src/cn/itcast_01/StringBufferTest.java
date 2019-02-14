package cn.itcast_01;

public class StringBufferTest {
	public static void main(String[] args) {
		int[] arr = { 11, 22, 33, 55, 44 };

		// test 1
		System.out.println(arrToStr1(arr));

		// test 2
		System.out.println(arrToStr2(arr));
	}

	// test 1
	public static String arrToStr1(int[] arr) {
		StringBuffer sb = new StringBuffer();

		sb.append("[");
		for (int i = 0; i < arr.length; i++) {
			if (i == arr.length - 1) {
				sb.append(arr[i]);
			} else {
				sb.append(arr[i]).append(", ");
			}
		}
		sb.append("]");

		return sb.toString();
	}

	// test 2
	public static String arrToStr2(int[] arr) {
		String s = "";

		s += "[";
		for (int i = 0; i < arr.length; i++) {
			if (i == arr.length - 1) {
				s += arr[i];
			} else {
				s += arr[i];
				s += ", ";
			}
		}
		s += "]";

		return s;
	}
}
