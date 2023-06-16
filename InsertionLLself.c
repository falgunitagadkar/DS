#include<stdio.h>

struct Node
{
	int data;
	struct Node* ptr;
};

struct Node* InsertionLLBeginning(struct Node* head,struct Node* New)
{
    int element;
    printf("Enter element to be inserted at the beginning of the list\n");
    scanf("%d",&element);
    New->data=element;
    New->ptr=head;
    head=New;
    return head;
}

struct Node* InsertionLLBetween(struct Node* head,struct Node* New,int index)
{
	int i,element;
	struct Node* temp=head;
	printf("Enter the element you want to insert in the middle\n");
	scanf("%d",&element);
	for(i=0;i<index-1;i++)
	{
		temp=temp->ptr;
	}
	
	New->data=element;
	New->ptr=temp->ptr;
	temp->ptr=New;
	
	return head;	
}

struct Node* InsertionLLEnd(struct Node* head,struct Node* New)
{
	int element;
	struct Node* temp=head;
	printf("Enter the element you want to insert at the end\n");
	scanf("%d",&element);
	while(temp!=NULL)
	{	
		temp=temp->ptr;
	}
	
	New->data=element;
	New->ptr=NULL;
	temp->ptr=New;
	return head;
}

void Traverse(struct Node* head)
{
	printf("The elements of link list are\n");
	while(head!=NULL)
	{
		printf("%d\n",head->data);
		head=head->ptr;
	}
}
int main()
{
  struct Node n1,n2,n3,n4;
  n1.data=3;
  n1.ptr=&n2;
  
  n2.data=45;
  n2.ptr=&n3;
  
  n3.data=34;
  n3.ptr=&n4;
  
  n4.data=22;
  n4.ptr=NULL;
  Traverse(&n1);
  
  struct Node n5,n6,n7;
  struct Node *head;
	head=InsertionLLBeginning(&n1,&n5);
  Traverse(head);
  
  head=InsertionLLBetween(head,&n6,3);
  Traverse(head);  
  
  head=InsertionLLEnd(head,&n7);
  Traverse(head);
	return 0;
}
