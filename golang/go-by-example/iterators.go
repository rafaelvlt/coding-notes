package main

import (
	"fmt"
	"iter"
	"slices"
)

// A partir da 1.23, go tem suporte para iterators, que permite fazer ranges em qualquer coisa

// Utilizando listas e elementos de generics.go, tinhamos AllElements que retornava um slice com todos elementos da lista. Com iteradores em Go podemos fazer melhor

// Usamos função anonima dentro de All, que retorna um iterador, que é uma função com uma assinatura especial
func (lst *List[T]) All() iter.Seq[T] {
	// A iterator func pega outra função como parametro, chamada de yield por convenção. ela irá chamar yield para cada elemento que queremos iterar sob, e anotar o valor de yield para uma possível terminação brusca

	return func(yield func(T) bool) {
		for e := lst.head; e != nil; e = e.next {
			if !yield(e.val) {
				return
			}
		}
	}
}

//Iteração não precisa de uma data structure, e não precisa ser finita. Um exemplo usando iterador para sequencia de fibonnaci

func genFib() iter.Seq[int] {
	return func(yield func(int) bool) {
		a, b := 1, 1

		for {
			if !yield(a) {
				return
			}
			a, b = b, a+b
		}
	}
}

func testeiter() {
	lst := List[int]{}
	lst.Push(10)
	lst.Push(13)
	lst.Push(23)

	//List.All retorna um iterador, podemos usar ele em um range loop regular
	for e := range lst.All() {
		fmt.Println(e)
	}

	// package slice tem vários funções para trabalhar com iterators. Collect pega qualquer iterador e coleta todos os valores dele em um slice
	all := slices.Collect(lst.All())
	fmt.Println("all:", all)

	// Quando o loop entra em break ou early return, o yield passado para o iterador irá retornar false
	for n := range genFib() {
		if n >= 10 {
			break
		}
		fmt.Println(n)
	}
}
