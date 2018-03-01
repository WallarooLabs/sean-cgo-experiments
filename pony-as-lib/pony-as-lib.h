#ifndef pony_pony-as-lib_h
#define pony_pony-as-lib_h

/* This is an auto-generated header file. Do not edit. */

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _MSC_VER
typedef struct __int128_t { uint64_t low; int64_t high; } __int128_t;
typedef struct __uint128_t { uint64_t low; uint64_t high; } __uint128_t;
#endif

/*
Produces `[min, max)` with a step of `inc` for any `Number` type.

```pony
// iterating with for-loop
for i in Range(0, 10) do
  env.out.print(i.string())
end

// iterating over Range of U8 with while-loop
let range = Range[U8](5, 100, 5)
while range.has_next() do
  handle_u8(range.next())
end
```

Supports `min` being smaller than `max` with negative `inc`
but only for signed integer types and floats:

```pony
var previous = 11
for left in Range[I64](10, -5, -1) do
  if not (left < previous) then
    error
  end
  previous = left
end
```

If the `step` is not moving `min` towards `max` or if it is `0`,
the Range is considered infinite and iterating over it
will never terminate:

```pony
let infinite_range1 = Range(0, 1, 0)
infinite_range1.is_infinite() == true

let infinite_range2 = Range[I8](0, 10, -1)
for _ in infinite_range2 do
  env.out.print("will this ever end?")
  env.err.print("no, never!")
end
```

When using `Range` with  floating point types (`F32` and `F64`)
`inc` steps < 1.0 are possible. If any of the arguments contains
`NaN`, `+Inf` or `-Inf` the range is considered infinite as operations on
any of them won't move `min` towards `max`.
The actual values produced by such a `Range` are determined by what IEEE 754
defines as the result of `min` + `inc`:

```pony
for and_a_half in Range[F64](0.5, 100) do
  handle_half(and_a_half)
end

// this Range will produce 0 at first, then infinitely NaN
let nan: F64 = F64(0) / F64(0)
for what_am_i in Range[F64](0, 1000, nan) do
  wild_guess(what_am_i)
end
```

*/
typedef struct collections_Range_USize_val collections_Range_USize_val;

/*
A collection of ways to fetch the current time.
*/
typedef struct time_Time time_Time;

typedef struct AwesomePonyActor AwesomePonyActor;

typedef struct None None;

/*
  A String is an ordered collection of characters.

  Strings don't specify an encoding.

  Example usage of some common String methods:

```pony
actor Main
  new create(env: Env) =>
    try
      // construct a new string
      let str = "Hello"

      // make an uppercased version
      let str_upper = str.upper()
      // make a reversed version
      let str_reversed = str.reverse()

      // add " world" to the end of our original string
      let str_new = str.add(" world")

      // count occurrences of letter "l"
      let count = str_new.count("l")

      // find first occurrence of letter "w"
      let first_w = str_new.find("w")
      // find first occurrence of letter "d"
      let first_d = str_new.find("d")

      // get substring capturing "world"
      let substr = str_new.substring(first_w, first_d+1)
      // clone substring
      let substr_clone = substr.clone()

      // print our substr
      env.out.print(consume substr)
  end
```
*/
typedef struct String String;

/*
Worker type providing simple to string conversions for numbers.
*/
typedef struct _ToString _ToString;

/*
A Pointer[A] is a raw memory pointer. It has no descriptor and thus can't be
included in a union or intersection, or be a subtype of any interface. Most
functions on a Pointer[A] are private to maintain memory safety.
*/
/* Allocate a collections_Range_USize_val without initialising it. */
collections_Range_USize_val* collections_Range_USize_val_Alloc();

size_t collections_Range_USize_val_ref_next_Z(collections_Range_USize_val* self);

bool collections_Range_USize_val_ref_has_next_b(collections_Range_USize_val* self);

bool collections_Range_USize_val_val_has_next_b(collections_Range_USize_val* self);

bool collections_Range_USize_val_box_has_next_b(collections_Range_USize_val* self);

collections_Range_USize_val* collections_Range_USize_val_ref_create_ZZZo(collections_Range_USize_val* self, size_t min, size_t max, size_t inc);

/* Allocate a time_Time without initialising it. */
time_Time* time_Time_Alloc();

/*
Monotonic unadjusted nanoseconds.
*/
uint64_t time_Time_box_nanos_W(time_Time* self);

/*
Monotonic unadjusted nanoseconds.
*/
uint64_t time_Time_val_nanos_W(time_Time* self);

time_Time* time_Time_val_create_o(time_Time* self);

/* Allocate a AwesomePonyActor without initialising it. */
AwesomePonyActor* AwesomePonyActor_Alloc();

None* AwesomePonyActor_tag_lets_call_some_go_o__send(AwesomePonyActor* self);

AwesomePonyActor* AwesomePonyActor_tag_create_o__send(AwesomePonyActor* self);

bool U8_val_eq_Cb(char self, char y);

bool U8_box_eq_Cb(char self, char y);

char U8_val_create_CC(char self, char value);

/* Allocate a None without initialising it. */
None* None_Alloc();

None* None_val_create_o(None* self);

size_t U64_box_usize_Z(uint64_t self);

size_t U64_val_usize_Z(uint64_t self);

uint64_t U64_box_div_WW(uint64_t self, uint64_t y);

uint64_t U64_val_div_WW(uint64_t self, uint64_t y);

uint64_t U64_val_u64_W(uint64_t self);

uint64_t U64_box_u64_W(uint64_t self);

bool U64_box_ne_Wb(uint64_t self, uint64_t y);

bool U64_val_ne_Wb(uint64_t self, uint64_t y);

String* U64_val_string_o(uint64_t self);

String* U64_box_string_o(uint64_t self);

uint64_t U64_box_mul_WW(uint64_t self, uint64_t y);

uint64_t U64_val_mul_WW(uint64_t self, uint64_t y);

bool U64_val_eq_Wb(uint64_t self, uint64_t y);

bool U64_box_eq_Wb(uint64_t self, uint64_t y);

uint64_t U64_val_create_WW(uint64_t self, uint64_t value);

uint64_t U64_box_sub_WW(uint64_t self, uint64_t y);

uint64_t U64_val_sub_WW(uint64_t self, uint64_t y);

uint64_t U64_box_add_WW(uint64_t self, uint64_t y);

uint64_t U64_val_add_WW(uint64_t self, uint64_t y);

/* Allocate a String without initialising it. */
String* String_Alloc();

/*
Returns a C compatible pointer to a null-terminated version of the
string, safe to pass to an FFI function that doesn't accept a size
argument, expecting a null-terminator. If the underlying string
is already null terminated, this is returned; otherwise the string
is copied into a new, null-terminated allocation.
*/
char* String_box_cstring_o(String* self);

/*
Returns a C compatible pointer to a null-terminated version of the
string, safe to pass to an FFI function that doesn't accept a size
argument, expecting a null-terminator. If the underlying string
is already null terminated, this is returned; otherwise the string
is copied into a new, null-terminated allocation.
*/
char* String_val_cstring_o(String* self);

/*
Returns a C compatible pointer to a null-terminated version of the
string, safe to pass to an FFI function that doesn't accept a size
argument, expecting a null-terminator. If the underlying string
is already null terminated, this is returned; otherwise the string
is copied into a new, null-terminated allocation.
*/
char* String_ref_cstring_o(String* self);

/*
Reverses the byte order in the string. This needs to be changed to handle
UTF-8 correctly.
*/
None* String_ref_reverse_in_place_o(String* self);

/*
Unsafe update, used internally.
*/
char String_ref__set_ZCC(String* self, size_t i, char value);

/*
Add a byte to the end of the string.
*/
None* String_ref_push_Co(String* self, char value);

/*
An empty string. Enough space for len bytes is reserved.
*/
String* String_ref_create_Zo(String* self, size_t len);

/*
Reserve space for len bytes. An additional byte will be reserved for the
null terminator.
*/
None* String_ref_reserve_Zo(String* self, size_t len);

/*
Return true if the string is null-terminated and safe to pass to an FFI
function that doesn't accept a size argument, expecting a null-terminator.
This method checks that there is a null byte just after the final position
of populated bytes in the string, but does not check for other null bytes
which may be present earlier in the content of the string.
If you need a null-terminated copy of this string, use the clone method.
*/
bool String_val_is_null_terminated_b(String* self);

/*
Return true if the string is null-terminated and safe to pass to an FFI
function that doesn't accept a size argument, expecting a null-terminator.
This method checks that there is a null byte just after the final position
of populated bytes in the string, but does not check for other null bytes
which may be present earlier in the content of the string.
If you need a null-terminated copy of this string, use the clone method.
*/
bool String_ref_is_null_terminated_b(String* self);

/*
Return true if the string is null-terminated and safe to pass to an FFI
function that doesn't accept a size argument, expecting a null-terminator.
This method checks that there is a null byte just after the final position
of populated bytes in the string, but does not check for other null bytes
which may be present earlier in the content of the string.
If you need a null-terminated copy of this string, use the clone method.
*/
bool String_box_is_null_terminated_b(String* self);

/* Allocate a _ToString without initialising it. */
_ToString* _ToString_Alloc();

String* _ToString_val__u64_Wbo(_ToString* self, uint64_t x, bool neg);

String* _ToString_box__u64_Wbo(_ToString* self, uint64_t x, bool neg);

_ToString* _ToString_val_create_o(_ToString* self);

bool Bool_box_op_and_bb(bool self, bool y);

bool Bool_val_op_and_bb(bool self, bool y);

bool Bool_val_op_or_bb(bool self, bool y);

bool Bool_box_op_or_bb(bool self, bool y);

bool Bool_val_create_bb(bool self, bool from);

bool USize_box_lt_Zb(size_t self, size_t y);

bool USize_val_lt_Zb(size_t self, size_t y);

size_t USize_val_div_ZZ(size_t self, size_t y);

size_t USize_box_div_ZZ(size_t self, size_t y);

size_t USize_val_clz_Z(size_t self);

size_t USize_box_clz_Z(size_t self);

bool USize_box_gt_Zb(size_t self, size_t y);

bool USize_val_gt_Zb(size_t self, size_t y);

bool USize_box_ne_Zb(size_t self, size_t y);

bool USize_val_ne_Zb(size_t self, size_t y);

bool USize_box_le_Zb(size_t self, size_t y);

bool USize_val_le_Zb(size_t self, size_t y);

size_t USize_val_min_ZZ(size_t self, size_t y);

size_t USize_box_min_ZZ(size_t self, size_t y);

size_t USize_val_next_pow2_Z(size_t self);

size_t USize_box_next_pow2_Z(size_t self);

size_t USize_val_shl_ZZ(size_t self, size_t y);

size_t USize_box_shl_ZZ(size_t self, size_t y);

bool USize_box_eq_Zb(size_t self, size_t y);

bool USize_val_eq_Zb(size_t self, size_t y);

size_t USize_val_create_ZZ(size_t self, size_t value);

size_t USize_val_sub_ZZ(size_t self, size_t y);

size_t USize_box_sub_ZZ(size_t self, size_t y);

size_t USize_val_bitwidth_Z(size_t self);

size_t USize_box_bitwidth_Z(size_t self);

size_t USize_val_add_ZZ(size_t self, size_t y);

size_t USize_box_add_ZZ(size_t self, size_t y);

size_t USize_val_max_value_Z(size_t self);

/*
Copy n elements from this to that.
*/
char* Pointer_U8_val_box__copy_to_oZo(char* self, char* that, size_t n);

/*
Copy n elements from this to that.
*/
char* Pointer_U8_val_ref__copy_to_oZo(char* self, char* that, size_t n);

/*
Copy n elements from this to that.
*/
char* Pointer_U8_val_val__copy_to_oZo(char* self, char* that, size_t n);

/*
Retrieve index i.
*/
char Pointer_U8_val_ref__apply_ZC(char* self, size_t i);

/*
Retrieve index i.
*/
char Pointer_U8_val_box__apply_ZC(char* self, size_t i);

/*
Retrieve index i.
*/
char Pointer_U8_val_val__apply_ZC(char* self, size_t i);

/*
Keep the contents, but reserve space for len instances of A.
*/
char* Pointer_U8_val_ref__realloc_Zo(char* self, size_t len);

/*
Set index i and return the previous value.
*/
char Pointer_U8_val_ref__update_ZCC(char* self, size_t i, char value);

/*
Space for len instances of A.
*/
char* Pointer_U8_val_ref__alloc_Zo(char* self, size_t len);

/*
Unsafe change in reference capability.
*/
char* Pointer_U8_val_val__unsafe_o(char* self);

/*
Unsafe change in reference capability.
*/
char* Pointer_U8_val_tag__unsafe_o(char* self);

/*
Unsafe change in reference capability.
*/
char* Pointer_U8_val_ref__unsafe_o(char* self);

/*
Unsafe change in reference capability.
*/
char* Pointer_U8_val_box__unsafe_o(char* self);


#ifdef __cplusplus
}
#endif

#endif
