//Bubble sort harry

#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int a[],int size)
{
	 int i,j;
	 int temp;
	 int isSorted;
	 for(i=0;i<size-1;i++)
	 {
	 	isSorted=1;//before every pass we make isSorted to 1...if there is no swapping required then issorted remains 1
	 	printf("We are in %d pass\n",i+1);
		for(j=0;j<size-1-i;j++)
	 	{
	 		if(a[j]>a[j+1])
	 		{
	 			temp=a[j];
	 			a[j]=a[j+1];
	 			a[j+1]=temp;
	 			isSorted=0;
			}
		}
		if(isSorted)
		{
			return;//if for any completed pass...isSorted is 1...which means array is sorted now...so we return here
		}
	 }
}

void printArray(int a[],int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		printf("%d ",a[i]);
	}
}
int main()
{
	int a[]={5,34,23,8,11};
	int size=5;
	printf("Array before sorting\n");
	printArray(a,size);
	
	printf("\n\n");
	printf("Array after sorting\n");
	bubbleSort(a,size);
	printArray(a,size);
	return 0;
}
