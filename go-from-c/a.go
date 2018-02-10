package main

//extern void DoTest();
// #cgo CFLAGS: -I.
// #cgo LDFLAGS: -L. -lfromc
import "C"

func main() {
    C.DoTest()
}
