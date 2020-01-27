package main

import (
	"fmt"
)

func main() {
	/*
	1. 基本数据类型
		布尔类型：bool
		数值类型：
			整数：
				int uint 根据计算机位数决定 但是 64 位机的 int64 != int
				int8 int16 int32(rune) int64
				uint8(byte) uint16 uint32 uint64
				uintptr 指针类型
			浮点数：
				float32 float64
			复数：complex64 complex128
		字符串：string
	2. 符合数据类型
		array slice map function pointer struct interface channel
	 */

	var b1 bool = true
	fmt.Println(b1)
	b2 := false
	fmt.Println(b2)
}
