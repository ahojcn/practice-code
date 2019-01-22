class Phone {

	private String brand;	// 品牌
	private int price;		// 价格
	private String color;	// 颜色

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

class TelPhone {
	public static void main(String[] args) {
		Phone s = new Phone();
		s.setBrand("SANSUNG");
		s.setPrice(1500);
		s.setColor("red");
		System.out.println(s.getBrand() + "," + s.getColor() + "," + s.getPrice());
	}
}