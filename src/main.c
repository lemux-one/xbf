#include <stdio.h>
#include <stdlib.h>
#include "./core/rt.h"

#define CELLS_COUNT 1024

int main(int argc, char *args[]) {
  if (argc != 2) {
    puts("Usage: xbf [code]");
    return 1;
  }

  char *code = args[1];
  char cells[CELLS_COUNT] = {0};
  exec(code, cells);

  exit(EXIT_SUCCESS);
}
