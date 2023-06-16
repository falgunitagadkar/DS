#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

struct Node* CreateListCircular(int data)
{
	struct Node* p=(struct Node*)malloc(sizeof(struct Node));
	p->data=data;
	
	p->next=p;
	return p;
}

struct Node* InsertionCLLBeginning(struct Node* head,int data,int total)
{
	struct Node* p=(struct Node*)malloc(sizeof(struct Node));
	p->data=data;
	p->next=head;
	head=p;
	
	struct Node* q=head;
	int i;
	for(i=0;i<total-1;i++)
	{
	  q=q->next;
	}
	
	q->next=head;
	return head;
}

struct Node* InsertionCLLBetween(struct Node* head,int data,int index)
{
	struct Node* p=(struct Node*)malloc(sizeof(struct Node));
	p->data=data;
	
	
	struct Node* q=head;
	int i;
	for(i=0;i<index-1;i++)
	{
		q=q->next;
	}
	p->next=q->next;
	q->next=p;
	
	return head;
}

struct Node* InsertionCLLEnd(struct Node* head,int data)
{
	struct Node* p=(struct Node*)malloc(sizeof(struct Node));
	p->data=data;
	
	struct Node* q=head;
	while(q->next!=head)
	{
		q=q->next;
	}
	
	q->next=p;
	p->next=head;
	
	return head;
}

void Traverse(struct Node* head)
{
	struct Node* p=head;
	
  printf("The elements of the link list are:\n");
	while(p->next!=head)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
	if(p->next==head)
	{
		printf("%d\n",p->data);
	}
}

struct Node* InsertionCLL(struct Node* head,struct Node* node,int data)
{
	struct Node* p=(struct Node*)malloc(sizeof(struct Node));
	p->data=data;
	
	p->next=node->next;
	node->next=p;
	
	return head;
}
int main()
{
	struct Node* head;
	head=CreateListCircular(23);
	Traverse(head);
	struct Node* node=head;
	
	head=InsertionCLLBeginning(head,33,2);
	Traverse(head);
	
	head=InsertionCLLBetween(head,45,1);
	Traverse(head);
	
	head=InsertionCLLEnd(head,67);
	Traverse(head);
	
	head=InsertionCLL(head,node,77);//insertion after a node i.e here after element 23
	Traverse(head);
	return 0;
}
