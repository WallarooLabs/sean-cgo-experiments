use "collections"
use "lib:fromc"
use "time"

use @CallIt[U64]()

actor Main
  var _total: U64 = 0
  new create(e: Env) =>
    for i in Range(0, 1_000_000) do
      let the_start = Time.nanos()
      @CallIt()
      let the_end = Time.nanos()
      _total = _total + (the_end - the_start)
    end

    e.out.print(_total.string())
