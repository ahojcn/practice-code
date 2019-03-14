import java.util.Scanner;

class NumGame {
	public static void main(String[] args) {
		int num = (int)(Math.random() * 100) + 1;

		while (true) {
			System.out.print("your input> ");
			Scanner sc = new Scanner(System.in);
			int inputNum = sc.nextInt();

			if (inputNum > num) {
				System.out.println("big");
			} else if (inputNum < num) {
				System.out.println("smail");
			} else {
				System.out.println("OK!");
				break;
			}
		}
	}
}