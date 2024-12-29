#include<stdio.h>
#include<stdlib.h>

// Traversing array 
void traverse_array(int A[],int n){
 printf("Given array is ");
 for(int i=0; i<=n; i++){
  printf("%d ", A[i]);
 }
}


// INsertion sort function
void sort(int A[],int n){
 int i,j,key;
 for(i=0; i<=n; i++){
  key=A[i];
  j=i-1;
  while(j>=0 && A[j]>key){
   A[j+1]=A[j];
   j--;
  }
  A[j+1]=key;
 }
}

int main(){
 int A[]={54,37,46,34,36,67,47,48};

 sort(A, 7);
 traverse_array(A, 7);

 return 0;
}

