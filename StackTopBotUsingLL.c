//Stack implementation using link list

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};
struct Node *top;

struct Node* push(struct Node *head,int val)
{
	struct Node *p=(struct Node*)malloc(sizeof(struct Node));
	p->data=val;
	p->next=head;
  
  top=p;
	return p;
}

void Traversal(struct Node* head)
{
	struct Node* p=head;
	
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
}

void pop(struct Node* head)
{
	top=head->next;
	
	free(head);
}

int stackTop()
{
	int val=top->data;
	return val;
}

int stackBottom()
{
	struct Node* p=top;
	while(p->next!=NULL)
	{
		  p=p->next;
	}
	
	int val=p->data;
	return val;
}

int peek(struct Node* head,int index)
{
	int tot=1;
	struct Node* p=head;
	while(p->next!=NULL)
	{
		p=p->next;
		tot++;
	}
	
	int top=tot-1;
	if(top-index+1==-1)
	{
		printf("Stack underflow! Cannot fetch the element at the entered index\n");
	}
	else
	{
		tot=0;
		p=head;
		while(tot<top-index+1)
		{
			p=p->next;
			tot++;
		}
		
		return p->data;
	}
}
int main()
{
	struct Node *n1=(struct Node*)malloc(sizeof(struct Node));
	struct Node *n2=(struct Node*)malloc(sizeof(struct Node));
	struct Node *n3=(struct Node*)malloc(sizeof(struct Node));
	struct Node *n4=(struct Node*)malloc(sizeof(struct Node));
	n1->data=10;
	n1->next=n2;
	
	n2->data=20;
	n2->next=n3;
	
	n3->data=30;
	n3->next=n4;
	
	n4->data=40;
	n4->next=NULL;
	
	//Traversal(n1);
  struct Node* head=push(n1,50);
  //Traversal(top);
  
  head=push(head,60);
  printf("LL after push and before pop\n");
  Traversal(top);
  
  printf("\n\n");
  printf("LL after pop\n");
  pop(top);
  pop(top);
  Traversal(top);
  
  printf("The top most element of the stack is %d\n",stackTop());	
	printf("The bottom most element of the stack is %d\n",stackBottom());
	
	printf("The value at index 2 from top is %d\n",peek(top,1));
	return 0;
}
