//Insertion sort

#include<stdio.h>
#include<stdlib.h>


int * insertionSort(int * arr1)
{
	int i,j,k;
	int temp;
	for(i=1;i<=4;i++)
	{
		for(j=i-1;j>=0;j--)
		{
			k=i;
			if(arr1[i]<arr1[j])
			{
				temp=arr1[i];
				arr1[i]=arr1[j];
				arr1[j]=temp;
				i=j;
			}
		}
		i=k;
	}
	
	return arr1;
}
int main()
{
	int* arr=(int*)malloc(5*sizeof(int));
	arr[0]=12;
	arr[1]=8;
	arr[2]=7;
	arr[3]=18;
	arr[4]=6;
	int * ans=insertionSort(arr);
	int i;
	printf("The Sorted array using Insertion Sort is:\n");
	for(i=0;i<5;i++)
	{
		printf("%d\n",ans[i]);
	}
	return 0;
}
