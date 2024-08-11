#include "../xsc/bool.h"
#include "./rt.h"
#include <stdio.h>

unsigned int counter;
char target, pair;

char *jump(char* code, bool backwards) {
  counter = 0;
  if (backwards) {
    target = '[';
    pair = ']';
  } else {
    target = ']';
    pair = '[';
  }
  for(;;) {
    if (backwards) --code; else ++code;
    if (*code == pair) ++counter;
    else if (*code == target) {
      if (counter == 0) return code;
      --counter;
    }
  }
}

void exec(char* code, char cells[]) {
  unsigned int pos = 0;
  while(*code != '\0') {
    switch(*code) {
      case '.': printf("%c", cells[pos]); break;
      case ',': cells[pos] = getchar(); break;
      case '+': (cells[pos])++; break;
      case '-': (cells[pos])--; break;
      case '>': ++pos; break;
      case '<': --pos; break;
      case '[': if (cells[pos] == 0) code = jump(code, false); break;
      case ']': if (cells[pos] != 0) code = jump(code, true); break;
    }
    ++code;
  }
}
