//Searching in binary search tree

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
	if(root==NULL)
	{
		return NULL;
	}
	else
	{
		if(root->data==key)
		{
			return root;
		}
		else if(key<root->data)
		{
			return search(root->left,key);
		}
		else if(key>root->data)
		{
			return search(root->right,key);
		}
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
	
	inOrder(p);
	printf("\n");
	
	struct Node* s=search(p,6);
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

