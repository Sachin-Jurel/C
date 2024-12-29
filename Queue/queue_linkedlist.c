#include<stdio.h>
#include<stdlib.h>

struct node {
 int data;
 struct node *next;
};

struct node *front=NULL;
struct node *rear=NULL;

void enqueue(struct node *q,int n){
 struct node *new=(struct  node *)malloc(sizeof(struct node));
 new->data=n;
 new->next=NULL;
 if(front==NULL){
  front=rear=new;
 }
 else{
  rear->next=new;
  rear=new;
 }
}

struct node *traverse(struct node *q){
 while(q!=NULL){
  printf("Element is %d\n", q->data);
  q=q->next;
 }
 return q;
}

int dequeue(){
 int data=-1;
 struct node *a=front;
 if(front==NULL){
  printf("Queue is empty");
 }
 else{
  front=front->next;
  data=a->data;
 }
 return data;
}

int main(){
 struct node *q;
 enqueue(q,4);
 enqueue(q,6);
 traverse(front);
 printf("\nQueue after deletion\n");
 dequeue();
 traverse(front);
 return 0;
}