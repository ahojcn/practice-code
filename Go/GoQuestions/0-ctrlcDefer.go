// 测试：ctrl + c 后是否执行 defer 语句
// 结果：不会执行 defer

package main

import (
	"fmt"
)

func main() {
	defer fmt.Println("defer ...")

	for {
		fmt.Println("for ing ...")
	}
}
