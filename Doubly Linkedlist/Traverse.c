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

 return 0;
} 