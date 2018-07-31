package main

import "C"

import "fmt"
import "time"

var lastPrinted int64

//export InitializeGoPlugin
func InitializeGoPlugin() int {
	fmt.Println("Hello world from Go!")
	return 0
}

//export TickEvent
func TickEvent() {
	nao := time.Now().Unix()
	if nao-lastPrinted >= 1 {
		lastPrinted = nao
		fmt.Println("Tick from go!!")
	}
}

func main() {
}
