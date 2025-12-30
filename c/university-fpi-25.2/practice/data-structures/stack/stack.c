#include "pilha.h"

void initStack(Pilha* p, int capacity){
  p->items = (int *) malloc(sizeof(int) * capacity);
  if (p->items == NULL){
    printf("Initialization error\n");
    exit(1);
  }
  p->numElems = -1;
  p->capacity = capacity;
}

bool isEmpty(Pilha* p){
  return (p->numElems == -1);
}

int top(Pilha* p){
  if (!isEmpty(p)){
    return p->items[p->numElems];
  }
  else{
    printf("Stack is empty.\n");
    return -1;
  }
}

void push(Pilha* p, int v){
  p->numElems++;
  if (p->numElems >= p->capacity){
    p->capacity *= 2;
    int* temp = (int*) realloc(p->items, sizeof(int) * p->capacity);
    if (temp == NULL){
      printf("Realocation failed, exiting.\n");
      freeStack(p);
      exit(1);
    } 
    p->items = temp; 
  }
  p->items[p->numElems] = v;
}


int pop(Pilha* p){
  if (isEmpty(p)){
    printf("Stack underflow.\n");
    return -1;
  }
  else{
    return p->items[(p->numElems)--];
  }
}

void freeStack(Pilha* p){
  free(p->items);
}
