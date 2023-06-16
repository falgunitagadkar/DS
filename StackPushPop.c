//Stack push and pop

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
		return 1;
	}
	else
	{
		return 0;
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

void push(struct stack *s,int val)
{
	if(IsFull(s))
	{
		printf("Stack Overflow! Cannot push %d in the stack\n",val);
	}
	else
	{
		s->top++;
		s->arr[s->top]=val;
	}
}

int pop(struct stack *s)
{
	if(IsEmpty(s))
	{
		printf("Stack Underflow!  Cannot pop from the stack\n");
		return -1;
	}
	else
	{
		int val=s->arr[s->top];
		s->top--;
		return val;
  }
}

int main()
{
	struct stack *s1=(struct stack*)malloc(sizeof(struct stack));
	s1->size=10;
	s1->top=-1;
	s1->arr=(int *)malloc(s1->size*sizeof(int));
	
	printf("Before push Empty Status:%d\n",IsEmpty(s1));
	printf("Before push Full Status:%d\n",IsFull(s1));

	push(s1,1);
	push(s1,2);
	push(s1,3);
	push(s1,4);
	push(s1,5);
	push(s1,6);
	push(s1,7);
	push(s1,8);
	push(s1,9);
	push(s1,10);
	//push(s1,11);
	pop(s1);
	
	printf("After push Empty Status:%d\n",IsEmpty(s1));
	printf("After push Full Status:%d\n",IsFull(s1));

	
	return 0;
}
