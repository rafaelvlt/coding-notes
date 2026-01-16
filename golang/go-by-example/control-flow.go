package main

import (
	"fmt"
)

func control() {
	// if-else simples, não precisa de parenteses mas tem {} obrigatorias
	a := 9
	if a+a == 19 {
		fmt.Println("simples")
	} else {
		fmt.Println("not reachable")
	}
	// ops logicos padrão funcionam
	if a != 9 || true {
		fmt.Println("or")
	} else if a == 9 || false {
		fmt.Println("else if!")
	}
	// possivel fazer declaração antes da condicional
	// o escopo delas é nessa branche ou nas subsequentes
	if num := 10; num < 0 {
		fmt.Println(num, "is negative")
	} else if num == 10 {
		fmt.Println("Dentro do num!")
	} else {
		num = 4
		fmt.Println(num, "novo num")
	}
	// não existe operador ternário em go
}
