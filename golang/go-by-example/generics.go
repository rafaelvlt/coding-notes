package main

import "fmt"

// Go tem suporte à generics desde a 1.18, chamados de type parameters também

// exemplo de função generica, pega um slice de qualquer tipo comparable e um elento daquele tipo e retorna o índice da primeira ocorrencia de v ou -1 se não estiver presente. O comparable significa que podemos comparar o valor desse tipo com == e !=.

// S ~[]E -> defini S como coleção e E como tipo da coleção, dando a restrição que E deve ser um tipo comparável. ~[]E diz para aceitar tipos subjacentes, baseados em slices também. Ou seja, S é uma coleção de tipos subjacentes à fatias, podendo ser qualquer coisa implementado baseado nisso, com os elementos da fatia sendo comparáveis. Passamos um elemento da fatia e ela para a função
func SlicesIndex[S ~[]E, E comparable](s S, v E) int {
	for i := range s {
		if v == s[i] {
			return i
		}
	}
	return -1
}

// podemos usar generics para tipos também
type element[T any] struct {
	next *element[T]
	val  T
}

// mesmo T dos elementos é o T daqui, é propagado
type List[T any] struct {
	head, tail *element[T]
}

// método para ponteiro de lista para dar push,
func (lst *List[T]) Push(v T) {
	if lst.tail == nil {
		lst.head = &element[T]{val: v}
		lst.tail = lst.head
	} else {
		lst.tail.next = &element[T]{val: v}
		lst.tail = lst.tail.next
	}
}

// método para retornar todos elems de uma Lista em formato de slice
func (lst *List[T]) AllElements() []T {
	var elems []T
	for e := lst.head; e != nil; e = e.next {
		elems = append(elems, e.val)
	}
	return elems
}

func testegenerics() {
	var s = []string{"foo", "bar", "zoo"}

	fmt.Println("index of zoo:", SlicesIndex(s, "zoo"))

	// Quando invocando funções genéricos podemos depender de inferencia do tipo. Não temos que especificar tipos para S e para E quando chamamos SlicesIndex, o compilador ifnere eles automaticamente
	_ = SlicesIndex[[]string, string](s, "zoo")

	lst := List[int]{}
	lst.Push(10)
	lst.Push(13)
	lst.Push(23)
	fmt.Println("list:", lst.AllElements())
}
