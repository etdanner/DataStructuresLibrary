#include "LinkedList.h"

LinkedList *list_create() {
  LinkedList *list = malloc(sizeof(LinkedList));
  list->head = NULL;
  list->tail = NULL;
  list->length = 0;
  return list;
}

void list_free(LinkedList *list) {
  Node *curr = list->head;
  while (curr != NULL) {
    Node *temp = curr;
    curr = curr->next;
    node_free(temp);
  }
  free(list);
}

Node *node_create(void *data, size_t data_size) {
  Node *node = malloc(sizeof(Node));
  node->data = malloc(data_size);
  memcpy(node->data, data, data_size);
  node->data_size = data_size;
  node->next = NULL;
  return node;
}

void node_free(Node *node) {
  free(node->data);
  free(node);
}
