// 定义动物培训接口
interface AnimalTrain {
	public abstract void jump();
}

/*
	接口的子类：
		1. 可以是抽象类，但是意义不大
		2. 可以是具体类，要重写接口中所有抽象方法。（推荐方案）
*/
abstract class Dog implements AnimalTrain {
}

class Cat implements AnimalTrain {
	public void jump() {
		System.out.println("cat jump!");
	}
}

class InterfaceDemo {
	public static void main(String[] args) {
		// AnimalTrain at = new AnimalTrain();	// error, 接口不能被实例化
		/*
			由此可见：多态中
				1. 具体类多态（几乎没有）
				2. 抽象类多态（常用）
				3. 接口多态（最常用）
		*/
		AnimalTrain at = new Cat();
		at.jump();
	}
}