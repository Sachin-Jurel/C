#include<stdio.h>
#include<stdlib.h>

struct node{
 int data;
 struct node *next;
};

void traverse(struct node *head){
 struct node *ptr=head;
 do{
  printf("%d ",ptr->data);
  ptr=ptr->next;
 }while(ptr!=head);
}

// INSERTION

// Insert at first
struct node *insertatfirst(struct node *head,int data){
 struct node *ptr=(struct node *)malloc(sizeof(struct node));
 ptr->data=data;
 struct node *p=head->next;
 while(p->next != head){
  p=p->next;
 }
 p->next=ptr;
 ptr->next=head;
 return ptr;
}

// Insert at last 
struct node *insertatend(struct node *head, int data){
 struct node *ptr=(struct node *)malloc(sizeof(struct node));
 ptr->data=data;
 struct node *p=head;
 while(p->next != head){
  p=p->next;
 }
 p->next=ptr;
 ptr->next=head;
 return ptr;
}

// Inserting at indexing 
struct node *insertatindex(struct node *head,int data, int index){
 struct node *ptr=(struct node *)malloc(sizeof(struct node));
 ptr->data=data;
 for(int i=0;i<index-1;i++){
  head=head->next;
 }
 ptr->next=head->next;
 head->next=ptr;
 return ptr;
}

// Insert after a given node 
struct node *insertatGN(struct node *GN,int data){
 struct node *ptr=(struct node *)malloc(sizeof(struct node));
 ptr->data=data;
 ptr->next=GN->next;
 GN->next=ptr;
 return ptr;
}

// DELETION

// Delete first node 
struct node *deleteatfirst(struct node *head){
 struct node *p=head;
 while(p->next!=head){
  p=p->next;
 }
 p->next=head->next;
 free(head);
 return p->next;
}

// Delete last node 
struct node *deleteatlast(struct node *head){
 struct node *p=head;
 struct node *q=head->next;
 while(q->next!=head){
  p=p->next;
  q=q->next;
 }
 p->next=head;
 free(q);
 return p;
}

// Delete indexing node 
struct node *deleteatindex(struct node *head, int index){
 struct node *p = head;
 struct node *q = head->next;
 for(int i=0; i<index-1; i++){
  p=p->next;
  q=q->next;
 }
 p->next=q->next;
 free(q);
 return p;
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

 first->data=8;
 first->next=second;

 second->data=34;
 second->next=third;

 third->data=67;
 third->next=fourth;

 fourth->data=23;
 fourth->next=fifth;

 fifth->data=45;
 fifth->next=first;

 traverse(first);

 // printf("\n After insert at first\n");
 // first=insertatfirst(first,13);
 // traverse(first);

 // printf("\n After insert at last\n");
 // insertatend(first,13);
 // traverse(first);

 // printf("\n insert at indexing\n");
 // insertatindex(first,13,3);
 // traverse(first);

 // printf("\n After insert given node\n");
 // insertatGN(second,13);
 // traverse(first);



 // printf("\n After delete first node\n");
 // first=deleteatfirst(first);
 // traverse(first);

 // printf("\n After delete last node\n");
 // deleteatlast(first);
 // traverse(first);

 printf("\n After delete indexing node\n");
 deleteatindex(first,2);
 traverse(first);

 return 0;
}