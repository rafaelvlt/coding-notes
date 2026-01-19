package main

import (
	"errors" // implementa funções para manipular errors
	"fmt"
)

// Em Go, é idiomático retornar errors via um segundo return value explícito. contrasta com exceções usadas em outras linguagens, e tambem com o overloading de um único return/error value em C. Faz o error handling ser explícito e claro com os msm construtos usados na própria linguagem

// A definição de tipos de errors customizados é simples, basta implementar o metodo Error().

type argError struct {
	arg     int
	message string
}

// Com esse método argError implementa a interface error
func (e *argError) Error() string {
	return fmt.Sprintf("%dd - %s", e.arg, e.message)
}

// Por convenção, errors são o ultimo return value e tem o tipo error, uma interface built in

func f(arg int) (int, error) {
	if arg == 42 {
		// Errors.New construi um error value com a mensagem
		//return -1, errors.New("cant work with 42")
		return -1, &argError{arg, "can't work with it"}
	}
	// se retornado nil, não teve error
	return arg + 3, nil
}

// Um sentinel error é uma variável pré-declarada que é usada para significar uma condição de erro específica
var ErrOutOfTea = errors.New("no more tea available")
var ErrPower = errors.New("can't boil water")

func makeTea(arg int) error {
	if arg == 2 {
		return ErrOutOfTea
		// podemos dar warp em errors com errors de maior nivel para adicionar contexto. O jeito mais fácil é com o %w em fmt.Errorf. Wrapped errors criam uma chain lógica que podem ser jogadas em funções como errors.Is e errors.As
	} else if arg == 4 {
		return fmt.Errorf("making tea %w", ErrPower)
	}
	return nil
}

func testerror() {
	for _, i := range []int{7, 42} {
		// é idiomático fazer error check na if line
		if r, e := f(i); e != nil {
			fmt.Println("f failed:", e)
		} else {
			fmt.Println("f worked:", r)
		}
	}
	// errors.Is checka se o erro dada ou qualquer erro na cadeia dá match em um valor de erro específico. É especialmente útil em erros envelopados ou nestados, permitindo identificar errors específicos ou sentinelas em uma chain de errors

	_, err := f(42)
	var ae *argError
	// Versão mais avançada de errors.Is. Checka que um erro dado ou um da chain dá match em um tipo específico de erro e converte o valor para aquele tipo, retornando true. Se não tem match retorna false
	if errors.As(err, &ae) {
		fmt.Println(ae.arg)
		fmt.Println(ae.message)
	} else {
		fmt.Println("err doesn't match argError")
	}
}
