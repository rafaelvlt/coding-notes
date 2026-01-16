package main

import (
	"fmt"
	"maps"
)

// map é um associateve data type aka hashes/dict
func mapsteste() {
	// sintaxe de criação de map vazio
	// m := make(map[key-type]val-type)
	m := make(map[string]int)

	m["k1"] = 7 // cria novo key-val pair
	// se for dado get na key e ela n existir reteorna o zero val do tipo

	v3 := m["k3"]
	fmt.Println("not existing key:", v3)
	// len returns the number of kv pairs

	// delete remove kv pairs from a map
	delete(m, "k1")

	// clear remove all kv pairs
	clear(m)

	// tem um tipo de valor de retorno opcional que diz se achou a key ou n, ajuda em ver se existe e tem zero val ou n existe
	_, found := m["k2"]
	fmt.Println(found)
	// init de map direto
	n := map[string]int{"foo": 1, "bar": 2}

	n2 := map[string]int{"foo": 1, "bar": 2}
	if maps.Equal(n, n2) {
		fmt.Println("n == n2")
	}
	// mapas são printados em formato [k:v k:v] se colocados em println
}
