#include "./rt.h"
#include <stdio.h>

unsigned int counter;

char *findClosing(char* code) {
  counter = 0;
  for(;;) {
    ++code;
    if (*code == '[') ++counter;
    else if (*code == ']') {
      if (counter == 0) return code;
      --counter;
    }
  }
}

char *findOpening(char* code) {
  counter = 0;
  for(;;) {
    --code;
    if (*code == ']') ++counter;
    else if (*code == '[') {
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
      case '[': if (cells[pos] == 0) code = findClosing(code); break;
      case ']': if (cells[pos] != 0) code = findOpening(code); break;
      default: printf("ERR: '%c'", *code);
    }
    ++code;
  }
}
