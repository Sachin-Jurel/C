#include<stdio.h>
#include<stdlib.h>

struct node{
 int data;
 struct node *next;
};

void traverse(struct node *ptr){
 printf("\n----------------------------------\n");
 while(ptr!=NULL){
  printf("Element is %d\n", ptr->data);
  ptr=ptr->next;
 }
 printf("----------------------------------");
}

// case 1: Element is inserted at first
struct node *insertatfirst(struct node *first, int data){
 struct node *ptr=(struct node *)malloc(sizeof(struct node));
 ptr->data=data;
 ptr->next=first;
 return ptr;
}

// case 2: Element is inserted at End
struct node *insertatEnd(struct node *end, int data){
 struct node *ptr=(struct node *)malloc(sizeof(struct node));
 end->next=ptr;
 ptr->data=data;
 ptr->next=NULL;
 return ptr;
}

// case 3: Element is inserted at index
struct node *insertatindex(struct node *first, int index, int data){
 struct node *ptr=(struct node *)malloc(sizeof(struct node));
 struct node *p=first;
 int i=0;
 while(i!=index-1){
  p=p->next;
  i++;
 }
 ptr->data=data;
 ptr->next=p->next;
 p->next=ptr;
 return first;
}

// case 4: Previous node is given 
struct node *insert(struct node *prevnode,int data){
 struct node *ptr=(struct node *)malloc(sizeof(struct node));
 ptr->data=data;
 ptr->next=prevnode->next;
 prevnode->next=ptr;
 return ptr;
}


int main(){
 struct node *first;
 struct node *second;
 struct node *third;

 first=(struct node *)malloc(sizeof(struct node));
 second=(struct node *)malloc(sizeof(struct node));
 third=(struct node *)malloc(sizeof(struct node));

 first->data=34;
 first->next=second;

 second->data=26;
 second->next=third;

 third->data=45;
 third->next=NULL;

 traverse(first);

 // printf("\n\nAfter insert a node at first");
 // first=insertatfirst(first,23);
 // traverse(first);

 // printf("\n\nAfter insert a node at End");
 // insertatEnd(third,67);
 // traverse(first);

 // printf("\n\nAfter insert a node at index");
 // insertatindex(first,4,32);
 // traverse(first);

 // printf("\n\nPrevious node is given");
 // insert(third,49);
 // traverse(first);
 
 return 0;
}