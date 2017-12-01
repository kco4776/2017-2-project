#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct location {
  int x;
  int y;
  int z;
} location;

int main(void) {
  location *p;
  p = (location *)malloc(sizeof(location));

  p->x = 1;
  p->y = 2;
  p->z = 3;

  printf("%d %d %d", p->x, p->y, p->z);

  return 0;
}
