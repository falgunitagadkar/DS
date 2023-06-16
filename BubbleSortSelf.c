//Bubble sort algorithm

#include<stdio.h>
#include<stdlib.h>

int * bubbleSort(int * a,int size)
{
	int i,j,k;
	for(i=0;i<size-1;i++)
	{
		k=0;
		for(j=4;j>i;j--)
		{
			if(a[k]>a[k+1])
			{
				int t;
				t=a[k];
				a[k]=a[k+1];
				a[k+1]=t;
				k++;
			}
			else
			{
				k++;
			}
		}
	}
	
	return a;
}
int main()
{
	int *arr=(int *)malloc(5*sizeof(int));
	arr[0]=339;
	arr[1]=399;
	arr[2]=336;
	arr[3]=366;
	arr[4]=333;
	int *ans=bubbleSort(arr,5);
	int i;
	for(i=0;i<5;i++)
	{
		printf("%d ",ans[i]);
	}
	return 0;
}
