//Selection sort self try

#include<stdio.h>
#include<stdlib.h>

int * selectionSort(int *a,int size)
{
	int i,j,k;
	int min;
	for(i=0;i<size-1;i++)
	{
		min=a[i];
		for(j=i+1;j<=size-1;j++)
		{
			if(a[j]<min)
			{
				min=a[j];
				k=j;
			}
		}
		//swap with the minimum from the unsorted part
		a[k]=a[i];
		a[i]=min;
	}
	return a;	
}

void printArray(int *a,int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		printf("%d ",a[i]);
	}
}
int main()
{
	int a[]={8,0,7,1,3};
	printArray(a,5);
	
	printf("\n\n");
	printf("After applying selection sort\n");
	int* arr=(int *)malloc(5*sizeof(int));
	arr=selectionSort(a,5);
	printArray(arr,5);
	return 0;
}
