#include<stdio.h>
#include<stdlib.h>

struct stack
{
	int size;
	int top;
	int* arr;
};

int peep(struct stack* s,int i)
{
	if(s->top-i+1<=-1)
	{
		printf("Stack underflow\n");
		return 0;
	}
	else
	{
		return (s->arr[s->top-i+1]);
	}
}

void change(struct stack* s,int i,int element)
{
	if(s->top-i+1<=-1)
	{
		printf("Stack underflow");
	}
	else
	{
		s->arr[s->top-i+1]=element;
	}
}

void Traverse(struct stack* s)
{
	int i;
	printf("The elements of the stack are:\n");
	for(i=s->top;i>=0;i--)
	{
		printf("%d\n",s->arr[i]);
	}
}
int main()
{
	struct stack s1;
	s1.size=5;
	s1.top=-1;
	s1.arr=(int *)malloc(s1.size*sizeof(int));
	
	s1.arr[0]=5;
	s1.arr[1]=7;
	s1.arr[2]=9;
	s1.top=2;
	
	Traverse(&s1);
	printf("\n\n");
	int i=2;//ith index from top
	
	if(peep(&s1,i)!=0)
	printf("The element at index %d from top is %d\n",i,peep(&s1,i));
	
	printf("\n\n");
	change(&s1,1,34);
	
	Traverse(&s1);
	return 0;
}
