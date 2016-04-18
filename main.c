#include <stdio.h>
#include "ui.h"
#include "stack.h"

int main(int argc, char *argv[]) {
  /* See ui.h, ui.c for initialize and execute */
  if (initialize(argc, argv)) {
    return execute();
  }
  return 1; /* failed to initialize */
}
