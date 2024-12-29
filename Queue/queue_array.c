#include <stdio.h>
#include <stdlib.h>

struct queue
{
 int size;
 int front;
 int rare;
 int *arr;
};

int empty(struct queue *ptr)
{
 if (ptr->front == ptr->rare)
 {
  return 1;
 }
 return 0;
}

int full(struct queue *ptr)
{
 if (ptr->rare == ptr->size - 1)
 {
  return 1;
 }
 return 0;
}

void enqueue(struct queue *ptr, int data)
{
 if (full(ptr))
 {
  printf("queue is full");
 }
 else
 {
  ptr->rare++;
  ptr->arr[ptr->rare] = data;
 }
}

int dequeue(struct queue *ptr)
{
 int p = 0;
 if (empty(ptr))
 {
  printf("queue is null");
 }
 else
 {
  ptr->front++;
  p = ptr->arr[ptr->front];
 }
 return p;
}

int main()
{
 struct queue ptr;
 ptr.size = 10;
 ptr.front = ptr.rare = -1;
 ptr.arr = (int *)malloc(sizeof(struct queue));
 enqueue(&ptr, 4);
 enqueue(&ptr, 6);
 printf("Dequeued element is %d\n", dequeue(&ptr));
 printf("Dequeued element is %d\n", dequeue(&ptr));
 return 0;
}

