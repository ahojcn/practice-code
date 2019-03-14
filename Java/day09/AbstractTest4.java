/*
	假如我们现在开发一个系统时需要对员工类进行设计，员工包含3个属性：姓名、工号、工资
	经理也是员工，除了含有员工的属性外，另外还有一个奖金属性
	使用继承的设计思想设计出员工类和经理类。
	要求：类中提供必要的方法进行属性访问

	分析：
		普通员工类：
			成员变量：姓名、工号、工资
			成员方法：工作
		经理类：
			成员变量：姓名、工号、工资、奖金属性
			成员方法：工作

	实现：
		员工类：
		普通员工类：
		经理类：
*/

// 员工类
abstract class Employee {
	private String name;
	private String id;
	private int salary;

	public Employee() {}

	public Employee(String name, String id, int salary) {
		this.name = name;
		this.id = id;
		this.salary = salary;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getId() {
		return id;
	}

	public void setId(String id) {
		this.id = id;
	}

	public int getSalary() {
		return salary;
	}

	public void setSalary(int salary) {
		this.salary = salary;
	}

	public abstract void work();
}

class Programmer extends Employee {
	public Programmer() {}

	public Programmer(String name, String id, int salary) {
		super(name, id, salary);
	}

	public void work() {
		System.out.println("写代码");
	}
}

class Manager extends Employee {
	private int bonus;	// 奖金

	public Manager() {}

	public Manager(String name, String id, int salary, int bonus) {
		super(name, id, salary);
		this.bonus = bonus;
	}

	public void work() {
		System.out.println("经理谈生意");
	}

	public int getBonus() {
		return bonus;
	}

	public void setBonus(int bonus) {
		this.bonus = bonus;
	}
}

class AbstractTest4 {
	public static void main(String[] args) {
		Employee e = new Programmer("ahoj", "41709310119", 20000);
		System.out.println(e.getName() + " " + e.getId() + " " + e.getSalary());
		e.work();
	}
}