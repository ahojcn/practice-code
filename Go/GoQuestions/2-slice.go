// 通过给函数传递 slice 的指针来改变 s
// 或者通过函数的返回值来改变 s

package main

import (
	"fmt"
)

func main() {
	s := []int{1, 1, 1}
	fmt.Println(s)
	myAppend(&s)
	fmt.Println(s)
	s = myAppend1(s)
	fmt.Println(s)
}

func myAppend(s *[]int) {
	*s = append(*s, 100)
	return
}

func myAppend1(s []int) []int {
	s = append(s, 200)
	return s
}
