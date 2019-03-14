package cn.itcast_04;

import java.util.Comparator;
import java.util.TreeSet;

/*
 * 键盘录入5个学生信息(姓名,语文成绩,数学成绩,英语成绩),按照总分从高到低输出到控制台
 */
public class TreeSetDemo {
	public static void main(String[] args) {
		TreeSet<Student> ts = new TreeSet<Student>(
				new Comparator<Student>() {

					@Override
					public int compare(Student o1, Student o2) {
						int num1 = o1.getSum() - o2.getSum();
						int num2 = num1 == 0 ? o1.getChinese() - o2.getChinese() : num1;
						int num3 = num2 == 0 ? o1.getEnglish() - o2.getEnglish() : num2;
						int num4 = num3 == 0 ? o1.getMath() - o2.getMath() : num3;
						int num5 = num4 == 0 ? o1.getName().compareTo(o2.getName()) : num4;
						return num5;
					}
					
				}
		);
		
		/* 录入学生信息... */
		/* 存入TreeSet并输出... */
	}
}
