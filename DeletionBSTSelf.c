//Deletion in Binary Search Tree
//Case 1>Deletion of Leaf Node
//Case 2>Deletion of Parent node//node having atleast one child as leaf node
//Case 3>Deletion of Root node or node with no child as leaf node

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

static struct Node* prev=NULL;
struct Node* search(struct Node* root,int key)
{	
	while(root!=NULL)
	{
		
			if(key==root->data)
			{
				printf("%d found\n");
				return root;
			}
			else if (key < root->data)
			{
				prev=root;
				root=root->left;
			}
			else
			{
				prev=root;
				root=root->right;
				root=root->right;
			}
		}
		
		printf("%d not found\n");
		return NULL;
}

int isLeaf(struct Node* n)
{
	if(n->left==NULL && n->right==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


void deletionLeaf(struct Node* n)
{
		if(n->data < prev->data)
			{
				prev->left=NULL;
				free(n);
				return;
			}
			else if(n->data > prev->data)
			{
				prev->right=NULL;
				free(n);
				return;
			}
}

void deletionInternal(struct Node* n)
{
	if(isLeaf(n->left))
	{
		if(n->data < prev->data)
		{
			//prev->left=inOrderPre(n);
			free(n);
			return;
		}
		else
		{
			//prev->right=inOrderPre(n);
			free(n);
			return;
		}
	}
	else
	{
		if(n->data < prev->data)
		{
			//prev->left=inOrderPost(n);
			free(n);
			return;
		}
		else
		{
			//prev->right=inOrderPost(n);
			free(n);
			return;
		}
	}
}

void deletionInBST(struct Node* root,int key)
{
	struct Node* n=search(root,key);
	if(search(root,key)!=NULL)//key found in the binary search tree
	{
		if(isLeaf(n))
		{
			deletionLeaf(n);	
		}
		if(isLeaf(n->left) || isLeaf(n->right))//any one is leaf
		{
		
			deletionInternal(n);
		}
	}
	else
	{
		printf("Key you want to delete not found in BST\n");
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


	if(isLeaf(p4))
	{
		printf("It is leaf node\n");
	}
	else
	{
		printf("Not a leaf node\n");
	}
	
	deletionInBST(p,1);
	search(p,1);
 	return 0;
}

