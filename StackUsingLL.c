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
  
	
	return 0;
}
