package main

import (
	"fmt"
	"time"
)

func testswitch() {
	i := 2
	switch i {
	case 1:
		fmt.Println("one")
	case 2:
		fmt.Println("two")
		fallthrough // pode adicionar fallthrough manual, mas tem break automatico
	case 3:
		fmt.Println("Three")
	}

	switch time.Now().Weekday() {
	// age como or aparentemente
	case time.Saturday, time.Sunday:
		fmt.Println("Fim de semana")
	default:
		fmt.Println("Dia de semana")
	}
	// usado no lugar de ifs se n tiver condição
	t := time.Now()
	switch {
	case t.Hour() < 12:
		fmt.Println("Antes do meio dia")
	default:
		fmt.Println("Depois do meio dia")
	}
	// type switch, compara tipos invés de valor
	// definição de função anonima tb, guarda na var e reusa ela
	whatAmI := func(i interface{}) { //pode ser usado any no lugar de interface
		switch i.(type) {
		case bool:
			fmt.Println("bool")
		case int64:
			fmt.Println("int64")
		case int32:
			fmt.Println("int64")
		case int:
			fmt.Println("int")
		default:
			fmt.Println("another type")
		}
	}
	whatAmI(true)
	whatAmI(1)
	whatAmI("Hey")
}
