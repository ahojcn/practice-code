import java.util.Scanner;

class JiaMi {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("please input a number:");
		int num = sc.nextInt();

		String ans = jiaMi(num);
		System.out.println(ans);
	}

	public static String jiaMi(int num) {
		int[] arr = new int[8];
		int index = 0;
		while (num > 0) {
			arr[index] = ((num%10) + 5 ) % 10;
			num /= 10;
			index ++;
		}

		int tmp = arr[0];
		arr[0] = arr[index - 1];
		arr[index - 1] = tmp;

		String ret = "";
		for (int i = 0; i < index; i ++) {
			ret += arr[i];
		}
		return ret;
	}
}





