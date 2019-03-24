package q16;

public class RandomCharacter {
	public static void main(String[] args) {
		// [0.0, 1.0)
		System.out.println((char) (Math.random() * 26 + 65));
		System.out.println(test());
	}

	public static Boolean test() {
		Boolean flag = true;
		for (int i = 0; i < 100; i++) {
			char a = (char) (Math.random() * 26 + 65);
			if (a >= 'A' || a <= 'Z') {
				
			} else {
				flag = false;
			}
		}
		return flag;
	}
}
