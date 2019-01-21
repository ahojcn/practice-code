import java.util.Scanner;

class FunTest {
	public static void main(String[] args) {
		int a = 10;
		int b = 20;
		System.out.println("a = " + a + ",b = " + b);
		fun(a,b);
		System.out.println("a = " + a + ",b = " + b);

		int[] arr = {1,2,3,4,5};
		printArr(arr);
		fun(arr);
		printArr(arr);
	}

	public static void fun(int a, int b) {
		a += 1;
		b += 2;
	}

	public static void fun(int[] arr) {
		for (int i = 0; i < arr.length; i ++) {
			arr[i] += 10;
		}
	}

	public static void printArr(int[] arr) {
		for (int i = 0; i < arr.length; i ++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
	}
}