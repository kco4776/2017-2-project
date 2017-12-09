#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* space_edit(char *string) {
  int i;
  for(i=0; *(string+i) != '\n'; i++) {
      *(string+i) = *(string+i+1);
  }
  *(string+i) = '\0';
  return string;
}

int main(void) {
  char *string;
  string = (char *)calloc(50, sizeof(char));
  printf("string:");
  fgets(string, 50, stdin);
  printf("string:%s\n", space_edit(string));
  printf("finish");
}
