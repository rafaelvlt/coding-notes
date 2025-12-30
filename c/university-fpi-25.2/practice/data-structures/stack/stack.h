#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
  int* items;
  int numElems;
  int capacity;
} Pilha;

void initStack(Pilha* p, int capacity);
bool isEmpty(Pilha* p);
void push(Pilha* p, int v);
int pop(Pilha* p);
int top(Pilha* p);
void freeStack(Pilha* p);

#endif

