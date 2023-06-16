//Quick sort Harry

#include<stdio.h>
#include<stdlib.h>

void printArray(int a[],int size)
{
	int i;
	for(i=0;i<=size-1;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

int partition(int a[],int low,int high)
{
	int pivot;
	int i,j;
	int temp;
	pivot=a[low];
	i=low+1;
	j=high;
	
	do
	{
		while(a[i]<=pivot)
		{
			i++;
		}
		while(a[j]>pivot)
		{
			j--;
		}
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
		
	}while(i<j);
	
	//swapping with pivot
	temp=a[low];
	a[low]=a[j];
	a[j]=temp;
	
	return j;
}

void quickSort(int a[],int low,int high)
{
	int partionIndex;
	
	if(low<high)
	{
		partionIndex=partition(a,low,high);
		quickSort(a,low,partionIndex-1);
		quickSort(a,partionIndex+1,high);	
	}
	
}
int main()
{
	int a[]={12,45,89,1,28,13,3,4,8,2,6,5,10,34,7};
	int size=15;
	printArray(a,size);
	
	printf("After applying Quick sort\n");
	quickSort(a,0,size-1);
	printArray(a,size);
	return 0;
}
