//Doubly link list insertion and traversal from 'head to end' and 'end to head'
#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* prev;
	struct Node* next;
};

struct Node* CreateDLL(int data)
{
	struct Node* p=(struct Node*)malloc(sizeof(struct Node));
	p->data=data;
	p->prev=NULL;
	p->next=NULL;
	
	return p;
}

struct Node* InsertionDLLBeginning(struct Node* head,int data)
{
	struct Node* p=(struct Node*)malloc(sizeof(struct Node));
	p->data=data;
	
	p->prev=NULL;
	p->next=head;
	head->prev=p;
	
	head=p;
	return head;
}

struct Node* InsertionDLLBetween(struct Node* head,int data,int index)
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
	p->prev=q;
	(q->next)->prev=p;
	q->next=p;
	
	return head;
	
}

struct Node* InsertionDLLEnd(struct Node* head,int data)
{
   struct Node* p=(struct Node*)malloc(sizeof(struct Node));
	 p->data=data;
	 
	 struct Node* q=head;
	 while(q->next!=NULL)
	 {
	 	  q=q->next;
	 }
	 
	 p->next=NULL;
	 p->prev=q;
	 q->next=p;
	 
	 return head;	
}

void Traverse(struct Node* head)
{
	struct Node* p=head;
	printf("The elements of the doubly link list from head to end are:\n");
	while(p->next!=NULL)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
	printf("%d\n",p->data);
	
	printf("The elements of the doubly link list from end to head are:\n");
	struct Node* q=p;
	while(q->prev!=NULL)
	{
		printf("%d\n",q->data);
		q=q->prev;
	}
	printf("%d\n",q->data);
	printf("\n\n\n");
}
int main()
{
	struct Node* head=CreateDLL(67);
	Traverse(head);
	
	head=InsertionDLLBeginning(head,78);
	Traverse(head);
	
	head=InsertionDLLBetween(head,89,1);
	Traverse(head);
	
	head=InsertionDLLEnd(head,99);
	Traverse(head);
	return 0;
}
