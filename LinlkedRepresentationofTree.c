//Linked representation of Binary Tree

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
};

int main()
{
	struct Node* p0=createNode(2);
	struct Node* p1=createNode(1);
	struct Node* p2=createNode(4);
	struct Node* p3=createNode(1);
	struct Node* p4=createNode(5);
	
	p0->left=p1;
	p0->right=p2;
	p1->left=p3;
	p1->right=p4;
	
	printf("    %d   \n",p0->data);
	printf(" %d    %d \n",(p0->left)->data,(p0->right)->data);
	printf("%d %d\n",((p0->left)->left)->data,((p0->left)->right)->data);	
	return 0;
}
