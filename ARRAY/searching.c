#include<stdio.h>

// linearsearch function
int linearsearch(int arr[], int size, int element){
 for(int i = 0; i < size; i++){
  if(arr[i] == element){
   printf("Element %d is found at index %d",element, i);
   return 1;
  }
 }
 return -1;
}

// binarySearch function
void binarySearch(int arr[],int low,int high,int element){
 int mid=(low+high)/2;
 if(arr[mid] == element){
  printf("Element %d is found at index %d",element, mid);
 }
 else if(arr[mid]<element){
  binarySearch(arr,mid,high,element);
 }
 else if(arr[mid]>element){
  binarySearch(arr,low,mid,element);
 }
 else{
  printf("Element %d is not found\n", element);
 }
}


int main(){

 // linearsearch
 printf("\n");
 int arr1[20]={3,5,7,10,2,8,9,12,4,1};
 int size=10;
 int element=4;
 int a = linearsearch(arr1, size, element);
 if(a==-1){
  printf("Element %d not found\n", element);
 }

 printf("\n");
 printf("--------------------------------\n");

 // binarySearch
 int arr2[20]={1,2,3,4,5,6,7,8,9,10};
 int high=9;
 binarySearch(arr2,0, high, 6);
 printf("\n");
 
 return 0;
}