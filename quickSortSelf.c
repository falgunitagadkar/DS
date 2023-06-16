//Quick sort

#include<stdio.h>
#include<stdlib.h>

int isSorted(int *a,int size)
{
	int i,j;
	int notSorted=0;
	for(i=1,j=0;i<size,j<size-1;i++,j++)
	{
		if(a[j]>a[i])
		{
			notSorted=1;
		}
	}
	
	if(notSorted==0)//not sorted is false which means array is sorted
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int* quickSort(int *a,int size)
{
	int pivot;
	int i,j;
	int low=0;
	int high=size-1;
	while(!isSorted(a,size))//while isSorted is false we perform the below code
	{
		pivot=low;
		i=low;
		j=high;
		while(a[i]<=a[pivot])
		{
			i++;
			if(i<j)
			{	
				int temp;
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
			
			if(j<=i)
			{
				break;
			}
		}
		while(a[j]>a[pivot])
		{
			j--;
			if(i<j)
			{	
				int temp;
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
			
			if(j<=i)
			{
				break;
			}
		}
		
		int temp;
		temp=a[pivot];
		a[pivot]=a[j];
		a[j]=temp;
		
		low=a[temp]+1;
		pivot=low;
		i=low;
		
	}
}
int main()
{
	int a[]={1,2,2,45};
	int size=4;
	
	if(isSorted(a,size))
	{
		printf("Array is sorted\n");
	}
	else
	{
		printf("Array is not sorted\n");
	}
	return 0;
}
