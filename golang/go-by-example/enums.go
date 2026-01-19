package main

import (
	"fmt"
)

// go não tem uma keyword para enum mas são fáceis de implementar usando idiomas da linguagem

type ServerState int // typedef para int

const (
	StateIdle ServerState = iota
	StateConnected
	StateError
	StateRetrying
)

// implementando a fmt.Stringer() interface, valores de serverState podem ser printados ou convertidos para strings como nessa implementação de interface
var stateName = map[ServerState]string{
	StateIdle:      "idle",
	StateConnected: "connected",
	StateError:     "error",
	StateRetrying:  "retrying",
}

// seria ruim se tivesse mts valores, nesse caso poderiamos usar stringer tool em conjunto com go:generate para automatizar o processo
func (ss ServerState) String() string {
	return stateName[ss]
}

// Caso tenhamos um valor de tipo int, não podemos passar pois o compiler reclamará de mismatch de tipo, isso é uma type safety em compile time para enums
func transition(s ServerState) ServerState {
	switch s {
	case StateIdle:
		return StateConnected
	case StateConnected, StateRetrying:
		return StateIdle
	case StateError:
		return StateError
	default:
		panic(fmt.Errorf("unknown state: %s", s))
	}
}

func testeenum() {
	ns := transition(StateIdle)
	fmt.Println(ns)

	ns2 := transition(ns)
	fmt.Println(ns2)
}
