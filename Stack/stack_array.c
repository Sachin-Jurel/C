#include<stdio.h>
#include<stdlib.h>

struct stack{
 int size;
 int top;
 int *array;
};

int isempty(struct stack *s){
 if(s->top==-1){
  return 1;
 }
 else{
  return 0;
 }
}

int isfull(struct stack *s){
 if(s->top==s->size-1){
  return 1;
 }
 else{
  return 0;
 }
}

void push(struct stack *s, int data){
 if(isfull(s)){
  printf("stack is full");
 }
 else{
  s->top++;
  s->array[s->top]=data;
 }
}

void pop(struct stack *s){
 int data=0;
 if(isempty(s)){
  printf("stack is empty\n");
 }
 else{
  data=s->array[s->top];
  s->top--;
  printf("%d poped from stack", data);
 }
}

int main(){
 struct stack *s;
 s->size=10;
 s->top=-1;
 s->array=(int*)malloc(s->size*sizeof(int));
 push(s,4);
 push(s,7);
 push(s,2);
 pop(s);

 return 0;
}


