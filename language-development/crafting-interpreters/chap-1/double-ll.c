#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  struct Node *next;
  struct Node *prev;
  char *val;
} Node;

typedef struct {
  Node *head;
  Node *tail;
} DoubleLL;

void insert_back(DoubleLL *lst, const char *val) {
  Node *new_node = NULL;
  new_node = (Node *)malloc(sizeof(Node));
  if (new_node == NULL) {
    perror("Failed to allocate for node.\n");
    exit(1);
  }
  new_node->val = (char *)malloc(strlen(val) + 1);
  if (new_node->val == NULL) {
    perror("Failed to allocate for node value.\n");
    exit(1);
  }
  strcpy(new_node->val, val);
  if (lst->head == NULL) {
    new_node->prev = NULL;
    new_node->next = NULL;
    lst->head = new_node;
    lst->tail = new_node;
  } else {
    Node *current_node = lst->head;
    while (current_node->next != NULL) {
      current_node = current_node->next;
    }
    current_node->next = new_node;
    new_node->prev = current_node;
    new_node->next = NULL;
    lst->tail = new_node;
  }
}

Node *find(DoubleLL *lst, const char *val) {
  Node *current_node = lst->head;
  while (current_node != NULL) {
    if (strcmp(current_node->val, val) == 0) {
      return current_node;
    } else {
      current_node = current_node->next;
    }
  }
  return NULL;
}

void delete(DoubleLL *lst, Node *target) {
  if (target->prev != NULL) {
    target->prev->next = target->next;
  } else {
    lst->head = target->next;
  }

  if (target->next != NULL) {
    target->next->prev = target->prev;
  } else {
    lst->tail = target->prev;
  }

  free(target->val);
  free(target);
}

int delete_by_value(DoubleLL *lst, const char *val) {
  int status = 0;
  Node *to_be_deleted = find(lst, val);
  if (to_be_deleted != NULL) {
    delete(lst, to_be_deleted);
    status = 1;
  }
  return status;
}
