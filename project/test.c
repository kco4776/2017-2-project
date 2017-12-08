#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char *names;
  names = (char *)calloc(100, sizeof(char));
  char *name;
  name = (char *)calloc(50, sizeof(char));
  printf("입력:");
  fgets(names, 100, stdin);
  printf("names:%s\n", names);
  name = strtok(names, ",");
  printf("%s\n", name);

  return 0;
}
