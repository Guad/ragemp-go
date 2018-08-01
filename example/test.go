package main

import (
	"C"
	"swig/rage"

	"fmt"
	"time"
	"unsafe"
)

var lastPrinted int64

//export InitializeGoPlugin
func InitializeGoPlugin(mp unsafe.Pointer) int {
	fmt.Println("Hello world from Go!")

	fmt.Printf("Pointer: %v\n", mp)

	//recast := (*rage.IMultiplayer)(mp)

	safemp := rage.IMultiplayerFromPointer(uintptr(mp))
	world := safemp.GetWorld()

	trafficLights := world.GetTrafficLightsState()

	fmt.Println("Traffic lights: ", trafficLights)

	world.SetTrafficLightsState(2)

	trafficLights = world.GetTrafficLightsState()

	fmt.Println("Traffic lights 2: ", trafficLights)

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

func main() {}
