package main

import "fmt"

func main() {
	// 常量
	const PATH string = "www.baidu.com"
	const PI = 3.14
	fmt.Println(PATH, PI)

	const (
		MALE   = 0
		FEMALE = 1
		UNKNOW = 3
	)

	const (
		a int = 100
		b
		c string = "ahojcn"
		d
	)
	fmt.Println(a, b, c, d)
}
