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


// DELETION

// case 1: Delete first node 
struct node *deleteatFirst(struct node *first){
 struct node *p=first->next;
 p->prev=first->prev;
 free(first);
 return p;
}

// case 2: Delete last node 
struct node *deleteatEnd(struct node *first){
 struct node *p=first;
 struct node *q=first->next;
 while(q->next != NULL){
  p=p->next;
  q=q->next;
 }
 p->next=NULL;
 free(q);
 return p;
}

// case 3: Delete Indexing node 
struct node *deleteatIndex(struct node *first, int index){
 struct node *p=first;
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
 return first;
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

 // DELETION

 // printf("\n******************************************");
 // printf("\n  After Deleting a first node\n");
 // printf("******************************************\n");
 // first=deleteatFirst(first);
 // traverse(first, fifth);

 // printf("\n******************************************");
 // printf("\n  After Deleting a last node\n");
 // printf("******************************************\n");
 // fifth=deleteatEnd(first);
 // traverse(first, fifth);

 // printf("\n******************************************");
 // printf("\n  After Deleting a Indexing node\n");
 // printf("******************************************\n");
 // deleteatIndex(first, 2);
 // traverse(first, fifth);

 // printf("\n******************************************");
 // printf("\n  After Deleting Given node\n");
 // printf("******************************************\n");
 // deleteGN(fourth);
 // traverse(first, fifth);

 return 0;
}