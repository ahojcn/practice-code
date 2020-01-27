package main

import "fmt"

func main() {
	const (
		A = iota
		B
		C
		D = "haha"
		E
		F = 100
		G
		H = iota
		I
	)
	const (
		J = iota
	)

	fmt.Println(A, B, C, D, E, F, G, H, I, J)
}
