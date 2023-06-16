//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
	int size;
	int top;
	char* arr;
};

int isEmpty(struct stack* s)
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

int isFull(struct stack* s)
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

void push(struct stack* s,char ele)
{
	s->top++;
	s->arr[s->top]=ele;
}

int pop(struct stack *s)//don't check isEmpty here as it is checked in the function itself
{
		s->top--;
		return 1;
}
int parenthesisCheck(char* exp)//char array passed here
{
	int i;
	struct stack* s=(struct stack*)malloc(sizeof(struct stack));
	s->size=strlen(exp);
	s->top=-1;
	s->arr=(char*)malloc(s->size*sizeof(char));
	for(i=0;exp[i]!='\0';i++)
	{
		if(exp[i]=='(')
		{
			push(s,'(');
		}
		else if(exp[i]==')')
		{
			if(isEmpty(s))
			{
				return 0;//return from the check function
			}
			else
			{
				pop(s);
			}
		}
	}
	
	if(isEmpty(s))
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
	char* exp="(8)+9-(7*8)()";
	if(parenthesisCheck(exp))
	{
		printf("The expression has matching parenthesis\n");
	}
	else
	{
		printf("The expression don't have matching parenthesis\n");
	}
	return 0;
}
