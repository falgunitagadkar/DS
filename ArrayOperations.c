#include<stdio.h>
#include<math.h>

void Traverse(int arr[],int n)
{
	int i;
	printf("The array elements are\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int InsertionArray(int arr[],int index,int size,int capacity,int element)
{
	int i;
	if(size>=capacity)
	{
		printf("Array out of bounds\n");
		return 0;
	}
	for(i=size-1;i>=index;i--)
	{
		arr[i+1]=arr[i];
	}
	arr[index]=element;
	return 1;	
}

void DeletionArray(int arr[],int index,int size)
{
	int i;
	if(index<0)
	{
		printf("Array underflow\n");
	}
	else
	{
		for(i=index+1;i<size;i++)
		{
			arr[i-1]=arr[i];
		}
	}
	
}

int LinearSearch(int arr[],int element,int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(arr[i]==element)
		{
			printf("Element %d found on index %d\n",element,i);
			return 0;
	  }
	}
	printf("Element not found\n");
	return -1;
}

int BinarySearch(int arr[],int element,int size)
{
	int mid;
	int low=0;
	int high=size-1;
	mid=(low+high)/2;
	
	while(low<=high)
	{
	  if(element==arr[mid])
	{
		printf("Element %d found at %d index\n",element,mid);
		return 1;
	}
	else if(element<arr[mid])
	{
		high=mid-1;
		mid=(low+high)/2;
	}
	else if(element>arr[mid])
	{
		low=mid+1;
		mid=(low+high)/2;
	}	
  }
  
  printf("Element not found in the array\n");
  return 0;
}
int main()
{
	int arr1[10];
	InsertionArray(arr1,0,0,10,1);
	InsertionArray(arr1,1,1,10,2);
	InsertionArray(arr1,2,2,10,6);
	InsertionArray(arr1,3,3,10,8);
	Traverse(arr1,4);
	
	//Above insertion was to add elements in the array
	//Now elements will be added in any index which already has some element and the rest will shift right
	
	InsertionArray(arr1,1,4,10,3);	
	Traverse(arr1,5);
	
	DeletionArray(arr1,2,5);
	Traverse(arr1,4);
	
	//DeletionArray(arr1,0,4);
	//Traverse(arr1,3);
	
	LinearSearch(arr1,6,4);
	BinarySearch(arr1,3,4);
	return 0;
}
