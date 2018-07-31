package ragemp

import "C"

type IWorld interface {
	setTime(hour, minute, second int)
	getTime() (hour, minute, second int)
}

type World struct {
}

func (w *World) setTime(hour, minute, second int) {

}

func (w *World) getTime() (hour, minute, second int) {
	return 0, 0, 0
}
