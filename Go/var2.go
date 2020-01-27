package main

import "fmt"

func main() {
	var num int
	num = 100
	fmt.Printf("num:%d, &num:%p\n", num, &num)

	num = 200
	fmt.Printf("num:%d, &num:%p\n", num, &num)
}
