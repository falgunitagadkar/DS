#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

struct Node* CreateList(int data)//for first element
{
	struct Node* p=(struct Node*)malloc(sizeof(struct Node));
	p->data=data;
	p->next=NULL;
	return p;
}

struct Node* InsertionLLBeginning(struct Node* head,int data)
{
	struct Node* p=(struct Node*)malloc(sizeof(struct Node));
	p->data=data;
	p->next=head;
	
	return p;
}

struct Node* InsertionLLBetween(struct Node* head,int index,int data)
{
	struct Node* p=(struct Node*)malloc(sizeof(struct Node));
	p->data=data;
	
	struct Node* q=head;
	int i=0;
	while(i<index)
	{
		q=q->next;
		i++;
	}
	
	p->next=q->next;
	q->next=p;
	
	return head;
}

struct Node* InsertionLLEnd(struct Node* head,int data)
{
	struct Node* p=(struct Node*)malloc(sizeof(struct Node));
	p->data=data;
	
	struct Node* q=head;
	while(q->next!=NULL)
	{
		q=q->next;
	}
	p->next=NULL;
	q->next=p;
	
	return head;
}

struct Node* InsertionLL(struct Node* head,struct Node* node,int data)
{
	struct Node* p=(struct Node*)malloc(sizeof(struct Node));
	p->data=data;
	
	p->next=node->next;
	node->next=p;
	
	return head;
} 

void Traverse(struct Node* head)
{
	struct Node* ptr=head;
	printf("The elements of the link list are:\n");
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->data);
		ptr=ptr->next;
	}
}

int main()
{
	struct Node* head;
	head=CreateList(5);
	Traverse(head);
	struct Node* ptr=head;
	
	head=InsertionLLBeginning(head,71);
	Traverse(head);
	
	head=InsertionLLBetween(head,1,833);
	Traverse(head);
	
	head=InsertionLLEnd(head,9);
	Traverse(head);

  head=InsertionLL(head,ptr,7888);//insertion of node after a given node ptr i.e after element 5	
  Traverse(head);
	return 0;
}
