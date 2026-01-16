package main

import (
	"fmt"
)

func testarrays() {
	// Arrays não são muito usados em Go
	var a [5]int // definição de um array, capacidade para 5 ints
	// inicializado em 0 para tudo, o tipo do array engloba o dado e o tamanho

	a[4] = 9
	fmt.Println("set:", a)
	fmt.Println("get:", a[4])
	fmt.Println("len:", len(a)) // built in

	b := [5]int{1, 2, 3, 4, 5} // forma de inicializar direto

	// ... -> compilador decide o tamanho baseado no inicializador
	// 3: 400 -> seta o indice 3 como 400, inbetween zerado
	b = [...]int{100, 3: 400, 500}

	fmt.Println("...:", b)

	var multi [2][3]int
	for i := range 2 {
		for j := range 3 {
			multi[i][j] = 1 + j
		}
	}

	fmt.Println("2d: ", multi)

	multi = [2][3]int{{1, 2, 3}, {1, 2, 3}}

	fmt.Println("2d: ", multi)
}
