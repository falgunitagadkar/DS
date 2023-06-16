#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

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

struct Node* DeletionLLBeginning(struct Node* head)
{
	struct Node* p=head;
	head=head->next;
	free(p);
	
	return head;
}

struct Node* DeletionLLBetween(struct Node* head,int index)
{
	struct Node* p=head;
	struct Node* q;
	int i;
	for(i=0;i<(index-1);i++)
	{
		p=p->next;
		i++;
	}
	q=p->next;
	
	p->next=q->next;
	free(q);
	
	return head;
}

struct Node* DeletionLLEnd(struct Node* head)
{
	struct Node* p=head;
	struct Node* q=head->next;
	while(q->next!=NULL)//q reaches upto last element
	{
		p=p->next;
		q=q->next;
	}
	
	p->next=NULL;
	free(q);
	return head;
}

struct Node* DeletionLLVal(struct Node* head,int value)
{
	int i=0;
	struct Node* ptr=head;
	while(value!=ptr->data && ptr->next!=NULL)
	{
		ptr=ptr->next;
		i++;
	}
	
	
	if(ptr->data!=value)
	{
		printf("%d not found in the link list\n",value);
		return head;
	}
	else
	{
	   printf("%d found at index %d in the link list\n",value,i);	
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
	head->data=78;
	
	n2=(struct Node*)malloc(sizeof(struct Node));
	n2->data=89;
	
	n3=(struct Node*)malloc(sizeof(struct Node));
	n3->data=990;
	
	n4=(struct Node*)malloc(sizeof(struct Node));
	n4->data=1889;
	
	n5=(struct Node*)malloc(sizeof(struct Node));
	n5->data=8999;
	
	head->next=n2;
	n2->next=n3;
	n3->next=n4;
	n4->next=n5;
	n5->next=NULL;
	
	Traverse(head);
	
	head=DeletionLLBeginning(head);
	Traverse(head);
	
	head=DeletionLLBetween(head,1);
	Traverse(head);
	
//	head=DeletionLLEnd(head);
	//Traverse(head);
	
	head=DeletionLLVal(head,8999);
	return 0;
}
