#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
  int *items;
  int front;
  int rear;
  int size;
  int capacity;
} Queue;

void initQueue(Queue* q, int c);
void enqueue(Queue* q, int v);
int dequeue(Queue* q);
int front(Queue* q);
bool isEmpty(Queue* q);
void freeQueue(Queue* q);



void initQueue(Queue* q, int c){
  q->items = (int *)malloc(sizeof(int) * c);
  if (q->items == NULL){
    printf("Failed to allocate for queue. ending program\n");
    exit(1);
  }
  q->front = -1;
  q->rear = -1;
  q->size = 0;
  q->capacity = c;
}

void enqueue(Queue* q, int v){
  if (q->size == q->capacity - 1){
    q->capacity *= 2;
    int* temp = (int *)realloc(q->items, sizeof(int) * q->capacity);
    if (temp == NULL){
      printf("Falied to reallocate for queue. ending program\n");
      free(q->items);
      exit(1);
    }
    if (q->front == -1){
      q->front = 0;
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->items[q->rear] = v;
    q->size++;
  }
}

int dequeue(Queue* q){
  if (q->size == 0){
    printf("Queue underflow.\n");
    return -1;
  }
  int value = q->items[q->front];
  if (q->front == q->rear){
    q->front = -1;
    q->rear = -1;
  }
  else{
    q->front = (q->front + 1) % q->capacity;
  }
  q->size--;
  return value;
}

bool isEmpty(Queue* q){
  return q->size == 0;
}

int front(Queue* q){
  if (isEmpty(q)){
    printf("There's no front, the queue is empty.\n");
    return -1;
  }
  return q->items[q->front];
}

void freeQueue(Queue* q){
  free(q->items);
}
