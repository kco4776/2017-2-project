#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  char *name;
  struct node *next;
} node;

int main(void) {
  node *p, *tmp;
  p = (node *)malloc(sizeof(char));
  p->name = (char *)calloc(50, sizeof(char));
  p->next = (node *)malloc(sizeof(char));
  p->next->name = (char *)calloc(50, sizeof(char));
  p->next->next = NULL;
  p->name = "string";
  p->next->name = "string2";
  tmp = p;
  printf("1:%s\n", tmp->name);
  tmp = tmp->next;
  printf("2:%s\n", tmp->name);
  tmp->next = (node *)malloc(sizeof(node));
  tmp->next->name = (char *)calloc(50, sizeof(char));
  tmp->next->next = NULL;
  tmp->next->name = "string3";
  printf("3:%s", p->next->next->name);

}
