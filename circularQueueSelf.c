//circular queue operation

#include<stdio.h>
#include<stdlib.h>
struct queue
{
	int size;
	int f;
	int r;
	int * arr;
};

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
	if((q->r+1)%q->size==q->f)
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
		printf("Queue is full!Cannot insert element in the queue\n");
	}
	else if(isEmpty(q))
	{
		q->r=(q->r+1)%q->size;//circular increment...after size-1 index...next index becomes 0
		q->arr[q->r]=val;
		q->f++;//increment the front pointer at 0 index;
	}
	else
	{
		q->r=(q->r+1)%q->size;
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
		q->f=(q->f+1)%q->size;
		return val;
	}
}
void traverse(struct queue* q)
{
	if(isEmpty(q))
	{
		printf("Cannot traverse through the queue as the queue is empty\n");
	}
	else
	{
		int i;
		for(i=q->f;i<=q->r;i++)
		{
			printf("%d\n",q->arr[i]);
		}
	}
}

int queueFront(struct queue* q)
{
	return q->arr[q->f];
}

int queueRear(struct queue* q)
{
	return q->arr[q->r];
}
int main()

{
	struct queue* q=(struct queue*)malloc(sizeof(struct queue));
	q->size=3;
	q->f=-1;
	q->r=-1;
	q->arr=(int *)malloc(q->size*sizeof(int));
	
	enqueue(q,10);
	enqueue(q,20);
	enqueue(q,30);
	printf("After insertion of 3 elements in the queue\n");
	traverse(q);

	printf("Front element:%d\n",queueFront(q));
	printf("Rear element:%d\n",queueRear(q));	
	printf("\n\n");
	printf("After performing dequeue and adding elements\n");
	dequeue(q);
	dequeue(q);
	enqueue(q,40); 
	enqueue(q,50);
	enqueue(q,60);
	dequeue(q);
	traverse(q);
	
	printf("Front element:%d\n",queueFront(q));
	printf("Rear element:%d\n",queueRear(q));
	return 0;
}
