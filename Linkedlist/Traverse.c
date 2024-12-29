#include<stdio.h>
#include<stdlib.h>

struct node{
 int data;
 struct node *next;
};

// traversal function
void traversal(struct node *ptr){
 printf("-----------------------------------------\n");
 while(ptr!=NULL){
  printf("ELement is %d\n",ptr->data);
  ptr = ptr->next;
 }
 printf("-----------------------------------------\n");
}


int main(){
 struct node *first;
 struct node *second;
 struct node *third;

 first=(struct node *)malloc(sizeof(struct node));
 second=(struct node *)malloc(sizeof(struct node));
 third=(struct node *)malloc(sizeof(struct node));

 first->data=22;
 first->next=second;

 second->data=34;
 second->next=third;
 
 third->data=12;
 third->next=NULL;

 traversal(first);

 return 0;
}