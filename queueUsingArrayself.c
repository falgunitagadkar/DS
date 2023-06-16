//Queue implimentation using array
//here we consider f pointing to index prior to element to be deleted

#include<stdio.h>
#include<stdlib.h>

struct queue
{
	int size;
	int f;
	int r;
	int * arr;
};

int isFull(struct queue* q)
{
	if(q->r==q->size-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isEmpty(struct queue* q)
{
	if(q->f==q->r)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void enqueue(struct queue* q,int val)
{
	if(isFull(q))
	{
		printf("Queue overflow!Cannot insert element %d in the queue\n",val);
	}
	else
	{
		q->r++;
		q->arr[q->r]=val;
	}
}

int dequeue(struct queue* q)
{
	if(isEmpty(q))
	{
		return -1;
	}
	else
	{
		int val;
		q->f++;
		val=q->arr[q->f];
		return val;
	}
}

void traverse(struct queue* q)
{
	int i;
	if(isEmpty(q))
	{
		printf("Sorry!No elements in the queue...");
	}
	for(i=q->f+1;i!=q->r+1;i++)
	{
		printf("%d\n",q->arr[i]);
	}
}
int main()
{
	struct queue* q=(struct queue*)malloc(sizeof(struct queue));
	q->size=10;
	q->f=-1;
	q->r=-1;
	q->arr=(int *)malloc(q->size*sizeof(int));
	
	traverse(q);
	
	printf("\n\n");
	printf("After push operation\n");
	enqueue(q,10);//first in 
	traverse(q);
	
	printf("\n\n");
	printf("After push operation\n");
	enqueue(q,20);
	traverse(q);
	
	printf("\n\n");
	printf("After push operation\n");
	enqueue(q,30);
	traverse(q);
	
	printf("\n\n");
	printf("After push operation\n");
	enqueue(q,40);
	traverse(q);
	printf("\n\n");
	printf("After pop operation\n");
	dequeue(q);
	traverse(q);//first out
	
	
	return 0;
}
