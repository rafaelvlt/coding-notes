package main // nome do package atual, acredito q sirva para importar

// pode importar diversos packages, não precisa de ,
import (
	"fmt"
	"math/rand"	// nome do package é o que vem por ultimo
)
// pode importar multilinha, mas ter um separado é ideal

//aparentemente o tipo vem depois (?)
func add(x int, y int) int {
	return x + y
}
// dá pra omitir o tipo se tiverem vários seguidos, mas deve ter no fim 1
func sub(x, y int) int{
	return x - y
}

// suporte para retorno de multiplas funções
func swap(x, y string) (string, string){
	return y, x
}

// pode dar nome aos retornos, serve para documentar
// return sem argumentos retorna os nomeados, chamado de naked return
// Só deve ser usado em funções curtas
func split(sum int) (x, y int) {
	x = sum * 4 / 9
	y = sum - x
	return
}

// declara uma lista de variáveis, tipo sempre por ultimo
// pode estar no escopo de package aka global ou em func
var c, python, java bool

// se houver um inicializador pode omitir o tipo da variavel
var j = 1

func main() {
	// Nomes que capitalizados é exportado de um package
	// Nomes não capitalizados não são exportados
	fmt.Println("Hello world!")
	//dá append direto com espaço para cada arg
	fmt.Println("My favorite number is", rand.Intn(10)) 
	// Formata sozinho, adiciona espaço entre args e da append em \n
	fmt.Println(add(42, 13)) 
	
	// Tem unpacking com walrus operator aparentemente, mas falha com =
	a, b := swap("hello", "world")
	fmt.Println(a, b)

	teste1, teste2 := split(9)
	fmt.Println(teste1, teste2)

	var i int
	fmt.Println(i, c, python, java)

	// na verdade := é short assignement, que pode ser usado no lugar de
	// var para tipos implicitos
	// fora de func toda declaração começa com uma keyword (var, func, etc)
	// logo := não é permitido

	// tipos basicos
	// int normalmente é 32 bits em sistemas 32 bits e 64 em sistema 64 bits
	// int deve ser usado normalmente, boas praticas
	var (
		toBe bool = false
		MaxInt uint64 = 1 <<64 - 1 // int, int8, int16, até 64
		// existe o mesmo para uint, e tem uintptr ainda
		random byte = 1 << 8 - 1 // alias para uint8
		cringe rune = 1 << 16 - 1 // alias para int32 e representa unicode
		grana float32 = 0.00 // float32 e float 64, além de complex64 ou 128
	)
	fmt.Println(toBe, MaxInt, random, cringe, grana)
	
	// variaveis declaradas sem inicializadores são dadas zero-value
	// 0 para tipos numericos, falso para bool e "" para strings
}
