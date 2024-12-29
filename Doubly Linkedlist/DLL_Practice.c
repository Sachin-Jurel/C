#include<stdio.h>
#include<stdlib.h>

struct node{
 struct node *prev;
 int data;
 struct node *next;
};

void traverse(struct node *head, struct node *last){
 printf("\nTraverse in forward direction\n");
 while(head!=NULL){
  printf("%d ", head->data);
  head=head->next;
 }
 printf("\nTraverse in reverse direction\n");
 while(last!=NULL){
  printf("%d ",last->data);
  last=last->prev;
 }
}

// INSERTION

// Insert a node at first
struct node *insertatfirst(struct node *head,int data){
 struct node *ptr=(struct node *)malloc(sizeof(struct node));
 ptr->data=data;
 ptr->prev=NULL;
 ptr->next=head;
 head->prev=ptr;
 return ptr;
}

// Insert a node at last 
struct node *insertatend(struct node *head,int data){
 struct node *ptr=(struct node *)malloc(sizeof(struct node));
 ptr->data=data;
 while(head->next!=NULL){
  head=head->next;
 }               
 head->next=ptr;
 ptr->prev=head;
 ptr->next=NULL;
 return ptr;                    
}

// INsert at indexing 
struct node *insertatindex(struct node *head, int data, int index){
 struct node *ptr=(struct node *)malloc(sizeof(struct node));
 ptr->data=data;
 struct node *p=head->next; 
 for(int i=0; i<index-1; i++){
  head=head->next;
  p=p->next;
 }
 ptr->prev=head;
 ptr->next=p;
 p->prev=ptr;
 head->next=ptr;
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

// DELETION

// DElete first node 
struct node *deletefirst(struct node *head){
 struct node *p=head->next;
 p->prev=NULL;
 free(head);
 return p;
}

// DElete last node 
struct node *deletelast(struct node *head){
 struct node *p=head;
 struct node *q=head->next;
 while(q->next != NULL){
  p=p->next;
  q=q->next;
 }
 p->next=NULL;
 free(q);
 return p;
}

// Delete indexing node 
struct node *deleteIndex(struct node *head, int index){
 struct node *p=head;
 struct node *q=p->next;
 struct node *r=q->next;
 for(int i=0; i<index-1; i++){
  p=p->next;
  q=q->next;
  r=r->next;
 }
 p->next=r;
 r->prev=p;
 free(q);
 return p;
}

// Delete Given node 
struct node *deleteGN(struct node *GN){
 struct node *p=GN->prev;
 struct node *q=GN->next;
 p->next=q;
 q->prev=p;
 free(GN);
 return p;
}


int main(){
 struct node *first;
 struct node *second;
 struct node *third;
 struct node *fourth;
 struct node *fifth;

 first=(struct node*)malloc(sizeof(struct node));
 second=(struct node*)malloc(sizeof(struct node));
 third=(struct node*)malloc(sizeof(struct node));
 fourth=(struct node*)malloc(sizeof(struct node));
 fifth=(struct node*)malloc(sizeof(struct node));

 first->prev=NULL;
 first->data=23;
 first->next=second;

 second->prev=first;
 second->data=35;
 second->next=third;

 third->prev=second;
 third->data=25;
 third->next=fourth;

 fourth->prev=third;
 fourth->data=56;
 fourth->next=fifth;

 fifth->prev=fourth;
 fifth->data=45;
 fifth->next=NULL;

 traverse(first,fifth);

 // printf("\n Insert a node at first position");
 // first=insertatfirst(first, 18);
 // traverse(first,fifth);

 // printf("\n Insert a node at last position");
 // fifth=insertatend(first, 18);
 // traverse(first,fifth);

 // printf("\n Insert a node at index position");
 // insertatindex(first, 18, 3);
 // traverse(first,fifth);

 // printf("\n Insert after a given node");
 // insertaftGN(third, 18);
 // traverse(first,fifth);


// DELETION

 // printf("\n AFTER Delete first node");
 // first=deletefirst(first);
 // traverse(first,fifth);

 // printf("\n AFTER Delete last node");
 // fifth=deletelast(first);
 // traverse(first,fifth);

 // printf("\n AFTER Delete indexing node");
 // deleteIndex(first, 2);
 // traverse(first,fifth);

 // printf("\n AFTER Delete given node");
 // deleteGN(fourth);
 // traverse(first,fifth);

 return 0;
}