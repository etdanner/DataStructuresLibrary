#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  void *data;
  size_t data_size;
  struct Node *next;
} Node;

typedef struct LinkedList {
  Node *head;
  Node *tail;
  int length;
} LinkedList;

LinkedList *list_create();
void list_free(LinkedList *list);
Node *node_create(void *data, size_t data_size);
void node_free(Node *node);
#endif
