package main

// #cgo LDFLAGS: ${SRCDIR}/libpony-as-lib.a
// #cgo LDFLAGS: /Users/sean/code/ponylang/ponyc/build/release/libponyrt.a
// #cgo CFLAGS: -I.
// extern void start_pony();
import "C"

//export ThisIsGo
func ThisIsGo() uint64 { return 42 }

func main() {
  C.start_pony()
}
