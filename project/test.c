#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char *string;
  char *tok;
  char *str;
  string = (char *)calloc(100, sizeof(char));
  tok = (char *)calloc(100, sizeof(char));
  str = (char *)calloc(100, sizeof(char));
  fgets(string, 100, stdin);
  tok = strtok(string, ",");
  printf("%s\n", tok);
  while (tok = strtok(NULL, ",")) {
    tok = strtok(NULL, ",");
    printf("%s\n", tok);
  }
}
