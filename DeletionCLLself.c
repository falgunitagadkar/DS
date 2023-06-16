#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

struct Node* DeletionCLLBeginning(struct Node* head)
{
	struct Node* p=head;
	struct Node* q=head;
	while(q->next!=head)
	{
		q=q->next;
	}
	
	head=head->next;
	q->next=head;
	free(p);
	
	return head;
}

struct Node* DeletionCLLBetween(struct Node* head,int index)
{
	struct Node* p=head;
	struct Node* q;
	
	int i;
	for(i=0;i<index-1;i++)
	{
		p=p->next;
	}
	q=p->next;
	
	p->next=q->next;
	free(q);
	
	return head;
}

struct Node* DeletionCLLEnd(struct Node* head)
{
	struct Node* p=head;
	struct Node* q=head->next;
	
	while(q->next!=head)
	{
		p=p->next;//set to the second last element
		q=q->next;//set to last element
	}
	
	p->next=head;
	free(q);
	
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

struct Node* DeletionCLLVal(struct Node* head,int value)
{
	struct Node* p=head;
	struct Node* q=head;
	int i=0;
	while(p->data!=value && p->next!=head)
	{
		p=p->next;
		i++;
	}
	
	if(p->data!=value)
	{
		printf("%d not found in the link list\n",value);
		return head;
	}
	else
	{
		while(q->next!=p)
		{
			q=q->next;
		}	
		q->next=p->next;
	  free(p);
	
	return head;
	}	
}
int main()
{
	struct Node* head;
	struct Node* n2;
	struct Node* n3;
	struct Node* n4;
	struct Node* n5;
	
	head=(struct Node*)malloc(sizeof(struct Node));
	head->data=56;
	
	n2=(struct Node*)malloc(sizeof(struct Node));
	n2->data=67;
	
	n3=(struct Node*)malloc(sizeof(struct Node));
	n3->data=77;
	
	n4=(struct Node*)malloc(sizeof(struct Node));
	n4->data=89;
	
	n5=(struct Node*)malloc(sizeof(struct Node));
	n5->data=98;
	
	head->next=n2;
	n2->next=n3;
	n3->next=n4;
	n4->next=n5;
	n5->next=head;
	Traverse(head);
	
  head=DeletionCLLBeginning(head);
	Traverse(head);
	
	head=DeletionCLLBetween(head,1);
	Traverse(head);
	
	head=DeletionCLLEnd(head);
	Traverse(head);
	
	head=DeletionCLLVal(head,43);
	Traverse(head);
	
	
	return 0;
}
