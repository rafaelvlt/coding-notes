package main

import (
	"fmt"
	"math"
)

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

// go suporta methods em structs também, por exemplo abaixo:
type rect struct {
	width, height int
}

// area method tem um receiver do tipo r *rect
func (r *rect) area() int {
	return r.width * r.height
}

func (r rect) perim() int {
	return 2*r.width + 2*r.height
}

// Outra feature em Go são interfaces, que são coleções nomeadas de assinatura de métodos

type geometry interface {
	area() float64
	perim() float64
}

type rectf struct {
	width, height float64
}

type circle struct {
	radius float64
}

func (r rectf) area() float64 {
	return r.width * r.height
}
func (r rectf) perim() float64 {
	return 2*r.width + 2*r.height
}

func (c circle) area() float64 {
	return math.Pi * c.radius * c.radius
}

func (c circle) perim() float64 {
	return 2 * math.Pi * c.radius
}

// Para implementar uma interface, é necessário implementar todos os métodos dela, aqui implementamos em rectf e em circle

// podemos passar tanto rectf quanto circle q essa função é ok
// pq os dois implementam a interface com sucesso
// mesmo que tenham atributos diferentes etc
func measure(g geometry) {
	fmt.Println(g)
	fmt.Println(g.perim())
	fmt.Println(g.perim())
}

// podemos chamar diretamente na interface sem problemas

func detectCircle(g geometry) {
	// isso é um type assertion para saber o tipo da interface em runtime, outro meio seria com um type switch como visto antes
	if c, ok := g.(circle); ok {
		fmt.Println("Circle with radius", c.radius)
	}
}

// Lembrando que todos metódos devem ser implementados para ser uma implementação de interface válida

// Outra feature de go é o embedding de structs e interfaces para expressar uma forma de compor tipos mlehores.

// Um conteiner dá embed em uma base. Uma embedding parece um field sem um nome

type base struct {
	num int
}

func (b base) describe() string {
	return fmt.Sprintf("Base with num=%v", b.num)
}

type container struct {
	base
	str string
}

func testembeddings() {
	// quando criamos structs com literals, temos que dar init na embedded explicitamente. o nome do tipo serve como field name
	co := container{
		base: base{
			num: 1,
		},
		str: "some name",
	}

	//podemos acessar os campos da base diretamente em co com co.num por exemplo

	fmt.Printf("co={num: %v, str: %v}\n", co.num, co.str)

	//podemos também dar o caminho inteiro como abaixo
	fmt.Printf("co={num: %v\n", co.base.num)

	// como o container tem uma base embedded, métodos que se aplicam a base também se aplicam ao conteiner
	fmt.Println("describe:", co.describe())

	// Usar structs embedding para dar implementações de interfaces para outras structs é bem comum, por exemplo
	type describer interface {
		describe() string
	}

	var d describer = co
	fmt.Println("describer:", d.describe())
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

	r := rect{width: 10, height: 5}

	// go automaticamente dá handle em conversão entre valores e ponteiros para métodos
	fmt.Println("area: ", r.area())
	fmt.Println("perim: ", r.perim())
	// devido ao handle, frequentemente adicionar receivers como pointers para evitar fazer copia por valor/permitir um método mutar a struct receptora

	rf := rectf{width: 3.0, height: 4.0}
	c := circle{radius: 5}

	measure(rf)
	measure(c)

	detectCircle(rf)
	detectCircle(c)

	testembeddings()
}
