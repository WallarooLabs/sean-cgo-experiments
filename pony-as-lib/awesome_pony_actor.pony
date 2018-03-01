use @ThisIsGo[None]()
use "collections"
use "time"

actor@ AwesomePonyActor
  var _total: U64 = 0

  new create() =>
    @printf[I32]("Hello from Pony actor constructor\n".cstring())
    None

  be lets_call_some_go() =>
      @printf[I32]("Hello from a Pony behavior that calls Go\n".cstring())
      let the_start = Time.nanos()
      for i in Range(0, 1_000_000) do
        @ThisIsGo()
        _total = _total + (the_end - the_start)
      end
      let the_end = Time.nanos()

      @printf[I32]("Total: %s\n".cstring(), _total.string().cstring())
