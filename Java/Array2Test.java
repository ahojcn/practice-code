class Array2Test {
	public static void main(String[] args) {
		int[][] arr = new int[3][2];
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 2; j++) {
				arr[i][j] = i + j;
			}
		}
		System.out.println("arr," + arr);
		System.out.println("arr[0]," + arr[0]);
		System.out.println("arr[1]," + arr[1]);
		System.out.println("arr[3]," + arr[2]);
		for (int i = 0; i < 3; i ++) {
			for (int j = 0; j < 2; j ++) {
				System.out.println("arr[" + i + "]" + "[" + j + "]=" + arr[i][j]);
			}
		}
	}
}