// f() 内的 s 是 main() 中 s 的一份拷贝
// f() 内的 s[index] 是对 s 解引用了

package main

import (
	"fmt"
)

func main() {
	s := []int{1, 1, 1}
	fmt.Printf("in main() &s : %p\n", s)
	f(s)
	fmt.Println("in main() s :", s)
}

func f(s []int) {
	fmt.Printf("in f() &s : %p\n", s)
	// for index, val := range s {
	// 	// 这里的 val 只是一个副本，所以并不会改变 s 的值
	// 	fmt.Println(index, val)
	// }

	for index := range s {
		s[index]++
	}

	s = append(s, 0)
	fmt.Println("in f() s :", s)
}
