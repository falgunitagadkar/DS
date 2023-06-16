//queue implementation

#include<stdio.h>
#include<stdlib.h>

struct queue
{
	int size;
	int f;
	int r;
	int *arr;
};

void enqueue(struct queue* q,int val)
{
	if(isFull(q))
	{
		printf("Queue is full! Cannot insert element in the queue\n");
	}
	else if(isEmpty(q))
	{
		q->r++;
		q->arr[q->r]=val;
		q->f++;
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
	else if(q->f==q->r)
	{
		int val=q->f;
		q->f=-1;
		q->r=-1;
		return val;
	}
	else
	{
		int val=q->f;
		q->f++;
		return val;
	}
}

void traverse(struct queue* q)
{
	int i;
	for(i=q->f;i<=q->r;i++)
	{
		printf("%d\n",q->arr[i]);
	}
}
int isEmpty(struct queue* q)
{
	if(q->f==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

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
int main()
{
	struct queue* q=(struct queue*)malloc(sizeof(struct queue));
	q->size=10;
	q->f=-1;
	q->r=-1;
	q->arr=(int *)malloc(q->size*sizeof(int));
	
	enqueue(q,10);
	enqueue(q,20);
	enqueue(q,30);
	traverse(q);
	
	printf("\n\n");
	printf("after dequeue operation\n");
	dequeue(q);
	traverse(q);
	return 0;
}
