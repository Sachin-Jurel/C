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


 return 0;
}