package main

import (
	"fmt"
	"unicode/utf8"
)

// strings em go são slices read-only de bytes(outro tipo)
func teststringsrunes() {
	// go trata strings como conteiners de texto UTF-8.
	// Em outras langs, strings são caracteres, em Go, um caracter é uma rune
	// rune -> inteiro que representa um codigo Unicode

	const s = "açaí"
	// strings são equivalentes à []byte -> produz o tamanho de bytes raw para ser armazenado
	// loop abaixo vai printar os bytes raw em cada indice, são os hex de fato
	for i := 0; i < len(s); i++ {
		fmt.Printf("%x ", s[i]) //Printf n dá newline automatico
	}
	fmt.Println()

	// para contar quantas runas tem uma string usamos a biblioteca utf-8
	// alguns caracteres são representados por multiplos bytes em UTF-8, depende mt disso
	fmt.Println("Rune count:", utf8.RuneCountInString(s))

	// range decode cada rune junto com o offset dela na string
	for idx, runeValue := range s {
		fmt.Printf("%#U starts at %d\n", runeValue, idx)
	}
	// seria o equivalente a usar o DecodeRuneInString para cada indice explicitamente

	fmt.Println("\nUsing DecodeRuneInString")
	for i, w := 0, 0; i < len(s); i += w {
		runeValue, width := utf8.DecodeRuneInString(s[i:])
		fmt.Printf("%#U starts at %d\n", runeValue, i)
		w = width
		examineRune(runeValue)
	}
}

// strings em singlequotes são rune literals, podemos usar para comparação
func examineRune(r rune) {
	if r == 't' {
		fmt.Println("found tee")
	} else if r == 'ส' {
		fmt.Println("found so sua")
	}

}
