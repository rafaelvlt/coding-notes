package main

import "fmt"

// range iterates over elements in built in structs too
func testrange() {
	nums := []int{2, 3, 4}
	sum := 0
	//first return is the index, second the value
	for _, num := range nums {
		sum += num
	}
	fmt.Println("sum:", sum)

	for i, num := range nums {
		if num == 3 {
			fmt.Println("index:", i)
		}
	}

	// em maps, retorna key, val
	kvs := map[string]string{"a": "apple", "b": "banana"}
	for k, v := range kvs {
		// omg existe printf também
		fmt.Printf("%s -> %s\n", k, v)
	}
	//range pode so iterar sob as keys do map se quiser, segundo é opcional

	// range itera sobre cada codigo unicode da string e indice
	for i, c := range "go" {
		fmt.Println(i, c)
	}
}
