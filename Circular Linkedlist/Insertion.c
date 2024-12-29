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


// INSERTION

// case 1: Insert a node at first
struct node *insertatFirst(struct node *first, int data){
 struct node *ptr=(struct node *)malloc(sizeof(struct node));
 ptr->data=data;
 struct node *p=first->next;
 while(p->next != first){
  p=p->next;
 }
 p->next=ptr;
 ptr->next=first;
 first=ptr;
 return first;
}

// case 2: Insert a node at end    
struct node *insertatEnd(struct node *first, int data){
 struct node *ptr=(struct node *)malloc(sizeof(struct node));
 ptr->data=data;
 struct node *p=first->next;
 while(p->next!=first){
  p=p->next;
 }
 p->next=ptr;
 ptr->next=first;
 return first;
}

// case 3: Insert a node at index
struct node *insertatIndex(struct node *first, int index, int data){
 struct node *ptr=(struct node *)malloc(sizeof(struct node));
 ptr->data=data;
 struct node *p=first;
 for(int i=0; i<index-1; i++){
  p=p->next;
 }
 ptr->next=p->next;
 p->next=ptr;
 return first;
}

// case 4: Previous node is given 
struct node *insert(struct node *prev, int data){
 struct node *ptr=(struct node *)malloc(sizeof(struct node));
 ptr->data=data;
 ptr->next=prev->next;
 prev->next=ptr;
 return ptr;
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

 // INSERTION.......................................

 // printf("\n After insert a node at first position");
 // first=insertatFirst(first, 34);
 // traverse(first);

 // printf("\n After insert a node at last position");
 // first=insertatEnd(first, 34);
 // traverse(first);

 // printf("\n After insert a node at index");
 // first=insertatIndex(first,2,34);
 // traverse(first);

 // printf("\n Previous node is given");
 // insert(first,34);
 // traverse(first);

 return 0;
} 