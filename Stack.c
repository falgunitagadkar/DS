//Stack first program

#include<stdio.h>
#include<stdlib.h>

struct stack
{
	int size;
	int top;
	int* arr;
};

int IsEmpty(struct stack *s)
{
	if(s->top==-1)
	{
		return 1;//true for the stack empty
	}
	else
	{
		return 0;//false
	}
}

int IsFull(struct stack *s)
{
	if(s->top==s->size-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	struct stack *s1=(struct stack*)malloc(sizeof(struct stack));
	
	s1->size=10;
	s1->top=-1;
	s1->arr=(int*)malloc(s1->size*sizeof(int));
	
	if(IsEmpty(s1))
	{
		printf("Stack is empty\n");
	}
	
	if(IsFull(s1))
	{
		printf("Stack is full\n");
	}
	return 0;
}
