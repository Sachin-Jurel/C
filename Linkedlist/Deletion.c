#include<stdio.h>
#include<stdlib.h>

struct node{
 int data;
 struct node *next;
};

void traverse(struct node *ptr){
 printf("\n-------------------------------------\n");
 while(ptr!=NULL){
  printf("Element is %d\n",ptr->data);
  ptr=ptr->next;
 }
 printf("-------------------------------------\n");
}

// case 1: Delete first node
struct node *deleteatfirst(struct node *first){
 struct node *ptr=first;
 first=first->next;
 free(ptr);
 return first;
}

// case 2: Delete last node 
struct node *deleteatEnd(struct node *first){
 struct node *p=first;
 struct node *q=first->next;
 while(q->next !=NULL){
  p=p->next;
  q=q->next;
 }
 p->next=NULL;
 free(q);
 return first;
}

// case 3: Delete indexing node
struct node *deleteatIndex(struct node *first, int index){
 struct node *p=first;
 struct node *q=first->next;
 for(int i=0; i<index-1; i++){
  p=p->next;
  q=q->next;
 }
 p->next=q->next;
 free(q);
 return first;
}

// case 4: Delete given value 
struct node *deleteatGV(struct node *first, int value){
 struct node *p=first;
 struct node *q=first->next;
 while(q->data!=value && q->next!=NULL){
  p=p->next;
  q=q->next;
 }
 if(q->data==value){
  p->next=q->next;
  free(q);
 }
 return first;
}


int main(){
 struct node *first;
 struct node *second;
 struct node *third;
 struct node *fourth;

 first=(struct node *)malloc(sizeof(struct node));
 second=(struct node *)malloc(sizeof(struct node));
 third=(struct node *)malloc(sizeof(struct node));
 fourth=(struct node *)malloc(sizeof(struct node));

 first->data= 24;
 first->next=second;

 second->data=14;
 second->next=third;

 third->data=29;
 third->next=fourth;

 fourth->data=42;
 fourth->next=NULL;

 traverse(first);

 // printf("\nDelete first node");
 // first=deleteatfirst(first);
 // traverse(first);

 // printf("\nDelete End node");
 // first=deleteatEnd(first);
 // traverse(first);

 // printf("\nDelete indexing node");
 // first=deleteatIndex(first,2);
 // traverse(first);

 // printf("\nDelete given value");
 // first=deleteatGV(first,29);
 // traverse(first);

 return 0;
}