#include<stdio.h>
#include<stdlib.h>

struct node{
 int data;
 struct node *prev;
 struct node *next;
};

// traverse
void traverse(struct node *first, struct node *fourth){
 printf("\nTraverse in forward direction\n");
 while(first != NULL){
  printf("Element is %d\n", first->data);
  first=first->next;
 }
 printf("\nTraverse in backward direction\n");
 while(fourth != NULL){
  printf("Element is %d\n", fourth->data);
  fourth=fourth->prev;
 }
}


// INSERTION

// case 1: Insert a node at first position
struct node *insertatFirst(struct node *first, int data){
 struct node *ptr=(struct node *)malloc(sizeof(struct node));
 ptr->data=data;
 ptr->prev=first->prev;
 first->prev=ptr;
 ptr->next=first;
 first=ptr;
 return first;
}

// case 2: Insert a node at last 
struct node *insertatEnd(struct node *first, int data){
 struct node *ptr=(struct node *)malloc(sizeof(struct node));
 ptr->data=data;
 struct node *p=first;
 while(p->next != NULL){
  p=p->next;
 }
 ptr->prev=p;
 p->next=ptr;
 ptr->next=NULL;
 return ptr;
}

// case 3: Insertion a node at given indexing
struct node *insertatIndex(struct node *first, int data, int index){
 struct node *ptr=(struct node *)malloc(sizeof(struct node));
 ptr->data=data;
 struct node *p=first;
 struct node *q=first->next;
 for(int i=0; i<index-1 ; i++){
  p=p->next;
  q=q->next;
 }
 ptr->prev=p;
 ptr->next=q;
 p->next=ptr;
 q->prev=ptr;
 return ptr;
}

// Insert after a given node 
struct node *insertaftGN(struct node *GN, int data){
 struct node *ptr=(struct node *)malloc(sizeof(struct node));
 ptr->data=data;
 struct node *p=GN->next;
 ptr->prev=GN;
 ptr->next=p;
 p->prev=ptr;
 GN->next=ptr;
 return ptr;
}



int main(){
 struct node *first;
 struct node *second;
 struct node *third;
 struct node *fourth;
 struct node *fifth;
 
 first=(struct node *)malloc(sizeof(struct node));
 second=(struct node *)malloc(sizeof(struct node));
 third=(struct node *)malloc(sizeof(struct node)); 
 fourth=(struct node *)malloc(sizeof(struct node));
 fifth=(struct node *)malloc(sizeof(struct node));

 first->prev=NULL;
 first->data=45;
 first->next=second;

 second->prev=first;
 second->data=23;
 second->next=third;

 third->prev=second;
 third->data=36;
 third->next=fourth;

 fourth->prev=third;
 fourth->data=18;
 fourth->next=fifth;

 fifth->prev=fourth;
 fifth->data=48;
 fifth->next=NULL;

 traverse(first,fifth);

 // INSERTION

 // printf("\n***************************************");
 // printf("\n\t After inserting a node at first\n");
 // printf("***************************************\n");
 // first=insertatFirst(first, 78);
 // traverse(first, fifth);

 // printf("\n******************************************");
 // printf("\n  After inserting a node at last\n");
 // printf("******************************************\n");
 // fourth=insertatEnd(first, 78);
 // traverse(first, fifth);

 printf("\n******************************************");
 printf("\n  After inserting a node at given index\n");
 printf("******************************************\n");
 insertatIndex(first, 78, 2);
 traverse(first, fifth);

 // printf("\n******************************************");
 // printf("\n  After inserting a Given node\n");
 // printf("******************************************\n");
 // insertaftGN(third, 78);
 // traverse(first, fifth);

 return 0;
} 