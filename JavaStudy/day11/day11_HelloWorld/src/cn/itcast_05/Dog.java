package cn.itcast_05;

public class Dog extends Animal{

	@Override	// 是注解，这个注解的意思是说这个方法是重写父类的，如果父类没有，就会报错
	public void eat() {
		System.out.println("eatting ...");
	}
	
}
