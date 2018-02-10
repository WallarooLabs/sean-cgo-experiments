package main

//extern void DoTest();
// #cgo LDFLAGS: -lpthread
import "C"
//import "fmt"

//export CallIt
func CallIt() uint64 {
  //fmt.Println("From Go")
  return 42

}

func main() {
    C.DoTest()
}
