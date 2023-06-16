//Insertion in Binary Search Tree

#include<stdio.h>
#include<stdlib.h>

struct Node 
{
	int data;
	struct Node* left;
	struct Node* right;
};

static struct Node* ptr=NULL;

struct Node* createNode(int data)
{
	struct Node* n=(struct Node*)malloc(sizeof(struct Node));
	n->data=data;
	n->left=NULL;
	n->right=NULL;
}

struct Node* search(struct Node* root,int key)
{	
	while(root!=NULL)
	{
			if(key==root->data)
			{
				return root;
			}
			else if (key < root->data)
			{
				ptr=root;
				root=root->left;
			}
			else
			{
				ptr=root;
				root=root->right;
			}
		}
		return NULL;
}

void insert(struct Node* root,int key)
{
	if(search(root,key)==NULL)
	{
		struct Node* n=createNode(key);
		if(key<ptr->data)
		{
			ptr->left=n;
		}
		else if(key > ptr->data)
		{
			ptr->right=n;
		}
		printf("Element inserted\n");
	}
	else
	{
		printf("Key already exists in the Binary Search Tree\n");
	}
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
	struct Node* p=createNode(8);
 	struct Node* p1=createNode(3);
	struct Node* p2=createNode(10);
 	struct Node* p3=createNode(1);
 	struct Node* p4=createNode(6);
 	struct Node* p5=createNode(4);
 	struct Node* p6=createNode(7);
 	struct Node* p7=createNode(14);
 	struct Node* p8=createNode(13);
 	/*
 	                8
 	              /  \
 	             3    10
						 / 	\     \
						1	   6     14
						    / \    /
						   4   7  13
						   
	*/
	p->left=p1;
	p->right=p2;
	
	p1->left=p3;
	p1->right=p4;
	
	p4->left=p5;
	p4->right=p6;
	
	p2->right=p7;
	
	p7->left=p8;
	
	if(isBST(p))
	{
		printf("Given tree is Binary Search Tree\n");
	}
	else
	{
		printf("Given tree is not Binary Search Tree\n");
	}
	
	insert(p,9);
	printf("%d\n",((p->right)->left)->data);
	 return 0;
}

