//Insertion in binary search tree Harry method

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
	
	return n;
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
		if(prev!=NULL && root->data <= prev->data)
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

void insert(struct Node* root,int key)
{
	struct Node* prev=NULL;
	while(root!=NULL)
	{
		prev=root;
		if(key==root->data)
		{
			printf("Key already exists in BST\n");
			return;
		}
		else if(key < root->data)
 		{
			root=root->left;
		}
		else
		{
			root=root->right;
		}
	}
	
	struct Node* new=createNode(key);
	if(key<prev->data)
	{
		prev->left=new;
	}
	else
	{
		prev->right=new;
	}
	
	printf("%d inserted in BST\n",key);
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

	insert(p,2);
	printf("%d\n",((p->left)->left)->right->data);
 	return 0;
}

