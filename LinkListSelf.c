#include<stdio.h>


struct Node
{
	int data;
	struct Node* ptr;
};

void CreateLinklist(struct Node *current,struct Node *next)
{
	int element;
	{	
		printf("Enter element\n");
		scanf("%d",&element);
		current->data=element;
		current->ptr=next;
	}
//	else if(i==(size-1))
	//{
		//current->data=element;
		//current->ptr=NULL;
	//}	
}

void Traverse(struct Node* n1)
{
	printf("The elements of array are:\n");
	while(n1!=NULL)
	{
  	printf("%d\n",n1->data);
	  n1=n1->ptr;
	}
	//if(n1->ptr==NULL)
	//{
		//printf("%d\n",n1->data);
	//}
}


int main()
{
	struct Node head,n2,n3,n4;
	CreateLinklist(&head,&n2);
	CreateLinklist(&n2,&n3);
	CreateLinklist(&n3,&n4);
	CreateLinklist(&n4,NULL);
	
	Traverse(&head);
	
	return 0;
}
