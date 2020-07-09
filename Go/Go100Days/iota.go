package main

import "fmt"

func main() {
	const (
		a = iota
		b = iota
		c = iota
	)
	fmt.Println(a, b, c)

	const (
		d = iota
		e
	)
	fmt.Println(d, e)

	const (
		MALE = iota
		FMALE
		UNKNOW
	)
	fmt.Println(MALE, FMALE, UNKNOW)
}
