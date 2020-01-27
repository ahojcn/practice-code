package main

import "fmt"

func main() {
	/*
	变量 variable
	go 是静态语言，强类型语言，go Java C++ C#
	动态语言：JavaScript PHP Python ruby
	 */
	// 基本用法
	var num1 int
	num1 = 30
	fmt.Printf("num1 = %d\n", num1)

	var num2 int = 20
	fmt.Printf("num2 = %d\n", num2)

	// 类型推断
	var name = "ahojcn"
	fmt.Printf("name 的类型是 %T, name = %s\n", name, name)

	// 简短定义，简短声明
	sum := 100
	fmt.Printf("sum = %d\n", sum)

	// 多个变量同事定义
	var a, b, c int
	a = 1
	b=2
	c=3
	fmt.Println(a,b,c)

	var m, n = 100, 100
	fmt.Println(m,n)

	var n1, f1, s1 = 100, 3.14, "Go"
	fmt.Println(n1, f1, s1)

	var (
		studentName = "ahojcn"
		age = 18
		sex = "男"
	)
	fmt.Printf("学生姓名：%s, 年龄：%d, 性别：%s\n", studentName, age, sex)
}
