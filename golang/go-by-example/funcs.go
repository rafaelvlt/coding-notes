package main

import "fmt"

// sintaxe para 2 args int e tipo de retorno int
func plus(a int, b int) int {
	return a + b
}

// pode ser colocado tipo implicito se vários seguidos sao do msm tipo
// ultimo sempre temq  ter tipo
func plus_plus(a, b, c int) int {
	return a + b + c
}

// go permite multiplos valores de retornos para funções
// é idiomatico e muito util, serve para debugging com error values
// sendo devolvidos

func sigs_seben() (int, int) {
	return 6, 7
}

// Variadic functions podem ser chamados com qualquer quantidade de args finais, fmt.Println é uma delas, pod eter quantos args quiser apos o 1
// essa é a sintaxe para ela, nums na verdade vira um []int. e chamamos o len dele para saber quantos vieram
func sum(nums ...int) {
	// Print não adiciona newline ao fim
	fmt.Print(nums, " ")
	total := 0

	for _, num := range nums {
		total += num
	}
	fmt.Println(total)
}

// retorna outra func definimos anonimanente na função ali
// a função retornada closes na variavel i para formar uma closure(?)
// closure é uma função que captura variaveis do escopo externo, normalmente atribuido a funções q são embedded em outras
func intSeq() func() int {
	i := 0
	return func() int {
		i++
		return i
	}
}

// suporte à recursão, func anonimas tb podem ser recursivas
// mas depende de explicitamente declarar var antes de atribuir a função ao declarar
func fact(n int) int {
	if n == 0 {
		return 1
	}
	return n * fact(n-1)
}

func testefuncoes() {
	res := plus(1, 2)
	fmt.Println("1 + 2 =", res)

	// não pode usar := se ja foi declarada antes
	res = plus_plus(1, 2, 3)
	fmt.Println("1 + 2 + 3 =", res)

	// caso não vá usar o valor de retorno ou de loop, use _ -> blank identifier
	sigs, _ := sigs_seben()
	fmt.Println(sigs)

	nums := []int{1, 2, 3, 4}
	// ... pode ser usado para dar unpack em array e enviar como vários args
	sum(nums...)

	// toda vez que chama nextInt a função captura outro i na closure
	nextInt := intSeq()

	fmt.Println(nextInt())
	fmt.Println(nextInt())
	fmt.Println(nextInt())

	// o estado é unico para func original, logo ao atribuir novamente, reseta
	newInts := intSeq()
	fmt.Println(newInts())

	fmt.Println(fact(5))

	// é necessário declarar antes ou durante a init para ser válido
	// func anonima recursiva
	var fib func(n int) int

	fib = func(n int) int {
		if n < 2 {
			return n
		}
		return fib(n-1) + fib(n-2)
	}
	fmt.Println(fib(7))
	// como fib é declarada antes na main, go sabe onde buscar ela ao realizar recursão
}
