#include<stdio.h>

// Traverse function
void display(int arr[] , int size){
 printf("\n********************************\n");
 for(int i=0; i<size; i++){
  printf("Element in %d position is %d\n",i, arr[i]);
 }
 printf("********************************\n\n");
}


// Insertion function
void insert(int arr[], int size, int capacity,int index, int element){
 if(index>=capacity){
  printf("overflow");
 }
 else{
  for(int i=size-1; i>=index; i--){
   arr[i+1]=arr[i];
  }
  arr[index]=element;
 }
}


// Deletion function
void delete(int arr[], int index, int size){
 for(int i=index; i<size; i++){
  arr[i]=arr[i+1];
 }
}


int main(){
 int arr[10]={2,4,6,10,12};
 int size=5;

 display(arr,size);

 // insertion
 insert(arr,size,10,3,8);
 size++;
 printf("\t After insert");
 display(arr,size);

 // Deletion
 delete(arr,3,size);
 size--;
 printf("\t After deletion");
 display(arr,size);

 return 0;
}