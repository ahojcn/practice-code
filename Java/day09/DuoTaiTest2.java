/*
	不同地方饮食文化不同的案例
*/

class Person {
	public void eat() {
		System.out.println("吃饭");
	}
}

class SouthPerson extends Person {
	public void eat() {
		System.out.println("吃米饭");
	}

	public void jingShang() {
		System.out.println("经商");
	}
}

class NorthPerson extends Person {
	public void eat() {
		System.out.println("吃面");
	}

	public void yanJiu() {
		System.out.println("搞研究");
	}
}

class DuoTaiTest2 {
	public static void main(String[] args) {
		Person p = new SouthPerson();
		p.eat();
		System.out.println("------");

		SouthPerson sp = (SouthPerson)p;
		sp.eat();
		sp.jingShang();
		System.out.println("------");

		p = new NorthPerson();
		p.eat();
		System.out.println("------");
		
		NorthPerson np = (NorthPerson)p;
		np.eat();
		np.yanJiu();
	}
}