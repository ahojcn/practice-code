class Phone {
	private String brand;	// 品牌
	private int price;		// 价格
	private String color;	// 颜色

	public Phone() {
	}

	public String getBrand() {
		return brand;
	}

	public void setBrand(String brand) {
		this.brand = brand;
	}

	public int getPrice() {
		return price;
	}

	public void setPrice(int price) {
		this.price = price;
	}

	public String getColor() {
		return color;
	}

	public void setColor(String color) {
		this.color = color;
	}
}

class PhoneDemo {
	public static void main(String[] args) {
		Phone p = new Phone();
		p.setBrand("SANSUNG");
		p.setPrice(1000);
		p.setColor("black");

		System.out.println(p.getBrand() + "," + p.getPrice() + "," + p.getColor());
	}
}