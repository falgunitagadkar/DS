//Stack implementation using link list
//here we only have one stack so we use top as global variable 

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

struct Node* top;

int isEmpty()//checks only for one stack as this is single stack program
{
	if(top==NULL)
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
	if(n==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
struct Node* push(int val)
{
	if(isFull())
	{
		printf("Stack overflow! Cannot insert %d in the stack\n",val);
		return top;
	}
	else
	{
		struct Node* n=(struct Node*)malloc(sizeof(struct Node));
		n->data=val;
		n->next=top;
		top=n;
		return top;
	}
}

int pop()
{
	if(isEmpty())
	{
		printf("Stack undeflow! Cannot pop element from the stack\n");
		return -1;
	}
	else
	{
		int val;
		struct Node* p=top;
		val=top->data;
		top=top->next;
		free(p);
		return val;
	}
}

void traversal()
{
   struct Node* p=top;
   while(p!=NULL)
   {
   	  printf("%d\n",p->data);
   	  p=p->next;
	 }
}
int main()
{
	top=NULL;
	//if(isEmpty())
	//{
	//	printf("Stack is empty\n");
	//}
	
	top=push(10);
	top=push(20);
	top=push(30);
	printf("Before pop\n");
	traversal();
	
	printf("\n\n");
	int i=pop();
	printf("After pop\n");
	traversal();
	return 0;
}
