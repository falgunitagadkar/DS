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
	struct Node* n=(struct Node*)malloc(sizeof(struct Node*));
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
int main()
{
	struct Node* p0=createNode(2);
	struct Node* p1=createNode(1);
	struct Node* p2=createNode(4);
	struct Node* p3=createNode(5);
	struct Node* p4=createNode(6);
	struct Node* p5=createNode(8);
	struct Node* p6=createNode(9);
	
	p0->left=p1;
	p0->right=p2;
	
	p1->left=p3;
	p1->right=p4;
	
	p2->left=p5;
	p2->right=p6;
	
	inOrder(p0);
 	return 0;
}

