#include<stdio.h>
#include<stdlib.h>

struct Array
{
	int totalsize;
	int usedsize;
	int *ptr;
};

void arraycreate(struct Array* a)
{
	printf("Enter the totalsize you want of your array\n");
	scanf("%d",&a->totalsize);
	a->ptr=(int*)malloc(a->totalsize*sizeof(int));
	a->usedsize=0;
}


void arrayInsert(struct Array *a)
{
	int i=a->usedsize;
	int x;
	printf("Enter the element you want to insert\n");
	scanf("%d",&x);
	(a->ptr)[i]=x;
	a->usedsize++;
}


void arrayUpdate(struct Array* a,int x)
{
	int i;
	printf("Enter the index you want to update\n");
	scanf("%d",&i);
	if(i>a->totalsize-1)
	{
		printf("Array out of bound\n");
	}
	else
	{
		(a->ptr)[i]=x;
	}
}

void display(struct Array* a)
{
	int i;
	printf("Elements of the stack are\n");
	for(i=0;i<a->totalsize;i++)
	{
		printf("%d\n",a->ptr[i]);
	}
}
int main()
{
	int i;
	struct Array marks;
	arraycreate(&marks);
	
	for(i=0;i<marks.totalsize;i++)
	{
		arrayInsert(&marks);
	}
	
  printf("Elements after insertion\n");
  display(&marks);
  
	arrayUpdate(&marks,5);
	printf("Elements after Updation\n");
	display(&marks);
	return 0;
}
