//Stack using link list

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

struct Node* top=NULL;

//Function for push
struct Node* push(int val)
{
	if(isFull())
	{
		printf("Stack overflow!Cannot push %d in the stack\n",val);
	}
	struct Node* p=(struct Node*)malloc(sizeof(struct Node));
	p->data=val;
	p->next=top;
	
	top=p;
	return top;
}

//Function for pop
int pop()
{
	if(isEmpty())
	{
		printf("Stack underflow!Cannot pop element from the stack\n");
	}
	int val;
	struct Node* n;
	val=top->data;
	n=top;
	top=top->next;
	
	free(n);
	return val;
}

//Function to check if the stack is empty
int isEmpty()
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

//Function to check if the stack is full
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

//Funtion for traversing stack
void traverse()
{
	struct Node* p=top;
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
}

//Function to return element at position i from top
int peek(int pos)
{
	int i;
	struct Node* p=top;
	for(i=0;i<pos-1 && p!=NULL;i++)
	{
		p=p->next;
	}
	
	if(p==NULL)
	{
		return -1;
	}
	else
	{
		return p->data;
	}
}

//Function to return top most element
int stackTop()
{
	return top->data;
}

//Function to return bottom most element 
int stackBottom()
{
	struct Node* p=top;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	return p->data;
}

int main()
{
	top=push(10);
	top=push(20);
	top=push(30);
	top=push(40);
	printf("Before pop\n");
	traverse();
	
	printf("\n\n");
	
	int i=pop();
	printf("After pop\n");//returns the popped value
	traverse();
	
	printf("\n");
	
	printf("Value at position 1 from top is:%d\n",peek(1));
	printf("Value at position 2 from top is:%d\n",peek(2));
	
	printf("\n");
	printf("The top most element of the stack is:%d\n",stackTop());
	printf("The bottom most element of the stack is:%d\n",stackBottom());
	return 0;
}
