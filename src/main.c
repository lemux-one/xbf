#include <stdio.h>

#define CELLS_COUNT 1024

char *findClosing(char* code) {
  int counter = 0;
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
  int counter = 0;
  for(;;) {
    --code;
    if (*code == ']') ++counter;
    else if (*code == '[') {
      if (counter == 0) return code;
      --counter;
    }
  }
}

int main(int argc, char *args[]) {
  if (argc != 2) {
    puts("Usage: xbf [code]");
    return 1;
  }

  char *code = args[1];
  char cells[CELLS_COUNT] = {0};
  int pos = 0;

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
  return 0;
}

