#include <stdio.h>
#include <stdlib.h>

struct myarray
{
 int total_size;
 int used_size;
 int *ptr;
};

void createarray(struct myarray *a, int t_size, int u_size)
{
 a->total_size = t_size;
 a->used_size = u_size;
 a->ptr = (int *)malloc(t_size * sizeof(int));
}

void setarray(struct myarray *a)
{
 printf("\n********************************************\n");
 for (int i = 0; i <= a->used_size - 1; i++)
 {
  printf("Enter element in %d position: ", i);
  scanf("%d", &(a->ptr)[i]);
 }
 printf("********************************************\n");
}

void showarray(struct myarray *a)
{
 for (int i = 0; i <= a->used_size - 1; i++)
 {
  printf("%d\n", (a->ptr)[i]);
 }
 printf("********************************************");
}

int main()
{
 struct myarray a;
 createarray(&a, 10, 2);
 setarray(&a);
 showarray(&a);

 return 0;
}