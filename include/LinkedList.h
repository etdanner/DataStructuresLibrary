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

// note: all pointer manipulation must go through the struct field
LinkedList *list_create();
void list_free(LinkedList *list);
Node *node_create(void *data, size_t data_size);
void node_free(Node *node);
void append(Node *node, LinkedList *list);
void prepend(Node *node, LinkedList *list);
void insert(int idx, Node *node, LinkedList *list);
void remove(Node *node, LinkedList *list);
void index_remove(int idx, LinkedList *list);
#endif
