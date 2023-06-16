//DEQueue implementation

#include<stdio.h>
#include<stdlib.h>

struct DEqueue
{
	int size;
	int f;
	int r;
	int* arr;
};

int isEmpty(struct DEqueue* q)
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

int isFull(struct DEqueue* q)
{
	if(q->r==q->size-1 || q->f==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void enqueueF(struct DEqueue* q,int val)
{
	if(q->f==-1)
	{
		printf("Queue is full from front end...Cannot insert element at front end\n");
	}
	else
	{
		q->arr[q->f]=val;//at front index put the new value
		q->f--;
	}
}

void enqueueR(struct DEqueue* q,int val)
{
	if(q->r==q->size-1)
	{
		printf("Queue is full from rear end...Cannot insert element at rear end\n");
	}
	else
	{
		q->r++;
		q->arr[q->r]=val;
	}
}

int dequeueF(struct DEqueue* q)
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

int dequeueR(struct DEqueue* q)
{
	if(isEmpty(q))
	{
		return -1;
	}
	else
	{
		int val;
		val=q->arr[q->r];
		q->r--;
	}
}

void traverse(struct DEqueue* q)
{
	if(isEmpty(q))
	{
		printf("No elements in the queue\n");
	}
	else
	{
		printf("Elements in the queue are:\n");
	  int i=q->f+1;
	  while(i<=q->r)
	  {
		  printf("%d\n",q->arr[i]);
		  i++;
	  }
	}
}
int main()
{
	struct DEqueue* q=(struct DEqueue*)malloc(sizeof(struct DEqueue));
	q->size=5;
	q->f=-1;
	q->r=-1;
	q->arr=(int *)malloc(q->size*sizeof(int));
	
	printf("Enqueuing from rear end\n");
	enqueueR(q,23);
	enqueueR(q,34);
	enqueueR(q,45);
	traverse(q);
	
	printf("\n\n");
	printf("Dequeing from front end\n");
	dequeueF(q);
  traverse(q);
  
  printf("\n\n");
  printf("Enqueuing from front end\n");
	enqueueF(q,67);
	traverse(q);
	
	printf("\n\n");
	printf("Dequeuing from rear end\n");
	dequeueR(q);
	traverse(q);
	return 0;
}
