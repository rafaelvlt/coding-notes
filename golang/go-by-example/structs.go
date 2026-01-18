package main

import "fmt"

// structs são coleções de campos tipadas -> agroupam dados juntos para formar registros
// sintaxe:
type person struct {
	name string
	age  int
}

func newPerson(name string) *person {
	p := person{name: name}
	p.age = 42
	// Go tem garbage collection, pode retornar ponteiro para uma var local, ela só vai ser cleanada quando não tiver referências para ela
	// Posso criar variáveis dentro de funções e retornar ref para elas tranquilamente, que essquisito
	return &p
}

func teststructs() {
	//sintaxe padrão, de construtor
	fmt.Println(person{"Bob", 20})

	// field omitido é zero-inited
	fmt.Println(person{name: "Fred"})

	fmt.Println(&person{name: "Ann", age: 40})

	// É idiomático fazer funções construtoras
	fmt.Println(newPerson("Jon"))

	// Acesso com dot op, também serve para ponteiros de structs, age como -> e . ao msm tempo dependendo do tipo
	s := person{"Sean", 50}

	fmt.Println(s.name)
	// structs são mutáveis, pode alterar elas tranquilamente

	// se uma struct só é usada uma vez, podemos criar uma struct anonima para isso, é chamado de table-driven tests.

	dog := struct {
		name   string
		isGood bool
	}{
		"Rex",
		true,
	}
	fmt.Println(dog)
}
