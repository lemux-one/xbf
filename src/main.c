#include <stdio.h>

#define CELLS_COUNT 1024

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
      default: printf("ERR: '%c'", *code);
    }
    code++;
  }
  return 0;
}

