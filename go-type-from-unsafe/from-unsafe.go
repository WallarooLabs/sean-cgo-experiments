package main

//import "reflect"
import "unsafe"
import "fmt"
import "reflect"

func main() {
  //x := start()
  to_ptr()
}

func start() interface{} {
  y := "hello there"
  return y
}

func to_ptr() {
  obj := "hello there"
  t := reflect.TypeOf(obj)
  //fmt.Println(t.Name())

  addr := uintptr(unsafe.Pointer(&obj))

  ptr_again := (unsafe.Pointer(addr))
  lazarus := reflect.NewAt(t, ptr_again)
  print_it(lazarus.Interface())

  //print_it(str_it)
}

func print_it(data interface{}) {
  input := *(data.(*string))
  fmt.Println(input)
}
