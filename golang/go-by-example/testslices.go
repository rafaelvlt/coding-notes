package main

import (
	"fmt"
	//"slices" pode ser importado e tem diversas funções para slices
)

func testslices() {
	// slices substituem arrays, são mais usados	// são tipados somente pelos elementos e n pelo numero deles
	// são igual init quando n inicializados e len 0
	var s []string // slice
	fmt.Println("before init:", s, s == nil, len(s))

	// criar slices inicializando é cm a keyword make
	s = make([]string, 3) // cria slice com tanaho 3 com zero-value
	// capacidade do slice é o tamanho dele, pode ser passado maior antes

	s[0] = "a"
	fmt.Println("get:", s[0])

	// slices suportam maios operações que arrays, como append e copy que sao built in

	// append pode alterar inplace ou retornar um valor com um novo slice + o de append dependendo da capacidade. se for passar ele retorna um novo, se não ele altera inpalce
	s = append(s, "b")
	s = append(s, "c")
	s = append(s, "d")
	// cria um empty slice com tamanho de s e copia tudo para ele
	c := make([]string, len(s))
	copy(c, s) // retorna qtd de elems copiados
	fmt.Println("c copy: ", c)
	// slices suportam a operação de slice, igual python
	// slice[low:high] -> pega elens entre low e high-1
	l := s[2:5]
	fmt.Println("l slice: ", l)
	// slices podem ser multidimensionais, com o inner slice podendo variar de tamanho
	twoD := make([][]int, 3)
	for i := range 3 {
		innerLen := i + 1
		twoD[i] = make([]int, innerLen)
		for j := range innerLen {
			twoD[i][j] = i + j
		}
	}
	fmt.Println("2d: ", twoD)
}
