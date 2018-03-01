#include "pony.h"
#include "pony-as-lib.h"
#include <stdio.h>
#include "_cgo_export.h"

void start_pony() {
  printf("Hello from C\n");

  char* dummy_args[] = { "", NULL };

  int argc = sizeof(dummy_args)/sizeof(dummy_args[0]) - 1;
  char **argv = dummy_args;

  pony_init(argc, argv);

  int exit_code;
  pony_start(true, &exit_code, NULL);

  AwesomePonyActor* x = AwesomePonyActor_Alloc();
  AwesomePonyActor_tag_create_o__send(x);
  AwesomePonyActor_tag_lets_call_some_go_o__send(x);

  pony_stop();
}

