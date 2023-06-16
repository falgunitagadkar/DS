//Iterative Search in Binary Search Tree
//Iterative is search without recursion 
#include<stdio.h>
#include<stdlib.h>

struct Node 
{
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* createNode(int data)
{
	struct Node* n=(struct Node*)malloc(sizeof(struct Node));
	n->data=data;
	n->left=NULL;
	n->right=NULL;
}

void inOrder(struct Node* root)
{
	if(root!=NULL)
	{
		inOrder(root->left);
		printf("%d ",root->data);
		inOrder(root->right);
	}
}


struct Node* search(struct Node* root,int key)
{
	while(root!=NULL)
	{
		if(key==root->data)
		{
			return root;//if found then returns from the function with the node
		}
		else if(key<root->data)
		{
			root=root->left;
		}
		else
		{
			root=root->right;
		}
	}
	
	return NULL;//if not found then returns taking the NULL pointer 
}


int isBST(struct Node* root)
{
	static struct Node* prev=NULL;
	if(root!=NULL)
	{
		if(!isBST(root->left))
		{
			return 0;
		}
		if(prev!=NULL && root->data <= prev->data)//prev is the prev node in the inOrder traversal...so current should alwaysbe >
		{
			return 0;
		}
		prev=root;
		return isBST(root->right);
	}
	else
	{
		return 1;
	}
}


int main()
{

	struct Node* p=createNode(5);
	struct Node* p1=createNode(3);
	struct Node* p2=createNode(6);
	struct Node* p3=createNode(1);
	struct Node* p4=createNode(4);
	
	p->left=p1;
	p->right=p2;
	
	p1->left=p3;
	p1->right=p4;
	
	if(isBST(p))
	{
		printf("Given tree is Binary Search Tree\n");
	}
	else
	{
		printf("Given tree is not Binary Search Tree\n");	
	}
	
	struct Node* s=search(p,1);
	if(s==NULL)
	{
		printf("Key not found in the Binary Search Tree\n");
	}
	else
	{
		printf("%d found in the Binary Search Tree\n",s->data);
	}	
 	return 0;
}

