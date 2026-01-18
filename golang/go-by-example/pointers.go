package main

import "fmt"

func zeroval(ival int) {
	ival = 0
}

func zeroptr(iptr *int) {
	*iptr = 0
}

// go possui suporte à pointers, permitindo passagem por referencia de valores
func testpointers() {
	i := 1
	fmt.Println("initial:", i)

	// operadores de endereço e de dereferencia são iguais à c
	zeroptr(&i)
	fmt.Println("after zeroptr:", i)

	fmt.Println("pointer addr:", &i)
}
