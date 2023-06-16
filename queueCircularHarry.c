
#include<stdio.h>
#include<stdlib.h>

struct circularQueue
{
	int size;
	int f;
	int r;
	int* arr;
};

int isEmpty(struct circularQueue* q)
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

int isFull(struct circularQueue* q)
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

void enqueue(struct circularQueue* q,int val)
{
	if(isFull(q))
	{
		printf("Queue is full!Cannot insert element %d\n",val);
	}
	else
	{
		q->r=(q->r+1)%q->size;
		q->arr[q->r]=val;
		printf("Enqueued element:%d\n",q->arr[q->r]);
		
	}
}

int dequeue(struct circularQueue* q)
{
	if(isEmpty(q))
	{
		return -1;
	}
	else
	{
		q->f=(q->f+1)%q->size;
		int val=q->arr[q->f];
		printf("Dequeued element:%d\n",val);
		return val;
	}
}
int queueFront(struct circularQueue* q)
{
	return q->arr[(q->f+1)%q->size];
}

int queueRear(struct circularQueue* q)
{
	return q->arr[q->r];
}

int main()
{
	struct circularQueue* q=(struct circularQueue*)malloc(sizeof(struct circularQueue));
	q->size=5;
	q->f=0;
	q->r=0;
	q->arr=(int *)malloc(q->size*sizeof(int));
	
	//if(isEmpty(q))
	//{
		//printf("Queue is empty\n");
	//}
	
	enqueue(q,10);
	enqueue(q,20);
	enqueue(q,30);
	enqueue(q,40);
	dequeue(q);
	dequeue(q);
	enqueue(q,50);
	enqueue(q,60);
	printf("Front element is %d at front index %d\n",queueFront(q),q->f+1);
	printf("Rear element is %d at rear index %d\n",queueRear(q),q->r);
	return 0;
}
