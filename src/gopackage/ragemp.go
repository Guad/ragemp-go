package main

//#include "wrap_ragemp.hxx"
import "C"

import "unsafe"

type IMultiplayer interface {
	getWorld() IWorld
}

type Multiplayer struct {
	classPtr unsafe.Pointer
}

func (mp *Multiplayer) getWorld() IWorld {
	ptr := C.getWorld(mp.classPtr)
	w := World{
		ptr,
	}

	return w
}

type IWorld interface {
	setTime(hour, minute, second int)
	getTime() (hour, minute, second int)
}

type World struct {
	classPtr unsafe.Pointer
}

func (w World) setTime(hour, minute, second int) {

}

func (w World) getTime() (hour, minute, second int) {
	return 0, 0, 0
}

func main() {}
