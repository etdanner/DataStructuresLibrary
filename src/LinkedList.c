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

// add to the end of the list
void append(Node *node, LinkedList *list) {
  if (list->head == NULL) {
    list->head = node;
    list->tail = node;
  } else {
    if (list->head->data_size != node->data_size) {
      fprintf(stderr, "data size doesn't match\n");
    }
    list->tail->next = node;
    list->tail = node;
  }
  list->length++;
}

// add to the front of the list
void prepend(Node *node, LinkedList *list) {
  if (list->head == NULL) {
    list->head = node;
    list->tail = node;
  } else {
    if (list->head->data_size != node->data_size) {
      fprintf(stderr, "data size doesn't match\n");
    }
    node->next = list->head;
    list->head = node;
  }
  list->length++;
}

void insert(int idx, Node *node, LinkedList *list) {
  int len = list->length;
  if (idx >= len || idx < 0) {
    fprintf(stderr, "index out of bounds\n");
  } else if (idx == 0) {
    prepend(node, list);
  } else if (idx == len - 1) {
    append(node, list);
  } else {
    Node *curr = list->head;
    if (curr->data_size != node->data_size) {
      fprintf(stderr, "data size doesn't match\n");
    }
    for (int i = 0; i < idx - 1; i++) {
      curr = curr->next;
    }
    node->next = curr->next;
    curr->next = node;
    list->length++;
  }
}

void remove(Node *node, LinkedList *list) {
  if (list->head == NULL)
    return;
  if (list->head == node) {
    list->head = list->head->next;
    if (list->head == NULL) {
      list->tail = NULL;
    }
  } else {
    Node *prev = list->head;
    while (prev->next != NULL && prev->next != node) {
      prev = prev->next;
    }
    if (prev->next == node) {
      prev->next = node->next;
      if (node->next == NULL) { // end of list
        list->tail = prev;
      }
    }
  }
  node_free(node);
  list->length--;
}
