class Phone {
	String brand;	//品牌
	int price;
	String color;	//颜色

	public void call(String name) {
		System.out.println("给" + name + "打电话");
	}

	public void sendMsg(String name) {
		System.out.println("给" + name + "发短信");
	}

	public void playGame(String game) {
		System.out.println("玩" + name + "游戏");
	}
}