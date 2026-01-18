package main

// pode ser blocado ou separado, é melhor blocado
import (
	"fmt"
	"math"
)

// const de chars, string, boolean e tipos numericos
const s string = "constant"

// const numericas n tem tipo explicito ate serem convertidas explicitamente

func main() {
	// tipos e vlaores
	fmt.Println("go" + "lang") // str com op de concat
	fmt.Println("1+1 = ", 1+1) // Println formata auto

	// ops booleanos padrões
	fmt.Println(true && false)
	fmt.Println(true || false)
	fmt.Println(!true)

	// var -> declara 1+ variaveis, pode inferir tipo
	// vars declaradas sem init são zero-inited
	var a = "initial"
	var b, c int = 1, 2 // unpacking por padrão
	// := pode ser usado para encurtar a declaração e init
	// só pode ser usado dentro de função, fora sempre tem q começar com keyword
	f := "teste"
	fmt.Println(a, b, c, f) // concatena cada arg com espaço de separador, faz \n automatico no fim

	const d = 3e20 / 5000
	// converte explicitamente no primeiro e no segundo vira float64
	fmt.Println(int64(d), math.Sin(d))

	// for é a unica estrutura de loop em go, alguns exemplos
	i := 1
	// single condition
	for i <= 3 {
		fmt.Println(i)
		i = i + 1
	}
	//initial condition afeter loop, a lsp criticou e prefere range
	for j := 0; j < 3; j++ {
		fmt.Println(j)
	}
	// for range, python syntax
	for i := range 3 {
		fmt.Println("range", i)
	}
	// loop infinito, basta omitir a condição
	for {
		fmt.Println("loop")
		break
	}
	// continue!
	for n := range 6 {
		if n%2 == 0 {
			continue
		}
		fmt.Println(n)
	}

	control()
	testswitch()
	testarrays()
	testslices()
	mapsteste()
	testefuncoes()
	testrange()
	testpointers()
	teststringsrunes()
	teststructs()
}
