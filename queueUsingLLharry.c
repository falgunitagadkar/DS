//Queue implementation using link list

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

//set global variables front and rear
struct Node* f=NULL;//initialize front to NULl
struct Node* r=NULL;//initialize rear to NULL

int isEmpty()
{
  if(f==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}	
}

int isFull()
{
	struct Node* n=(struct Node*)malloc(sizeof(struct Node));
	if(n==NULL)//no space to create new node then queue is said to be full
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

struct Node* enqueue(int val)
{
	if(isFull())
	{
		printf("Memory not available..Queue full!\n");
		return f;
	}
	else if(isEmpty())
	{
		struct Node* n=(struct Node*)malloc(sizeof(struct Node));
		n->data=val;
		n->next=NULL;
		f=n;
		r=n;
		printf("Enqueued element:%d\n",r->data);
		return f;
	}
	else
	{
		struct Node* n=(struct Node*)malloc(sizeof(struct Node));
	  n->data=val;
	  n->next=NULL;
	  r->next=n;
	  r=n;
	  printf("Enqueued element:%d\n",r->data);
	  return f;
	}
}

int dequeue()
{
	if(isEmpty())
	{
	  printf("Queue is empty!\n");
	  return -1;
	}
	else if(f==r)
	{
		int val;
		struct Node* p=f;
		val=p->data;
		f=NULL;
		r=NULL;
		free(p);
		printf("Dequeued element:%d\n",val);
		return val;
	}
	else
	{
	int val;
	struct Node* p=f;
	f=f->next;
	val=p->data;
	free(p);
	printf("Dequeued element:%d\n",val);
	return val;
  }
}
int main()
{ 
  enqueue(10);
	return 0;
}
