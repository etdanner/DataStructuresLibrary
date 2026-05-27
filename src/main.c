#include "LinkedList.h"
#include <stdio.h>

int main() {
  LinkedList *list = list_create(sizeof(int));

  int x = 42;
  Node *n = node_create(&x, sizeof(int));

  list_free(list);
  return 0;
}
