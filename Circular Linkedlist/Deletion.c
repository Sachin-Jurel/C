#include<stdio.h>
#include<stdlib.h>

struct node{
 int data;
 struct node *next;
};

// traverse 
void traverse(struct node *first){
 struct node *ptr=first;
 printf("\n**************************************\n");
 do{
  printf("Element is %d\n",ptr->data);
  ptr=ptr->next;
 }while(ptr!=first);
 printf("**************************************\n");
}


// DELETION

// case 1: Delete a first node
struct node *deleteatFirst(struct node *first){
 struct node *p=first->next;
 while(p->next!=first){
  p=p->next;
 }
 p->next=first->next;
 free(first);
 return (p->next);
}

// case 2: Delete a last node 
struct node *deleteatEnd(struct node *first){
 struct node *p=first;
 struct node *q=p->next;
 while(q->next!=first){
  p=p->next;
  q=q->next;
 }
 p->next=q->next;
 free(q);
 return first;
}

// case 3: Delete a Indexing node 
struct node *deleteatIndex(struct node *first, int index){
 struct node *p=first;
 struct node *q=p->next;
 for(int i=0; i<index-1; i++){
  p=p->next;
  q=q->next;
 }
 p->next=q->next;
 free(q);
 return first;
}

// case 4: Delete a given node 
struct node *deleteatGV(struct node *first, int value){
 struct node *p=first;
 struct node *q=p->next;
 while(q->data!=value && q->next!=NULL){
  p=p->next;
  q=q->next;
 }
 if(q->data==value){
  p->next=q->next;
  free(q);
 }
 else{
  printf("given value is not found\n");
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

 first->data=23;
 first->next=second;

 second->data=19;
 second->next=third;

 third->data=45;
 third->next=fourth;

 fourth->data=12;
 fourth->next=first;

 traverse(first);


// DELETION........................................

 // printf("\n After delete a first node");
 // first=deleteatFirst(first);
 // traverse(first);

 // printf("\n After delete a last node");
 // deleteatEnd(first);
 // traverse(first);

 // printf("\n After delete a Indexing node");
 // deleteatIndex(first,2);
 // traverse(first);

 // printf("\n After delete a Given value");
 // deleteatGV(first,19);
 // traverse(first);

 return 0;
}