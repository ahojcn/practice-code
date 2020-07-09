package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	/*
	var x int
	var y float64

	fmt.Println("请输入一个整数，一个浮点数：")
	fmt.Scanln(&x, &y)
	fmt.Println(x, y)

	fmt.Scanf("%d,%f", &x, &y)
	fmt.Println(x, y)
	*/

	fmt.Println("请输入一个字符串")
	reader:=bufio.NewReader(os.Stdin)
	s1, _ := reader.ReadString('\n')
	fmt.Println(s1)
}
