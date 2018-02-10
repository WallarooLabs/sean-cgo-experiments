package main

import (
  "C"
  wa "wallarooapi"
    // other imports
    // ...
)

//export ApplicationSetup
func ApplicationSetup() *C.char {
  wa.Serialize = Serialize
  wa.Deserialize = Deserialize
    // create the application pipelines
    // ...
  json := application.ToJson()
  return C.CString(json)
}

// define the application classes
// ..

func Serialize(c interface{}) []byte {
    // define your serialization strategy
    // ...
}

func Deserialize(buff []byte) interface{} {
    // define your deserialization strategy
    // ..
}

func main() {}
